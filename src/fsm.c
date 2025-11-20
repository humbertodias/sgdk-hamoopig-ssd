#include "fsm.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "collision.h"
#include "player.h"
#include "utils.h"

void FUNCAO_FSM()
{
	
	if(P[1].direcao==1){gDistancia=P[2].x-P[1].x;}else{gDistancia=P[1].x-P[2].x;}
	for(i=1; i<=2; i++)
	{
		u8 PA; //Player Attack (Player que ataca)
		u8 PR; //Player Receive (Player que recebe o dano)
		if(i==1){ PA=1; PR=2; }else{ PA=2; PR=1; }
		
		
		//O calculo abaixo é usado para defender magias :)
		u8 distancia_Player_X_Magia=250;
		if(P[PR].fBallX!=0 && P[PR].fBallY!=0)
		{
			if(P[PA].direcao== 1){ distancia_Player_X_Magia=P[PR].fBallX-P[PA].x+25; }
			if(P[PA].direcao==-1){ distancia_Player_X_Magia=P[PA].x-P[PR].fBallX; }
		}		
		
		//defesa start - EM PE e ABAIXADO!
		if
		(
			(
				(P[PR].state >= STATE_SOCO_FRACO_LONGE && P[PR].state <= STATE_CHUTE_FORTE_LONGE) || 
				(P[PR].state >= STATE_SOCO_FRACO_PERTO && P[PR].state <= STATE_CHUTE_FORTE_PERTO) || 
				(P[PR].state >= STATE_SOCO_FRACO_ABAIXADO && P[PR].state <= STATE_CHUTE_FORTE_ABAIXADO) || 
				(P[PR].state >= STATE_SOCO_FRACO_AEREO_NEUTRO && P[PR].state <= STATE_CHUTE_FORTE_AEREO_NEUTRO) || 
				(P[PR].state >= STATE_SOCO_FRACO_AEREO_TRAS && P[PR].state <= STATE_CHUTE_FORTE_AEREO_TRAS) || 
				(P[PR].state >= STATE_SOCO_FRACO_AEREO_FRENTE && P[PR].state <= STATE_CHUTE_FORTE_AEREO_FRENTE) || 
				(P[PR].state >= STATE_ESPECIAL_700 && P[PR].state <= STATE_ESPECIAL_790) || 
				(distancia_Player_X_Magia<=70)
			) && 
			(
			  (
			    (P[PA].direcao== 1 && P[PA].key_JOY_LEFT_status ==2) || 
			    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==2)
			  ) && (P[PA].state == STATE_PARADO || P[PA].state == STATE_ABAIXADO || P[PA].state == STATE_ANDANDO_TRAS || P[PA].state == STATE_ANDANDO_FRENTE)
			) 
		){
			if(P[i].key_JOY_DOWN_status==2){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_INICIO); }else{ PLAYER_STATE(i, STATE_DEFESA_PE_INICIO); } //defesa (107 = em pe ; 207 = abaixado)
		}
		
		//soltou a defesa - EM PE
		if( (P[i].state == STATE_DEFESA_PE_INICIO || P[i].state == STATE_DEFESA_PE_DEFENDENDO) && 
		(
		    (P[PA].direcao==1 && P[PA].key_JOY_LEFT_status==0) || 
		    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==0)
		)
		){ PLAYER_STATE(i, STATE_DEFESA_PE_FINAL); } 
		
		//defesa se encerrou com o final do ataque - EM PE
		if(P[i].state == STATE_DEFESA_PE_DEFENDENDO && 
			(P[PR].state == STATE_PARADO || P[PR].state == STATE_ABAIXADO || P[PR].state == STATE_ANDANDO_TRAS || P[PR].state == STATE_ANDANDO_FRENTE)
		){ PLAYER_STATE(i, STATE_DEFESA_PE_FINAL); } 
		
		//soltou a defesa - ABAIXADO
		if( (P[i].state == STATE_DEFESA_ABAIXADO_INICIO || P[i].state == STATE_DEFESA_ABAIXADO_DEFENDENDO) && 
		(
		    (P[PA].direcao==1 && P[PA].key_JOY_LEFT_status==0) || 
		    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==0)
		)
		){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_FINAL); } 
		
		//defesa se encerrou com o final do ataque - ABAIXADO
		if(P[i].state == STATE_DEFESA_ABAIXADO_DEFENDENDO && 
			(P[PR].state == STATE_PARADO || P[PR].state == STATE_ABAIXADO || P[PR].state == STATE_ANDANDO_TRAS || P[PR].state == STATE_ANDANDO_FRENTE)
		){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_FINAL); } 
		
		//variacao de defesa em pe e abaixado
		if(P[i].state == STATE_DEFESA_PE_DEFENDENDO && P[i].key_JOY_DOWN_status==2){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_DEFENDENDO); }
		if(P[i].state == STATE_DEFESA_ABAIXADO_DEFENDENDO && P[i].key_JOY_DOWN_status==0){ PLAYER_STATE(i, STATE_DEFESA_PE_DEFENDENDO); }
		
		//golpes normais!
		if(gDistancia>64)
		{
			//golpes em pe de longe
			if(P[i].key_JOY_X_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_FRACO_LONGE); }
			if(P[i].key_JOY_Y_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_MEDIO_LONGE); }
			if(P[i].key_JOY_Z_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_FORTE_LONGE); }
			if(P[i].key_JOY_A_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_FRACO_LONGE); }
			if(P[i].key_JOY_B_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_LONGE); }
			if(P[i].key_JOY_C_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_FORTE_LONGE); }
		}else{
			//golpes em pe de perto
			if(P[i].key_JOY_X_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_FRACO_PERTO); }
			if(P[i].key_JOY_Y_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_MEDIO_PERTO); }
			if(P[i].key_JOY_Z_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_SOCO_FORTE_PERTO); }
			if(P[i].key_JOY_A_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_FRACO_PERTO); }
			if(P[i].key_JOY_B_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_PERTO); }
			if(P[i].key_JOY_C_status==1 && (P[i].state == STATE_PARADO || P[i].state == STATE_CORRENDO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)){ PLAYER_STATE(i, STATE_CHUTE_FORTE_PERTO); }
		}
		
		//golpes abaixados
		if(P[i].key_JOY_X_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_SOCO_FRACO_ABAIXADO); }
		if(P[i].key_JOY_Y_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_SOCO_MEDIO_ABAIXADO); }
		if(P[i].key_JOY_Z_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_SOCO_FORTE_ABAIXADO); }
		if(P[i].key_JOY_A_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_CHUTE_FRACO_ABAIXADO); }
		if(P[i].key_JOY_B_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_ABAIXADO); }
		if(P[i].key_JOY_C_status==1 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_CHUTE_FORTE_ABAIXADO); }
		
		//abaixando ; esquivando; levantando
		if((P[i].key_JOY_DOWN_status==1 || P[i].key_JOY_DOWN_status==2) && (P[i].state == STATE_PARADO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE))
		{ 
			if(P[i].key_JOY_countdown[2]==0){ PLAYER_STATE(i, STATE_ABAIXANDO); }else{ PLAYER_STATE(i, STATE_ESQUIVA_BAIXO); } //abaixar ou esquivar
		}
		if(P[i].key_JOY_DOWN_status==0 && P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_LEVANTANDO_TRANSICAO); } //levantar
		
		//interrupcao da esquiva abaixada
		if(P[i].state == STATE_ESQUIVA_BAIXO && P[i].animFrame==2 && P[i].key_JOY_DOWN_status==0)
		{ 
			P[i].animFrame=3; 
			P[i].frameTimeAtual=1; 
			P[i].frameTimeTotal=P[i].dataAnim[3]; 
		}
		
		//virando de lado (mudanca de estado)
		if(P[PA].direcao== 1 && P[PR].x<P[PA].x && P[PA].state == STATE_PARADO){ PLAYER_STATE(i, STATE_VIRANDO_PE); P[PA].direcao=-1; }
		if(P[PA].direcao==-1 && P[PA].x<P[PR].x && P[PA].state == STATE_PARADO){ PLAYER_STATE(i, STATE_VIRANDO_PE); P[PA].direcao= 1; }
		if(P[PA].direcao== 1 && P[PR].x<P[PA].x && P[PA].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_VIRANDO_ABAIXADO); P[PA].direcao=-1; }
		if(P[PA].direcao==-1 && P[PA].x<P[PR].x && P[PA].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_VIRANDO_ABAIXADO); P[PA].direcao= 1; }
		
		//ini pulos
		if((P[i].key_JOY_UP_status==1 || P[i].key_JOY_UP_status==2) && (P[i].state == STATE_PARADO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE || P[i].state == STATE_LEVANTANDO_TRANSICAO))
		{ 
			if(P[i].key_JOY_RIGHT_status==2){ if(P[i].direcao==1){PLAYER_STATE(i, STATE_INICIO_PULO_FRENTE);}else{PLAYER_STATE(i, STATE_INICIO_PULO_TRAS);} }
			if(P[i].key_JOY_RIGHT_status==0 && P[i].key_JOY_LEFT_status==0)PLAYER_STATE(i, STATE_INICIO_PULO_NEUTRO); 
			if(P[i].key_JOY_LEFT_status ==2){ if(P[i].direcao==1){PLAYER_STATE(i, STATE_INICIO_PULO_TRAS);}else{PLAYER_STATE(i, STATE_INICIO_PULO_FRENTE);} }
		}
		
		//end pulos
		if((P[i].state == STATE_PULO_NEUTRO || P[i].state == STATE_PULO_TRAS || P[i].state == STATE_PULO_FRENTE) && P[i].y>=gAlturaPiso){ P[i].y=gAlturaPiso; P[i].puloTimer=0; P[i].hSpeed=0; PLAYER_STATE(i, STATE_FINAL_PULO); }
		if((P[i].state >= STATE_SOCO_FRACO_AEREO_NEUTRO && P[i].state <= STATE_CHUTE_FORTE_AEREO_FRENTE) && P[i].y>=gAlturaPiso){ P[i].y=gAlturaPiso; P[i].hSpeed=0; PLAYER_STATE(i, STATE_FINAL_PULO); } 
		
		//golpes aereos
		if(P[i].key_JOY_X_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_SOCO_FRACO_AEREO_NEUTRO); }
		if(P[i].key_JOY_Y_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_SOCO_MEDIO_AEREO_NEUTRO); }
		if(P[i].key_JOY_Z_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_SOCO_FORTE_AEREO_NEUTRO); }
		if(P[i].key_JOY_A_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_CHUTE_FRACO_AEREO_NEUTRO); }
		if(P[i].key_JOY_B_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_AEREO_NEUTRO); }
		if(P[i].key_JOY_C_status==1 && P[i].state == STATE_PULO_NEUTRO){ PLAYER_STATE(i, STATE_CHUTE_FORTE_AEREO_NEUTRO); }
		
		if(P[i].key_JOY_X_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_SOCO_FRACO_AEREO_TRAS); }
		if(P[i].key_JOY_Y_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_SOCO_MEDIO_AEREO_TRAS); }
		if(P[i].key_JOY_Z_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_SOCO_FORTE_AEREO_TRAS); }
		if(P[i].key_JOY_A_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_CHUTE_FRACO_AEREO_TRAS); }
		if(P[i].key_JOY_B_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_AEREO_TRAS); }
		if(P[i].key_JOY_C_status==1 && P[i].state == STATE_PULO_TRAS){ PLAYER_STATE(i, STATE_CHUTE_FORTE_AEREO_TRAS); }
		
		if(P[i].key_JOY_X_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_SOCO_FRACO_AEREO_FRENTE); }
		if(P[i].key_JOY_Y_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_SOCO_MEDIO_AEREO_FRENTE); }
		if(P[i].key_JOY_Z_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_SOCO_FORTE_AEREO_FRENTE); }
		if(P[i].key_JOY_A_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_CHUTE_FRACO_AEREO_FRENTE); }
		if(P[i].key_JOY_B_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_CHUTE_MEDIO_AEREO_FRENTE); }
		if(P[i].key_JOY_C_status==1 && P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_CHUTE_FORTE_AEREO_FRENTE); }
		
		//andando
		if(P[i].direcao==1)
		{
			if(P[i].key_JOY_LEFT_status>0 && P[i].state == STATE_PARADO){ 
				if(P[i].key_JOY_countdown[4]==0){ PLAYER_STATE(i, STATE_ANDANDO_TRAS); }else{ PLAYER_STATE(i, STATE_ROLAMENTO_TRAS); }}
			if(P[i].key_JOY_RIGHT_status>0 && P[i].state == STATE_PARADO){ 
				if(P[i].key_JOY_countdown[6]==0){ PLAYER_STATE(i, STATE_ANDANDO_FRENTE); }else{ PLAYER_STATE(i, STATE_ROLAMENTO_FRENTE); }}
			
			if(P[i].key_JOY_LEFT_status==0 && P[i].state == STATE_ANDANDO_TRAS){ PLAYER_STATE(i, STATE_PARADO); } //end walk
			if(P[i].key_JOY_RIGHT_status==0 && P[i].state == STATE_ANDANDO_FRENTE){ PLAYER_STATE(i, STATE_PARADO); }
		}else{
			if(P[i].key_JOY_LEFT_status>0 && P[i].state == STATE_PARADO){ 
				if(P[i].key_JOY_countdown[4]==0){ PLAYER_STATE(i, STATE_ANDANDO_FRENTE); }else{ PLAYER_STATE(i, STATE_ROLAMENTO_FRENTE);}}
			if(P[i].key_JOY_RIGHT_status>0 && P[i].state == STATE_PARADO){ 
				if(P[i].key_JOY_countdown[6]==0){ PLAYER_STATE(i, STATE_ANDANDO_TRAS); }else{ PLAYER_STATE(i, STATE_ROLAMENTO_TRAS);}}
			
			if(P[i].key_JOY_LEFT_status ==0 && P[i].state == STATE_ANDANDO_FRENTE){ P[i].hSpeed=0; PLAYER_STATE(i, STATE_PARADO); } //end walk
			if(P[i].key_JOY_RIGHT_status==0 && P[i].state == STATE_ANDANDO_TRAS){ P[i].hSpeed=0; PLAYER_STATE(i, STATE_PARADO); }
		}
		
		//key_JOY_countdown é um timer regressivo, ativado quando se aperta algum botao direcional, usado para Corrida e Esquiva, entre outros...
		if(P[i].key_JOY_countdown[8]>0){ P[i].key_JOY_countdown[8]--; }
		if(P[i].key_JOY_countdown[2]>0){ P[i].key_JOY_countdown[2]--; }
		if(P[i].key_JOY_countdown[4]>0){ P[i].key_JOY_countdown[4]--; }
		if(P[i].key_JOY_countdown[6]>0){ P[i].key_JOY_countdown[6]--; }
		
		//ativacao de 'key_JOY_countdown'...
		if(P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE || P[i].state == STATE_ABAIXANDO || P[i].state == STATE_INICIO_PULO_TRAS || P[i].state == STATE_INICIO_PULO_NEUTRO || P[i].state == STATE_INICIO_PULO_FRENTE)
		{
			if(P[i].key_JOY_UP_status   ==1){ P[i].key_JOY_countdown[8]=12; P[i].key_JOY_countdown[2]=0; }
			if(P[i].key_JOY_LEFT_status ==1){ P[i].key_JOY_countdown[4]=12; P[i].key_JOY_countdown[6]=0; }
			if(P[i].key_JOY_RIGHT_status==1){ P[i].key_JOY_countdown[6]=12; P[i].key_JOY_countdown[4]=0; }
			if(P[i].key_JOY_DOWN_status ==1){ P[i].key_JOY_countdown[2]=12; P[i].key_JOY_countdown[8]=0; P[i].key_JOY_countdown[4]=0; P[i].key_JOY_countdown[6]=0; }
		}
		
		//time over decision; timeover
		if((gClockLTimer==0 && gClockRTimer==0) && P[1].state != STATE_WIN1 && P[1].state != STATE_PERDENDO_TIME_OVER)
		{
			bool updateWinsFlag=0;
			if(P[1].energiaBase> P[2].energiaBase){ PLAYER_STATE(1, STATE_WIN1); P[1].wins++; updateWinsFlag=1; PLAYER_STATE(2, STATE_PERDENDO_TIME_OVER); }
			if(P[1].energiaBase< P[2].energiaBase){ PLAYER_STATE(2, STATE_WIN1); P[2].wins++; updateWinsFlag=2; PLAYER_STATE(1, STATE_PERDENDO_TIME_OVER); }
			if(P[1].energiaBase==P[2].energiaBase){ PLAYER_STATE(1, STATE_PERDENDO_TIME_OVER); PLAYER_STATE(2, STATE_PERDENDO_TIME_OVER); }
			if(updateWinsFlag!=0){
				if(updateWinsFlag==1) //P1
				{
					if(P[1].wins>=1){ SPR_setVisibility(GE[12].sprite, VISIBLE); }
					if(P[1].wins>=2){ SPR_setVisibility(GE[13].sprite, VISIBLE); }
				}
				if(updateWinsFlag==2) //P2
				{
					if(P[2].wins>=1){ SPR_setVisibility(GE[15].sprite, VISIBLE); }
					if(P[2].wins>=2){ SPR_setVisibility(GE[14].sprite, VISIBLE); }
				}
			}
		}
		
		/////////////
		// Colisao //
		/////////////
		
		if( FUNCAO_COLISAO(
		 P[PA].x+P[PA].dataHBox[0], P[PA].y+P[PA].dataHBox[1], P[PA].x+P[PA].dataHBox[2], P[PA].y+P[PA].dataHBox[3], 
		 P[PR].x+P[PR].dataBBox[0], P[PR].y+P[PR].dataBBox[1], P[PR].x+P[PR].dataBBox[2], P[PR].y+P[PR].dataBBox[3]
		)==1 )
		{
			if(P[PR].state == STATE_DEFESA_PE_INICIO || P[PR].state == STATE_DEFESA_PE_DEFENDENDO || P[PR].state == STATE_DEFESA_PE_FINAL || P[PR].state == STATE_DEFESA_PE_APLICADA ||
			   P[PR].state == STATE_DEFESA_ABAIXADO_INICIO || P[PR].state == STATE_DEFESA_ABAIXADO_DEFENDENDO || P[PR].state == STATE_DEFESA_ABAIXADO_FINAL || P[PR].state == STATE_DEFESA_ABAIXADO_APLICADA) 
			{
				//DEFENDEU!
				if(P[PR].state >= STATE_DEFESA_PE_INICIO && P[PR].state <= STATE_DEFESA_PE_FINAL){ PLAYER_STATE(PR, STATE_DEFESA_PE_APLICADA); P[PR].hitPause=12; }
				if(P[PR].state >= STATE_DEFESA_ABAIXADO_INICIO && P[PR].state <= STATE_DEFESA_ABAIXADO_FINAL){ PLAYER_STATE(PR, STATE_DEFESA_ABAIXADO_APLICADA); P[PR].hitPause=12; }
				
				u8 AlturaDoHit = P[PA].y+P[PA].dataHBox[3];
				P[PA].dataHBox[0]=0; P[PA].dataHBox[1]=0; P[PA].dataHBox[2]=0; P[PA].dataHBox[3]=0; //desativa a hitbox
				
				if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
				if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
				
				if(
					P[PA].state == STATE_CHUTE_FRACO_LONGE || P[PA].state == STATE_CHUTE_MEDIO_LONGE || P[PA].state == STATE_CHUTE_FORTE_LONGE ||
					P[PA].state == STATE_CHUTE_FRACO_PERTO || P[PA].state == STATE_CHUTE_MEDIO_PERTO || P[PA].state == STATE_CHUTE_FORTE_PERTO || 
					P[PA].state == STATE_CHUTE_FRACO_ABAIXADO || P[PA].state == STATE_CHUTE_MEDIO_ABAIXADO || P[PA].state == STATE_CHUTE_FORTE_ABAIXADO || 
					P[PA].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[PA].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[PA].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || 
					P[PA].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[PA].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[PA].state == STATE_CHUTE_FORTE_AEREO_TRAS || 
					P[PA].state == STATE_CHUTE_FRACO_AEREO_FRENTE || P[PA].state == STATE_CHUTE_MEDIO_AEREO_FRENTE || P[PA].state == STATE_CHUTE_FORTE_AEREO_FRENTE
				){
					//spark de defesa contra chutes
					if(PR==1){Spark1_countDown=12;}
					if(PR==2){Spark2_countDown=12;}
					Spark[PR] = SPR_addSpriteExSafe( &spr_spark_def2, P[PR].x-16, AlturaDoHit-30, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				}else{
					//spark de defesa contra espada
					if(PR==1){Spark1_countDown=20;}
					if(PR==2){Spark2_countDown=20;}
					Spark[PR] = SPR_addSpriteExSafe( &spr_spark_def1, P[PR].x-64, AlturaDoHit-60, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				}
				if(P[PR].direcao == -1){ SPR_setHFlip(Spark[PR], TRUE); }
				SPR_setDepth(Spark[PR], 1);
				
			}else{
				//NAO DEFENDEU!
				u8 AlturaDoHit = P[PA].y+P[PA].dataHBox[3];
				P[PA].dataHBox[0]=0; P[PA].dataHBox[1]=0; P[PA].dataHBox[2]=0; P[PA].dataHBox[3]=0; //desativa a hitbox
				
				u8 SparkType = 0;
				
				//golpes de longe
				if(P[PA].state == STATE_SOCO_FRACO_LONGE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state == STATE_SOCO_MEDIO_LONGE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 5; }
				if(P[PA].state == STATE_SOCO_FORTE_LONGE)
				{ 
					if(P[1].fBallActive==1 || P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){ PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){ PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FORTE);} SparkType= 3; 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11);
				}
				if(P[PA].state == STATE_CHUTE_FRACO_LONGE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=10; }
				if(P[PA].state == STATE_CHUTE_MEDIO_LONGE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=11; }
				if(P[PA].state == STATE_CHUTE_FORTE_LONGE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType=12; }
				
				//golpes de perto
				if(P[PA].state == STATE_SOCO_FRACO_PERTO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state == STATE_SOCO_MEDIO_PERTO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 1; }
				if(P[PA].state == STATE_SOCO_FORTE_PERTO && P[PA].animFrame<12){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 2; }
				if(P[PA].state == STATE_SOCO_FORTE_PERTO && P[PA].animFrame>12)
				{ 
					if(P[1].fBallActive==1 && P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FORTE);} SparkType= 1;/*3*/ 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,3); 
				} 
				if(P[PA].state == STATE_CHUTE_FRACO_PERTO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 10; }
				if(P[PA].state == STATE_CHUTE_MEDIO_PERTO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 11; }
				if(P[PA].state == STATE_CHUTE_FORTE_PERTO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 12; }
				
				//golpes abaixado
				if(P[PA].state == STATE_SOCO_FRACO_ABAIXADO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=  1; }
				if(P[PA].state == STATE_SOCO_MEDIO_ABAIXADO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=  2; }
				if(P[PA].state == STATE_SOCO_FORTE_ABAIXADO)
				{ 
					if(P[1].fBallActive==1 && P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);
						}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FORTE);} SparkType=  2;/*3*/ 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); 
				} 
				if(P[PA].state == STATE_CHUTE_FRACO_ABAIXADO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 10; }
				if(P[PA].state == STATE_CHUTE_MEDIO_ABAIXADO){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 11; }
				if(P[PA].state == STATE_CHUTE_FORTE_ABAIXADO){ PLAYER_STATE(PR, STATE_CAINDO); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 12; }
				
				//golpes aereos
				if(P[PA].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[PA].state == STATE_SOCO_FRACO_AEREO_TRAS || P[PA].state == STATE_SOCO_FRACO_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[PA].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[PA].state == STATE_SOCO_MEDIO_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 2; }
				if(P[PA].state == STATE_SOCO_FORTE_AEREO_NEUTRO || P[PA].state == STATE_SOCO_FORTE_AEREO_TRAS || P[PA].state == STATE_SOCO_FORTE_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 3; }
				if(P[PA].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[PA].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[PA].state == STATE_CHUTE_FRACO_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FRACO);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=10; }
				if(P[PA].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[PA].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[PA].state == STATE_CHUTE_MEDIO_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_MEDIO);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=11; }
				if(P[PA].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || P[PA].state == STATE_CHUTE_FORTE_AEREO_TRAS || P[PA].state == STATE_CHUTE_FORTE_AEREO_FRENTE){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType=12; }
				
				//MAGIAS HITS /////////////////////////////
				
				//HAOHMARU ID:1
				if(P[PA].id==1)
				{
					if(P[PA].state == STATE_ESPECIAL_700){ PLAYER_STATE(PR, STATE_CAINDO); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state == STATE_ESPECIAL_720){ PLAYER_STATE(PR, STATE_CAINDO); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state == STATE_ESPECIAL_730){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR, STATE_CAINDO);}else{PLAYER_STATE(PR, STATE_HIT_TIPO2_FORTE);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType=12; }
				}
				//GILLIUS ID:2
				if(P[PA].id==2)
				{
					if(P[PA].state == STATE_ESPECIAL_710){ PLAYER_STATE(PR, STATE_CAINDO); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state == STATE_ESPECIAL_720){ PLAYER_STATE(PR, STATE_CAINDO); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state == STATE_ESPECIAL_730){ PLAYER_STATE(PR, STATE_HIT_TIPO2_FRACO); FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				}
				
				///////////////////////////////////////////
				
				//oponente zero energy = dead
				if((P[PR].state >= STATE_HIT_TIPO1_FRACO && P[PR].state <= STATE_HIT_TIPO2_FORTE) && P[PR].energiaBase==0)
				{ 
					SPR_releaseSprite(GE[11].sprite);
					PLAYER_STATE(PR, STATE_CAINDO); 
				}
				
				//Spark, efeito FX, do golpe acertando o oponente
				if(SparkType!=0)
				{
					P[PR].hitPause=16; //hitpause Shake
					if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
					if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
					if(PR==1){Spark1_countDown=12;}
					if(PR==2){Spark2_countDown=12;}
					
					if(SparkType== 1){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit1, P[PR].x-12, AlturaDoHit-16- 3, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 2){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit2, P[PR].x-20, AlturaDoHit-24- 6, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 3){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit3, P[PR].x-28, AlturaDoHit-36-10, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 4){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit4, P[PR].x-20, AlturaDoHit- 8- 8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 5){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit5, P[PR].x-32, AlturaDoHit-12-12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 6){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit6, P[PR].x-44, AlturaDoHit-16-16, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 7){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit7, P[PR].x-12, AlturaDoHit-16, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 8){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit8, P[PR].x-16, AlturaDoHit-24, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType== 9){ Spark[PR] = SPR_addSpriteExSafe( &spr_spark_hit9, P[PR].x-24, AlturaDoHit-40, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType==10){ Spark[PR] = SPR_addSpriteExSafe(&spr_spark_hit10, P[PR].x- 8, AlturaDoHit- 8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType==11){ Spark[PR] = SPR_addSpriteExSafe(&spr_spark_hit11, P[PR].x-12, AlturaDoHit-12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					if(SparkType==12){ Spark[PR] = SPR_addSpriteExSafe(&spr_spark_hit12, P[PR].x-16, AlturaDoHit-16, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
					
					if(P[PR].direcao == 1){ SPR_setHFlip(Spark[PR], TRUE); }
					SPR_setDepth(Spark[PR], 1);
				}
			}
		}
		
		////////////////////
		// CORPO x MAGIAS //
		//////////////////// ─=≡ΣO)) x PLAYER
		
		if( FUNCAO_COLISAO(
		 (P[PA].fBallX+20)-20, (P[PA].fBallY+20)-20, (P[PA].fBallX+20)+20, (P[PA].fBallY+20)+20,
		 P[PR].x+P[PR].dataBBox[0], P[PR].y+P[PR].dataBBox[1], P[PR].x+P[PR].dataBBox[2], P[PR].y+P[PR].dataBBox[3]
		)==1 && (P[PA].fBallX!=0 && P[PA].fBallY!=0) )
		{
			if(P[PR].state == STATE_DEFESA_PE_INICIO || P[PR].state == STATE_DEFESA_PE_DEFENDENDO || P[PR].state == STATE_DEFESA_PE_FINAL || P[PR].state == STATE_DEFESA_PE_APLICADA ||
			   P[PR].state == STATE_DEFESA_ABAIXADO_INICIO || P[PR].state == STATE_DEFESA_ABAIXADO_DEFENDENDO || P[PR].state == STATE_DEFESA_ABAIXADO_FINAL || P[PR].state == STATE_DEFESA_ABAIXADO_APLICADA) 
			{
				//DEFENDEU!
				if(P[PR].state >= STATE_DEFESA_PE_INICIO && P[PR].state <= STATE_DEFESA_PE_FINAL){ PLAYER_STATE(PR, STATE_DEFESA_PE_APLICADA); P[PR].hitPause=20; }
				if(P[PR].state >= STATE_DEFESA_ABAIXADO_INICIO && P[PR].state <= STATE_DEFESA_ABAIXADO_FINAL){ PLAYER_STATE(PR, STATE_DEFESA_ABAIXADO_APLICADA); P[PR].hitPause=20; }
			}else{
				//NAO DEFENDEU!
				P[PR].hitPause=20;
				FUNCAO_UPDATE_LIFESP(PR,1,-30); 
				FUNCAO_UPDATE_LIFESP(PR,2, 11);
				if(P[PR].energiaBase==0)
				{
					PLAYER_STATE(PR, STATE_CAINDO);
				}else{
					if(P[PR].y!=gAlturaPiso)
					{ 
						if(P[PA].id==1)
						{
							PLAYER_STATE(PR, STATE_USER_HIT); //magia do haomaru faz o oponente subir
						}else{
							PLAYER_STATE(PR, STATE_CAINDO); //cai apos cair sobre a magia
						}
						
					}else{
						if(P[PA].id==1)
						{
							PLAYER_STATE(PR, STATE_USER_HIT); //magia do haomaru faz o oponente subir
						}else{
							PLAYER_STATE(PR, STATE_HIT_TIPO1_FORTE); //recebe o hit da magia em pe
						}
					}
				}
				
			}
			
			//desativa a magia
			if(P[PA].fBallActive==1)
			{ 
				if(P[PA].fBall)
				{ 
					SPR_releaseSprite(P[PA].fBall); 
					P[PA].fBall = NULL; 
				} 
				P[PA].fBallActive=0;
			}			
			
			//SPARK DE MAGIA SUMINDO
			if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
			if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
			if(PA==1){Spark1_countDown=20;}
			if(PA==2){Spark2_countDown=20;}
			
			if(PA==1)
			{
				//gillius
				if(P[PA].id==2){ Spark[PA] = SPR_addSpriteExSafe( &spr_gillius_702, P[PA].fBallX-20, P[PA].fBallY, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
			}
			if(PA==2)
			{
				//gillius
				if(P[PA].id==2){ Spark[PA] = SPR_addSpriteExSafe( &spr_gillius_702, P[PA].fBallX-20, P[PA].fBallY, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
			}
			
			//se o spark foi carregado com sucesso...
			if (Spark[PA])
			{ 
				if(P[PA].direcao == -1){ SPR_setHFlip(Spark[PA], TRUE); }
				SPR_setDepth(Spark[PA], 1); 
			}
			
			//reseta posicao da magia
			P[PA].fBallX=0; P[PA].fBallY=0; 
			
		}
		
		/////////////////////
		// MAGIAS x MAGIAS //
		///////////////////// ─=≡ΣO)) x ((O3≡=-
		
		if( FUNCAO_COLISAO(
		 (P[1].fBallX+20)-20, (P[1].fBallY+20)-20, (P[1].fBallX+20)+20, (P[1].fBallY+20)+20,
		 (P[2].fBallX+20)-20, (P[2].fBallY+20)-20, (P[2].fBallX+20)+20, (P[2].fBallY+20)+20
		)==1 && (P[PA].fBallX!=0 && P[PA].fBallY!=0) )
		{
			//desativa a magia P1
			if(P[1].fBallActive==1)
			{ 
				if(P[1].fBall)
				{ 
					SPR_releaseSprite(P[1].fBall); 
					P[1].fBall = NULL; 
				} 
				P[1].fBallActive=0;
				P[1].fBallX=0; P[1].fBallY=0; 
			}
			//desativa a magia P2
			if(P[2].fBallActive==1)
			{ 
				if(P[2].fBall)
				{ 
					SPR_releaseSprite(P[2].fBall); 
					P[2].fBall = NULL; 
				} 
				P[2].fBallActive=0;
				P[2].fBallX=0; P[2].fBallY=0; 
			}
		}
		
		
		//MAGIAS STARTUP (FSM CHANGESTATE)
		//Condicoes para que se possa soltar as magias, e posterior Acionamento delas!
		
		if( 
			(P[i].state >= STATE_PARADO && P[i].state <= STATE_CHUTE_FORTE_PERTO) || 
			P[i].state == STATE_ANDANDO_TRAS || 
			P[i].state == STATE_ANDANDO_FRENTE || 
			P[i].state == STATE_ROLAMENTO_TRAS || 
			P[i].state == STATE_ROLAMENTO_FRENTE || 
			P[i].state == STATE_LEVANTANDO_TRANSICAO || 
			P[i].state == STATE_FINAL_PULO 
		)
		{
			u8 magic_avaliable=1;
			
			if(P[i].id==1) //HAOHMARU
			{
				//700
				//Ougi Kogetsu Zan (Secret Skill Arc Moon Slash) 
				if // >, v, v>, > + P ; frente, baixo, baixo+frente, frente + Soco
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao== 1 && ( P[i].inputArray[2]==6 && P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao==-1 && ( P[i].inputArray[2]==4 && P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==1 ||  P[i].attackButton==2 || P[i].attackButton==3)
				)
				{
					if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); Spark1_countDown=0; }
					if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); Spark2_countDown=0; }
					PLAYER_STATE(i, STATE_ESPECIAL_700);
					magic_avaliable=0; 
				}
				
				//710
				//Ougi Senpuu Retsu Zan (Secret Skill Whirlwind Rending Slash)
				if // v, v>, > + P ; baixo, baixo+frente, frente + Soco
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao== 1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao==-1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==1 ||  P[i].attackButton==2 || P[i].attackButton==3)
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_710);
					magic_avaliable=0;
				}
				
				//720
				//Ougi Resshin Zan (Secret Skill Violent Quake Slash)
				if // >, v, v>, > + P ; baixo, baixo+frente, frente + Chute
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao== 1 && ( P[i].inputArray[2]==6 && P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao==-1 && ( P[i].inputArray[2]==4 && P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==4 ||  P[i].attackButton==5 || P[i].attackButton==6)
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_720);
					magic_avaliable=0;
				}
				
				//730
				//Sake Kougeki (Sake Attack)
				if // v, <v, < + LP ; baixo, baixo+tras, tras + Soco Fraco
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao==-1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao== 1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==1 ) //*Apenas com Soco Fraco!
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_730);
					magic_avaliable=0;
				}
				
			}//---end char; HAOHMARU
			
			if(P[i].id==2) //GILLIUS
			{
				//700
				//Rock Throw
				if // v, v>, > + P ; baixo, baixo+frente, frente + Soco
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao== 1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao==-1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==1 ||  P[i].attackButton==2 || P[i].attackButton==3 )
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_700);
					magic_avaliable=0;
				}
				
				//710
				//Axe Spin
				if // v, <v, < + P ; baixo, baixo+tras, tras + Soco
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao==-1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao== 1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==1 ||  P[i].attackButton==2 || P[i].attackButton==3 ) 
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_710);
					magic_avaliable=0;
				}
				
				//720
				//Shoulder Ram
				if // v, v>, > + K ; baixo, baixo+frente, frente + Chute
				(
					magic_avaliable==1 && 
					(
						(P[i].direcao== 1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[6] ) && (P[i].joyDirTimer[2]!=0) ) 
						|| 
						(P[i].direcao==-1 && ( P[i].joyDirTimer[2] < P[i].joyDirTimer[4] ) && (P[i].joyDirTimer[2]!=0) )
					) &&			
					( P[i].attackButton==4 ||  P[i].attackButton==5 || P[i].attackButton==6)
				)
				{
					PLAYER_STATE(i, STATE_ESPECIAL_720);
					magic_avaliable=0;
				}
				
			}//---end char; GILLIUS
			
			if(magic_avaliable==0)
			{
				//reset input array
				P[i].inputArray[0]=0; P[i].inputArray[1]=0; P[i].inputArray[2]=0; P[i].inputArray[3]=0; P[i].inputArray[4]=0;
			}
			
		}
		
		//HAOHMARU MAGIA 711 (FIREBALL)
		if(P[i].id==1 && P[i].state == STATE_ESPECIAL_710 && P[i].animFrame==14 && P[i].frameTimeAtual==1)
		{
			if(P[i].fBallActive==1){ if(P[i].fBall){ SPR_releaseSprite(P[i].fBall); P[i].fBall = NULL; } }
			P[i].fBallActive=1;
			P[i].fBallX = P[i].x-32+(32*P[i].direcao);
			P[i].fBallY = P[i].y-80;
			P[i].fBall = SPR_addSpriteExSafe(&spr_haohmaru_711, P[i].fBallX, P[i].fBallY, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			if(i==1){ SPR_setVRAMTileIndex(P[1].fBall,1711); } //define uma posicao especifica para o GFX na VRAM (magia do 'P1')
			if(P[i].fBall){ SPR_setDepth(P[i].fBall, 1); }
			if(P[i].direcao == -1){ SPR_setHFlip(P[i].fBall, TRUE); }
			P[i].fBallDirecao = P[i].direcao;
		}
		
		//GILLIUS MAGIA 701 (FIREBALL)
		if(P[i].id==2 && P[i].state == STATE_ESPECIAL_700 && P[i].animFrame==5 && P[i].frameTimeAtual==1)
		{
			if(P[i].fBallActive==1){ if(P[i].fBall){ SPR_releaseSprite(P[i].fBall); P[i].fBall = NULL; } }
			P[i].fBallActive=1;
			P[i].fBallX = P[i].x+(50*P[i].direcao); if(P[i].direcao==-1){P[i].fBallX-=50;}
			P[i].fBallY = P[i].y-100;
			P[i].fBall = SPR_addSpriteExSafe(&spr_gillius_701, P[i].fBallX, P[i].fBallY, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			if(i==1){ SPR_setVRAMTileIndex(P[1].fBall,1711); } //define uma posicao especifica para o GFX na VRAM (magia do 'P1')
			if(P[i].fBall){ SPR_setDepth(P[i].fBall, 1); }
			if(P[i].direcao == -1){ SPR_setHFlip(P[i].fBall, TRUE); }
			P[i].fBallDirecao = P[i].direcao;
		}
		
		//Rage Explosion! Rage timer!
		if( 
		P[i].rageTimerCountdown==RAGETIMER && P[i].energiaSP>=32 
		&& (P[i].state == STATE_PARADO || P[i].state == STATE_ABAIXADO || P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE) 
		&& gPodeMover==1
		)
		{
			P[i].rageTimerCountdown--;
			PLAYER_STATE(i, STATE_RAGE_EXPLOSION);
		}
		if(P[i].energiaSP>=32 && P[i].rageTimerCountdown<RAGETIMER && P[i].energiaBase>0 && gFrames>350){ if(P[i].rageTimerCountdown>0){ P[i].rageTimerCountdown--; } }
		if(P[i].rageTimerCountdown==0 && (P[i].state == STATE_PARADO || P[i].state == STATE_ABAIXADO)){ P[i].rageTimerCountdown=RAGETIMER; P[i].energiaSP=0; }
		
		//Vitoria
		if(
		 (P[PA].state == STATE_PARADO || P[PA].state == STATE_ABAIXADO || P[PA].state == STATE_ANDANDO_TRAS || P[PA].state == STATE_ANDANDO_FRENTE) 
		 && (P[PA].state != STATE_WIN1 || P[PA].state != STATE_WIN2 || P[PA].state != STATE_WIN3 || P[PA].state != STATE_WIN4) 
		 && (P[PR].energiaBase<=0)
		)
		{
			//Carrega 1 entre 4 poses de vitoria
			//Ajuste a probabilidade conforme preferir. gPing10 = 10% ; variacao de 0 a 9
			if(gPing10>=1 && gPing10<=3){ PLAYER_STATE(PA, STATE_WIN1); P[PA].wins++; }
			if(gPing10>=4 && gPing10<=6){ PLAYER_STATE(PA, STATE_WIN2); P[PA].wins++; }
			if(gPing10>=7 && gPing10<=9){ PLAYER_STATE(PA, STATE_WIN3); P[PA].wins++; }
			if(gPing10==0              ){ PLAYER_STATE(PA, STATE_WIN3); P[PA].wins++; } //Vc pode carregar uma pose diferente aqui, eu estou usando 3!
			
			//Exibe o contador de Wins correspondente
			if(PA==1) //P1
			{
				if(P[PA].wins>=1){ SPR_setVisibility(GE[12].sprite, VISIBLE); }
				if(P[PA].wins>=2){ SPR_setVisibility(GE[13].sprite, VISIBLE); }
			}
			if(PA==2) //P2
			{
				if(P[PA].wins>=1){ SPR_setVisibility(GE[15].sprite, VISIBLE); }
				if(P[PA].wins>=2){ SPR_setVisibility(GE[14].sprite, VISIBLE); }
			}
			
		}
		
	}
	
}

void FUNCAO_FSM_HITBOXES(u8 Player)
{
	bool reset_BBox=0;
	bool reset_HBox=0;
	
	if(P[Player].id==1) //haohmaru
	{
	if(P[Player].state == STATE_PARADO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_FRACO_LONGE && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_SOCO_FRACO_LONGE && P[Player].animFrame==8){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_MEDIO_LONGE && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]=125; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_MEDIO_LONGE && P[Player].animFrame==6){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_LONGE && P[Player].animFrame==8){ P[Player].dataHBox[0]= 70; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=170; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_LONGE && P[Player].animFrame==9){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FRACO_LONGE || P[Player].state == STATE_CHUTE_MEDIO_LONGE) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-30; }
	if((P[Player].state == STATE_CHUTE_FRACO_LONGE || P[Player].state == STATE_CHUTE_MEDIO_LONGE) && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_LONGE && P[Player].animFrame==3){ P[Player].dataHBox[0]= 30; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-70; }
	if(P[Player].state == STATE_CHUTE_FORTE_LONGE && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-60; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==5){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==6){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==9){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==10){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==18){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==19){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FRACO_PERTO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_CHUTE_FRACO_PERTO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_MEDIO_PERTO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_CHUTE_MEDIO_PERTO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_PERTO && P[Player].animFrame==3){ P[Player].dataHBox[0]=  1; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]= 60; P[Player].dataHBox[3]=-70; }
	if(P[Player].state == STATE_CHUTE_FORTE_PERTO && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ABAIXADO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if((P[Player].state == STATE_SOCO_FRACO_ABAIXADO || P[Player].state == STATE_SOCO_MEDIO_ABAIXADO) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 96; P[Player].dataHBox[3]=-10; }
	if((P[Player].state == STATE_SOCO_FRACO_ABAIXADO || P[Player].state == STATE_SOCO_MEDIO_ABAIXADO) && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_ABAIXADO && P[Player].animFrame== 8){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-140; P[Player].dataHBox[2]= 96; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_ABAIXADO && P[Player].animFrame==11){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FRACO_ABAIXADO || P[Player].state == STATE_CHUTE_MEDIO_ABAIXADO) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-10; }
	if((P[Player].state == STATE_CHUTE_FRACO_ABAIXADO || P[Player].state == STATE_CHUTE_MEDIO_ABAIXADO) && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_ABAIXADO && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-10; }
	if(P[Player].state == STATE_CHUTE_FORTE_ABAIXADO && P[Player].animFrame==4){ reset_HBox=1; }
	
	if((P[Player].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FRACO_AEREO_TRAS || P[Player].state == STATE_SOCO_FRACO_AEREO_FRENTE) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-40; }
	if((P[Player].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FRACO_AEREO_TRAS || P[Player].state == STATE_SOCO_FRACO_AEREO_FRENTE) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[Player].state == STATE_SOCO_MEDIO_AEREO_FRENTE) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-40; }
	if((P[Player].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[Player].state == STATE_SOCO_MEDIO_AEREO_FRENTE) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state == STATE_SOCO_FORTE_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FORTE_AEREO_TRAS || P[Player].state == STATE_SOCO_FORTE_AEREO_FRENTE) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-20; }
	if((P[Player].state == STATE_SOCO_FORTE_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FORTE_AEREO_TRAS || P[Player].state == STATE_SOCO_FORTE_AEREO_FRENTE) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[Player].state == STATE_CHUTE_FRACO_AEREO_FRENTE) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-30; }
	if((P[Player].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[Player].state == STATE_CHUTE_FRACO_AEREO_FRENTE) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[Player].state == STATE_CHUTE_MEDIO_AEREO_FRENTE) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-30; }
	if((P[Player].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[Player].state == STATE_CHUTE_MEDIO_AEREO_FRENTE) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FORTE_AEREO_TRAS || P[Player].state == STATE_CHUTE_FORTE_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 20; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-30; }
	if((P[Player].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FORTE_AEREO_TRAS || P[Player].state == STATE_CHUTE_FORTE_AEREO_FRENTE) && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==2){ reset_BBox=1; }
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state == STATE_ROLAMENTO_TRAS && P[Player].animFrame<=2){ reset_BBox=1; }
	if(P[Player].state == STATE_ROLAMENTO_FRENTE && P[Player].animFrame<=2){ reset_BBox=1; }
	
	if(P[Player].state == STATE_ABAIXANDO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_LEVANTANDO_TRANSICAO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state == STATE_ESPECIAL_700 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_ESPECIAL_700 && P[Player].animFrame==17){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESPECIAL_720 && P[Player].animFrame== 8){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-1; }
	if(P[Player].state == STATE_ESPECIAL_720 && P[Player].animFrame==12){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESPECIAL_730 && P[Player].animFrame== 6){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_ESPECIAL_730 && P[Player].animFrame== 7){ reset_HBox=1; }
	}
	
	if(P[Player].id==2) //gillius
	{
	if(P[Player].state == STATE_PARADO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_FRACO_LONGE && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=85; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_SOCO_FRACO_LONGE && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_MEDIO_LONGE && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_MEDIO_LONGE && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_LONGE && P[Player].animFrame==5){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_LONGE && P[Player].animFrame==9){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FRACO_LONGE && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=95; P[Player].dataHBox[3]=-20; }
	if(P[Player].state == STATE_CHUTE_FRACO_LONGE && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_MEDIO_LONGE && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-110; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-60; }
	if(P[Player].state == STATE_CHUTE_MEDIO_LONGE && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_LONGE && P[Player].animFrame==4){ P[Player].dataHBox[0]= 20; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-70; }
	if(P[Player].state == STATE_CHUTE_FORTE_LONGE && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-80; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-60; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-80; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-60; }
	if(P[Player].state == STATE_SOCO_FRACO_PERTO && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==2){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 50; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==4){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_MEDIO_PERTO && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=85; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==9){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_PERTO && P[Player].animFrame==11){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FRACO_PERTO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-50; P[Player].dataHBox[2]=50; P[Player].dataHBox[3]=-20; }
	if(P[Player].state == STATE_CHUTE_FRACO_PERTO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_MEDIO_PERTO && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-50; }
	if(P[Player].state == STATE_CHUTE_MEDIO_PERTO && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_PERTO && P[Player].animFrame==4){ P[Player].dataHBox[0]=  1; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]= 60; P[Player].dataHBox[3]=-70; }
	if(P[Player].state == STATE_CHUTE_FORTE_PERTO && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_ABAIXADO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_SOCO_FRACO_ABAIXADO && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_SOCO_FRACO_ABAIXADO && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_MEDIO_ABAIXADO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_SOCO_MEDIO_ABAIXADO && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_SOCO_FORTE_ABAIXADO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-40; }
	if(P[Player].state == STATE_SOCO_FORTE_ABAIXADO && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FRACO_ABAIXADO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-10; }
	if(P[Player].state == STATE_CHUTE_FRACO_ABAIXADO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_MEDIO_ABAIXADO && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-10; }
	if(P[Player].state == STATE_CHUTE_MEDIO_ABAIXADO && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state == STATE_CHUTE_FORTE_ABAIXADO && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_CHUTE_FORTE_ABAIXADO && P[Player].animFrame==4){ reset_HBox=1; }
	
	if((P[Player].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FRACO_AEREO_TRAS || P[Player].state == STATE_SOCO_FRACO_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FRACO_AEREO_TRAS || P[Player].state == STATE_SOCO_FRACO_AEREO_FRENTE) && P[Player].animFrame==4){ reset_HBox=1; }
	if((P[Player].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[Player].state == STATE_SOCO_MEDIO_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[Player].state == STATE_SOCO_MEDIO_AEREO_FRENTE) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state == STATE_SOCO_FORTE_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FORTE_AEREO_TRAS || P[Player].state == STATE_SOCO_FORTE_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state == STATE_SOCO_FORTE_AEREO_NEUTRO || P[Player].state == STATE_SOCO_FORTE_AEREO_TRAS || P[Player].state == STATE_SOCO_FORTE_AEREO_FRENTE) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[Player].state == STATE_CHUTE_FRACO_AEREO_FRENTE) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=60; P[Player].dataHBox[3]=-10; }
	if((P[Player].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[Player].state == STATE_CHUTE_FRACO_AEREO_FRENTE) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[Player].state == STATE_CHUTE_MEDIO_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]=-20; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-10; }
	if((P[Player].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[Player].state == STATE_CHUTE_MEDIO_AEREO_FRENTE) && P[Player].animFrame==4){ reset_HBox=1; }
	if((P[Player].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FORTE_AEREO_TRAS || P[Player].state == STATE_CHUTE_FORTE_AEREO_FRENTE) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-10; }
	if((P[Player].state == STATE_CHUTE_FORTE_AEREO_NEUTRO || P[Player].state == STATE_CHUTE_FORTE_AEREO_TRAS || P[Player].state == STATE_CHUTE_FORTE_AEREO_FRENTE) && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==2){ reset_BBox=1; }
	if(P[Player].state == STATE_ESQUIVA_BAIXO && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state == STATE_ROLAMENTO_TRAS && P[Player].animFrame<=2){ reset_BBox=1; }
	if(P[Player].state == STATE_ROLAMENTO_FRENTE && P[Player].animFrame<=2){ reset_BBox=1; }
	
	if(P[Player].state == STATE_ABAIXANDO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state == STATE_LEVANTANDO_TRANSICAO && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state == STATE_ESPECIAL_710 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= -40; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=40; P[Player].dataHBox[3]=-10; }
	if(P[Player].state == STATE_ESPECIAL_710 && P[Player].animFrame==17){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESPECIAL_720 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-20; }
	if(P[Player].state == STATE_ESPECIAL_720 && P[Player].animFrame== 7){ reset_HBox=1; }
	
	if(P[Player].state == STATE_ESPECIAL_730 && P[Player].animFrame== 6){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-30; }
	if(P[Player].state == STATE_ESPECIAL_730 && P[Player].animFrame== 7){ reset_HBox=1; }
	}
	
	
	if(P[Player].direcao==-1)//dataHBox[0]<P[Player].dataHBox[2]) //Normaliza a box
	{
		s16 a;
		a = P[Player].dataHBox[0];
		P[Player].dataHBox[0] = P[Player].dataHBox[2];
		P[Player].dataHBox[2] = a;
		P[Player].dataHBox[0] = P[Player].dataHBox[0] * P[Player].direcao;
		P[Player].dataHBox[2] = P[Player].dataHBox[2] * P[Player].direcao;
	}
	
	//padroes
	if(P[Player].state == STATE_PARADO && P[Player].animFrame==1){ reset_HBox=1; } //parado
	if( (P[Player].state >= STATE_INTRO && P[Player].state <= STATE_RAGE_EXPLOSION) /*&& P[Player].animFrame==1*/ ){ reset_BBox=1; } //win poses, time over; rage explosion
	if( (P[Player].state == STATE_CAINDO) /*&& P[Player].animFrame==1*/ ){ reset_BBox=1; } //win poses, time over; rage explosion
	
	if(Player==1 && (P[2].state == STATE_DEFESA_PE_APLICADA || P[2].state == STATE_DEFESA_ABAIXADO_APLICADA)){ reset_HBox=1; }
	if(Player==2 && (P[1].state == STATE_DEFESA_PE_APLICADA || P[1].state == STATE_DEFESA_ABAIXADO_APLICADA)){ reset_HBox=1; }
	
	//resets
	if(reset_HBox==1){ P[Player].dataHBox[0]=0; P[Player].dataHBox[1]=0; P[Player].dataHBox[2]=0; P[Player].dataHBox[3]=0; } //Hit Boxes
	if(reset_BBox==1){ P[Player].dataBBox[0]=0; P[Player].dataBBox[1]=0; P[Player].dataBBox[2]=0; P[Player].dataBBox[3]=0; } //Body Boxes
	
}
