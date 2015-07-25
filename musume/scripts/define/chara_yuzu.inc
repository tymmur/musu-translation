## ‚ä‚¸—§‚¿Ý’è #############################################################
chara_folder	l_yuzu,"chara"
chara_name	l_yuzu,"‚ä‚¸"
@yuzu_small
#@yuzu_shifuku
@yuzu_jyosou

## Á‚· #######################################################################
macro	yuzu_
	chara_off	l_yuzu
endmacro

## ‹——£ #######################################################################
# ‰“‚¢
macro	yuzu_small
	chara_size	l_yuzu,"¬",0,103
endm

# ’†ŠÔ
macro	yuzu_middle
	chara_size	l_yuzu,"’†",0,6
endm

# ‹ß‚¢
macro	yuzu_large
	chara_size	l_yuzu,"‘å",0,-78
endm

## •ž‘• ######################################################################
macro	yuzu_shifuku
	chara_clothes	l_yuzu,"Ž„•ž"
endm
macro	yuzu_jyosou
	chara_clothes	l_yuzu,"—‘•"
endm
macro	yuzu_seifuku
	chara_clothes	l_yuzu,"“~•ž"
	if _MONTH>6 and _MONTH<10 then chara_clothes	l_mikan,"‰Ä•ž"
endm
macro	yuzu_mizugi
	chara_clothes	l_yuzu,"…’…"
endm
macro	yuzu_pajama
	chara_clothes	l_yuzu,"ƒpƒWƒƒƒ}"
endm

## •\î ######################################################################

#- •’Ê ----------------------------------------------------------------------
macro	yuzu
	chara_auto	l_yuzu,"•.png"
endm
#- Î‚¢ ----------------------------------------------------------------------
macro	yuzu_warai
	chara_auto	l_yuzu,"Î.png"
endm
#- Æ‚ê ----------------------------------------------------------------------
macro	yuzu_tere
	chara_auto	l_yuzu,"‹Á.png"
endm
#- “{‚è ----------------------------------------------------------------------
macro	yuzu_ikari
	chara_auto	l_yuzu,"“{.png"
endm
#- •ð‚ê ----------------------------------------------------------------------
macro	yuzu_akire
	chara_auto	l_yuzu,"š}.png"
endm
#- ‹Á‚« ----------------------------------------------------------------------
macro	yuzu_odoroki
	chara_auto	l_yuzu,"‹Á.png"
endm
#- ˆ£‚µ‚Ý --------------------------------------------------------------------
macro	yuzu_kanashimi
	chara_auto	l_yuzu,"ˆ£.png"
endm
#- Šì‚Ñ --------------------------------------------------------------------
macro	yuzu_yorokobi
	chara_auto	l_yuzu,"Šì.png"
endm
