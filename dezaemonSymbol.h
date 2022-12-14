// Zero page registers
#define	D0	0x000000
#define	D1	0x000004
#define	D2	0x000008
#define	D3	0x00000c
#define	D4	0x000010
#define	D5	0x000014
#define	D6	0x000018
#define	D7	0x00001c
#define	D8	0x000020
#define	D9	0x000024
#define	A0	0x000028
#define	A1	0x00002c
#define	A2	0x000030
#define	A3	0x000034
#define	A4	0x000038
#define	A5	0x00003c
#define	A6	0x000040
#define	A7	0x000044
#define	A8	0x000048
#define	A9	0x00004c
#define	B0	0x000050
#define	B1	0x000054
#define	B2	0x000058
#define	B3	0x00005c
#define	B4	0x000060
#define	B5	0x000064
#define	B6	0x000068
#define	B7	0x00006c
#define	B8	0x000070
#define	B9	0x000074
#define	C0	0x000078
#define	C1	0x00007c
#define	C2	0x000080
#define	C3	0x000084
#define	C4	0x000088
#define	C5	0x00008c
#define	C6	0x000090
#define	C7	0x000094
#define	C8	0x000098
#define	C9	0x00009c
#define	R0	0x0000a0
#define	R1	0x0000a4
#define	R2	0x0000a8
#define	R3	0x0000ac
#define	R4	0x0000b0
#define	R5	0x0000b4
#define	R6	0x0000b8
#define	R7	0x0000bc
#define	R8	0x0000c0
#define	R9	0x0000c4
#define	AF	0x0000c8
#define	BC	0x0000cc
#define	DE	0x0000d0
#define	HL	0x0000d4
#define	T0	0x0000d8
#define	T1	0x0000d9
#define	T2	0x0000da
#define	TIMER0	0x0000db
#define	TIMER1	0x0000dc
#define	TIMER2	0x0000dd
#define	TIMER3	0x0000de
#define	TIMER4	0x0000df
#define	TIMER5	0x0000e0
#define	TIMER6	0x0000e1
#define	TIMER7	0x0000e2
#define	T_FRQ0	0x0000e3
#define	T_FRQ1	0x0000e4
#define	T_FRQ2	0x0000e5
#define	T_FRQ3	0x0000e6
#define	T_FRQ4	0x0000e7
#define	T_FRQ5	0x0000e8
#define	T_FRQ6	0x0000e9
#define	T_FRQ7	0x0000ea
#define	T_WORK0	0x0000eb
#define	T_WORK1	0x0000ec
#define	T_WORK2	0x0000ed
#define	T_WORK3	0x0000ee
#define	T_WORK4	0x0000ef
#define	T_WORK5	0x0000f0
#define	T_WORK6	0x0000f1
#define	T_WORK7	0x0000f2
#define	PRI_R0	0x0000f3
#define	PRI_R1	0x0000f5
#define	PRI_R2	0x0000f7
#define	PRI_R3	0x0000f9
#define	PRI_R4	0x0000fb
#define	PRI_R5	0x0000fd
#define	FN_CALL	0x0000fe
#define	BOTTOMZERO	0x0000ff

// work memory
#define	NMIJOB	0x000100
#define	IRQJOB	0x000103
#define	NMIIRQ	0x000106
#define	NMIREQ	0x000107
#define	PAUSE_ENEBLE	0x000108
#define	INTERRUPT_COUNT	0x000109
#define	JOB_COUNT	0x00010a
#define	DISPFADE	0x00010b
#define	REDBRIGHT	0x00010c
#define	BLUEBRIGHT	0x00010d
#define	GREENBRIGHT	0x00010e
#define	BGTYPE	0x00010f
#define	MOUSEX	0x000110
#define	MOUSEY	0x000112
#define	MOUSEH	0x000114
#define	MOUSEV	0x000116
#define	MOUSELIMITL	0x000118
#define	MOUSELIMITR	0x00011a
#define	MOUSELIMITU	0x00011c
#define	MOUSELIMITD	0x00011e
#define	MOUSEXV	0x000120
#define	MOUSEYV	0x000121
#define	MOUSEXGAP	0x000122
#define	MOUSEYGAP	0x000123
#define	MOUSESW	0x000124
#define	MOUSESWTR	0x000125
#define	MOUSESWRP	0x000126
#define	MOUSESWDC	0x000127
#define	MOUSEDCTIME	0x000128
#define	MOUSEDCCOUNT	0x000129
#define	MOUSEINIT	0x00012a
#define	MOUSEREV	0x00012b
#define	MOUSEWORK0	0x00012c
#define	MOUSEWORK1	0x00012e
#define	MOUSEWORK2	0x000130
#define	MOUSEWORK3	0x000132
#define	PADCONNECT	0x000134
#define	PADREPEATCOUNT	0x000135
#define	PADSTATUS	0x000136
#define	PADANGLE	0x000137
#define	PADANGLEOLD	0x000138
#define	FIRSTREPEATTIME	0x000139
#define	NEXTREPEATTIME	0x00013a
#define	MOUSECURSOR	0x00013b
#define	MOUSECURSOROLD	0x00013c
#define	MOUSECURSORTIME	0x00013d
#define	MOUSE_L	0x00013e
#define	MOUSE_R	0x00013f
#define	MOUSE_REP_WORK	0x000140
#define	MOUSE_ADDRESS	0x000141
#define	MOUSE_MODE	0x000144
#define	MOUSE_TIME	0x000145
#define	LEFT_KEY	0x000146
#define	RIGHT_KEY	0x000148
#define	M7ABUFF	0x00014a
#define	M7BBUFF	0x00014c
#define	M7CBUFF	0x00014e
#define	M7DBUFF	0x000150
#define	M7XBUFF	0x000152
#define	M7YBUFF	0x000154
#define	PALETTE	0x000156
#define	BACKUPCHRTOP	0x000157
#define	PAD	0x000158
#define	PADTR	0x00015a
#define	PADBAK	0x00015c
#define	SHOT_KEY	0x00015e
#define	BOMB_KEY	0x000160
#define	TRANSFARTABLE	0x000162
#define	TRANSFARTABLECOUNT	0x000192
#define	TRANSFARCOUNTER	0x000194
#define	DMABUSY	0x000196
#define	TRANSVRAM	0x000197
#define	NEXTVRAMADDRESS	0x000199
#define	SOURCEADDRESS	0x00019b
#define	CHARACTORBUFF	0x00019e
#define	CHARACTORBUFFNEXT	0x00039e
#define	CHRTRANSMISS	0x0003a0
#define	CHRTRANSBUSY	0x0003a1
#define	HDMASWITCH	0x0003a2
#define	BLANKINGTIMEOUT	0x0003a3
#define	DMASTOP	0x0003a4
#define	CHRSTOP	0x0003a5
#define	ASCTEMPADDRESS	0x0003a6
#define	CHARACTORBUFFADDRESS	0x0003a9
#define	PRINTN	0x0003ab
#define	MODE16	0x0003ac
#define	FIXADDRESS	0x0003ad
#define	BCDBUFF	0x0003af
#define	BCDR0	0x0003b3
#define	BCDR1	0x0003b7
#define	BCDR2	0x0003bb
#define	BCDR3	0x0003bf
#define	RND	0x0003c3
#define	REGISTERDATA	0x0003c5
#define	TASKSTATUS	0x000445
#define	TASKCOUNT	0x00044d
#define	TEMPA	0x00044e
#define	TEMPX	0x000450
#define	TEMPY	0x000452
#define	TEMPP	0x000454
#define	TEMPPC	0x000455
#define	TEMPDBR	0x000458
#define	TASKPC	0x000459
#define	TASKBAR	0x00045c
#define	SPBUFF	0x00045d
#define	SPCHRTEST	0x00145d
#define	SPRITECOUNT	0x00145e
#define	SPWORK0	0x00145f
#define	SPWORK1	0x001461
#define	SPWORK2	0x001463
#define	SPWORK3	0x001465
#define	SPWORK4	0x001467
#define	SPWORK5	0x001469
#define	SELOVER	0x00146b
#define	SPRITEBUSY	0x00146c
#define	OAMBUFFFLAG	0x00146d
#define	PRIORITY_BUFF	0x00146e
#define	BG1HBUFF	0x001576
#define	BG1VBUFF	0x001578
#define	BG2HBUFF	0x00157a
#define	BG2VBUFF	0x00157c
#define	BG3HBUFF	0x00157e
#define	BG3VBUFF	0x001580
#define	BG2HPOS	0x001582
#define	BG2VPOS	0x001584
#define	BG2VBAK	0x001586
#define	BG2VBAK2	0x001588
#define	BG2VBAK3	0x00158a
#define	BG2VSPD	0x00158c
#define	WINDOWBUFF1	0x00158e
#define	WINDOWBUFF2	0x00178e
#define	WINDOWBUFFADD	0x00198e
#define	WINDOWBUFFADD2	0x001990
#define	WINDOWENTRYFLAG	0x001992
#define	WINDOWTYPE	0x001993
#define	WINDOWFLAG	0x001994
#define	WINDOWR0	0x001995
#define	WINDOWR1	0x001997
#define	WINDOWR2	0x001999
#define	WINDOWR3	0x00199b
#define	WINDOWR4	0x00199d
#define	WINDOWR5	0x00199f
#define	WINDOWR6	0x0019a1
#define	WINDOWR7	0x0019a3
#define	WINDOWBOX	0x0019a5
#define	WINDOWX1	0x0019a6
#define	WINDOWX2	0x0019a7
#define	WINDOWY1	0x0019a8
#define	WINDOWY2	0x0019a9
#define	WINDOWBUFF	0x0019aa
#define	MAPEDIT	0x0019ba
#define	SCROLL_SPEED	0x0019bb
#define	TEST_PLAY	0x0019bd
#define	GAME_MODE	0x0019be
#define	SCORE	0x0019bf
#define	EXTEND_TABLE_ADDRESS	0x0019c3
#define	NEXT_EXTEND	0x0019c5
#define	BOMB_FLAG	0x0019c9
#define	NON_HIT	0x0019ca
#define	TITLE_BUSY	0x0019cb
#define	TITLE_MODE	0x0019cc
#define	USER_MODE	0x0019ce
#define	STAGE_CLEAR	0x0019cf
#define	STAGE_CLEAR_REQUEST	0x0019d0
#define	AUTO_SHOT_COUNT	0x0019d1
#define	PLAYER_LEFT	0x0019d2
#define	BOMB_LEFT	0x0019d3
#define	PLAYER_SPEED	0x0019d4
#define	PLAYER_LEVEL	0x0019d5
#define	BASE_LEVEL	0x0019d6
#define	GAME_LEVEL	0x0019d8
#define	STAGE	0x0019da
#define	RETURN_MAP_POINT	0x0019db
#define	BOSS_FLAG	0x0019dd
#define	PLAYER_TYPE	0x0019de
#define	ITEM_NUMBER	0x0019df
#define	WEAPON_NUMBER	0x0019e0
#define	SHOTSPEED	0x0019e1
#define	TARGET_ADDRESS	0x0019e3
#define	HIT_OFF_TIMER	0x0019e5
#define	SHIELD_ON	0x0019e6
#define	IN_THE_ENEMY	0x0019e7
#define	HIGH_SCORE_ENTRY	0x0019e8
#define	B_SHOT_TYPE1	0x0019e9
#define	B_SHOT_TYPE2	0x0019ea
#define	B_SHOT_TYPE3	0x0019eb
#define	B_SHOT_INTERVAL1	0x0019ec
#define	B_SHOT_INTERVAL2	0x0019ed
#define	B_SHOT_INTERVAL3	0x0019ee
#define	B_SHOT_SPEED1	0x0019ef
#define	B_SHOT_SPEED2	0x0019f1
#define	B_SHOT_SPEED3	0x0019f3
#define	B_SHOT_COUNT1	0x0019f5
#define	B_SHOT_COUNT2	0x0019f6
#define	B_SHOT_COUNT3	0x0019f7
#define	B_SHOT_CHAR1	0x0019f8
#define	B_SHOT_CHAR2	0x0019f9
#define	B_SHOT_CHAR3	0x0019fa
#define	B_SHOT_WORK1	0x0019fb
#define	B_SHOT_WORK2	0x0019fc
#define	B_SHOT_WORK3	0x0019fd
#define	B_SHOT_H_OFFSET1	0x0019fe
#define	B_SHOT_H_OFFSET2	0x0019ff
#define	B_SHOT_H_OFFSET3	0x001a00
#define	B_SHOT_V_OFFSET1	0x001a01
#define	B_SHOT_V_OFFSET2	0x001a02
#define	B_SHOT_V_OFFSET3	0x001a03
#define	B_SHOT_TIME_MASK1	0x001a04
#define	B_SHOT_TIME_MASK2	0x001a05
#define	B_SHOT_TIME_MASK3	0x001a06
#define	TITLE	0x001a07
#define	PADFTIME	0x001a08
#define	PADNTIME	0x001a09
#define	TEMP	0x001a0a
#define	PALETTE_TEMP	0x001b0a
#define	GAME_BGM	0x001b4a
#define	TRANS_BGM	0x001b4b
#define	POWER_ON	0x001b4c
#define	POWER_ON_RESET_RAM	0x001b4c
#define	ATHENA_LOGO_PUT	0x001b54
#define	EDITBGM	0x001b55
#define	BGM_STEREO_MONO	0x001b56
#define	MOUSESPEED	0x001b57
#define	EDITSTAGE	0x001b58
#define	LEVEL	0x001b59
#define	EXTEND	0x001b5a
#define	HOT_START	0x001b5b
#define	HIDE_COMMAND	0x001b5c
#define	FONT_NUMBER	0x001b5d
#define	INTERRUPT_TIME	0x001b5e
#define	BOTTOMRAM	0x001b5f
#define	POWER_ON_RESET_RAM_BOTTOM	0x001b5f
#define	AREA_S	0x001c08
#define	AREA_E	0x001c0a
#define	GRAPHMODE	0x001c0f
#define	WINDOWSIZE	0x001c17
#define	ANIM_ENTRY	0x001c98
#define	ANIM_TIME	0x001c99
#define	ANIM_WORK	0x001c9a
#define	ANIM_PTN	0x001c9b
#define	BITMAP_SW	0x001d09
#define	TX_REQ	0x001d0d
#define	ITEM_BUSY	0x001d0f
#define	Error	0x008000
#define	Error_stop	0x00800a
#define	Reset_start	0x00800b
#define	INT_NMI	0x008029
#define	INT_IRQ	0x00802c
#define	CHECKSUM_GRAPH	0x700000
#define	SRAM70_TOP	0x700000
#define	CHECKSUM_MAP1	0x700002
#define	CHECKSUM_MAP2	0x700004
#define	CHECKSUM_MAP3	0x700006
#define	CHECKSUM_MAP4	0x700008
#define	CHECKSUM_MAP5	0x70000a
#define	CHECKSUM_MAP6	0x70000c
#define	CHECKSUM_DATA1	0x70000e
#define	CHECKSUM_DATA2	0x700010
#define	CHECKSUM_DATA3	0x700012
#define	CHECKSUM_DATA4	0x700014
#define	CHECKSUM_DATA5	0x700016
#define	CHECKSUM_DATA6	0x700018
#define	CHECKSUM_DATAE	0x70001a
#define	CHECKSUM_MUSIC	0x70001c
#define	CHECKSUM	0x70001e
#define	PALETTE24	0x700040
#define	BACKUPMAPBUFF	0x700340
#define	BACKUPMAPPING	0x703940
#define	BACKUPMAPGROUP	0x704540
#define	BACKUP_MY_SHIP_ODR	0x704b40
#define	BACKUP_ENEMY_GROUP	0x704b80
#define	BACKUP_BOSS_GROUP	0x704e80
#define	BACKUP_TITLE_GROUP	0x705000
#define	BACKUP_ENDING_GROUP	0x705040
#define	SOUND_SRAM	0x705058
#define	BACKUP_TITLE_TYPE	0x707e58
#define	CHECK_SUM_COPY	0x707e5a
#define	BACKUP_MOUSESPEED	0x707e7a
#define	BACKUP_FONT_NUMBER	0x707e7b
#define	BACKUP_EDITBGM	0x707e7c
#define	BGM_PATCH	0x707e7e
#define	BACKUP_HIGH_SCORE_SAMPLE	0x707e8e
#define	BACKUP_HIGH_SCORE_USER	0x707f2e
#define	BACKUP_KEY_CONFIG	0x707fce
#define	BOTTOM_SRAM70	0x707fd2
#define	CHECK_STRINGS	0x707ff8
#define	BACKUP_ENEMY_DATA	0x710000
#define	SRAM71_TOP	0x710000
#define	BACKUP_APPEAR_DATA	0x710c00
#define	BACKUP_ENEMY_ODR	0x717800
#define	BACKUP_MY_SHIP_GROUP	0x717f80
#define	BOTTOM_SRAM71	0x718000
#define	BACKUPCHR	0x720000
#define	BACKUPCHR2	0x730000
#define	CHARACTORTEMP	0x7e2000
#define	MAPBUFF	0x7e6000
#define	MAPPINGDATA	0x7e7000
#define	EFECTBUFF	0x7e7100
#define	LPBUFF	0x7e7200
#define	CHBUFF	0x7e9200
#define	UNDOBUFF1	0x7e9a00
#define	UNDOBUFF2	0x7ea200
#define	ENEMY_ODR_BUFF	0x7eb200
#define	MY_SHIP_ODR_BUFF	0x7eb480
#define	BOSS_ODR_BUFF	0x7eb516
#define	TITLE_ODR_BUFF	0x7eb556
#define	ENDING_ODR_BUFF	0x7eb596
#define	APPEAR_BUFF	0x7eb5ae
#define	OAMBUFF1	0x7ef5ae
#define	OAMBUFF2	0x7ef7ce
#define	ENEMY_DATA	0x7ef9ee
#define	PALETTE_TEMP_GAME	0x7efbee
#define	PAINTTEMP	0x7f0000
#define	GROUPBUFF	0x7f3000
#define	BITMAPBUFF	0x7f3100
#define	MAPPING_NO_BUFF	0x7f7100
#define	MAT_BUFF	0x7f7500
#define	MAPPING_DATA_BUFF	0x7f7700
#define	ASC_FNT	0x7f8500
#define	ASC2_FNT	0x7f9500
#define	ASCTEMPBUFF	0x7fc000
#define	NMI_entry	0x80817e
#define	IRQ_entry	0x80819f
#define	NMI_stop	0x8081c7
#define	IRQ_stop	0x8081e9
#define	Ram_check	0x808234
#define	Check_sum	0x80841a
#define	V_Wait	0x809126
#define	V_interrupt	0x809133
#define	DMA_ctrl	0x8092cd
#define	DMA_entry	0x809561
#define	Task_ctrl	0x809679
#define	Return_to_task_core	0x809711
#define	Entry_task	0x80977f
#define	Break_task	0x809817
#define	Auto_break_task	0x809825
#define	Pause_task	0x809836
#define	Continue_task	0x809849
#define	Convert_appear	0x8098b2
#define	Read_appear	0x809992
#define	Write_appear	0x809a54
#define	Write_map	0x809ab5
#define	Read_map	0x809b9c
#define	Group_buff_initialize	0x809cce
#define	Read_my_ship	0x809ce5
#define	Write_my_ship	0x809d5f
#define	Read_enemy	0x809da2
#define	Write_enemy	0x809e48
#define	Read_boss	0x809edb
#define	Write_boss	0x809f38
#define	Boss_map_put	0x809f8c
#define	Read_title	0x80a068
#define	Write_title	0x80a0b2
#define	Read_ending	0x80a0e6
#define	Write_ending	0x80a11f
#define	Read_enemy_data	0x80a14d
#define	Write_enemy_data	0x80a17f
#define	Get_palette	0x80a1b5
#define	Sprite_put_player	0x80a2fe
#define	Sprite_put_shield	0x80a336
#define	Sprite_put_weapon	0x80a35c
#define	Sprite_put_homing	0x80a38c
#define	Sprite_put_item	0x80a3bc
#define	Sprite_put_enemy_16x16	0x80a3ec
#define	Sprite_put_enemy_32x16	0x80a44c
#define	Sprite_put_enemy_16x32	0x80a4ae
#define	Sprite_put_enemy_32x32	0x80a510
#define	Sprite_put_enemy_64x64	0x80a573
#define	Sprite_put_enemy_fire1	0x80a5e7
#define	Sprite_put_enemy_fire2	0x80a627
#define	Sprite_put_enemy_blast1	0x80a667
#define	Sprite_put_enemy_blast2	0x80a6a1
#define	Sprite_put_fragment	0x80a6db
#define	Boss_put	0x80a88d
#define	ANIM_TIME_DATA	0x80ab57
#define	SCORE_TABLE	0x80ab5f
#define	SCORE_TABLE_BOSS	0x80ab6f
#define	LIFE_TABLE	0x80ab8f
#define	Group_search	0x80abfd
#define	Group_rest_test	0x80ac44
#define	Group_trans	0x80ac5d
#define	Job_jumper	0x80acab
#define	Mouse_cursor	0x80ad32
#define	Chr_temp_put	0x80ae36
#define	Chr_address_get	0x80ae81
#define	Title_disp	0x80b011
#define	Monitor_mouse	0x80b782
#define	Core	0x80bb8b
#define	Sprite_clear	0x80bc32
#define	OAM_clear	0x80bc45
#define	Vram_clear	0x80bc60
#define	CPU_PPU_init	0x80bcc3
#define	PPU_MODE1	0x80bd7c
#define	PPU_MODE5	0x80bdbb
#define	Cls_fix	0x80bdf3
#define	Print2	0x80be34
#define	Print	0x80be6a
#define	Chr_trans	0x80bfad
#define	Screen_put	0x80c011
#define	Hex_print	0x80c03f
#define	Window_data_flip	0x80c5cf
#define	Window_entry	0x80c625
#define	Box_window_init	0x80c960
#define	OAM_trans	0x80ccf0
#define	Sprite_ctrl	0x80cd8c
#define	Pad_ctrl	0x80d738
#define	Scroll_ctrl	0x80d80d
#define	Test_programs	0x80d941
#define	CHECK_SUM_ENEBLE	0x80ffb0
#define	ROM_Check_sum	0x80ffde
#define	Target_angle2	0x818000
#define	Target_angle	0x81809b
#define	Hex_to_dec	0x81815a
#define	Sin	0x81824a
#define	Cos	0x81825e
#define	Muls32	0x818272
#define	Randomize_initialize	0x81831b
#define	Randomize	0x818326
#define	Cut_side_check	0x819891
#define	Graph_trans	0x819c65
#define	Graph_editor	0x819dc8
#define	Map_editor	0x81d259
#define	Scroll_efect	0x81ed4b
#define	Efect_ctrl	0x81f96b
#define	UG_BGM01	0x81fc4a
#define	Motion_ctrl	0x828000
#define	Level_ctrl	0x82808e
#define	Area_check	0x828120
#define	Area_check_e_shot	0x828141
#define	Sequence_move	0x82815f
#define	SPBUFF_search	0x82821d
#define	SPBUFF_back_search	0x828254
#define	Hit_size_get	0x82828c
#define	Anim_ctrl	0x8282ad
#define	Hit_check	0x8283c9
#define	Hit_check_e_shot	0x828421
#define	Player_hit_check	0x82843c
#define	BOSS_INIT_DATA_H	0x8285ac
#define	BOSS_INIT_DATA_V	0x8285c0
#define	Player	0x8285d6
#define	Player_shot_entry	0x828843
#define	Player_laser_mother	0x828fbd
#define	Player_laser_chaild	0x829156
#define	Player_shot	0x829643
#define	Player_miss	0x829667
#define	Player_horming	0x8296ba
#define	Bomber2	0x82986c
#define	Bomber3	0x829926
#define	Bomber1	0x829b18
#define	Teki1	0x829cb6
#define	Teki2	0x829d01
#define	Teki3	0x829ddb
#define	Teki4	0x829e72
#define	Boss	0x829f89
#define	Move_table	0x82a5f5
#define	Boss_move_table	0x82ca17
#define	Bomb	0x82e8b9
#define	Bomb2	0x82e8d3
#define	Bomb_entry	0x82e9b7
#define	Entry_item	0x82eb09
#define	Item	0x82eb8f
#define	Enemy_laser	0x82ecc2
#define	Enemy_shot	0x82eea6
#define	Enemy_shot_bunretsu1	0x82eecf
#define	Enemy_shot_bunretsu2	0x82ef20
#define	Enemy_shot_5way2	0x82efa8
#define	Fragment	0x82f004
#define	Fragment_entry	0x82f01c
#define	Enemy_shot_entry	0x82f064
#define	Menu_item_move	0x82f5a3
#define	Kumitate_anim3	0x82f643
#define	Kumitate_anim4	0x82f669
#define	Kumitate_anim5	0x82f692
#define	UG_BGM02	0x82f69c
#define	UG_BGM03	0x82f97c
#define	UG_BGM04	0x82fc5c
#define	Sound_bit_map	0x838000
#define	SoundEdit	0x838003
#define	PaletteData	0x839704
#define	Multiple	0x83986b
#define	BitMapBlanking	0x83a60b
#define	BitMap	0x83a674
#define	Main_menu	0x83ab11
#define	Restor_Music_select	0x83c1c4
#define	Athena_logo	0x83d127
#define	MAP1BG_MAP	0x83d63c
#define	MAP2BG_MAP	0x83e63c
#define	SET_BG_MAP	0x83e83c
#define	SET_BG2_MAP	0x83f03c
#define	ATHENA_MAP	0x83f63c
#define	SOUND_BG_MAP	0x83f83c
#define	UG_BGM05	0x83fa3c
#define	UG_BGM06	0x83fd1c
#define	Construction_editor	0x84804b
#define	Set_editor_enemy	0x84d35e
#define	Set_editor_boss	0x84e9b9
#define	UG_BGM07	0x84fc14
#define	Base	0x858000
#define	Set_editor_title	0x8586ff
#define	Appear_ctrl	0x858e33
#define	Appear_editor	0x858fe6
#define	Game_main	0x85b206
#define	Status_init	0x85ba45
#define	Status_put	0x85ba55
#define	Cut_side	0x85bb9a
#define	Cut_side2	0x85bf6e
#define	Ending_main	0x85c34e
#define	High_score_disp	0x85cd77
#define	High_score_entry	0x85cdcc
#define	AP_BG_MAP	0x85d251
#define	D_TITLE_MAP	0x85d451
#define	D_TITLE2_MAP	0x85d651
#define	EDBG_MAP	0x85d851
#define	KUMITATE_MAP	0x85dc51
#define	FUT_ASC_FNT	0x85ec51
#define	UG_BGM08	0x85f651
#define	UG_BGM09	0x85f931
#define	UG_BGM10	0x85fc11
#define	AP_BG_FNT	0x868000
#define	AP_SP_FNT	0x868c00
#define	MAIN_ASC_FNT	0x869000
#define	MAIN_ASC2_FNT	0x86a000
#define	CURSOR_FNT	0x86a400
#define	D_TITLE_FNT	0x86a800
#define	D_TITLE2_FNT	0x86b800
#define	EDBG_FNT	0x86cc00
#define	EDSP_FNT	0x86dc00
#define	UG_BGM11	0x86fc00
#define	Sprite_table	0x878000
#define	MEMU_ICON_0C	0x878580
#define	UG_BGM12	0x87ea17
#define	UG_BGM13	0x87ecf7
#define	UG_BGM14	0x87efd7
#define	UG_BGM15	0x87f2b7
#define	UG_BGM16	0x87f597
#define	UG_BGM17	0x87f877
#define	UG_BGM18	0x87fb57
#define	SOUND_BG_FNT	0x8c8000
#define	KUMITATE_FNT	0x8ca800
#define	MAP1SP_FNT	0x8cd800
#define	OCR_ASC_FNT	0x8ce000
#define	NAMCO_ASC_FNT	0x8cea00
#define	ITA_ASC_FNT	0x8cf400
#define	MENUISP_FNT	0x8d8000
#define	SET_BG2_FNT	0x8dac00
#define	SET_SP_FNT	0x8dcc00
#define	NORMAL_ASC_FNT	0x8de800
#define	D70_ASC_FNT	0x8df200
#define	UG_BGM19	0x8dfc00
#define	SET_TIT_FNT	0x8e8000
#define	SOUND_SP_FNT	0x8e8c00
#define	ATHENA_FNT	0x8ebc00
#define	MAPBG_FNT	0x8ed000
#define	SET_BG_FNT	0x8ee400
#define	SoundInit	0x8f8000
#define	Kill_request	0x8ffc78
#define	Blanking_SE	0x8ffcab
#define	Request_SE	0x8ffcdb
#define	Request_BGM	0x8ffd16
