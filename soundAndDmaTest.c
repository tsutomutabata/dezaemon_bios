#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "soundAndDmaTest.h"


short DmaTestInit(DmaTestActivityWork *aw){
	cls();
	print(2,2,"DMA TEST");

	print(12,14,"FONT SELECT");
	print(8,16,"!\"()*+,-./0123456789");
	print(3,18,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	print(1,23,"PRESS LEFT OR RIGHT KEY");
	print(1,24,"TO SELECT");
	print(1,26,"PRESS X BUTTON TO SPECIAL MENU");
	return false;
}

short DmaTestUpdate(DmaTestActivityWork *aw){
	unsigned short pad = readTriggerPad();
	unsigned char *p;
	int i,x,y;
	if(pad & PADLEFT && aw->font > 0) aw->font--;
	if(pad & PADRIGHT && aw->font < 6) aw->font++;
	if(pad & (PADLEFT|PADRIGHT)){
		aw->dma.Vram.Mode = 2;
		aw->dma.Vram.VramAddress = 0x6000;
		aw->dma.Vram.Size = 4096;
		aw->dma.Vram.ZeroMark = 0;
		switch(aw->font){
			case 0:
				aw->dma.Vram.SourceAddr = MAIN_ASC_FNT;
				aw->dma.Vram.SourceBank = MAIN_ASC_FNT>>16;
				break;
			case 1:
				aw->dma.Vram.SourceAddr = NORMAL_ASC_FNT;
				aw->dma.Vram.SourceBank = NORMAL_ASC_FNT>>16;
				break;
			case 2:
				aw->dma.Vram.SourceAddr = OCR_ASC_FNT;
				aw->dma.Vram.SourceBank = OCR_ASC_FNT>>16;
				break;
			case 3:
				aw->dma.Vram.SourceAddr = NAMCO_ASC_FNT;
				aw->dma.Vram.SourceBank = NAMCO_ASC_FNT>>16;
				break;
			case 4:
				aw->dma.Vram.SourceAddr = FUT_ASC_FNT;
				aw->dma.Vram.SourceBank = FUT_ASC_FNT>>16;
				break;
			case 5:
				aw->dma.Vram.SourceAddr = D70_ASC_FNT;
				aw->dma.Vram.SourceBank = D70_ASC_FNT>>16;
				break;
			case 6:
				aw->dma.Vram.SourceAddr = ITA_ASC_FNT;
				aw->dma.Vram.SourceBank = ITA_ASC_FNT>>16;
				break;
		}
		if(!isDmaBusy()) requestDma(&aw->dma);
	}
	if(isDmaBusy()){
		print(5,20,"DMA BUSY");
	}else{
		print(5,20,"        ");
	}

	if(pad & PADX){
		return false;
	}
	return true;
}






short SoundTestInit(SoundTestActivityWork *aw){
	cls();
	print(2,2,"SOUND TEST");
	print(4,4,"BGM");
	print(4,5,"SE ");
	print(1,24,"PRESS B BUTTON TO PLAY");
	print(1,26,"PRESS X BUTTON TO SPECIAL MENU");
	setUserMode(0);
	aw->bgm = 0xd0;
	return false;
}


short SoundTestUpdate(SoundTestActivityWork *aw){
	unsigned short pad = readTriggerPad();

	print(3,4," ");
	print(3,5," ");
	print(3,4+aw->cur,"*");
	hexPrint(8,4,1,aw->bgm);
	hexPrint(8,5,1,aw->se);



	if(pad & PADUP){
		aw->cur = 0;
	}
	if(pad & PADDOWN){
		aw->cur = 1;
	}
	switch(aw->cur){
		case 0:
			if(pad & PADLEFT && aw->bgm > 0) aw->bgm--;
			if(pad & PADRIGHT && aw->bgm < 0xff) aw->bgm++;
			if(pad & PADB) requestBgm(aw->bgm);
			break;
		case 1:
			if(pad & PADLEFT && aw->se > 0) aw->se--;
			if(pad & PADRIGHT && aw->se < 0xff) aw->se++;
			if(pad & PADB) requestSe(aw->se);
			break;
	}

	if(pad & PADX){
		return false;
	}
	return true;
}