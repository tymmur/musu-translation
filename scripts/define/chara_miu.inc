## 美雨立ち設定 #############################################################
chara_folder	l_miu,"chara"
chara_name	l_miu,"美雨"
@miu_small
@miu_maid

## 消す #######################################################################
macro	miu_
	chara_off	l_miu
endmacro

## 距離 #######################################################################
# 遠い
macro	miu_small
	chara_size	l_miu,"小",-32,0
endm

# 遠い（車いす用）
macro	miu_small_kuruma
	chara_size	l_miu,"小",0,0
endm

# 中間
macro	miu_middle
	chara_size	l_miu,"中",0,-74
endm

# 中間（車いす用）
macro	miu_middle_kuruma
	chara_size	l_miu,"中",0,0
endm

# 近い
macro	miu_large
	chara_size	l_miu,"大",0,-105
endm

## 服装 ######################################################################
#メイド服
macro	miu_maid
	chara_clothes	l_miu,"メイド"
endm

#メイド服(出血)
macro	miu_maid_damage
	chara_clothes	l_miu,"メイド出血"
endm

#メイド服(さらに出血)
macro	miu_maid_damage2
	chara_clothes	l_miu,"メイド出血2"
endm

#水着
macro	miu_mizugi
	chara_clothes	l_miu,"水着"
endm

#裸
macro	miu_hadaka
	chara_clothes	l_miu,"裸"
endm

#メイド服・車イス
macro	miu_kurumaisu
	chara_clothes	l_miu,"車いす"
endm


## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	miu
	chara_auto	l_miu,"閉_にこ.png"
endm
#- 普通２ ----------------------------------------------------------------------
macro	miu2
	chara_auto	l_miu,"開_にこ.png"
endm
#- 笑 ------------------------------------------------------------------------
macro	miu_niko
	chara_auto	l_miu,"笑.png"
endm
#- 笑 ------------------------------------------------------------------------
macro	miu_warai
	chara_auto	l_miu,"笑.png"
endm
#- 照れ ----------------------------------------------------------------------
macro	miu_tere
	chara_auto	l_miu,"開_照.png"
endm
#- 照れ２ --------------------------------------------------------------------
macro	miu_tere2
	chara_auto	l_miu,"閉_照.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	miu_odoroki
	chara_auto	l_miu,"開_普通.png"
endm
#- 困る ----------------------------------------------------------------------
macro	miu_komaru
	chara_auto	l_miu,"開_困.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	miu_kanashimi
	chara_auto	l_miu,"開_哀.png"
endm
#- 哀しみ２ ------------------------------------------------------------------
macro	miu_kanashimi2
	chara_auto	l_miu,"閉_哀.png"
endm
#- コミカル汗 ----------------------------------------------------------------
macro	miu_komikaru_ase
	chara_auto	l_miu,"コミカル汗.png"
endm
macro	miu_ase
	chara_auto	l_miu,"コミカル汗.png"
endm
#- コミカル怒 ----------------------------------------------------------------
macro	miu_komikaru_ikari
	chara_auto	l_miu,"コミカル怒.png"
endm
macro	miu_ikari_c
	chara_auto	l_miu,"コミカル怒.png"
endm
#- 怒 ------------------------------------------------------------------------
macro	miu_ikari
	chara_auto	l_miu,"閉_怒.png"
endm
#- 怒２ ----------------------------------------------------------------------
macro	miu_ikari2
	chara_auto	l_miu,"開_怒.png"
endm
#- 無表情 ----------------------------------------------------------------------
macro	miu_mu
	chara_auto	l_miu,"開_普通.png"
endm


#- 普（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma
	chara_auto	l_miu,"普.png"
endm
#- 喜（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_yorokobi
	chara_auto	l_miu,"喜.png"
endm
#- 笑（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_warai
	chara_auto	l_miu,"笑.png"
endm
#- 驚（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_odoroki
	chara_auto	l_miu,"驚.png"
endm
#- 哀（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_kanashimi
	chara_auto	l_miu,"哀.png"
endm
#- 怒（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_ikari
	chara_auto	l_miu,"怒.png"
endm
#- 真剣（車いす専用） ----------------------------------------------------------------------
macro	miu_kuruma_shinken
	chara_auto	l_miu,"真剣.png"
endm





