#ifndef _SPRITE_TEST_ACTIVITY_H
#define _SPRITE_TEST_ACTIVITY_H

typedef struct {
	short InitStep;
	short spriteIdx;
	DmaRequest dma;
	unsigned char spChTest;
} SpriteTestActivityWork;

short SpriteTestInit(SpriteTestActivityWork *aw);
short SpriteTestUpdate(SpriteTestActivityWork *aw);

#endif