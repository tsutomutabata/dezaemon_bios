#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "neraiActivity.h"


static short BlackPalette[] = { 0 };

short NeraiInit(NeraiActivityWork *aw){
	switch(aw->InitStep){
		case 0:
			cls();
			setMouseCursor(0);
			aw->Dma.Vram.Mode = 2;
			aw->Dma.Vram.VramAddress = 0x4000;
			aw->Dma.Vram.SourceAddr = 0x8000;
			aw->Dma.Vram.SourceBank = 0x88;		// sample graphic data bank #1
			aw->Dma.Vram.Size = 0x2000;
			aw->Dma.Vram.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 1:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 2:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0xa0;
			aw->Dma.CgRam.SourceAddr = 0x827e;	// player palette
			aw->Dma.CgRam.SourceBank = 0x8A;	// sample data bank #1
			aw->Dma.CgRam.Size = 32;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			aw->Addr = 0x827e;
			break;
		case 3:
			cls();
			aw->Dma.Vram.Mode = 2;
			aw->Dma.Vram.VramAddress = 0x5000;
			aw->Dma.Vram.SourceAddr = 0xd400;
			aw->Dma.Vram.SourceBank = 0x89;		// sample graphic data bank #2
			aw->Dma.Vram.Size = 0x2000;
			aw->Dma.Vram.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 4:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 5:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0xb0;
			aw->Dma.CgRam.SourceAddr = 0x827e;	// enemy stage #2
			aw->Dma.CgRam.SourceBank = 0x8a;	// sample data bank #1
			aw->Dma.CgRam.Size = 32;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 6:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 7:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0xc0;
			aw->Dma.CgRam.SourceAddr = 0x82de;	// palayer weapon
			aw->Dma.CgRam.SourceBank = 0x8a;	// sample data bank #1
			aw->Dma.CgRam.Size = 32;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 8:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 9:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0xd0;
			aw->Dma.CgRam.SourceAddr = 0x82be;	// explosion palette
			aw->Dma.CgRam.SourceBank = 0x8a;	// sample data bank #1
			aw->Dma.CgRam.Size = 32;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 10:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 11:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0x00;
			aw->Dma.CgRam.SourceAddr = (unsigned short)BlackPalette;
			aw->Dma.CgRam.SourceBank = 0x7e;
			aw->Dma.CgRam.Size = 2;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep = 99;
//			aw->InitStep = 20;
//			aw->Addr = 0x82be;
			break;
		case 20:{				// debug step
			unsigned short pad = readTriggerPad();
			unsigned short old = aw->Addr;
			hexPrint(2,2,3,aw->Addr);
			if(pad & PADUP) aw->Addr -= 0x400;
			if(pad & PADDOWN) aw->Addr += 0x400;
			if(pad & PADB){
				aw->InitStep = 99;
				testSpriteCharactor(0);
			}
			if(old != aw->Addr){
				aw->Dma.Vram.Mode = 2;
				aw->Dma.Vram.VramAddress = 0x5000;
				aw->Dma.Vram.SourceAddr = aw->Addr;
				aw->Dma.Vram.SourceBank = 0x89;		// sample graphic data bank #2
				aw->Dma.Vram.Size = 0x2000;
				aw->Dma.Vram.ZeroMark = 0;
				requestDma(&aw->Dma);
			}
			testSpriteCharactor(1);
			break;
		}
		case 99:
		testSpriteCharactor(0);
			return false;

	}
	return true;
}

static unsigned short MyShipSpriteData [] = {
	0x0400,0x0402,0x0420,0x0422,
	0x0404,0x0406,0x0424,0x0426,
	0x0408,0x040a,0x0428,0x042a
};

typedef struct {
	short	Hspd;
	short	Vspd;
	short	Counter;
} SpriteWork;

#define	PLAYER_IDX		(0)
#define SHOT_IDX		(1)
#define ENEMY_IDX		(10)

static void putPlayer(x,y){
	SpriteBuffer *sp;
	SpriteWork *sw;
	sp = getSpriteBuffer(0);
	sp->Motion = 0x20;
	sp->Pattern = 1;
	sp->Hpos = x;
	sp->Vpos = y;
	sp->Select = 1;
	sp->Flash = 0;
	sp->StructDataAddr = (unsigned short)MyShipSpriteData;
	sp->StructDataBank = 0x7e;
}

static unsigned short EnemySpriteData [] = {
	0x076a,0x076c,0x076e,0x476c
};

static void putEnemy(NeraiActivityWork *aw){
	SpriteBuffer *sp,*pl;
	SpriteWork *sw;
	long tmp;
	short i,appear = biosRand() % 3,angle;
	pl = getSpriteBuffer(PLAYER_IDX);
	sp = getSpriteBuffer(ENEMY_IDX);
	for(i = 0; i < SPRITE_ARRAY_LENGTH-ENEMY_IDX; i++,sp++){
		if(sp->Motion) continue;
		sp->Motion = 0x21;
		sp->Pattern = 0;
		switch(appear){
			case 0:		// 右辺
				sp->Hpos = 0x7fff;
				sp->Vpos = biosRand() % 0x6800;
				break;
			case 1:		// 上部
				sp->Hpos = biosRand() & 0x7fff;
				sp->Vpos = 0;
				break;
			case 2:		// 左辺
				sp->Hpos = 0;
				sp->Vpos = biosRand() % 0x6800;
				break;
		}
		sp->Select = 0;
		sp->Flash = 0;
		sp->StructDataAddr = (unsigned short)EnemySpriteData;
		sp->StructDataBank = 0x7e;
		sw = (SpriteWork *)sp->Work;
		angle = biosAngle((char)(sp->Hpos>>8),(char)(sp->Vpos>>8),(char)(pl->Hpos>>8),(char)(pl->Vpos>>8));
		biosHwMul32(biosCos(angle),aw->EnemySpeed,&tmp);
		sw->Hspd = (short)(tmp>>16);
		biosHwMul32(biosSin(angle),aw->EnemySpeed,&tmp);
		sw->Vspd = -(short)(tmp>>16);
		break;
	}
}

static unsigned short ShotSpriteData [] = {
	0x08ca,
};

static void putShot(x,y){
	SpriteBuffer *sp;
	SpriteWork *sw;
	short i,j,angle[] = {0x38,0x40,0x48};
	long tmp;
	for(i = 0; i < 3; i++){
		sp = getSpriteBuffer(SHOT_IDX + i + (i<<1));
		if(sp->Motion) continue;
		if((sp+1)->Motion) continue;
		if((sp+2)->Motion) continue;
		for(j = 0;j < 3; j++,sp++){
			sp->Motion = 0x22;
			sp->Pattern = 0;
			sp->Hpos = x;
			sp->Vpos = y;
			sp->Select = 0;
			sp->Flash = 0;
			sp->StructDataAddr = (unsigned short)ShotSpriteData;
			sp->StructDataBank = 0x7e;
			sw = (SpriteWork *)sp->Work;
			biosHwMul32(biosCos(angle[j]),0x800,&tmp);
			sw->Hspd = (short)(tmp>>16);
			biosHwMul32(biosSin(angle[j]),0x800,&tmp);
			sw->Vspd = -(short)(tmp>>16);
			requestSe(0x2a);
		}
		break;
	}
}

static unsigned short explosionSpriteData [] = {
	0x0aa0,0x0aa2,0x0aa4,0x0aa6,0x0aa8,0x0aaa,
};

static void putExplosion(SpriteBuffer *sp){
	SpriteWork *sw;
	sp->Motion = 0x23;
	sp->Pattern = 0;
	sp->Select = 0;
	sp->Flash = 0;
	sp->StructDataAddr = (unsigned short)explosionSpriteData;
	sp->StructDataBank = 0x7e;
	sw = (SpriteWork *)sp->Work;
	sw->Counter = 0;
}

static void playerMotion(SpriteBuffer *sp){
	unsigned short pad = readPad();
	SpriteWork *sw = (SpriteWork *)sp->Work;
	long tmp;
	short dir[] = {
		0x00,0x00,0x80,0x00,
		0x40,0x20,0x60,0x00,
		0xc0,0xe0,0xa0,0x00,
		0x00,0x00,0x00,0x00
	},key = 0;
	if(pad & PADB){
		if(sw->Counter == 0){
			putShot(sp->Hpos,sp->Vpos);
		}
		if(++sw->Counter > 3){
			sw->Counter = 0;
		}
	}else{
		sw->Counter = 0;
	}
	if(pad & PADRIGHT) key |= 1;
	if(pad & PADLEFT) key |= 2;
	if(pad & PADUP) key |= 4;
	if(pad & PADDOWN) key |= 8;
	if(key){
		biosHwMul32(biosCos(dir[key]),0x280,&tmp);		// Player の移動速度は 2.5 dot/int
		sp->Hpos += (short)(tmp>>16);
		biosHwMul32(biosSin(dir[key]),0x280,&tmp);
		sp->Vpos -= (short)(tmp>>16);
	}
	if(sp->Hpos > 0x7800) sp->Hpos = 0x7800;
	if(sp->Hpos < 0x0800) sp->Hpos = 0x0800;
	if(sp->Vpos > 0x6800) sp->Vpos = 0x6800;
	if(sp->Vpos < 0x1000) sp->Vpos = 0x1000;
}

static void enemyMotion(SpriteBuffer *sp,NeraiActivityWork *aw){
	SpriteBuffer *st;
	short i,tmp;
	SpriteWork *sw = (SpriteWork *)sp->Work;
	if(++sw->Counter > 4){
		sw->Counter = 0;
		if(++sp->Pattern >= 4){
			sp->Pattern = 0;
		}
	}
	sp->Hpos += sw->Hspd;
	sp->Vpos += sw->Vspd;

	if(sp->Hpos > 0x8800) sp->Motion = 0;
	if(sp->Hpos < -0x0400) sp->Motion = 0;
	if(sp->Vpos > 0x7400) sp->Motion = 0;
	if(sp->Vpos < -0x0400) sp->Motion = 0;	

	st = getSpriteBuffer(PLAYER_IDX);
	for(i = 0;i < 10; i++,st++){
		if(!st->Motion) continue;
		tmp = sp->Hpos - st->Hpos;
		if(tmp < 0) tmp = -tmp;
		if(tmp > 0x400) continue;
		tmp = sp->Vpos - st->Vpos;
		if(tmp < 0) tmp = -tmp;
		if(tmp > 0x400) continue;
		putExplosion(sp);
		if(i == 0){
			putExplosion(st);
			SFCIO_SET8(APUIO0,0xf0);		// BGM Stop
			requestSe(0x0d);
			aw->GameOver = 1;
		}else{
			aw->Score++;
			requestSe(0x21);
			st->Motion = 0;
		}
		break;
	}

}

static void shotMotion(SpriteBuffer *sp){
	SpriteWork *sw = (SpriteWork *)sp->Work;
	sp->Hpos += sw->Hspd;
	sp->Vpos += sw->Vspd;
	if(sp->Hpos > 0x9000) sp->Motion = 0;
	if(sp->Hpos < -0x1000) sp->Motion = 0;
	if(sp->Vpos > 0x7400) sp->Motion = 0;
	if(sp->Vpos < -0x0400) sp->Motion = 0;	
}

static void explosionMotion(SpriteBuffer *sp){
	SpriteWork *sw = (SpriteWork *)sp->Work;
	if(++sw->Counter > 2){
		sw->Counter = 0;
		if(++sp->Pattern >= 6){
			sp->Motion = 0;
		}
	}
}



static void motion(NeraiActivityWork *aw){
	SpriteBuffer *sp = getSpriteBuffer(0);
	int idx;
	for(idx = 0; idx < SPRITE_ARRAY_LENGTH; idx++,sp++){
		if(sp->Motion == 0) continue;
		switch(sp->Motion){
			case 0x20:
				playerMotion(sp);
				break;
			case 0x21:
				enemyMotion(sp,aw);
				break;
			case 0x22:
				shotMotion(sp);
				break;
			case 0x23:
				explosionMotion(sp);
				break;
		}
	}
}


short NeraiUpdate(NeraiActivityWork *aw){
	unsigned short pad = readTriggerPad();
	unsigned short old = aw->Addr,oldcg = aw->Cg;
	SpriteBuffer *sp;
	short i;
	if(pad & PADX){
		setMouseCursor(1);
		return false;
	}
	switch(aw->UpdateStep){
		case 0:
			cls();
			requestBgm(0xd0);
			sp = getSpriteBuffer(0);
			for(i < 0;i < SPRITE_ARRAY_LENGTH; i++,sp++) sp->Motion = 0;
			aw->EnemySpeed = 0x180;
			aw->AppearInterval = 0x80;
			print(14,8,"NERAI");
			print(8,14,"HIGH SCORE");
			print(10,18,"PRESS B BUTTON");
			bcdPrint(19,14,4,aw->Score);
			aw->UpdateStep++;
			return true;
		case 1:
			if(pad & PADB){
				cls();
				aw->UpdateStep++;
				aw->Counter = 0;
				SFCIO_SET8(APUIO0,0xf0);		// BGM Stop
				requestSe(0x37);
			}
			return true;
		case 2:
			if(++aw->Counter > 60){
				aw->UpdateStep = 10;
			}
			break;
		case 10:
			requestBgm(0xd1);
			aw->GameOver = 0;
			aw->Score = 0;
			putPlayer(0x4000,0x6000);
			aw->UpdateStep++;
			print(2,2,"SCORE");
			break;
		case 11:
			bcdPrint(8,2,4,aw->Score);
			aw->AppearTime += aw->AppearInterval;
			if(aw->AppearTime >= 0x1000){
				aw->AppearTime = 0;
				putEnemy(aw);
				if(aw->AppearInterval < 0x600 ){
					aw->AppearInterval += 4;
					aw->EnemySpeed += 1;
				}
			}
			if(aw->GameOver) aw->UpdateStep++;
			break;
		case 12:
			if(++aw->GameOver > 120){
				aw->UpdateStep++;
				requestBgm(0xdc);
				print(12,12,"GAME OVER");
			}
			break;
		case 13:
			if(++aw->GameOver > 300) aw->UpdateStep++;
			return true;
		case 14:
			if(aw->Score > aw->HighScore) aw->HighScore = aw->Score;
			aw->UpdateStep = 0;
			return true;
	}
	motion(aw);

	return true;
}

