#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"

void setUserMode(short mode){
	*((unsigned char *)USER_MODE) = mode;
}

void requestBgm(short reqestNumber){
	*((unsigned char *)GAME_BGM) = reqestNumber;
}

unsigned char isDmaBusy(){
	return *((unsigned char *)DMABUSY);
}

void testSpriteCharactor(unsigned char isTest){
	*((unsigned char *)SPCHRTEST) = isTest;
}

SpriteBuffer* getSpriteBuffer(short idx){
	return (SpriteBuffer*)(SPBUFF + (idx<<6));
}

void setMouseCursor(unsigned char mode){
	*((unsigned char *)MOUSECURSOR) = mode; 
}

