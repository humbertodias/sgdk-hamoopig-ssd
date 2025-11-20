#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#include <genesis.h>

//--- DEFINICOES ---//
#define WEAK   1
#define MEDIUM 2
#define FIERCE 3
#define LP     1
#define MP     2
#define HP     3
#define LK     4
#define MK     5
#define HK     6
#define INDEX_MAR 0xe3 // Usado na animacao do cenario (endereco de memoria)
#define CIGD 3         // (C)iclo(I)nteracoes(G)ravidade(D)efault (usado na engine de Fisica)
#define BODYSPACE 20   // Distancia minima entre os jogadores (x2)
#define RAGETIMER 600  // Tempo de Fúria no samsho2, antes de voltar ao normal
//SOUND DEFs
#define INGAME_SFX 64
#define P1_SFX     65
#define P2_SFX     66

//--- ENUMS ---//
// Game room/screen states
typedef enum {
	ROOM_HAMOOPIG = 1,       // Tela HAMOOPIG
	ROOM_PRESENTATION = 2,   // Tela de apresentacao
	ROOM_CHAR_SELECT = 3,    // Character selection
	ROOM_STAGE_SELECT = 4,   // Stage selection
	ROOM_DESCOMPRESSION = 9, // Descompressao
	ROOM_IN_GAME = 10,       // In game
	ROOM_AFTER_MATCH = 11    // After match
} GameRoom;

// Player states - HAMOOPIG Finite State Machine (FSM)
typedef enum {
	// Portraits
	STATE_PORTRAIT_GRANDE = 0,          // Retrato Grande do Personagem
	STATE_PORTRAIT_PEQUENO = 1,         // Retrato Pequeno do Personagem
	
	// Standing - Long Distance
	STATE_PARADO = 100,                 // Personagem PARADO
	STATE_SOCO_FRACO_LONGE = 101,       // Soco Fraco de Longe
	STATE_SOCO_MEDIO_LONGE = 102,       // Soco Médio de Longe
	STATE_SOCO_FORTE_LONGE = 103,       // Soco Forte de Longe
	STATE_CHUTE_FRACO_LONGE = 104,      // Chute Fraco de Longe
	STATE_CHUTE_MEDIO_LONGE = 105,      // Chute Médio de Longe
	STATE_CHUTE_FORTE_LONGE = 106,      // Chute Forte de Longe
	STATE_DEFESA_PE_INICIO = 107,       // Inicio da Defesa em Pé
	STATE_DEFESA_PE_DEFENDENDO = 108,   // Defendendo em Pé
	STATE_DEFESA_PE_FINAL = 109,        // Final da Defesa em Pé
	STATE_DEFESA_PE_APLICADA = 110,     // Defesa em Pé, Aplicada
	
	// Standing - Close Distance
	STATE_SOCO_FRACO_PERTO = 151,       // Soco Fraco de Perto
	STATE_SOCO_MEDIO_PERTO = 152,       // Soco Médio de Perto
	STATE_SOCO_FORTE_PERTO = 153,       // Soco Forte de Perto
	STATE_CHUTE_FRACO_PERTO = 154,      // Chute Fraco de Perto
	STATE_CHUTE_MEDIO_PERTO = 155,      // Chute Médio de Perto
	STATE_CHUTE_FORTE_PERTO = 156,      // Chute Forte de Perto
	
	// Crouching
	STATE_ABAIXADO = 200,               // Abaixado
	STATE_SOCO_FRACO_ABAIXADO = 201,    // Soco Fraco Abaixado
	STATE_SOCO_MEDIO_ABAIXADO = 202,    // Soco Médio Abaixado
	STATE_SOCO_FORTE_ABAIXADO = 203,    // Soco Forte Abaixado
	STATE_CHUTE_FRACO_ABAIXADO = 204,   // Chute Fraco Abaixado
	STATE_CHUTE_MEDIO_ABAIXADO = 205,   // Chute Médio Abaixado
	STATE_CHUTE_FORTE_ABAIXADO = 206,   // Chute Forte Abaixado
	STATE_DEFESA_ABAIXADO_INICIO = 207, // Inicio da Defesa Abaixado
	STATE_DEFESA_ABAIXADO_DEFENDENDO = 208, // Defendendo Abaixado
	STATE_DEFESA_ABAIXADO_FINAL = 209,  // Final da Defesa Abaixado
	STATE_DEFESA_ABAIXADO_APLICADA = 210, // Defesa Abaixada, Aplicada
	
	// Aerial - Neutral
	STATE_PULO_NEUTRO = 300,            // Pulo Neutro
	STATE_SOCO_FRACO_AEREO_NEUTRO = 301,  // Soco Fraco Aéreo Neutro
	STATE_SOCO_MEDIO_AEREO_NEUTRO = 302,  // Soco Médio Aéreo Neutro
	STATE_SOCO_FORTE_AEREO_NEUTRO = 303,  // Soco Forte Aéreo Neutro
	STATE_CHUTE_FRACO_AEREO_NEUTRO = 304, // Chute Fraco Aéreo Neutro
	STATE_CHUTE_MEDIO_AEREO_NEUTRO = 305, // Chute Médio Aéreo Neutro
	STATE_CHUTE_FORTE_AEREO_NEUTRO = 306, // Chute Forte Aéreo Neutro
	
	// Aerial - Backward
	STATE_PULO_TRAS = 310,              // Pulo para Trás
	STATE_SOCO_FRACO_AEREO_TRAS = 311,  // Soco Fraco Aéreo para Trás
	STATE_SOCO_MEDIO_AEREO_TRAS = 312,  // Soco Médio Aéreo para Trás
	STATE_SOCO_FORTE_AEREO_TRAS = 313,  // Soco Forte Aéreo para Trás
	STATE_CHUTE_FRACO_AEREO_TRAS = 314, // Chute Fraco Aéreo para Trás
	STATE_CHUTE_MEDIO_AEREO_TRAS = 315, // Chute Médio Aéreo para Trás
	STATE_CHUTE_FORTE_AEREO_TRAS = 316, // Chute Forte Aéreo para Trás
	
	// Aerial - Forward
	STATE_PULO_FRENTE = 320,            // Pulo para Frente
	STATE_SOCO_FRACO_AEREO_FRENTE = 321,  // Soco Fraco Aéreo para Frente
	STATE_SOCO_MEDIO_AEREO_FRENTE = 322,  // Soco Médio Aéreo para Frente
	STATE_SOCO_FORTE_AEREO_FRENTE = 323,  // Soco Forte Aéreo para Frente
	STATE_CHUTE_FRACO_AEREO_FRENTE = 324, // Chute Fraco Aéreo para Frente
	STATE_CHUTE_MEDIO_AEREO_FRENTE = 325, // Chute Médio Aéreo para Frente
	STATE_CHUTE_FORTE_AEREO_FRENTE = 326, // Chute Forte Aéreo para Frente
	
	// Movement
	STATE_ANDANDO_TRAS = 410,           // Andando para Trás
	STATE_ANDANDO_FRENTE = 420,         // Andando para Frente
	STATE_ESQUIVA_BAIXO = 470,          // Esquiva para Baixo / Esquiva para Trás
	STATE_ROLAMENTO_TRAS = 471,         // Rolamento para Trás
	STATE_ROLAMENTO_FRENTE = 472,       // Rolamento para Frente
	STATE_DISPONIVEL_473 = 473,         // disponível
	STATE_DISPONIVEL_475 = 475,         // disponível
	STATE_CORRIDA_INICIO = 480,         // Inicio da corrida
	STATE_CORRENDO = 481,               // Correndo
	STATE_CORRIDA_FINAL = 482,          // Final da Corrida
	
	// Getting Hit
	STATE_HIT_TIPO1_FRACO = 501,        // Hit Tipo 1, Fraco
	STATE_HIT_TIPO1_MEDIO = 502,        // Hit Tipo 1, Medio
	STATE_HIT_TIPO1_FORTE = 503,        // Hit Tipo 1, Forte
	STATE_HIT_DISPONIVEL_504 = 504,     // disponível
	STATE_HIT_DISPONIVEL_505 = 505,     // disponível
	STATE_HIT_TIPO2_FRACO = 506,        // Hit Tipo 2, Fraco
	STATE_HIT_TIPO2_MEDIO = 507,        // Hit Tipo 2, Medio
	STATE_HIT_TIPO2_FORTE = 508,        // Hit Tipo 2, Forte
	STATE_HIT_TIPO3_FRACO = 511,        // Hit Tipo 3, Fraco
	STATE_HIT_TIPO3_MEDIO = 512,        // Hit Tipo 3, Medio
	STATE_HIT_TIPO3_FORTE = 513,        // Hit Tipo 3, Forte
	STATE_HIT_DISPONIVEL_514 = 514,     // disponível
	STATE_HIT_DISPONIVEL_515 = 515,     // disponível
	STATE_USER_HIT = 516,               // User Hit
	STATE_HIT_DISPONIVEL_517 = 517,     // disponível
	STATE_HIT_DISPONIVEL_518 = 518,     // disponível
	STATE_HIT_DISPONIVEL_519 = 519,     // disponível
	STATE_HIT_DISPONIVEL_520 = 520,     // disponível
	STATE_CAINDO = 550,                 // Caindo
	STATE_QUICANDO_CHAO = 551,          // Quicando no chão
	STATE_LEVANTANDO = 552,             // Levantando
	STATE_HIT_DISPONIVEL_555 = 555,     // disponível
	STATE_CAIDO_MORTO = 570,            // Caido, Morto
	
	// Transitions
	STATE_ABAIXANDO = 601,              // Abaixando
	STATE_LEVANTANDO_TRANSICAO = 602,   // Levantando
	STATE_INICIO_PULO_TRAS = 603,       // Inicio Pulo para Trás
	STATE_INICIO_PULO_NEUTRO = 604,     // Inicio Pulo Neutro
	STATE_INICIO_PULO_FRENTE = 605,     // Inicio Pulo para Frente
	STATE_FINAL_PULO = 606,             // Final do Pulo / Aterrisando no chão
	STATE_VIRANDO_PE = 607,             // Virando, em Pé
	STATE_VIRANDO_ABAIXADO = 608,       // Virando Abaixado
	STATE_NOCAUTE = 609,                // Nocaute
	
	// Victory and Defeat
	STATE_INTRO = 610,                  // Intro
	STATE_WIN1 = 611,                   // Win1
	STATE_WIN2 = 612,                   // Win2
	STATE_WIN3 = 613,                   // Win3
	STATE_WIN4 = 614,                   // Win4
	STATE_PERDENDO_TIME_OVER = 615,     // Perdendo por Time Over
	STATE_RAGE_EXPLOSION = 618,         // Rage Explosion (Samurai Shodown 2)
	STATE_RAGE_DISPONIVEL_619 = 619,    // disponível
	
	// Special Moves (700-900)
	STATE_ESPECIAL_700 = 700,           // Especial 1
	STATE_FIREBALL_701 = 701,           // Fireball 1
	STATE_SPARK_FIREBALL = 702,         // Spark da Fireball 1
	STATE_ESPECIAL_710 = 710,           // Especial 2
	STATE_ESPECIAL_711 = 711,           // Especial 2 Fireball
	STATE_ESPECIAL_720 = 720,           // Especial 3
	STATE_ESPECIAL_730 = 730,           // Especial 4
	STATE_ESPECIAL_740 = 740,           // Especial 5
	STATE_ESPECIAL_750 = 750,           // Especial 6
	STATE_ESPECIAL_751 = 751,           // Especial 6 continuation
	STATE_ESPECIAL_790 = 790            // Last special slot
} PlayerState;

//--- ESTRUTURAS ---//
struct PlayerDEF {
	Sprite* sprite;      //Sprite do Player 
	Sprite* sombra;      //Sprite (sombra) do Player 
	Sprite* fBall;       //Fireball do Player
	s8 fBallDirecao;     //Direcao de propagacao da Fireball (eixo X)
	u8 fBallSpeedX;      //Velocidade da Magia (eixo X)
	bool fBallActive;    //Fireball está ativada ou nao
	s16 fBallX;          //Posicao X da Magia
	s16 fBallY;          //Posicao Y da Magia
	int paleta;          //Paleta do personagem
	u8  palID;           //ID da paleta ativa no momento
	u8  wins;            //Contador de vitorias; Rounds vencidos
	u8  energia;         //Energia do Player, usada para fins de HUD, graficos das barras
	u8  energiaBase;     //Energia Base do Player, essa é a energia real, usada para definir o round
	u8  energiaSP;       //Energia / Barra de Especial
	u8  rageLvl;         //Nivel de Raiva, usado no jogo Samurai Shodown 2 /*samsho2*/
	u16 rageTimerCountdown; //Tempo em que fica furioso no samsho2
	u16 state;           //Controla o estado (animacao) do Player
	u8  joyDirTimer[10]; //Utilizado para verificar o comando das magias -> Direcionais Timers
	u8  inputArray[5];   //Utilizado para verificar o comando das magias -> Direcionais Ordenados
	u8  attackPower;     //Utilizado para verificar o comando das magias -> Weak; Medium; Fierce
	u8  attackButton;    //Utilizado para verificar o comando das magias -> LP, MP, HK, LK, MK, HK
	u8  id;              //Identificacao numerica do personagem selecionado. Exemplo: Ryu=1; Ken=2; etc...
	s16 x;               //Posicao X do Player
	s16 y;               //Posicao Y do Player
	u8  w;               //Largura do Sprite
	u8  h;               //Altura do Sprite
	u8  axisX;           //Posicao X do Ponto Pivot
	u8  axisY;           //Posicao Y do Ponto Pivot
	s8  direcao;         //Direcao para qual o Player esta olhando (1 ; -1)
	u8  hSpeed;          //Velocidade Horizontal
	u8  puloTimer;       //Tempo do Pulo
	u8  cicloInteracoesGravidade;     //Controles de Gravidade
	u8  cicloInteracoesGravidadeCont; //Controles de Gravidade
	s8  impulsoY;                     //Controles de Gravidade
	s8  gravidadeY;                   //Controles de Gravidade
	u16 frameTimeAtual;  //Tempo atual do frame de animacao corrente
	u16 frameTimeTotal;  //Tempo total do frame de animacao corrente
	u16 animFrame;       //Frame de animacao atual
	u16 animFrameTotal;  //Qtde total de frames deste estado (animacao)
	u8  hitPause;        //Tempo de congelamento apos o Hit
	u16 dataAnim[60];    //Total de frames disponiveis para cada estado (animacao)
	u16 dataHBox[4];     //Posiconamento das Hit Boxes (caixas vermelhas de ataque)
	u16 dataBBox[4];     //Posiconamento das Body Boxes (caixas azuis, area vulneravel a ataques)
	u16 dataMBox[4];     //Posiconamento das Mass Boxes (caixas de massa, corpo fisico do personagem, usado para empurrar)
	//JOYSTICK
	u8 key_JOY_UP_status; u8 key_JOY_DOWN_status; u8 key_JOY_LEFT_status; u8 key_JOY_RIGHT_status;
	u8 key_JOY_A_status; u8 key_JOY_B_status; u8 key_JOY_C_status;
	u8 key_JOY_X_status; u8 key_JOY_Y_status; u8 key_JOY_Z_status;
	u8 key_JOY_START_status; u8 key_JOY_MODE_status;
	u8 key_JOY_countdown[10]; //timer regressivo, ativado apos pressionar um botao direcional (usado para correr, esquivar, etc)
};

struct GraphicElementDEF {
	Sprite* sprite;      //Sprite do Graphic Element
};

#endif // GAME_TYPES_H
