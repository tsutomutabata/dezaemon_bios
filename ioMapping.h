//  --------------------
//		I/O Access macro
//  --------------------
#define SFCIO_GET8(addr)		*((volatile unsigned char *)(addr))
#define SFCIO_SET8(addr,data)	*((volatile unsigned char *)(addr)) = (data)
#define SFCIO_GET16(addr)		*((volatile unsigned short *)(addr))
#define SFCIO_SET16(addr,data)	*((volatile unsigned short *)(addr)) = (data)

//  --------------------
//  	PPU REGISTERS
//  --------------------
#define	INIDISP		0x2100	//  INITIALIZE DISPLAY
#define	OBJSEL		0x2101	//  OBJECT MODE SET
#define	OAMADD		0x2102	//  OAM ACCESS ADDRESS
#define	OAMDATA		0x2104	//  OAM WRITE DATA
#define	BGMODE		0x2105	//  BG MODE SET
#define	MOZAIKU		0x2106	//  MOZAIKU SET
#define	BG1SC		0x2107	//  {
#define	BG2SC		0x2108	//  BG SC DATA ADDRESS AND SIZE
#define	BG3SC		0x2109	//  	(MODE 0-6)
#define	BG4SC		0x210A	//  }
#define	BG12NBA		0x210B	//  {BG CHARACTER DATA AREA
#define	BG34NBA		0x210C	//  }
#define	BG1HOFS		0x210D	//  BG 1 H OFFSET
#define	BG1VOFS		0x210E	//  BG 1 V OFFSET
#define	BG2HOFS		0x210F	//  BG 2 H OFFSET
#define	BG2VOFS		0x2110	//  BG 2 V OFFSET
#define	BG3HOFS		0x2111	//  BG 3 H OFFSET
#define	BG3VOFS		0x2112	//  BG 3 V OFFSET
#define	BG4HOFS		0x2113	//  BG 4 H OFFSET
#define	BG4VOFS		0x2114	//  BG 4 V OFFSET
#define	VMAINC		0x2115	//  VRAM ADDRESS INCREMENT
#define	VMADD		0x2116	//  VRAM READ/WRITE ADDRESS
#define	VMDATA		0x2118	//  VRAM WRITE DATA
#define	M7SEL		0x211A	//  MODE 7 SET
#define	M7A			0x211B	//  {
#define	M7B			0x211C	//  MODE 7 PARAMATERS
#define	M7C			0x211D	//  
#define	M7D			0x211E	//  
#define	M7X			0x211F	//  
#define	M7Y			0x2120	//  }
#define	CGADD		0x2121	//  CGRAM WRITE ADDRESS
#define	CGDATA		0x2122	//  CGRAM WRITE DATA
#define	W12SEL		0x2123	//  {
#define	W34SEL		0x2124	//  WINDOW MASK SET
#define	WOBJSEL		0x2125	//  }
#define	WH0			0x2126	//  {
#define	WH1			0x2127	//  WINDOW POSITION
#define	WH2			0x2128	//  
#define	WH3			0x2129	//  }
#define	WBGLOG		0x212A	//  {WINDOW MASK LOGIC
#define	WOBJLOG		0x212B	//  }
#define	TM			0x212C	//  THTOUGH MAIN SCREEN
#define	TS			0x212D	//  THROUGH SUB SCREEN
#define	TMW			0x212E	//  WINDOW MASK SET OF THROUGH MAIN
#define	TSW			0x212F	//  WINDOW MASK SET OF THROUGH SUB
#define	CGSWSEL		0x2130	//  
#define	CGADDSUB	0x2131	//  
#define	COLDATA		0x2132	//  
#define	SETINI		0x2133	//  INITIALIZE SCREEN
#define	RDMPY1L		0x2134	//  {
#define	RDMPY1M		0x2135	//  RESULT OF MULTIPLICATION
#define	RDMPY1H		0x2136	//  }
#define	RDSLHV		0x2137	//  SOFT LATCH FOR H,V COUNTER
#define	RDOAMDATA	0x2138	//  OAM READ DATA
#define	RDVMDATA	0x2139	//  VRAM READ DATA
#define	RDCGDATA	0x213B	//  CGRAM READ DATA
#define	RDOPHCT		0x213C	//  OUTPUT DATA OF H COUNTER
#define	RDOPVCT		0x213D	//  OUTPUT DATA OF V COUNTER
#define	RDSTAT77	0x213E	//  STATUS OF 5C77
#define	RDSTAT78	0x213F	//  STATUS OF 5C78

//  -------------------
//  	APU I/O PORT
//  -------------------
#define	APUIO0			0x2140	//  BGM
#define	APUIO1			0x2141	//  SE
#define	APUIO2			0x2142	//  COMMAND 1:FADE OUT 2:PAUSE 3:CONTINUE 4:STEREO 5:MONAURAL
#define	APUIO3			0x2143	//  FADE TIME (0x00 - 0xFF)
#define	WMDATA			0x2180	//  WORK RAM READ/WRITE
#define	WMADDL			0x2181
#define	WMADDM			0x2182
#define	WMADDH			0x2183

//  --------------------
//  	CPU REGISTERS
//  --------------------
#define	NMITIMEN		0x4200	//  NMI ENABLE FLAGS AND JOY-C AUTO READ
#define	WRIO			0x4201	//  PROGRAMABLE I/O PORT
#define	WRMPYA			0x4202	//  {MULTIPLICATION
#define	WRMPYB			0x4203	//  }
#define	WRDIV			0x4204	//  {DIVISION
#define	WRDIVB			0x4206	//  }
#define	HTIME			0x4207	//  H COUNT TIMER
#define	VTIME			0x4209	//  V COUNT TIMER
#define	MDMAEN			0x420B	//  HANYOU DMA ENABLE FLAG
#define	HDMAEN			0x420C	//  H-DMA ENABLE FLAG
#define	MEMSEL			0x420D	//  MEMORY(2) ACCESS CYCLE
#define	RDNMI			0x4210	//  BLANK NMI
#define	RDTIMEUP		0x4211	//  TIMER IRQ
#define	RDHVBJOY		0x4212	//  H,V BLANKING FLAG AND JOY-C ENABLE
#define	RDIO			0x4213	//  PROGRAMABLE I/O PORT (READ)
#define	RDDIV2			0x4214	//  
#define	RDMPY2			0x4216	//  
#define	RDJOY1			0x4218	//  {
#define	RDJOY2			0x421A	//  JOY-C DATA
#define	RDJOY3			0x421C	//  
#define	RDJOY4			0x421E	//  }

//  --------------------
//  	DMA REGISTERS
//  --------------------
#define	DMAMOD			0x4300
#define	DMAMOD0			0x4300
#define	DMAMOD1			0x4310
#define	DMAMOD2			0x4320
#define	DMAMOD3			0x4330
#define	DMAMOD4			0x4340
#define	DMAMOD5			0x4350
#define	DMAMOD6			0x4360
#define	DMAMOD7			0x4370

#define	BBUSADD			0x4301
#define	BBUSADD0		0x4301
#define	BBUSADD1		0x4311
#define	BBUSADD2		0x4321
#define	BBUSADD3		0x4331
#define	BBUSADD4		0x4341
#define	BBUSADD5		0x4351
#define	BBUSADD6		0x4361
#define	BBUSADD7		0x4371

#define	ATBLADD			0x4302
#define	ATBLADD0		0x4302
#define	ATBLADD1		0x4312
#define	ATBLADD2		0x4322
#define	ATBLADD3		0x4332
#define	ATBLADD4		0x4342
#define	ATBLADD5		0x4352
#define	ATBLADD6		0x4362
#define	ATBLADD7		0x4372

#define	ATBLBNK			0x4304
#define	ATBLBNK0		0x4304
#define	ATBLBNK1		0x4314
#define	ATBLBNK2		0x4324
#define	ATBLBNK3		0x4334
#define	ATBLBNK4		0x4344
#define	ATBLBNK5		0x4354
#define	ATBLBNK6		0x4364
#define	ATBLBNK7		0x4374

#define	TRBYTE			0x4305
#define	TRBYTE0			0x4305
#define	TRBYTE1			0x4315
#define	TRBYTE2			0x4325
#define	TRBYTE3			0x4335
#define	TRBYTE4			0x4345
#define	TRBYTE5			0x4355
#define	TRBYTE6			0x4365
#define	TRBYTE7			0x4375

#define	DTBNK			0x4307
#define	DTBNK0			0x4307
#define	DTBNK1			0x4317
#define	DTBNK2			0x4327
#define	DTBNK3			0x4337
#define	DTBNK4			0x4347
#define	DTBNK5			0x4357
#define	DTBNK6			0x4367
#define	DTBNK7			0x4377

#define	PADB			0x8000
#define	PADY			0x4000
#define	PADSELECT		0x2000
#define	PADSTART		0x1000
#define	PADUP			0x800
#define	PADDOWN			0x400
#define	PADLEFT			0x200
#define	PADRIGHT		0x100
#define	PADA			0x80
#define	PADX			0x40
#define	PADL			0x20
#define	PADR			0x10
