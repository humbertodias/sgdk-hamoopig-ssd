#include "haohmaru.h"
#include "sprite.h"
#include "gfx.h"

void haohmaru_state_handler(u8 Player, u16 State)
{
	{
		if(State==100){
			P[Player].y = gAlturaPiso;
			P[Player].w = 10*8;
			P[Player].h = 15*8;
			P[Player].axisX = P[Player].w/2;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 8;
			P[Player].dataAnim[2]  = 7;
			P[Player].dataAnim[3]  = 7;
			P[Player].dataAnim[4]  = 7;
			P[Player].dataAnim[5]  = 7;
			P[Player].dataAnim[6]  = 7;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_100, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==101){
			P[Player].w = 19*8;
			P[Player].h = 19*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-11;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 1;
			P[Player].dataAnim[4]  = 1;
			P[Player].dataAnim[5]  = 1;
			P[Player].dataAnim[6]  = 1;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 3;
			P[Player].dataAnim[9]  = 6;
			P[Player].dataAnim[10] = 5;
			P[Player].dataAnim[11] = 3;
			P[Player].animFrameTotal = 11;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_101, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==102){
			P[Player].w = 22*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+48;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 1;
			P[Player].dataAnim[5]  = 1;
			P[Player].dataAnim[6]  = 14;
			P[Player].dataAnim[7]  = 5;
			P[Player].dataAnim[8]  = 5;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_102, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==103){
			P[Player].w = 26*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+64;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 1;
			P[Player].dataAnim[7]  = 1;
			P[Player].dataAnim[8]  = 1;
			P[Player].dataAnim[9]  = 3;
			P[Player].dataAnim[10] = 3;
			P[Player].dataAnim[11] = 19;
			P[Player].dataAnim[12] = 7;
			P[Player].dataAnim[13] = 7;
			P[Player].animFrameTotal = 13;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_103, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==104){
			P[Player].w = 16*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+26;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 4;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_104, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==105){
			P[Player].w = 16*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+26;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 7;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 6;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_104, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==106){
			P[Player].w = 14*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+38;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 7;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 5;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_106, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==107){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_107, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==108){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==109){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_109, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==110){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==151){
			P[Player].w = 15*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+10;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 4;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_151, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==152){
			P[Player].w = 16*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+24;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 9;
			P[Player].dataAnim[9]  = 6;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_152, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==153){
			P[Player].w = 19*8;
			P[Player].h = 22*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-12;
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
			P[Player].dataAnim[16] = 2;
			P[Player].dataAnim[17] = 2;
			P[Player].dataAnim[18] = 2;
			P[Player].dataAnim[19] = 2;
			P[Player].dataAnim[20] = 2;
			P[Player].dataAnim[21] = 2;
			P[Player].dataAnim[22] = 2;
			P[Player].dataAnim[23] = 2;
			P[Player].dataAnim[24] = 2;
			P[Player].dataAnim[25] = 2;
			P[Player].animFrameTotal = 25;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_153, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==154){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+14;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 4;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_154, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==155){
			P[Player].w = 13*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+14;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 7;
			P[Player].dataAnim[3]  = 3;
			P[Player].dataAnim[4]  = 6;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_154, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==156){
			P[Player].w = 14*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)-6;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 14;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 9;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_156, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==200){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 250;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_200, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==201){
			P[Player].w = 16*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+32;
			P[Player].axisY =  (P[Player].h)-2;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 1;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 5;
			P[Player].dataAnim[7]  = 4;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_201, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}		
		if(State==202){
			P[Player].w = 16*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+32;
			P[Player].axisY =  (P[Player].h)-2;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 3;
			P[Player].dataAnim[6]  = 11;
			P[Player].dataAnim[7]  = 5;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_202, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==203){
			P[Player].w = 17*8;
			P[Player].h = 20*8;
			P[Player].axisX = ((P[Player].w)/2)+37;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 1;
			P[Player].dataAnim[4]  = 1;
			P[Player].dataAnim[5]  = 1;
			P[Player].dataAnim[6]  = 1;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 2;
			P[Player].dataAnim[10] = 2;
			P[Player].dataAnim[11] = 2;
			P[Player].dataAnim[12] = 3;
			P[Player].dataAnim[13] = 5;
			P[Player].dataAnim[14] = 9;
			P[Player].dataAnim[15] = 9;
			P[Player].dataAnim[16] = 7;
			P[Player].dataAnim[17] = 8;
			P[Player].animFrameTotal = 17;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_203, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==204){
			P[Player].w = 14*8;
			P[Player].h = 11*8;
			P[Player].axisX = ((P[Player].w)/2)+26;
			P[Player].axisY =  (P[Player].h)-2;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_204, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==205){
			P[Player].w = 14*8;
			P[Player].h = 11*8;
			P[Player].axisX = ((P[Player].w)/2)+26;
			P[Player].axisY =  (P[Player].h)-2;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 7;
			P[Player].dataAnim[3]  = 6;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_204, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==206){
			P[Player].w = 19*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+20;
			P[Player].axisY =  (P[Player].h)-4;
			P[Player].dataAnim[1]  = 8;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 21;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_206, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==207){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_207, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==208){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==209){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_209, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==210){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==300){
			P[Player].w = 10*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+13;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 11;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 8;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 99;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_300, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==301 || State==311 || State==321){
			P[Player].w = 20*8;
			P[Player].h = 13*8;
			P[Player].axisX = ((P[Player].w)/2)+8;
			P[Player].axisY =  (P[Player].h)+8;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 12;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 99;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_301, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==302 || State==312 || State==322){
			P[Player].w = 20*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+8;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 3;
			P[Player].dataAnim[6]  = 3;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 3;
			P[Player].dataAnim[9]  = 99;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_302, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==303 || State==313 || State==323){
			P[Player].w = 16*8;
			P[Player].h = 15*8;
			P[Player].axisX = ((P[Player].w)/2)+28;
			P[Player].axisY =  (P[Player].h)-8;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 5;
			P[Player].dataAnim[8]  = 99;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_303, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==304 || State==314 || State==324){
			P[Player].w = 13*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+28;
			P[Player].axisY =  (P[Player].h)+26;
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 19;
			P[Player].dataAnim[3]  = 99;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_304, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==305 || State==315 || State==325){
			P[Player].w = 13*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+28;
			P[Player].axisY =  (P[Player].h)+26;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 99;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_304, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==306 || State==316 || State==326){
			P[Player].w = 17*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+28;
			P[Player].axisY =  (P[Player].h)+20;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 12;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 99;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_306, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==310){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+4;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 18-1;
			P[Player].dataAnim[2]  = 3;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].dataAnim[7]  = 4;
			P[Player].dataAnim[8]  = 3;
			P[Player].dataAnim[9]  = 99;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_310, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==320){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+13;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 18-1;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 99;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_320, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==410){
			P[Player].w = 11*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 5;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 5;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 5;
			P[Player].dataAnim[6]  = 5;
			P[Player].dataAnim[7]  = 5;
			P[Player].dataAnim[8]  = 5;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_410, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==420){
			P[Player].w = 10*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 5;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 5;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 5;
			P[Player].dataAnim[6]  = 5;
			P[Player].dataAnim[7]  = 5;
			P[Player].dataAnim[8]  = 5;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_420, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==470){
			P[Player].w = 16*8;
			P[Player].h = 15*8;
			P[Player].axisX = ((P[Player].w)/2)+0;
			P[Player].axisY =  (P[Player].h)-4;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 90;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 9;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_470, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==471){
			P[Player].w = 18*8;
			P[Player].h = 15*8;
			P[Player].axisX = ((P[Player].w)/2)+13;
			P[Player].axisY =  (P[Player].h)-4;
			P[Player].dataAnim[1]  = 7;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 5;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 7;
			P[Player].dataAnim[6]  = 3;
			P[Player].dataAnim[7]  = 2;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_471, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==472){
			P[Player].w = 17*8;
			P[Player].h = 17*8;
			P[Player].axisX = ((P[Player].w)/2)-28;
			P[Player].axisY =  (P[Player].h)-16;
			P[Player].dataAnim[1]  = 7;
			P[Player].dataAnim[2]  = 5;
			P[Player].dataAnim[3]  = 5;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 7;
			P[Player].dataAnim[6]  = 3;
			P[Player].dataAnim[7]  = 2;
			P[Player].animFrameTotal = 7;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_472, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==501){
			P[Player].w = 10*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)-1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_501, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==502){
			P[Player].w = 11*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)+8;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_502, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==503){
			P[Player].w = 11*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)-2;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 25;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_503, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==506){
			P[Player].w = 11*8;
			P[Player].h = 11*8;
			P[Player].axisX = ((P[Player].w)/2)+8;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;//6
			P[Player].dataAnim[2]  = 6;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_506, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==507){
			P[Player].w = 12*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)-8;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;//15
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 13;
			P[Player].dataAnim[4]  = 3;
			P[Player].dataAnim[5]  = 3;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_507, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==508){
			P[Player].w = 16*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)-12;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;//33
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 8;
			P[Player].dataAnim[5]  = 9;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 3;
			P[Player].dataAnim[9]  = 3;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_508, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==511){
			P[Player].w = 9*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)-1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_511, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==512){
			P[Player].w = 9*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)-2;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_512, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==513){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)-2;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 25;
			P[Player].dataAnim[4]  = 5;
			P[Player].dataAnim[5]  = 4;
			P[Player].animFrameTotal = 5;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_513, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==516){
			P[Player].y = gAlturaPiso-1;
			P[Player].gravidadeY = gravidadePadrao; 
			P[Player].impulsoY = -22;
			P[Player].w = 10*8;
			P[Player].h = 15*8;
			P[Player].axisX = P[Player].w/2;
			P[Player].axisY = P[Player].h-32;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 2;
			P[Player].dataAnim[7]  = 2;
			P[Player].dataAnim[8]  = 250;
			P[Player].animFrameTotal = 8;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_516, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==550){
			P[Player].gravidadeY = gravidadePadrao; 
			P[Player].impulsoY = impulsoPadrao;
			P[Player].y-=4*8; //Compensa o deslocamento do eixo Y (.axisY)
			P[Player].w = 14*8;
			P[Player].h = 11*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-4*8;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 9;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 99;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_550, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==551){
			P[Player].w = 15*8;
			P[Player].h =  7*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-3*8;
			P[Player].dataAnim[1]  = 99;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_551, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==552){
			P[Player].w = 16*8;
			P[Player].h = 17*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-2*8;
			P[Player].dataAnim[1]  = 9;
			P[Player].dataAnim[2]  = 9;
			P[Player].dataAnim[3]  = 9;
			P[Player].dataAnim[4]  = 9;
			P[Player].dataAnim[5]  = 9;
			P[Player].dataAnim[6]  = 9;
			P[Player].animFrameTotal = 6;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_552, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==570){
			P[Player].w = 15*8;
			P[Player].h =  6*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-2*8;
			P[Player].dataAnim[1]  = 60;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_570, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==601){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 1;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_601, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==602){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 1;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_602, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==603 || State==604 || State==605){
			P[Player].w = 10*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 2;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_604, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==606){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-14;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 3;
			P[Player].animFrameTotal = 3;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_606, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==607){
			P[Player].w = 10*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_607, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==608){
			P[Player].w = 9*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_608, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==610){
			P[Player].w = 18*8;
			P[Player].h = 18*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-11;
			P[Player].dataAnim[1]  = 75;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 5;
			P[Player].dataAnim[6]  = 7;
			P[Player].dataAnim[7]  = 11;
			P[Player].dataAnim[8]  = 6;
			P[Player].dataAnim[9]  = 12;
			P[Player].dataAnim[10] = 6;
			P[Player].dataAnim[11] = 2;
			P[Player].dataAnim[12] = 2;
			P[Player].dataAnim[13] = 2;
			P[Player].dataAnim[14] = 2;
			P[Player].dataAnim[15] = 4;
			P[Player].dataAnim[16] = 4;
			P[Player].dataAnim[17] = 4;
			P[Player].dataAnim[18] = 12;
			P[Player].dataAnim[19] = 2;
			P[Player].dataAnim[20] = 6;
			P[Player].dataAnim[21] = 2;
			P[Player].dataAnim[22] = 2;
			P[Player].dataAnim[23] = 2;
			P[Player].dataAnim[24] = 2;
			P[Player].dataAnim[25] = 2;
			P[Player].dataAnim[26] = 2;
			P[Player].dataAnim[27] = 2;
			P[Player].dataAnim[28] = 2;
			P[Player].dataAnim[29] = 161;
			P[Player].animFrameTotal = 29;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_610, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==611){
			P[Player].w = 17*8;
			P[Player].h = 26*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 120;
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
			P[Player].dataAnim[16] = 2;
			P[Player].dataAnim[17] = 2;
			P[Player].dataAnim[18] = 2;
			P[Player].dataAnim[19] = 2;
			P[Player].dataAnim[20] = 2;
			P[Player].dataAnim[21] = 2;
			P[Player].dataAnim[22] = 2;
			P[Player].dataAnim[23] = 2;
			P[Player].dataAnim[24] = 2;
			P[Player].dataAnim[25] = 2;
			P[Player].dataAnim[26] = 2;
			P[Player].dataAnim[27] = 2;
			P[Player].dataAnim[28] = 2;
			P[Player].dataAnim[29] = 2;
			P[Player].dataAnim[30] = 2;
			P[Player].dataAnim[31] = 2;
			P[Player].dataAnim[32] = 2;
			P[Player].dataAnim[33] = 2;
			P[Player].dataAnim[34] = 250;
			P[Player].animFrameTotal = 34;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_611, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==612){
			P[Player].w = 12*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 120;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 6;
			P[Player].dataAnim[8]  = 6;
			P[Player].dataAnim[9]  = 250;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_612, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==613){
			P[Player].w = 16*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 120;
			P[Player].dataAnim[2]  = 6;
			P[Player].dataAnim[3]  = 6;
			P[Player].dataAnim[4]  = 6;
			P[Player].dataAnim[5]  = 6;
			P[Player].dataAnim[6]  = 6;
			P[Player].dataAnim[7]  = 6;
			P[Player].dataAnim[8]  = 6;
			P[Player].dataAnim[9]  = 250;
			P[Player].animFrameTotal = 9;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_613, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==615){
			P[Player].w = 8*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 32;
			P[Player].dataAnim[2]  = 8;
			P[Player].dataAnim[3]  = 10;
			P[Player].dataAnim[4]  = 250;
			P[Player].animFrameTotal = 4;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_615, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==618){
			P[Player].w = 17*8;
			P[Player].h = 17*8;
			P[Player].axisX = ((P[Player].w)/2)-30;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 8;
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
			P[Player].dataAnim[12] = 60;
			P[Player].animFrameTotal = 12;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_618, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==700){
			if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
			if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
			P[Player].w = 19*8;
			P[Player].h = 20*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 1;
			P[Player].dataAnim[2]  = 1;
			P[Player].dataAnim[3]  = 1;
			P[Player].dataAnim[4]  = 1;
			P[Player].dataAnim[5]  = 1;
			P[Player].dataAnim[6]  = 1;
			P[Player].dataAnim[7]  = 1;
			P[Player].dataAnim[8]  = 1;
			P[Player].dataAnim[9]  = 1;
			P[Player].dataAnim[10] = 1;
			P[Player].dataAnim[11] = 1;
			P[Player].dataAnim[12] = 1;
			P[Player].dataAnim[13] = 1;
			P[Player].dataAnim[14] = 1;
			P[Player].dataAnim[15] = 1;
			P[Player].dataAnim[16] = 14;
			P[Player].dataAnim[17] = 3;
			P[Player].dataAnim[18] = 3;
			P[Player].dataAnim[19] = 3;
			P[Player].dataAnim[20] = 3;
			P[Player].dataAnim[21] = 3;
			P[Player].dataAnim[22] = 4;
			P[Player].dataAnim[23] = 99;
			P[Player].animFrameTotal = 23;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_700, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==710){
			if(Spark1_countDown>0){ SPR_releaseSprite(Spark[1]); }
			if(Spark2_countDown>0){ SPR_releaseSprite(Spark[2]); }
			P[Player].w = 17*8;
			P[Player].h = 20*8;
			P[Player].axisX = ((P[Player].w)/2)+28;
			P[Player].axisY =  (P[Player].h)-1;
			P[Player].dataAnim[1]  = 3;
			P[Player].dataAnim[2]  = 14;
			P[Player].dataAnim[3]  = 5;
			P[Player].dataAnim[4]  = 3;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 5;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 2;
			P[Player].dataAnim[9]  = 2;
			P[Player].dataAnim[10] = 3;
			P[Player].dataAnim[11] = 4;
			P[Player].dataAnim[12] = 4;
			P[Player].dataAnim[13] = 8;
			P[Player].dataAnim[14] = 8;
			P[Player].dataAnim[15] = 8;
			P[Player].dataAnim[16] = 8;
			P[Player].dataAnim[17] = 10;
			P[Player].dataAnim[18] = 10;
			P[Player].dataAnim[19] = 10;
			P[Player].animFrameTotal = 19;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_710, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==720){
			P[Player].gravidadeY = gravidadePadrao; 
			if(P[i].attackPower==1){ P[Player].impulsoY = impulsoPadrao; }
			if(P[i].attackPower==2){ P[Player].impulsoY = impulsoPadrao-2; }
			if(P[i].attackPower==3){ P[Player].impulsoY = impulsoPadrao-3; }
			P[Player].y -= 36; //Compensa o deslocamento do eixo Y (.axisY)
			P[Player].w = 18*8;
			P[Player].h = 17*8;
			P[Player].axisX = ((P[Player].w)/2)+24;
			P[Player].axisY =  (P[Player].h)-36;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].dataAnim[3]  = 4;
			P[Player].dataAnim[4]  = 4;
			P[Player].dataAnim[5]  = 4;
			P[Player].dataAnim[6]  = 4;
			P[Player].dataAnim[7]  = 4;
			P[Player].dataAnim[8]  = 4;
			P[Player].dataAnim[9]  = 4;
			P[Player].dataAnim[10] = 250;
			P[Player].dataAnim[11] = 4;
			P[Player].dataAnim[12] = 4;
			P[Player].dataAnim[13] = 4;
			P[Player].dataAnim[14] = 4;
			P[Player].dataAnim[15] = 4;
			P[Player].dataAnim[16] = 4;
			P[Player].dataAnim[17] = 4;
			P[Player].dataAnim[18] = 4;
			P[Player].animFrameTotal = 18;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_720, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==730){
			P[Player].w = 20*8;
			P[Player].h = 14*8;
			P[Player].axisX = ((P[Player].w)/2)+30;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].dataAnim[3]  = 2;
			P[Player].dataAnim[4]  = 2;
			P[Player].dataAnim[5]  = 2;
			P[Player].dataAnim[6]  = 5;
			P[Player].dataAnim[7]  = 3;
			P[Player].dataAnim[8]  = 3;
			P[Player].dataAnim[9]  = 3;
			P[Player].dataAnim[10] = 3;
			P[Player].dataAnim[11] = 3;
			P[Player].dataAnim[12] = 3;
			P[Player].dataAnim[13] = 3;
			P[Player].dataAnim[14] = 4;
			P[Player].dataAnim[15] = 4;
			P[Player].animFrameTotal = 15;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_730, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
}

}
