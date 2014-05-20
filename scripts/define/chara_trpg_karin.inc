## TRPG‚¢‚Â‚«—§‚¿İ’è #########################################################
chara_folder	l_trpg_karin,"chara"
chara_name	l_trpg_karin,"TRPG‚©‚è‚ñ"
@trpg_karin_small
@trpg_karin_shifuku

## Á‚· #######################################################################
macro	trpg_karin_
	layer_fadeout	l_trpg_karin
	trpg_karin_flag=0
endmacro

## ‹——£ #######################################################################
# ‰“‚¢
macro	trpg_karin_small
	chara_size	l_trpg_karin,"¬",0,0
endm

# ’†ŠÔ
macro	trpg_karin_middle
	chara_size	l_trpg_karin,"’†",0,6
endm

# ‹ß‚¢
macro	trpg_karin_large
	chara_size	l_trpg_karin,"‘å",0,-78
endm

## •‘• ######################################################################
macro	trpg_karin_shifuku
	chara_clothes	l_trpg_karin,"„•"
endm

macro	trpg_karin_in
	if trpg_karin_flag=0 then layer_move	l_trpg_karin,1000,320,0,0,0,PASSTYPE_BEZIER_A
	trpg_karin_flag=1
endm

## •\î ######################################################################

#- •’Ê ----------------------------------------------------------------------
macro	trpg_karin
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\•.png",550,0
	@trpg_karin_in
endm
#- “{‚è ----------------------------------------------------------------------
macro	trpg_karin_ikari
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\“{.png",550,0
	@trpg_karin_in
endm
#- Æ‚ê ----------------------------------------------------------------------
macro	trpg_karin_tere
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\Æ.png",550,0
	@trpg_karin_in
endm
#- ‹Á‚« ----------------------------------------------------------------------
macro	trpg_karin_odoroki
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\‹Á.png",550,0
	@trpg_karin_in
endm
#- ˆ£‚µ‚İ --------------------------------------------------------------------
macro	trpg_karin_kanashimi
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\ˆ£.png",550,0
	@trpg_karin_in
endm
#- Šì‚Ñ --------------------------------------------------------------------
macro	trpg_karin_yorokobi
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\Šì.png",550,0
	@trpg_karin_in
endm
macro	trpg_karin_warai
	@trpg_karin_yorokobi
	@trpg_karin_in
endm
#- •KE --------------------------------------------------------------------
macro	trpg_karin_special
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\–‚–@.png",550,0
endm
#- ‚â‚ç‚ê ------------------------------------------------------------------
macro	trpg_karin_damage
	chara	l_trpg_karin,"chara\trpg‚©‚è‚ñ\¬\„•\‚â‚ç‚ê.png",550,0
	layer_move	l_trpg_karin,500,0,0,120,0,PASSTYPE_BEZIER_A
endm
