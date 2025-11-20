#include "physics.h"
#include "game_globals.h"
#include "player.h"
#include "collision.h"

void FUNCAO_PHYSICS() //FISICA!
{
	for(i=1; i<=2; i++)
	{
		/*samsho2*/
		//-----------------------------------------------------------------------------------------
		if(P[i].id==1) //HAOHMARU
		{
			//Slide (DOWN + HIGH KICK)
			if(P[i].state == STATE_CHUTE_FORTE_ABAIXADO && P[i].animFrame<=3 && (P[1].hitPause==0 && P[2].hitPause==0) ) 
			{
				P[i].hSpeed=1;
				P[i].x+=P[i].hSpeed*P[i].direcao;
			}
			
			//impulso do 'shoryuken'
			if(P[i].state == STATE_ESPECIAL_700) 
			{
				if(P[i].animFrame==16 && P[i].frameTimeAtual==1 && P[i].y==gAlturaPiso)
				{
					if(P[i].attackPower == 1){ P[i].impulsoY = impulsoPadrao  ; }
					if(P[i].attackPower == 2){ P[i].impulsoY = impulsoPadrao-4; }
					if(P[i].attackPower == 3){ P[i].impulsoY = impulsoPadrao-8; }
					P[i].gravidadeY = gravidadePadrao; 
					P[i].y--;
				}
				
				//'700' subindo
				if( P[i].animFrame>=16 && P[1].hitPause==0 && P[2].hitPause==0 )
				{
					P[i].cicloInteracoesGravidadeCont++;
					
					if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade)
					{
						P[i].cicloInteracoesGravidadeCont=0;
						P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
						P[i].impulsoY-=1;
					}
					if( P[i].impulsoY>0 ){ P[i].cicloInteracoesGravidade=CIGD*5; } //retarda a queda
					P[i].y += P[i].impulsoY;
					
					if(P[i].direcao==1){ P[i].x+=1; }else{ P[i].x-=1; }
				}
				
				//'700' > Altura Piso
				if(P[i].state == STATE_ESPECIAL_700 && P[i].y>gAlturaPiso)
				{
					P[i].y=gAlturaPiso;
					P[i].gravidadeY = 0;
					P[i].impulsoY = 0;
					P[i].cicloInteracoesGravidade=CIGD;
					PLAYER_STATE(i, STATE_PARADO);
				}
			}
			
			//velocidade da magia
			if(P[i].state == STATE_ESPECIAL_710 && P[i].animFrame==12)
			{
				if(P[i].attackPower==1){ P[i].fBallSpeedX = 2; }
				if(P[i].attackPower==2){ P[i].fBallSpeedX = 3; }
				if(P[i].attackPower==3){ P[i].fBallSpeedX = 4; }
			}
			
		}
		//-----------------------------------------------------------------------------------------
		if(P[i].id==2) //GILLIUS
		{
			//velocidade da magia
			if(P[i].state == STATE_ESPECIAL_700 && P[i].animFrame==5)
			{
				if(P[i].attackPower==1){ P[i].fBallSpeedX = 1; }
				if(P[i].attackPower==2){ P[i].fBallSpeedX = 2; }
				if(P[i].attackPower==3){ P[i].fBallSpeedX = 3; }
			}
			
			//fisica da magia 710
			if(P[i].state == STATE_ESPECIAL_710) 
			{
				//'710' subindo
				if( P[1].hitPause==0 && P[2].hitPause==0 )
				{
					P[i].cicloInteracoesGravidadeCont++;
					
					if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade)
					{
						P[i].cicloInteracoesGravidadeCont=0;
						P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
						P[i].impulsoY-=1;
					}
					if( P[i].impulsoY>0 ){ P[i].cicloInteracoesGravidade=CIGD*5; } //retarda a queda
					P[i].y += P[i].impulsoY;
					
					if(P[i].direcao==1)
					{ 
						if(P[i].attackPower==1){ if(gPing4==0){P[i].x+= 1;} }
						if(P[i].attackPower==2){ P[i].x+= 2; }
						if(P[i].attackPower==3){ P[i].x+= 3; }
					}else{ 
						if(P[i].attackPower==1){ if(gPing4==0){P[i].x-= 1;} }
						if(P[i].attackPower==2){ P[i].x-= 2; }
						if(P[i].attackPower==3){ P[i].x-= 3; }
					}
				}
				
				//'710' > Altura Piso
				if(P[i].state == STATE_ESPECIAL_710 && P[i].y>gAlturaPiso+16)
				{
					P[i].y=gAlturaPiso;
					P[i].gravidadeY = 0;
					P[i].impulsoY = 0;
					P[i].cicloInteracoesGravidade=CIGD;
					PLAYER_STATE(i, STATE_ESPECIAL_711);
				}
			}
			
			//'720' Shoulder Ram
			if(P[i].state == STATE_ESPECIAL_720 && (P[i].animFrame>=3 && P[i].animFrame<=7) && (P[1].hitPause==0 && P[2].hitPause==0) ) 
			{
				if(P[i].attackPower==1){ P[i].hSpeed=4; }
				if(P[i].attackPower==2){ P[i].hSpeed=5; }
				if(P[i].attackPower==3){ P[i].hSpeed=6; }
				
				P[i].cicloInteracoesGravidadeCont++;
				
				if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade)
				{
					P[i].cicloInteracoesGravidadeCont=0;
					P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
					P[i].impulsoY-=1;
				}
				
				P[i].x+=P[i].hSpeed*P[i].direcao;
				P[i].y += P[i].impulsoY;
				
				if(P[i].y>gAlturaPiso){P[i].y=gAlturaPiso;}
			}
		}
		//-----------------------------------------------------------------------------------------
		
		//Hits Movement, deslocamento dos Players para trás, durante os ataques
		if(P[i].state>=500 && P[i].state <= STATE_CAINDO && (P[1].hitPause==0 && P[2].hitPause==0) )
		{
			u8 PA=0; //Player que Ataca
			u8 PR=0; //Player que Recebe o Ataque
			if(i == 1){ PA = 2; PR = 1; }else{ PA = 1; PR = 2; }
			
			//Nota, sem as condicoes abaixo, o deslocamento será continuo, enquanto durar a animacao de Hit
			//Esse algoritimo simples simula a desaceleracao, ou friccao, causada pelo atrito com o solo
			if(P[PR].animFrame<=3)
			{ 
				if(P[PR].animFrame==1) { P[PR].hSpeed = 3; } //vel 3
				if(P[PR].animFrame==2) { P[PR].hSpeed = 2; } //vel 2
				if(P[PR].animFrame==3) { P[PR].hSpeed = 1; } //vel 1
				P[PR].x += P[PR].hSpeed*(P[PR].direcao*-1);
			}			
			
			if(P[PR].x >= gLimiteCenarioD)
			{
				P[PA].hSpeed = 2;
				if(gPing2 == 1 && (P[PR].state != STATE_CAINDO) ){ P[PA].x += P[PA].hSpeed*(P[PA].direcao*-1); }
			}
			if(P[PR].x <= gLimiteCenarioE)
			{
				P[PA].hSpeed = 2;
				if(gPing2 == 1 && (P[PR].state != STATE_CAINDO) ){ P[PA].x += P[PA].hSpeed*(P[PA].direcao*-1); }
			}
		}
		
		//hitpause shake
		if(P[i].hitPause>0)
		{
			if(gPing2==0){ P[i].x-=2; }
			if(gPing2==1){ P[i].x+=2; }
			P[i].hitPause--;
		}
		
		//andar
		if(P[i].state == STATE_ANDANDO_TRAS || P[i].state == STATE_ANDANDO_FRENTE)
		{
			P[i].hSpeed=2;
			if(P[i].state == STATE_ANDANDO_TRAS){P[i].x+=P[i].hSpeed*(P[i].direcao*-1);}
			if(P[i].state == STATE_ANDANDO_FRENTE){P[i].x+=P[i].hSpeed*(P[i].direcao);}
		}
		
		//esquiva frente e tras
		if(P[i].state == STATE_ROLAMENTO_TRAS || P[i].state == STATE_ROLAMENTO_FRENTE)
		{
			if(P[i].animFrame>=1){ P[i].hSpeed=3; if(P[i].state == STATE_ROLAMENTO_TRAS){ P[i].hSpeed=4; } }
			if(P[i].animFrame>=3){ P[i].hSpeed=2; }
			if(P[i].animFrame>=5){ P[i].hSpeed=1; }
			if(P[i].animFrame>=6){ P[i].hSpeed=0; } //anula o deslocamento
			if(P[i].state == STATE_ROLAMENTO_TRAS){P[i].x+=P[i].hSpeed*(P[i].direcao*-1);}
			if(P[i].state == STATE_ROLAMENTO_FRENTE){P[i].x+=P[i].hSpeed*(P[i].direcao);}
		}
		
		//defesas
		if( (P[i].state == STATE_DEFESA_PE_APLICADA || P[i].state == STATE_DEFESA_ABAIXADO_APLICADA) && (P[1].hitPause==0 && P[2].hitPause==0) )
		{
			P[i].hSpeed=4;
			if(P[i].state == STATE_DEFESA_PE_APLICADA){P[i].x+=P[i].hSpeed*(P[i].direcao*-1);}//defesa em pe
			if(P[i].state == STATE_DEFESA_ABAIXADO_APLICADA){P[i].x+=P[i].hSpeed*(P[i].direcao*-1);}//defesa abaixado
		}
		
		//pulos
		if(P[1].hitPause==0 && P[2].hitPause==0)
		{
			if(P[i].puloTimer!=0){ P[i].puloTimer++; }
		
			if(P[i].state >= STATE_PULO_NEUTRO && P[i].state <= STATE_CHUTE_FORTE_AEREO_FRENTE)
			{ 
				P[i].hSpeed=3;
				/*samsho2*/ //hard code :P
				//o metodo a seguir é extremamente preciso, mas exige notacao manual!
				//para outros metodos de movimento, ver fisica no state 550, ou outros golpes por exemplo
				if(P[i].puloTimer== 1){ P[i].y-=11; }
				if(P[i].puloTimer== 2){ P[i].y-=11; }
				if(P[i].puloTimer== 3){ P[i].y-=10; }
				if(P[i].puloTimer== 4){ P[i].y-= 9; }
				if(P[i].puloTimer== 5){ P[i].y-= 9; }
				if(P[i].puloTimer== 6){ P[i].y-= 8; }
				if(P[i].puloTimer== 7){ P[i].y-= 8; }
				if(P[i].puloTimer== 8){ P[i].y-= 8; }
				if(P[i].puloTimer== 9){ P[i].y-= 7; }
				if(P[i].puloTimer==10){ P[i].y-= 6; } 
				if(P[i].puloTimer==11){ P[i].y-= 6; }
				if(P[i].puloTimer==12){ P[i].y-= 5; }
				if(P[i].puloTimer==13){ P[i].y-= 5; }
				if(P[i].puloTimer==14){ P[i].y-= 4; }
				if(P[i].puloTimer==15){ P[i].y-= 4; }
				if(P[i].puloTimer==16){ P[i].y-= 3; }
				if(P[i].puloTimer==17){ P[i].y-= 3; }
				if(P[i].puloTimer==18){ P[i].y-= 3; }
				if(P[i].puloTimer==19){ P[i].y-= 1; }
				if(P[i].puloTimer==20){ P[i].y-= 2; } 
				if(P[i].puloTimer==21){ P[i].y-= 0; }
				if(P[i].puloTimer==22){ P[i].y-= 1; }
				if(P[i].puloTimer==23){ P[i].y+= 1; }
				if(P[i].puloTimer==24){ P[i].y+= 0; }
				if(P[i].puloTimer==25){ P[i].y+= 2; }
				if(P[i].puloTimer==26){ P[i].y+= 1; }
				if(P[i].puloTimer==27){ P[i].y+= 3; }
				if(P[i].puloTimer==28){ P[i].y+= 3; }
				if(P[i].puloTimer==29){ P[i].y+= 3; }
				if(P[i].puloTimer==30){ P[i].y+= 4; } 
				if(P[i].puloTimer==31){ P[i].y+= 4; }
				if(P[i].puloTimer==32){ P[i].y+= 5; }
				if(P[i].puloTimer==33){ P[i].y+= 5; }
				if(P[i].puloTimer==34){ P[i].y+= 6; }
				if(P[i].puloTimer==35){ P[i].y+= 6; }
				if(P[i].puloTimer==36){ P[i].y+= 7; }
				if(P[i].puloTimer==37){ P[i].y+= 8; }
				if(P[i].puloTimer==38){ P[i].y+= 8; }
				if(P[i].puloTimer==39){ P[i].y+= 8; }
				if(P[i].puloTimer==40){ P[i].y+= 9; } 
				if(P[i].puloTimer==41){ P[i].y+= 9; }
				if(P[i].puloTimer==42){ P[i].y+=10; }
				if(P[i].puloTimer==43){ P[i].y+=11; }
				if(P[i].puloTimer==44){ P[i].y+=11; }
				if(P[i].puloTimer==45){ P[i].y+= 1; }
				
				if(P[i].state >= STATE_PULO_FRENTE && P[i].state <= STATE_CHUTE_FORTE_AEREO_FRENTE){ P[i].x+=P[i].hSpeed*(P[i].direcao); }
				if(P[i].state >= STATE_PULO_TRAS && P[i].state <= STATE_CHUTE_FORTE_AEREO_TRAS){ P[i].x+=P[i].hSpeed*(P[i].direcao*-1); }
			}
		}
		
		//corrige posX //limites do cenario
		if(P[i].x<gLimiteCenarioE)
		{ 
			if( P[i].state >= STATE_CAINDO && P[i].state <= STATE_LEVANTANDO )
			{ 
				P[i].x=gLimiteCenarioE+1; 
			}else{ 
				P[i].x=gLimiteCenarioE; 
			}
		}
		if(P[i].x>gLimiteCenarioD)
		{ 
			if( P[i].state >= STATE_CAINDO && P[i].state <= STATE_LEVANTANDO )
			{ 
				P[i].x=gLimiteCenarioD-1; 
			}else{
				P[i].x=gLimiteCenarioD; 
			}
		}
		
		/*samsho2*/
		//'516' CAINDO (Apos Magia do Haohmaru)
		if( P[1].hitPause==0 && P[2].hitPause==0 )
		{
			P[i].cicloInteracoesGravidadeCont++;
			
			if(P[i].state == STATE_USER_HIT)
			{
				if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade){
					P[i].cicloInteracoesGravidadeCont=0;
					P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
					P[i].impulsoY-=1;
				}
				P[i].y += P[i].impulsoY;
				if(gPing2==1){ if(P[i].direcao==1){ P[i].x-=1; }else{ P[i].x+=1; } }
			}
		}
		
		//'516' > Altura Piso
		if(P[i].state == STATE_USER_HIT && P[i].y>gAlturaPiso)
		{
			P[i].y=gAlturaPiso-1;
			P[i].gravidadeY = gravidadePadrao;
			P[i].impulsoY = -6;//-14
			PLAYER_STATE(i, STATE_QUICANDO_CHAO);
		}
		
		//'550' CAINDO
		if( P[1].hitPause==0 && P[2].hitPause==0 )
		{
			P[i].cicloInteracoesGravidadeCont++;
			
			if(P[i].state == STATE_CAINDO)
			{
				if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade){
					P[i].cicloInteracoesGravidadeCont=0;
					P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
					P[i].impulsoY-=1;
				}
				P[i].y += P[i].impulsoY;
				if(P[i].direcao==1){ P[i].x-=2; }else{ P[i].x+=2; }
			}
		}
		
		//'550' > Altura Piso
		if(P[i].state == STATE_CAINDO && P[i].y>gAlturaPiso)
		{
			P[i].y=gAlturaPiso-1;
			P[i].gravidadeY = gravidadePadrao;
			P[i].impulsoY = -6;//-14
			PLAYER_STATE(i, STATE_QUICANDO_CHAO);
		}
		
		if(P[i].state == STATE_QUICANDO_CHAO){
			if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade){
				P[i].cicloInteracoesGravidadeCont=0;
				P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
				P[i].impulsoY-=1;
			}
			P[i].y += P[i].impulsoY;
			if(P[i].direcao==1){ P[i].x-=2; }else{ P[i].x+=2; }
		}
		
		//'551' > Altura Piso
		if(P[i].state == STATE_QUICANDO_CHAO && P[i].y>gAlturaPiso)
		{
			P[i].y=gAlturaPiso;
			PLAYER_STATE(i, STATE_CAIDO_MORTO);
		}
		
		//-----------------------------------------------------------------------------------------
		
		//'MAGIAS' FISICA
		if( P[1].hitPause==0 && P[2].hitPause==0 )
		{
			//P[i].cicloInteracoesGravidadeCont++;
			
			if( (P[i].state == STATE_ESPECIAL_710 || P[i].state == STATE_ESPECIAL_720 || P[i].state == STATE_ESPECIAL_730 || P[i].state==STATE_ESPECIAL_740 || P[i].state==STATE_ESPECIAL_750) && P[i].y!=gAlturaPiso )
			{
				if(P[i].cicloInteracoesGravidadeCont>=P[i].cicloInteracoesGravidade){
					P[i].cicloInteracoesGravidadeCont=0;
					P[i].impulsoY = P[i].impulsoY+P[i].gravidadeY;
					P[i].impulsoY-=1;
				}
				P[i].y += P[i].impulsoY;
				if(P[i].direcao==-1){ P[i].x-=2; }else{ P[i].x+=2; }
			}
		}
		
		//'MAGIAS' FISICA > Altura Piso
		//HAOHMARU (magia 720)
		if( (P[i].state == STATE_ESPECIAL_720) && P[i].y+2>gAlturaPiso)
		{
			P[i].y = gAlturaPiso;
			P[i].frameTimeAtual = P[i].frameTimeTotal; //Passa para o proximo frame de animacao
		}
		
		//-----------------------------------------------------------------------------------------
		
		//Movimento das Magias
		if(P[i].fBallActive == 1)
		{
			P[i].fBallX += P[i].fBallSpeedX * P[i].fBallDirecao;
			SPR_setPosition( P[i].fBall, P[i].fBallX, P[i].fBallY );
			if(P[i].fBallX<gLimiteCenarioE-100){ SPR_releaseSprite(P[i].fBall); P[i].fBallActive=0; }
			if(P[i].fBallX>gLimiteCenarioD+100){ SPR_releaseSprite(P[i].fBall); P[i].fBallActive=0; }
		}
		
	}
	
	//Colisao Mass Boxes
	if(FUNCAO_COLISAO(
	P[1].x+P[1].dataMBox[0], P[1].y+P[1].dataMBox[1], P[1].x+P[1].dataMBox[2], P[1].y+P[1].dataMBox[3], 
	P[2].x+P[2].dataMBox[0], P[2].y+P[2].dataMBox[1], P[2].x+P[2].dataMBox[2], P[2].y+P[2].dataMBox[3]
	)){
		u8 tempBigHSpeed=0;
		if(P[1].hSpeed>=P[2].hSpeed){tempBigHSpeed=P[1].hSpeed;}else{tempBigHSpeed=P[2].hSpeed;}
		if(P[1].x<P[2].x){
			P[1].x-=tempBigHSpeed;
			P[2].x+=tempBigHSpeed;
		}else{
			P[1].x+=tempBigHSpeed;
			P[2].x-=tempBigHSpeed;
		}
		
	}
}

