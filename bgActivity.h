#ifndef _BG_ACTIVITY_H
#define _BG_ACTIVITY_H



typedef struct {
	short	InitStep;
	short	UpdateStep;
	DmaRequest Dma;
	unsigned short TileBuffer[2][32*32];
	short	DispBg;
	short	Hpos;
	short	Vpos;
} BgActivityWork;


short BgInit(BgActivityWork *aw);
short BgUpdate(BgActivityWork *aw);

#endif