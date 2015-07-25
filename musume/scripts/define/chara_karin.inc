## かりん立ち設定 #############################################################
chara_folder	l_karin,"chara"
chara_name	l_karin,"かりん"
@karin_small
@karin_shifuku

## 消す #######################################################################
macro	karin_
	chara_off	l_karin
endmacro

## 距離 #######################################################################
# 遠い
macro	karin_small
	chara_size	l_karin,"小",0,128
endm

# 中間
macro	karin_middle
	chara_size	l_karin,"中",0,21
endm

# 近い
macro	karin_large
	chara_size	l_karin,"大",0,11
endm

## 服装 ######################################################################
macro	karin_shifuku
	chara_clothes	l_karin,"私服"
endm
macro	karin_shifuku_dere
	chara_clothes	l_karin,"私服デレ"
endm
macro	karin_heyagi
	chara_clothes	l_karin,"部屋着"
endm
macro	karin_shitagi
	chara_clothes	l_karin,"下着"
endm
macro	karin_seifuku
	chara_clothes	l_karin,"冬服"
	if _MONTH>6 and _MONTH<10 then chara_clothes	l_karin,"夏服"
endm
macro	karin_pajama
	chara_clothes	l_karin,"部屋着"
endm
macro	karin_pajama_dere
	chara_clothes	l_karin,"部屋着デレ"
endm
macro	karin_yukata
	chara_clothes	l_karin,"浴衣"
endm
macro	karin_mizugi
	chara_clothes	l_karin,"水着"
endm
macro	karin_hadaka
	chara_clothes	l_karin,"裸"
endm
macro	karin_bondage
	chara_clothes	l_karin,"ボンデージ"
endm
macro	karin_bondage_dere
	chara_clothes	l_karin,"ボンデージデレ"
endm

## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	karin
	chara_auto	l_karin,"普通.png"
endm
#- 放心 ----------------------------------------------------------------------
macro	karin_houshin
	chara_auto	l_karin,"放心.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	karin_warai
	chara_auto	l_karin,"笑.png"
endm
#- てれ ----------------------------------------------------------------------
macro	karin_tere
	chara_auto	l_karin,"照.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	karin_ikari
	chara_auto	l_karin,"怒.png"
endm
#- 呆れ ----------------------------------------------------------------------
macro	karin_akire
	chara_auto	l_karin,"嫌悪.png"
endm
#- 侮蔑 ----------------------------------------------------------------------
macro	karin_bubetsu
	chara_auto	l_karin,"侮蔑.png"
endm
#- 嫌悪 ----------------------------------------------------------------------
macro	karin_keno
	chara_auto	l_karin,"嫌悪.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	karin_odoroki
	chara_auto	l_karin,"驚.png"
endm
#- 興奮 ----------------------------------------------------------------------
macro	karin_koufun
	chara_auto	l_karin,"興奮.png"
endm
#- 興奮ｎ ----------------------------------------------------------------------
macro	karin_koufun_n
	chara_auto	l_karin,"興奮n.png"
endm
#- 泣き ----------------------------------------------------------------------
macro	karin_naki
	chara_auto	l_karin,"泣.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	karin_kanashimi
	chara_auto	l_karin,"哀.png"
endm
#- にこ ----------------------------------------------------------------------
macro	karin_niko
	chara_auto	l_karin,"にこ.png"
endm
#- コミカル怒り --------------------------------------------------------------
macro	karin_komikaru_ikari
	chara_auto	l_karin,"コミカル怒.png"
endm
macro	karin_ikari_c
	chara_auto	l_karin,"コミカル怒.png"
endm
#- コミカル怒りｎ --------------------------------------------------------------
macro	karin_komikaru_ikari_n
	chara_auto	l_karin,"コミカル怒n.png"
endm
#- コミカル怒り2 --------------------------------------------------------------
macro	karin_komikaru_ikari2
	chara_auto	l_karin,"コミカル怒2.png"
endm
#- コミカル欲 --------------------------------------------------------------
macro	karin_komikaru_yoku
	chara_auto	l_karin,"コミカル欲.png"
endm
macro	karin_yoku
	chara_auto	l_karin,"コミカル欲.png"
endm
#- コミカル欲ｎ --------------------------------------------------------------
macro	karin_komikaru_yoku_n
	chara_auto	l_karin,"コミカル欲n.png"
endm
#- コミカル涙 --------------------------------------------------------------
macro	karin_komikaru_namida
	chara_auto	l_karin,"コミカル涙.png"
endm

