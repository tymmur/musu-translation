#かりんパラメータセット-------------------------------------------------------
macro	karin_set
	@karin_check
	lifebar_setmax		life_kenkou,karin_kenkou_max
	lifebar_setdirect	life_kenkou,karin_kenkou
	lifebar_setmax		life_kiryoku,karin_kiryoku_max
	lifebar_setdirect	life_kiryoku,karin_kiryoku
	lifebar_setmax		life_miryoku,karin_miryoku_max
	lifebar_setdirect	life_miryoku,karin_miryoku
	lifebar_setmax		life_karada,karin_karada_max
	lifebar_setdirect	life_karada,karin_karada
	lifebar_setmax		life_kokoro,karin_kokoro_max
	lifebar_setdirect	life_kokoro,karin_kokoro
	lifebar_setmax		life_atama,karin_atama_max
	lifebar_setdirect	life_atama,karin_atama
	lifebar_setlevel	life_karada,karin_karada_level
	lifebar_setlevel	life_atama,karin_atama_level
	lifebar_setlevel	life_kokoro,karin_kokoro_level
endm


#みかんパラメータセット-------------------------------------------------------
macro	karin_setauto
	@karin_check
	lifebar_setmax		life_kenkou,karin_kenkou_max
	lifebar_setauto		life_kenkou,karin_kenkou
	lifebar_setmax		life_kiryoku,karin_kiryoku_max
	lifebar_setauto		life_kiryoku,karin_kiryoku
	lifebar_setmax		life_miryoku,karin_miryoku_max
	lifebar_setauto		life_miryoku,karin_miryoku
	lifebar_setmax		life_karada,karin_karada_max
	lifebar_setauto		life_karada,karin_karada
	lifebar_setmax		life_kokoro,karin_kokoro_max
	lifebar_setauto		life_kokoro,karin_kokoro
	lifebar_setmax		life_atama,karin_atama_max
	lifebar_setauto		life_atama,karin_atama
	lifebar_setlevel	life_karada,karin_karada_level
	lifebar_setlevel	life_atama,karin_atama_level
	lifebar_setlevel	life_kokoro,karin_kokoro_level
endm



## みかんステータスチェック ##################################################
macro	karin_check
	#けんこう
	if karin_kenkou<0 then karin_kenkou=0
	if karin_kenkou>karin_kenkou_max then karin_kenkou=karin_kenkou_max
	#きりょく
	if karin_kiryoku<0 then karin_kiryoku=0
	if karin_kiryoku>karin_kiryoku_max then karin_kiryoku=karin_kiryoku_max

	#からだ
	if karin_karada<0 then karin_karada=0
	if karin_karada>karin_karada_max then gosub karin_check_levelup_karada
	#こころ
	if karin_kokoro<0 then karin_kokoro=0
	if karin_kokoro>karin_kokoro_max then gosub karin_check_levelup_kokoro
	#あたま
	if karin_atama<0 then karin_atama=0
	if karin_atama>karin_atama_max then gosub karin_check_levelup_atama

	#みりょく
	@calc_karin_miryoku

	goto	karin_check_skip

label	karin_check_levelup_karada
	#からだレベルアップ
	if karin_karada_level=99 then return
	lifebar_setauto		life_karada,karin_karada
	wait	1000
	karin_karada=karin_karada-karin_karada_max
	karin_karada_max=karin_karada_max+100
	karin_karada_level=karin_karada_level+1
	karin_kenkou=karin_kenkou+karin_kenkou_max
	karin_kenkou_max=karin_kenkou_max+100
	lifebar_setlevel	life_karada,karin_karada_level
	lifebar_setmax		life_karada,karin_karada_max
	lifebar_set		life_karada,karin_karada
	lifebar_setmax		life_kenkou,karin_kenkou_max
	lifebar_set		life_kenkou,karin_kenkou
	voice	"P03582"
	@status_levelup
	voice	"P03584"
	karin_karada_levelup_flag=karin_karada_levelup_flag+1
	return

label	karin_check_levelup_kokoro
	#こころレベルアップ
	if karin_kokoro_level=99 then return
	lifebar_setauto		life_kokoro,karin_kokoro
	wait	1000
	karin_kokoro=karin_kokoro-karin_kokoro_max
	karin_kokoro_max=karin_kokoro_max+100
	karin_kokoro_level=karin_kokoro_level+1
	karin_kiryoku=karin_kiryoku+karin_kiryoku_max
	karin_kiryoku_max=karin_kiryoku_max+100
	lifebar_setlevel	life_kokoro,karin_kokoro_level
	lifebar_setmax		life_kokoro,karin_kokoro_max
	lifebar_set		life_kokoro,karin_kokoro
	lifebar_setmax		life_kiryoku,karin_kiryoku_max
	lifebar_set		life_kiryoku,karin_kiryoku
	voice	"P03582"
	@status_levelup
	voice	"P03586"
	karin_kokoro_levelup_flag=karin_kokoro_levelup_flag+1
	return

label	karin_check_levelup_atama
	#あたまレベルアップ
	if karin_atama_level=99 then return
	lifebar_setauto		life_atama,karin_atama
	wait	1000
	karin_atama=karin_atama-karin_atama_max
	karin_atama_max=karin_atama_max+100
	karin_atama_level=karin_atama_level+1
	lifebar_setlevel	life_atama,karin_atama_level
	lifebar_setmax		life_atama,karin_atama_max
	lifebar_set		life_atama,karin_atama
	voice	"P03582"
	@status_levelup
	@karin_command_up
	voice	"P03588"
	karin_atama_levelup_flag=karin_atama_levelup_flag+1
	return

label	karin_check_skip
endm

# みかんコマンドアップ########################################################
macro	karin_command_up
	if karin_atama_level>11 then goto karin_command_up_skip
	@status_atamalevelup
	if karin_atama_level=2 then karin_study_level=2
	if karin_atama_level=3 then karin_work_level=2
	if karin_atama_level=4 then karin_special_level=2
	if karin_atama_level=5 then karin_rest_level=2
	if karin_atama_level=6 then karin_study_level=3
	if karin_atama_level=7 then karin_work_level=3
	if karin_atama_level=8 then karin_special_level=3
	if karin_atama_level=9 then karin_study_level=4
	if karin_atama_level=10 then karin_work_level=4
	if karin_atama_level=11 then karin_special_level=4
label	karin_command_up_skip
endm


#かりん魅力計算 #############################################################
macro	calc_karin_miryoku
#	if karin_miryoku_sub>500 then karin_miryoku_sub=500
	karin_miryoku=karin_atama+karin_atama_max+karin_karada+karin_karada_max+karin_kokoro+karin_kokoro_max
	karin_miryoku=karin_miryoku/6+karin_miryoku_sub
	if karin_miryoku<0 then karin_miryoku=0
	if karin_miryoku>karin_miryoku_max then karin_miryoku=karin_miryoku_max

#	if debug=1 then karin_miryoku=1000


endm

# かりん魅力追加 #############################################################
macro	karin_add_miryoku
	lifebar_setdirect	life_miryoku,karin_miryoku
	karin_miryoku_sub=karin_miryoku_sub+add_miryoku
	@calc_karin_miryoku
	lifebar_open	life_miryoku
	wait	500
	lifebar_setauto	life_miryoku,karin_miryoku
	wait	1000
	lifebar_close	life_miryoku
	wait	500
endm


# かりんのスケジュールを全部休みにする #######################################
macro	karin_schedule_alldown
	for n=0 to 4
		_karin_command(n) = 90
	next
endm











#かりん　あたまアップ--------------------------------------------------------
macro	karin_atama_up
	@karin_set
	lifebar_open	life_atama
	wait	500
	karin_atama=karin_atama+karin_atama_max/10
	@karin_check
	lifebar_setauto	life_atama,karin_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm
#かりん　あたまダウン--------------------------------------------------------
macro	karin_atama_down
	@karin_set
	lifebar_open	life_atama
	wait	500
	karin_atama=karin_atama-karin_atama_max/10
	@karin_check
	lifebar_setauto	life_atama,karin_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm

#かりん　からだアップ--------------------------------------------------------
macro	karin_karada_up
	@karin_set
	lifebar_open	life_karada
	wait	500
	karin_karada=karin_karada+karin_karada_max/10
	@karin_check
	lifebar_setauto	life_karada,karin_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm
#かりん　からだダウン--------------------------------------------------------
macro	karin_karada_down
	@karin_set
	lifebar_open	life_karada
	wait	500
	karin_karada=karin_karada-karin_karada_max/10
	@karin_check
	lifebar_setauto	life_karada,karin_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm

#かりん　こころアップ--------------------------------------------------------
macro	karin_kokoro_up
	@karin_set
	lifebar_open	life_kokoro
	wait	500
	karin_kokoro=karin_kokoro+karin_kokoro_max/10
	@karin_check
	lifebar_setauto	life_kokoro,karin_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm
#かりん　こころダウン--------------------------------------------------------
macro	karin_kokoro_down
	@karin_set
	lifebar_open	life_kokoro
	wait	500
	karin_kokoro=karin_kokoro-karin_kokoro_max/10
	@karin_check
	lifebar_setauto	life_kokoro,karin_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm











#かりんステータス表示 #######################################################
macro	status_karin
minimoney_close
@bg_karin
@status_chara_karin

money_open
@karin_set
@karin_plate_open
@lifebar_fullopen

endm

# かりんステータス表示 #######################################################
macro	status_open_karin
minimoney_close
money_open
@karin_plate_open
@karin_set
@lifebar_fullopen
@bg_karin_n
@karin_middle
@status_chara_karin
endm

# かりんステータス非表示 #####################################################
macro	status_close_karin
money_close
@karin_plate_close
@lifebar_fullclose
@karin_
endm

# かりんステータスキャラ表示 #################################################
macro	status_chara_karin
@karin_shifuku
@karin_middle
now=karin_kenkou
max=karin_kenkou_max/8
if karin_kenkou<karin_kiryoku then goto status_chara_karin_0
now=karin_kiryoku
max=karin_kiryoku_max/8
label	status_chara_karin_0

if now>max*6 	then goto status_chara_karin_1
if now>max*4 	then goto status_chara_karin_2
if now>max*2	then goto status_chara_karin_3
if now>max 	then goto status_chara_karin_4
if now=0 	then goto status_chara_karin_5
goto status_chara_karin_4

label	status_chara_karin_1
@karin_warai
goto	status_chara_karin_skip

label	status_chara_karin_2
@karin
goto	status_chara_karin_skip

label	status_chara_karin_3
#voice "A02538"
@karin_kanashimi
goto	status_chara_karin_skip

label	status_chara_karin_4
#voice "A02538"
@karin_naki
goto	status_chara_karin_skip

label	status_chara_karin_5
@karin_houshin
goto	status_chara_karin_skip

label	status_chara_karin_skip
endm

#かりんプレートオープン ######################################################
macro	karin_plate_open
	layer_load 		5,"schedule\status_name_karin_.png"
	layer_position_set 	5,510,4
	layer_move		5,500,300,-300,0,0,PASSTYPE_BEZIER_A
endm

#かりんプレートクローズ ######################################################
macro	karin_plate_close
	layer_move		5,500,0,0,300,-300,PASSTYPE_BEZIER_B
endm

