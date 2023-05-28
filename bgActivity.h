#ifndef _BG_ACTIVITY_H
#define _BG_ACTIVITY_H

typedef struct {
	unsigned char Size;
	unsigned short Addr;
} HdmaTable;

typedef struct {
	short	InitStep;
	short	UpdateStep;
	DmaRequest Dma;
	unsigned short TileBuffer[2][32*32];
	short	DispBg;
	short	Hpos;
	short	Vpos;
	short	Mode;
	short	Gain;
	short	Angle;
	short	AngularVelocity;
	HdmaTable	HdmaCommand[5];
	unsigned short HdmaBuff[224];
} BgActivityWork;


short BgInit(BgActivityWork *aw);
short BgUpdate(BgActivityWork *aw);

#endif