#ifndef _BIOS_MATH_TEST_ACTIVITY_H
#define _BIOS_MATH_TEST_ACTIVITY_H

typedef struct {
	short Angle;
	short Sx,Sy,Tx,Ty;
	short MulA,MulB;
	short DivA,DivB;
	short Sel;
} BiosMathTestActivityWork;

short BiosMathTestInit(BiosMathTestActivityWork *aw);
short BiosMathTestUpdate(BiosMathTestActivityWork *aw);

#endif