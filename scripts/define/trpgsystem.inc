
#モンスター上下
macro	monster_effect_1
layer_movepass_init	l_trpg_monster,0
layer_movepass_add	l_trpg_monster,0,	0,	0,0
layer_movepass_add	l_trpg_monster,0,	100,	0,8
layer_movepass_add	l_trpg_monster,0,	100,	0,0
layer_movepass_add	l_trpg_monster,0,	100,	0,-8
layer_movepass_add	l_trpg_monster,0,	100,	0,0
layer_movepass_add	l_trpg_monster,0,	100,	0,8
layer_movepass_add	l_trpg_monster,0,	100,	0,0
layer_movepass_add	l_trpg_monster,0,	100,	0,-8
layer_movepass_type	l_trpg_monster,0,	PASSTYPE_TCB
layer_movepass_play	l_trpg_monster,0,	play_once
endm

#モンスター去る
macro	monster_
layer_move	l_trpg_monster,1000,0,0,-320,0,PASSTYPE_BEZIER_B
endm

#モンスター倒れる
macro	monster_dead
layer_move	l_trpg_monster,2000,0,0,0,700,PASSTYPE_BEZIER_B
endm

#回復
macro	trpg_heal
	window_close
	@se126
	layer_movie_load 62,"system\movie\回復2.mpg",play_once
	layer_position_set	62,250,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	wait		2000
	layer_alpha		62,1000,0,-255,passtype_linear
#	layer_scale		62,500,0,0,400,400,PASSTYPE_BEZIER_A
	wait		1000
	layer_release	62
endm


#バトルスタート ##############################################################
macro	trpg_battle_start
	window_close
	se	0,"sound\se\SE221_TRPG戦闘開始.wav",play_once

	layer_load	61,"system\trpg\battlestart.png"
	layer_position	61,120,200
	layer_scale	61,500,200,200,0,0,PASSTYPE_BEZIER_B
	wait	500
#	se	0,"sound\se\アイテム使用2.wav",play_once
	layer_movie_load 62,"system\movie\効果A.mpg",play_once
	layer_position_set	62,250,280-128
	layer_scale_set		62,400,400
	layer_drawmode_set	62,DRAW_ADD
	@bgm07
	wait		2000
	layer_alpha		61,500,0,-255,passtype_linear
#	layer_scale		61,500,0,0,400,400,PASSTYPE_BEZIER_A
	wait		500
	layer_release	61
	layer_release	62
endm

#ゲームオーバー ##############################################################
macro	trpg_gameover
	window_close
	@se118

	layer_load	61,"system\trpg\gameover.png"
	layer_position	61,120,200
	layer_scale	61,500,400,400,0,0,PASSTYPE_BEZIER_A
	wait	500
#	se	0,"sound\se\アイテム使用2.wav",play_once
	layer_movie_load 62,"system\movie\効果3.mpg",play_once
	layer_position_set	62,250,280-128
	layer_scale_set		62,500,500
	layer_drawmode_set	62,DRAW_ADD
	@bgm07
	wait		2000
	layer_alpha		61,500,0,-255,passtype_linear
#	layer_scale		61,500,0,0,400,400,PASSTYPE_BEZIER_A
	wait		500
	layer_release	61
	layer_release	62
endm


#勝利 ########################################################################
macro	trpg_youwin
	layer_load	61,"system\trpg\youwin.png"
	layer_position	61,120,200
	layer_scale	61,500,400,400,0,0,PASSTYPE_BEZIER_B
	bgm_stop
	@se117
	wait	500
	layer_movie_load 62,"system\movie\せまる1.mpg",play_once
	layer_position_set	62,250,280-128
	layer_scale_set		62,500,500
	layer_drawmode_set	62,DRAW_ADD
	wait		2000
	layer_alpha		61,500,0,-255,passtype_linear
#	layer_scale		61,500,0,0,400,400,PASSTYPE_BEZIER_A
	wait		500
	layer_release	61
	layer_release	62
endm

#敵ダメージ ##################################################################
macro	trpg_enemydamage
layer_movepass_init	l_trpg_monster,0
layer_movepass_add	l_trpg_monster,0,	0,	0,0
layer_movepass_add	l_trpg_monster,0,	50,	0,16
layer_movepass_add	l_trpg_monster,0,	50,	16,0
layer_movepass_add	l_trpg_monster,0,	50,	0,-16
layer_movepass_add	l_trpg_monster,0,	50,	16,0
layer_movepass_add	l_trpg_monster,0,	50,	8,8
layer_movepass_add	l_trpg_monster,0,	50,	8,-8
layer_movepass_add	l_trpg_monster,0,	50,	0,8
layer_movepass_type	l_trpg_monster,0,	PASSTYPE_TCB
layer_movepass_play	l_trpg_monster,0,	play_once
endm

#スタート ####################################################################
macro	trpg_start
	twx=300
	twy=400
	twl=63
	window_close
	layer_load	twl,"system\trpg\command_window.png"
	layer_position	twl,twx,twy

	lifebar_load		life_trpg_itsuki,"system\trpg\bar_itsuki.png"
	lifebar_position	life_trpg_itsuki,500,400
	lifebar_levelmode	life_trpg_itsuki,false
	lifebar_open		life_trpg_itsuki

	lifebar_load		life_trpg_mikan,"system\trpg\bar_mikan.png"
	lifebar_position	life_trpg_mikan,500,400+46*1
	lifebar_levelmode	life_trpg_mikan,false

	lifebar_load		life_trpg_karin,"system\trpg\bar_karin.png"
	lifebar_position	life_trpg_karin,500,400+46*2
	lifebar_levelmode	life_trpg_karin,false
	lifebar_open		life_trpg_karin

	lifebar_load		life_trpg_ichigo,"system\trpg\bar_ichigo.png"
	lifebar_position	life_trpg_ichigo,500,400+46*3
	lifebar_levelmode	life_trpg_ichigo,false
	lifebar_open		life_trpg_ichigo

	trpg_life_itsuki=	mikan_kenkou_max+karin_kenkou_max+ichigo_kenkou_max
	trpg_life_itsuki=	trpg_life_itsuki/3
	trpg_life_mikan	=	mikan_kenkou_max
	trpg_life_karin	=	karin_kenkou_max
	trpg_life_ichigo=	ichigo_kenkou_max

	lifebar_open		life_trpg_itsuki
	lifebar_setmax		life_trpg_itsuki,trpg_life_itsuki
	lifebar_setauto		life_trpg_itsuki,trpg_life_itsuki

	lifebar_open		life_trpg_mikan
	lifebar_setmax		life_trpg_mikan,trpg_life_mikan
	lifebar_setauto		life_trpg_mikan,trpg_life_mikan

	lifebar_open		life_trpg_karin
	lifebar_setmax		life_trpg_karin,trpg_life_karin
	lifebar_setauto		life_trpg_karin,trpg_life_karin

	lifebar_open		life_trpg_ichigo
	lifebar_setmax		life_trpg_ichigo,trpg_life_ichigo
	lifebar_setauto		life_trpg_ichigo,trpg_life_ichigo

endm

#いつきアタック
macro	trpg_itsuki_attack
	layer_load	62,"system\trpg\message_itsuki_special.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	@trpg_itsuki_special
	wait	1000
	layer_move	l_trpg_itsuki,500,-600,0,0,0,PASSTYPE_BEZIER_A
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	monster_life=monster_life-trpg_itsuki_attack*3
	@trpg_itsuki_ikari
	layer_move	l_trpg_itsuki,500,600,0,0,0,PASSTYPE_BEZIER_A
endm

#みかんアタック
macro	trpg_mikan_attack
	voice "A02640"
	@trpg_mikan_special
	se	0,"sound\se\trpg_魔法前.wav",play_once
	wait	1000
	layer_movie_load 62,"system\movie\稲妻02.mpg",play_once
	layer_position_set	62,-50,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	se	1,"sound\se\trpg_雷魔法.wav",play_once
	wait	2000
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	400
	@trpg_damage
	layer_release		62
	wait	200
	monster_life=monster_life-trpg_mikan_attack*3
	@trpg_mikan_ikari
#	layer_move	l_trpg_mikan,500,600,0,0,0,PASSTYPE_BEZIER_A
endm

#かりんアタック
macro	trpg_karin_attack
	@trpg_karin_special
	screen_whiteout	1000
	se	0,"sound\se\trpg_魔法前.wav",play_once
	wait	1000
	screen_whitein	1
	layer_movie_load 62,"system\movie\炎1.mpg",play_once
	layer_position_set	62,-50,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	se	1,"sound\se\trpg_雷魔法.wav",play_once
	wait	2000
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	400
	@trpg_damage
	layer_release		62
	wait	200
endm

#いつきコマンド ###############################################################
macro	trpg_itsuki_command
	@trpg_itsuki_ikari
	layer_move	l_trpg_itsuki,500,0,0,-100,0,PASSTYPE_BEZIER_A
	clearbutton
#	# setbutton ボタン番号,X,Y,エフェクト
	setbutton 1,twx+16,twy+8,0,"system\trpg\command_itsuki_attack_over.png","system\trpg\command_itsuki_attack.png"
	setbutton 2,twx+16,twy+8+32*1,0,"system\trpg\command_itsuki_protect_over.png","system\trpg\command_itsuki_protect.png"
#	setbutton 3,twx+16,twy+8+32*2,0,"system\trpg\command_itsuki_defense_over.png","system\trpg\command_itsuki_defense.png"
	if trpg_itsuki_sp=0 then setbutton 4,twx+16,twy+8+32*3,0,"system\trpg\command_itsuki_special_over.png","system\trpg\command_itsuki_special.png"

	layer_load	62,"system\trpg\message_itsuki_start.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400

	getbutton sel
	if sel=1 then goto trpg_itsuki_command_attack	#攻撃
	if sel=2 then goto trpg_itsuki_command_defence	#防御
	if sel=4 then goto trpg_itsuki_command_special	#特別

	#攻撃
label	trpg_itsuki_command_attack
	layer_load	62,"system\trpg\message_itsuki_attack.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	l_layer=l_trpg_monster
	@trpg_damage
	wait	1000
	layer_move	l_trpg_itsuki,500,-100,0,0,0,PASSTYPE_BEZIER_A
	monster_life=monster_life-trpg_itsuki_attack

	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait		400
	goto	trpg_itsuki_command_skip

	#防御
label	trpg_itsuki_command_defence
	layer_load	62,"system\trpg\message_itsuki_defense.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	trpg_itsuki_defence_flag=1
	layer_move	l_trpg_itsuki,500,0,0,100,0,PASSTYPE_BEZIER_A
	goto	trpg_itsuki_command_skip

	#特別
label	trpg_itsuki_command_special
	trpg_itsuki_sp=1
	layer_move	l_trpg_mikan,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_karin,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,0,0,500,0,PASSTYPE_BEZIER_A

	layer_load	62,"system\trpg\message_itsuki_special.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	@trpg_itsuki_special
	wait	1000
	layer_move	l_trpg_itsuki,500,-600,0,0,0,PASSTYPE_BEZIER_A
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	@trpg_damage
	layer_move	l_trpg_itsuki,200,-600,0,0,0,PASSTYPE_BEZIER_A
	wait	200
	monster_life=monster_life-trpg_itsuki_attack*3
	@trpg_itsuki_ikari
	layer_move	l_trpg_itsuki,500,600,0,0,0,PASSTYPE_BEZIER_A

	layer_move	l_trpg_mikan,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_karin,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,500,0,0,0,PASSTYPE_BEZIER_A

	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait		400
	goto	trpg_itsuki_command_skip

label	trpg_itsuki_command_skip
	lifebar_setauto	life_trpg_itsuki,trpg_life_itsuki


endm
#みかんコマンド ###############################################################
macro	trpg_mikan_command
	@trpg_mikan_ikari
	layer_move	l_trpg_mikan,500,0,0,-100,0,PASSTYPE_BEZIER_A
	clearbutton
#	# setbutton ボタン番号,X,Y,エフェクト
	setbutton 1,twx+16,twy+8,0,"system\trpg\command_mikan_attack_over.png","system\trpg\command_mikan_attack.png"
	setbutton 2,twx+16,twy+8+32*1,0,"system\trpg\command_mikan_protect_over.png","system\trpg\command_mikan_protect.png"
#	setbutton 3,twx+16,twy+8+32*2,0,"system\trpg\command_mikan_defense_over.png","system\trpg\command_mikan_defense.png"
	if trpg_mikan_sp=0 then setbutton 4,twx+16,twy+8+32*3,0,"system\trpg\command_mikan_special_over.png","system\trpg\command_mikan_special.png"
	getbutton sel
	if sel=1 then goto trpg_mikan_command_attack	#攻撃
	if sel=2 then goto trpg_mikan_command_defence	#防御
	if sel=4 then goto trpg_mikan_command_special	#特別

	#攻撃
label	trpg_mikan_command_attack
	voice "A02639"
	l_layer=l_trpg_monster
	@trpg_damage
	wait	1000
	layer_move	l_trpg_mikan,500,-100,0,0,0,PASSTYPE_BEZIER_A
	monster_life=monster_life-trpg_mikan_attack

	goto	trpg_mikan_command_skip

	#防御
label	trpg_mikan_command_defence
	voice "A02641"
	trpg_mikan_defence_flag=1
	layer_move	l_trpg_mikan,500,0,0,100,0,PASSTYPE_BEZIER_A
	goto	trpg_mikan_command_skip

	#特別
label	trpg_mikan_command_special
	trpg_mikan_sp=1
	layer_move	l_trpg_itsuki,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_karin,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,0,0,500,0,PASSTYPE_BEZIER_A
	voice "A02640"
	@trpg_mikan_special
	se	0,"sound\se\trpg_魔法前.wav",play_once
	wait	1000
	layer_movie_load 62,"system\movie\稲妻02.mpg",play_once
	layer_position_set	62,-50,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	se	1,"sound\se\trpg_雷魔法.wav",play_once
	wait	2000
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	400
	@trpg_damage
	layer_release		62
	wait	200
	monster_life=monster_life-trpg_mikan_attack*3
	@trpg_mikan_ikari
#	layer_move	l_trpg_mikan,500,600,0,0,0,PASSTYPE_BEZIER_A

	layer_move	l_trpg_itsuki,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_karin,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,500,0,0,0,PASSTYPE_BEZIER_A

	goto	trpg_mikan_command_skip

label	trpg_mikan_command_skip
	lifebar_setauto	life_trpg_mikan,trpg_life_mikan

endm

#かりんコマンド ###############################################################
macro	trpg_karin_command
	@trpg_karin_ikari
	layer_move	l_trpg_karin,500,0,0,-100,0,PASSTYPE_BEZIER_A
	clearbutton
#	# setbutton ボタン番号,X,Y,エフェクト
	setbutton 1,twx+16,twy+8,0,"system\trpg\command_karin_attack_over.png","system\trpg\command_karin_attack.png"
	setbutton 2,twx+16,twy+8+32*1,0,"system\trpg\command_karin_protect_over.png","system\trpg\command_karin_protect.png"
#	setbutton 3,twx+16,twy+8+32*2,0,"system\trpg\command_karin_defense_over.png","system\trpg\command_karin_defense.png"
	if trpg_karin_sp=0 then setbutton 4,twx+16,twy+8+32*3,0,"system\trpg\command_karin_special_over.png","system\trpg\command_karin_special.png"
	getbutton sel
	if sel=1 then goto trpg_karin_command_attack	#攻撃
	if sel=2 then goto trpg_karin_command_defence	#防御
	if sel=4 then goto trpg_karin_command_special	#特別

	#攻撃
label	trpg_karin_command_attack
	voice "P02727"
	l_layer=l_trpg_monster
	@trpg_damage
	wait	1000
	layer_move	l_trpg_karin,500,-100,0,0,0,PASSTYPE_BEZIER_A
	monster_life=monster_life-trpg_karin_attack

	goto	trpg_karin_command_skip

	#防御
label	trpg_karin_command_defence
	voice "P02729"
	trpg_karin_defence_flag=1
	layer_move	l_trpg_karin,500,0,0,100,0,PASSTYPE_BEZIER_A
	goto	trpg_karin_command_skip

	#特別
label	trpg_karin_command_special
	trpg_karin_sp=1
	layer_move	l_trpg_itsuki,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_mikan,500,0,0,500,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,0,0,500,0,PASSTYPE_BEZIER_A
	voice "P02728"
	@trpg_karin_special
	screen_whiteout	1000
	se	0,"sound\se\trpg_魔法前.wav",play_once
	wait	1000
	screen_whitein	1
	layer_movie_load 62,"system\movie\炎1.mpg",play_once
	layer_position_set	62,-50,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	se	1,"sound\se\trpg_雷魔法.wav",play_once
	wait	2000
	l_layer=l_trpg_monster
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	200
	@trpg_damage
	wait	400
	@trpg_damage
	layer_release		62
	wait	200
	monster_life=monster_life-trpg_karin_attack*3
	@trpg_karin_ikari
#	layer_move	l_trpg_karin,500,600,0,0,0,PASSTYPE_BEZIER_A

	layer_move	l_trpg_itsuki,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_mikan,500,500,0,0,0,PASSTYPE_BEZIER_A
	layer_move	l_trpg_ichigo,500,500,0,0,0,PASSTYPE_BEZIER_A

	goto	trpg_karin_command_skip

label	trpg_karin_command_skip
	lifebar_setauto	life_trpg_karin,trpg_life_karin

endm

#いちごコマンド ###############################################################
macro	trpg_ichigo_command
	@trpg_ichigo_ikari
	layer_move	l_trpg_ichigo,500,0,0,-100,0,PASSTYPE_BEZIER_A
	clearbutton
#	# setbutton ボタン番号,X,Y,エフェクト
	setbutton 1,twx+16,twy+8,0,"system\trpg\command_ichigo_attack_over.png","system\trpg\command_ichigo_attack.png"
	setbutton 2,twx+16,twy+8+32*1,0,"system\trpg\command_ichigo_protect_over.png","system\trpg\command_ichigo_protect.png"
#	setbutton 3,twx+16,twy+8+32*2,0,"system\trpg\command_ichigo_defense_over.png","system\trpg\command_ichigo_defense.png"
	if trpg_ichigo_sp=0 then setbutton 4,twx+16,twy+8+32*3,0,"system\trpg\command_ichigo_special_over.png","system\trpg\command_ichigo_special.png"
	getbutton sel
	if sel=1 then goto trpg_ichigo_command_attack	#攻撃
	if sel=2 then goto trpg_ichigo_command_defence	#防御
	if sel=4 then goto trpg_ichigo_command_special	#特別

	#攻撃
label	trpg_ichigo_command_attack
	voice "O02760"
	l_layer=l_trpg_monster
	@trpg_damage
	wait	1000
	layer_move	l_trpg_ichigo,500,-100,0,0,0,PASSTYPE_BEZIER_A
	monster_life=monster_life-trpg_ichigo_attack

	goto	trpg_ichigo_command_skip

	#防御
label	trpg_ichigo_command_defence
#	voice "P02729"
	trpg_ichigo_defence_flag=1
	layer_move	l_trpg_ichigo,500,0,0,100,0,PASSTYPE_BEZIER_A
	goto	trpg_ichigo_command_skip

	#特別
label	trpg_ichigo_command_special
	trpg_ichigo_sp=1
	voice "P02761"
	@trpg_ichigo_special
	screen_whiteout	1000
	se	0,"sound\se\trpg_魔法前.wav",play_once
	wait	1000
	screen_whitein	1
	layer_movie_load 62,"system\movie\回復2.mpg",play_once
	layer_position_set	62,-50,200
	layer_scale_set		62,300,300
	layer_drawmode_set	62,DRAW_ADD
	se	1,"sound\se\trpg_雷魔法.wav",play_once
	wait	2000
#	l_layer=l_trpg_monster
#	@trpg_damage
#	wait	200
#	@trpg_damage
#	wait	200
#	@trpg_damage
#	wait	200
#	@trpg_damage
#	wait	400
#	@trpg_damage
#	layer_release		62
#	wait	200
#	monster_life=monster_life-trpg_ichigo_attack*3

	if trpg_life_itsuki>0 then trpg_life_itsuki=trpg_life_itsuki+100
	if trpg_life_mikan>0 then trpg_life_mikan=trpg_life_mikan+100
	if trpg_life_karin>0 then trpg_life_karin=trpg_life_karin+100

	lifebar_setauto	life_trpg_itsuki,trpg_life_itsuki
	lifebar_setauto	life_trpg_mikan,trpg_life_mikan
	lifebar_setauto	life_trpg_karin,trpg_life_karin
	lifebar_setauto	life_trpg_ichigo,trpg_life_ichigo

	@trpg_ichigo_ikari

	goto	trpg_ichigo_command_skip

label	trpg_ichigo_command_skip
	lifebar_setauto	life_trpg_ichigo,trpg_life_ichigo

endm




#ダメージ演出 ################################################################
macro	trpg_damage
layer_movepass_init	l_layer,0

@se60

for t=0 to 12
	rand x,0,32
	x=x-16
	rand y,0,32
	y=y-16
	layer_movepass_add	l_layer,0,	30,	x,y
next

layer_movepass_type	l_layer,0,	PASSTYPE_LINEAR
layer_movepass_play	l_layer,0,	play_once

layer_load		60,"system\trpg\effect_attack01.png"
layer_drawmode_set	60,DRAW_ADD
layer_position		60,0,200
#layer_move		60,1000,-400,-400,400,400,passtype_tcb
layer_scale		60,500,400,400,-100,-100,passtype_tcb
layer_reference_set	60,l_layer
endm

#モンスター攻撃 ##############################################################
macro	trpg_monster_attack


layer_movepass_init	l_trpg_monster,0
layer_movepass_add	l_trpg_monster,0,	100,	16,0
layer_movepass_add	l_trpg_monster,0,	100,	-16,0
layer_movepass_add	l_trpg_monster,0,	100,	16,0
layer_movepass_add	l_trpg_monster,0,	100,	-16,0
layer_movepass_add	l_trpg_monster,0,	100,	16,0
layer_movepass_add	l_trpg_monster,0,	100,	-16,0
layer_movepass_add	l_trpg_monster,0,	100,	16,0
layer_movepass_add	l_trpg_monster,0,	100,	-16,0
layer_movepass_type	l_trpg_monster,0,	PASSTYPE_TCB
layer_movepass_play	l_trpg_monster,0,	play_once
@se59
wait	100
@se59
wait	100
@se59
wait	100
@se59
wait	100
wait	400

	rand	damage,10,monster_damage
label	trpg_monster_attack_loop
	rand	chara_sel,1,4


	if chara_sel=1 and trpg_life_itsuki<1 then goto trpg_monster_attack_loop
	if chara_sel=2 and trpg_life_mikan<1 then goto trpg_monster_attack_loop
	if chara_sel=3 and trpg_life_karin<1 then goto trpg_monster_attack_loop
	if chara_sel=4 and trpg_life_ichigo<1 then goto trpg_monster_attack_loop

	if chara_sel=1 then goto trpg_monster_attack_itsuki
	if chara_sel=2 then goto trpg_monster_attack_mikan
	if chara_sel=3 then goto trpg_monster_attack_karin
	if chara_sel=4 then goto trpg_monster_attack_ichigo

label	trpg_monster_attack_itsuki
	rand	rnd,0,9
	if rnd<1 then goto trpg_monster_attack_itsuki_sake
	#いつきダメージ
	layer_load	62,"system\trpg\message_itsuki_damage.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	if trpg_itsuki_defence_flag=1 then damage=damage/3
	trpg_life_itsuki=trpg_life_itsuki-damage
	l_layer=l_trpg_itsuki
	@trpg_damage
	@trpg_itsuki_damage
	if trpg_life_itsuki<1 then goto trpg_monster_attack_itsuki_dead
	goto	trpg_monster_attack_skip

label	trpg_monster_attack_itsuki_dead
	#いつき死亡
	if trpg_itsuki_flag=1 then layer_move	l_trpg_itsuki,2000,0,0,0,600,PASSTYPE_BEZIER_B
	trpg_itsuki_flag=0
	layer_load	62,"system\trpg\message_itsuki_dead.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400
	goto	trpg_monster_attack_skip

label	trpg_monster_attack_itsuki_sake
	#いつき攻撃避け
	@se50
	layer_move	l_trpg_itsuki,500,0,0,100,0,PASSTYPE_BEZIER_A
	layer_load	62,"system\trpg\message_itsuki_avoid.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	layer_move	l_trpg_itsuki,500,100,0,0,0,PASSTYPE_BEZIER_A
	goto	trpg_monster_attack_skip
	
label	trpg_monster_attack_mikan
	#みかん回避判定
	#みかんダメージ
	if trpg_mikan_defence_flag=1 then damage=damage/3
	trpg_life_mikan=trpg_life_mikan-damage
	l_layer=l_trpg_mikan
	@trpg_damage
	@trpg_mikan_damage
	voice	"A02642"
	if trpg_life_mikan<1 then goto trpg_monster_attack_mikan_dead
	goto	trpg_monster_attack_skip
label	trpg_monster_attack_mikan_dead
	#みかん死亡
	wait	1000
	voice	"A02644"
	if trpg_mikan_flag=1 then layer_move	l_trpg_mikan,2000,0,0,0,600,PASSTYPE_BEZIER_B
	trpg_mikan_flag=0
	layer_load	62,"system\trpg\message_mikan_dead.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400
	goto	trpg_monster_attack_skip

label	trpg_monster_attack_karin
	#かりんダメージ
	if trpg_karin_defence_flag=1 then damage=damage/3
	trpg_life_karin=trpg_life_karin-damage
	l_layer=l_trpg_karin
	@trpg_damage
	@trpg_karin_damage
	voice	"P02730"
	if trpg_life_karin<1 then goto trpg_monster_attack_karin_dead
	goto	trpg_monster_attack_skip
label	trpg_monster_attack_karin_dead
	#かりん死亡
	wait	1000
	voice	"P02732"
	if trpg_karin_flag=1 then layer_move	l_trpg_karin,2000,0,0,0,600,PASSTYPE_BEZIER_B
	trpg_karin_flag=0
	layer_load	62,"system\trpg\message_karin_dead.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400
	goto	trpg_monster_attack_skip

label	trpg_monster_attack_ichigo
	#いちごダメージ
	if trpg_ichigo_defence_flag=1 then damage=damage/3
	trpg_life_ichigo=trpg_life_ichigo-damage
	l_layer=l_trpg_ichigo
	@trpg_damage
	@trpg_ichigo_damage
	voice	"O02763"
	if trpg_life_ichigo<1 then goto trpg_monster_attack_ichigo_dead
	goto	trpg_monster_attack_skip
label	trpg_monster_attack_ichigo_dead
	#いちご死亡
	wait	1000
	voice	"O02765"
	if trpg_ichigo_flag=1 then layer_move	l_trpg_ichigo,2000,0,0,0,600,PASSTYPE_BEZIER_B
	trpg_ichigo_flag=0
	layer_load	62,"system\trpg\message_ichigo_dead.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400
	goto	trpg_monster_attack_skip

label	trpg_monster_attack_skip

	lifebar_setauto	life_trpg_itsuki,trpg_life_itsuki
	lifebar_setauto	life_trpg_mikan,trpg_life_mikan
	lifebar_setauto	life_trpg_karin,trpg_life_karin
	lifebar_setauto	life_trpg_ichigo,trpg_life_ichigo


endm



macro	trpg_battle
	trpg_gameover_flag=0
	trpg_itsuki_sp=0
	trpg_mikan_sp=0
	trpg_karin_sp=0
	trpg_ichigo_sp=0
	trpg_itsuki_defence_flag=	0
	trpg_mikan_defence_flag	=	0
	trpg_karin_defence_flag	=	0
	trpg_ichigo_defence_flag=	0
	#攻撃力
	trpg_mikan_attack	=	mikan_karada+mikan_karada_max
	trpg_karin_attack	=	karin_karada+karin_karada_max
	trpg_ichigo_attack	=	ichigo_karada+ichigo_karada_max
	trpg_itsuki_attack	=	trpg_mikan_attack+trpg_karin_attack+trpg_ichigo_attack
	trpg_itsuki_attack	=	trpg_itsuki_attack/3
	#防御力


	trpg_suika_voice_count	=	0

label	trpg_battle_loop

	if trpg_life_itsuki<1 then goto trpg_battle_skip1
	#いつき達のターン
	layer_load	62,"system\trpg\message_itsukiturn.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B

	@trpg_itsuki_command
	if monster_life<1 then goto trpg_battle_clear

label	trpg_battle_skip1
	if trpg_life_mikan<1 then goto trpg_battle_skip2
	#みかんのターン
	layer_load	62,"system\trpg\message_turn_mikan.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	
	@trpg_mikan_command
	if monster_life<1 then voice "A02697"	#「あははッ♪　みかん達の勝ちだよー！」
	if monster_life<1 then goto trpg_battle_clear

label	trpg_battle_skip2
	if trpg_life_karin<1 then goto trpg_battle_skip3
	#かりんのターン
	layer_load	62,"system\trpg\message_turn_karin.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	
	@trpg_karin_command
	if monster_life<1 then voice "P02807"	#「まだまだ、私たちの敵じゃなかったわね」
	if monster_life<1 then goto trpg_battle_clear

label	trpg_battle_skip3
	if trpg_life_ichigo<1 then goto trpg_battle_skip4
	#いちごのターン
	layer_load	62,"system\trpg\message_turn_ichigo.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	
	@trpg_ichigo_command
	if monster_life<1 then voice "O02814"	#「まだまだ、私たちの敵じゃなかったわね」
	if monster_life<1 then goto trpg_battle_clear
label	trpg_battle_skip4



	#敵のターン
	layer_load	62,"system\trpg\message_enemyturn.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400

	rand	rnd,0,9
	if rnd<1 then goto trpg_battle_loop_2

label	trpg_battle_loop_1

	layer_load	62,"system\trpg\message_enemy_attack.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B

	@trpg_monster_attack
	if trpg_life_itsuki<1 and trpg_life_mikan<1 and trpg_life_karin<1 and trpg_life_ichigo<1 then goto trpg_battle_gameover	#ゲームオーバー
	goto	trpg_battle_loop_3

label	trpg_battle_loop_2
	layer_load	62,"system\trpg\message_enemy_look.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	wait	400
	goto	trpg_battle_loop_3

label	trpg_battle_loop_3

#	if trpg_suika_voice_count=1 then	voice	"R00974"	#「敵は手負いです。一気に攻めちゃいましょう」
	if trpg_suika_voice_count=3 then	voice	"R00975"	#「大丈夫ですか？　油断はしないでくださいね」
#	if trpg_suika_voice_count=5 then	voice	"R00976"	#「良い調子です。頑張ってください」
	if trpg_suika_voice_count=7 then	voice	"R00977"	#「慎重かつ大胆に。よく聞く言葉ですけど、どんな行動なんでしょう？」
	

	trpg_suika_voice_count=trpg_suika_voice_count+1


	goto	trpg_battle_loop

label	trpg_battle_gameover
	layer_load	62,"system\trpg\message_lose.png"
	layer_move	62,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	@trpg_gameover
	layer_move	62,400,0,0,800,0,PASSTYPE_BEZIER_B
	trpg_gameover_flag=1
	goto	trpg_battle_skip

label	trpg_battle_clear
	clearbutton
	layer_load	63,"system\trpg\message_win.png"
	layer_move	63,400,-800,0,0,0,PASSTYPE_BEZIER_A
	wait	800
	@monster_dead
	@trpg_youwin
	wait	800
	layer_move	63,400,0,0,800,0,PASSTYPE_BEZIER_B
	@trpg_mikan_warai
	@trpg_itsuki_warai
	@trpg_karin_warai
	@trpg_ichigo_warai

	goto	trpg_battle_skip

label	trpg_battle_skip
	wait	2000
	lifebar_close		life_trpg_itsuki

	lifebar_close		life_trpg_mikan

	lifebar_close		life_trpg_karin

	lifebar_close		life_trpg_ichigo
	layer_release		62
	bgm_stop
endm

macro	trpg_evup
	trpg_event=trpg_event+1
endm



