#include "char_select_room.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "input.h"
#include "utils.h"

void char_select_room_handler()
{
	FUNCAO_INPUT_SYSTEM(); //Verifica os joysticks 
			
			//"cursorConfirmTimer" eh usado para o efeito FX, ativado quando se escolhe um personagem
			//cursorConfirmTimer = Velocidade da animacao (sprite.res) * Total de quadros :)
			cursorConfirmTimer = 2*9; //18
			
			if(gFrames==1)
			{
				//comeca a tocar a musica
				XGM_startPlay(music_char_select); XGM_isPlaying(); //FIX
				
				cursorP1ConfirmFX = cursorConfirmTimer;
				cursorP2ConfirmFX = cursorConfirmTimer;
				
				//apos a escolha de ambos os players, este eh o tempo (em frames) para avancar para a proxima tela
				gTimerExit=60*2;
				
				//Fique atento para mudar aqui, ALTERE caso tenha outros personagens no jogo
				P[1].id = 1; cursorP1_ID = 1; //haohmaru selecao inicial
				P[2].id = 2; cursorP2_ID = 2; //gillius selecao inicial
				
				cursorP1ColorChoice = 1;
				cursorP2ColorChoice = 1;
				
				endP1Selection = 0;
				endP2Selection = 0;
				
				gInd_tileset=1;
			
				VDP_loadTileSet(bg_char_select_bgb.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_B,bg_char_select_bgb.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
				PAL_setPalette(PAL0, bg_char_select_bgb.palette->data, CPU);
				gInd_tileset += bg_char_select_bgb.tileset->numTile;
				
				VDP_loadTileSet(bg_char_select_bga.tileset,gInd_tileset,DMA); 
				VDP_setTileMapEx(BG_A,bg_char_select_bga.tilemap,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,gInd_tileset),12,19,0,0,16,8,DMA_QUEUE);
				PAL_setPalette(PAL1, bg_char_select_bga.palette->data, CPU);
				gInd_tileset += bg_char_select_bga.tileset->numTile;
				
				//Cursores
				GE[2].sprite = SPR_addSpriteExSafe(&spr_char_sel_cursor_p2, 192, 148, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[2].sprite, 1461); //define uma posicao especifica para o GFX na VRAM
				GE[1].sprite = SPR_addSpriteExSafe(&spr_char_sel_cursor_p1,  96, 148, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[1].sprite, 1441); //define uma posicao especifica para o GFX na VRAM
				
				//Retratos grandes
				GE[3].sprite = SPR_addSpriteExSafe(&spr_haohmaru_001,  16, 16, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				PAL_setPalette(PAL2, spr_haohmaru_001.palette->data, CPU);
				GE[4].sprite = SPR_addSpriteExSafe(&spr_gillius_001,  232, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				PAL_setPalette(PAL3, spr_gillius_001.palette->data, CPU);
				SPR_setHFlip(GE[4].sprite, TRUE);
				
				//Lutadores
				GE[5].sprite = SPR_addSpriteExSafe(&spr_haohmaru_100CS,   8,  98-8, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				GE[6].sprite = SPR_addSpriteExSafe(&spr_gillius_100CS,  228, 124-8, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setHFlip(GE[6].sprite, TRUE);
			}
			
			//Tamanho do seletor, quantidade total de personagens (Colunas * Linhas)
			u8 QtdeColunas = 4;
			u8 QtdeLinhas  = 2;
			u8 moverCursorP1 = 0;
			u8 moverCursorP2 = 0;
			u8 tamanhoDoIcone = 32; //tamanho do icone de selecao dos personagens, em pixels
			
			//Movimenta os cursores
			if(cursorP1ConfirmFX==cursorConfirmTimer)
			{
				if(P[1].key_JOY_RIGHT_status==1){ moverCursorP1=1; if(cursorP1coluna<QtdeColunas){cursorP1coluna++;}else{cursorP1coluna=1;} }
				if(P[1].key_JOY_LEFT_status ==1){ moverCursorP1=1; if(cursorP1coluna>1){cursorP1coluna--;}else{cursorP1coluna=QtdeColunas;} }
				if(P[1].key_JOY_UP_status   ==1){ moverCursorP1=1; if(cursorP1linha<QtdeLinhas){cursorP1linha++;}else{cursorP1linha=1;} }
				if(P[1].key_JOY_DOWN_status ==1){ moverCursorP1=1; if(cursorP1linha>1){cursorP1linha--;}else{cursorP1linha=QtdeLinhas;} }
			}
			
			if(cursorP2ConfirmFX==cursorConfirmTimer)
			{
				if(P[2].key_JOY_RIGHT_status==1){ moverCursorP2=1; if(cursorP2coluna<QtdeColunas){cursorP2coluna++;}else{cursorP2coluna=1;} }
				if(P[2].key_JOY_LEFT_status ==1){ moverCursorP2=1; if(cursorP2coluna>1){cursorP2coluna--;}else{cursorP2coluna=QtdeColunas;} }
				if(P[2].key_JOY_UP_status   ==1){ moverCursorP2=1; if(cursorP2linha<QtdeLinhas){cursorP2linha++;}else{cursorP2linha=1;} }
				if(P[2].key_JOY_DOWN_status ==1){ moverCursorP2=1; if(cursorP2linha>1){cursorP2linha--;}else{cursorP2linha=QtdeLinhas;} }
			}			
			
			//Mapeamento dos personagens
			/*
			            1       2       3       4     coluna
			        +-------+-------+-------+-------+
			  1     | char1 | char2 | char3 | char4 |
			        +-------+-------+-------+-------+
			  2     | char5 | char6 | char7 | char8 |
			        +-------+-------+-------+-------+
			linha
			*/
			
			if(moverCursorP1==1) //P1
			{
				XGM_setPCM(P1_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
				
				//atribuicao de ID
				if(cursorP1coluna==1 && cursorP1linha==1){ cursorP1_ID=1; }
				if(cursorP1coluna==2 && cursorP1linha==1){ cursorP1_ID=2; }
				if(cursorP1coluna==3 && cursorP1linha==1){ cursorP1_ID=1; }
				if(cursorP1coluna==4 && cursorP1linha==1){ cursorP1_ID=2; }
				if(cursorP1coluna==1 && cursorP1linha==2){ cursorP1_ID=2; }
				if(cursorP1coluna==2 && cursorP1linha==2){ cursorP1_ID=1; }
				if(cursorP1coluna==3 && cursorP1linha==2){ cursorP1_ID=2; }
				if(cursorP1coluna==4 && cursorP1linha==2){ cursorP1_ID=1; }
				P[1].id = cursorP1_ID;
				
				//Movimentacao de Sprite do cursor
				SPR_setPosition(GE[1].sprite, 96+((cursorP1coluna-1)*tamanhoDoIcone), 148+((cursorP1linha-1)*tamanhoDoIcone));
				
				//Update Visual Char
				if (GE[3].sprite){ SPR_releaseSprite(GE[3].sprite); GE[3].sprite = NULL; }
				if (GE[5].sprite){ SPR_releaseSprite(GE[5].sprite); GE[5].sprite = NULL; }
				
				if(cursorP1_ID==1)
				{
					GE[3].sprite = SPR_addSpriteExSafe(&spr_haohmaru_001,  16, 16, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL2, spr_haohmaru_001.palette->data, CPU);
					GE[5].sprite = SPR_addSpriteExSafe(&spr_haohmaru_100CS, 8, 98-8, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				}
				if(cursorP1_ID==2)
				{
					GE[3].sprite = SPR_addSpriteExSafe(&spr_gillius_001,  16,  16, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL2, spr_gillius_001.palette->data, CPU);
					GE[5].sprite = SPR_addSpriteExSafe(&spr_gillius_100CS, -14, 124-8, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				}
			}//---end P1
			
			if(moverCursorP2==1) //P2
			{
				XGM_setPCM(P2_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4);
				
				//atribuicao de ID
				if(cursorP2coluna==1 && cursorP2linha==1){ cursorP2_ID=1; }
				if(cursorP2coluna==2 && cursorP2linha==1){ cursorP2_ID=2; }
				if(cursorP2coluna==3 && cursorP2linha==1){ cursorP2_ID=1; }
				if(cursorP2coluna==4 && cursorP2linha==1){ cursorP2_ID=2; }
				if(cursorP2coluna==1 && cursorP2linha==2){ cursorP2_ID=2; }
				if(cursorP2coluna==2 && cursorP2linha==2){ cursorP2_ID=1; }
				if(cursorP2coluna==3 && cursorP2linha==2){ cursorP2_ID=2; }
				if(cursorP2coluna==4 && cursorP2linha==2){ cursorP2_ID=1; }
				P[2].id = cursorP2_ID;
				
				//Movimentacao de Sprite do cursor
				SPR_setPosition(GE[2].sprite, 96+((cursorP2coluna-1)*tamanhoDoIcone), 148+((cursorP2linha-1)*tamanhoDoIcone));
				
				//Update Visual Char
				if (GE[4].sprite){ SPR_releaseSprite(GE[4].sprite); GE[4].sprite = NULL; }
				if (GE[6].sprite){ SPR_releaseSprite(GE[6].sprite); GE[6].sprite = NULL; }
				
				if(cursorP2_ID==1)
				{
					GE[4].sprite = SPR_addSpriteExSafe(&spr_haohmaru_001,  232, 16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL3, spr_haohmaru_001.palette->data, CPU);
					GE[6].sprite = SPR_addSpriteExSafe(&spr_haohmaru_100CS, 230, 98-8, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					SPR_setHFlip(GE[6].sprite, TRUE);
				}
				if(cursorP2_ID==2)
				{
					GE[4].sprite = SPR_addSpriteExSafe(&spr_gillius_001,   232,  16, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					PAL_setPalette(PAL3, spr_gillius_001.palette->data, CPU);
					GE[6].sprite = SPR_addSpriteExSafe(&spr_gillius_100CS, 228, 124-8, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				}
				SPR_setHFlip(GE[4].sprite, TRUE);
				SPR_setHFlip(GE[6].sprite, TRUE);
			}//---end P2
			
			//Seleciona o Char, P1
			if(
				cursorP1ConfirmFX==cursorConfirmTimer && (
				P[1].key_JOY_A_status==1 || P[1].key_JOY_B_status==1 || P[1].key_JOY_C_status==1 || 
				P[1].key_JOY_X_status==1 || P[1].key_JOY_Y_status==1 || P[1].key_JOY_Z_status==1 || 
				P[1].key_JOY_START_status==1 || P[1].key_JOY_MODE_status==1 )
			)
			{
				cursorP1ConfirmFX--;
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				GE[1].sprite = SPR_addSpriteExSafe(&spr_cursor_confirm,  96+((cursorP1coluna-1)*tamanhoDoIcone), 148+((cursorP1linha-1)*tamanhoDoIcone)+4, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[1].sprite, 1441); //define uma posicao especifica para o GFX na VRAM
			}
			if(cursorP1ConfirmFX<cursorConfirmTimer)
			{
				if(cursorP1ConfirmFX>0)
				{
					cursorP1ConfirmFX--;
					if(cursorP1ConfirmFX==1)
					{
						XGM_setPCM(P1_SFX, snd_confirm, sizeof(snd_confirm)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
						
						if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
						GE[1].sprite = SPR_addSpriteExSafe(&spr_color_cursor,  20, 89, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					}
				}else{
					//SELECAO DE COR!
					u8 mudarcor=0;
					if(P[1].key_JOY_RIGHT_status==1 && endP1Selection==0){ mudarcor=1; if(cursorP1ColorChoice<8){cursorP1ColorChoice++; }else{cursorP1ColorChoice=1;} }
					if(P[1].key_JOY_LEFT_status ==1 && endP1Selection==0){ mudarcor=1; if(cursorP1ColorChoice>1){cursorP1ColorChoice--; }else{cursorP1ColorChoice=8;} }
					if(mudarcor==1)
					{
						XGM_setPCM(P1_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
						
						if(cursorP1_ID==1) //haohmaru
						{
							if(cursorP1ColorChoice==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_1a.palette->data, CPU); }
							if(cursorP1ColorChoice==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_1a.palette->data, CPU); }
						}
						if(cursorP1_ID==2) //gillius
						{
							if(cursorP1ColorChoice==1){ PAL_setPalette(PAL2, spr_gillius_pal1.palette->data, CPU); }
							if(cursorP1ColorChoice==2){ PAL_setPalette(PAL2, spr_gillius_pal2.palette->data, CPU); }
							if(cursorP1ColorChoice==3){ PAL_setPalette(PAL2, spr_gillius_pal3.palette->data, CPU); }
							if(cursorP1ColorChoice==4){ PAL_setPalette(PAL2, spr_gillius_pal4.palette->data, CPU); }
							if(cursorP1ColorChoice==5){ PAL_setPalette(PAL2, spr_gillius_pal5.palette->data, CPU); }
							if(cursorP1ColorChoice==6){ PAL_setPalette(PAL2, spr_gillius_pal6.palette->data, CPU); }
							if(cursorP1ColorChoice==7){ PAL_setPalette(PAL2, spr_gillius_pal7.palette->data, CPU); }
							if(cursorP1ColorChoice==8){ PAL_setPalette(PAL2, spr_gillius_pal8.palette->data, CPU); }
						}
						//Movimentacao de Sprite do cursor de cor
						SPR_setPosition(GE[1].sprite, 20+((cursorP1ColorChoice-1)*8), 89);
					}
					if(
						endP1Selection==0 && (
						P[1].key_JOY_A_status==1 || P[1].key_JOY_B_status==1 || P[1].key_JOY_C_status==1 || 
						P[1].key_JOY_X_status==1 || P[1].key_JOY_Y_status==1 || P[1].key_JOY_Z_status==1 || 
						P[1].key_JOY_START_status==1 || P[1].key_JOY_MODE_status==1 )
					)
					{
						endP1Selection=1;
						
						XGM_setPCM(P1_SFX, snd_confirm, sizeof(snd_confirm)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3);
						
						if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
						GE[1].sprite = SPR_addSpriteExSafe(&spr_color_cursor_static,  20+((cursorP1ColorChoice-1)*8), 89, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					}
				}
			}
			
			//Seleciona o Char, P2
			if(
				cursorP2ConfirmFX==cursorConfirmTimer && (
				P[2].key_JOY_A_status==1 || P[2].key_JOY_B_status==1 || P[2].key_JOY_C_status==1 || 
				P[2].key_JOY_X_status==1 || P[2].key_JOY_Y_status==1 || P[2].key_JOY_Z_status==1 || 
				P[2].key_JOY_START_status==1 || P[2].key_JOY_MODE_status==1 )
			)
			{
				cursorP2ConfirmFX--;
				if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
				GE[2].sprite = SPR_addSpriteExSafe(&spr_cursor_confirm,  96+((cursorP2coluna-1)*tamanhoDoIcone), 148+((cursorP2linha-1)*tamanhoDoIcone)+4, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
				SPR_setVRAMTileIndex(GE[2].sprite, 1461); //define uma posicao especifica para o GFX na VRAM
			}
			if(cursorP2ConfirmFX<cursorConfirmTimer)
			{
				if(cursorP2ConfirmFX>0)
				{
					cursorP2ConfirmFX--;
					if(cursorP2ConfirmFX==1)
					{
						XGM_setPCM(P2_SFX, snd_confirm, sizeof(snd_confirm)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4);
						
						if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
						GE[2].sprite = SPR_addSpriteExSafe(&spr_color_cursor,  237, 89, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					}
				}else{
					//SELECAO DE COR!
					u8 mudarcor=0;
					if(P[2].key_JOY_RIGHT_status==1 && endP2Selection==0){ mudarcor=1; if(cursorP2ColorChoice<8){cursorP2ColorChoice++; }else{cursorP2ColorChoice=1;} }
					if(P[2].key_JOY_LEFT_status ==1 && endP2Selection==0){ mudarcor=1; if(cursorP2ColorChoice>1){cursorP2ColorChoice--; }else{cursorP2ColorChoice=8;} }
					if(mudarcor==1)
					{
						XGM_setPCM(P2_SFX, snd_cursor, sizeof(snd_cursor)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4);
						
						if(cursorP2_ID==1) //haohmaru
						{
							if(cursorP2ColorChoice==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_1a.palette->data, CPU); }
							if(cursorP2ColorChoice==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_1a.palette->data, CPU); }
						}
						if(cursorP2_ID==2) //gillius
						{
							if(cursorP2ColorChoice==1){ PAL_setPalette(PAL3, spr_gillius_pal1.palette->data, CPU); }
							if(cursorP2ColorChoice==2){ PAL_setPalette(PAL3, spr_gillius_pal2.palette->data, CPU); }
							if(cursorP2ColorChoice==3){ PAL_setPalette(PAL3, spr_gillius_pal3.palette->data, CPU); }
							if(cursorP2ColorChoice==4){ PAL_setPalette(PAL3, spr_gillius_pal4.palette->data, CPU); }
							if(cursorP2ColorChoice==5){ PAL_setPalette(PAL3, spr_gillius_pal5.palette->data, CPU); }
							if(cursorP2ColorChoice==6){ PAL_setPalette(PAL3, spr_gillius_pal6.palette->data, CPU); }
							if(cursorP2ColorChoice==7){ PAL_setPalette(PAL3, spr_gillius_pal7.palette->data, CPU); }
							if(cursorP2ColorChoice==8){ PAL_setPalette(PAL3, spr_gillius_pal8.palette->data, CPU); }
						}
						//Movimentacao de Sprite do cursor de cor
						SPR_setPosition(GE[2].sprite, 237+((cursorP2ColorChoice-1)*8), 89);
					}
					if(
						endP2Selection==0 && (
						P[2].key_JOY_A_status==1 || P[2].key_JOY_B_status==1 || P[2].key_JOY_C_status==1 || 
						P[2].key_JOY_X_status==1 || P[2].key_JOY_Y_status==1 || P[2].key_JOY_Z_status==1 || 
						P[2].key_JOY_START_status==1 || P[2].key_JOY_MODE_status==1 )
					)
					{
						endP2Selection=1;
						
						XGM_setPCM(P2_SFX, snd_confirm, sizeof(snd_confirm)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4);
						
						if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
						GE[2].sprite = SPR_addSpriteExSafe(&spr_color_cursor_static,  237+((cursorP2ColorChoice-1)*8), 89, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
					}
				}
			}
			
			//Saida
			if(endP1Selection==1 && endP2Selection==1){ gTimerExit--; }
			if(gTimerExit==1)
			{ 
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
				if (GE[3].sprite){ SPR_releaseSprite(GE[3].sprite); GE[3].sprite = NULL; }
				if (GE[4].sprite){ SPR_releaseSprite(GE[4].sprite); GE[4].sprite = NULL; }
				if (GE[5].sprite){ SPR_releaseSprite(GE[5].sprite); GE[5].sprite = NULL; }
				if (GE[6].sprite){ SPR_releaseSprite(GE[6].sprite); GE[6].sprite = NULL; }
				CLEAR_VDP(); 
				gFrames=0; 
				gRoom = ROOM_STAGE_SELECT; 
			}
}
