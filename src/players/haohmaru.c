#include "haohmaru.h"
#include "sprite.h"
#include "gfx.h"

void haohmaru_state_handler(u8 Player, u16 State)
{
	{
		if(State==STATE_PARADO){
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
		if(State==STATE_SOCO_FRACO_LONGE){
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
		if(State==STATE_SOCO_MEDIO_LONGE){
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
		if(State==STATE_SOCO_FORTE_LONGE){
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
		if(State==STATE_CHUTE_FRACO_LONGE){
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
		if(State==STATE_CHUTE_MEDIO_LONGE){
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
		if(State==STATE_CHUTE_FORTE_LONGE){
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
		if(State==STATE_DEFESA_PE_INICIO){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_107, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_DEFENDENDO){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_FINAL){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_109, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_PE_APLICADA){
			P[Player].w = 12*8;
			P[Player].h = 16*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_108, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_PERTO){
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
		if(State==STATE_SOCO_MEDIO_PERTO){
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
		if(State==STATE_SOCO_FORTE_PERTO){
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
		if(State==STATE_CHUTE_FRACO_PERTO){
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
		if(State==STATE_CHUTE_MEDIO_PERTO){
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
		if(State==STATE_CHUTE_FORTE_PERTO){
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
		if(State==STATE_ABAIXADO){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 250;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_200, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_SOCO_FRACO_ABAIXADO){
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
		if(State==STATE_SOCO_MEDIO_ABAIXADO){
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
		if(State==STATE_SOCO_FORTE_ABAIXADO){
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
		if(State==STATE_CHUTE_FRACO_ABAIXADO){
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
		if(State==STATE_CHUTE_MEDIO_ABAIXADO){
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
		if(State==STATE_CHUTE_FORTE_ABAIXADO){
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
		if(State==STATE_DEFESA_ABAIXADO_INICIO){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_207, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_DEFENDENDO){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_FINAL){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_209, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_DEFESA_ABAIXADO_APLICADA){
			P[Player].w = 10*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)+1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_208, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_PULO_NEUTRO){
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
		if(State==STATE_SOCO_FRACO_AEREO_NEUTRO || State==STATE_SOCO_FRACO_AEREO_TRAS || State==STATE_SOCO_FRACO_AEREO_FRENTE){
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
		if(State==STATE_SOCO_MEDIO_AEREO_NEUTRO || State==STATE_SOCO_MEDIO_AEREO_TRAS || State==STATE_SOCO_MEDIO_AEREO_FRENTE){
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
		if(State==STATE_SOCO_FORTE_AEREO_NEUTRO || State==STATE_SOCO_FORTE_AEREO_TRAS || State==STATE_SOCO_FORTE_AEREO_FRENTE){
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
		if(State==STATE_CHUTE_FRACO_AEREO_NEUTRO || State==STATE_CHUTE_FRACO_AEREO_TRAS || State==STATE_CHUTE_FRACO_AEREO_FRENTE){
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
		if(State==STATE_CHUTE_MEDIO_AEREO_NEUTRO || State==STATE_CHUTE_MEDIO_AEREO_TRAS || State==STATE_CHUTE_MEDIO_AEREO_FRENTE){
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
		if(State==STATE_CHUTE_FORTE_AEREO_NEUTRO || State==STATE_CHUTE_FORTE_AEREO_TRAS || State==STATE_CHUTE_FORTE_AEREO_FRENTE){
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
		if(State==STATE_PULO_TRAS){
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
		if(State==STATE_PULO_FRENTE){
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
		if(State==STATE_ANDANDO_TRAS){
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
		if(State==STATE_ANDANDO_FRENTE){
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
		if(State==STATE_ESQUIVA_BAIXO){
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
		if(State==STATE_ROLAMENTO_TRAS){
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
		if(State==STATE_ROLAMENTO_FRENTE){
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
		if(State==STATE_HIT_TIPO1_FRACO){
			P[Player].w = 10*8;
			P[Player].h = 12*8;
			P[Player].axisX = ((P[Player].w)/2)-1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_501, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO1_MEDIO){
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
		if(State==STATE_HIT_TIPO1_FORTE){
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
		if(State==STATE_HIT_TIPO2_FRACO){
			P[Player].w = 11*8;
			P[Player].h = 11*8;
			P[Player].axisX = ((P[Player].w)/2)+8;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 2;//6
			P[Player].dataAnim[2]  = 6;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_506, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO2_MEDIO){
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
		if(State==STATE_HIT_TIPO2_FORTE){
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
		if(State==STATE_HIT_TIPO3_FRACO){
			P[Player].w = 9*8;
			P[Player].h = 10*8;
			P[Player].axisX = ((P[Player].w)/2)-1;
			P[Player].axisY =  (P[Player].h);
			P[Player].dataAnim[1]  = 12;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_511, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_HIT_TIPO3_MEDIO){
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
		if(State==STATE_HIT_TIPO3_FORTE){
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
		if(State==STATE_USER_HIT){
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
		if(State==STATE_CAINDO){
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
		if(State==STATE_QUICANDO_CHAO){
			P[Player].w = 15*8;
			P[Player].h =  7*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-3*8;
			P[Player].dataAnim[1]  = 99;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_551, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_LEVANTANDO){
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
		if(State==STATE_CAIDO_MORTO){
			P[Player].w = 15*8;
			P[Player].h =  6*8;
			P[Player].axisX = ((P[Player].w)/2);
			P[Player].axisY =  (P[Player].h)-2*8;
			P[Player].dataAnim[1]  = 60;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_570, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_ABAIXANDO){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 1;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_601, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_LEVANTANDO_TRANSICAO){
			P[Player].w = 13*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-10;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 1;
			P[Player].dataAnim[2]  = 2;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_602, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_INICIO_PULO_TRAS || State==STATE_INICIO_PULO_NEUTRO || State==STATE_INICIO_PULO_FRENTE){
			P[Player].w = 10*8;
			P[Player].h = 15*8;
			P[Player].axisX = (P[Player].w/2)-1;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 2;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_604, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_FINAL_PULO){
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
		if(State==STATE_VIRANDO_PE){
			P[Player].w = 10*8;
			P[Player].h = 14*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_607, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_VIRANDO_ABAIXADO){
			P[Player].w = 9*8;
			P[Player].h = 11*8;
			P[Player].axisX = (P[Player].w/2);
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 4;
			P[Player].dataAnim[2]  = 4;
			P[Player].animFrameTotal = 2;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_haohmaru_608, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
		if(State==STATE_INTRO){
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
		if(State==STATE_WIN1){
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
		if(State==STATE_WIN2){
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
		if(State==STATE_WIN3){
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
		if(State==STATE_PERDENDO_TIME_OVER){
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
		if(State==STATE_RAGE_EXPLOSION){
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
		if(State==STATE_ESPECIAL_700){
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
		if(State==STATE_ESPECIAL_710){
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
		if(State==STATE_ESPECIAL_720){
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
		if(State==STATE_ESPECIAL_730){
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
