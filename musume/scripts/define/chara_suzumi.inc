## —ÁŠC—§‚¿İ’è #############################################################
chara_folder	l_suzumi,"chara"
chara_name	l_suzumi,"—ÁŠC"
@suzumi_small
@suzumi_shifuku

## Á‚· #######################################################################
macro	suzumi_
	chara_off	l_suzumi
endmacro

## ‹——£ #######################################################################
# ‰“‚¢
macro	suzumi_small
	chara_size	l_suzumi,"¬",0,145
endm

# ’†ŠÔ
macro	suzumi_middle
	chara_size	l_suzumi,"’†",0,0
endm

# ‹ß‚¢
macro	suzumi_large
	chara_size	l_suzumi,"‘å",0,0
endm

## •‘• ######################################################################
macro	suzumi_shifuku
	chara_clothes	l_suzumi,"„•"
endm


## •\î ######################################################################

#- •’Ê ----------------------------------------------------------------------
macro	suzumi
	chara_auto	l_suzumi,"•.png"
endm
#- Î‚¢ ----------------------------------------------------------------------
macro	suzumi_warai
	chara_auto	l_suzumi,"Î.png"
endm
#- “{‚è ----------------------------------------------------------------------
macro	suzumi_ikari
	chara_auto	l_suzumi,"“{.png"
endm
#- •ğ‚ê ----------------------------------------------------------------------
macro	suzumi_niko
	chara_auto	l_suzumi,"‚É‚±.png"
endm
#- ‹Á‚« ----------------------------------------------------------------------
macro	suzumi_odoroki
	chara_auto	l_suzumi,"‹Á.png"
endm
#- ˆ£‚µ‚İ --------------------------------------------------------------------
macro	suzumi_kanashimi
	chara_auto	l_suzumi,"ˆ£.png"
endm
#- ‹ƒ‚«1 --------------------------------------------------------------------
macro	suzumi_naki
	chara_auto	l_suzumi,"‹ƒ1.png"
endm
#- ‹ƒ‚«2 --------------------------------------------------------------------
macro	suzumi_naki2
	chara_auto	l_suzumi,"‹ƒ2.png"
endm
#- ƒRƒ~ƒJƒ‹“{ --------------------------------------------------------------
macro	suzumi_komical_ikari
	chara_auto	l_suzumi,"ƒRƒ~ƒJƒ‹“{.png"
endm
macro	suzumi_comical_ikari
	@suzumi_komical_ikari
endm
macro	suzumi_ikari_c
	@suzumi_komical_ikari
endm
