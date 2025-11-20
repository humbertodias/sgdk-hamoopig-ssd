#include "after_match_room.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "input.h"
#include "utils.h"

void after_match_room_handler()
{
			FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			if(gFrames==1)
			{
				gContinueOption=1;
				gInd_tileset=1;
				gScrollValue=0;
				VDP_setHorizontalScroll(BG_B, gScrollValue);
				
				//BACKGROUND
				if(gBG_Choice==1)
				{
					VDP_loadTileSet(gfx_bgb1_win_screen.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_B,gfx_bgb1_win_screen.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,3,0,0,40,22,DMA_QUEUE);
					PAL_setPalette(PAL0, gfx_bgb1_win_screen.palette->data, CPU);
					gInd_tileset += gfx_bgb1_win_screen.tileset->numTile;
				}
				if(gBG_Choice==2)
				{
					VDP_loadTileSet(gfx_bgb2_win_screen.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_B,gfx_bgb2_win_screen.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,3,0,0,40,22,DMA_QUEUE);
					PAL_setPalette(PAL0, gfx_bgb2_win_screen.palette->data, CPU);
					gInd_tileset += gfx_bgb2_win_screen.tileset->numTile;
				}
				
				//WINNER
				if(gWinnerID==1) //haohmaru
				{
					VDP_loadTileSet(bg_win_haohmaru_bga.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_A,bg_win_haohmaru_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
					PAL_setPalette(PAL1, bg_win_haohmaru_bga.palette->data, CPU);
					gInd_tileset += bg_win_haohmaru_bga.tileset->numTile;
				}
				if(gWinnerID==2) //gillius
				{
					VDP_loadTileSet(bg_win_gillius_bga.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_A,bg_win_gillius_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
					PAL_setPalette(PAL1, bg_win_gillius_bga.palette->data, CPU);
					gInd_tileset += bg_win_gillius_bga.tileset->numTile;
				}
				
				//Elementos Graficos
				if(gWinnerID==1) //haohmaru
				{
					if(gPing2==0){ 
						GE[1].sprite = SPR_addSpriteExSafe(&spr_haohmaru_win_phrase1A,  168,  40, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
						GE[2].sprite = SPR_addSpriteExSafe(&spr_haohmaru_win_phrase1B,  168, 112, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
					}
					if(gPing2==1){ 
						GE[1].sprite = SPR_addSpriteExSafe(&spr_haohmaru_win_phrase2A,  168,  40, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
						GE[2].sprite = SPR_addSpriteExSafe(&spr_haohmaru_win_phrase2B,  168, 112, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
					}
					PAL_setPalette(PAL3, spr_haohmaru_win_phrase1A.palette->data, CPU);
				}
				if(gWinnerID==2) //gillius
				{
					if(gPing2==0){ 
						GE[1].sprite = SPR_addSpriteExSafe(&spr_gillius_win_phrase1A,  168,  40, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
						GE[2].sprite = SPR_addSpriteExSafe(&spr_gillius_win_phrase1B,  168, 112, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
					}
					if(gPing2==1){ 
						GE[1].sprite = SPR_addSpriteExSafe(&spr_gillius_win_phrase2A,  168,  40, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
						GE[2].sprite = SPR_addSpriteExSafe(&spr_gillius_win_phrase2B,  168, 112, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
					}
					PAL_setPalette(PAL3, spr_gillius_win_phrase1A.palette->data, CPU);
				}
				
				//Continue; Rematch
				GE[3].sprite = SPR_addSpriteExSafe(&spr_continue, 54, 192, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				GE[4].sprite = SPR_addSpriteExSafe(&spr_continue_yes, 190, 192, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				GE[5].sprite = SPR_addSpriteExSafe(&spr_continue_no , 230, 192, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setDepth(GE[3].sprite, 255); 
				SPR_setDepth(GE[4].sprite, 1); 
				SPR_setDepth(GE[5].sprite, 1); 
			}
			
			//Continue?
			//"gContinueOption==0" NO
			//"gContinueOption==1" YES
			bool SoundContinueChoice = 0;
			if(P[1].key_JOY_LEFT_status ==1 || P[2].key_JOY_LEFT_status ==1){ gContinueOption=1; SoundContinueChoice=1; }
			if(P[1].key_JOY_RIGHT_status==1 || P[2].key_JOY_RIGHT_status==1){ gContinueOption=0; SoundContinueChoice=1; }
			if(SoundContinueChoice==1){ XGM_setPCM(P1_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(gContinueOption==1){
				if(gPing10>=1 && gPing10<=6){ SPR_setVisibility(GE[4].sprite, VISIBLE); }
				if(gPing10>=7 && gPing10<=9){ SPR_setVisibility(GE[4].sprite, HIDDEN ); }
				SPR_setVisibility(GE[5].sprite, HIDDEN);
			}
			if(gContinueOption==0){
				if(gPing10>=1 && gPing10<=6){ SPR_setVisibility(GE[5].sprite, VISIBLE); }
				if(gPing10>=7 && gPing10<=9){ SPR_setVisibility(GE[5].sprite, HIDDEN ); }
				SPR_setVisibility(GE[4].sprite, HIDDEN);
			}
			if(P[1].key_JOY_START_status==1 && gFrames>5)
			{
				CLEAR_VDP();
				gFrames=0;
				if(gContinueOption==0){ gRoom = ROOM_PRESENTATION; }
				if(gContinueOption==1){ gRoom = ROOM_DESCOMPRESSION; gDescompressionExit=10; }
			};
			
}
