#include "gillius.h"
#include "sprite.h"
#include "gfx.h"

void gillius_state_handler(u8 Player, u16 State)
{
	{
		if(State==100){
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
		if(State==101){
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
		if(State==102){
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
		if(State==103){
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
		if(State==104){
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
		if(State==105){
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
		if(State==106){
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
		if(State==107){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_107, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==108){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==109){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_109, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==110){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==151){
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
		if(State==152){
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
		if(State==153){
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
		if(State==154){
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
		if(State==155){
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
		if(State==156){
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
		if(State==200){
			P[Player].y = gAlturaPiso;
			P[Player].w = 11*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)+4;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 250;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_200, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==201){
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
		if(State==202){
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
		if(State==203){
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
		if(State==204){
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
		if(State==205){
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
		if(State==206){
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
		if(State==207){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_207, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==208){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==209){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_209, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==210){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==300){
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
		if(State==301 || State==311 || State==321){
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
		if(State==302 || State==312 || State==322){
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
		if(State==303 || State==313 || State==323){
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
		if(State==304 || State==314 || State==324){
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
		if(State==305 || State==315 || State==325 || State==306 || State==316 || State==326){
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
		if(State==310){
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
		if(State==320){
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
		if(State==410){
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
		if(State==420){
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
		if(State==470){
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
		if(State==471){
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
		if(State==472){
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
		if(State==481){
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
		if(State==501){
			P[Player].w = 14*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_501, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==502){
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
		if(State==503){
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
		if(State==506){
			P[Player].w = 14*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_506, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==507){
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
		if(State==508){
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
		if(State==511){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_511, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==512){
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
		if(State==513){
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
		if(State==516){
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
		if(State==550){
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
		if(State==551){
			P[Player].w = 17*8;
			P[Player].h = 12*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-3*8;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 99;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_551, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==552){
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
		if(State==570){
			P[Player].w = 20*8;
			P[Player].h = 6*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 60;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_570, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==601 || State==602 || State==603 || State==604|| State==605 || State==606 || State==473 || State==475 || State==480 || State==482){
			P[Player].y = gAlturaPiso;
			P[Player].w = 10*8;
			P[Player].h = 13*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h-4;
			P[Player].dataAnim[1]  = 4;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_601, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==607){
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
		if(State==608){
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
		if(State==610){
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
		if(State==611){
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
		if(State==612){
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
		if(State==613){
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
		if(State==615){
			P[Player].w = 12*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h-9;
			P[Player].dataAnim[1]  = 60;
			P[Player].dataAnim[2]  = 250;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_615, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==618){
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
		if(State==700){
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
		if(State==710){
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
		if(State==711){
			P[Player].w = 11*8;
			P[Player].h = 10*8;
			P[Player].axisX = (P[Player].w/2)+10;
			P[Player].axisY = P[Player].h-8;
			P[Player].dataAnim[1]  = 12;
			P[Player].dataAnim[2]  = 6;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_gillius_711, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==720){
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
