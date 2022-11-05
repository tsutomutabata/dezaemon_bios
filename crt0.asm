
		chip	65816

		include "wdc65816.inc"
		include "dezaemon_symbol.inc"
		include "io_mapping.inc"

		code
		xref	BaseTask

BiosStart:
		php
		ONI
		OFFA
		AutoBreak
		Entry	BaseTask,1
		plp
		rtl

		xdef 	BiosExit
BiosExit:
		php
		ONI
		OFFA
		ldx		#0
		ldy		#4096
FontTrans:
		lda		>MAIN_ASC_FNT,x
		sta		>ASC_FNT,x
		inx
		dey
		bne		FontTrans
		AutoBreak
		Entry	Test_programs,0
		plp
		rtl

		end