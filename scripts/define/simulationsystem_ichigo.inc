#いちごパラメータセット-------------------------------------------------------
macro	ichigo_set
	@ichigo_check
	lifebar_setmax		life_kenkou,ichigo_kenkou_max
	lifebar_setdirect	life_kenkou,ichigo_kenkou
	lifebar_setmax		life_kiryoku,ichigo_kiryoku_max
	lifebar_setdirect	life_kiryoku,ichigo_kiryoku
	lifebar_setmax		life_miryoku,ichigo_miryoku_max
	lifebar_setdirect	life_miryoku,ichigo_miryoku
	lifebar_setmax		life_karada,ichigo_karada_max
	lifebar_setdirect	life_karada,ichigo_karada
	lifebar_setmax		life_kokoro,ichigo_kokoro_max
	lifebar_setdirect	life_kokoro,ichigo_kokoro
	lifebar_setmax		life_atama,ichigo_atama_max
	lifebar_setdirect	life_atama,ichigo_atama
	lifebar_setlevel	life_karada,ichigo_karada_level
	lifebar_setlevel	life_atama,ichigo_atama_level
	lifebar_setlevel	life_kokoro,ichigo_kokoro_level
endm

#みかんパラメータセット-------------------------------------------------------
macro	ichigo_setauto
	@ichigo_check
	lifebar_setmax		life_kenkou,ichigo_kenkou_max
	lifebar_setauto		life_kenkou,ichigo_kenkou
	lifebar_setmax		life_kiryoku,ichigo_kiryoku_max
	lifebar_setauto		life_kiryoku,ichigo_kiryoku
	lifebar_setmax		life_miryoku,ichigo_miryoku_max
	lifebar_setauto		life_miryoku,ichigo_miryoku
	lifebar_setmax		life_karada,ichigo_karada_max
	lifebar_setauto		life_karada,ichigo_karada
	lifebar_setmax		life_kokoro,ichigo_kokoro_max
	lifebar_setauto		life_kokoro,ichigo_kokoro
	lifebar_setmax		life_atama,ichigo_atama_max
	lifebar_setauto		life_atama,ichigo_atama
	lifebar_setlevel	life_karada,ichigo_karada_level
	lifebar_setlevel	life_atama,ichigo_atama_level
	lifebar_setlevel	life_kokoro,ichigo_kokoro_level
endm





## みかんステータスチェック ##################################################
macro	ichigo_check
	#けんこう
	if ichigo_kenkou<0 then ichigo_kenkou=0
	if ichigo_kenkou>ichigo_kenkou_max then ichigo_kenkou=ichigo_kenkou_max
	#きりょく
	if ichigo_kiryoku<0 then ichigo_kiryoku=0
	if ichigo_kiryoku>ichigo_kiryoku_max then ichigo_kiryoku=ichigo_kiryoku_max

	#からだ
	if ichigo_karada<0 then ichigo_karada=0
	if ichigo_karada>ichigo_karada_max then gosub ichigo_check_levelup_karada
	#こころ
	if ichigo_kokoro<0 then ichigo_kokoro=0
	if ichigo_kokoro>ichigo_kokoro_max then gosub ichigo_check_levelup_kokoro
	#あたま
	if ichigo_atama<0 then ichigo_atama=0
	if ichigo_atama>ichigo_atama_max then gosub ichigo_check_levelup_atama

	#みりょく
	@calc_ichigo_miryoku

	goto	ichigo_check_skip

label	ichigo_check_levelup_karada
	#からだレベルアップ
	if ichigo_karada_level=99 then return
	lifebar_setauto		life_karada,ichigo_karada
	wait	1000
	ichigo_karada=ichigo_karada-ichigo_karada_max
	ichigo_karada_max=ichigo_karada_max+100
	ichigo_karada_level=ichigo_karada_level+1
	ichigo_kenkou=ichigo_kenkou+ichigo_kenkou_max
	ichigo_kenkou_max=ichigo_kenkou_max+100
	lifebar_setlevel	life_karada,ichigo_karada_level
	lifebar_setmax		life_karada,ichigo_karada_max
	lifebar_set		life_karada,ichigo_karada
	lifebar_setmax		life_kenkou,ichigo_kenkou_max
	lifebar_set		life_kenkou,ichigo_kenkou
	voice	"O03716"
	@status_levelup
	voice	"O03718"
	ichigo_karada_levelup_flag=ichigo_karada_levelup_flag+1
	return

label	ichigo_check_levelup_kokoro
	#こころレベルアップ
	if ichigo_kokoro_level=99 then return
	lifebar_setauto		life_kokoro,ichigo_kokoro
	wait	1000
	ichigo_kokoro=ichigo_kokoro-ichigo_kokoro_max
	ichigo_kokoro_max=ichigo_kokoro_max+100
	ichigo_kokoro_level=ichigo_kokoro_level+1
	ichigo_kiryoku=ichigo_kiryoku+ichigo_kiryoku_max
	ichigo_kiryoku_max=ichigo_kiryoku_max+100
	lifebar_setlevel	life_kokoro,ichigo_kokoro_level
	lifebar_setmax		life_kokoro,ichigo_kokoro_max
	lifebar_set		life_kokoro,ichigo_kokoro
	lifebar_setmax		life_kiryoku,ichigo_kiryoku_max
	lifebar_set		life_kiryoku,ichigo_kiryoku
	voice	"O03716"
	@status_levelup
	voice	"O03720"
	ichigo_kokoro_levelup_flag=ichigo_kokoro_levelup_flag+1
	return

label	ichigo_check_levelup_atama
	#あたまレベルアップ
	if ichigo_atama_level=99 then return
	lifebar_setauto		life_atama,ichigo_atama
	wait	1000
	ichigo_atama=ichigo_atama-ichigo_atama_max
	ichigo_atama_max=ichigo_atama_max+100
	ichigo_atama_level=ichigo_atama_level+1
	lifebar_setlevel	life_atama,ichigo_atama_level
	lifebar_setmax		life_atama,ichigo_atama_max
	lifebar_set		life_atama,ichigo_atama
	voice	"O03716"
	@status_levelup
	@ichigo_command_up
	voice	"O03722"
	ichigo_atama_levelup_flag=ichigo_atama_levelup_flag+1
	return

label	ichigo_check_skip
endm

# みかんコマンドアップ########################################################
macro	ichigo_command_up
	if ichigo_atama_level>11 then goto ichigo_command_up_skip
	@status_atamalevelup
	if ichigo_atama_level=2 then ichigo_study_level=2
	if ichigo_atama_level=3 then ichigo_work_level=2
	if ichigo_atama_level=4 then ichigo_special_level=2
	if ichigo_atama_level=5 then ichigo_rest_level=2
	if ichigo_atama_level=6 then ichigo_study_level=3
	if ichigo_atama_level=7 then ichigo_work_level=3
	if ichigo_atama_level=8 then ichigo_special_level=3
	if ichigo_atama_level=9 then ichigo_study_level=4
	if ichigo_atama_level=10 then ichigo_work_level=4
	if ichigo_atama_level=11 then ichigo_special_level=4
label	ichigo_command_up_skip
endm


#いちご魅力計算 #############################################################
macro	calc_ichigo_miryoku
	ichigo_miryoku=ichigo_atama+ichigo_atama_max+ichigo_karada+ichigo_karada_max+ichigo_kokoro+ichigo_kokoro_max
	ichigo_miryoku=ichigo_miryoku/6+ichigo_miryoku_sub
	if ichigo_miryoku<0 then ichigo_miryoku=0
	if ichigo_miryoku>ichigo_miryoku_max then ichigo_miryoku=ichigo_miryoku_max
endm

# いちご魅力追加 #############################################################
macro	ichigo_add_miryoku
	lifebar_setdirect	life_miryoku,ichigo_miryoku
	ichigo_miryoku_sub=ichigo_miryoku_sub+add_miryoku
	@calc_ichigo_miryoku
	lifebar_open	life_miryoku
	wait	500
	lifebar_setauto	life_miryoku,ichigo_miryoku
	wait	1000
	lifebar_close	life_miryoku
	wait	500
endm


























# いちごのスケジュールを全部休みにする #######################################
macro	ichigo_schedule_alldown
	for n=0 to 4
		_ichigo_command(n) = 90
	next
endm

























#いちご　あたまアップ--------------------------------------------------------
macro	ichigo_atama_up
	@ichigo_set
	lifebar_open	life_atama
	wait	500
	ichigo_atama=ichigo_atama+ichigo_atama_max/10
	@ichigo_check
	lifebar_setauto	life_atama,ichigo_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm
#いちご　あたまダウン--------------------------------------------------------
macro	ichigo_atama_down
	@ichigo_set
	lifebar_open	life_atama
	wait	500
	ichigo_atama=ichigo_atama-ichigo_atama_max/10
	@ichigo_check
	lifebar_setauto	life_atama,ichigo_atama
	wait	1000
	lifebar_close	life_atama
	wait	500
endm

#いちご　からだアップ--------------------------------------------------------
macro	ichigo_karada_up
	@ichigo_set
	lifebar_open	life_karada
	wait	500
	ichigo_karada=ichigo_karada+ichigo_karada_max/10
	@ichigo_check
	lifebar_setauto	life_karada,ichigo_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm
#いちご　からだアップ--------------------------------------------------------
macro	ichigo_karada_up2
	@ichigo_set
	lifebar_open	life_karada
	wait	500
	ichigo_karada=ichigo_karada+ichigo_karada_max/5
	@ichigo_check
	lifebar_setauto	life_karada,ichigo_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm
#いちご　からだダウン--------------------------------------------------------
macro	ichigo_karada_down
	@ichigo_set
	lifebar_open	life_karada
	wait	500
	ichigo_karada=ichigo_karada-ichigo_karada_max/10
	@ichigo_check
	lifebar_setauto	life_karada,ichigo_karada
	wait	1000
	lifebar_close	life_karada
	wait	500
endm

#いちご　こころアップ--------------------------------------------------------
macro	ichigo_kokoro_up
	@ichigo_set
	lifebar_open	life_kokoro
	wait	500
	ichigo_kokoro=ichigo_kokoro+ichigo_kokoro_max/10
	@ichigo_check
	lifebar_setauto	life_kokoro,ichigo_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm
#いちご　こころダウン--------------------------------------------------------
macro	ichigo_kokoro_down
	@ichigo_set
	lifebar_open	life_kokoro
	wait	500
	ichigo_kokoro=ichigo_kokoro-ichigo_kokoro_max/10
	@ichigo_check
	lifebar_setauto	life_kokoro,ichigo_kokoro
	wait	1000
	lifebar_close	life_kokoro
	wait	500
endm







#いちごステータス表示 #######################################################
macro	status_ichigo
minimoney_close
@bg_ichigo
@status_chara_ichigo

money_open
@ichigo_set
@ichigo_plate_open
@lifebar_fullopen

endm

# いちごステータス表示 #######################################################
macro	status_open_ichigo
minimoney_close
money_open
@ichigo_plate_open
@ichigo_set
@lifebar_fullopen
@bg_ichigo_n
@ichigo_middle
@status_chara_ichigo
endm

# いちごステータス非表示 #####################################################
macro	status_close_ichigo
money_close
@ichigo_plate_close
@lifebar_fullclose
@ichigo_
endm

# いちごステータスキャラ表示 #################################################
macro	status_chara_ichigo
@ichigo_shifuku
@ichigo_middle
now=ichigo_kenkou
max=ichigo_kenkou_max/8
if ichigo_kenkou<ichigo_kiryoku then goto status_chara_ichigo_0
now=ichigo_kiryoku
max=ichigo_kiryoku_max/8
label	status_chara_ichigo_0

if now>max*6 	then goto status_chara_ichigo_1
if now>max*4 	then goto status_chara_ichigo_2
if now>max*2	then goto status_chara_ichigo_3
if now>max 	then goto status_chara_ichigo_4
if now=0 	then goto status_chara_ichigo_5
goto status_chara_ichigo_4

label	status_chara_ichigo_1
@ichigo_warai
goto	status_chara_ichigo_skip

label	status_chara_ichigo_2
@ichigo
goto	status_chara_ichigo_skip

label	status_chara_ichigo_3
#voice "A02538"
@ichigo_kanashimi
goto	status_chara_ichigo_skip

label	status_chara_ichigo_4
#voice "A02538"
@ichigo_naki
goto	status_chara_ichigo_skip

label	status_chara_ichigo_5
@ichigo_houshin
goto	status_chara_ichigo_skip

label	status_chara_ichigo_skip
endm

#いちごプレートオープン ######################################################
macro	ichigo_plate_open
	layer_load 		5,"schedule\status_name_ichigo_.png"
	layer_position_set 	5,510,4
	layer_move		5,500,300,-300,0,0,PASSTYPE_BEZIER_A
endm

#いちごプレートクローズ ######################################################
macro	ichigo_plate_close
	layer_move		5,500,0,0,300,-300,PASSTYPE_BEZIER_B
endm

