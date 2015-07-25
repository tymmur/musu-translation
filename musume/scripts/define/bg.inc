macro	bg_init
	layer_release	1
	layer_release	2
	se_stop		1
	se_bg_stop
	screen_effect_snow_off
	screen_effect_rain_off
	screen_effect_storm_off
	if kaisou_flag=0 then screen_color_set 	0,0,0
endm
# ‰ñ‘zƒtƒBƒ‹ƒ^[ -------------------------------------------------------------
macro	kaisou
	screen_color_set 	32,0,-16
	kaisou_flag=1
endm
# ‰ñ‘zƒtƒBƒ‹ƒ^[ƒIƒt ---------------------------------------------------------
macro	kaisou_off
	screen_color_set 	0,0,0
	kaisou_flag=0
endm
# • -------------------------------------------------------------------------
macro	bg_black
	@bg_init
	@chara_clear
	bg	"cg\bg\black.png"
endm
# ”’ -------------------------------------------------------------------------
macro	bg_white
	@bg_init
	@chara_clear
	bg	"cg\bg\white.png"
endm
# Ô -------------------------------------------------------------------------
macro	bg_red
	@bg_init
	bg	"cg\bg\red.png"
endm
# Ô -------------------------------------------------------------------------
macro	bg_pink
	@bg_init
layer_movie_load 	1,"system\movie\‰ñ•œ2.mpg",play_loop
layer_position_set	1,240,180
layer_scale_set		1,250,250
layer_drawmode_set	1,DRAW_ADD
	bg	"cg\bg\pink.png"
endm
# ‹ó -------------------------------------------------------------------------
macro	bg_sky
	@bg_init
	bg	"cg\bg\sky.png"
endm
# “Ü‹ó ----------------------------------------------------------------------
macro	bg_sky_k
	@bg_init
	bg	"cg\bg\bg02_‚­‚à‚è.png"
endm
# —[•û‚Ì‹ó -------------------------------------------------------------------
macro	bg_sky_y
	@bg_init
	bg	"cg\bg\—[•û.png"
endm
# –é‹ó -----------------------------------------------------------------------
macro	bg_sky_n
	@bg_init
	bg	"cg\bg\–é‹ó.png"
endm
# –é‹ó2 -----------------------------------------------------------------------
macro	bg_sky2_n
	@bg_init
	bg	"cg\bg\–é‹ó2.png"
endm
# ‰J‹ó -----------------------------------------------------------------------
macro	bg_sky_ame
	@bg_init
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\‰J‹ó.png"
endm
# “V‚Ìì --------------------------------------------------------------------
macro	bg_sky_amaanogawa
	@bg_init
	bg	"cg\bg\“V‚Ìì.png"
endm
# ‹ó(c’·) ------------------------------------------------------------------
macro	bg_sky2
	@bg_init
	layer_load	0,"cg\bg\sky2.png"
	layer_load	1,"cg\bg\bg01ŒÇ™‰@‘O_“§–¾.png"
	screen_blackin	2000
	layer_move	0,40000,0,-300,0,0,passtype_tcb
	layer_move	1,40000,0,0,0,600,passtype_tcb
endm
# ‹ó(c’·)/ŒÇ™‰@–³‚µ---------------------------------------------------------
macro	bg_sky3
	@bg_init
	layer_load	0,"cg\bg\sky3.png"
	screen_blackin	1000
	layer_move	0,10000,0,-400,0,0,passtype_tcb
endm
# ŒŒ­ -----------------------------------------------------------------------
macro	bg_kekkon
	@bg_init
	bg	"cg\bg\bg_kekkon.png"
endm
# ŒŒ­2 -----------------------------------------------------------------------
macro	bg_kekkon2
	@bg_init
	layer_load	0,"cg\bg\bg_kekkon.png"
endm
# ƒQ[ƒ€ƒI[ƒo[ -------------------------------------------------------------
macro	bg_gameover
	@bg_init
	bg	"cg\bg\gameover.png"
endm
# ƒQ[ƒ€ƒI[ƒo[2 -------------------------------------------------------------
macro	bg_gameover2
	@bg_init
	bg	"cg\bg\gameover2.png"
endm
# ƒXƒPƒWƒ…[ƒ‹—p”wŒi ---------------------------------------------------------
macro	bg_schedule
	@bg_init
	layer_load_overlap	0,"cg\bg\‹ó‘±‚«.png"
	layer_load	1,"cg\bg\bg01ŒÇ™‰@‘O_“§–¾.png"
	screen_blackin	500
	layer_move	0,4000,0,-500,0,0,passtype_linear
#	layer_move	1,40000,0,600,0,0,passtype_tcb
	layer_position	1,0,150
endm


###############################################################################


# ’¬ --------------------------------------------------------------------------
macro	bg_machi
	@bg_init
	se_bg	"sound\se\BG_ŠX2.ogg"
	bg	"cg\bg\bg_machi.png"
endm
# ‰w‘O ------------------------------------------------------------------------
macro	bg_ekimae
	@bg_init
	se_bg	"sound\se\BG_‰w‘O.ogg"
	bg	"cg\bg\bg_ekimae.png"
endm
# ¤“XŠX ----------------------------------------------------------------------
macro	bg_syoutengai
	@bg_init
	se_bg	"sound\se\BG_¤“XŠX.ogg"
	bg	"cg\bg\¤“XŠX.png"
endm
# ¤“XŠX(“Ü) -----------------------------------------------------------------
macro	bg_syoutengai_k
	@bg_init
	se_bg	"sound\se\BG_¤“XŠX.ogg"
	bg	"cg\bg\¤“XŠX_“Ü.png"
endm
# ¤“XŠX(‰J) -----------------------------------------------------------------
macro	bg_syoutengai_a
	@bg_init
#	screen_effect_rain	200,1
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\¤“XŠX_“Ü.png"
endm
# ¤“XŠX(—[•û) ---------------------------------------------------------------
macro	bg_syoutengai_y
	@bg_init
	se_bg	"sound\se\BG_¤“XŠX.ogg"
	bg	"cg\bg\¤“XŠX_—[•û.png"
endm
# ’…º ----------------------------------------------------------------------
macro	bg_fittingroom
	@bg_init
#	se_bg	"sound\se\BG_¤“XŠX.ogg"
	bg	"cg\bg\’…º.png"
endm
# ”É‰ØŠX ----------------------------------------------------------------------
macro	bg_hankagai
	@bg_init
	se_bg	"sound\se\BG_”É‰ØŠX.ogg"
	bg	"cg\bg\bg_hankagai.png"
endm
# ”É‰ØŠX ----------------------------------------------------------------------
macro	bg_hankagai_n
	@bg_init
	se_bg	"sound\se\BG_”É‰ØŠX.ogg"
	bg	"cg\bg\bg_hankagai_n.png"
endm
# Z‘îŠX ----------------------------------------------------------------------
macro	bg_jyuutakugai
	@bg_init
	se_bg	"sound\se\BG_Ã‚©‚ÈZ‘îŠX‚È‚Ç.ogg"
	bg	"cg\bg\Z‘îŠX.png"
endm
# Z‘îŠX(“Ü) ------------------------------------------------------------------
macro	bg_jyuutakugai_k
	@bg_init
	se_bg	"sound\se\BG_Ã‚©‚ÈZ‘îŠX‚È‚Ç.ogg"
	bg	"cg\bg\Z‘îŠX_“Ü.png"
endm
# Z‘îŠX(‰J) ------------------------------------------------------------------
macro	bg_jyuutakugai_a
	@bg_init
	screen_effect_rain	200,1
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\Z‘îŠX_“Ü.png"
endm
# Z‘îŠX (—[•û) --------------------------------------------------------------
macro	bg_jyuutakugai_y
	@bg_init
	se_bg	"sound\se\BG_Ã‚©‚ÈZ‘îŠX‚È‚Ç.ogg"
	bg	"cg\bg\Z‘îŠX_—[•û.png"
endm
# Z‘îŠX (–é)-----------------------------------------------------------------
macro	bg_jyuutakugai_n
	@bg_init
	bg	"cg\bg\Z‘îŠX_–é.png"
endm
# ’ç–h ----------------------------------------------------------------------
macro	bg_teibou
	@bg_init
	se_bg	"sound\se\BG_’ç–h.ogg"
	bg	"cg\bg\’ç–h.png"
endm
# Õ‚è ----------------------------------------------------------------------
macro	bg_matsuri
	@bg_init
	se_bg	"sound\se\BG_‚¨Õ‚è`o“X‘O.ogg"
	bg	"cg\bg\bg_maturi.png"
endm
# ˜H’n—  ----------------------------------------------------------------------
macro	bg_rojiura
	@bg_init
	bg	"cg\bg\˜H’n— .png"
endm
# @{İŠOŠÏ -----------------------------------------------------------------
macro	bg_soushisetsu
	@bg_init
	bg	"cg\bg\@{İŠOŠÏ.png"
endm
# @{İŠOŠÏ(—[•û) -----------------------------------------------------------
macro	bg_soushisetsu_y
	@bg_init
	bg	"cg\bg\@{İŠOŠÏ_—[•û.png"
endm
# @{İŠOŠÏ(–é) -------------------------------------------------------------
macro	bg_soushisetsu_n
	@bg_init
	bg	"cg\bg\@{İŠOŠÏ_–é.png"
endm
# @{İŒÂº -----------------------------------------------------------------
macro	bg_soushisetsu_koshitsu
	@bg_init
	bg	"cg\bg\@{İŒÂº.png"
endm
# @{İŒÂº(—[•û) -----------------------------------------------------------
macro	bg_soushisetsu_koshitsu_y
	@bg_init
	bg	"cg\bg\@{İŒÂº_—[•û.png"
endm
# @{İŒÂº(–é) -------------------------------------------------------------
macro	bg_soushisetsu_koshitsu_n
	@bg_init
	bg	"cg\bg\@{İŒÂº_–é.png"
endm
# •a‰@ŠOŠÏ -----------------------------------------------------------------
macro	bg_byouin
	@bg_init
	bg	"cg\bg\•a‰@ŠOŠÏ.PNG"
endm
# •a‰@˜L‰º -----------------------------------------------------------------
macro	bg_byouin_rouka
	@bg_init
	bg	"cg\bg\•a‰@˜L‰º.PNG"
endm
# •aº -----------------------------------------------------------------
macro	bg_byoushitsu
	@bg_init
	bg	"cg\bg\•aº.PNG"
endm
# —Ñ -----------------------------------------------------------------------
macro	bg_hayashi
	@bg_init
	bg	"cg\bg\BG—Ñ“¹.png"
endm
# —Ñ(“Ü‚è) -------------------------------------------------------------------
macro	bg_hayashi_k
	@bg_init
	bg	"cg\bg\BG—Ñ“¹_“Ü.png"
endm
# —Ñ(–é) -------------------------------------------------------------------
macro	bg_hayashi_n
	@bg_init
	bg	"cg\bg\BG—Ñ“¹_–é.png"
endm
# Œö‰€ -------------------------------------------------------------------
macro	bg_kouen
	@bg_init
#	se_bg	"sound\se\BG_Œö‰€.ogg"
	bg	"cg\bg\Œö‰€.png"
endm
# Œö‰€ (“Ü‚è)----------------------------------------------------------------
macro	bg_kouen_k
	@bg_init
	bg	"cg\bg\Œö‰€_“Ü‚è.png"
endm
# Œö‰€ (‰J)----------------------------------------------------------------
macro	bg_kouen_a
	@bg_init
	screen_effect_rain	200,1
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\Œö‰€_“Ü‚è.png"
endm
# Œö‰€ (—[•û)-----------------------------------------------------------------
macro	bg_kouen_y
	@bg_init
	bg	"cg\bg\Œö‰€_—[•û.png"
endm
# Œö‰€ (–é)-----------------------------------------------------------------
macro	bg_kouen_n
	@bg_init
	bg	"cg\bg\Œö‰€_–é.png"
endm
# ‹‰Ø•”‰® -----------------------------------------------------------------
macro	bg_goukabeya
	@bg_init
	bg	"cg\bg\‹‰Ø•”‰®.png"
endm
# ƒEƒH[ƒ^[ƒp[ƒN -----------------------------------------------------------
macro	bg_waterpark
	@bg_init
	se_bg	"sound\se\BG_ƒEƒH[ƒ^[ƒp[ƒN.ogg"
layer_movie_load 	1,"system\movie\‚Ğ‚©‚è03.mpg",play_loop
layer_position_set	1,240,180
layer_scale_set		1,250,250
layer_drawmode_set	1,DRAW_ADD
	bg	"cg\bg\bg17.png"
endm
# ”ò‚Ñ‚İ‘ä ----------------------------------------------------------------
macro	bg_waterpark_tobikomi
	@bg_init
	bg	"cg\bg\bg18.png"
endm
# ”ò‚Ñ‚İ‘ä ----------------------------------------------------------------
macro	bg_waterpark_tobikomi_t
	@bg_init
	bg	"cg\bg\bg18_t.png"
endm



# ƒGƒƒLƒ…[ƒg ----------------------------------------------------------------
macro	bg_erocute
	@bg_init
	@bg_black
	@subuta_counter
	@subuta_right
	@subuta
	se		0,"sound\se\BG_ƒAƒCƒeƒ€ƒVƒ‡ƒbƒvŠK’i~‚è‚é.WAV",play_once
	layer_load	0,"cg\bg\bg_erocute1.png"
	layer_load	60,"cg\bg\bg_erocute2.png"
	screen_blackin	2000
	wait		2000
	se		0,"sound\se\ƒAƒCƒeƒ€ƒVƒ‡ƒbƒv_ƒhƒAŠJ.wav",play_once
	layer_scale	60,2000,0,0,-100,50,passtype_tcb
	layer_move	60,2000,0,0,1000,0,passtype_tcb
	wait		1000
	layer_alpha	60,1000,0,-255,passtype_tcb
	wait		1000
	layer_release	60
endm
# ƒGƒƒLƒ…[ƒg ----------------------------------------------------------------
macro	bg_erocute2
	@bg_init
	bg	"cg\bg\bg_erocute1.png"
endm
# ƒVƒ‡ƒbƒv -------------------------------------------------------------------
macro	bg_shop
	@bg_init
	bg	"cg\bg\bg_erocute1.png"
endm
# –és‚Ì•”‰® -----------------------------------------------------------------
macro	bg_yakou
	@bg_init
	bg	"cg\bg\–és‚Ì•”‰®.png"
endm
# –és‚Ìƒrƒ‹ -----------------------------------------------------------------
macro	bg_yakoubill
	@bg_init
	bg	"cg\bg\–és‚Ìƒrƒ‹.png"
endm
# –és‚Ìƒrƒ‹(—[) -------------------------------------------------------------
macro	bg_yakoubill_y
	@bg_init
	bg	"cg\bg\–és‚Ìƒrƒ‹_—[.png"
endm
# –és‚Ìƒrƒ‹(–é) -------------------------------------------------------------
macro	bg_yakoubill_n
	@bg_init
	bg	"cg\bg\–és‚Ìƒrƒ‹_–é.png"
endm
# –és‚Ìƒrƒ‹@˜L‰º ----------------------------------------------------------
macro	bg_yakoubill_rouka
	@bg_init
	bg	"cg\bg\–és_˜L‰º.png"
endm
# –és‚Ìƒrƒ‹@˜L‰º(’n‰º) -----------------------------------------------------
macro	bg_yakoubill_rouka_chika
	@bg_init
	bg	"cg\bg\–és_’n‰º˜L‰º.png"
endm

##############################################################################

# ‘Œ´ ----------------------------------------------------------------------
macro	bg_trpg_sougen
	@bg_init
	bg	"cg\bg\‘Œ´.png"
#	layer_movie_load 	1,"system\movie\‚Ğ‚©‚è02.mpg",play_loop
#	layer_position_set	1,240,180
#	layer_scale_set		1,250,250
#	layer_drawmode_set	1,DRAW_ADD
endm

# ‘Œ´ ----------------------------------------------------------------------
macro	bg_trpg_sougen_n
	@bg_init
	bg	"cg\bg\‘Œ´_n.png"
#	layer_movie_load 	1,"system\movie\‚Ğ‚©‚è02.mpg",play_loop
#	layer_position_set	1,240,180
#	layer_scale_set		1,250,250
#	layer_drawmode_set	1,DRAW_ADD
endm

# ‚Ü‚¿ ----------------------------------------------------------------------
macro	bg_trpg_machi
	@bg_init
	bg	"cg\bg\TRPGŠX.png"
endm
# ‚Ü‚¿ ----------------------------------------------------------------------
macro	bg_trpg_machi_n
	@bg_init
	bg	"cg\bg\TRPGŠX_n.png"
endm

# ğê ----------------------------------------------------------------------
macro	bg_trpg_sakaba
	@bg_init
	bg	"cg\bg\ğê.png"
endm





##############################################################################

# {İŠOŠÏ ----------------------------------------------------------------
macro	bg_kojiin_n
	@bg_init
	bg	"cg\bg\bg01ŒÇ™‰@‘O_–é.png"
endm

# ŒÇ™‰@‘O ----------------------------------------------------------------
macro	bg_gate
	@bg_init
	bg	"cg\bg\bg02_’‹.png"
endm
# ŒÇ™‰@‘O(“Ü) -----------------------------------------------------------
macro	bg_gate_k
	@bg_init
	bg	"cg\bg\bg02_‚­‚à‚è.png"
endm
# ŒÇ™‰@‘O(‰J) -----------------------------------------------------------
macro	bg_gate_a
	@bg_init
	screen_effect_rain	200,1
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\bg02_‚­‚à‚è.png"
endm
# ŒÇ™‰@‘O(á) -----------------------------------------------------------
macro	bg_gate_s
	@bg_init
	screen_effect_snow	200,1
	bg	"cg\bg\bg02_‚­‚à‚è.png"
endm
# ŒÇ™‰@‘O(–é) -----------------------------------------------------------
macro	bg_gate_n
	@bg_init
	bg	"cg\bg\bg02_–é.png"
endm
# ŒÇ™‰@‘O(—[•û) ---------------------------------------------------------
macro	bg_gate_y
	@bg_init
	bg	"cg\bg\bg02_—[.png"
endm
# ƒŠƒrƒ“ƒO -------------------------------------------------------------------
macro	bg_living
	@bg_init
	bg	"cg\bg\bg04.png"
endm
# ƒŠƒrƒ“ƒO(–é) ---------------------------------------------------------------
macro	bg_living_n
	@bg_init
	bg	"cg\bg\bg04_n.png"
endm
# ƒŠƒrƒ“ƒO(‰J) ---------------------------------------------------------------
macro	bg_living_a
	@bg_init
	se_bg	"sound\se\BG_‰J.ogg"
	bg	"cg\bg\bg04_n.png"
endm
# ŒºŠÖ ----------------------------------------------------------------------
macro	bg_genkan
	@bg_init
	bg	"cg\bg\bg11.png"
endm
# LŠÔ ----------------------------------------------------------------------
macro	bg_hiroma
	@bg_init
	bg	"cg\bg\bg09.png"
endm
# ’†’ë ---------------------------------------------------------------------
macro	bg_nakaniwa
	@bg_init
	bg	"cg\bg\bg06.png"
endm
# ’†’ë(—[•û) ----------------------------------------------------------------
macro	bg_nakaniwa_y
	@bg_init
	bg	"cg\bg\bg06y.png"
endm
# ’†’ë(–é) ----------------------------------------------------------------
macro	bg_nakaniwa_n
	@bg_init
	screen_color_set 	-32,-16,0
	bg	"cg\bg\bg06n.png"
endm
# ƒhƒA‘O --------------------------------------------------------------------
macro	bg_door
	@bg_init
	bg	"cg\bg\bg14.png"
endm
# ƒhƒA‘O(–é) ----------------------------------------------------------------
macro	bg_door_n
	@bg_init
	bg	"cg\bg\bg14n.png"
endm
# H“° -----------------------------------------------------------------------
macro	bg_dining
	@bg_init
	bg	"cg\bg\bg12.png"
endm
# H“°(–é) -------------------------------------------------------------------
macro	bg_dining_n
	@bg_init
	bg	"cg\bg\bg12n.png"
endm
# —º -----------------------------------------------------------------------
macro	bg_bathroom
	@bg_init
	bg	"cg\bg\bg05.png"
endm
# —º(–é) -------------------------------------------------------------------
macro	bg_bathroom_n
	@bg_init
	bg	"cg\bg\bg05n.png"
endm
# }‘º ---------------------------------------------------------------------
macro	bg_library
	@bg_init
	bg	"cg\bg\bg07.png"
endm
# }‘º(–é)------------------------------------------------------------------
macro	bg_library_n
	@bg_init
	bg	"cg\bg\bg07n.png"
endm
# ŒâŠyº ---------------------------------------------------------------------
macro	bg_goraku
	@bg_init
	bg	"cg\bg\bg15.png"
endm
# ŒâŠyº (–é) ----------------------------------------------------------------
macro	bg_goraku_n
	@bg_init
	bg	"cg\bg\bg15n.png"
endm
# ˜L‰º -----------------------------------------------------------------------
macro	bg_rouka
	@bg_init
	bg	"cg\bg\rouka.png"
endm
# ˜L‰º(–é) -------------------------------------------------------------------
macro	bg_rouka_n
	@bg_init
	bg	"cg\bg\rouka_n.png"
endm
# ˜L‰º(Á“”) -----------------------------------------------------------------
macro	bg_rouka_nn
	@bg_init
	screen_color_set 	-32,-16,0
	bg	"cg\bg\rouka_nn.png"
endm
# ƒLƒbƒ`ƒ“ -------------------------------------------------------------------
macro	bg_kitchen
	@bg_init
	bg	"cg\bg\bg03.png"
endm
# ƒLƒbƒ`ƒ“(–é) ---------------------------------------------------------------
macro	bg_kitchen_n
	@bg_init
	bg	"cg\bg\bg03n.png"
endm
# ’²‹³•”‰® -------------------------------------------------------------------
macro	bg_choukyou
	@bg_init
	bg	"cg\bg\bg08.png"
endm
# ’²‹³•”‰®(–é) ---------------------------------------------------------------
macro	bg_choukyou_n
	@bg_init
	bg	"cg\bg\bg08_–é.png"
endm
# ƒn[ƒh’²‹³•”‰® -------------------------------------------------------------
macro	bg_choukyou_hard
	@bg_init
	bg	"cg\bg\bg16.png"
endm
# ‰®ª -----------------------------------------------------------------------
macro	bg_yane_a
	@bg_init
	se_bg	"sound\se\BG_—‹2.ogg"
	screen_effect_rain	400,2
	screen_effect_storm	20,200
	screen_color_set 	-32,-16,0
	bg	"cg\bg\“Ü‹ó.png"
endm


##############################################################################


# ‚İ‚©‚ñ‚Ì•”‰® ---------------------------------------------------------------
macro	bg_mikan
	@bg_init
	bg	"cg\bg\‚İ‚©‚ñ•”‰®.png"
endm
# ‚İ‚©‚ñ‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_mikan_n
	@bg_init
	bg	"cg\bg\‚İ‚©‚ñ•”‰®_–é.png"
endm
# ‚¢‚¿‚²‚Ì•”‰® ---------------------------------------------------------------
macro	bg_ichigo
	@bg_init
	bg	"cg\bg\‚¢‚¿‚²•”‰®.png"
endm
# ‚¢‚¿‚²‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_ichigo_n
	@bg_init
	bg	"cg\bg\‚¢‚¿‚²•”‰®_–é.png"
endm
# ‚¢‚¿‚²‚Ì•”‰®(Á“”) --------------------------------------------------------
macro	bg_ichigo_nn
	@bg_init
	bg	"cg\bg\‚¢‚¿‚²•”‰®_Á“”.png"
endm
# ‚©‚è‚ñ‚Ì•”‰® ---------------------------------------------------------------
macro	bg_karin
	@bg_init
	bg	"cg\bg\‚©‚è‚ñ•”‰®.png"
endm
# ‚©‚è‚ñ‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_karin_n
	@bg_init
	bg	"cg\bg\‚©‚è‚ñ•”‰®_–é.png"
endm
# ‚´‚­‚ë‚Ì•”‰® ---------------------------------------------------------------
macro	bg_zakuro
	@bg_init
	bg	"cg\bg\‚´‚­‚ë•”‰®.png"
endm
# ‚´‚­‚ë‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_zakuro_n
	@bg_init
	bg	"cg\bg\‚´‚­‚ë•”‰®_–é.png"
endm
# ‚·‚¢‚©‚Ì•”‰® ---------------------------------------------------------------
macro	bg_suika
	@bg_init
	bg	"cg\bg\‚·‚¢‚©•”‰®.png"
endm
# ‚·‚¢‚©‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_suika_n
	@bg_init
	bg	"cg\bg\‚·‚¢‚©•”‰®_–é.png"
endm
# ‚Ğ‚©‚è‚Ì•”‰® ---------------------------------------------------------------
macro	bg_hikari
	@bg_init
	bg	"cg\bg\‚Ğ‚©‚è•”‰®.png"
endm
# ‚Ğ‚©‚è‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_hikari_n
	@bg_init
	bg	"cg\bg\‚Ğ‚©‚è•”‰®_–é.png"
endm
# ‚ä‚¸‚Ì•”‰® ---------------------------------------------------------------
macro	bg_yuzu
	@bg_init
	bg	"cg\bg\‚ä‚¸•”‰®.png"
endm
# ‚ä‚¸‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_yuzu_n
	@bg_init
	bg	"cg\bg\‚ä‚¸•”‰®_–é.png"
endm


##############################################################################


# ”ü‰J‚Ì•”‰® -----------------------------------------------------------------
macro	bg_miu
	@bg_init
	bg	"cg\bg\”ü‰J‚Ì•”‰®.png"
endm
# ”ü‰J‚Ì•”‰®(–é) -------------------------------------------------------------
macro	bg_miu_n
	@bg_init
	bg	"cg\bg\”ü‰J‚Ì•”‰®_–é.png"
endm
# ”ü‰J‚Ì•”‰®(Á“”) -----------------------------------------------------------
macro	bg_miu_nn
	@bg_init
	bg	"cg\bg\”ü‰J‚Ì•”‰®_Á“”.png"
endm
# ´‚Ì•”‰® ---------------------------------------------------------------
macro	bg_shizuku
	@bg_init
	bg	"cg\bg\´‚Ì•”‰®.png"
endm
# ´‚Ì•”‰®(–é) -----------------------------------------------------------
macro	bg_shizuku_n
	@bg_init
	bg	"cg\bg\´‚Ì•”‰®_–é.png"
endm
# ©º -----------------------------------------------------------------------
macro	bg_itsuki
	@bg_init
	bg	"cg\bg\÷‚Ì•”‰®.png"
endm
# ©º(–é) -------------------------------------------------------------------
macro	bg_itsuki_n
	@bg_init
	bg	"cg\bg\÷‚Ì•”‰®_–é.png"
endm
# ©º(Á“”) -----------------------------------------------------------------
macro	bg_itsuki_nn
	@bg_init
	bg	"cg\bg\÷‚Ì•”‰®_Á“”.png"
endm


# ‹ó‚«•”‰® -------------------------------------------------------------------
macro	bg_akibeya
	@bg_init
	bg	"cg\bg\‹ó‚«•”‰®.png"
endm
# ‹ó‚«•”‰®(–é) ---------------------------------------------------------------
macro	bg_akibeya_n
	@bg_init
	bg	"cg\bg\‹ó‚«•”‰®_–é.png"
endm
