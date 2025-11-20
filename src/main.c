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
#include "char_select_room.h"

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
		
		if(gRoom == ROOM_PRESENTATION) //TELA DE APRESENTACAO -------------------------------------------------------
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
		
		if(gRoom == ROOM_CHAR_SELECT) //CHAR SELECT ----------------------------------------------------------------
		{
			char_select_room_handler();
		}
		
		if(gRoom == ROOM_STAGE_SELECT) //STAGE SELECT ---------------------------------------------------------------
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
		
		if(gRoom == ROOM_DESCOMPRESSION) //DESCOMPRESSION -------------------------------------------------------------
		{
			GE[1].sprite = SPR_addSpriteExSafe(&spr_point,  0, 225, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			GE[2].sprite = SPR_addSpriteExSafe(&spr_point,  0, 225, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			GE[3].sprite = SPR_addSpriteExSafe(&spr_point,  0, 225, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			
			if(gFrames==20)
			{
				if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
				if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
				if (GE[3].sprite){ SPR_releaseSprite(GE[3].sprite); GE[3].sprite = NULL; }
				gRoom=gDescompressionExit;
				gFrames=1; 
				CLEAR_VDP();
			}
			
		}
		
		if(gRoom == ROOM_IN_GAME) //IN GAME -------------------------------------------------------------------
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
		
		if(gRoom == ROOM_AFTER_MATCH) //AFTER MATCH ---------------------------------------------------------------
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
		
		//--- FINALIZACOES ---//
		//VDP_showFPS(1);        //Mostra a taxa de FPS
		SPR_update();          //Atualiza (desenha) os sprites
        SYS_doVBlankProcess(); //Wait for screen refresh and do all SGDK VBlank tasks
    }
	
    return 0;
}

//--- FUNCOES ---//


















//EOF - END OF FILE; by GAMEDEVBOSS 2015-2022