		chip	65816

		include "wdc65816.inc"
		include "dezaemon_symbol.inc"
		include "io_mapping.inc"
		
		code
		
		ONAI
		xdef	~~print
~~print:
		PreProcess

		Arg		0
		sta		D0
		Arg		1
		sta		D0+1
		stz		D1
		Arg		2
		pha
		Arg		3
		pha
		lda		#0
		tad
		jsl		Print

		PostProcess	4
		rtl

		xdef	~~cls
~~cls:
		phd
		lda		#0
		tad
		jsl		Cls_fix
		pld
		rtl

		xdef	~~hexPrint
~~hexPrint:
		PreProcess

		Arg		0
		sta		D0
		Arg		1
		sta		D0+1
		stz		D1
		lda		#1
		sta		D1+1
		Arg		2
		sta		D2
		Arg		3
		sta		D3
		Arg		4
		sta		D3+2

		lda		#0
		tad
		jsl		Hex_print

		PostProcess	5
		rtl

		xdef	~~bcdPrint
~~bcdPrint:
		PreProcess

		Arg		0
		sta		D0
		Arg		1
		sta		D0+1
		stz		D1
		stz		D1+1
		Arg		2
		sta		D2
		Arg		3
		sta		D3
		Arg		4
		sta		D3+2

		lda		#0
		tad
		jsl		Hex_to_dec
		jsl		Hex_print

		PostProcess	5
		rtl

		xdef	~~readTriggerPad
~~readTriggerPad:
		lda		PADTR
		rtl

		xdef	~~readPad
~~readPad:
		lda		PAD
		rtl

		xdef	~~readMouseX
~~readMouseX:
		lda		MOUSEX
		rtl

		xdef	~~readMouseY
~~readMouseY:
		lda		MOUSEY
		rtl

		xdef	~~readMouseTriggerButton
~~readMouseTriggerButton:
		lda		MOUSESWTR
		and		#$ff
		rtl

		xdef	~~readMouseButton
~~readMouseButton:
		lda		MOUSESW
		and		#$ff
		rtl

		xdef	~~requestSe
~~requestSe:
		PreProcess

		Arg		0
		tax

		lda		#0
		tad
		txa
		jsl		Request_SE

		PostProcess	1
		rtl

		xdef	~~requestDma
~~requestDma:
		PreProcess

		Arg		0
		pha
		Arg		1
		pha
		lda		#0
		tad
		jsl		DMA_entry

		PostProcess	2
		rtl

		xdef	~~biosRand
~~biosRand:
		phd
		lda		#0
		tad
		jsl		Randomize
		pld
		rtl

		xdef	~~biosSin
~~biosSin:
		PreProcess

		Arg		0
		sta		D7
		lda		#0
		tad
		jsl		Sin
		tay

		PostProcess	1
		tya
		rtl

		xdef	~~biosCos
~~biosCos:
		PreProcess

		Arg		0
		sta		D7
		lda		#0
		tad
		jsl		Cos
		tay

		PostProcess	1
		tya
		rtl

		xdef	~~biosAngle
~~biosAngle:
		PreProcess

		Arg		0
		sta		D0
		Arg		1
		sta		D1
		Arg		2
		sta		D2
		Arg		3
		sta		D3
		lda		#0
		tad
		phb
		OFFA
		pha
		plb
		ONA
		jsl		Target_angle
		plb
		tay

		PostProcess	4
		tya
		rtl

		xdef	~~biosHwMul32
~~biosHwMul32:
		PreProcess

		Arg		0
		sta		D0
		Arg		1
		sta		D1
		Arg		2
		pha
		Arg		3
		pha

		lda		#0
		tad
		phb
		OFFA
		pha
		plb
		ONA
		jsl		Muls32
		plb

		pla
		sta		<A0+2		; DR == 0 => Direct page access mode '<'
		pla
		sta		<A0
		lda		<R0
		sta		(<A0)
		inc		<A0
		inc		<A0
		lda		<R0+2
		sta		(<A0)

		PostProcess	4
		rtl

		xdef	~~biosHwDiv16
~~biosHwDiv16:
		PreProcess

		Arg		0
		sta		>WRDIV
		Arg		1
		sta		>WRDIVB

		PostProcess	2

		lda		>RDDIV2
		rtl
