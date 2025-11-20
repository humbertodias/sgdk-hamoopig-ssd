#include "hamoopig_room.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "input.h"
#include "utils.h"

void hamoopig_room_handler()
{
			FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			//inicializacao
			if(gFrames==1)
			{
				//bg_A
				VDP_drawImageEx(BG_A, &room_0_bga, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, gInd_tileset), 0, 0, FALSE, TRUE);
				gInd_tileset += room_0_bga.tileset->numTile;
				//bg_B
				VDP_drawImageEx(BG_B, &room_0_bgb, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, gInd_tileset), 0, 0, FALSE, TRUE);
				gInd_tileset += room_0_bgb.tileset->numTile;
				
				PAL_setPalette(PAL0, room_0_bga.palette->data, CPU);
				PAL_setPalette(PAL1, room_0_bgb.palette->data, CPU);
				
				VDP_setBackgroundColor(0);
			}
			
			if(gFrames==10)
			{
				XGM_setPCM(P1_SFX, snd_future_now, sizeof(snd_future_now)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
			}
			
			if( (gFrames>=60*5) || (P[1].key_JOY_START_status==1 && gFrames>10) ){
				CLEAR_VDP();
				gRoom = ROOM_PRESENTATION;
				gFrames=1;
				//if(key_JOY1_A_status>0){gRoom=111111;}//atalho para outra Room...
				//if(key_JOY1_B_status>0){gRoom=222222;}//atalho para outra Room...
				//if(key_JOY1_C_status>0){gRoom=333333;}//atalho para outra Room...
			};
}
