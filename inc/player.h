#ifndef PLAYER_H
#define PLAYER_H

#include "game_globals.h"

// Player state management
void PLAYER_STATE(u8 Player, u16 State);
void FUNCAO_PLAY_SND(u8 Player, u16 State);
void FUNCAO_DEPTH(u8 Player);

#endif // PLAYER_H
