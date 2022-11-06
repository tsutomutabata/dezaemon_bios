#ifndef _NERAI_ACTIVITY_H
#define _NERAI_ACTIVITY_H



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
	short	HighScore;
	short	GameOver;
	short	Counter;
} NeraiActivityWork;


short NeraiInit(NeraiActivityWork *aw);
short NeraiUpdate(NeraiActivityWork *aw);

#endif