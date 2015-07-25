## 誠司立ち設定 #############################################################
chara_folder	l_seiji,"chara"
chara_name	l_seiji,"誠司"
@seiji_small
@seiji_shifuku

## 消す #######################################################################
macro	seiji_
	chara_off	l_seiji
	layer_release	l_seiji+1
endmacro

## 距離 #######################################################################
# 遠い
macro	seiji_small
	chara_size	l_seiji,"小",0,-30
endm

# 中間
macro	seiji_middle
	chara_size	l_seiji,"中",0,0
endm

# 近い
macro	seiji_large
	chara_size	l_seiji,"大",0,0
endm

## 服装 ######################################################################
macro	seiji_shifuku
	chara_clothes	l_seiji,"私服"
endm


## 表情 ######################################################################

#- 普通 ----------------------------------------------------------------------
macro	seiji
	layer_release	l_seiji+1
	chara_auto	l_seiji,"普.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	seiji_warai
	layer_release	l_seiji+1
	chara_auto	l_seiji,"笑.png"
endm
#- 怒り ----------------------------------------------------------------------
macro	seiji_ikari
	layer_release	l_seiji+1
	chara_auto	l_seiji,"怒.png"
endm
#- にこ ----------------------------------------------------------------------
macro	seiji_niko
	layer_release	l_seiji+1
	chara_auto	l_seiji,"にこ.png"
endm


#- 汗 ----------------------------------------------------------------------
macro	seiji_ase
	layer_release	l_seiji+1
	chara_auto	l_seiji,"笑.png"
endm
#- 驚き ----------------------------------------------------------------------
macro	seiji_odoroki
	layer_release	l_seiji+1
	chara_auto	l_seiji,"驚.png"
endm
#- 哀しみ --------------------------------------------------------------------
macro	seiji_kanashimi
	layer_release	l_seiji+1
	chara_auto	l_seiji,"哀.png"
endm
#- 号泣 ----------------------------------------------------------------------
macro	seiji_goukyuu
	layer_release	l_seiji+1
	chara_auto	l_seiji,"号泣.png"
endm



#- 普通 ----------------------------------------------------------------------
macro	seiji2
	layer_release	l_seiji+1
	chara_auto	l_seiji,"普.png"
endm
#- 笑い ----------------------------------------------------------------------
macro	seiji2_warai
	layer_release	l_seiji+1
	chara_auto	l_seiji,"笑.png"
	layer_movepass_add	l_seiji,0,100,0,8
	layer_movepass_add	l_seiji,0,100,0,0
	layer_movepass_add	l_seiji,0,100,0,8
	layer_movepass_add	l_seiji,0,100,0,0
	layer_movepass_add	l_seiji,0,100,0,8
	layer_movepass_add	l_seiji,0,100,0,0
	layer_movepass_add	l_seiji,0,100,0,8
	layer_movepass_add	l_seiji,0,100,0,0
	layer_movepass_add	l_seiji,0,100,0,8
	layer_movepass_add	l_seiji,0,100,0,0
	layer_movepass_play	l_seiji,0,play_once

	chara		l_seiji+1,"chara\マーク\てんてんマーク2_小.png"
	layer_reference_set	l_seiji+1,l_seiji
	layer_position	l_seiji+1,120,40
	layer_scalepass_add 	l_seiji+1,0,	300,30,30
	layer_scalepass_add 	l_seiji+1,0,	300,0,0
	layer_scalepass_play	l_seiji+1,0,	PLAY_LOOP
endm
#- 怒り ----------------------------------------------------------------------
macro	seiji2_ikari
	layer_release	l_seiji+1
	chara_auto	l_seiji,"怒.png"
#	layer_movepass_add	l_seiji,0,50,0,8
#	layer_movepass_add	l_seiji,0,50,0,0
#	layer_movepass_add	l_seiji,0,50,0,8
#	layer_movepass_add	l_seiji,0,50,0,0
#	layer_movepass_add	l_seiji,0,50,0,8
#	layer_movepass_add	l_seiji,0,50,0,0
#	layer_movepass_add	l_seiji,0,50,0,8
#	layer_movepass_add	l_seiji,0,50,0,0
#	layer_movepass_add	l_seiji,0,50,0,8
#	layer_movepass_add	l_seiji,0,50,0,0
#	layer_movepass_play	l_seiji,0,play_once

	chara		l_seiji+1,"chara\マーク\怒りマーク_小.png"
	layer_reference_set	l_seiji+1,l_seiji
	layer_position	l_seiji+1,160,32
	layer_scalepass_add 	l_seiji+1,0,	100,20,20
	layer_scalepass_add 	l_seiji+1,0,	100,0,0
	layer_scalepass_play	l_seiji+1,0,	PLAY_LOOP


endm
#- にこ ----------------------------------------------------------------------
macro	seiji2_niko
	layer_release	l_seiji+1
	chara_auto	l_seiji,"にこ.png"
endm


#- 汗 ----------------------------------------------------------------------
macro	seiji2_ase
	layer_release	l_seiji+1
	chara_auto	l_seiji,"笑.png"
	chara		l_seiji+1,"chara\マーク\飛ぶ汗マーク2_小.png"

	layer_reference_set	l_seiji+1,l_seiji
	layer_position	l_seiji+1,120,20
	layer_movepass_add	l_seiji+1,0,0,0,0
	layer_movepass_add	l_seiji+1,0,1000,-32,32
	layer_movepass_play	l_seiji+1,0,play_once
	layer_alpha		l_seiji+1,1000,0,-255,passtype_tcb
endm
#- 驚き ----------------------------------------------------------------------
macro	seiji2_odoroki
	layer_release	l_seiji+1
	chara_auto	l_seiji,"驚.png"
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_play	l_seiji,0,play_once

	chara		l_seiji+1,"chara\マーク\汗マーク_小.png"
	layer_reference_set	l_seiji+1,l_seiji
	layer_position	l_seiji+1,160,-16
	layer_move	l_seiji+1,500,0,0,0,80,passtype_tcb
endm
#- 哀しみ --------------------------------------------------------------------
macro	seiji2_kanashimi
	layer_release	l_seiji+1
	chara_auto	l_seiji,"哀.png"
	chara		l_seiji+1,"chara\マーク\もやもや_小.png"
	layer_reference_set	l_seiji+1,l_seiji
	layer_position	l_seiji+1,100,40
	layer_scalepass_add 	l_seiji+1,0,	300,20,20
	layer_scalepass_add 	l_seiji+1,0,	300,0,0
	layer_scalepass_play	l_seiji+1,0,	PLAY_LOOP
endm
#- 号泣 ----------------------------------------------------------------------
macro	seiji2_goukyuu
	layer_release	l_seiji+1
	chara_auto	l_seiji,"号泣.png"
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_add	l_seiji,0,50,0,8
	layer_movepass_add	l_seiji,0,50,0,0
	layer_movepass_play	l_seiji,0,play_loop
endm

