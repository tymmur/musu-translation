## みかんステータスチェック ##################################################
macro	mikan_check
	#けんこう
	if mikan_kenkou<0 then mikan_kenkou=0
	if mikan_kenkou>mikan_kenkou_max then mikan_kenkou=mikan_kenkou_max
	#きりょく
	if mikan_kiryoku<0 then mikan_kiryoku=0
	if mikan_kiryoku>mikan_kiryoku_max then mikan_kiryoku=mikan_kiryoku_max

	#からだ
	if mikan_karada<0 then mikan_karada=0
	if mikan_karada>mikan_karada_max then gosub mikan_check_levelup_karada
	#こころ
	if mikan_kokoro<0 then mikan_kokoro=0
	if mikan_kokoro>mikan_kokoro_max then gosub mikan_check_levelup_kokoro
	#あたま
	if mikan_atama<0 then mikan_atama=0
	if mikan_atama>mikan_atama_max then gosub mikan_check_levelup_atama

	#みりょく
	@calc_mikan_miryoku

	goto	mikan_check_skip

label	mikan_check_levelup_karada
	#からだレベルアップ
	if mikan_karada_level=99 then return
	lifebar_setauto		life_karada,mikan_karada
	wait	1000
	mikan_karada=mikan_karada-mikan_karada_max
	mikan_karada_max=mikan_karada_max+100
	mikan_karada_level=mikan_karada_level+1
	mikan_kenkou=mikan_kenkou+mikan_kenkou_max
	mikan_kenkou_max=mikan_kenkou_max+100
	lifebar_setlevel	life_karada,mikan_karada_level
	lifebar_setmax		life_karada,mikan_karada_max
	lifebar_set		life_karada,mikan_karada
	lifebar_setmax		life_kenkou,mikan_kenkou_max
	lifebar_set		life_kenkou,mikan_kenkou
	voice	"A02530"
	@status_levelup
	voice	"A02532"
	mikan_karada_levelup_flag=mikan_karada_levelup_flag+1
	return

label	mikan_check_levelup_kokoro
	#こころレベルアップ
	if mikan_kokoro_level=99 then return
	lifebar_setauto		life_kokoro,mikan_kokoro
	wait	1000
	mikan_kokoro=mikan_kokoro-mikan_kokoro_max
	mikan_kokoro_max=mikan_kokoro_max+100
	mikan_kokoro_level=mikan_kokoro_level+1
	mikan_kiryoku=mikan_kiryoku+mikan_kiryoku_max
	mikan_kiryoku_max=mikan_kiryoku_max+100
	lifebar_setlevel	life_kokoro,mikan_kokoro_level
	lifebar_setmax		life_kokoro,mikan_kokoro_max
	lifebar_set		life_kokoro,mikan_kokoro
	lifebar_setmax		life_kiryoku,mikan_kiryoku_max
	lifebar_set		life_kiryoku,mikan_kiryoku
	voice	"A02530"
	@status_levelup
	voice	"A02534"
	mikan_kokoro_levelup_flag=mikan_kokoro_levelup_flag+1
	return

label	mikan_check_levelup_atama
	#あたまレベルアップ
	if mikan_atama_level=99 then return
	lifebar_setauto		life_atama,mikan_atama
	wait	1000
	mikan_atama=mikan_atama-mikan_atama_max
	mikan_atama_max=mikan_atama_max+100
	mikan_atama_level=mikan_atama_level+1
	lifebar_setlevel	life_atama,mikan_atama_level
	lifebar_setmax		life_atama,mikan_atama_max
	lifebar_set		life_atama,mikan_atama
	voice	"A02530"
	@status_levelup
	@mikan_command_up
	voice	"A02536"
	mikan_atama_levelup_flag=mikan_atama_levelup_flag+1
	return

label	mikan_check_skip
endm

# みかんコマンドアップ########################################################
macro	mikan_command_up
	if mikan_atama_level>11 then goto mikan_command_up_skip
	@status_atamalevelup
	if mikan_atama_level=2 then mikan_study_level=2
	if mikan_atama_level=3 then mikan_work_level=2
	if mikan_atama_level=4 then mikan_special_level=2
	if mikan_atama_level=5 then mikan_rest_level=2
	if mikan_atama_level=6 then mikan_study_level=3
	if mikan_atama_level=7 then mikan_work_level=3
	if mikan_atama_level=8 then mikan_special_level=3
	if mikan_atama_level=9 then mikan_study_level=4
	if mikan_atama_level=10 then mikan_work_level=4
	if mikan_atama_level=11 then mikan_special_level=4
label	mikan_command_up_skip
endm

# みかん魅力計算 #############################################################
macro	calc_mikan_miryoku
	mikan_miryoku=mikan_atama+mikan_atama_max+mikan_karada+mikan_karada_max+mikan_kokoro+mikan_kokoro_max
	mikan_miryoku=mikan_miryoku/6+mikan_miryoku_sub
	if mikan_miryoku<0 then mikan_miryoku=0
	if mikan_miryoku>mikan_miryoku_max then mikan_miryoku=mikan_miryoku_max


#	if debug=1 then mikan_miryoku=1000
endm

# みかん魅力追加 #############################################################
macro	mikan_add_miryoku
	lifebar_setdirect	life_miryoku,mikan_miryoku
	mikan_miryoku_sub=mikan_miryoku_sub+add_miryoku
	@calc_mikan_miryoku
	lifebar_open	life_miryoku
	wait	500
	@mikan_check
	lifebar_setauto	life_miryoku,mikan_miryoku
	wait	1000
	lifebar_close	life_miryoku
	wait	500
endm














# みかんのスケジュールを全部休みにする #######################################
macro	mikan_schedule_alldown
	for n=0 to 4
		_mikan_command(n) = 90
	next
endm



#みかん　あたまアップ--------------------------------------------------------
macro	mikan_atama_up
	@mikan_set
	lifebar_open	life_atama
	wait	500
	mikan_atama=mikan_atama+mikan_atama_max/10
	@mikan_check
	lifebar_setauto	life_atama,mikan_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm
#みかん　あたまダウン--------------------------------------------------------
macro	mikan_atama_down
	@mikan_set
	lifebar_open	life_atama
	wait	500
	mikan_atama=mikan_atama-mikan_atama_max/10
	@mikan_check
	lifebar_setauto	life_atama,mikan_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm

#みかん　からだアップ--------------------------------------------------------
macro	mikan_karada_up
	@mikan_set
	lifebar_open	life_karada
	wait	500
	mikan_karada=mikan_karada+mikan_karada_max/10
	@mikan_check
	lifebar_setauto	life_karada,mikan_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm
#みかん　からだダウン--------------------------------------------------------
macro	mikan_karada_down
	@mikan_set
	lifebar_open	life_karada
	wait	500
	mikan_karada=mikan_karada-mikan_karada_max/10
	@mikan_check
	lifebar_setauto	life_karada,mikan_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm

#みかん　こころアップ--------------------------------------------------------
macro	mikan_kokoro_up
	@mikan_set
	lifebar_open	life_kokoro
	wait	500
	mikan_kokoro=mikan_kokoro+mikan_kokoro_max/10
	@mikan_check
	lifebar_setauto	life_kokoro,mikan_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm
#みかん　こころダウン--------------------------------------------------------
macro	mikan_kokoro_down
	@mikan_set
	lifebar_open	life_kokoro
	wait	500
	mikan_kokoro=mikan_kokoro-mikan_kokoro_max/10
	@mikan_check
	lifebar_setauto	life_kokoro,mikan_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm

#みかんライフバー 変更--------------------------------------------------------
macro	mikan_lifebar_draw
window_close
#オープン
if mikan_atama_old=mikan_atama then goto mikan_lifebar_draw_1
lifebar_open	life_atama
label	mikan_lifebar_draw_1
if mikan_karada_old=mikan_karada then goto mikan_lifebar_draw_2
lifebar_open	life_karada
label	mikan_lifebar_draw_2
if mikan_kokoro_old=mikan_kokoro then goto mikan_lifebar_draw_3
lifebar_open	life_kokoro
label	mikan_lifebar_draw_3

	wait	500

	#加算/減算
	lifebar_setauto	life_atama,mikan_atama
	lifebar_setauto	life_karada,mikan_karada
	lifebar_setauto	life_kokoro,mikan_kokoro

	wait	3000

	lifebar_close	life_atama
	lifebar_close	life_karada
	lifebar_close	life_kokoro
endm

#みかんパラメータセット-------------------------------------------------------
macro	mikan_set
	@mikan_check
	lifebar_setmax		life_kenkou,mikan_kenkou_max
	lifebar_setdirect	life_kenkou,mikan_kenkou
	lifebar_setmax		life_kiryoku,mikan_kiryoku_max
	lifebar_setdirect	life_kiryoku,mikan_kiryoku
	lifebar_setmax		life_miryoku,mikan_miryoku_max
	lifebar_setdirect	life_miryoku,mikan_miryoku
	lifebar_setmax		life_karada,mikan_karada_max
	lifebar_setdirect	life_karada,mikan_karada
	lifebar_setmax		life_kokoro,mikan_kokoro_max
	lifebar_setdirect	life_kokoro,mikan_kokoro
	lifebar_setmax		life_atama,mikan_atama_max
	lifebar_setdirect	life_atama,mikan_atama
	lifebar_setlevel	life_karada,mikan_karada_level
	lifebar_setlevel	life_atama,mikan_atama_level
	lifebar_setlevel	life_kokoro,mikan_kokoro_level
endm

#みかんパラメータセット-------------------------------------------------------
macro	mikan_setauto
	@mikan_check
	lifebar_setmax		life_kenkou,mikan_kenkou_max
	lifebar_setauto		life_kenkou,mikan_kenkou
	lifebar_setmax		life_kiryoku,mikan_kiryoku_max
	lifebar_setauto		life_kiryoku,mikan_kiryoku
	lifebar_setmax		life_miryoku,mikan_miryoku_max
	lifebar_setauto		life_miryoku,mikan_miryoku
	lifebar_setmax		life_karada,mikan_karada_max
	lifebar_setauto		life_karada,mikan_karada
	lifebar_setmax		life_kokoro,mikan_kokoro_max
	lifebar_setauto		life_kokoro,mikan_kokoro
	lifebar_setmax		life_atama,mikan_atama_max
	lifebar_setauto		life_atama,mikan_atama
	lifebar_setlevel	life_karada,mikan_karada_level
	lifebar_setlevel	life_atama,mikan_atama_level
	lifebar_setlevel	life_kokoro,mikan_kokoro_level
endm



















#みかんステータス表示 #######################################################
macro	status_mikan
minimoney_close
@bg_mikan
@status_chara_mikan

money_open
@mikan_set
@mikan_plate_open
@lifebar_fullopen

endm

# みかんステータス表示 #######################################################
macro	status_open_mikan
minimoney_close
money_open
@mikan_plate_open
@mikan_set
@lifebar_fullopen
@bg_mikan_n
@mikan_middle
@status_chara_mikan
endm

# みかんステータス非表示 #####################################################
macro	status_close_mikan
money_close
@mikan_plate_close
@lifebar_fullclose
@mikan_
endm

# みかんステータスキャラ表示 #################################################
macro	status_chara_mikan
@mikan_shifuku
@mikan_middle
now=mikan_kenkou
max=mikan_kenkou_max/8
if mikan_kenkou<mikan_kiryoku then goto status_chara_mikan_0
now=mikan_kiryoku
max=mikan_kiryoku_max/8
label	status_chara_mikan_0

if now>max*6 	then goto status_chara_mikan_1
if now>max*4 	then goto status_chara_mikan_2
if now>max*2	then goto status_chara_mikan_3
if now>max 	then goto status_chara_mikan_4
if now=0 	then goto status_chara_mikan_5
goto status_chara_mikan_4

label	status_chara_mikan_1
@mikan_warai2
goto	status_chara_mikan_skip

label	status_chara_mikan_2
@mikan
goto	status_chara_mikan_skip

label	status_chara_mikan_3
voice "A02538"
@mikan_kanashimi
goto	status_chara_mikan_skip

label	status_chara_mikan_4
voice "A02538"
@mikan_naki
goto	status_chara_mikan_skip

label	status_chara_mikan_5
@mikan_houshin
goto	status_chara_mikan_skip

label	status_chara_mikan_skip
endm

#みかんプレートオープン ######################################################
macro	mikan_plate_open
	if plate=1 then goto mikan_plate_open_skip
	layer_load 		5,"schedule\status_name_mikan_.png"
	layer_position_set 	5,510,4
	layer_move		5,500,300,-300,0,0,PASSTYPE_BEZIER_A
	plate=1
label	mikan_plate_open_skip
endm

#みかんプレートクローズ ######################################################
macro	mikan_plate_close
	if plate=0 then goto mikan_plate_close_skip
	layer_move		5,500,0,0,300,-300,PASSTYPE_BEZIER_B
	plate=0
label	mikan_plate_close_skip
endm
