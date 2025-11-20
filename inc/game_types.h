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
