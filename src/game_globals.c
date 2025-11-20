#include "game_globals.h"

//--- VARIAVEIS ---//
u8   i = 0;
u32  gFrames = 0;
bool gPodeMover = 1;
u8   gWinnerID = 0;
u8   gLoseID = 0;
bool gContinueOption = 0;
u8   gRoom = 1;
u8   gTimerExit = 0;
u8   gDescompressionExit = 0;
s8   gClockTimer = 60;
s8   gClockLTimer = 9;
s8   gClockRTimer = 9;
u8   gRound = 1;
u8   gSombraStyle = 1;
bool gDebug = 0;
char gStr[64] = {0};
u16  gInd_tileset = 0;
bool gASG_system = 0;
u8   gPing2 = 0;
u8   gPing4 = 0;
u8   gPing10 = 0;
u8   gInputTimerCountDown = 20;
u16  gDistancia = 0;
u8   gAlturaPiso = 0;
u8   gBgAnim = 0;
u16  gLimiteCenarioE = 30;
u16  gLimiteCenarioD = 290;
u8   gravidadePadrao = 3;
u8   impulsoPadrao = -14;
u16  gBG_Width = 0;
s16  gScrollValues[28] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
s16  gScrollValue = 0;
u8   gBG_Choice = 1;
u8   Spark1_countDown = 0;
u8   Spark2_countDown = 0;
s16  PetalaPX[40] = {0};
s16  PetalaPY[40] = {0};

//Char Selection Menu
u8   cursorP1linha  = 1;
u8   cursorP1coluna = 1;
u8   cursorP1_ID = 0;
u8   cursorP1ConfirmFX = 0;
u8   cursorP1ColorChoice = 0;
u8   cursorP2linha  = 1;
u8   cursorP2coluna = 4;
u8   cursorP2_ID = 0;
u8   cursorP2ConfirmFX = 0;
u8   cursorP2ColorChoice = 0;
u8   cursorConfirmTimer = 0;
bool endP1Selection = 0;
bool endP2Selection = 0;

//Sprites
Sprite* Rect1BB1_Q1 = NULL; Sprite* Rect1BB1_Q2 = NULL; Sprite* Rect1BB1_Q3 = NULL; Sprite* Rect1BB1_Q4 = NULL;
Sprite* Rect1HB1_Q1 = NULL; Sprite* Rect1HB1_Q2 = NULL; Sprite* Rect1HB1_Q3 = NULL; Sprite* Rect1HB1_Q4 = NULL;
Sprite* Rect2BB1_Q1 = NULL; Sprite* Rect2BB1_Q2 = NULL; Sprite* Rect2BB1_Q3 = NULL; Sprite* Rect2BB1_Q4 = NULL;
Sprite* Rect2HB1_Q1 = NULL; Sprite* Rect2HB1_Q2 = NULL; Sprite* Rect2HB1_Q3 = NULL; Sprite* Rect2HB1_Q4 = NULL;
Sprite* ClockL = NULL;
Sprite* ClockR = NULL;
Sprite* HUD_Lethers = NULL;
Sprite* Spark[3] = {NULL, NULL, NULL};

//Inputs, Joystick
bool JOY1_UP=0, JOY1_DOWN=0, JOY1_LEFT=0, JOY1_RIGHT=0, JOY1_A=0, JOY1_B=0, JOY1_C=0, JOY1_X=0, JOY1_Y=0, JOY1_Z=0, JOY1_START=0, JOY1_MODE=0;
bool key_JOY1_UP_pressed=0, key_JOY1_UP_hold=0, key_JOY1_UP_released=0;
bool key_JOY1_DOWN_pressed=0, key_JOY1_DOWN_hold=0, key_JOY1_DOWN_released=0;
bool key_JOY1_LEFT_pressed=0, key_JOY1_LEFT_hold=0, key_JOY1_LEFT_released=0;
bool key_JOY1_RIGHT_pressed=0, key_JOY1_RIGHT_hold=0, key_JOY1_RIGHT_released=0;
bool key_JOY1_A_pressed=0, key_JOY1_A_hold=0, key_JOY1_A_released=0;
bool key_JOY1_B_pressed=0, key_JOY1_B_hold=0, key_JOY1_B_released=0;
bool key_JOY1_C_pressed=0, key_JOY1_C_hold=0, key_JOY1_C_released=0;
bool key_JOY1_X_pressed=0, key_JOY1_X_hold=0, key_JOY1_X_released=0;
bool key_JOY1_Y_pressed=0, key_JOY1_Y_hold=0, key_JOY1_Y_released=0;
bool key_JOY1_Z_pressed=0, key_JOY1_Z_hold=0, key_JOY1_Z_released=0;
bool key_JOY1_START_pressed=0, key_JOY1_START_hold=0, key_JOY1_START_released=0;
bool key_JOY1_MODE_pressed=0, key_JOY1_MODE_hold=0, key_JOY1_MODE_released=0;

bool JOY2_UP=0, JOY2_DOWN=0, JOY2_LEFT=0, JOY2_RIGHT=0, JOY2_A=0, JOY2_B=0, JOY2_C=0, JOY2_X=0, JOY2_Y=0, JOY2_Z=0, JOY2_START=0, JOY2_MODE=0;
bool key_JOY2_UP_pressed=0, key_JOY2_UP_hold=0, key_JOY2_UP_released=0;
bool key_JOY2_DOWN_pressed=0, key_JOY2_DOWN_hold=0, key_JOY2_DOWN_released=0;
bool key_JOY2_LEFT_pressed=0, key_JOY2_LEFT_hold=0, key_JOY2_LEFT_released=0;
bool key_JOY2_RIGHT_pressed=0, key_JOY2_RIGHT_hold=0, key_JOY2_RIGHT_released=0;
bool key_JOY2_A_pressed=0, key_JOY2_A_hold=0, key_JOY2_A_released=0;
bool key_JOY2_B_pressed=0, key_JOY2_B_hold=0, key_JOY2_B_released=0;
bool key_JOY2_C_pressed=0, key_JOY2_C_hold=0, key_JOY2_C_released=0;
bool key_JOY2_X_pressed=0, key_JOY2_X_hold=0, key_JOY2_X_released=0;
bool key_JOY2_Y_pressed=0, key_JOY2_Y_hold=0, key_JOY2_Y_released=0;
bool key_JOY2_Z_pressed=0, key_JOY2_Z_hold=0, key_JOY2_Z_released=0;
bool key_JOY2_START_pressed=0, key_JOY2_START_hold=0, key_JOY2_START_released=0;
bool key_JOY2_MODE_pressed=0, key_JOY2_MODE_hold=0, key_JOY2_MODE_released=0;

//Players e Graphic Elements
struct PlayerDEF P[3] = {{0}};
struct GraphicElementDEF GE[25] = {{0}};
