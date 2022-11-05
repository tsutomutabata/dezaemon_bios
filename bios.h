#ifndef _BIOS_H
#define _BIOS_H

#define false (0)
#define true (!false)

void print(short x,short y,char *msg);
void cls();
void hexPrint(short x,short y,short digit,long value);
void bcdPrint(short x,short y,short digit,long value);

/***********************************************************************
;			<< BGM request >>
;
; < Request number >
;
; $00-$0f : 使用禁止（動作保証無し。）
; $10-$15 : STAGE BGM
; $16-$1b : BOSS BGM
; $1c	  : TITLE
; $1d	  : GAME OVER
; $1e	  : ENDING
; $1f	  : STAGE CLEAR
;
; Bit7=0  : Fade out and BGM request
; Bit7=1  : BGM request only
;
; Bit6=0  : Request table reference
; Bit6=1  : Direct request
;
; < 仕様 >
; Bit7=0の時は、演奏要求を受けると直ちにFade outを開始し、
; 音量が0になりしだい演奏Dataを転送し演奏を開始する。
;
; USERとSAMPLEの判断はWORK.X65にある'USER_MODE'で切替をしてください。
; USER_MODE = 0  ==> SAMPLE(ROM)のBGM reruest table を参照
; USER_MODE = 1  ==> USER(S-RAM)のBGM reruest table を参照
;
; Bit6=1の時は、request tableを参照せず内部のRequest numberを使用。
;
; 内部のRequest numberは0-$fがS-RAM,$10-$1fがROM側です。
***********************************************************************/
void setUserMode(short mode);
void requestBgm(short reqestNumber);
void requestSe(short reqestNumber);

typedef struct _dmaRequestVram {
  	unsigned char	Mode;			// Always 2 : Rom to Vram
	unsigned short	VramAddress;	// VRAM address
	unsigned short	SourceAddr;	// Source address
	unsigned char	SourceBank;   // Source bank
	unsigned short	Size;		// Transfar size
	unsigned char	ZeroMark;		// Always 0
} DmaRequestVram;

typedef struct _dmaRequestCgRam {
  	unsigned char	Mode;			// Always 3 : Rom to CgRam
	unsigned char	CgAddress;	// CG address
	unsigned short	SourceAddr;	// Source address
	unsigned char	SourceBank;   // Source bank
	unsigned short	Size;		// Transfar size
	unsigned char	ZeroMark;		// Always 0
} DmaRequestCgRam;

typedef struct _dmaRequestVramClean {
  	unsigned char	Mode;			// Always 4 : V ram clean
	unsigned short	VramAddress;	// VRAM address
	unsigned short	Size;		// Transfar size
	unsigned char	ZeroMark;		// Always 0
} DmaRequestVramClean;

typedef union _dmaRequest {
	DmaRequestVram		Vram;
	DmaRequestCgRam		CgRam;
	DmaRequestVramClean	Clean;
} DmaRequest;

void requestDma(DmaRequest *tbl);		// DmaRequest はローカル変数で渡さない（グローバル変数で用意すること）
unsigned char isDmaBusy();

typedef struct _SpriteBuffer {	// buffer size 0x40
	unsigned char 	Motion;
	unsigned char 	Pattern;
	short			Hpos; 
	short			Vpos;
	unsigned char 	Select;		// 0: 16x16 1:32x32 2:48x48 3 64x64 4: 128x128 5: 32x16 6: 16x32
	unsigned char 	Flash;		// 0x0e Flush after write
	unsigned short	StructDataAddr;
	unsigned char 	StructDataBank;
	unsigned char	Work[0x35];
} SpriteBuffer;

void testSpriteCharactor(unsigned char isTest);
SpriteBuffer* getSpriteBuffer(short idx);
#define	SPRITE_ARRAY_LENGTH	(0x40)

unsigned short readTriggerPad();
unsigned short readPad();
unsigned short readMouseX();
unsigned short readMouseY();
unsigned short readMouseTriggerButton();
unsigned short readMouseButton();
void setMouseCursor(unsigned char mode);


unsigned short biosRand();
short biosSin(unsigned short hexDegree);		// hexDegree : 0x00 -> 0,  0x40 -> 90,  0x80 -> 180,  0xc0 -> 270
short biosCos(unsigned short hexDegree);
short biosAngle(short x,short y,short tx,short ty);	// x,y -> tx,ty -> arcTan() -> return to hexDegree
void biosHwMul32(short a,short b,long *ans);	// Hard ware multiplier a(16bit) * b(16bit) => ans(32bit)
short biosHwDiv16(short a,short b);				// Hard ware divider a(16bit) / b(8bit) => return (16bit)

#endif