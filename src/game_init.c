#include "game_init.h"
#include "sprite.h"
#include "gfx.h"
#include "sound.h"
#include "player.h"
#include "utils.h"

void FUNCAO_INICIALIZACAO()
{
	gPodeMover=0;
	
	//BG_B
	gInd_tileset=1; //Antes de carregar o Background, definir o ponto de inicio de carregamento na VRAM
	
	//Load the tileset 'BGB1'
	if(gBG_Choice==1){ 
		gBG_Width = 560; // Largura do Cenario em pixels!
		gScrollValue=-(gBG_Width-320)/2;
		VDP_loadTileSet(gfx_bgb1A.tileset,gInd_tileset,DMA); 
		VDP_setTileMapEx(BG_B,gfx_bgb1A.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,gBG_Width/8,28,DMA_QUEUE);
		PAL_setPalette(PAL0, gfx_bgb1A.palette->data, CPU);
		gInd_tileset += gfx_bgb1A.tileset->numTile;
	} 
	
	//Load the tileset 'BGB2'
	if(gBG_Choice==2){ 
		gBG_Width = 320; // Largura do Cenario em pixels!
		gScrollValue=-(gBG_Width-320)/2;
		VDP_loadTileSet(gfx_bgb2.tileset,gInd_tileset,DMA); 
		VDP_setTileMapEx(BG_B,gfx_bgb2.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,gBG_Width/8,28,DMA_QUEUE);
		PAL_setPalette(PAL0, gfx_bgb2.palette->data, CPU);
		gInd_tileset += gfx_bgb2.tileset->numTile;
	} 
	
	//Load the tileset 'BGB3'
	if(gBG_Choice==3){ 
		gBG_Width = 624; // Largura do Cenario em pixels!
		gScrollValue=-(gBG_Width-320)/2;
		VDP_loadTileSet(gfx_bgb3.tileset,gInd_tileset,DMA); 
		VDP_setTileMapEx(BG_B,gfx_bgb3.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,gInd_tileset),0,0,0,0,gBG_Width/8,28,DMA_QUEUE);
		PAL_setPalette(PAL0, gfx_bgb3.palette->data, CPU);
		gInd_tileset += gfx_bgb3.tileset->numTile;
	} 
	
	//load palette HUD in PAL1, GFX load AFTER round intro...
	PAL_setPalette(PAL1, spr_n0.palette->data, CPU); 
	
	gAlturaPiso = (224/20)*19;
	
	for(i=1; i<=2; i++) { P[i].key_JOY_countdown[2]=0; P[i].key_JOY_countdown[4]=0; P[i].key_JOY_countdown[6]=0; P[i].key_JOY_countdown[8]=0; }
	
	//P1
	P[1].energia = 128;
	P[1].energiaBase = 128;
	P[1].energiaSP = 0;
	P[1].rageTimerCountdown=RAGETIMER;
	P[1].wins = 0;
	P[1].x = (320/4);
	P[1].y = gAlturaPiso;
	P[1].hitPause = 0;
	P[1].direcao = 1;
	P[1].state = 610; //610, Intro State!
	P[1].puloTimer = 0;
	P[1].dataMBox[0] = -BODYSPACE;
	P[1].dataMBox[1] = -60;
	P[1].dataMBox[2] = +BODYSPACE;
	P[1].dataMBox[3] = - 1;
	P[1].paleta = PAL2;
	P[1].cicloInteracoesGravidade = CIGD; //CIGD eh uma definicao global! ver inicio do codigo
	P[1].cicloInteracoesGravidadeCont = 0;
	P[1].fBallActive = 0;
	
	//P2
	P[2].energia = 128;
	P[2].energiaBase = 128;
	P[2].energiaSP = 0;
	P[2].rageTimerCountdown=RAGETIMER;
	P[2].wins = 0;
	P[2].x = (320/4)*3;
	P[2].y = gAlturaPiso;
	P[2].hitPause = 0;
	P[2].direcao = -1;
	P[2].state = 610; //610, Intro State!
	P[2].puloTimer = 0;
	P[2].dataMBox[0] = -BODYSPACE;
	P[2].dataMBox[1] = -60;
	P[2].dataMBox[2] = +BODYSPACE;
	P[2].dataMBox[3] = - 1;
	P[2].paleta = PAL3;
	P[2].cicloInteracoesGravidade = CIGD; //CIGD eh uma definicao global! ver inicio do codigo
	P[2].cicloInteracoesGravidadeCont = 0;
	P[2].fBallActive = 0;
	
	P[1].sombra = SPR_addSpriteExSafe(&spr_sombra, P[1].x-P[1].axisX, P[1].y-2, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	if(gSombraStyle==2)
	{
		P[2].sombra = SPR_addSpriteExSafe(&spr_sombra, P[2].x-P[1].axisX, P[2].y-2, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	}
	
	//reset Graphic Elements
	if (GE[ 1].sprite){ SPR_releaseSprite(GE[ 1].sprite); GE[ 1].sprite = NULL; }
	if (GE[ 2].sprite){ SPR_releaseSprite(GE[ 2].sprite); GE[ 2].sprite = NULL; }
	if (GE[ 3].sprite){ SPR_releaseSprite(GE[ 3].sprite); GE[ 3].sprite = NULL; }
	if (GE[ 4].sprite){ SPR_releaseSprite(GE[ 4].sprite); GE[ 4].sprite = NULL; }
	if (GE[ 5].sprite){ SPR_releaseSprite(GE[ 5].sprite); GE[ 5].sprite = NULL; }
	if (GE[ 6].sprite){ SPR_releaseSprite(GE[ 6].sprite); GE[ 6].sprite = NULL; }
	if (GE[ 7].sprite){ SPR_releaseSprite(GE[ 7].sprite); GE[ 7].sprite = NULL; }
	if (GE[ 8].sprite){ SPR_releaseSprite(GE[ 8].sprite); GE[ 8].sprite = NULL; }
	if (GE[ 9].sprite){ SPR_releaseSprite(GE[ 9].sprite); GE[ 9].sprite = NULL; }
	if (GE[10].sprite){ SPR_releaseSprite(GE[10].sprite); GE[10].sprite = NULL; }
	if (GE[11].sprite){ SPR_releaseSprite(GE[11].sprite); GE[11].sprite = NULL; }
	if (GE[12].sprite){ SPR_releaseSprite(GE[12].sprite); GE[12].sprite = NULL; }
	if (GE[13].sprite){ SPR_releaseSprite(GE[13].sprite); GE[13].sprite = NULL; }
	if (GE[14].sprite){ SPR_releaseSprite(GE[14].sprite); GE[14].sprite = NULL; }
	if (GE[15].sprite){ SPR_releaseSprite(GE[15].sprite); GE[15].sprite = NULL; }
	if (GE[16].sprite){ SPR_releaseSprite(GE[16].sprite); GE[16].sprite = NULL; }
	if (GE[17].sprite){ SPR_releaseSprite(GE[17].sprite); GE[17].sprite = NULL; }
	if (GE[18].sprite){ SPR_releaseSprite(GE[18].sprite); GE[18].sprite = NULL; }
	if (GE[19].sprite){ SPR_releaseSprite(GE[19].sprite); GE[19].sprite = NULL; }
	if (GE[20].sprite){ SPR_releaseSprite(GE[20].sprite); GE[20].sprite = NULL; }
	
	gClockTimer=60; //Relogio, timer de 1 seg
	gClockLTimer=9; //Digito esquerdo do Relogio
	gClockRTimer=9; //Digito direito do Relogio
	gRound=1;       //Round Number
	
	//Marcadores de Vitoria e Retratos da Interface ingame
	GE[12].sprite = SPR_addSpriteExSafe(&spr_icon_victory, 26-8, 25, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setDepth(GE[12].sprite, 255 );
	SPR_setVRAMTileIndex(GE[12].sprite, 1530); //define uma posicao especifica para o GFX na VRAM
	GE[13].sprite = SPR_addSpriteExSafe(&spr_icon_victory, 52-8, 25, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setDepth(GE[13].sprite, 255 );
	SPR_setVRAMTileIndex(GE[13].sprite, 1530); //define uma posicao especifica para o GFX na VRAM
	GE[14].sprite = SPR_addSpriteExSafe(&spr_icon_victory,240+8+4, 25, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setDepth(GE[14].sprite, 255 );
	SPR_setVRAMTileIndex(GE[14].sprite, 1530); //define uma posicao especifica para o GFX na VRAM
	GE[15].sprite = SPR_addSpriteExSafe(&spr_icon_victory,266+8+4, 25, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setDepth(GE[15].sprite, 255 );
	SPR_setVRAMTileIndex(GE[15].sprite, 1530); //define uma posicao especifica para o GFX na VRAM
	
	//Retratos
	if(P[1].id==1){ GE[16].sprite = SPR_addSpriteExSafe(&spr_haohmaru_000, 0, 24, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
	if(P[1].id==2){ GE[16].sprite = SPR_addSpriteExSafe(&spr_gillius_000,  0, 24, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
	SPR_setDepth(GE[16].sprite, 255 );
	SPR_setVRAMTileIndex(GE[16].sprite, 1522); //define uma posicao especifica para o GFX na VRAM
	
	if(P[2].id==1){ GE[17].sprite = SPR_addSpriteExSafe(&spr_haohmaru_000, 304, 24, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
	if(P[2].id==2){ GE[17].sprite = SPR_addSpriteExSafe(&spr_gillius_000,  304, 24, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
	if(P[1].id==P[2].id){ SPR_setVRAMTileIndex(GE[17].sprite, 1522); } //SE P1 e P2 IGUAIS, ENTAO... define uma posicao especifica para o GFX na VRAM
	SPR_setDepth(GE[17].sprite, 255 );
	SPR_setHFlip(GE[17].sprite, TRUE);
	
	//Desliga a visibilidade destes elementos de HUD (Marcadores de Vitoria e Retratos da Interface ingame)
	SPR_setVisibility(GE[12].sprite, HIDDEN); 
	SPR_setVisibility(GE[13].sprite, HIDDEN); 
	SPR_setVisibility(GE[14].sprite, HIDDEN); 
	SPR_setVisibility(GE[15].sprite, HIDDEN); 
	SPR_setVisibility(GE[16].sprite, HIDDEN); 
	SPR_setVisibility(GE[17].sprite, HIDDEN); 
	
	ClockL = SPR_addSpriteEx(&spr_n9, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	ClockR = SPR_addSpriteEx(&spr_n9, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setVRAMTileIndex(ClockL,1703); //define uma posicao especifica para o GFX na VRAM
	SPR_setVRAMTileIndex(ClockR,1707); //define uma posicao especifica para o GFX na VRAM
	
	//desabilitado na intro...
	SPR_setVisibility(ClockL, HIDDEN); 
	SPR_setVisibility(ClockR, HIDDEN);
	
	Rect1BB1_Q1 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1BB1_Q2 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1BB1_Q3 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1BB1_Q4 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1HB1_Q1 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1HB1_Q2 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1HB1_Q3 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect1HB1_Q4 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	
	Rect2BB1_Q1 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2BB1_Q2 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2BB1_Q3 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2BB1_Q4 = SPR_addSpriteEx(&spr_rect_bb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2HB1_Q1 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2HB1_Q2 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2HB1_Q3 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	Rect2HB1_Q4 = SPR_addSpriteEx(&spr_rect_hb, -8, -8, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	
	SPR_setHFlip(Rect1BB1_Q2, TRUE);
	SPR_setVFlip(Rect1BB1_Q3, TRUE);
	SPR_setHFlip(Rect1BB1_Q4, TRUE); SPR_setVFlip(Rect1BB1_Q4, TRUE);
	SPR_setHFlip(Rect1HB1_Q2, TRUE);
	SPR_setVFlip(Rect1HB1_Q3, TRUE);
	SPR_setHFlip(Rect1HB1_Q4, TRUE); SPR_setVFlip(Rect1HB1_Q4, TRUE);
	
	SPR_setHFlip(Rect2BB1_Q2, TRUE);
	SPR_setVFlip(Rect2BB1_Q3, TRUE);
	SPR_setHFlip(Rect2BB1_Q4, TRUE); SPR_setVFlip(Rect2BB1_Q4, TRUE);
	SPR_setHFlip(Rect2HB1_Q2, TRUE);
	SPR_setVFlip(Rect2HB1_Q3, TRUE);
	SPR_setHFlip(Rect2HB1_Q4, TRUE); SPR_setVFlip(Rect2HB1_Q4, TRUE);
	
	SPR_setDepth(Rect1BB1_Q1, 1);
	SPR_setDepth(Rect1BB1_Q2, 1);
	SPR_setDepth(Rect1BB1_Q3, 1);
	SPR_setDepth(Rect1BB1_Q4, 1);
	SPR_setDepth(Rect1HB1_Q1, 1);
	SPR_setDepth(Rect1HB1_Q2, 1);
	SPR_setDepth(Rect1HB1_Q3, 1);
	SPR_setDepth(Rect1HB1_Q4, 1);
	
	SPR_setDepth(Rect2BB1_Q1, 1);
	SPR_setDepth(Rect2BB1_Q2, 1);
	SPR_setDepth(Rect2BB1_Q3, 1);
	SPR_setDepth(Rect2BB1_Q4, 1);
	SPR_setDepth(Rect2HB1_Q1, 1);
	SPR_setDepth(Rect2HB1_Q2, 1);
	SPR_setDepth(Rect2HB1_Q3, 1);
	SPR_setDepth(Rect2HB1_Q4, 1);
	
	//Intro State, Player Start
	P[1].sprite = SPR_addSpriteExSafe(&spr_point, P[1].x-P[1].axisX, P[1].y-P[1].axisY, TILE_ATTR(PAL2, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	P[2].sprite = SPR_addSpriteExSafe(&spr_point, P[2].x-P[2].axisX, P[2].y-P[2].axisY, TILE_ATTR(PAL3, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	
	//Se Player1 e Player2 com o mesmo personagem, desliguei a intro, pois elas somadas, usam muitos tiles /*samsho2*/
	if(P[1].id!=P[2].id)
	{
		PLAYER_STATE(1, STATE_INTRO);
		PLAYER_STATE(2, STATE_INTRO);
	}else{
		PLAYER_STATE(1, STATE_PARADO);
		PLAYER_STATE(2, STATE_PARADO);
	}
	
	SPR_setHFlip(P[2].sprite, TRUE);
	
	//Define a paleta dos players...
	P[1].palID=cursorP1ColorChoice;
	P[2].palID=cursorP2ColorChoice; 
	
	if( P[1].id==P[2].id && P[1].palID==P[2].palID)
	{
		//se ambos os players forem iguais e com a mesma paleta...
		P[1].palID=1; //Por padrao, P1 fica com a paleta 1
		P[2].palID=2; //Por padrao, P2 fica com a paleta 2 'cor alternativa'
	}
	
	if(P[1].id==1 && P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_1a.palette->data, CPU); } //haohmaru
	if(P[1].id==1 && P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_1a.palette->data, CPU); } //haohmaru
	
	if(P[1].id==2 && P[1].palID==1){ PAL_setPalette(PAL2, spr_gillius_pal1.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==2){ PAL_setPalette(PAL2, spr_gillius_pal2.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==3){ PAL_setPalette(PAL2, spr_gillius_pal3.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==4){ PAL_setPalette(PAL2, spr_gillius_pal4.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==5){ PAL_setPalette(PAL2, spr_gillius_pal5.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==6){ PAL_setPalette(PAL2, spr_gillius_pal6.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==7){ PAL_setPalette(PAL2, spr_gillius_pal7.palette->data, CPU); } //gillius
	if(P[1].id==2 && P[1].palID==8){ PAL_setPalette(PAL2, spr_gillius_pal8.palette->data, CPU); } //gillius
	
	if(P[2].id==1 && P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_1a.palette->data, CPU); } //haohmaru
	if(P[2].id==1 && P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_1a.palette->data, CPU); } //haohmaru
	
	if(P[2].id==2 && P[2].palID==1){ PAL_setPalette(PAL3, spr_gillius_pal1.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==2){ PAL_setPalette(PAL3, spr_gillius_pal2.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==3){ PAL_setPalette(PAL3, spr_gillius_pal3.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==4){ PAL_setPalette(PAL3, spr_gillius_pal4.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==5){ PAL_setPalette(PAL3, spr_gillius_pal5.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==6){ PAL_setPalette(PAL3, spr_gillius_pal6.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==7){ PAL_setPalette(PAL3, spr_gillius_pal7.palette->data, CPU); } //gillius
	if(P[2].id==2 && P[2].palID==8){ PAL_setPalette(PAL3, spr_gillius_pal8.palette->data, CPU); } //gillius
	
	//AXIS
	if (GE[1].sprite){ SPR_releaseSprite(GE[1].sprite); GE[1].sprite = NULL; }
	if (GE[2].sprite){ SPR_releaseSprite(GE[2].sprite); GE[2].sprite = NULL; }
	GE[1].sprite = SPR_addSpriteExSafe(&spr_point, P[1].x-4, P[1].y-5, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	GE[2].sprite = SPR_addSpriteExSafe(&spr_point, P[2].x-4, P[2].y-5, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
	SPR_setVisibility(GE[1].sprite, HIDDEN);
	SPR_setVisibility(GE[2].sprite, HIDDEN);
	
	//DEPTH
	SPR_setDepth(GE[1].sprite, 1 );
	SPR_setDepth(GE[2].sprite, 2 );
	
	//depth 3 e 4 reservados
	SPR_setDepth(P[1].sprite,  5 );
	SPR_setDepth(P[2].sprite,  6 );
	//depth 7 e 8 reservados
	SPR_setDepth(P[1].sombra, 98 );
	if(gSombraStyle==2){ SPR_setDepth(P[2].sombra, 99 ); }
}

void FUNCAO_ROUND_INIT()
{
	/*samsho2*/ //-Intro Rotine -BEGIN-//
	 if(gFrames== 3){ 
		
		//clear sprite
		if (HUD_Lethers){ SPR_releaseSprite(HUD_Lethers); HUD_Lethers = NULL; }
		
		//Gairyu Isle Evening
		if(gBG_Choice==1){ HUD_Lethers = SPR_addSpriteEx(&spr_BG_desc1, 72, 48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		//Gairyu Isle Night
		if(gBG_Choice==2){ HUD_Lethers = SPR_addSpriteEx(&spr_BG_desc2, 72, 48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		//Himalaya Top of The Montain
		if(gBG_Choice==3){ HUD_Lethers = SPR_addSpriteEx(&spr_BG_desc3, 72, 48, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
	 }
	 if(gFrames== 63){ SPR_releaseSprite(HUD_Lethers); }
	 
	 //start SFX
	 if(gFrames== 64 && gRound==1)
	 { 
		XGM_setPCM(INGAME_SFX, snd_round_init, sizeof(snd_round_init)); XGM_startPlayPCM(INGAME_SFX, 1, SOUND_PCM_CH3); 
	 }
	 
	 if(gFrames== 65){ HUD_Lethers = SPR_addSpriteEx(&spr_engarde, 96, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
	 if(gFrames== 70){ SPR_setAnimAndFrame(HUD_Lethers, 0, 1); }
	 if(gFrames== 75){ SPR_setAnimAndFrame(HUD_Lethers, 0, 2); }
	 if(gFrames== 80){ SPR_setAnimAndFrame(HUD_Lethers, 0, 3); }
	 if(gFrames== 85){ SPR_setAnimAndFrame(HUD_Lethers, 0, 4); }
	 if(gFrames== 90){ SPR_setAnimAndFrame(HUD_Lethers, 0, 5); }
	 if(gFrames== 95){ SPR_setAnimAndFrame(HUD_Lethers, 0, 6); }
	 if(gFrames==100){ SPR_setAnimAndFrame(HUD_Lethers, 0, 7); }
	 if(gFrames==169){ SPR_setAnimAndFrame(HUD_Lethers, 0, 8); }
	 if(gFrames==173){ SPR_setAnimAndFrame(HUD_Lethers, 0, 9); }
	 if(gFrames==175){ SPR_setAnimAndFrame(HUD_Lethers, 0,10); }
	 if(gFrames==177){ SPR_setAnimAndFrame(HUD_Lethers, 0,11); }
	 if(gFrames==179){ SPR_setAnimAndFrame(HUD_Lethers, 0,12); }
	 if(gFrames==181){ SPR_setAnimAndFrame(HUD_Lethers, 0,13); }
	 if(gFrames==183){ SPR_setAnimAndFrame(HUD_Lethers, 0,14); }
	 if(gFrames==185){ SPR_releaseSprite(HUD_Lethers); }
	 if(gFrames==193)
	 { 
		if(gRound==1){ HUD_Lethers = SPR_addSpriteEx(&spr_duel1, 112, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		if(gRound==2){ HUD_Lethers = SPR_addSpriteEx(&spr_duel2, 112, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		if(gRound==3){ HUD_Lethers = SPR_addSpriteEx(&spr_duel3, 112, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		if(gRound==4){ HUD_Lethers = SPR_addSpriteEx(&spr_duel4, 112, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
		if(gRound==5){ HUD_Lethers = SPR_addSpriteEx(&spr_duel5, 112, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
	 }
	 if(gFrames==195){ SPR_setAnimAndFrame(HUD_Lethers, 0, 1); }
	 if(gFrames==197){ SPR_setAnimAndFrame(HUD_Lethers, 0, 2); }
	 if(gFrames==199){ SPR_setAnimAndFrame(HUD_Lethers, 0, 3); }
	 if(gFrames==201){ SPR_setAnimAndFrame(HUD_Lethers, 0, 4); }
	 if(gFrames==203){ SPR_setAnimAndFrame(HUD_Lethers, 0, 5); }
	 if(gFrames==205){ SPR_setAnimAndFrame(HUD_Lethers, 0, 6); }
	 if(gFrames==207){ SPR_setAnimAndFrame(HUD_Lethers, 0, 7); }
	 if(gFrames==237){ SPR_setAnimAndFrame(HUD_Lethers, 0, 8); }
	 if(gFrames==239){ SPR_setAnimAndFrame(HUD_Lethers, 0, 9); }
	 if(gFrames==241){ SPR_setAnimAndFrame(HUD_Lethers, 0,10); }
	 if(gFrames==243){ SPR_setAnimAndFrame(HUD_Lethers, 0,11); }
	 if(gFrames==245){ SPR_setAnimAndFrame(HUD_Lethers, 0,12); }
	 if(gFrames==247){ SPR_setAnimAndFrame(HUD_Lethers, 0,13); }
	 if(gFrames==249){ SPR_setAnimAndFrame(HUD_Lethers, 0,14); }
	 if(gFrames==251){ SPR_releaseSprite(HUD_Lethers); }
	 if(gFrames==293){ HUD_Lethers = SPR_addSpriteEx(&spr_begin, 120, 64, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); SPR_setDepth(HUD_Lethers, 1 ); }
	 if(gFrames==295){ SPR_setAnimAndFrame(HUD_Lethers, 0, 1); }
	 if(gFrames==297){ SPR_setAnimAndFrame(HUD_Lethers, 0, 2); }
	 if(gFrames==299){ SPR_setAnimAndFrame(HUD_Lethers, 0, 3); }
	 if(gFrames==301){ SPR_setAnimAndFrame(HUD_Lethers, 0, 4); }
	 if(gFrames==351){ SPR_releaseSprite(HUD_Lethers); }
	 
	  if(gFrames== 302 && gRound==1)
	 { 
		//comeca a tocar a musica
		XGM_startPlay(music_stage1); XGM_isPlaying(); //FIX
	 }
	 
	 if(gFrames==352)
	 {
		SPR_setVisibility(ClockL, VISIBLE); //reativado apos a intro...
		SPR_setVisibility(ClockR, VISIBLE);
		
		//BG_A
		VDP_loadTileSet(gfx_bga.tileset,gInd_tileset,DMA); //Load the tileset
		VDP_setTileMapEx(BG_A,gfx_bga.tilemap,TILE_ATTR_FULL(PAL1,1,FALSE,FALSE,gInd_tileset),0,0,0,0,40,28,DMA_QUEUE);
		PAL_setPalette(PAL1, gfx_bga.palette->data, CPU);
		gInd_tileset += gfx_bga.tileset->numTile;
		
		//Barras de Energia
		if(gRound==1)
		{
			GE[3].sprite = SPR_addSpriteExSafe(&spr_bar_energy,  16, 12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			GE[4].sprite = SPR_addSpriteExSafe(&spr_bar_energy, 176, 12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			SPR_setVRAMTileIndex(GE[3].sprite,1648); //define uma posicao especifica para o GFX na VRAM
			SPR_setVRAMTileIndex(GE[4].sprite,1664); //define uma posicao especifica para o GFX na VRAM
			
			//Retratos
			SPR_setVisibility(GE[16].sprite, VISIBLE); 
			SPR_setVisibility(GE[17].sprite, VISIBLE); 
		}
		
		
		GE[5].sprite = SPR_addSpriteExSafe(&spr_bar_energy_sub,   0, 12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		GE[6].sprite = SPR_addSpriteExSafe(&spr_bar_energy_sub, 312, 12, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		SPR_setVRAMTileIndex(GE[5].sprite,1681); //define uma posicao especifica para o GFX na VRAM
		SPR_setVRAMTileIndex(GE[6].sprite,1682); //define uma posicao especifica para o GFX na VRAM
		
		GE[7].sprite = SPR_addSpriteExSafe(&spr_bar_sp,  48, 208, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		GE[8].sprite = SPR_addSpriteExSafe(&spr_bar_sp, 208, 208, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		SPR_setVRAMTileIndex(GE[7].sprite,1683); //define uma posicao especifica para o GFX na VRAM
		SPR_setVRAMTileIndex(GE[8].sprite,1683+8); //define uma posicao especifica para o GFX na VRAM
		
		GE[9].sprite  = SPR_addSpriteExSafe(&spr_pow,  22, 192, TILE_ATTR(PAL1, TRUE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		GE[10].sprite = SPR_addSpriteExSafe(&spr_pow, 266, 192, TILE_ATTR(PAL1, TRUE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		SPR_setVRAMTileIndex(GE[9].sprite ,1441); //define uma posicao especifica para o GFX na VRAM 
		SPR_setVRAMTileIndex(GE[10].sprite,1441); //define uma posicao especifica para o GFX na VRAM *1699
		
		SPR_setHFlip(GE[3].sprite, TRUE);
		SPR_setHFlip(GE[5].sprite, TRUE);
		SPR_setHFlip(GE[8].sprite, TRUE);
		
		//POW icons invisiveis (barra de SP vazia)
		SPR_setVisibility(GE[ 9].sprite, HIDDEN); 
		SPR_setVisibility(GE[10].sprite, HIDDEN);
		
		//DEPTH
		SPR_setDepth(GE[3].sprite, 1 ); // Barra de energia P1
		SPR_setDepth(GE[4].sprite, 1 ); // Barra de energia P2
		SPR_setDepth(GE[5].sprite, 1 ); // Barra de energia (complemento) P1
		SPR_setDepth(GE[6].sprite, 1 ); // Barra de energia (complemento) P2
		SPR_setDepth(GE[9].sprite, 1 ); // POW icon P1
		SPR_setDepth(GE[10].sprite,1 ); // POW icon P2
		SPR_setDepth(GE[7].sprite, 1 ); // Barra de energia especial P1
		SPR_setDepth(GE[8].sprite, 1 ); // Barra de energia especial P2
	 }
	 
	 if(gFrames==355){ gPodeMover=1; }
	/*samsho2*/ //-Intro Rotine -END-//
}

void FUNCAO_ROUND_RESTART()
{
	if(P[1].wins==2 || P[2].wins==2)
	{
		//A LUTA ACABOU!
		
		//Atualiza Winner e Lose ID's usadas na tela de WINNER!
		if(P[1].wins==2){ gWinnerID=P[1].id; gLoseID=P[2].id; }
		if(P[2].wins==2){ gWinnerID=P[2].id; gLoseID=P[1].id; }

		gRoom=9; gDescompressionExit=11;
		gFrames=1;
		CLEAR_VDP();
	}else{
		//A LUTA NAO ACABOU, + 1 ROUND!
		gPodeMover=0;
		gRound++;
		gFrames = 64; //reinicia o round apos os dizeres com o nome do cenario /*samsho2*/
		gInd_tileset -= gfx_bga.tileset->numTile;
		gScrollValue=-(gBG_Width-320)/2;
		gClockTimer = 60;
		gClockLTimer = 9;
		gClockRTimer = 9;
		SPR_releaseSprite(ClockL);
		SPR_releaseSprite(ClockR);
		ClockL = SPR_addSpriteEx(&spr_n9, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		ClockR = SPR_addSpriteEx(&spr_n9, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); 
		SPR_setVRAMTileIndex(ClockL,1703); //define uma posicao especifica para o GFX na VRAM
		SPR_setVRAMTileIndex(ClockR,1707); //define uma posicao especifica para o GFX na VRAM
		P[1].energia = 128; P[1].energiaBase = 128;
		P[2].energia = 128; P[2].energiaBase = 128;
		P[1].x = (320/4);
		P[2].x = (320/4)*3;
		P[1].direcao = 1;
		P[2].direcao = -1;
		PLAYER_STATE(1, STATE_PARADO);
		PLAYER_STATE(2, STATE_PARADO);
		
		//barras de energia cheias ao reiniciar o round
			//SPR_releaseSprite(GE[3].sprite); GE[3].sprite = NULL;
			//SPR_releaseSprite(GE[4].sprite); GE[4].sprite = NULL;
		SPR_setAnimAndFrame(GE[3].sprite, 0, 0);
		SPR_setAnimAndFrame(GE[4].sprite, 0, 0);
		
		SPR_releaseSprite(GE[5].sprite); GE[5].sprite = NULL;
		SPR_releaseSprite(GE[6].sprite); GE[6].sprite = NULL;
		SPR_releaseSprite(GE[7].sprite); GE[7].sprite = NULL;
		SPR_releaseSprite(GE[8].sprite); GE[8].sprite = NULL;
		SPR_releaseSprite(GE[9].sprite); GE[9].sprite = NULL;
		SPR_releaseSprite(GE[10].sprite); GE[10].sprite = NULL;
		
		FUNCAO_ROUND_INIT();
	}
	
}

