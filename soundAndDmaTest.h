#ifndef _SOUND_AND_DMA_TEST_ACTIVITY_H
#define _SOUND_AND_DMA_TEST_ACTIVITY_H

typedef struct {
	short font;
	DmaRequest dma;
} DmaTestActivityWork;

short DmaTestInit(DmaTestActivityWork *aw);
short DmaTestUpdate(DmaTestActivityWork *aw);


typedef struct {
	short	bgm;
	short	se;
	short	cur;
} SoundTestActivityWork;

short SoundTestInit(SoundTestActivityWork *aw);
short SoundTestUpdate(SoundTestActivityWork *aw);


#endif