## TRPG‚¢‚¿‚²—§‚¿İ’è #########################################################
chara_folder	l_trpg_ichigo,"chara"
chara_name	l_trpg_ichigo,"TRPG‚¢‚¿‚²"
@trpg_ichigo_small
@trpg_ichigo_shifuku

## Á‚· #######################################################################
macro	trpg_ichigo_
	layer_fadeout	l_trpg_ichigo
	trpg_ichigo_flag=0
endmacro

## ‹——£ #######################################################################
# ‰“‚¢
macro	trpg_ichigo_small
	chara_size	l_trpg_ichigo,"¬",0,-32
endm

# ’†ŠÔ
macro	trpg_ichigo_middle
	chara_size	l_trpg_ichigo,"’†",0,6
endm

# ‹ß‚¢
macro	trpg_ichigo_large
	chara_size	l_trpg_ichigo,"‘å",0,-78
endm

## •‘• ######################################################################
macro	trpg_ichigo_shifuku
	chara_clothes	l_trpg_ichigo,"„•"
endm

macro	trpg_ichigo_motion_default
	layer_movepass_add	l_trpg_ichigo,0,	0,	0,0
	layer_movepass_add	l_trpg_ichigo,0,	500,	0,4
	layer_movepass_add	l_trpg_ichigo,0,	500,	0,0
	layer_movepass_add	l_trpg_ichigo,0,	500,	0,-4
	layer_movepass_add	l_trpg_ichigo,0,	500,	0,0
	layer_movepass_type	l_trpg_ichigo,0,	PASSTYPE_TCB
	layer_movepass_play	l_trpg_ichigo,0,	play_loop
endm

macro	trpg_ichigo_in
	if trpg_ichigo_flag=0 then screen_effect_stardust	600,0,200,200
	if trpg_ichigo_flag=0 then layer_scale	l_trpg_ichigo,500,-99,400,0,0,PASSTYPE_BEZIER_A
	if trpg_ichigo_flag=0 then wait	500
	trpg_ichigo_flag=1
endm

## •\î ######################################################################

#- •’Ê ----------------------------------------------------------------------
macro	trpg_ichigo
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\•.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
#- “{‚è ----------------------------------------------------------------------
macro	trpg_ichigo_ikari
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\“{.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
#- Æ‚ê ----------------------------------------------------------------------
macro	trpg_ichigo_tere
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\Æ.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
#- ‹Á‚« ----------------------------------------------------------------------
macro	trpg_ichigo_odoroki
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\‹Á.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
#- ˆ£‚µ‚İ --------------------------------------------------------------------
macro	trpg_ichigo_kanashimi
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\ˆ£.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
#- Šì‚Ñ --------------------------------------------------------------------
macro	trpg_ichigo_yorokobi
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\Šì.png",540,-64
	@trpg_ichigo_in
	@trpg_ichigo_motion_default
endm
macro	trpg_ichigo_warai
	@trpg_ichigo_yorokobi
endm
#- •KE --------------------------------------------------------------------
macro	trpg_ichigo_special
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\•Â.png",540,-64
	@trpg_ichigo_motion_default
endm
#- ‚â‚ç‚ê ------------------------------------------------------------------
macro	trpg_ichigo_damage
	chara	l_trpg_ichigo,"chara\trpg‚¢‚¿‚²\¬\„•\‚â‚ç‚ê.png",540,-64
	@trpg_ichigo_motion_default
endm
