## ひかり設定 #################################################################
chara_folder	l_hikari,"chara"
chara_name	l_hikari,"ひかり"
@hikari_small
@hikari_shifuku

## 消す #######################################################################
macro	hikari_
	chara_off	l_hikari
	layer_release	l_hikari+1
endmacro
macro	hikari2_
	chara_off	l_hikari
	layer_release	l_hikari+1
endmacro

## 距離 #######################################################################
# 遠い
macro	hikari_small
	chara_size	l_hikari,"小",0,130
	hikari_size=0
endm

# 中間
macro	hikari_middle
	chara_size	l_hikari,"中",0,99
	hikari_size=1
endm

# 近い
macro	hikari_large
	chara_size	l_hikari,"大",0,93
	hikari_size=2
endm

## 服装 ######################################################################
macro	hikari_shifuku
	chara_clothes	l_hikari,"私服"
endm
macro	hikari_pajama
	chara_clothes	l_hikari,"パジャマ"
endm
macro	hikari_shitagi
	chara_clothes	l_hikari,"下着"
endm
macro	hikari_mizugi
	chara_clothes	l_hikari,"水着"
endm
macro	hikari_hadaka
	chara_clothes	l_hikari,"裸"
endm

## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	hikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"普.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	hikari_ikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"怒.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	hikari_ikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"怒2.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	hikari_warai
	layer_release	l_hikari+1
	chara_auto	l_hikari,"笑.png"
endm
#- 照れ ----------------------------------------------------------------------
macro	hikari_tere
	layer_release	l_hikari+1
	chara_auto	l_hikari,"照.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	hikari_odoroki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"驚.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	hikari_kanashimi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"哀.png"
endm
#- にこ ----------------------------------------------------------------------
macro	hikari_yorokobi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"喜.png"
endm
#- 泣き ----------------------------------------------------------------------
macro	hikari_naki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"泣.png"
endm
#- 困る ----------------------------------------------------------------------
macro	hikari_komaru
	layer_release	l_hikari+1
	chara_auto	l_hikari,"困.png"
endm

macro	hikari_gimon
	layer_release	l_hikari+1
	chara_auto	l_hikari,"普.png"
endm


#- 普通 ----------------------------------------------------------------------
macro	hikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"普.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	hikari2_ikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"怒2.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	hikari2_ikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"怒.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	hikari2_warai
	layer_release	l_hikari+1
	chara_auto	l_hikari,"笑.png"
	if hikari2_size=0 then chara	l_hikari+1,"chara\マーク\てんてんマーク_小.png"
	if hikari2_size=1 then chara	l_hikari+1,"chara\マーク\てんてんマーク_小.png"
	if hikari2_size=2 then chara	l_hikari+1,"chara\マーク\てんてんマーク.png"
	layer_reference_set	l_hikari+1,l_hikari
	if hikari_size=0 then layer_position		l_hikari+1,250,60
	if hikari_size=1 then layer_position		l_hikari+1,350,60
	if hikari_size=2 then layer_position		l_hikari+1,400,40
	layer_scalepass_add 	l_hikari+1,0,	500,30,30
	layer_scalepass_add 	l_hikari+1,0,	500,0,0
	layer_scalepass_play	l_hikari+1,0,	PLAY_LOOP

endm
#- 照れ ----------------------------------------------------------------------
macro	hikari2_tere
	layer_release	l_hikari+1
	chara_auto	l_hikari,"照.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	hikari2_odoroki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"驚.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	hikari2_kanashimi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"哀.png"
endm
#- にこ ----------------------------------------------------------------------
macro	hikari2_yorokobi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"喜.png"
endm
#- 泣き ----------------------------------------------------------------------
macro	hikari2_naki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"泣.png"
endm
#- 困る ----------------------------------------------------------------------
macro	hikari2_komaru
	layer_release	l_hikari+1
	chara_auto	l_hikari,"困.png"
endm

macro	hikari2_gimon
	layer_release	l_hikari+1
	chara_auto	l_hikari,"普.png"
	if hikari_size=0 then chara	l_hikari+1,"chara\マーク\はてなマーク.png"

	layer_reference_set	l_hikari+1,l_hikari
	layer_position		l_hikari+1,80,40
	layer_movepass_add	l_hikari+1,0,0,0,0
	layer_movepass_add	l_hikari+1,0,2000,-32,-32
	layer_movepass_play	l_hikari+1,0,play_once
	layer_alpha		l_hikari+1,2000,-255,0,passtype_tcb
endm
