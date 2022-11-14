/*
  custom hiroomin (The miniGame NERAI function is: tsutomutabata/dezaemon_bios )  */
  
#ifndef _SWAXHINNERAI_ACTIVITY_H
#define _SWAXHINNERAI_ACTIVITY_H

typedef struct {
	short	InitStep;
	short	UpdateStep;
	DmaRequest Dma;
	unsigned short Addr;
	unsigned short Cg;
	short	EnemySpeed;
	short	AppearTime;
	short	AppearInterval;
	short	Score;
	short	Second;
	short	HighScore;
	short	GameOver;
	short	Counter;
} SwatchinNeraiActivityWork;

short SwatchinNeraiInit(SwatchinNeraiActivityWork *aw);
short SwatchinNeraiUpdate(SwatchinNeraiActivityWork *aw);

#endif