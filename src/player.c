#include "player.h"
#include "sprite.h"
#include "sound.h"
#include "animation.h"
#include "players/haohmaru.h"
#include "players/gillius.h"

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
		haohmaru_state_handler(Player, State);
	}
	
	//--- GILLIUS ---// #ID:2
	if(P[Player].id==2)
	{
		gillius_state_handler(Player, State);
	}
	
	//Depth
	u16 depth = Player;
	if(P[Player].state>=601 && P[Player].state<=605)                         {depth = Player+ 0;} //Derrota
	if(P[Player].state==609)                                                 {depth = Player+ 0;} //Nocaute
	if(P[Player].state==618 || P[Player].state==619)                         {depth = Player+ 0;} //Raiva
	if(P[Player].state>=400 && P[Player].state<=599)                         {depth = Player+12;} //Dano
	if(P[Player].state==607 || P[Player].state==608)                         {depth = Player+10;} //Virando de lado
	if(P[Player].state==100 || P[Player].state==200)                         {depth = Player+10;} //Parado
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
