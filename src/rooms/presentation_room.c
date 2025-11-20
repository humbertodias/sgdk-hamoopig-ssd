#include "presentation_room.h"
#include "sprite.h"
#include "gfx.h"
#include "../inc/input.h"
#include "../inc/utils.h"

void presentation_room_handler()
{
			FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			if(gFrames==1)
			{
				gInd_tileset=1;
			
				VDP_loadTileSet(bg_title_bgb.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_B,bg_title_bgb.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
				PAL_setPalette(PAL0, bg_title_bgb.palette->data, CPU);
				gInd_tileset += bg_title_bgb.tileset->numTile;
				
				VDP_loadTileSet(bg_title_bga.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_A,bg_title_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
				PAL_setPalette(PAL1, bg_title_bga.palette->data, CPU);
				gInd_tileset += bg_title_bga.tileset->numTile;
				
				GE[1].sprite = SPR_addSpriteExSafe(&spr_roman_two, 184, 32, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				PAL_setPalette(PAL2, spr_roman_two.palette->data, CPU);
				SPR_setDepth(GE[1].sprite, 255); 
				
				//Petalas
				
				PAL_setPalette(PAL3, spr_petala_big.palette->data, CPU);
				
				GE[2].sprite = SPR_addSpriteExSafe(&spr_petala_big,  40, 40, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[2].sprite, 1451); //define uma posicao especifica para o GFX na VRAM
				
				GE[3].sprite = SPR_addSpriteExSafe(&spr_petala_big,  160, 120, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[3].sprite, 1461); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[3].sprite, 0, 2);
				
				GE[4].sprite = SPR_addSpriteExSafe(&spr_petala_big,  80, 70, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[4].sprite, 1471); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[4].sprite, 0, 3);
				
				GE[5].sprite = SPR_addSpriteExSafe(&spr_petala_big,  50, 110, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[5].sprite, 1481); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[5].sprite, 0, 8);
				
				GE[6].sprite = SPR_addSpriteExSafe(&spr_petala_big,  110, 150, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[6].sprite, 1491); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[6].sprite, 0, 12);
				
				GE[7].sprite = SPR_addSpriteExSafe(&spr_petala_big,  50, 160, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[7].sprite, 1501); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[7].sprite, 0, 1);
				
				GE[8].sprite = SPR_addSpriteExSafe(&spr_petala_big,  30, 140, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[8].sprite, 1511); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[8].sprite, 0, 14);
				
				GE[9].sprite = SPR_addSpriteExSafe(&spr_petala_big,  30, 160, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[9].sprite, 1521); //define uma posicao especifica para o GFX na VRAM
				
				GE[10].sprite = SPR_addSpriteExSafe(&spr_petala_big,  70, 180, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				//SPR_setVRAMTileIndex(GE[10].sprite, 1521); //define uma posicao especifica para o GFX na VRAM
				
				GE[11].sprite = SPR_addSpriteExSafe(&spr_petala_big,  170, 10, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[11].sprite, 0, 1);
				GE[12].sprite = SPR_addSpriteExSafe(&spr_petala_big,  150, 30, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[12].sprite, 0, 3);
				GE[13].sprite = SPR_addSpriteExSafe(&spr_petala_big,  180, 50, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[13].sprite, 0, 5);
				GE[14].sprite = SPR_addSpriteExSafe(&spr_petala_big,  200, 70, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[14].sprite, 0, 7);
				GE[15].sprite = SPR_addSpriteExSafe(&spr_petala_big,  230, 90, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[15].sprite, 0, 9);
				
				GE[16].sprite = SPR_addSpriteExSafe(&spr_petala_big,  20, 20, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[16].sprite, 1441); //define uma posicao especifica para o GFX na VRAM
				SPR_setAnimAndFrame(GE[16].sprite, 0, 6);
				
				GE[17].sprite = SPR_addSpriteExSafe(&spr_petala_big,  270, 110, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[17].sprite, 0, 1);
				GE[18].sprite = SPR_addSpriteExSafe(&spr_petala_big,  250, 130, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[18].sprite, 0, 3);
				GE[19].sprite = SPR_addSpriteExSafe(&spr_petala_big,  280, 200, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[19].sprite, 0, 5);
				GE[20].sprite = SPR_addSpriteExSafe(&spr_petala_big,  240, 15, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[20].sprite, 0, 7);
				GE[21].sprite = SPR_addSpriteExSafe(&spr_petala_big,  300, 180, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setAnimAndFrame(GE[21].sprite, 0, 7);
				
				//Posicao Inicial Aleatoria das Petalas
				for(int i = 0; i<=21; i++){
					if(i== 2){ PetalaPX[i]=219; PetalaPY[i]=160; }
					if(i== 3){ PetalaPX[i]=242; PetalaPY[i]=108; }
					if(i== 4){ PetalaPX[i]=  2; PetalaPY[i]=162; }
					if(i== 5){ PetalaPX[i]=313; PetalaPY[i]=215; }
					if(i== 6){ PetalaPX[i]=122; PetalaPY[i]=107; }
					if(i== 7){ PetalaPX[i]= 47; PetalaPY[i]=186; }
					if(i== 8){ PetalaPX[i]=129; PetalaPY[i]= 95; }
					if(i== 9){ PetalaPX[i]=142; PetalaPY[i]= 42; }
					if(i==10){ PetalaPX[i]=242; PetalaPY[i]= 37; }
					if(i==11){ PetalaPX[i]= 86; PetalaPY[i]= 78; }
					if(i==12){ PetalaPX[i]=188; PetalaPY[i]=130; }
					if(i==13){ PetalaPX[i]=174; PetalaPY[i]=185; }
					if(i==14){ PetalaPX[i]=319; PetalaPY[i]=222; }
					if(i==15){ PetalaPX[i]= 45; PetalaPY[i]=213; }
					if(i==16){ PetalaPX[i]=175; PetalaPY[i]= 50; }
					if(i==17){ PetalaPX[i]=265; PetalaPY[i]=136; }
					if(i==18){ PetalaPX[i]=128; PetalaPY[i]=133; }
					if(i==19){ PetalaPX[i]=145; PetalaPY[i]=126; }
					if(i==20){ PetalaPX[i]= 60; PetalaPY[i]= 93; }
					if(i==21){ PetalaPX[i]= 70; PetalaPY[i]= 20; }
				}
				
				//Todas as Petalas acima do algarismo romano 'II' /*samsho2*/
				for(int i =2; i<=21; i++){
					SPR_setDepth(GE[i].sprite, 1); 
				}
			}
			
			//Movimenta as Petalas
			for(int i = 2; i<=21; i++){
				PetalaPX[i]--; 
				PetalaPY[i]++; 
				if(i==1 || i==2){ PetalaPX[i]--; PetalaPY[i]++;  }
				if(i==5 || i==10 || i==15 || i==20){ PetalaPY[i]++; }
				if(i==6 || i==11 || i==16 || i==21){ if(gPing2==1){PetalaPX[i]++;} if(gPing10>=1 && gPing10<=4){PetalaPY[i]++;} }
				if(PetalaPX[i]<=-25){PetalaPX[i]=320;}
				if(PetalaPY[i]> 245){PetalaPY[i]=-24;}
				SPR_setPosition(GE[i].sprite, PetalaPX[i], PetalaPY[i]);
			}
			
			if(P[1].key_JOY_START_status==1 && gFrames>5)
			{
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				CLEAR_VDP();
				gFrames=0;
				gRoom = ROOM_CHAR_SELECT;
			};
			
}
