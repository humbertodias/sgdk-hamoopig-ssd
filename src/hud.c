#include "hud.h"
#include "sprite.h"
#include "gfx.h"

void FUNCAO_RELOGIO()
{
	if(gClockTimer>0 && (gClockLTimer>0 || gClockRTimer>0) && (P[1].energiaBase>0 && P[2].energiaBase>0) ){ gClockTimer--; }
	if(gClockTimer==0)
	{
		gClockRTimer--;
		if(ClockR){ SPR_releaseSprite(ClockR); ClockR = NULL; }
		if(gClockRTimer==9){ ClockR = SPR_addSpriteEx(&spr_n9, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==8){ ClockR = SPR_addSpriteEx(&spr_n8, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==7){ ClockR = SPR_addSpriteEx(&spr_n7, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==6){ ClockR = SPR_addSpriteEx(&spr_n6, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==5){ ClockR = SPR_addSpriteEx(&spr_n5, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==4){ ClockR = SPR_addSpriteEx(&spr_n4, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==3){ ClockR = SPR_addSpriteEx(&spr_n3, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==2){ ClockR = SPR_addSpriteEx(&spr_n2, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==1){ ClockR = SPR_addSpriteEx(&spr_n1, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		if(gClockRTimer==0){ ClockR = SPR_addSpriteEx(&spr_n0, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
		
		if(gClockRTimer==-1)
		{
			if(gClockLTimer>0)
			{
				gClockLTimer--;
				if(ClockL){ SPR_releaseSprite(ClockL); ClockL = NULL; }
				if(gClockLTimer==9){ ClockL = SPR_addSpriteEx(&spr_n9, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==8){ ClockL = SPR_addSpriteEx(&spr_n8, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==7){ ClockL = SPR_addSpriteEx(&spr_n7, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==6){ ClockL = SPR_addSpriteEx(&spr_n6, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==5){ ClockL = SPR_addSpriteEx(&spr_n5, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==4){ ClockL = SPR_addSpriteEx(&spr_n4, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==3){ ClockL = SPR_addSpriteEx(&spr_n3, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==2){ ClockL = SPR_addSpriteEx(&spr_n2, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==1){ ClockL = SPR_addSpriteEx(&spr_n1, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				if(gClockLTimer==0){ ClockL = SPR_addSpriteEx(&spr_n0, 144, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC); }
				gClockRTimer=9;
				if(ClockR){ SPR_releaseSprite(ClockR); ClockR = NULL; }
				ClockR = SPR_addSpriteEx(&spr_n9, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
			}
		}
		gClockTimer=38; //reset Clock Count timer
		SPR_setVRAMTileIndex(ClockL,1703); //define uma posicao especifica para o GFX na VRAM
		SPR_setVRAMTileIndex(ClockR,1707); //define uma posicao especifica para o GFX na VRAM
	}
	
	//if(gClockRTimer==-1 && gClockRTimer==-1)
	//{ 
		/*TIMER OVER!*/ 
		//ClockR = SPR_addSpriteEx(&spr_n0, 160, 32, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_DISABLE_DELAYED_FRAME_UPDATE | SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		//SPR_setVRAMTileIndex(ClockR,1707); //define uma posicao especifica para o GFX na VRAM
	//}
}

void FUNCAO_BARRAS_DE_ENERGIA()
{
	for(i=1; i<=2; i++)
	{
		if( P[i].energia != P[i].energiaBase )
		{ 
			if(P[i].energia > P[i].energiaBase){ P[i].energia--; } //decrementa a 'energia' aos poucos, até igualar a 'energiaBase'
			if(P[i].energia < P[i].energiaBase){ P[i].energia++; } //incrementa a 'energia' aos poucos, até igualar a 'energiaBase'
		} 
		
		u8 subEnergyPos;
		if(                           P[i].energia==128){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 0); subEnergyPos= 0;
		}else if(P[i].energia< 128 && P[i].energia>=120){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 1); subEnergyPos= 1;
		}else if(P[i].energia< 120 && P[i].energia>=112){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 2); subEnergyPos= 2; 
		}else if(P[i].energia< 112 && P[i].energia>=104){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 3); subEnergyPos= 3;
		}else if(P[i].energia< 104 && P[i].energia>= 96){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 4); subEnergyPos= 4;
		}else if(P[i].energia<  96 && P[i].energia>= 88){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 5); subEnergyPos= 5;
		}else if(P[i].energia<  88 && P[i].energia>= 80){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 6); subEnergyPos= 6;
		}else if(P[i].energia<  80 && P[i].energia>= 72){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 7); subEnergyPos= 7;
		}else if(P[i].energia<  72 && P[i].energia>= 64){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 8); subEnergyPos= 8;
		}else if(P[i].energia<  64 && P[i].energia>= 56){ SPR_setAnimAndFrame(GE[2+i].sprite, 0, 9); subEnergyPos= 9;
		}else if(P[i].energia<  56 && P[i].energia>= 48){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,10); subEnergyPos=10;
		}else if(P[i].energia<  48 && P[i].energia>= 40){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,11); subEnergyPos=11;
		}else if(P[i].energia<  40 && P[i].energia>= 32){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,12); subEnergyPos=12;
		}else if(P[i].energia<  32 && P[i].energia>= 24){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,13); subEnergyPos=13;
		}else if(P[i].energia<  24 && P[i].energia>= 16){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,14); subEnergyPos=14;
		}else if(P[i].energia<  16 && P[i].energia>=  8){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,15); subEnergyPos=15;
		}else if(P[i].energia<   8 && P[i].energia>=  1){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,16); subEnergyPos=16;
		}else if(                     P[i].energia==  0){ SPR_setAnimAndFrame(GE[2+i].sprite, 0,16); subEnergyPos=16;
		}
		if(i==1){ SPR_setPosition(GE[4+i].sprite,   8+(subEnergyPos*8), 12); }
		if(i==2){ SPR_setPosition(GE[4+i].sprite, 304-(subEnergyPos*8), 12); }
		
		int a=0;
		if(subEnergyPos== 0){ a=128; }
		if(subEnergyPos== 1){ a=120; }
		if(subEnergyPos== 2){ a=112; }
		if(subEnergyPos== 3){ a=104; }
		if(subEnergyPos== 4){ a= 96; }
		if(subEnergyPos== 5){ a= 88; }
		if(subEnergyPos== 6){ a= 80; }
		if(subEnergyPos== 7){ a= 72; }
		if(subEnergyPos== 8){ a= 64; }
		if(subEnergyPos== 9){ a= 56; }
		if(subEnergyPos==10){ a= 48; }
		if(subEnergyPos==11){ a= 40; }
		if(subEnergyPos==12){ a= 32; }
		if(subEnergyPos==13){ a= 24; }
		if(subEnergyPos==14){ a= 16; }
		if(subEnergyPos==15){ a=  8; }
		if(subEnergyPos==16){ a=  0; }
		SPR_setAnimAndFrame(GE[4+i].sprite, 0, (P[i].energia-a) );
		
		//Exibe a barra de especial, e fica piscando, caso seja == 32
		if(P[i].energiaSP<32)
		{
			SPR_setAnimAndFrame(GE[6+i].sprite, 0, P[i].energiaSP);
		}else{
			if(gPing2==1){
				SPR_setAnimAndFrame(GE[6+i].sprite, 0, 32);
			}else{
				SPR_setAnimAndFrame(GE[6+i].sprite, 0, 33);
			}
		}
		
	}
	
	if(P[1].energiaSP>=32){ SPR_setVisibility(GE[ 9].sprite, VISIBLE); }else{ SPR_setVisibility(GE[ 9].sprite, HIDDEN); }
	if(P[2].energiaSP>=32){ SPR_setVisibility(GE[10].sprite, VISIBLE); }else{ SPR_setVisibility(GE[10].sprite, HIDDEN); }
	
}

void FUNCAO_SAMSHOFX() //ESPECIFICO DO SAMURAI SHODOWN 2
{
	//Carregar Sprite da Onda (Splash da Onda)
	//Eu optei por desabilitar temporariamente esse efeito para liberar VRAM
	/*
	if(gFrames==355 && gBG_Choice==1)
	{
		//GE[11].sprite = SPR_addSpriteExSafe(&spr_point, P[1].x, P[1].y, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		if (GE[11].sprite)
		{
		  SPR_releaseSprite(GE[11].sprite);
		  GE[11].sprite = NULL;
		}
		GE[11].sprite = SPR_addSpriteExSafe(&spr_wave_splash_big, 50, 88, TILE_ATTR(PAL1, FALSE, FALSE, FALSE), SPR_FLAG_AUTO_VISIBILITY | SPR_FLAG_AUTO_VRAM_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD | SPR_FLAG_AUTO_VRAM_ALLOC);
		SPR_setDepth(GE[11].sprite, 255 );
		SPR_setVRAMTileIndex(GE[11].sprite, 1453); //define uma posicao especifica para o GFX na VRAM
	}
	*/
	
	//ESPECIFICO DE SAMURAI SHODOW. AJUSTE DA BARRA DE RAGE
	if(P[1].energiaSP ==  0){  P[1].rageLvl=0; }
	if(P[1].energiaSP >   0 && P[1].energiaSP<=15){ P[1].rageLvl=0; }
	if(P[1].energiaSP >= 16 && P[1].energiaSP<=31){ P[1].rageLvl=1; }
	if(P[1].energiaSP >= 32){  P[1].rageLvl=2; }
	
	if(P[2].energiaSP ==  0){  P[2].rageLvl=0; }
	if(P[2].energiaSP >   0 && P[2].energiaSP<=15){ P[2].rageLvl=0; }
	if(P[2].energiaSP >= 16 && P[2].energiaSP<=31){ P[2].rageLvl=1; }
	if(P[2].energiaSP >= 32){  P[2].rageLvl=2; }
	
	//ESPECIFICO DO SAMURAI SHODOW. ESPADA PISCANDO E SOMBRA
	if(gPing2==0)
	{ 
		//P1
		if(P[1].id==1) //haohmaru
		{
			if(P[1].rageLvl==0)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_1a.palette->data, CPU); } 
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_1a.palette->data, CPU); } 
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_1a.palette->data, CPU); } 
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_1a.palette->data, CPU); } 
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_1a.palette->data, CPU); } 
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_1a.palette->data, CPU); } 
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_1a.palette->data, CPU); } 
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_1a.palette->data, CPU); } 
			}
			if(P[1].rageLvl==1)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_2a.palette->data, CPU); } 
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_2a.palette->data, CPU); } 
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_2a.palette->data, CPU); } 
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_2a.palette->data, CPU); } 
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_2a.palette->data, CPU); } 
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_2a.palette->data, CPU); } 
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_2a.palette->data, CPU); } 
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_2a.palette->data, CPU); } 
			}
			if(P[1].rageLvl==2)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_3a.palette->data, CPU); } 
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_3a.palette->data, CPU); } 
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_3a.palette->data, CPU); } 
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_3a.palette->data, CPU); } 
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_3a.palette->data, CPU); } 
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_3a.palette->data, CPU); } 
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_3a.palette->data, CPU); } 
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_3a.palette->data, CPU); } 
			}
		}
		if(gSombraStyle==2){ SPR_setVisibility(P[1].sombra, VISIBLE); }
		//P2
		if(P[2].id==1) //haohmaru
		{
			if(P[2].rageLvl==0)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_1a.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_1a.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_1a.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_1a.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_1a.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_1a.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_1a.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_1a.palette->data, CPU); } 
			}
			//P2
			if(P[2].rageLvl==1)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_2a.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_2a.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_2a.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_2a.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_2a.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_2a.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_2a.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_2a.palette->data, CPU); } 
			}
			//P2
			if(P[2].rageLvl==2)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_3a.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_3a.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_3a.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_3a.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_3a.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_3a.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_3a.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_3a.palette->data, CPU); } 
			}
		}
		if(gSombraStyle==2){ SPR_setVisibility(P[2].sombra, HIDDEN); }
	}
	if(gPing2==1)
	{ 
		//P1
		if(P[1].id==1) //haohmaru
		{
			if(P[1].rageLvl==0)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_1b.palette->data, CPU); }
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_1b.palette->data, CPU); }
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_1b.palette->data, CPU); }
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_1b.palette->data, CPU); }
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_1b.palette->data, CPU); }
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_1b.palette->data, CPU); }
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_1b.palette->data, CPU); }
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_1b.palette->data, CPU); } 
			}
			if(P[1].rageLvl==1)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_2b.palette->data, CPU); }
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_2b.palette->data, CPU); }
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_2b.palette->data, CPU); }
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_2b.palette->data, CPU); }
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_2b.palette->data, CPU); }
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_2b.palette->data, CPU); }
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_2b.palette->data, CPU); }
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_2b.palette->data, CPU); } 
			}
			if(P[1].rageLvl==2)
			{
				if(P[1].palID==1){ PAL_setPalette(PAL2, spr_haohmaru_pal1_3b.palette->data, CPU); }
				if(P[1].palID==2){ PAL_setPalette(PAL2, spr_haohmaru_pal2_3b.palette->data, CPU); }
				if(P[1].palID==3){ PAL_setPalette(PAL2, spr_haohmaru_pal3_3b.palette->data, CPU); }
				if(P[1].palID==4){ PAL_setPalette(PAL2, spr_haohmaru_pal4_3b.palette->data, CPU); }
				if(P[1].palID==5){ PAL_setPalette(PAL2, spr_haohmaru_pal5_3b.palette->data, CPU); }
				if(P[1].palID==6){ PAL_setPalette(PAL2, spr_haohmaru_pal6_3b.palette->data, CPU); }
				if(P[1].palID==7){ PAL_setPalette(PAL2, spr_haohmaru_pal7_3b.palette->data, CPU); }
				if(P[1].palID==8){ PAL_setPalette(PAL2, spr_haohmaru_pal8_3b.palette->data, CPU); } 
			}
		}
		if(gSombraStyle==2){ SPR_setVisibility(P[1].sombra, HIDDEN); }
		//P2
		if(P[2].id==1) //haohmaru
		{
			if(P[2].rageLvl==0)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_1b.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_1b.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_1b.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_1b.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_1b.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_1b.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_1b.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_1b.palette->data, CPU); } 
			}
			if(P[2].rageLvl==1)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_2b.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_2b.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_2b.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_2b.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_2b.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_2b.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_2b.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_2b.palette->data, CPU); } 
			}
			if(P[2].rageLvl==2)
			{
				if(P[2].palID==1){ PAL_setPalette(PAL3, spr_haohmaru_pal1_3b.palette->data, CPU); }
				if(P[2].palID==2){ PAL_setPalette(PAL3, spr_haohmaru_pal2_3b.palette->data, CPU); }
				if(P[2].palID==3){ PAL_setPalette(PAL3, spr_haohmaru_pal3_3b.palette->data, CPU); }
				if(P[2].palID==4){ PAL_setPalette(PAL3, spr_haohmaru_pal4_3b.palette->data, CPU); }
				if(P[2].palID==5){ PAL_setPalette(PAL3, spr_haohmaru_pal5_3b.palette->data, CPU); }
				if(P[2].palID==6){ PAL_setPalette(PAL3, spr_haohmaru_pal6_3b.palette->data, CPU); }
				if(P[2].palID==7){ PAL_setPalette(PAL3, spr_haohmaru_pal7_3b.palette->data, CPU); }
				if(P[2].palID==8){ PAL_setPalette(PAL3, spr_haohmaru_pal8_3b.palette->data, CPU); } 
			}
		}
		if(gSombraStyle==2){ SPR_setVisibility(P[2].sombra, VISIBLE); }
	}
}

