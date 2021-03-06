## TRPGいつき立ち設定 #########################################################
chara_folder	l_trpg_itsuki,"chara"
chara_name	l_trpg_itsuki,"TRPG樹"
@trpg_itsuki_small
@trpg_itsuki_shifuku

## 消す #######################################################################
macro	trpg_itsuki_
#	if trpg_itsuki_flag=1 then layer_move	l_trpg_itsuki,250,0,0,320,0,passtype_tcb
	trpg_itsuki_flag=0
	layer_fadeout	l_trpg_itsuki
endmacro

## 距離 #######################################################################
# 遠い
macro	trpg_itsuki_small
	chara_size	l_trpg_itsuki,"小",0,0
endm

# 中間
macro	trpg_itsuki_middle
	chara_size	l_trpg_itsuki,"中",0,6
endm

# 近い
macro	trpg_itsuki_large
	chara_size	l_trpg_itsuki,"大",0,-78
endm

## 服装 ######################################################################
macro	trpg_itsuki_shifuku
	chara_clothes	l_trpg_itsuki,"私服"
endm

macro	trpg_itsuki_in
	if trpg_itsuki_flag=0 then layer_move	l_trpg_itsuki,1000,320,0,0,0,PASSTYPE_BEZIER_A
	trpg_itsuki_flag=1
endm


## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	trpg_itsuki
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\普.png",320,0
	@trpg_itsuki_in
endm
#- 怒り ----------------------------------------------------------------------
macro	trpg_itsuki_ikari
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\怒.png",320,0
	@trpg_itsuki_in
endm
#- 驚き ----------------------------------------------------------------------
macro	trpg_itsuki_odoroki
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\驚.png",320,0
	@trpg_itsuki_in
endm
#- 哀しみ --------------------------------------------------------------------
macro	trpg_itsuki_kanashimi
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\哀.png",320,0
	@trpg_itsuki_in
endm
#- 喜び --------------------------------------------------------------------
macro	trpg_itsuki_yorokobi
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\喜.png",320,0
	@trpg_itsuki_in
endm
macro	trpg_itsuki_warai
	@trpg_itsuki_yorokobi
	@trpg_itsuki_in
endm
#- 必殺 --------------------------------------------------------------------
macro	trpg_itsuki_special
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\必殺.png",320,0
endm
#- やられ ------------------------------------------------------------------
macro	trpg_itsuki_damage
	chara	l_trpg_itsuki,"chara\trpg樹\小\私服\やられ.png",320,0
	layer_move	l_trpg_itsuki,500,0,0,120,0,PASSTYPE_BEZIER_A
endm
