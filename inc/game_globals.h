#ifndef GAME_GLOBALS_H
#define GAME_GLOBALS_H

#include "game_types.h"

//--- VARIAVEIS GLOBAIS ---//
extern u8   i;                   //Variavel inteira de uso geral
extern u32  gFrames;             //Contador de frames
extern bool gPodeMover;          //Desabilita os inputs dos players em momentos especificos
extern u8   gWinnerID;           //Personagem Vencedor da Luta
extern u8   gLoseID;             //Personagem Perdedor da Luta
extern bool gContinueOption;     //Reinicia, ou nao, a luta
extern u8   gRoom;               //'Room / Sala' do jogo
extern u8   gTimerExit;          //Timer para ir para a proxima tela
extern u8   gDescompressionExit; //Usado na Room de Descompressao
extern s8   gClockTimer;         //Relogio, timer de 1 seg
extern s8   gClockLTimer;        //Digito esquerdo do Relogio
extern s8   gClockRTimer;        //Digito direito do Relogio
extern u8   gRound;              //Round Number
extern u8   gSombraStyle;        //Estilo de Sombra
extern bool gDebug;              //Exibe o Debug
extern char gStr[64];            //Variavel para armazenar textos
extern u16  gInd_tileset;        //Variavel utilizada para carregar dados de background
extern bool gASG_system;         //Anti Sprite Glitch System
extern u8   gPing2;              //Variavel que alterna entre 0 e 1
extern u8   gPing4;              //Variavel que alterna entre 0 ; 1 ; 2 ; 3
extern u8   gPing10;             //Variavel que alterna entre 0 ; 1 ; 2 ... 9
extern u8   gInputTimerCountDown; //Utilizada para os comandos de magias
extern u16  gDistancia;          //Distancia entre os Players
extern u8   gAlturaPiso;         //Altura do Piso
extern u8   gBgAnim;             //Timer para animacao do cenario
extern u16  gLimiteCenarioE;     //Limite Esquerdo
extern u16  gLimiteCenarioD;     //Limite Direito
extern u8   gravidadePadrao;     //Utilizado nos controles de Fisica
extern u8   impulsoPadrao;       //Utilizado nos controles de Fisica
extern u16  gBG_Width;           //Largura do Cenario, em pixels
extern s16  gScrollValues[28];   //Scrolling do Cenario
extern s16  gScrollValue;        //Scrolling de Cenario
extern u8   gBG_Choice;          //Cenario Escolhido
extern u8   Spark1_countDown;    //Desativa Efeito Spark1
extern u8   Spark2_countDown;    //Desativa Efeito Spark2
extern s16  PetalaPX[40];        //Petalas da tela de Apresentacao, X
extern s16  PetalaPY[40];        //Petalas da tela de Apresentacao, Y

//Char Selection Menu
extern u8   cursorP1linha;
extern u8   cursorP1coluna;
extern u8   cursorP1_ID;
extern u8   cursorP1ConfirmFX;
extern u8   cursorP1ColorChoice;
extern u8   cursorP2linha;
extern u8   cursorP2coluna;
extern u8   cursorP2_ID;
extern u8   cursorP2ConfirmFX;
extern u8   cursorP2ColorChoice;
extern u8   cursorConfirmTimer;
extern bool endP1Selection;
extern bool endP2Selection;

//Sprites
extern Sprite* Rect1BB1_Q1; extern Sprite* Rect1BB1_Q2; extern Sprite* Rect1BB1_Q3; extern Sprite* Rect1BB1_Q4;
extern Sprite* Rect1HB1_Q1; extern Sprite* Rect1HB1_Q2; extern Sprite* Rect1HB1_Q3; extern Sprite* Rect1HB1_Q4;
extern Sprite* Rect2BB1_Q1; extern Sprite* Rect2BB1_Q2; extern Sprite* Rect2BB1_Q3; extern Sprite* Rect2BB1_Q4;
extern Sprite* Rect2HB1_Q1; extern Sprite* Rect2HB1_Q2; extern Sprite* Rect2HB1_Q3; extern Sprite* Rect2HB1_Q4;
extern Sprite* ClockL;
extern Sprite* ClockR;
extern Sprite* HUD_Lethers;
extern Sprite* Spark[3];

//Inputs, Joystick
extern bool JOY1_UP, JOY1_DOWN, JOY1_LEFT, JOY1_RIGHT, JOY1_A, JOY1_B, JOY1_C, JOY1_X, JOY1_Y, JOY1_Z, JOY1_START, JOY1_MODE;
extern bool key_JOY1_UP_pressed, key_JOY1_UP_hold, key_JOY1_UP_released;
extern bool key_JOY1_DOWN_pressed, key_JOY1_DOWN_hold, key_JOY1_DOWN_released;
extern bool key_JOY1_LEFT_pressed, key_JOY1_LEFT_hold, key_JOY1_LEFT_released;
extern bool key_JOY1_RIGHT_pressed, key_JOY1_RIGHT_hold, key_JOY1_RIGHT_released;
extern bool key_JOY1_A_pressed, key_JOY1_A_hold, key_JOY1_A_released;
extern bool key_JOY1_B_pressed, key_JOY1_B_hold, key_JOY1_B_released;
extern bool key_JOY1_C_pressed, key_JOY1_C_hold, key_JOY1_C_released;
extern bool key_JOY1_X_pressed, key_JOY1_X_hold, key_JOY1_X_released;
extern bool key_JOY1_Y_pressed, key_JOY1_Y_hold, key_JOY1_Y_released;
extern bool key_JOY1_Z_pressed, key_JOY1_Z_hold, key_JOY1_Z_released;
extern bool key_JOY1_START_pressed, key_JOY1_START_hold, key_JOY1_START_released;
extern bool key_JOY1_MODE_pressed, key_JOY1_MODE_hold, key_JOY1_MODE_released;

extern bool JOY2_UP, JOY2_DOWN, JOY2_LEFT, JOY2_RIGHT, JOY2_A, JOY2_B, JOY2_C, JOY2_X, JOY2_Y, JOY2_Z, JOY2_START, JOY2_MODE;
extern bool key_JOY2_UP_pressed, key_JOY2_UP_hold, key_JOY2_UP_released;
extern bool key_JOY2_DOWN_pressed, key_JOY2_DOWN_hold, key_JOY2_DOWN_released;
extern bool key_JOY2_LEFT_pressed, key_JOY2_LEFT_hold, key_JOY2_LEFT_released;
extern bool key_JOY2_RIGHT_pressed, key_JOY2_RIGHT_hold, key_JOY2_RIGHT_released;
extern bool key_JOY2_A_pressed, key_JOY2_A_hold, key_JOY2_A_released;
extern bool key_JOY2_B_pressed, key_JOY2_B_hold, key_JOY2_B_released;
extern bool key_JOY2_C_pressed, key_JOY2_C_hold, key_JOY2_C_released;
extern bool key_JOY2_X_pressed, key_JOY2_X_hold, key_JOY2_X_released;
extern bool key_JOY2_Y_pressed, key_JOY2_Y_hold, key_JOY2_Y_released;
extern bool key_JOY2_Z_pressed, key_JOY2_Z_hold, key_JOY2_Z_released;
extern bool key_JOY2_START_pressed, key_JOY2_START_hold, key_JOY2_START_released;
extern bool key_JOY2_MODE_pressed, key_JOY2_MODE_hold, key_JOY2_MODE_released;

//Players e Graphic Elements
extern struct PlayerDEF P[3];
extern struct GraphicElementDEF GE[25];

#endif // GAME_GLOBALS_H
