#include "utils.h"
#include "gfx.h"

void FUNCAO_UPDATE_LIFESP(u8 Player, u8 EnergyType, s8 Value)
{
	if(EnergyType==1) //energia
	{
		if(P[Player].energiaBase<Value*-1){ P[Player].energiaBase=0;
		}else{ P[Player].energiaBase = P[Player].energiaBase+Value; }
	}
	if(EnergyType==2) //energia especial
	{
		if(P[Player].energiaSP<Value*-1){ P[Player].energiaSP=0;
		}else{ P[Player].energiaSP = P[Player].energiaSP+Value; }
	}
}

void CLEAR_VDP()
{
	SYS_disableInts();
	 SPR_reset();
	 //VDP_resetSprites();
	 //VDP_releaseAllSprites();
	 //SPR_defragVRAM();
	 VDP_clearPlane(BG_A, TRUE);
	 VDP_clearPlane(BG_B, TRUE);	
	 PAL_setPaletteColors(0, (u16*) palette_black, 64);
	 VDP_setBackgroundColor(0);
	 //VDP_resetScreen();
	SYS_enableInts();
	gInd_tileset=0;
}
