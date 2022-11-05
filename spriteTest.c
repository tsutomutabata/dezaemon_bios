#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "spriteTest.h"




unsigned short playerPalette [] = {
	0x0120,0x0000,0x3188,0x56B3,0x7BDE,0x02C0,0x2BE3,0x000F,
	0x1139,0x3E9F,0x5523,0x724B,0x7F76,0x0210,0x2B39,0x67FF
};

short SpriteTestInit(SpriteTestActivityWork *aw){

	switch(aw->InitStep){
		case 0:
			cls();
			print(2,2,"SPRITE TEST");
			hexPrint(2,4,7,(unsigned long)aw);
			print(0,22,"PRESS B BUTTON TO ADD SPRITE");
			print(0,24,"PRESS A BUTTON TO CHARACTOR TEST");
			print(0,26,"PRESS X BUTTON TO SPECIAL MENU");
			setMouseCursor(0);
			aw->spriteIdx = 0;

			aw->dma.Vram.Mode = 2;
			aw->dma.Vram.VramAddress = 0x4000;
			aw->dma.Vram.SourceAddr = 0x8000;
			aw->dma.Vram.SourceBank = 0x88;		// sample graphic data bank #1
			aw->dma.Vram.Size = 4096;
			aw->dma.Vram.ZeroMark = 0;
			requestDma(&aw->dma);
			aw->InitStep = 1;
			break;
		case 1:
			if(!isDmaBusy()) aw->InitStep = 2;
			break;
		case 2:
			aw->dma.CgRam.Mode = 3;
			aw->dma.CgRam.CgAddress = 0xf0;
			aw->dma.CgRam.SourceAddr = (unsigned short)playerPalette;
			aw->dma.CgRam.SourceBank = 0x7e; // (unsigned char)((unsigned long)playerPalette>>16);
			aw->dma.CgRam.Size = 32;
			aw->dma.CgRam.ZeroMark = 0;
			requestDma(&aw->dma);
			return false;
	}
	return true;
}


unsigned short MyShipSpriteData [] = {
	0x3e00,0x3e02,0x3e20,0x3e22,
	0x3e04,0x3e06,0x3e24,0x3e26,
	0x3e08,0x3e0a,0x3e28,0x3e2a
};

typedef struct _SpriteWork {
	short	Hspd;
	short	Vspd;
} SpriteWork;

void putPlayer(x,y,idx){
	SpriteBuffer *sp;
	SpriteWork *sw;
	if(idx < 0 || idx >= SPRITE_ARRAY_LENGTH) return;
	sp = getSpriteBuffer(idx);
	sp->Motion = 0x20;
	sp->Pattern = 1;
	sp->Hpos = x;
	sp->Vpos = y;
	sp->Select = 1;
	sp->Flash = 0;
	sp->StructDataAddr = (unsigned short)MyShipSpriteData;
	sp->StructDataBank = 0x7e; // (unsigned char)((unsigned long)MyShipSpriteData>>16);
	sw = (SpriteWork *)sp->Work;
	sw->Hspd = 0x80 - (biosRand() & 0xff);
	sw->Vspd = 0x80 - (biosRand() & 0xff);
}

void motion(){
	SpriteBuffer *sp = getSpriteBuffer(0);
	SpriteWork *sw;
	short i;
	for(i = 0; i < SPRITE_ARRAY_LENGTH; i++,sp++){
		if(!sp->Motion) continue;
		sw = (SpriteWork *)sp->Work;
		sp->Hpos += sw->Hspd;
		sp->Vpos += sw->Vspd;
		if(sp->Hpos > 0x7800){
			sp->Hpos = 0x77ff;
			sw->Hspd = -sw->Hspd;
		}
		if(sp->Hpos < 0x800){
			sp->Hpos = 0x800;
			sw->Hspd = -sw->Hspd;
		}
		if(sp->Vpos > 0x7000){
			sp->Vpos = 0x6fff;
			sw->Vspd = -sw->Vspd;
		}
		if(sp->Vpos < 0){
			sp->Vpos = 0;
			sw->Vspd = -sw->Vspd;
		}
	}
}


short SpriteTestUpdate(SpriteTestActivityWork *aw){
	unsigned short pad = readTriggerPad();

	if(pad & PADB){
		putPlayer(biosRand()&0x7fff,biosRand()&0x7fff,aw->spriteIdx++);
		if(aw->spriteIdx >= SPRITE_ARRAY_LENGTH)
			aw->spriteIdx = 0;
	}

	if(pad & PADA){
		aw->spChTest ^= 1;
		testSpriteCharactor(aw->spChTest);
	}

	motion();

	if(pad & PADX){
		testSpriteCharactor(0);
		setMouseCursor(1);
		return false;
	}
	return true;
}
