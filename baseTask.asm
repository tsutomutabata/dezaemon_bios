		chip	65816

		include "wdc65816.inc"
		include "dezaemon_symbol.inc"

		data
ActivityInit	ds	4
ActivityUpdate	ds	4
NextInit		ds	4
NextUpdate		ds	4

		code
		xdef	BaseTask
		xref	BiosExit,~~Init,~~Update

BaseTask:
		ONAI
		lda		#^~~Init
		sta		>ActivityInit+2
		lda		#~~Init
		sta		>ActivityInit
		lda		#^~~Update
		sta		>ActivityUpdate+2
		lda		#~~Update
		sta		>ActivityUpdate
		Entry	Request_BGM,7
ActivityLoop:
		lda		#0
		sta		>NextInit
		sta		>NextInit+2
		ldx		#0
		ldy		#$8000
ClearLoop:
		sta		>$7f0000,x
		inx
		inx
		dey
		bne		ClearLoop
InitLoop:
		pea		#$7f
		pea		#0
		jsl		FarJumpInit
		cmp		#0
		beq		Loop
		lda		#0
		tad
		Leave
		bra		InitLoop
Loop:
		lda		#0
		tad
		Leave
		pea		#$7f
		pea		#0
		jsl		FarJumpUpdate
		cmp		#0
		beq		Exit
		lda		>NextInit
		cmp		#0
		bne		NextActivity
		lda		>NextInit+2
		cmp		#0
		bne		NextActivity
		bra		Loop
NextActivity:
		lda		>NextInit
		sta		>ActivityInit
		lda		>NextInit+2
		sta		>ActivityInit+2
		lda		>NextUpdate
		sta		>ActivityUpdate
		lda		>NextUpdate+2
		sta		>ActivityUpdate+2
		bra		ActivityLoop
Exit:
		lda		#0
		tad
		Break	7
		jsl		BiosExit
Stop:
		Leave
		bra		Stop;

FarJumpInit:
		lda		#0
		tad
		lda		>ActivityInit
		sta		<A0
		lda		>ActivityInit+2
		sta		<A0+2
		jml		(A0)

FarJumpUpdate:
		lda		#0
		tad	
		lda		>ActivityUpdate
		sta		<A0
		lda		>ActivityUpdate+2
		sta		<A0+2
		jml		(A0)


		xdef	~~NextActivity
~~NextActivity:
		PreProcess

		Arg		0
		sta		>NextInit
		Arg		1
		sta		>NextInit+2
		Arg		2
		sta		>NextUpdate
		Arg		3
		sta		>NextUpdate+2

		PostProcess	4
		rtl

