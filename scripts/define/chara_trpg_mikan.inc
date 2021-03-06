## TRPGいつき立ち設定 #########################################################
chara_folder	l_trpg_mikan,"chara"
chara_name	l_trpg_mikan,"TRPGみかん"
@trpg_mikan_small
@trpg_mikan_shifuku

## 消す #######################################################################
macro	trpg_mikan_
	layer_fadeout	l_trpg_mikan
	trpg_mikan_flag=0
endmacro

## 距離 #######################################################################
# 遠い
macro	trpg_mikan_small
	chara_size	l_trpg_mikan,"小",0,0
endm

# 中間
macro	trpg_mikan_middle
	chara_size	l_trpg_mikan,"中",0,6
endm

# 近い
macro	trpg_mikan_large
	chara_size	l_trpg_mikan,"大",0,-78
endm

## 服装 ######################################################################
macro	trpg_mikan_shifuku
	chara_clothes	l_trpg_mikan,"私服"
endm

macro	trpg_mikan_in
	if trpg_mikan_flag=0 then layer_move	l_trpg_mikan,1000,320,0,0,0,PASSTYPE_BEZIER_A
	trpg_mikan_flag=1
endm

## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	trpg_mikan
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\普.png",420,0
	@trpg_mikan_in
endm
#- 怒り ----------------------------------------------------------------------
macro	trpg_mikan_ikari
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\怒.png",420,0
	@trpg_mikan_in
endm
#- 照れ ----------------------------------------------------------------------
macro	trpg_mikan_tere
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\照.png",420,0
	@trpg_mikan_in
endm
#- 驚き ----------------------------------------------------------------------
macro	trpg_mikan_odoroki
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\驚.png",420,0
	@trpg_mikan_in
endm
#- 哀しみ --------------------------------------------------------------------
macro	trpg_mikan_kanashimi
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\哀.png",420,0
	@trpg_mikan_in
endm
#- 喜び --------------------------------------------------------------------
macro	trpg_mikan_yorokobi
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\喜.png",420,0
	@trpg_mikan_in
endm
macro	trpg_mikan_warai
	@trpg_mikan_yorokobi
endm
#- 必殺 --------------------------------------------------------------------
macro	trpg_mikan_special
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\必殺.png",420,0
endm
#- やられ ------------------------------------------------------------------
macro	trpg_mikan_damage
	chara		l_trpg_mikan,"chara\trpgみかん\小\私服\やられ.png",420,0
	layer_move	l_trpg_mikan,500,0,0,120,0,PASSTYPE_BEZIER_A

endm
