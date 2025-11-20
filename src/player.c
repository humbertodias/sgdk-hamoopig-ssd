#include "player.h"
#include "sprite.h"
#include "sound.h"
#include "animation.h"

void PLAYER_STATE(u8 Player, u16 State)
{
	SPR_releaseSprite(P[Player].sprite);
	P[Player].animFrame      = 1;
	P[Player].frameTimeAtual = 1;
	P[Player].dataAnim[1]    = 1;
	P[Player].animFrameTotal = 1;
	P[Player].state = State;
	
	FUNCAO_PLAY_SND(Player, State); //SOUND; SFX!
	
	/*samsho2*/ 
	// Evita o bug de sobrecarga de sprites, desabilitando o splash da onda.
	// O sprite da onda é desligado, caso:
	// * Debug esteja ativado
	// * PLAYERS soltem magias
	// * Golpes medios
	// * Golpes fortes
	// * Raiva
	if(
		gDebug==1 || 
		(State>=700 && State<=790) || 
		State==103 || State==106 || 
		State==102 || State==105 || 
		State==618
	){
		if (GE[11].sprite){
		  SPR_releaseSprite(GE[11].sprite);
		  GE[11].sprite = NULL;
		}
	}
	
	/*samsho2*/
	// Evita o bug de sobrecarga de sprites, desabilitando golpes (medio / forte) SIMULTANEOS do Gillius 
	// Esta solucao é temporaria! :)
	if( (P[1].id==2 && P[2].id==2) && ((P[1].state==102 || P[1].state==103) && Player==2) && (State==102 || State==103) ){ State=101; }
	if( (P[1].id==2 && P[2].id==2) && ((P[2].state==102 || P[2].state==103) && Player==1) && (State==102 || State==103) ){ State=101; }
	
	//virando de lado (mudanca de estado)
	if(Player==1 && P[1].direcao== 1 && P[2].x<P[1].x && State==100){ State=607; }
	if(Player==1 && P[1].direcao==-1 && P[1].x<P[2].x && State==100){ State=607; }
	if(Player==2 && P[2].direcao== 1 && P[1].x<P[2].x && State==100){ State=607; }
	if(Player==2 && P[2].direcao==-1 && P[2].x<P[1].x && State==100){ State=607; }
	if(Player==1 && P[1].direcao== 1 && P[2].x<P[1].x && State==200){ State=608; }
	if(Player==1 && P[1].direcao==-1 && P[1].x<P[2].x && State==200){ State=608; }
	if(Player==2 && P[2].direcao== 1 && P[1].x<P[2].x && State==200){ State=608; }
	if(Player==2 && P[2].direcao==-1 && P[2].x<P[1].x && State==200){ State=608; }
	
	//--- DEBUG_CHARACTER_TEST ---// #ID:0
	if(P[Player].id==0)
	{
		if(State==100 || State==610){
			P[Player].y = gAlturaPiso;
			P[Player].w = 8;
			P[Player].h = 8;
			P[Player].axisX = P[Player].w/2;
			P[Player].axisY = P[Player].h;
			P[Player].dataAnim[1]  = 250;
			P[Player].animFrameTotal = 1;
			P[Player].sprite = SPR_addSpriteExSafe(&spr_point, P[Player].x-P[Player].axisX, P[Player].y-P[Player].axisY, TILE_ATTR(P[Player].paleta, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		}
	}
	
	//--- HAOHMARU ---// #ID:1
	if(P[Player].id==1)
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
	
	//--- GILLIUS ---// #ID:2
	if(P[Player].id==2)
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
	FUNCAO_DEPTH(Player); //Define a prioridade de desenho
	FUNCAO_SPR_POSITION(); //Define a posicao do Sprite
}

void FUNCAO_PLAY_SND(u8 Player, u16 State)
{
	//P1 utiliza o 'P1_SFX' e 'SOUND_PCM_CH3'
	//P2 utiliza o 'P2_SFX' e 'SOUND_PCM_CH4'
	
	//Samurai Shodown 2 (SS2) nota:
	//Os golpes <FRACOS> geralmente alternam entre 2 sons
	//Os golpes <MEDIOS> e <FORTES> geralmente, alternam entre 4 sons
	
	if(Player==1)
	{
		if(P[1].id==1) //Haohmaru
		{
			if(
				State==101 || State==104 || 
				State==151 || State==154 || 
				State==201 || State==202 || State==204 || 
				State==301 || State==302 || State==311 || State==312 || State==321 || State==322
			)
			{
				if(gPing2==0){ XGM_setPCM(P1_SFX, snd_haohmaru_101a, sizeof(snd_haohmaru_101a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing2==1){ XGM_setPCM(P1_SFX, snd_haohmaru_101b, sizeof(snd_haohmaru_101b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			}
			if(
				State==102 || State==103 || State==105 || State==106 || 
				State==152 || State==153 || State==155 || State==156 || 
				State==203 || State==205 || State==206 || 
				State==303 || State==304 || State==305 || State==306 || 
				State==313 || State==314 || State==315 || State==316 || 
				State==323 || State==324 || State==325 || State==326
			)
			{
				if(gPing4==0){ XGM_setPCM(P1_SFX, snd_haohmaru_101a, sizeof(snd_haohmaru_101a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==1){ XGM_setPCM(P1_SFX, snd_haohmaru_101b, sizeof(snd_haohmaru_101b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==2){ XGM_setPCM(P1_SFX, snd_haohmaru_102a, sizeof(snd_haohmaru_102a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==3){ XGM_setPCM(P1_SFX, snd_haohmaru_102b, sizeof(snd_haohmaru_102b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			}
			if(State==110 || State==210){ XGM_setPCM(P1_SFX, snd_110, sizeof(snd_110)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==300 || State==310 || State==320){ XGM_setPCM(P1_SFX, snd_300, sizeof(snd_300)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==501 || State==506 || State==511){ XGM_setPCM(P1_SFX, snd_hit_1, sizeof(snd_hit_1)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==502 || State==507 || State==512){ XGM_setPCM(P1_SFX, snd_hit_2, sizeof(snd_hit_2)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==503 || State==508 || State==513 || State==555){ XGM_setPCM(P1_SFX, snd_hit_3, sizeof(snd_hit_3)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==551){ XGM_setPCM(P1_SFX, snd_551, sizeof(snd_551)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==606){ XGM_setPCM(P1_SFX, snd_606, sizeof(snd_606)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==618){ XGM_setPCM(P1_SFX, snd_haohmaru_618, sizeof(snd_haohmaru_618)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==700){ XGM_setPCM(P1_SFX, snd_haohmaru_700, sizeof(snd_haohmaru_700)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==710){ XGM_setPCM(P1_SFX, snd_haohmaru_710, sizeof(snd_haohmaru_710)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==720){ XGM_setPCM(P1_SFX, snd_haohmaru_720, sizeof(snd_haohmaru_720)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==730){ XGM_setPCM(P1_SFX, snd_haohmaru_102b, sizeof(snd_haohmaru_102b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
		}
		if(P[1].id==2) //Gillius
		{
			if(
				State==101 || State==104 || 
				State==151 || State==154 || 
				State==201 || State==202 || State==204 || 
				State==301 || State==302 || State==311 || State==312 || State==321 || State==322
			)
			{
				if(gPing2==0){ XGM_setPCM(P1_SFX, snd_gillius_101a, sizeof(snd_gillius_101a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing2==1){ XGM_setPCM(P1_SFX, snd_gillius_101b, sizeof(snd_gillius_101b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			}
			if(
				State==102 || State==103 || State==105 || State==106 || 
				State==152 || State==153 || State==155 || State==156 || 
				State==203 || State==205 || State==206 || 
				State==303 || State==304 || State==305 || State==306 || 
				State==313 || State==314 || State==315 || State==316 || 
				State==323 || State==324 || State==325 || State==326
			)
			{
				if(gPing4==0){ XGM_setPCM(P1_SFX, snd_gillius_101a, sizeof(snd_gillius_101a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==1){ XGM_setPCM(P1_SFX, snd_gillius_101b, sizeof(snd_gillius_101b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==2){ XGM_setPCM(P1_SFX, snd_gillius_102a, sizeof(snd_gillius_102a)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
				if(gPing4==3){ XGM_setPCM(P1_SFX, snd_gillius_102b, sizeof(snd_gillius_102b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			}
			if(State==110 || State==210){ XGM_setPCM(P1_SFX, snd_110, sizeof(snd_110)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==300 || State==310 || State==320){ XGM_setPCM(P1_SFX, snd_300, sizeof(snd_300)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==501 || State==506 || State==511){ XGM_setPCM(P1_SFX, snd_hit_1, sizeof(snd_hit_1)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==502 || State==507 || State==512){ XGM_setPCM(P1_SFX, snd_hit_2, sizeof(snd_hit_2)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==503 || State==508 || State==513 || State==555){ XGM_setPCM(P1_SFX, snd_hit_3, sizeof(snd_hit_3)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==551){ XGM_setPCM(P1_SFX, snd_551, sizeof(snd_551)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==606){ XGM_setPCM(P1_SFX, snd_606, sizeof(snd_606)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==618){ XGM_setPCM(P1_SFX, snd_gillius_102b, sizeof(snd_gillius_102b)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==700){ XGM_setPCM(P1_SFX, snd_gillius_700, sizeof(snd_gillius_700)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==710){ XGM_setPCM(P1_SFX, snd_gillius_710, sizeof(snd_gillius_710)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==720){ XGM_setPCM(P1_SFX, snd_gillius_720, sizeof(snd_gillius_720)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==730){ XGM_setPCM(P1_SFX, snd_gillius_730, sizeof(snd_gillius_730)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
			if(State==750){ XGM_setPCM(P1_SFX, snd_gillius_750, sizeof(snd_gillius_750)); XGM_startPlayPCM(P1_SFX, 1, SOUND_PCM_CH3); }
		}
	}
	
	if(Player==2)
	{
		if(P[2].id==1) //Haohmaru
		{		
			if(
				State==101 || State==104 || 
				State==151 || State==154 || 
				State==201 || State==202 || State==204 || 
				State==301 || State==302 || State==311 || State==312 || State==321 || State==322
			)
			{
				if(gPing2==0){ XGM_setPCM(P2_SFX, snd_haohmaru_101a, sizeof(snd_haohmaru_101a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing2==1){ XGM_setPCM(P2_SFX, snd_haohmaru_101b, sizeof(snd_haohmaru_101b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			}
			if(
				State==102 || State==103 || State==105 || State==106 || 
				State==152 || State==153 || State==155 || State==156 || 
				State==203 || State==205 || State==206 || 
				State==303 || State==304 || State==305 || State==306 || 
				State==313 || State==314 || State==315 || State==316 || 
				State==323 || State==324 || State==325 || State==326
			)
			{
				if(gPing4==0){ XGM_setPCM(P2_SFX, snd_haohmaru_101a, sizeof(snd_haohmaru_101a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==1){ XGM_setPCM(P2_SFX, snd_haohmaru_101b, sizeof(snd_haohmaru_101b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==2){ XGM_setPCM(P2_SFX, snd_haohmaru_102a, sizeof(snd_haohmaru_102a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==3){ XGM_setPCM(P2_SFX, snd_haohmaru_102b, sizeof(snd_haohmaru_102b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			}
			if(State==110 || State==210){ XGM_setPCM(P2_SFX, snd_110, sizeof(snd_110)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==300 || State==310 || State==320){ XGM_setPCM(P2_SFX, snd_300, sizeof(snd_300)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==501 || State==506 || State==511){ XGM_setPCM(P2_SFX, snd_hit_1, sizeof(snd_hit_1)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==502 || State==507 || State==512){ XGM_setPCM(P2_SFX, snd_hit_2, sizeof(snd_hit_2)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==503 || State==508 || State==513 || State==555){ XGM_setPCM(P2_SFX, snd_hit_3, sizeof(snd_hit_3)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==551){ XGM_setPCM(P2_SFX, snd_551, sizeof(snd_551)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==606){ XGM_setPCM(P2_SFX, snd_606, sizeof(snd_606)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==618){ XGM_setPCM(P2_SFX, snd_haohmaru_618, sizeof(snd_haohmaru_618)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==700){ XGM_setPCM(P2_SFX, snd_haohmaru_700, sizeof(snd_haohmaru_700)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==710){ XGM_setPCM(P2_SFX, snd_haohmaru_710, sizeof(snd_haohmaru_710)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==720){ XGM_setPCM(P2_SFX, snd_haohmaru_720, sizeof(snd_haohmaru_720)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==730){ XGM_setPCM(P2_SFX, snd_haohmaru_102b, sizeof(snd_haohmaru_102b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
		}
		if(P[2].id==2) //Gillius
		{		
			if(
				State==101 || State==104 || 
				State==151 || State==154 || 
				State==201 || State==202 || State==204 || 
				State==301 || State==302 || State==311 || State==312 || State==321 || State==322
			)
			{
				if(gPing2==0){ XGM_setPCM(P2_SFX, snd_gillius_101a, sizeof(snd_gillius_101a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing2==1){ XGM_setPCM(P2_SFX, snd_gillius_101b, sizeof(snd_gillius_101b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			}
			if(
				State==102 || State==103 || State==105 || State==106 || 
				State==152 || State==153 || State==155 || State==156 || 
				State==203 || State==205 || State==206 || 
				State==303 || State==304 || State==305 || State==306 || 
				State==313 || State==314 || State==315 || State==316 || 
				State==323 || State==324 || State==325 || State==326
			)
			{
				if(gPing4==0){ XGM_setPCM(P2_SFX, snd_gillius_101a, sizeof(snd_gillius_101a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==1){ XGM_setPCM(P2_SFX, snd_gillius_101b, sizeof(snd_gillius_101b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==2){ XGM_setPCM(P2_SFX, snd_gillius_102a, sizeof(snd_gillius_102a)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
				if(gPing4==3){ XGM_setPCM(P2_SFX, snd_gillius_102b, sizeof(snd_gillius_102b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			}
			if(State==110 || State==210){ XGM_setPCM(P2_SFX, snd_110, sizeof(snd_110)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==300 || State==310 || State==320){ XGM_setPCM(P2_SFX, snd_300, sizeof(snd_300)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==501 || State==506 || State==511){ XGM_setPCM(P2_SFX, snd_hit_1, sizeof(snd_hit_1)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==502 || State==507 || State==512){ XGM_setPCM(P2_SFX, snd_hit_2, sizeof(snd_hit_2)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==503 || State==508 || State==513 || State==555){ XGM_setPCM(P2_SFX, snd_hit_3, sizeof(snd_hit_3)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==551){ XGM_setPCM(P2_SFX, snd_551, sizeof(snd_551)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==606){ XGM_setPCM(P2_SFX, snd_606, sizeof(snd_606)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==618){ XGM_setPCM(P2_SFX, snd_gillius_102b, sizeof(snd_gillius_102b)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==700){ XGM_setPCM(P2_SFX, snd_gillius_700, sizeof(snd_gillius_700)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==710){ XGM_setPCM(P2_SFX, snd_gillius_710, sizeof(snd_gillius_710)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==720){ XGM_setPCM(P2_SFX, snd_gillius_720, sizeof(snd_gillius_720)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==730){ XGM_setPCM(P2_SFX, snd_gillius_730, sizeof(snd_gillius_730)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
			if(State==750){ XGM_setPCM(P2_SFX, snd_gillius_750, sizeof(snd_gillius_750)); XGM_startPlayPCM(P2_SFX, 1, SOUND_PCM_CH4); }
		}
	}
	
}

void FUNCAO_DEPTH(u8 Player)
{
	//Qto menor o 'depth', mais para frente o objeto fica na tela
	u8 depth;
	if(P[Player].state>=500 && P[Player].state<=572)                         {depth = Player+20;} //Hurts, Caindo
	if(P[Player].state==100)                                                 {depth = Player+10;} //Parado
	if(P[Player].state==471 || P[Player].state==472)                         {depth = Player+10;} //Rolamento, Dash, Esquiva
	if(P[Player].state==410 || P[Player].state==420)                         {depth = Player+10;} //Andando
	if(P[Player].state>=107 && P[Player].state<=110)                         {depth = Player+10;} //Defesa em Pe
	if(P[Player].state>=207 && P[Player].state<=210)                         {depth = Player+10;} //Defesa Abaixado
	if(P[Player].state>=101 && P[Player].state<=156)                         {depth = Player+ 8;} //Golpes em Pe
	if(P[Player].state>=200 && P[Player].state<=206)                         {depth = Player+ 6;} //Golpes Abaixados
	if(P[Player].state==300 || P[Player].state==310 || P[Player].state==320) {depth = Player+ 4;} //Pulos
	if(P[Player].state>=301 && P[Player].state<=326)                         {depth = Player+ 2;} //Golpes Aereos
	if(P[Player].state>=611 && P[Player].state<=614)                         {depth = Player+ 2;} //Vitoria
	if(P[Player].state>=700 && P[Player].state<=790)                         {depth = Player+ 2;} //Magias
	//define o Depth, SE e SOMENTE SE o sprite estiver carregado. 
	//O comando 'SPR_setDepth' pode ser potencialmente perigoso e TRAVAR o jogo se o SPRITE nao estiver completamente carregado na VRAM
	if(P[Player].sprite){ SPR_setDepth(P[Player].sprite, depth); }
}

