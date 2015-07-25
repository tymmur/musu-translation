#調教システムのサブルーチン

#-- スパンキングエフェクト(小)------------------------------------------------
macro	spanking_effect_small
	rand	rnd,0,2
	if	rnd=0 then @seh02
	if	rnd=1 then @seh03
n_x = _x-75+64
n_y = _y-75+48
	if rnd=0 then layer_load_paste_mul _LAYER,"system\TrainingSystem\spanking_ato01s.png",n_x,n_y
	if rnd=1 then layer_load_paste_mul _LAYER,"system\TrainingSystem\spanking_ato02s.png",n_x,n_y
endm

#-- スパンキングエフェクト(大)------------------------------------------------
macro	spanking_effect_big
	@seh02
	rand	rnd,0,2
n_x = _x-175+64
n_y = _y-175+48
	if rnd=0 then layer_load_paste_mul _LAYER,"system\TrainingSystem\spanking_ato01l.png",n_x,n_y
	if rnd=1 then layer_load_paste_mul _LAYER,"system\TrainingSystem\spanking_ato02l.png",n_x,n_y
endm


#-- 鞭エフェクト--------------------------------------------------------------
macro	muchi_effect
#	layer_load		l_effect,"system\TrainingSystem\muchi_kiseki01.png"
#	layer_drawmode_set	l_effect,DRAW_ADD
#	layer_scale		l_effect,200,200,200,-100,-100,passtype_tcb
#	layer_position_set	l_effect,	_X-400,_Y-150
	if _TRANSLATOR_OPTION_DISABLE_FLASHES=0 then screen_flash		500
endm

#-- 鞭痕エフェクト(小)--------------------------------------------------------
macro	muchiato_effect_small
	se	0,"sound\se\muchi.wav",play_once
	rand	rnd,0,8
muchi_x = _x-72+64
muchi_y = _y-72+48
	if rnd=0 then goto muchiato_effect_s_01
	if rnd=1 then goto muchiato_effect_s_02
	if rnd=2 then goto muchiato_effect_s_03
	if rnd=3 then goto muchiato_effect_s_04
	if rnd=4 then goto muchiato_effect_s_05
	if rnd=5 then goto muchiato_effect_s_06
	if rnd=6 then goto muchiato_effect_s_07
	if rnd=7 then goto muchiato_effect_s_08

	label muchiato_effect_s_01
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato01s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_02
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato02s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_03
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato03s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_04
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato04s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_05
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato05s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_06
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato06s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_07
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato07s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label muchiato_effect_s_08
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato08s.png",muchi_x,muchi_y
		goto muchiato_effect_s_skip
	label	muchiato_effect_s_skip

endm

#-- 鞭痕エフェクト(大)--------------------------------------------------------
macro	muchiato_effect_big
	se	0,"sound\se\muchi.wav",play_once
	rand	rnd,0,8
muchi_x = _x-142+64
muchi_y = _y-142+48
	if rnd=0 then goto muchiato_effect_b_01
	if rnd=1 then goto muchiato_effect_b_02
	if rnd=2 then goto muchiato_effect_b_03
	if rnd=3 then goto muchiato_effect_b_04
	if rnd=4 then goto muchiato_effect_b_05
	if rnd=5 then goto muchiato_effect_b_06
	if rnd=6 then goto muchiato_effect_b_07
	if rnd=7 then goto muchiato_effect_b_08

	label muchiato_effect_b_01
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato01l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_02
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato02l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_03
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato03l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_04
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato04l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_05
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato05l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_06
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato06l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_07
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato07l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label muchiato_effect_b_08
		layer_load_paste_mul	_LAYER,"system\TrainingSystem\muchi_ato08l.png",muchi_x,muchi_y
		goto muchiato_effect_b_skip
	label	muchiato_effect_b_skip
endm


#-- 蝋燭エフェクト------------------------------------------------------------
macro	rousoku_effect
#	layer_load		l_effect,"system\TrainingSystem\muchi_kiseki01.png"
#	layer_drawmode_set	l_effect,DRAW_ADD
#	layer_scale		l_effect,200,200,200,-100,-100,passtype_tcb
#	layer_position_set	l_effect,	_X-400,_Y-150
	if _TRANSLATOR_OPTION_DISABLE_FLASHES=0 then screen_flash		500
endm

#-- 蝋燭エフェクト(小)--------------------------------------------------------
macro	rousoku_effect_small
#	@seh13
	rand	rnd,1,8
	rou_x = _x-40+64
	rou_y = _y-40+48
	if rnd=0 then goto rousoku_effect_s_01
	if rnd=1 then goto rousoku_effect_s_02
	if rnd=2 then goto rousoku_effect_s_03
	if rnd=3 then goto rousoku_effect_s_04
	if rnd=4 then goto rousoku_effect_s_05
	if rnd=5 then goto rousoku_effect_s_06
	if rnd=6 then goto rousoku_effect_s_07
	if rnd=7 then goto rousoku_effect_s_08

	label rousoku_effect_s_02
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato02s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_03
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato03s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_04
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato04s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_05
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato05s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_06
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato06s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_07
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato07s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label rousoku_effect_s_08
		layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato08s.png",rou_x,rou_y
		goto rousoku_effect_s_skip
	label	rousoku_effect_s_skip
endm

#-- 蝋燭エフェクト(大)--------------------------------------------------------
macro	rousoku_effect_big
#	@seh13
	rand	rnd,0,3
	rou_x = _x-72+64
	rou_y = _y-72+48

	if rnd=0 then layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato12s.png",rou_x,rou_y
	if rnd=1 then layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato06s.png",rou_x,rou_y
	if rnd=2 then layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato11s.png",rou_x,rou_y
	if rnd=3 then layer_load_paste	_LAYER,"system\TrainingSystem\rou_ato04s.png",rou_x,rou_y
endm

macro	set_motion_speed
	layer_allpass_speed	l_body,passspeed
	layer_allpass_speed	l_arm,passspeed
	layer_allpass_speed	l_head,passspeed
	layer_allpass_speed	l_leg,passspeed
endm

macro	training_allclear
	
endm

#イク時のエフェクト
macro	effect_iku
	if _TRANSLATOR_OPTION_DISABLE_FLASHES=0 then screen_flash	1000
	voice_bg_stop
	se_stop	0
	se_stop	1
endm

#調教アニメリリース
macro	training_anime_release
	screen_blackout	1000
	wait		1000
	voice_bg_stop
	for z=0 to 63
	layer_release z
	next
	@bg_black
	screen_blackin	10
endm

#調教アニメリリース
macro	all_layerrelease
	for z=0 to 63
	layer_release z
	next
endm

# macro to avoid untranslated training
# 
macro	remove_this_line_when_translating
	select skip_untranslated_training,"Goto untranslated activity","Pick something else"
	if skip_untranslated_training=1 then return
endm
