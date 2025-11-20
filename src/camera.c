#include "camera.h"
#include "gfx.h"
#include "game_globals.h"

void FUNCAO_CAMERA_BGANIM()
{
	
	//Animacao do Cenario / Background!
	if(gBG_Choice==1){ 
		u8 BGtimer = 33;
		gBgAnim++;
		if(gBgAnim==BGtimer*1){ VDP_loadTileData(gfx_bgb1B.tileset->tiles + INDEX_MAR*8, INDEX_MAR+1, 468, DMA_QUEUE); }
		if(gBgAnim==BGtimer*2){ VDP_loadTileData(gfx_bgb1C.tileset->tiles + INDEX_MAR*8, INDEX_MAR+1, 468, DMA_QUEUE); }
		if(gBgAnim==BGtimer*3){ VDP_loadTileData(gfx_bgb1D.tileset->tiles + INDEX_MAR*8, INDEX_MAR+1, 468, DMA_QUEUE); }
		if(gBgAnim==BGtimer*4){ VDP_loadTileData(gfx_bgb1A.tileset->tiles + INDEX_MAR*8, INDEX_MAR+1, 468, DMA_QUEUE); }
		if(gBgAnim==BGtimer*4){ gBgAnim = 0; }
	}
	
    s16 pMax = max(P[1].x, P[2].x);
	s16 pMin = min(P[1].x, P[2].x);
	bool walk1= FALSE, walk2 = FALSE;

	// percebe se o player está parado ou andando, tem que checar os outros casos de parado
	if(P[1].state != 100)
	{
		walk1 = TRUE;
	}
	if(P[2].state != 100)
	{
		walk2 = TRUE;
	}

	if((pMax > 250) & (pMin > 40) & (walk1 | walk2) & (gScrollValue > (320-(gBG_Width))))
	{
		if(walk2 == FALSE)
		{
			P[2].x -= P[1].hSpeed;
			P[1].x -= P[1].hSpeed;
			gScrollValue -= P[1].hSpeed;
		}
		else if(walk1 == FALSE)
		{
			P[1].x -= P[2].hSpeed;
			P[2].x -= P[2].hSpeed;
			gScrollValue -= P[2].hSpeed;
		}
		if(gScrollValue == -192)
		{
			if(gBG_Choice==1){ VDP_setTileMapEx(BG_B,gfx_bgb1A.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,0),0,0,64,0,8,28,DMA_QUEUE); }
			if(gBG_Choice==3){ VDP_setTileMapEx(BG_B,gfx_bgb3.tilemap ,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,0),0,0,64,0,8,28,DMA_QUEUE); }
		}
		KLog_S1("scroll negativo: ", gScrollValue);
	}
	if((pMin < 70) & (pMax < 280) & (walk1 | walk2) & (gScrollValue < 0)) 
	{
		if(walk2 == FALSE)
		{
			P[2].x += P[1].hSpeed;
			P[1].x += P[1].hSpeed;
			gScrollValue += P[1].hSpeed;
		}
		else if(walk1 == FALSE)
		{
			P[1].x += P[2].hSpeed;
			P[2].x += P[2].hSpeed;
			gScrollValue += P[2].hSpeed;
		}
		if(gScrollValue == -60)
		{
			if(gBG_Choice==1){ VDP_setTileMapEx(BG_B,gfx_bgb1A.tilemap,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,0),0,0,0,0,8,28,DMA_QUEUE); }
			if(gBG_Choice==3){ VDP_setTileMapEx(BG_B,gfx_bgb3.tilemap ,TILE_ATTR_FULL(PAL0,0,FALSE,FALSE,0),0,0,0,0,8,28,DMA_QUEUE); }
		}
		KLog_S1("scroll positivo: ", gScrollValue);
	}
	VDP_setHorizontalScroll(BG_B, gScrollValue);

}

