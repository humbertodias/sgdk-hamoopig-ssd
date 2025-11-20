#include "gillius.h"
#include "sprite.h"
#include "gfx.h"

void gillius_state_handler(u8 Player, u16 State)
{
	{
		if(State==STATE_PARADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 13*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-12;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 10;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 8;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 9;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_100, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 15*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+20;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_101, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_MEDIO_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 22*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)+30;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 5;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_102, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FORTE_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 24*8;
			P[Player].h = 18*8;
			P[Player].axisX = (P[Player].w/2)+33;
			P[Player].axisY = P[Player].h-19;
			P[Player].dataAnim[1]  = 6;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 4;
			P[Player].dataAnim[10] = 6;
			P[Player].dataAnim[11] = 10;
			P[Player].animFrameTotal = 11;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_103, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FRACO_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 19*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2)+16;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_104, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_MEDIO_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 17*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)+16;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 12;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 4;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_105, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FORTE_LONGE){
			P[Player].y = gAlturaPiso;
			P[Player].w = 21*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)+16;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 12;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 4;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_106, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_INICIO){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_107, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_DEFENDENDO){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_FINAL){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_109, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_APLICADA){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 15*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+20;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 8;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_151, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_MEDIO_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 21*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 12;
			P[Player].dataAnim[4]  = 8;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_152, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FORTE_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 19*8;
			P[Player].h = 19*8;
			P[Player].axisX = (P[Player].w/2)+20;
			P[Player].axisY = P[Player].h-19;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 2;
			P[Player].dataAnim[10] = 2;
			P[Player].dataAnim[11] = 2;
			P[Player].dataAnim[12] = 2;
			P[Player].dataAnim[13] = 2;
			P[Player].dataAnim[14] = 2;
			P[Player].dataAnim[15] = 2;
			P[Player].animFrameTotal = 15;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_153, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FRACO_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 17*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)+16;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_154, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_MEDIO_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 17*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)+16;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_155, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FORTE_PERTO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 16*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)-8;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 10;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 6;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_156, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 11*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+4;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 250;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_200, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 20*8;
			P[Player].h = 9*8;
			P[Player].axisX = (P[Player].w/2)+40;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 1;
			P[Player].dataAnim[3]  = 8;
			P[Player].dataAnim[4]  = 2;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_201, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_MEDIO_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 20*8;
			P[Player].h = 10*8;
			P[Player].axisX = (P[Player].w/2)+40;
			P[Player].axisY = P[Player].h-7;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 12;
			P[Player].dataAnim[5]  = 2;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_202, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FORTE_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 23*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)+32;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 2;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_203, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FRACO_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 16*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)+24;
			P[Player].axisY = P[Player].h-2;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 2;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_204, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_MEDIO_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 19*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)+32;
			P[Player].axisY = P[Player].h-6;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 12;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 5;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_205, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FORTE_ABAIXADO){
			P[Player].y = gAlturaPiso;
			P[Player].w = 18*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+30;
			P[Player].axisY = P[Player].h-10;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 12;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 4;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_206, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_INICIO){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_207, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_DEFENDENDO){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_FINAL){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_209, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_APLICADA){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_PULO_NEUTRO){
			P[Player].w = 16*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)-20;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 6;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 99;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_300, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_AEREO_NEUTRO || State==STATE_SOCO_FRACO_AEREO_TRAS || State==STATE_SOCO_FRACO_AEREO_FRENTE){
			P[Player].w = 20*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)+1;
			P[Player].axisY = P[Player].h-1;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 12;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 99;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_301, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_MEDIO_AEREO_NEUTRO || State==STATE_SOCO_MEDIO_AEREO_TRAS || State==STATE_SOCO_MEDIO_AEREO_FRENTE){
			P[Player].w = 20*8;
			P[Player].h = 20*8;
			P[Player].axisX = (P[Player].w/2)+1;
			P[Player].axisY = P[Player].h-1;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 13;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 99;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_302, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FORTE_AEREO_NEUTRO || State==STATE_SOCO_FORTE_AEREO_TRAS || State==STATE_SOCO_FORTE_AEREO_FRENTE){
			P[Player].w = 23*8;
			P[Player].h = 20*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-1;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 99;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_303, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_FRACO_AEREO_NEUTRO || State==STATE_CHUTE_FRACO_AEREO_TRAS || State==STATE_CHUTE_FRACO_AEREO_FRENTE){
			P[Player].w = 17*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h+20;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 20;
			P[Player].dataAnim[3]  = 99;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_304, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CHUTE_MEDIO_AEREO_NEUTRO || State==STATE_CHUTE_MEDIO_AEREO_TRAS || State==STATE_CHUTE_MEDIO_AEREO_FRENTE || State==STATE_CHUTE_FORTE_AEREO_NEUTRO || State==STATE_CHUTE_FORTE_AEREO_TRAS || State==STATE_CHUTE_FORTE_AEREO_FRENTE){
			P[Player].w = 16*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h+20;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 20;
			P[Player].dataAnim[4]  = 99;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_306, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_PULO_TRAS){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-20;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 99;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_310, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_PULO_FRENTE){
			P[Player].w = 10*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)-20;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 99;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_320, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ANDANDO_TRAS){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].dataAnim[7]  = 4;
			P[Player].dataAnim[8]  = 4;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_410, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ANDANDO_FRENTE){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].dataAnim[7]  = 4;
			P[Player].dataAnim[8]  = 4;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_420, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ESQUIVA_BAIXO){
			P[Player].w = 16*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-16-8;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 90;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 9;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_470, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ROLAMENTO_TRAS){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_471, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ROLAMENTO_FRENTE){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_472, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CORRENDO){
			P[Player].w = 13*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_481, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO1_FRACO){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_501, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO1_MEDIO){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_502, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO1_FORTE){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 25;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_503, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO2_FRACO){
			P[Player].w = 14*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_506, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO2_MEDIO){
			P[Player].w = 14*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_507, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO2_FORTE){
			P[Player].w = 14*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 25;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_508, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO3_FRACO){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_511, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO3_MEDIO){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_512, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO3_FORTE){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 25;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_513, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_USER_HIT){
			P[Player].y = gAlturaPiso-1;
			P[Player].gravidadeY = gravidadePadrao; 
			P[Player].impulsoY = -22;
			P[Player].w = 10*8;
			P[Player].h = 15*8;
			P[Player].axisX = P[Player].w/2;
			P[Player].axisY = P[Player].h-1;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 250;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_516, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CAINDO){
			P[Player].gravidadeY = gravidadePadrao; 
			P[Player].impulsoY = impulsoPadrao;
			P[Player].y-=4*8; //Compensa o deslocamento do eixo Y (.axisY)
			P[Player].w = 18*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4*8;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 9;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 9;
			P[Player].dataAnim[5]  = 9;
			P[Player].dataAnim[6]  = 99;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_550, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_QUICANDO_CHAO){
			P[Player].w = 17*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-3*8;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 99;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_551, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_LEVANTANDO){
			P[Player].w = 20*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 9;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 9;
			P[Player].dataAnim[5]  = 9;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_552, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_CAIDO_MORTO){
			P[Player].w = 20*8;
			P[Player].h = 6*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 60;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_570, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ABAIXANDO || State==STATE_LEVANTANDO_TRANSICAO || State==STATE_INICIO_PULO_TRAS || State==STATE_INICIO_PULO_NEUTRO|| State==STATE_INICIO_PULO_FRENTE || State==STATE_FINAL_PULO || State==STATE_DISPONIVEL_473 || State==STATE_DISPONIVEL_475 || State==STATE_CORRIDA_INICIO || State==STATE_CORRIDA_FINAL){
			P[Player].y = gAlturaPiso;
			P[Player].w = 10*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_601, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_VIRANDO_PE){
			P[Player].w = 13*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_607, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_VIRANDO_ABAIXADO){
			P[Player].w = 10*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_608, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_INTRO){
			P[Player].w = 11*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 60;
			P[Player].dataAnim[2]  = 10;
			P[Player].dataAnim[3]  = 10;
			P[Player].dataAnim[4]  = 10;
			P[Player].dataAnim[5]  = 10;
			P[Player].dataAnim[6]  = 10;
			P[Player].dataAnim[7]  = 10;
			P[Player].dataAnim[8]  = 10;
			P[Player].dataAnim[9]  = 10;
			P[Player].dataAnim[10] = 10;
			P[Player].dataAnim[11] = 10;
			P[Player].dataAnim[12] = 10;
			P[Player].dataAnim[13] = 10;
			P[Player].dataAnim[14] = 10;
			P[Player].dataAnim[15] = 5;
			P[Player].animFrameTotal = 15;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_610, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_WIN1){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 60;
			P[Player].dataAnim[2]  = 10;
			P[Player].dataAnim[3]  = 10;
			P[Player].dataAnim[4]  = 250;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_611, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_WIN2){
			P[Player].w = 12*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 60;
			P[Player].dataAnim[2]  = 10;
			P[Player].dataAnim[3]  = 10;
			P[Player].dataAnim[4]  = 10;
			P[Player].dataAnim[5]  = 10;
			P[Player].dataAnim[6]  = 10;
			P[Player].dataAnim[7]  = 200;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_612, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_WIN3){
			P[Player].w = 14*8;
			P[Player].h = 17*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 20;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 60;
			P[Player].dataAnim[8]  = 6;
			P[Player].dataAnim[9]  = 6;
			P[Player].dataAnim[10] = 6;
			P[Player].dataAnim[11] = 12;
			P[Player].dataAnim[12] = 200;
			P[Player].animFrameTotal = 12;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_613, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_PERDENDO_TIME_OVER){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 60;
			P[Player].dataAnim[2]  = 250;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_615, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_RAGE_EXPLOSION){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 10;
			P[Player].dataAnim[2]  = 10;
			P[Player].dataAnim[3]  = 10;
			P[Player].dataAnim[4]  = 60;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_611, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ESPECIAL_700){
			P[Player].w = 15*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-7;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 13;
			P[Player].dataAnim[6]  = 12;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_700, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ESPECIAL_710){
			P[Player].gravidadeY = gravidadePadrao; 
			//if(P[i].attackPower==1){ P[Player].impulsoY = impulsoPadrao; }
			//if(P[i].attackPower==2){ P[Player].impulsoY = impulsoPadrao-2; }
			//if(P[i].attackPower==3){ P[Player].impulsoY = impulsoPadrao-3; }
			P[Player].impulsoY = impulsoPadrao-3; //optei por manter sempre o mesmo impulso vertical, aqui
			P[i].cicloInteracoesGravidade=2;
			P[Player].w = 16*8;
			P[Player].h = 16*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 3;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 1;
			P[Player].dataAnim[9]  = 1;
			P[Player].dataAnim[10] = 1;
			P[Player].dataAnim[11] = 1;
			P[Player].dataAnim[12] = 1;
			P[Player].dataAnim[13] = 1;
			P[Player].dataAnim[14] = 1;
			P[Player].dataAnim[15] = 1;
			P[Player].dataAnim[16] = 1;
			P[Player].dataAnim[17] = 1;
			P[Player].dataAnim[18] = 99;
			P[Player].animFrameTotal = 18;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_710, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ESPECIAL_711){
			P[Player].w = 11*8;
			P[Player].h = 10*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 12;
			P[Player].dataAnim[2]  = 6;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_711, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ESPECIAL_720){
			P[Player].gravidadeY = gravidadePadrao; 
			//if(P[i].attackPower==1){ P[Player].impulsoY = impulsoPadrao; }
			//if(P[i].attackPower==2){ P[Player].impulsoY = impulsoPadrao-2; }
			//if(P[i].attackPower==3){ P[Player].impulsoY = impulsoPadrao-3; }
			P[Player].impulsoY = -6; //optei por manter sempre o mesmo impulso vertical, aqui
			P[i].cicloInteracoesGravidade=6;
			P[Player].w = 16*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 8;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 3;
			P[Player].dataAnim[5]  = 3;
			P[Player].dataAnim[6]  = 3;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 8;
			P[Player].dataAnim[9]  = 8;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_720, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		
	}
	
	if(P[Player].direcao==1){SPR_setHFlip(P[Player].sprite, FALSE);}else{SPR_setHFlip(P[Player].sprite, TRUE);}
	SPR_setAnimAndFrame(P[Player].sprite, 0, P[Player].animFrame-1);
	P[Player].frameTimeTotal  = P[Player].dataAnim[1];
}
