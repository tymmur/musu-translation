## 宝交立ち設定 #############################################################
chara_folder	l_houkou,"chara"
chara_name	l_houkou,"宝交"
@houkou_small
@houkou_shifuku

## 消す #######################################################################
macro	houkou_
	chara_off	l_houkou
endmacro

## 距離 #######################################################################
# 遠い
macro	houkou_small
	chara_size	l_houkou,"小",0,-20
endm

# 中間
macro	houkou_middle
	chara_size	l_houkou,"中",0,-120
endm

# 近い
macro	houkou_large
	chara_size	l_houkou,"大",0,0
endm

## 服装 ######################################################################
macro	houkou_shifuku
	chara_clothes	l_houkou,"私服"
endm
macro	houkou_knife
	chara_clothes	l_houkou,"ナイフ"
endm
macro	houkou_knife2
	chara_clothes	l_houkou,"ナイフ2"
endm
macro	houkou_knife3
	chara_clothes	l_houkou,"ナイフ3"
endm


## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	houkou
	chara_auto	l_houkou,"普.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	houkou_warai
	chara_auto	l_houkou,"喜.png"
endm
#- 喜び ----------------------------------------------------------------------
macro	houkou_yorokobi
	chara_auto	l_houkou,"喜.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	houkou_ikari
	chara_auto	l_houkou,"怒.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	houkou_odoroki
	chara_auto	l_houkou,"驚.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	houkou_kanashimi
	chara_auto	l_houkou,"哀.png"
endm
#- 影 ------------------------------------------------------------------------
macro	houkou_kage
	chara_auto	l_houkou,"影.png"
endm
#- 苦 ------------------------------------------------------------------------
macro	houkou_kurushimi
	chara_auto	l_houkou,"苦.png"
endm

