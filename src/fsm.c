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
				(P[PR].state>=101 && P[PR].state<=106) || 
				(P[PR].state>=151 && P[PR].state<=156) || 
				(P[PR].state>=201 && P[PR].state<=206) || 
				(P[PR].state>=301 && P[PR].state<=306) || 
				(P[PR].state>=311 && P[PR].state<=316) || 
				(P[PR].state>=321 && P[PR].state<=326) || 
				(P[PR].state>=700 && P[PR].state<=790) || 
				(distancia_Player_X_Magia<=70)
			) && 
			(
			  (
			    (P[PA].direcao== 1 && P[PA].key_JOY_LEFT_status ==2) || 
			    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==2)
			  ) && (P[PA].state==100 || P[PA].state==200 || P[PA].state==410 || P[PA].state==420)
			) 
		){
			if(P[i].key_JOY_DOWN_status==2){ PLAYER_STATE(i,207); }else{ PLAYER_STATE(i,107); } //defesa (107 = em pe ; 207 = abaixado)
		}
		
		//soltou a defesa - EM PE
		if( (P[i].state==107 || P[i].state==108) && 
		(
		    (P[PA].direcao==1 && P[PA].key_JOY_LEFT_status==0) || 
		    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==0)
		)
		){ PLAYER_STATE(i,109); } 
		
		//defesa se encerrou com o final do ataque - EM PE
		if(P[i].state==108 && 
			(P[PR].state==100 || P[PR].state==200 || P[PR].state==410 || P[PR].state==420)
		){ PLAYER_STATE(i,109); } 
		
		//soltou a defesa - ABAIXADO
		if( (P[i].state==207 || P[i].state==208) && 
		(
		    (P[PA].direcao==1 && P[PA].key_JOY_LEFT_status==0) || 
		    (P[PA].direcao==-1 && P[PA].key_JOY_RIGHT_status==0)
		)
		){ PLAYER_STATE(i,209); } 
		
		//defesa se encerrou com o final do ataque - ABAIXADO
		if(P[i].state==208 && 
			(P[PR].state==100 || P[PR].state==200 || P[PR].state==410 || P[PR].state==420)
		){ PLAYER_STATE(i,209); } 
		
		//variacao de defesa em pe e abaixado
		if(P[i].state==108 && P[i].key_JOY_DOWN_status==2){ PLAYER_STATE(i,208); }
		if(P[i].state==208 && P[i].key_JOY_DOWN_status==0){ PLAYER_STATE(i,108); }
		
		//golpes normais!
		if(gDistancia>64)
		{
			//golpes em pe de longe
			if(P[i].key_JOY_X_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,101); }
			if(P[i].key_JOY_Y_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,102); }
			if(P[i].key_JOY_Z_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,103); }
			if(P[i].key_JOY_A_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,104); }
			if(P[i].key_JOY_B_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,105); }
			if(P[i].key_JOY_C_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,106); }
		}else{
			//golpes em pe de perto
			if(P[i].key_JOY_X_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,151); }
			if(P[i].key_JOY_Y_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,152); }
			if(P[i].key_JOY_Z_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,153); }
			if(P[i].key_JOY_A_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,154); }
			if(P[i].key_JOY_B_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,155); }
			if(P[i].key_JOY_C_status==1 && (P[i].state==100 || P[i].state==481 || P[i].state==410 || P[i].state==420)){ PLAYER_STATE(i,156); }
		}
		
		//golpes abaixados
		if(P[i].key_JOY_X_status==1 && P[i].state==200){ PLAYER_STATE(i,201); }
		if(P[i].key_JOY_Y_status==1 && P[i].state==200){ PLAYER_STATE(i,202); }
		if(P[i].key_JOY_Z_status==1 && P[i].state==200){ PLAYER_STATE(i,203); }
		if(P[i].key_JOY_A_status==1 && P[i].state==200){ PLAYER_STATE(i,204); }
		if(P[i].key_JOY_B_status==1 && P[i].state==200){ PLAYER_STATE(i,205); }
		if(P[i].key_JOY_C_status==1 && P[i].state==200){ PLAYER_STATE(i,206); }
		
		//abaixando ; esquivando; levantando
		if((P[i].key_JOY_DOWN_status==1 || P[i].key_JOY_DOWN_status==2) && (P[i].state==100 || P[i].state==410 || P[i].state==420))
		{ 
			if(P[i].key_JOY_countdown[2]==0){ PLAYER_STATE(i,601); }else{ PLAYER_STATE(i,470); } //abaixar ou esquivar
		}
		if(P[i].key_JOY_DOWN_status==0 && P[i].state==200){ PLAYER_STATE(i,602); } //levantar
		
		//interrupcao da esquiva abaixada
		if(P[i].state==470 && P[i].animFrame==2 && P[i].key_JOY_DOWN_status==0)
		{ 
			P[i].animFrame=3; 
			P[i].frameTimeAtual=1; 
			P[i].frameTimeTotal=P[i].dataAnim[3]; 
		}
		
		//virando de lado (mudanca de estado)
		if(P[PA].direcao== 1 && P[PR].x<P[PA].x && P[PA].state==100){ PLAYER_STATE(i,607); P[PA].direcao=-1; }
		if(P[PA].direcao==-1 && P[PA].x<P[PR].x && P[PA].state==100){ PLAYER_STATE(i,607); P[PA].direcao= 1; }
		if(P[PA].direcao== 1 && P[PR].x<P[PA].x && P[PA].state==200){ PLAYER_STATE(i,608); P[PA].direcao=-1; }
		if(P[PA].direcao==-1 && P[PA].x<P[PR].x && P[PA].state==200){ PLAYER_STATE(i,608); P[PA].direcao= 1; }
		
		//ini pulos
		if((P[i].key_JOY_UP_status==1 || P[i].key_JOY_UP_status==2) && (P[i].state==100 || P[i].state==410 || P[i].state==420 || P[i].state==602))
		{ 
			if(P[i].key_JOY_RIGHT_status==2){ if(P[i].direcao==1){PLAYER_STATE(i,605);}else{PLAYER_STATE(i,603);} }
			if(P[i].key_JOY_RIGHT_status==0 && P[i].key_JOY_LEFT_status==0)PLAYER_STATE(i,604); 
			if(P[i].key_JOY_LEFT_status ==2){ if(P[i].direcao==1){PLAYER_STATE(i,603);}else{PLAYER_STATE(i,605);} }
		}
		
		//end pulos
		if((P[i].state==300 || P[i].state==310 || P[i].state==320) && P[i].y>=gAlturaPiso){ P[i].y=gAlturaPiso; P[i].puloTimer=0; P[i].hSpeed=0; PLAYER_STATE(i,606); }
		if((P[i].state>=301 && P[i].state<=326) && P[i].y>=gAlturaPiso){ P[i].y=gAlturaPiso; P[i].hSpeed=0; PLAYER_STATE(i,606); } 
		
		//golpes aereos
		if(P[i].key_JOY_X_status==1 && P[i].state==300){ PLAYER_STATE(i,301); }
		if(P[i].key_JOY_Y_status==1 && P[i].state==300){ PLAYER_STATE(i,302); }
		if(P[i].key_JOY_Z_status==1 && P[i].state==300){ PLAYER_STATE(i,303); }
		if(P[i].key_JOY_A_status==1 && P[i].state==300){ PLAYER_STATE(i,304); }
		if(P[i].key_JOY_B_status==1 && P[i].state==300){ PLAYER_STATE(i,305); }
		if(P[i].key_JOY_C_status==1 && P[i].state==300){ PLAYER_STATE(i,306); }
		
		if(P[i].key_JOY_X_status==1 && P[i].state==310){ PLAYER_STATE(i,311); }
		if(P[i].key_JOY_Y_status==1 && P[i].state==310){ PLAYER_STATE(i,312); }
		if(P[i].key_JOY_Z_status==1 && P[i].state==310){ PLAYER_STATE(i,313); }
		if(P[i].key_JOY_A_status==1 && P[i].state==310){ PLAYER_STATE(i,314); }
		if(P[i].key_JOY_B_status==1 && P[i].state==310){ PLAYER_STATE(i,315); }
		if(P[i].key_JOY_C_status==1 && P[i].state==310){ PLAYER_STATE(i,316); }
		
		if(P[i].key_JOY_X_status==1 && P[i].state==320){ PLAYER_STATE(i,321); }
		if(P[i].key_JOY_Y_status==1 && P[i].state==320){ PLAYER_STATE(i,322); }
		if(P[i].key_JOY_Z_status==1 && P[i].state==320){ PLAYER_STATE(i,323); }
		if(P[i].key_JOY_A_status==1 && P[i].state==320){ PLAYER_STATE(i,324); }
		if(P[i].key_JOY_B_status==1 && P[i].state==320){ PLAYER_STATE(i,325); }
		if(P[i].key_JOY_C_status==1 && P[i].state==320){ PLAYER_STATE(i,326); }
		
		//andando
		if(P[i].direcao==1)
		{
			if(P[i].key_JOY_LEFT_status>0 && P[i].state==100){ 
				if(P[i].key_JOY_countdown[4]==0){ PLAYER_STATE(i,410); }else{ PLAYER_STATE(i,471); }}
			if(P[i].key_JOY_RIGHT_status>0 && P[i].state==100){ 
				if(P[i].key_JOY_countdown[6]==0){ PLAYER_STATE(i,420); }else{ PLAYER_STATE(i,472); }}
			
			if(P[i].key_JOY_LEFT_status==0 && P[i].state==410){ PLAYER_STATE(i,100); } //end walk
			if(P[i].key_JOY_RIGHT_status==0 && P[i].state==420){ PLAYER_STATE(i,100); }
		}else{
			if(P[i].key_JOY_LEFT_status>0 && P[i].state==100){ 
				if(P[i].key_JOY_countdown[4]==0){ PLAYER_STATE(i,420); }else{ PLAYER_STATE(i,472);}}
			if(P[i].key_JOY_RIGHT_status>0 && P[i].state==100){ 
				if(P[i].key_JOY_countdown[6]==0){ PLAYER_STATE(i,410); }else{ PLAYER_STATE(i,471);}}
			
			if(P[i].key_JOY_LEFT_status ==0 && P[i].state==420){ P[i].hSpeed=0; PLAYER_STATE(i,100); } //end walk
			if(P[i].key_JOY_RIGHT_status==0 && P[i].state==410){ P[i].hSpeed=0; PLAYER_STATE(i,100); }
		}
		
		//key_JOY_countdown é um timer regressivo, ativado quando se aperta algum botao direcional, usado para Corrida e Esquiva, entre outros...
		if(P[i].key_JOY_countdown[8]>0){ P[i].key_JOY_countdown[8]--; }
		if(P[i].key_JOY_countdown[2]>0){ P[i].key_JOY_countdown[2]--; }
		if(P[i].key_JOY_countdown[4]>0){ P[i].key_JOY_countdown[4]--; }
		if(P[i].key_JOY_countdown[6]>0){ P[i].key_JOY_countdown[6]--; }
		
		//ativacao de 'key_JOY_countdown'...
		if(P[i].state==410 || P[i].state==420 || P[i].state==601 || P[i].state==603 || P[i].state==604 || P[i].state==605)
		{
			if(P[i].key_JOY_UP_status   ==1){ P[i].key_JOY_countdown[8]=12; P[i].key_JOY_countdown[2]=0; }
			if(P[i].key_JOY_LEFT_status ==1){ P[i].key_JOY_countdown[4]=12; P[i].key_JOY_countdown[6]=0; }
			if(P[i].key_JOY_RIGHT_status==1){ P[i].key_JOY_countdown[6]=12; P[i].key_JOY_countdown[4]=0; }
			if(P[i].key_JOY_DOWN_status ==1){ P[i].key_JOY_countdown[2]=12; P[i].key_JOY_countdown[8]=0; P[i].key_JOY_countdown[4]=0; P[i].key_JOY_countdown[6]=0; }
		}
		
		//time over decision; timeover
		if((gClockLTimer==0 && gClockRTimer==0) && P[1].state!=611 && P[1].state!=615)
		{
			bool updateWinsFlag=0;
			if(P[1].energiaBase> P[2].energiaBase){ PLAYER_STATE(1,611); P[1].wins++; updateWinsFlag=1; PLAYER_STATE(2,615); }
			if(P[1].energiaBase< P[2].energiaBase){ PLAYER_STATE(2,611); P[2].wins++; updateWinsFlag=2; PLAYER_STATE(1,615); }
			if(P[1].energiaBase==P[2].energiaBase){ PLAYER_STATE(1,615); PLAYER_STATE(2,615); }
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
			if(P[PR].state==107 || P[PR].state==108 || P[PR].state==109 || P[PR].state==110 ||
			   P[PR].state==207 || P[PR].state==208 || P[PR].state==209 || P[PR].state==210) 
			{
				//DEFENDEU!
				if(P[PR].state>=107 && P[PR].state<=109){ PLAYER_STATE(PR,110); P[PR].hitPause=12; }
				if(P[PR].state>=207 && P[PR].state<=209){ PLAYER_STATE(PR,210); P[PR].hitPause=12; }
				
				u8 AlturaDoHit = P[PA].y+P[PA].dataHBox[3];
				P[PA].dataHBox[0]=0; P[PA].dataHBox[1]=0; P[PA].dataHBox[2]=0; P[PA].dataHBox[3]=0; //desativa a hitbox
				
				if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
				if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
				
				if(
					P[PA].state==104 || P[PA].state==105 || P[PA].state==106 ||
					P[PA].state==154 || P[PA].state==155 || P[PA].state==156 || 
					P[PA].state==204 || P[PA].state==205 || P[PA].state==206 || 
					P[PA].state==304 || P[PA].state==305 || P[PA].state==306 || 
					P[PA].state==314 || P[PA].state==315 || P[PA].state==316 || 
					P[PA].state==324 || P[PA].state==325 || P[PA].state==326
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
				if(P[PA].state==101){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,506);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state==102){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 5; }
				if(P[PA].state==103)
				{ 
					if(P[1].fBallActive==1 || P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){ PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,503);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){ PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,508);} SparkType= 3; 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11);
				}
				if(P[PA].state==104){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,501);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=10; }
				if(P[PA].state==105){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=11; }
				if(P[PA].state==106){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,503);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType=12; }
				
				//golpes de perto
				if(P[PA].state==151){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,506);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state==152){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 1; }
				if(P[PA].state==153 && P[PA].animFrame<12){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,503);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 2; }
				if(P[PA].state==153 && P[PA].animFrame>12)
				{ 
					if(P[1].fBallActive==1 && P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,503);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,508);} SparkType= 1;/*3*/ 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,3); 
				} 
				if(P[PA].state==154){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,506);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 10; }
				if(P[PA].state==155){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 11; }
				if(P[PA].state==156){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,503);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 12; }
				
				//golpes abaixado
				if(P[PA].state==201){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,506);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=  1; }
				if(P[PA].state==202){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=  2; }
				if(P[PA].state==203)
				{ 
					if(P[1].fBallActive==1 && P[2].fBallActive==1)
					{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,503);} SparkType= 0; 
					}else{
						if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);
						}else{PLAYER_STATE(PR,508);} SparkType=  2;/*3*/ 
					} 
					FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); 
				} 
				if(P[PA].state==204){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,506);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 10; }
				if(P[PA].state==205){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,507);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 11; }
				if(P[PA].state==206){ PLAYER_STATE(PR,550); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 12; }
				
				//golpes aereos
				if(P[PA].state==301 || P[PA].state==311 || P[PA].state==321){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,501);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				if(P[PA].state==302 || P[PA].state==312 || P[PA].state==322){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,502);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType= 2; }
				if(P[PA].state==303 || P[PA].state==313 || P[PA].state==323){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,503);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType= 3; }
				if(P[PA].state==304 || P[PA].state==314 || P[PA].state==324){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,501);} FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType=10; }
				if(P[PA].state==305 || P[PA].state==315 || P[PA].state==325){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,502);} FUNCAO_UPDATE_LIFESP(PR,1,-20); FUNCAO_UPDATE_LIFESP(PR,2,6); SparkType=11; }
				if(P[PA].state==306 || P[PA].state==316 || P[PA].state==326){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,503);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,11); SparkType=12; }
				
				//MAGIAS HITS /////////////////////////////
				
				//HAOHMARU ID:1
				if(P[PA].id==1)
				{
					if(P[PA].state==700){ PLAYER_STATE(PR,550); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state==720){ PLAYER_STATE(PR,550); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state==730){ if(P[PR].y!=gAlturaPiso){PLAYER_STATE(PR,550);}else{PLAYER_STATE(PR,508);} FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType=12; }
				}
				//GILLIUS ID:2
				if(P[PA].id==2)
				{
					if(P[PA].state==710){ PLAYER_STATE(PR,550); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state==720){ PLAYER_STATE(PR,550); FUNCAO_UPDATE_LIFESP(PR,1,-30); FUNCAO_UPDATE_LIFESP(PR,2,5); SparkType= 1; }
					if(P[PA].state==730){ PLAYER_STATE(PR,506); FUNCAO_UPDATE_LIFESP(PR,1,-10); FUNCAO_UPDATE_LIFESP(PR,2,3); SparkType= 1; }
				}
				
				///////////////////////////////////////////
				
				//oponente zero energy = dead
				if((P[PR].state>=501 && P[PR].state<=508) && P[PR].energiaBase==0)
				{ 
					SPR_releaseSprite(GE[11].sprite);
					PLAYER_STATE(PR,550); 
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
			if(P[PR].state==107 || P[PR].state==108 || P[PR].state==109 || P[PR].state==110 ||
			   P[PR].state==207 || P[PR].state==208 || P[PR].state==209 || P[PR].state==210) 
			{
				//DEFENDEU!
				if(P[PR].state>=107 && P[PR].state<=109){ PLAYER_STATE(PR,110); P[PR].hitPause=20; }
				if(P[PR].state>=207 && P[PR].state<=209){ PLAYER_STATE(PR,210); P[PR].hitPause=20; }
			}else{
				//NAO DEFENDEU!
				P[PR].hitPause=20;
				FUNCAO_UPDATE_LIFESP(PR,1,-30); 
				FUNCAO_UPDATE_LIFESP(PR,2, 11);
				if(P[PR].energiaBase==0)
				{
					PLAYER_STATE(PR,550);
				}else{
					if(P[PR].y!=gAlturaPiso)
					{ 
						if(P[PA].id==1)
						{
							PLAYER_STATE(PR,516); //magia do haomaru faz o oponente subir
						}else{
							PLAYER_STATE(PR,550); //cai apos cair sobre a magia
						}
						
					}else{
						if(P[PA].id==1)
						{
							PLAYER_STATE(PR,516); //magia do haomaru faz o oponente subir
						}else{
							PLAYER_STATE(PR,503); //recebe o hit da magia em pe
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
			(P[i].state >= 100 && P[i].state <= 156) || 
			P[i].state == 410 || 
			P[i].state == 420 || 
			P[i].state == 471 || 
			P[i].state == 472 || 
			P[i].state == 602 || 
			P[i].state == 606 
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
					PLAYER_STATE(i,700);
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
					PLAYER_STATE(i,710);
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
					PLAYER_STATE(i,720);
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
					PLAYER_STATE(i,730);
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
					PLAYER_STATE(i,700);
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
					PLAYER_STATE(i,710);
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
					PLAYER_STATE(i,720);
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
		if(P[i].id==1 && P[i].state==710 && P[i].animFrame==14 && P[i].frameTimeAtual==1)
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
		if(P[i].id==2 && P[i].state==700 && P[i].animFrame==5 && P[i].frameTimeAtual==1)
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
		&& (P[i].state==100 || P[i].state==200 || P[i].state==410 || P[i].state==420) 
		&& gPodeMover==1
		)
		{
			P[i].rageTimerCountdown--;
			PLAYER_STATE(i,618);
		}
		if(P[i].energiaSP>=32 && P[i].rageTimerCountdown<RAGETIMER && P[i].energiaBase>0 && gFrames>350){ if(P[i].rageTimerCountdown>0){ P[i].rageTimerCountdown--; } }
		if(P[i].rageTimerCountdown==0 && (P[i].state==100 || P[i].state==200)){ P[i].rageTimerCountdown=RAGETIMER; P[i].energiaSP=0; }
		
		//Vitoria
		if(
		 (P[PA].state==100 || P[PA].state==200 || P[PA].state==410 || P[PA].state==420) 
		 && (P[PA].state!=611 || P[PA].state!=612 || P[PA].state!=613 || P[PA].state!=614) 
		 && (P[PR].energiaBase<=0)
		)
		{
			//Carrega 1 entre 4 poses de vitoria
			//Ajuste a probabilidade conforme preferir. gPing10 = 10% ; variacao de 0 a 9
			if(gPing10>=1 && gPing10<=3){ PLAYER_STATE(PA,611); P[PA].wins++; }
			if(gPing10>=4 && gPing10<=6){ PLAYER_STATE(PA,612); P[PA].wins++; }
			if(gPing10>=7 && gPing10<=9){ PLAYER_STATE(PA,613); P[PA].wins++; }
			if(gPing10==0              ){ PLAYER_STATE(PA,613); P[PA].wins++; } //Vc pode carregar uma pose diferente aqui, eu estou usando 3!
			
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
	if(P[Player].state==100 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==101 && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==101 && P[Player].animFrame==8){ reset_HBox=1; }
	if(P[Player].state==102 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]=125; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==102 && P[Player].animFrame==6){ reset_HBox=1; }
	if(P[Player].state==103 && P[Player].animFrame==8){ P[Player].dataHBox[0]= 70; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=170; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==103 && P[Player].animFrame==9){ reset_HBox=1; }
	if((P[Player].state==104 || P[Player].state==105) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-30; }
	if((P[Player].state==104 || P[Player].state==105) && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==106 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 30; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-70; }
	if(P[Player].state==106 && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state==151 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-60; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==151 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==152 && P[Player].animFrame==5){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==152 && P[Player].animFrame==6){ reset_HBox=1; }
	if(P[Player].state==153 && P[Player].animFrame==9){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==153 && P[Player].animFrame==10){ reset_HBox=1; }
	if(P[Player].state==153 && P[Player].animFrame==18){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==153 && P[Player].animFrame==19){ reset_HBox=1; }
	if(P[Player].state==154 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==154 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==155 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==155 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==156 && P[Player].animFrame==3){ P[Player].dataHBox[0]=  1; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]= 60; P[Player].dataHBox[3]=-70; }
	if(P[Player].state==156 && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state==200 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if((P[Player].state==201 || P[Player].state==202) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 96; P[Player].dataHBox[3]=-10; }
	if((P[Player].state==201 || P[Player].state==202) && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==203 && P[Player].animFrame== 8){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-140; P[Player].dataHBox[2]= 96; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==203 && P[Player].animFrame==11){ reset_HBox=1; }
	if((P[Player].state==204 || P[Player].state==205) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-10; }
	if((P[Player].state==204 || P[Player].state==205) && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==206 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-10; }
	if(P[Player].state==206 && P[Player].animFrame==4){ reset_HBox=1; }
	
	if((P[Player].state==301 || P[Player].state==311 || P[Player].state==321) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-40; }
	if((P[Player].state==301 || P[Player].state==311 || P[Player].state==321) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state==302 || P[Player].state==312 || P[Player].state==322) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-40; }
	if((P[Player].state==302 || P[Player].state==312 || P[Player].state==322) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state==303 || P[Player].state==313 || P[Player].state==323) && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-20; }
	if((P[Player].state==303 || P[Player].state==313 || P[Player].state==323) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state==304 || P[Player].state==314 || P[Player].state==324) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-30; }
	if((P[Player].state==304 || P[Player].state==314 || P[Player].state==324) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state==305 || P[Player].state==315 || P[Player].state==325) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-30; }
	if((P[Player].state==305 || P[Player].state==315 || P[Player].state==325) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state==306 || P[Player].state==316 || P[Player].state==326) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 20; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-30; }
	if((P[Player].state==306 || P[Player].state==316 || P[Player].state==326) && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state==470 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==470 && P[Player].animFrame==2){ reset_BBox=1; }
	if(P[Player].state==470 && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state==471 && P[Player].animFrame<=2){ reset_BBox=1; }
	if(P[Player].state==472 && P[Player].animFrame<=2){ reset_BBox=1; }
	
	if(P[Player].state==601 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==602 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state==700 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==700 && P[Player].animFrame==17){ reset_HBox=1; }
	
	if(P[Player].state==720 && P[Player].animFrame== 8){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-1; }
	if(P[Player].state==720 && P[Player].animFrame==12){ reset_HBox=1; }
	
	if(P[Player].state==730 && P[Player].animFrame== 6){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==730 && P[Player].animFrame== 7){ reset_HBox=1; }
	}
	
	if(P[Player].id==2) //gillius
	{
	if(P[Player].state==100 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==101 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=85; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==101 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==102 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 65; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==102 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==103 && P[Player].animFrame==5){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==103 && P[Player].animFrame==9){ reset_HBox=1; }
	if(P[Player].state==104 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=95; P[Player].dataHBox[3]=-20; }
	if(P[Player].state==104 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==105 && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-110; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-60; }
	if(P[Player].state==105 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==106 && P[Player].animFrame==4){ P[Player].dataHBox[0]= 20; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-70; }
	if(P[Player].state==106 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==151 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-80; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-60; }
	if(P[Player].state==151 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==151 && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-80; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-60; }
	if(P[Player].state==151 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==152 && P[Player].animFrame==2){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==152 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=90; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==152 && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 50; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==152 && P[Player].animFrame==4){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 30; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==152 && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state==153 && P[Player].animFrame==4){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=85; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==153 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==153 && P[Player].animFrame==9){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==153 && P[Player].animFrame==11){ reset_HBox=1; }
	if(P[Player].state==154 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-50; P[Player].dataHBox[2]=50; P[Player].dataHBox[3]=-20; }
	if(P[Player].state==154 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==155 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=-70; P[Player].dataHBox[2]=80; P[Player].dataHBox[3]=-50; }
	if(P[Player].state==155 && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state==156 && P[Player].animFrame==4){ P[Player].dataHBox[0]=  1; P[Player].dataHBox[1]=-120; P[Player].dataHBox[2]= 60; P[Player].dataHBox[3]=-70; }
	if(P[Player].state==156 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==200 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==201 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==201 && P[Player].animFrame==4){ reset_HBox=1; }
	if(P[Player].state==202 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==202 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==203 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 70; P[Player].dataHBox[2]=120; P[Player].dataHBox[3]=-40; }
	if(P[Player].state==203 && P[Player].animFrame==5){ reset_HBox=1; }
	if(P[Player].state==204 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]= 90; P[Player].dataHBox[3]=-10; }
	if(P[Player].state==204 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==205 && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 30; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-10; }
	if(P[Player].state==205 && P[Player].animFrame==3){ reset_HBox=1; }
	if(P[Player].state==206 && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=100; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==206 && P[Player].animFrame==4){ reset_HBox=1; }
	
	if((P[Player].state==301 || P[Player].state==311 || P[Player].state==321) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state==301 || P[Player].state==311 || P[Player].state==321) && P[Player].animFrame==4){ reset_HBox=1; }
	if((P[Player].state==302 || P[Player].state==312 || P[Player].state==322) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state==302 || P[Player].state==312 || P[Player].state==322) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state==303 || P[Player].state==313 || P[Player].state==323) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]= 80; P[Player].dataHBox[3]=-1; }
	if((P[Player].state==303 || P[Player].state==313 || P[Player].state==323) && P[Player].animFrame==6){ reset_HBox=1; }
	if((P[Player].state==304 || P[Player].state==314 || P[Player].state==324) && P[Player].animFrame==2){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=60; P[Player].dataHBox[3]=-10; }
	if((P[Player].state==304 || P[Player].state==314 || P[Player].state==324) && P[Player].animFrame==3){ reset_HBox=1; }
	if((P[Player].state==305 || P[Player].state==315 || P[Player].state==325) && P[Player].animFrame==3){ P[Player].dataHBox[0]=-20; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-10; }
	if((P[Player].state==305 || P[Player].state==315 || P[Player].state==325) && P[Player].animFrame==4){ reset_HBox=1; }
	if((P[Player].state==306 || P[Player].state==316 || P[Player].state==326) && P[Player].animFrame==3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-10; }
	if((P[Player].state==306 || P[Player].state==316 || P[Player].state==326) && P[Player].animFrame==4){ reset_HBox=1; }
	
	if(P[Player].state==470 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==470 && P[Player].animFrame==2){ reset_BBox=1; }
	if(P[Player].state==470 && P[Player].animFrame==3){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 90; P[Player].dataBBox[2]= 15; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state==471 && P[Player].animFrame<=2){ reset_BBox=1; }
	if(P[Player].state==472 && P[Player].animFrame<=2){ reset_BBox=1; }
	
	if(P[Player].state==601 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	if(P[Player].state==602 && P[Player].animFrame==1){ P[Player].dataBBox[0]=-20; P[Player].dataBBox[1]=- 70; P[Player].dataBBox[2]= 20; P[Player].dataBBox[3]=  0; }
	
	if(P[Player].state==710 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= -40; P[Player].dataHBox[1]=-100; P[Player].dataHBox[2]=40; P[Player].dataHBox[3]=-10; }
	if(P[Player].state==710 && P[Player].animFrame==17){ reset_HBox=1; }
	
	if(P[Player].state==720 && P[Player].animFrame== 3){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=70; P[Player].dataHBox[3]=-20; }
	if(P[Player].state==720 && P[Player].animFrame== 7){ reset_HBox=1; }
	
	if(P[Player].state==730 && P[Player].animFrame== 6){ P[Player].dataHBox[0]= 10; P[Player].dataHBox[1]=- 50; P[Player].dataHBox[2]=110; P[Player].dataHBox[3]=-30; }
	if(P[Player].state==730 && P[Player].animFrame== 7){ reset_HBox=1; }
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
	if(P[Player].state==100 && P[Player].animFrame==1){ reset_HBox=1; } //parado
	if( (P[Player].state>=610 && P[Player].state<=618) /*&& P[Player].animFrame==1*/ ){ reset_BBox=1; } //win poses, time over; rage explosion
	if( (P[Player].state==550) /*&& P[Player].animFrame==1*/ ){ reset_BBox=1; } //win poses, time over; rage explosion
	
	if(Player==1 && (P[2].state==110 || P[2].state==210)){ reset_HBox=1; }
	if(Player==2 && (P[1].state==110 || P[1].state==210)){ reset_HBox=1; }
	
	//resets
	if(reset_HBox==1){ P[Player].dataHBox[0]=0; P[Player].dataHBox[1]=0; P[Player].dataHBox[2]=0; P[Player].dataHBox[3]=0; } //Hit Boxes
	if(reset_BBox==1){ P[Player].dataBBox[0]=0; P[Player].dataBBox[1]=0; P[Player].dataBBox[2]=0; P[Player].dataBBox[3]=0; } //Body Boxes
	
}
