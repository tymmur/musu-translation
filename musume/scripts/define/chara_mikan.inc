## みかん立ち設定 #############################################################
chara_folder	l_mikan,"chara"
chara_name	l_mikan,"みかん"
@mikan_small
@mikan_shifuku

## 消す #######################################################################
macro	mikan_
	chara_off	l_mikan
endmacro

## 距離 #######################################################################
# 遠い
macro	mikan_small
	layer_release	l_mikan
	chara_size	l_mikan,"小",0,98
endm

# 中間
macro	mikan_middle
	layer_release	l_mikan
	chara_size	l_mikan,"中",0,0
endm

# 近い
macro	mikan_large
	layer_release	l_mikan
	chara_size	l_mikan,"大",0,0
endm

## 服装 ######################################################################
macro	mikan_shifuku
	chara_clothes	l_mikan,"私服"
endm
macro	mikan_seifuku
	chara_clothes	l_mikan,"冬服"
	if _MONTH>6 and _MONTH<10 then chara_clothes	l_mikan,"夏服"
endm
macro	mikan_pajama
	chara_clothes	l_mikan,"パジャマ"
endm
macro	mikan_bondage
	chara_clothes	l_mikan,"ボンデージ"
endm
macro	mikan_hadaka
	chara_clothes	l_mikan,"裸"
endm
macro	mikan_yukata
	chara_clothes	l_mikan,"浴衣"
endm
macro	mikan_mizugi
	chara_clothes	l_mikan,"水着"
endm

## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	mikan
	chara_auto	l_mikan,"普通.png"
endm
#- 普通(欲情) ----------------------------------------------------------------
macro	mikan2
	chara_auto	l_mikan,"欲情_普通.png"
endm
#- 喜 ------------------------------------------------------------------------
macro	mikan_yorokobi
	chara_auto	l_mikan,"喜.png"
endm
#- 喜(欲情) ------------------------------------------------------------------
macro	mikan_yorokobi2
	chara_auto	l_mikan,"欲情_喜.png"
endm
#- てれ ------------------------------------------------------------------
macro	mikan_tere
	chara_auto	l_mikan,"欲情_喜.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	mikan_ikari
	chara_auto	l_mikan,"怒.png"
endm
#- 真剣怒り ------------------------------------------------------------------
macro	mikan_shinkenikari
	chara_auto	l_mikan,"真剣怒り.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	mikan_warai
	chara_auto	l_mikan,"笑.png"
endm
#- 笑い2 ---------------------------------------------------------------------
macro	mikan_warai2
	chara_auto	l_mikan,"笑2.png"
endm
#- 苦笑 ---------------------------------------------------------------------
macro	mikan_kusyou
	chara_auto	l_mikan,"苦笑.png"
endm
macro	mikan_komaru
	chara_auto	l_mikan,"苦笑.png"
endm
#- 驚 ------------------------------------------------------------------------
macro	mikan_odoroki
	chara_auto	l_mikan,"驚.png"
	layer_movepass_add	l_mikan,0,	100,	0,32
	layer_movepass_add	l_mikan,0,	100,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
#- 泣 ------------------------------------------------------------------------
macro	mikan_naki
	chara_auto	l_mikan,"泣.png"
endm
#- 哀 ------------------------------------------------------------------------
macro	mikan_kanashimi
	chara_auto	l_mikan,"哀.png"
endm
#- 放心 ----------------------------------------------------------------------
macro	mikan_houshin
	chara_auto	l_mikan,"放心.png"
endm
#- コミカル怒り --------------------------------------------------------------
macro	mikan_komikaru_ikari
	chara_auto	l_mikan,"コミカル怒.png"
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_add	l_mikan,0,	150,	0,16
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_add	l_mikan,0,	150,	0,16
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
macro	mikan_ikari_c
	@mikan_komikaru_ikari
endm

#- コミカル笑い --------------------------------------------------------------
macro	mikan_komikaru_warai
	chara_auto	l_mikan,"コミカル笑.png"
	layer_movepass_add	l_mikan,0,	150,	8,0
	layer_movepass_add	l_mikan,0,	150,	-8,0
	layer_movepass_add	l_mikan,0,	150,	8,0
	layer_movepass_add	l_mikan,0,	150,	-8,0
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
#- コミカル哀しみ ------------------------------------------------------------
macro	mikan_komikaru_kanashimi
	chara_auto	l_mikan,"コミカル哀.png"
endm
macro	mikan_kanashimi_c
	chara_auto	l_mikan,"コミカル哀.png"
endm


macro	mikan_yokujyou2
	chara_auto	l_mikan,"欲情_喜.png"
endm
macro	mikan_yokujyou
	chara_auto	l_mikan,"欲情_普通.png"
endm
