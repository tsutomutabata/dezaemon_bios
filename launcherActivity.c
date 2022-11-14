#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "launcherActivity.h"
#include "soundAndDmaTest.h"
#include "spriteTest.h"
#include "biosMathTest.h"
#include "kakushi.h"
#include "swatchinNeraiActivity.h"

short LauncherInit(LauncherActivityWork *aw){
	cls();
	print(2,2,"LAUNCHER MENU");
	print(1,24,"PRESS B BUTTON TO LAUNCH");
	print(1,26,"PRESS X BUTTON TO SPECIAL MENU");

	print(4,4,"SOUND TEST");
	aw->Menu[0].InitAddr = SoundTestInit;
	aw->Menu[0].UpdateAddr = SoundTestUpdate;
	print(4,5,"DMA TEST");
	aw->Menu[1].InitAddr = DmaTestInit;
	aw->Menu[1].UpdateAddr = DmaTestUpdate;
	print(4,6,"SPRITE TEST");
	aw->Menu[2].InitAddr = SpriteTestInit;
	aw->Menu[2].UpdateAddr = SpriteTestUpdate;
	print(4,7,"MATH TEST");
	aw->Menu[3].InitAddr = BiosMathTestInit;
	aw->Menu[3].UpdateAddr = BiosMathTestUpdate;
	print(4,9,"KAKUSHI");
	aw->Menu[5].InitAddr = KakushiInit;
	aw->Menu[5].UpdateAddr = KakushiUpdate;
	print(4,10,"DEZA SWATCH IN NERAI");
	aw->Menu[6].InitAddr = SwatchinNeraiInit;
	aw->Menu[6].UpdateAddr = SwatchinNeraiUpdate;
	return false;
}

short LauncherUpdate(LauncherActivityWork *aw){
	unsigned short pad = readTriggerPad();

	print(2,aw->Select + 4," ");

	if(pad & PADUP && aw->Select > 0) aw->Select--;
	if(pad & PADDOWN && aw->Select < 6) aw->Select++;
	if(pad & PADB){
		NextActivity(aw->Menu[aw->Select].InitAddr,aw->Menu[aw->Select].UpdateAddr);
		return true;
	}

	print(2,aw->Select + 4,"*");
	if(pad & PADX){
		return false;
	}
	return true;
}

