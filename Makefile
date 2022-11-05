
TARGET	= sfc.bin
RAWDATA	= rawdata

OBJ		= crt0.o \
		  bios.o \
		  biosC.o \
		  baseTask.o \
		  baseActivity.o \
		  launcherActivity.o \
		  spriteTest.o \
		  soundAndDmaTest.o \
		  biosMathTest.o 

AS		= wdc816as
CC		= wdc816cc
LD		= wdcln
HZ2BIN	= tool\hz2bin
RM		= del

ASFLAGS		= -g -l 
CFLAGS		= -ML
LDFLAGS		= -C7E2000 -HZ -g -sz -t -j
LDLIB		= -lcl -lml

CLEAN		= $(RM) $(TARGET) $(OBJ) $(RAWDATA).* *.map *.sym *.lst *.tmp

.SUFFIXES: .c .asm

%.o : %.asm
	@echo [ assemble ] $<
	@$(AS) $(ASFLAGS) -O $@ $<

%.o : %.c
	@echo [ compile ] $<
	@$(CC) $(CFLAGS) -O $@ $<

$(TARGET): $(OBJ)
	$(LD) $(LDFLAGS) -O $@ $(OBJ) $(LDLIB)
	$(HZ2BIN) $@ $(RAWDATA)
	$(HZ2BIN) --hex $@ $(RAWDATA)

clean:
	$(CLEAN)

