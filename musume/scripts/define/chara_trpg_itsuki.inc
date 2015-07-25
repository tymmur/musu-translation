## TRPG‚¢‚Â‚«—§‚¿İ’è #########################################################
chara_folder	l_trpg_itsuki,"chara"
chara_name	l_trpg_itsuki,"TRPG÷"
@trpg_itsuki_small
@trpg_itsuki_shifuku

## Á‚· #######################################################################
macro	trpg_itsuki_
#	if trpg_itsuki_flag=1 then layer_move	l_trpg_itsuki,250,0,0,320,0,passtype_tcb
	trpg_itsuki_flag=0
	layer_fadeout	l_trpg_itsuki
endmacro

## ‹——£ #######################################################################
# ‰“‚¢
macro	trpg_itsuki_small
	chara_size	l_trpg_itsuki,"¬",0,0
endm

# ’†ŠÔ
macro	trpg_itsuki_middle
	chara_size	l_trpg_itsuki,"’†",0,6
endm

# ‹ß‚¢
macro	trpg_itsuki_large
	chara_size	l_trpg_itsuki,"‘å",0,-78
endm

## •‘• ######################################################################
macro	trpg_itsuki_shifuku
	chara_clothes	l_trpg_itsuki,"„•"
endm

macro	trpg_itsuki_in
	if trpg_itsuki_flag=0 then layer_move	l_trpg_itsuki,1000,320,0,0,0,PASSTYPE_BEZIER_A
	trpg_itsuki_flag=1
endm


## •\î ######################################################################

#- •’Ê ----------------------------------------------------------------------
macro	trpg_itsuki
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\•.png",320,0
	@trpg_itsuki_in
endm
#- “{‚è ----------------------------------------------------------------------
macro	trpg_itsuki_ikari
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\“{.png",320,0
	@trpg_itsuki_in
endm
#- ‹Á‚« ----------------------------------------------------------------------
macro	trpg_itsuki_odoroki
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\‹Á.png",320,0
	@trpg_itsuki_in
endm
#- ˆ£‚µ‚İ --------------------------------------------------------------------
macro	trpg_itsuki_kanashimi
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\ˆ£.png",320,0
	@trpg_itsuki_in
endm
#- Šì‚Ñ --------------------------------------------------------------------
macro	trpg_itsuki_yorokobi
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\Šì.png",320,0
	@trpg_itsuki_in
endm
macro	trpg_itsuki_warai
	@trpg_itsuki_yorokobi
	@trpg_itsuki_in
endm
#- •KE --------------------------------------------------------------------
macro	trpg_itsuki_special
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\•KE.png",320,0
endm
#- ‚â‚ç‚ê ------------------------------------------------------------------
macro	trpg_itsuki_damage
	chara	l_trpg_itsuki,"chara\trpg÷\¬\„•\‚â‚ç‚ê.png",320,0
	layer_move	l_trpg_itsuki,500,0,0,120,0,PASSTYPE_BEZIER_A
endm
