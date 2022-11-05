#ifndef _BASE_ACTIVITY_H
#define _BASE_ACTIVITY_H



typedef union {
	short		Step;
	short		Count;
} BaseActivityWork;

void NextActivity(void *init,void *update);

short Init(BaseActivityWork *aw);		// BaseActivityWork は 65536Bytes のワークメモリを提供
short Update(BaseActivityWork *aw);


#endif