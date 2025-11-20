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
					if(P[i].state == STATE_PARADO){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_ABAIXADO){ PLAYER_STATE(i, STATE_ABAIXADO); }
					
					// estes aqui previnem bug, caso o tempo de animacao dos Aereos seja definido errado
					// e o player nao tenha tempo de chegar ao solo...
					if(P[i].state == STATE_PULO_NEUTRO || P[i].state == STATE_PULO_TRAS || P[i].state == STATE_PULO_FRENTE){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_SOCO_FRACO_AEREO_NEUTRO || P[i].state == STATE_SOCO_MEDIO_AEREO_NEUTRO || P[i].state == STATE_SOCO_FORTE_AEREO_NEUTRO){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_CHUTE_FRACO_AEREO_NEUTRO || P[i].state == STATE_CHUTE_MEDIO_AEREO_NEUTRO || P[i].state == STATE_CHUTE_FORTE_AEREO_NEUTRO){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_SOCO_FRACO_AEREO_TRAS || P[i].state == STATE_SOCO_MEDIO_AEREO_TRAS || P[i].state == STATE_SOCO_FORTE_AEREO_TRAS){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_CHUTE_FRACO_AEREO_TRAS || P[i].state == STATE_CHUTE_MEDIO_AEREO_TRAS || P[i].state == STATE_CHUTE_FORTE_AEREO_TRAS){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_SOCO_FRACO_AEREO_FRENTE || P[i].state == STATE_SOCO_MEDIO_AEREO_FRENTE || P[i].state == STATE_SOCO_FORTE_AEREO_FRENTE){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_CHUTE_FRACO_AEREO_FRENTE || P[i].state == STATE_CHUTE_MEDIO_AEREO_FRENTE || P[i].state == STATE_CHUTE_FORTE_AEREO_FRENTE){ PLAYER_STATE(i, STATE_PARADO); }
					
					if(P[i].state == STATE_ANDANDO_TRAS){ PLAYER_STATE(i, STATE_ANDANDO_TRAS); }
					if(P[i].state == STATE_ANDANDO_FRENTE){ PLAYER_STATE(i, STATE_ANDANDO_FRENTE); }
					if(P[i].state == STATE_ESQUIVA_BAIXO || P[i].state == STATE_ROLAMENTO_TRAS || P[i].state == STATE_ROLAMENTO_FRENTE){ if(P[i].key_JOY_DOWN_status>0){ PLAYER_STATE(i, STATE_ABAIXADO); }else{ PLAYER_STATE(i, STATE_PARADO); } }
					if(P[i].state == STATE_ABAIXANDO){ PLAYER_STATE(i, STATE_ABAIXADO); }
					if(P[i].state == STATE_LEVANTANDO_TRANSICAO){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_INICIO_PULO_TRAS){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i, STATE_PULO_TRAS); }
					if(P[i].state == STATE_INICIO_PULO_NEUTRO){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i, STATE_PULO_NEUTRO); }
					if(P[i].state == STATE_INICIO_PULO_FRENTE){ P[i].y-=1; P[i].puloTimer=1; PLAYER_STATE(i, STATE_PULO_FRENTE); }
					if(P[i].state == STATE_VIRANDO_PE){ PLAYER_STATE(i, STATE_PARADO); } //virando em pe
					if(P[i].state == STATE_VIRANDO_ABAIXADO){ PLAYER_STATE(i, STATE_ABAIXADO); } //virando abaixado
					if(P[i].state >= STATE_SOCO_FRACO_LONGE && P[i].state <= STATE_CHUTE_FORTE_LONGE){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_DEFESA_PE_INICIO){ PLAYER_STATE(i, STATE_DEFESA_PE_DEFENDENDO); }
					if(P[i].state == STATE_DEFESA_PE_DEFENDENDO){ PLAYER_STATE(i, STATE_DEFESA_PE_DEFENDENDO); }
					if(P[i].state == STATE_DEFESA_PE_FINAL){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state == STATE_DEFESA_PE_APLICADA){ PLAYER_STATE(i, STATE_DEFESA_PE_FINAL); }
					if(P[i].state >= STATE_SOCO_FRACO_PERTO && P[i].state <= STATE_CHUTE_FORTE_PERTO){ PLAYER_STATE(i, STATE_PARADO); }
					if(P[i].state >= STATE_SOCO_FRACO_ABAIXADO && P[i].state <= STATE_CHUTE_FORTE_ABAIXADO){ PLAYER_STATE(i, STATE_ABAIXADO); }
					if(P[i].state == STATE_DEFESA_ABAIXADO_INICIO){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_DEFENDENDO); }
					if(P[i].state == STATE_DEFESA_ABAIXADO_DEFENDENDO){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_DEFENDENDO); }
					if(P[i].state == STATE_DEFESA_ABAIXADO_FINAL){ PLAYER_STATE(i, STATE_ABAIXADO); }
					if(P[i].state == STATE_DEFESA_ABAIXADO_APLICADA){ PLAYER_STATE(i, STATE_DEFESA_ABAIXADO_FINAL); }
					if(P[i].state >= STATE_HIT_TIPO1_FRACO && P[i].state <= STATE_CAINDO){ PLAYER_STATE(i, STATE_PARADO); } //end hurts
					if(P[i].state == STATE_LEVANTANDO){ PLAYER_STATE(i, STATE_PARADO); } //end queda
					if(P[i].state == STATE_CAIDO_MORTO){ if(P[i].energiaBase>0){ PLAYER_STATE(i, STATE_LEVANTANDO); }else{ PLAYER_STATE(i, STATE_CAIDO_MORTO); } } //end pulos
					if(P[i].state == STATE_FINAL_PULO){ PLAYER_STATE(i, STATE_PARADO); } //end pulos
					if(P[i].state == STATE_INTRO){ PLAYER_STATE(i, STATE_PARADO); } //end Intro
					if(P[i].state == STATE_WIN1 || P[i].state == STATE_WIN2 || P[i].state == STATE_WIN3 || P[i].state == STATE_WIN4){ FUNCAO_ROUND_RESTART(); } //end WIN Pose
					if(P[i].state == STATE_PERDENDO_TIME_OVER){ FUNCAO_ROUND_RESTART(); } //end time lose
					if(P[i].state == STATE_RAGE_EXPLOSION){ PLAYER_STATE(i, STATE_PARADO); } //end Rage Explosion
					if(P[i].state >= STATE_ESPECIAL_700 && P[i].state <= STATE_ESPECIAL_790){ PLAYER_STATE(i, STATE_PARADO); } //end magias
				}
				P[i].frameTimeAtual=1;
				P[i].frameTimeTotal = P[i].dataAnim[P[i].animFrame];
				SPR_setAnimAndFrame(P[i].sprite, 0, P[i].animFrame-1);
				FUNCAO_FSM_HITBOXES(i); //Atualiza as Hurt / Hitboxes
			}else if(P[i].frameTimeAtual>P[i].frameTimeTotal && gASG_system==1){ //A.S.G.S. 
				if(P[i].frameTimeAtual>1){ P[i].frameTimeAtual--; }
			}
			//*NOTA: No caso do SS2, a animacao abaixando é encurtada (para se abaixar mais rapido) caso se mantenha pressionado para baixo apos o pulo //end pulos 
			/*samsho2*/ if(P[i].state == STATE_FINAL_PULO && P[i].animFrame==2 && P[i].frameTimeAtual>=3 && P[i].key_JOY_DOWN_status>=1){ PLAYER_STATE(i, STATE_ABAIXADO); } 
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

