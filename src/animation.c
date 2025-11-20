#include "animation.h"
#include "game_globals.h"

void FUNCAO_ANIMACAO()
{
	//CONTROLE DE ANIMACAO E END ANIMATION
	if(P[1].hitPause==0 && P[2].hitPause==0)
	{ 
		gASG_system = 0; //A.S.G.S. Anti Sprite Glitch System; (Evita a troca simultanea de sprites dos players)
		
		for(i=1; i<=2; i++)
		{
			P[i].frameTimeAtual++; 
			if(P[i].frameTimeAtual>P[i].frameTimeTotal && gASG_system==0) //hora de trocar o frame!
			{
				P[i].animFrame++;
				if(P[i].animFrame>P[i].animFrameTotal) //hora de trocar ou recarregar a animacao!
				{
					gASG_system = 1;
					if(P[i].state==100){ PLAYER_STATE(i,100); }
					if(P[i].state==200){ PLAYER_STATE(i,200); }
					
					// estes aqui previnem bug, caso o tempo de animacao dos Aereos seja definido errado
					// e o player nao tenha tempo de chegar ao solo...
					if(P[i].state==300 || P[i].state==310 || P[i].state==320){ PLAYER_STATE(i,100); }
					if(P[i].state==301 || P[i].state==302 || P[i].state==303){ PLAYER_STATE(i,100); }
					if(P[i].state==304 || P[i].state==305 || P[i].state==306){ PLAYER_STATE(i,100); }
					if(P[i].state==311 || P[i].state==312 || P[i].state==313){ PLAYER_STATE(i,100); }
					if(P[i].state==314 || P[i].state==315 || P[i].state==316){ PLAYER_STATE(i,100); }
					if(P[i].state==321 || P[i].state==322 || P[i].state==323){ PLAYER_STATE(i,100); }
					if(P[i].state==324 || P[i].state==325 || P[i].state==326){ PLAYER_STATE(i,100); }
					
					if(P[i].state==410){ PLAYER_STATE(i,410); }
					if(P[i].state==420){ PLAYER_STATE(i,420); }
					if(P[i].state==470 || P[i].state==471 || P[i].state==472){ if(P[i].key_JOY_DOWN_status>0){ PLAYER_STATE(i,200); }else{ PLAYER_STATE(i,100); } }
					if(P[i].state==601){ PLAYER_STATE(i,200); }
					if(P[i].state==602){ PLAYER_STATE(i,100); }
					if(P[i].state==603){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i,310); }
					if(P[i].state==604){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i,300); }
					if(P[i].state==605){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i,320); }
					if(P[i].state==607){ PLAYER_STATE(i,100); } //virando em pe
					if(P[i].state==608){ PLAYER_STATE(i,200); } //virando abaixado
					if(P[i].state>=101 && P[i].state<=106){ PLAYER_STATE(i,100); }
					if(P[i].state==107){ PLAYER_STATE(i,108); }
					if(P[i].state==108){ PLAYER_STATE(i,108); }
					if(P[i].state==109){ PLAYER_STATE(i,100); }
					if(P[i].state==110){ PLAYER_STATE(i,109); }
					if(P[i].state>=151 && P[i].state<=156){ PLAYER_STATE(i,100); }
					if(P[i].state>=201 && P[i].state<=206){ PLAYER_STATE(i,200); }
					if(P[i].state==207){ PLAYER_STATE(i,208); }
					if(P[i].state==208){ PLAYER_STATE(i,208); }
					if(P[i].state==209){ PLAYER_STATE(i,200); }
					if(P[i].state==210){ PLAYER_STATE(i,209); }
					if(P[i].state>=501 && P[i].state<=550){ PLAYER_STATE(i,100); } //end hurts
					if(P[i].state==552){ PLAYER_STATE(i,100); } //end queda
					if(P[i].state==570){ if(P[i].energiaBase>0){ PLAYER_STATE(i,552); }else{ PLAYER_STATE(i,570); } } //end pulos
					if(P[i].state==606){ PLAYER_STATE(i,100); } //end pulos
					if(P[i].state==610){ PLAYER_STATE(i,100); } //end Intro
					if(P[i].state==611 || P[i].state==612 || P[i].state==613 || P[i].state==614){ FUNCAO_ROUND_RESTART(); } //end WIN Pose
					if(P[i].state==615){ FUNCAO_ROUND_RESTART(); } //end time lose
					if(P[i].state==618){ PLAYER_STATE(i,100); } //end Rage Explosion
					if(P[i].state>=700 && P[i].state<=790){ PLAYER_STATE(i,100); } //end magias
				}
				P[i].frameTimeAtual=1;
				P[i].frameTimeTotal = P[i].dataAnim[P[i].animFrame];
				SPR_setAnimAndFrame(P[i].sprite, 0, P[i].animFrame-1);
				FUNCAO_FSM_HITBOXES(i); //Atualiza as Hurt / Hitboxes
			}else if(P[i].frameTimeAtual>P[i].frameTimeTotal && gASG_system==1){ //A.S.G.S. 
				if(P[i].frameTimeAtual>1){ P[i].frameTimeAtual--; }
			}
			//*NOTA: No caso do SS2, a animacao abaixando é encurtada (para se abaixar mais rapido) caso se mantenha pressionado para baixo apos o pulo //end pulos 
			/*samsho2*/ if(P[i].state==606 && P[i].animFrame==2 && P[i].frameTimeAtual>=3 && P[i].key_JOY_DOWN_status>=1){ PLAYER_STATE(i,200); } 
		}
	}
	FUNCAO_SPR_POSITION(); //Define a posicao do Sprite
	
}

void FUNCAO_SPR_POSITION()
{
	//ajusta posicao do sprite
	if(P[1].direcao== 1){ SPR_setPosition(P[1].sprite, P[1].x-(P[1].w-P[1].axisX), P[1].y-P[1].axisY); }
	if(P[1].direcao==-1){ SPR_setPosition(P[1].sprite, P[1].x- P[1].axisX        , P[1].y-P[1].axisY); }
	if(P[2].direcao== 1){ SPR_setPosition(P[2].sprite, P[2].x-(P[2].w-P[2].axisX), P[2].y-P[2].axisY); }
	if(P[2].direcao==-1){ SPR_setPosition(P[2].sprite, P[2].x- P[2].axisX        , P[2].y-P[2].axisY); }
	
	if(gSombraStyle==2)
	{
		SPR_setPosition(P[1].sombra, P[1].x-32, gAlturaPiso-5); // *NOTA: A sombra do SS2 tem 80px, entao desloquei -40px no eixo X
		SPR_setPosition(P[2].sombra, P[2].x-32, gAlturaPiso-5); // para que ela ficasse perfeitamente alinhada aos players /*samsho2*/
	}else{
		if(gPing2==0){ SPR_setPosition(P[1].sombra, P[1].x-32, gAlturaPiso-5); }
		if(gPing2==1){ SPR_setPosition(P[1].sombra, P[2].x-32, gAlturaPiso-5); }
	}
}

