#include "stage_select_room.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "input.h"
#include "utils.h"

void stage_select_room_handler()
{
			FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			if(gFrames==1)
			{
				gInd_tileset=1;
			
				VDP_loadTileSet(bg_stage_select_bgb.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_B,bg_stage_select_bgb.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
				PAL_setPalette(PAL0, bg_stage_select_bgb.palette->data, CPU);
				gInd_tileset += bg_stage_select_bgb.tileset->numTile;
				
				VDP_loadTileSet(bg_stage1_select_bga.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_A,bg_stage1_select_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),13,11,0,0,16,8,DMA_QUEUE);
				PAL_setPalette(PAL1, bg_stage1_select_bga.palette->data, CPU);
				//gInd_tileset += bg_stage1_select_bga.tileset->numTile;
				
				//Elementos Graficos
				GE[1].sprite = SPR_addSpriteExSafe(&spr_BG_desc1,  16, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				PAL_setPalette(PAL3, spr_BG_desc1.palette->data, CPU);
				GE[2].sprite = SPR_addSpriteExSafe(&kuroko_shoulder, 104, 128, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				PAL_setPalette(PAL2, kuroko_shoulder.palette->data, CPU);
				GE[3].sprite = SPR_addSpriteExSafe(&spr_stage_sel_icon,  282, 168, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			}
			
			u8 atualizaMiniatura=0;
			u8 NumberOfStages = 3; //Inserir aqui o total de stages criados!
			
			if(P[1].key_JOY_RIGHT_status==1 || P[2].key_JOY_RIGHT_status==1)
			{
				atualizaMiniatura=1;
				gBG_Choice--;
				if(gBG_Choice<1){gBG_Choice=NumberOfStages;}
			}
			if(P[1].key_JOY_LEFT_status==1 || P[2].key_JOY_LEFT_status==1)
			{
				atualizaMiniatura=1;
				gBG_Choice++;
				if(gBG_Choice>NumberOfStages){gBG_Choice=1;}
			}
			if(atualizaMiniatura==1)
			{
				XGM_setPCM(P1_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
				
				//move o cursor 'gps'
				if(gBG_Choice==1){ SPR_setPosition(GE[3].sprite, 282, 168); }
				if(gBG_Choice==2){ SPR_setPosition(GE[3].sprite, 236, 157); }
				if(gBG_Choice==3){ SPR_setPosition(GE[3].sprite, 176, 187); }
				
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				if(gBG_Choice==1)
				{ 
					GE[1].sprite = SPR_addSpriteExSafe(&spr_BG_desc1,  16, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL3, spr_BG_desc1.palette->data, CPU);
					
					VDP_loadTileSet(bg_stage1_select_bga.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_A,bg_stage1_select_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),13,11,0,0,16,8,DMA_QUEUE);
					PAL_setPalette(PAL1, bg_stage1_select_bga.palette->data, CPU);
				}
				if(gBG_Choice==2)
				{
					GE[1].sprite = SPR_addSpriteExSafe(&spr_BG_desc2,  16, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL3, spr_BG_desc1.palette->data, CPU);
					
					VDP_loadTileSet(bg_stage2_select_bga.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_A,bg_stage2_select_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),13,11,0,0,16,8,DMA_QUEUE);
					PAL_setPalette(PAL1, bg_stage2_select_bga.palette->data, CPU);
				}
				if(gBG_Choice==3)
				{
					GE[1].sprite = SPR_addSpriteExSafe(&spr_BG_desc3,  16, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL3, spr_BG_desc1.palette->data, CPU);
					
					VDP_loadTileSet(bg_stage3_select_bga.tileset,gInd_tileset,DMA); 
					VDP_setTileMapEx(BG_A,bg_stage3_select_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),13,11,0,0,16,8,DMA_QUEUE);
					PAL_setPalette(PAL1, bg_stage3_select_bga.palette->data, CPU);
				}
			}
			
			if(P[1].key_JOY_START_status==1 && gFrames>5){
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
				if (GE[3].sprite){ SPR_releaseSprite(GE[3].sprite); GE[3].sprite = NULL; }
				gRoom = ROOM_DESCOMPRESSION; gDescompressionExit=10;
				gFrames=1; 
				CLEAR_VDP();
			};
}
