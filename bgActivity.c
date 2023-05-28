#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "bgActivity.h"



short BgInit(BgActivityWork *aw){
	short x,y;
	switch(aw->InitStep){
		case 0:
			cls();
			setMouseCursor(0);
			print(2,2,"BG TEST");
			print(0,20,"PRESS Y TO HDMA MODE");
			print(0,22,"PRESS ARROW KEY TO SCROLL");
			print(0,24,"PRESS A BUTTON TO BG ENABLE CHANGE");
			print(0,26,"PRESS X BUTTON TO SPECIAL MENU");

			SFCIO_SET8(BGMODE,0x39);		// GB MODE 1 Tile BG1/2 16x16 BG3 8x8 and High Priotity
			SFCIO_SET8(BG12NBA,0x20);		// BG Image address BG1 0000 BG2 2000
			SFCIO_SET8(BG1SC,0x68);			// BG1 Tile size 32x32 address BG1 6800
			SFCIO_SET8(BG2SC,0x70);			// BG2 Tile size 32x32 address BG2 7000
			aw->Dma.Vram.Mode = 2;
			aw->Dma.Vram.VramAddress = 0x0000;
			aw->Dma.Vram.SourceAddr = 0x0000;
			aw->Dma.Vram.SourceBank = 0x72;		// s-ram graphic data top
			aw->Dma.Vram.Size = 0x8000;
			aw->Dma.Vram.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 1:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 2:
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0x10;
			aw->Dma.CgRam.SourceAddr = 0x0040;	// s-ram PALETTE24
			aw->Dma.CgRam.SourceBank = 0x70;	// s-ram bank #0
			aw->Dma.CgRam.Size = 32;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 3:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 4:
			for(y = 0; y < 16; y++){
				for(x = 0; x < 16; x++){
					aw->TileBuffer[0][y*32+x] = y*64 + ((x&7) << 1) + ((x&8) << 2) | (0x400 * 1);
					aw->TileBuffer[1][y*32+x] = y*64 + ((x&7) << 1) + ((x&8) << 2) | (0x400 * 1);
				}
			}
			aw->Dma.Vram.Mode = 2;
			aw->Dma.Vram.VramAddress = 0x6800;
			aw->Dma.Vram.SourceAddr = (unsigned short)((unsigned long)&aw->TileBuffer[0][0] & 0xffff);
			aw->Dma.Vram.SourceBank = 0x7f;		// Activity work ram bank
			aw->Dma.Vram.Size = 0x800;
			aw->Dma.Vram.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 5:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 6:
			aw->Dma.Vram.Mode = 2;
			aw->Dma.Vram.VramAddress = 0x7000;
			aw->Dma.Vram.SourceAddr = (unsigned short)((unsigned long)&aw->TileBuffer[1][0] & 0xffff);
			aw->Dma.Vram.SourceBank = 0x7f;		// Activity work ram bank
			aw->Dma.Vram.Size = 0x800;
			aw->Dma.Vram.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 7:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 8:		// 抜き色が緑になるので黒くする。
			aw->Dma.CgRam.Mode = 3;
			aw->Dma.CgRam.CgAddress = 0x00;
			aw->Dma.CgRam.SourceAddr = 0x0040;	// s-ram PALETTE24
			aw->Dma.CgRam.SourceBank = 0x70;	// s-ram bank #0
			aw->Dma.CgRam.Size = 2;
			aw->Dma.CgRam.ZeroMark = 0;
			requestDma(&aw->Dma);
			aw->InitStep++;
			break;
		case 9:
			if(!isDmaBusy()) aw->InitStep++;
			break;
		case 10:	// H-DMA Setup
			aw->HdmaCommand[0].Size = 0x80 + 64;
			aw->HdmaCommand[0].Addr = (unsigned short)((unsigned long)&aw->HdmaBuff[0] & 0xffff);
			aw->HdmaCommand[1].Size = 0x80 + 64;
			aw->HdmaCommand[1].Addr = (unsigned short)((unsigned long)&aw->HdmaBuff[64] & 0xffff);
			aw->HdmaCommand[2].Size = 0x80 + 64;
			aw->HdmaCommand[2].Addr = (unsigned short)((unsigned long)&aw->HdmaBuff[128] & 0xffff);
			aw->HdmaCommand[3].Size = 0x80 + 32;
			aw->HdmaCommand[3].Addr = (unsigned short)((unsigned long)&aw->HdmaBuff[192] & 0xffff);
			aw->HdmaCommand[4].Size = 0;
			aw->HdmaCommand[4].Addr = 0;
			SFCIO_SET16(ATBLADD1,(unsigned short)((unsigned long)aw->HdmaCommand & 0xffff));
			SFCIO_SET8(ATBLBNK1,0x7f);		// Activity work ram bank
			SFCIO_SET8(DTBNK1,0x7f);		// Activity work ram bank
			SFCIO_SET8(BBUSADD1,BG1HOFS & 0xff);
			SFCIO_SET8(DMAMOD1,0x42);		// Indirect and incliment 2 byte trans mode
			*((unsigned char *)HDMASWITCH) = 0;
			aw->Gain = 0x80;
			aw->AngularVelocity = 0x200;
			aw->InitStep++;
			break;
		case 11:
			SFCIO_SET8(TM,0x15);				// Enable disp BG1,BG3 and Obj
			aw->DispBg = 1;
			aw->Hpos = 0;
			aw->Vpos = 0;
			return false;

	}
	return true;
}

short BgUpdate(BgActivityWork *aw){
	unsigned short padT = readTriggerPad();
	unsigned short pad = readPad();
	short TmpAngle,TmpVal,TmpPos;
	short i;
	unsigned short *p;
	long mul;
	if(padT & PADX){
		SFCIO_SET8(TM,0x14);				// Enable disp BG3 and Obj
		setMouseCursor(1);
		return false;
	}
	if(padT & PADY){
		aw->Mode++;
		aw->Mode &= 1;
		print(0,3,"             ");
		print(0,4,"             ");
		print(0,5,"             ");
		print(0,6,"             ");
		if(aw->Mode){
			print(2,3,"HDMA MODE");
			print(3,4,   "GAIN");
			print(2,5,  "ANGLE");
			print(0,6,"VELOCTY");
		}
	}
	if(aw->Mode == 0){
		*((unsigned char *)HDMASWITCH) = 0;	// Disable HDMA
		switch(aw->DispBg){
			case 0: 
				print(2,3,"     "); 
				break;
			case 1: 
				print(2,3,"BG1  "); 
				break;
			case 2: 
				print(2,3,"BG2  "); 
				break;
			case 3: 
				print(2,3,"BG1/2"); 
				break;
		}

		if(padT & PADA){
			aw->DispBg++;
			aw->DispBg &= 3;
			SFCIO_SET8(TM,0x14 | aw->DispBg);
		}
		if(pad & PADRIGHT){
			aw->Hpos++;
		}
		if(pad & PADLEFT){
			aw->Hpos--;
		}
		if(pad & PADUP){
			aw->Vpos--;
		}
		if(pad & PADDOWN){
			aw->Vpos++;
		}
		*(short *)BG1HBUFF = aw->Hpos;
		*(short *)BG2HBUFF = aw->Hpos >> 1;
		*(short *)BG1VBUFF = aw->Vpos;
		*(short *)BG2VBUFF = aw->Vpos >> 1;
	}else{
		SFCIO_SET8(TM,0x15);
		aw->DispBg = 1;
		*((unsigned char *)HDMASWITCH) = 2;	// Enable CH1 HDMA
		hexPrint(8,4,3,aw->Gain);
		hexPrint(8,5,3,aw->Angle);
		hexPrint(8,6,3,aw->AngularVelocity);
		if(pad & PADRIGHT){
			aw->Gain++;
		}
		if(pad & PADLEFT){
			aw->Gain--;
		}
		if(pad & PADUP){
			aw->Angle+=0x100;
		}
		if(pad & PADDOWN){
			aw->Angle-=0x100;
		}
		if(pad & PADL){
			aw->AngularVelocity++;
		}
		if(pad & PADR){
			aw->AngularVelocity--;
		}
		TmpAngle = aw->Angle;
		p = aw->HdmaBuff;
		for(i = 0; i < 224; i++){
			TmpVal = biosSin(TmpAngle >> 8);
			biosHwMul32(TmpVal,aw->Gain,&mul);
			*p++ = mul >> 16;
			TmpAngle += aw->AngularVelocity;
		}
	}
	return true;
}

