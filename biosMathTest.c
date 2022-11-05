#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "biosMathTest.h"


short BiosMathTestInit(BiosMathTestActivityWork *aw){
	cls();
	print(2,2,"MATH TEST");

	print(4,4,"ANGLE    SIN      COS");
	print(4,5,"START  X");
	print(4,6,"START  Y");
	print(4,7,"TARGET X");
	print(4,8,"TARGET Y      ARC TAN");
	print(4,9,"MUL A");
	print(4,10,"MUL B      ANS");
	print(4,11,"DIV A");
	print(4,12,"DIV B      ANS");

	print(1,26,"PRESS X BUTTON TO SPECIAL MENU");
	aw->DivB = 1;
	return false;
}

short BiosMathTestUpdate(BiosMathTestActivityWork *aw){
	unsigned short padTr = readTriggerPad();
	unsigned short pad = readPad();
	long mul;

	print(2,4+aw->Sel," ");
	if(padTr & PADUP && aw->Sel > 0) aw->Sel--;
	if(padTr & PADDOWN && aw->Sel < 8) aw->Sel++;

	switch(aw->Sel){
		case 0:
			if(pad & PADLEFT) aw->Angle--;
			if(pad & PADRIGHT) aw->Angle++;
			break;
		case 1:
			if(pad & PADLEFT) aw->Sx--;
			if(pad & PADRIGHT) aw->Sx++;
			break;
		case 2:
			if(pad & PADLEFT) aw->Sy--;
			if(pad & PADRIGHT) aw->Sy++;
			break;
		case 3:
			if(pad & PADLEFT) aw->Tx--;
			if(pad & PADRIGHT) aw->Tx++;
			break;
		case 4:
			if(pad & PADLEFT) aw->Ty--;
			if(pad & PADRIGHT) aw->Ty++;
			break;
		case 5:
			if(pad & PADLEFT) aw->MulA--;
			if(pad & PADRIGHT) aw->MulA++;
			break;
		case 6:
			if(pad & PADLEFT) aw->MulB--;
			if(pad & PADRIGHT) aw->MulB++;
			break;
		case 7:
			if(pad & PADLEFT) aw->DivA--;
			if(pad & PADRIGHT) aw->DivA++;
			break;
		case 8:
			if(padTr & PADLEFT) aw->DivB--;
			if(padTr & PADRIGHT) aw->DivB++;
			break;
	}

	hexPrint(10,4,1,aw->Angle);
	hexPrint(17,4,3,biosSin(aw->Angle));
	hexPrint(26,4,3,biosCos(aw->Angle));

	hexPrint(13,5,3,aw->Sx);
	hexPrint(13,6,3,aw->Sy);
	hexPrint(13,7,3,aw->Tx);
	hexPrint(13,8,3,aw->Ty);
	hexPrint(26,8,1,biosAngle(aw->Sx,aw->Sy,aw->Tx,aw->Ty));

	biosHwMul32(aw->MulA,aw->MulB,&mul);
	hexPrint(10,9,3,aw->MulA);
	hexPrint(10,10,3,aw->MulB);
	hexPrint(19,10,7,mul);

	hexPrint(10,11,3,aw->DivA);
	hexPrint(10,12,1,aw->DivB);
	hexPrint(19,12,3,biosHwDiv16(aw->DivA,aw->DivB));

	print(2,4+aw->Sel,"*");

	if(padTr & PADX){
		return false;
	}
	return true;
}

