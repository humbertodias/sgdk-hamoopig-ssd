//////////////////////////////////////////////////////////////////////////////
// HAMOOPI(G) by GameDevBoss (Daniel Moura) 2015-2022                       //
// www.youtube.com/c/GameDevBoss                                            //
// HAMOOPIG É GRATUITO E SEMPRE SERÁ - HAMOOPIG IS FREE AND ALWAYS WILL BE  //
// O CONHECIMENTO DEVE SER COMPARTILHADO - KNOWLEDGE MUST BE SHARED         //
//////////////////////////////////////////////////////////////////////////////

#include <genesis.h>
#include "sprite.h"
#include "gfx.h"
#include "sound.h"

// Include modular headers
#include "game_types.h"
#include "game_globals.h"
#include "collision.h"
#include "utils.h"
#include "player.h"
#include "input.h"
#include "fsm.h"
#include "physics.h"
#include "animation.h"
#include "camera.h"
#include "hud.h"
#include "game_init.h"
#include "debug.h"
#include "rooms/hamoopig_room.h"
#include "rooms/presentation_room.h"
#include "rooms/char_select_room.h"
#include "rooms/stage_select_room.h"
#include "rooms/descompression_room.h"
#include "rooms/in_game_room.h"
#include "rooms/after_match_room.h"

int main(u16 hard) /************** MAIN **************/
{
    //Inicializacao da VDP (Video Display Processor)
	SYS_disableInts();
	 VDP_init();                    //Inicializa a VDP (Video Display Processor)
	 VDP_setScreenWidth320();       //Resolucao padrao de 320x224 (Largura)
	 VDP_setScreenHeight224();      //Resolucao padrao de 320x224 (Altura)
	 VDP_setPlaneSize(64,32,TRUE);  //Recomendado para BGs grandes
	 VDP_setTextPlane(BG_A);        //Textos serao desenhados no BG_A
	 VDP_setTextPalette(PAL1);      //Textos serao desenhados com a ultima cor da PAL0
    //  SPR_init(127, 384, 256);       //SPR_init(u16 maxSprite, u16 vramSize, u16 unpackBufferSize)
	SPR_init();                     //SPR_init() - no longer takes parameters in latest SGDK
	 VDP_setBackgroundColor(0);     //Range 0-63 //4 Paletas de 16 cores = 64 cores
	SYS_enableInts();
	
    while(TRUE) /// LOOP PRINCIPAL ///
    {
        gFrames++; 
		if(gPing2  == 1){ gPing2 = -1; } gPing2++;  //var 'gPing2'  (50%) variacao: 0 ; 1
		if(gPing4  == 3){ gPing4 = -1; } gPing4++;  //var 'gPing4'  (25%) variacao: 0 ; 1 ; 2 ; 3
		if(gPing10 == 9){ gPing10= -1; } gPing10++; //var 'gPing10' (10%) variacao: 0 ; 1 ; 2 ; 3 ; 4 ; 5 ; 6 ; 7 ; 8 ; 9
		
		if(gRoom == ROOM_HAMOOPIG) //TELA HAMOOPIG --------------------------------------------------------------
		{
			hamoopig_room_handler();
		}
		
		
		if(gRoom == ROOM_PRESENTATION) //TELA DE APRESENTACAO -------------------------------------------------------
		{
			presentation_room_handler();
		}
		
		
		if(gRoom == ROOM_CHAR_SELECT) //CHAR SELECT ----------------------------------------------------------------
		{
			char_select_room_handler();
		}
		
		
		if(gRoom == ROOM_STAGE_SELECT) //STAGE SELECT ---------------------------------------------------------------
		{
			stage_select_room_handler();
		}
		
		
		if(gRoom == ROOM_DESCOMPRESSION) //DESCOMPRESSION -------------------------------------------------------------
		{
			descompression_room_handler();
		}
		
		
		if(gRoom == ROOM_IN_GAME) //IN GAME -------------------------------------------------------------------
		{
			in_game_room_handler();
		}
		
		
		if(gRoom == ROOM_AFTER_MATCH) //AFTER MATCH ---------------------------------------------------------------
		{
			after_match_room_handler();
		}
		
		
		//--- FINALIZACOES ---//
		//VDP_showFPS(1);        //Mostra a taxa de FPS
		SPR_update();          //Atualiza (desenha) os sprites
        SYS_doVBlankProcess(); //Wait for screen refresh and do all SGDK VBlank tasks
    }
	
    return 0;
}

//--- FUNCOES ---//


















//EOF - END OF FILE; by GAMEDEVBOSS 2015-2022