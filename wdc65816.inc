N_FLAG		equ	1<<7
V_FLAG		equ	1<<6
M_FLAG		equ	1<<5
X_FLAG		equ	1<<4
B_FLAG		equ	1<<4
D_FLAG		equ	1<<3
I_FLAG		equ	1<<2
Z_FLAG		equ	1<<1
C_FLAG		equ	1<<0

ONA		macro
		rep	#M_FLAG
		longa	on
		endm

ONI		macro
		rep	#X_FLAG
		longi	on
		endm

ONAI	macro
		rep	#M_FLAG|X_FLAG
		longa	on
		longi	on
		endm

OFFA	macro
		sep	#M_FLAG
		longa	off
		endm

OFFI	macro
		sep	#X_FLAG
		longi	off
		endm

OFFAI	macro
		sep	#M_FLAG|X_FLAG
		longa	off
		longi	off
		endm

PreProcess macro
		tsa
		sec
		sbc		#0
		tas
		phd
		tad
		phd
		endm

PostProcess	macro	argc
		pld
		lda		<$02
		sta		<$02+argc*2
		lda		<$01
		sta		<$01+argc*2
		pld
		tsa
		clc
		adc		#argc*2
		tas
		endm

Arg		macro	arg
		lda		<$04+arg*2
		endm

Leave	macro
		jsl		Return_to_task_core
		endm

Entry	macro	LABEL,NO
		pea		#NO*$100+^LABEL
		pea		#LABEL
		jsl		Entry_task
		endm

Pause	macro	NO
		lda		#NO
		jsl		Pause_task
		endm

Continue	macro	NO
		lda		#NO
		jsl		Continue_task
		endm

Break	macro	NO
		lda		#NO
		jsl		Break_task
		endm

AutoBreak	macro
		jsl		Auto_break_task
		endm
