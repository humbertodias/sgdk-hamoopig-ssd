#include "in_game_room.h"
#include "input.h"
#include "fsm.h"
#include "physics.h"
#include "animation.h"
#include "camera.h"
#include "hud.h"
#include "debug.h"
#include "game_init.h"

void in_game_room_handler()
{
			if(gFrames == 1){ FUNCAO_INICIALIZACAO(); } //Inicializacao
			if(gFrames<=355){ 
				FUNCAO_ROUND_INIT(); //Rotina de Letreiramento de inicio dos rounds
			}else{
				FUNCAO_RELOGIO(); //HUD relogio
				FUNCAO_BARRAS_DE_ENERGIA(); //HUD barras
			}    
			
			//libera os graficos dos sparks
			if(Spark1_countDown>0){ Spark1_countDown--; if(Spark1_countDown==1){ SPR_releaseSprite(Spark[1]); Spark[1] = NULL; } }
			if(Spark2_countDown>0){ Spark2_countDown--; if(Spark2_countDown==1){ SPR_releaseSprite(Spark[2]); Spark[2] = NULL; } }
			
			FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			FUNCAO_ANIMACAO(); //Atualiza animacao
			
			FUNCAO_FSM(); //FSM = Finite State Machine (Maquina de Estados)
			
			FUNCAO_PHYSICS(); //Funcoes de Fisica
			
			FUNCAO_CAMERA_BGANIM();
			
			FUNCAO_SAMSHOFX(); //Efeitos do jogo SS2
			
			if(gDebug == 1){ FUNCAO_DEBUG(); } //Debug
}
