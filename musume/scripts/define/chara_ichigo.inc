## いちご立ち設定 #############################################################
chara_folder	l_ichigo,"chara"
chara_name	l_ichigo,"いちご"
@ichigo_small
@ichigo_shifuku

## 消す #######################################################################
macro	ichigo_
	chara_off	l_ichigo
endmacro

## 距離 #######################################################################
# 遠い
macro	ichigo_small
	chara_size	l_ichigo,"小",0,74
endm

# 中間
macro	ichigo_middle
	chara_size	l_ichigo,"中",0,-40
endm

# 近い
macro	ichigo_large
	chara_size	l_ichigo,"大",0,0
endm

## 服装 ######################################################################
macro	ichigo_shifuku
	chara_clothes	l_ichigo,"私服"
endm
macro	ichigo_yukata
	chara_clothes	l_ichigo,"浴衣"
endm
macro	ichigo_shitagi
	chara_clothes	l_ichigo,"下着"
endm
macro	ichigo_seifuku
	chara_clothes	l_ichigo,"冬服"
endm
macro	ichigo_pajama
	chara_clothes	l_ichigo,"パジャマ"
endm
macro	ichigo_mizugi
	chara_clothes	l_ichigo,"水着"
endm
macro	ichigo_hadaka
	chara_clothes	l_ichigo,"裸"
endm

## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	ichigo
	chara_auto	l_ichigo,"普通.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	ichigo_warai
	chara_auto	l_ichigo,"笑.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	ichigo_ikari
	chara_auto	l_ichigo,"怒.png"
endm
#- 呆れ ----------------------------------------------------------------------
macro	ichigo_akire
	chara_auto	l_ichigo,"呆れ.png"
endm
#- 放心 ----------------------------------------------------------------------
macro	ichigo_houshin
	chara_auto	l_ichigo,"放心.png"
endm
#- 欲情_喜び -----------------------------------------------------------------
macro	ichigo_yokujyou_yorokobi
	chara_auto	l_ichigo,"欲情_喜.png"
endm
#- 欲情 ----------------------------------------------------------------------
macro	ichigo_yokujou
	chara_auto	l_ichigo,"欲情_普通.png"
endm
#- 照れ ----------------------------------------------------------------------
macro	ichigo_tere
	chara_auto	l_ichigo,"照れ.png"
endm
#- 困る ----------------------------------------------------------------------
macro	ichigo_komaru
	chara_auto	l_ichigo,"困.png"
endm
#- 苦しい --------------------------------------------------------------------
macro	ichigo_kurushii
	chara_auto	l_ichigo,"苦.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	ichigo_odoroki
	chara_auto	l_ichigo,"驚.png"
endm
#- 泣き ----------------------------------------------------------------------
macro	ichigo_naki
	chara_auto	l_ichigo,"泣.png"
endm
#- 喜び ----------------------------------------------------------------------
macro	ichigo_yorokobi
	chara_auto	l_ichigo,"喜.png"
endm
#- 企み ----------------------------------------------------------------------
macro	ichigo_takurami
	chara_auto	l_ichigo,"企み.png"
endm
#- 汗 ------------------------------------------------------------------------
macro	ichigo_ase
	chara_auto	l_ichigo,"汗.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	ichigo_kanashimi
	chara_auto	l_ichigo,"哀.png"
endm
#- コミカル怒り --------------------------------------------------------------
macro	ichigo_komikaru_ikari
	chara_auto	l_ichigo,"コミカル怒.png"
endm
macro	ichigo_ikari_c
	chara_auto	l_ichigo,"コミカル怒.png"
endm
#- コミカル笑い --------------------------------------------------------------
macro	ichigo_komikaru_warai
	chara_auto	l_ichigo,"コミカル笑.png"
endm
macro	ichigo_warai_c
	@ichigo_komikaru_warai
endm
#- コミカル驚き --------------------------------------------------------------
macro	ichigo_komikaru_odoroki
	chara_auto	l_ichigo,"コミカル驚.png"
endm
#- コミカル疑問 --------------------------------------------------------------
macro	ichigo_gimon
	chara_auto	l_ichigo,"コミカル疑問.png"
endm

