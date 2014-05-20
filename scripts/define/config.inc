
#メッセージウィンドウの位置
SetMessageWindowPos	9,362

#みかん ----------------------------------------------------------------------

#健康
life_kenkou	=	0
lifebar_load		life_kenkou,"system\lifebar\status_kenkou.png"
lifebar_position	life_kenkou,510,310
lifebar_levelmode	life_kenkou,false

mikan_kenkou	=	100			#みかん健康
mikan_kenkou_max=	100			#みかん健康(最大値)
mikan_kenkou_hosei=	1

karin_kenkou	=	80			#みかん健康
karin_kenkou_max=	80			#みかん健康(最大値)
karin_kenkou_hosei=	0.9

ichigo_kenkou	=	120			#みかん健康
ichigo_kenkou_max=	120			#みかん健康(最大値)
ichigo_kenkou_hosei=	1.2


#気力
life_kiryoku	=	1
lifebar_load		life_kiryoku,"system\lifebar\status_kiryoku.png"
lifebar_position	life_kiryoku,510,310+44*1
lifebar_levelmode	life_kiryoku,false

mikan_kiryoku	=	100			#みかん気力
mikan_kiryoku_max=	100			#みかん気力(最大値)
mikan_kiryoku_hosei=	1

karin_kiryoku	=	120			#みかん気力
karin_kiryoku_max=	120			#みかん気力(最大値)
karin_kiryoku_hosei=	1.2

ichigo_kiryoku	=	80			#みかん気力
ichigo_kiryoku_max=	80			#みかん気力(最大値)
ichigo_kiryoku_hosei=	0.9


#魅力
life_miryoku	=	2
lifebar_load		life_miryoku,"system\lifebar\status_miryoku.png"
lifebar_position	life_miryoku,510,310+44*2
lifebar_levelmode	life_miryoku,false

mikan_miryoku	=	50			#みかん魅力
mikan_miryoku_max=	9999			#みかん魅力(最大値)
ichigo_miryoku	=	50			#みかん魅力
ichigo_miryoku_max=	9999			#みかん魅力(最大値)
karin_miryoku	=	50			#みかん魅力
karin_miryoku_max=	9999			#みかん魅力(最大値)

mikan_money_hosei=	1
ichigo_money_hosei=	1
karin_money_hosei=	1


#からだ #######################################################################
life_karada	=	3
lifebar_load		life_karada,"system\lifebar\status_karada.png"
lifebar_position	life_karada,510,360+44*2

#みかん
mikan_karada	=	48			#みかんからだ
mikan_karada_max=	80			#みかんからだ(最大値)
mikan_karada_level=	1
mikan_karada_hosei=	0.8
mikan_karada_old=	mikan_karada

#かりん
karin_karada	=	48			#みかんからだ
karin_karada_max=	100			#みかんからだ(最大値)
karin_karada_level=	1
karin_karada_hosei=	1
karin_karada_old=	karin_karada

#いちご
ichigo_karada	=	80			#みかんからだ
ichigo_karada_max=	120			#みかんからだ(最大値)
ichigo_karada_level=	1
ichigo_karada_hosei=	1.2
ichigo_karada_old=	ichigo_karada


#こころ ######################################################################
life_kokoro	=	4
lifebar_load		life_kokoro,"system\lifebar\status_kokoro.png"
lifebar_position	life_kokoro,510,360+44*3

#みかん
mikan_kokoro	=	32			#みかんこころ
mikan_kokoro_max=	120			#みかんこころ(最大値)
mikan_kokoro_level=	1
mikan_kokoro_hosei=	1.2
mikan_kokoro_old=	mikan_kokoro

#かりん
karin_kokoro	=	32			#みかんこころ
karin_kokoro_max=	80			#みかんこころ(最大値)
karin_kokoro_level=	1
karin_kokoro_hosei=	1
karin_kokoro_old=	karin_kokoro

#いちご
ichigo_kokoro	=	50			#みかんこころ
ichigo_kokoro_max=	100			#みかんこころ(最大値)
ichigo_kokoro_level=	1
ichigo_kokoro_hosei=	1
ichigo_kokoro_old=	ichigo_kokoro

#あたま ######################################################################
life_atama	=	5
lifebar_load		life_atama,"system\lifebar\status_atama.png"
lifebar_position	life_atama,510,360+44*4

#みかん
mikan_atama	=	25			#みかんあたま
mikan_atama_max	=	100			#みかんあたま(最大値)
mikan_atama_level=	1
mikan_atama_hosei=	1
mikan_atama_old	=	mikan_atama

#かりん
karin_atama	=	80			#みかんあたま
karin_atama_max	=	120			#みかんあたま(最大値)
karin_atama_level=	1
karin_atama_hosei=	1.2
karin_atama_old	=	karin_atama

#いちご
ichigo_atama	=	20			#みかんあたま
ichigo_atama_max=	80			#みかんあたま(最大値)
ichigo_atama_level=	1
ichigo_atama_hosei=	0.8
ichigo_atama_old=	ichigo_atama



#体力(調教)
life_tairyoku	=	6
tairyoku	=	128			#体力
tairyoku_max	=	128			#体力(最大値)
lifebar_load		life_tairyoku,"system\lifebar\tyoukyou_tairyoku.png"
lifebar_position	life_tairyoku,510,4
lifebar_levelmode	life_tairyoku,false
lifebar_soundmode	life_tairyoku,false

#精神力(調教)
life_seishin	=	7
seishin		=	128			#精神力
seishin_max	=	128			#精神力(最大値)
lifebar_load		life_seishin,"system\lifebar\tyoukyou_seishin.png"
lifebar_position	life_seishin,220,4
lifebar_levelmode	life_seishin,false
lifebar_soundmode	life_seishin,false

life_trpg_itsuki=	10
life_trpg_mikan	=	11
life_trpg_karin	=	12
life_trpg_ichigo=	13



#コマンドレベル
mikan_study_level=	1
mikan_work_level=	1
mikan_reception_level=	1
mikan_rest_level=	1
mikan_special_level=	1

ichigo_study_level=	1
ichigo_work_level=	1
ichigo_reception_level=	1
ichigo_rest_level=	1
ichigo_special_level=	1

karin_study_level=	1
karin_work_level=	1
karin_reception_level=	1
karin_rest_level=	1
karin_special_level=	1




#ゆず好感度
yuzu_love=0



#バイトのパラメータ---------------------------------------------------------
#メイド喫茶
mikan_work1_price=5000		#時給
ichigo_work1_price=5000		#時給
karin_work1_price=5000		#時給

#きぐるみ
mikan_work2_price=10000		#時給
ichigo_work2_price=10000	#時給
karin_work2_price=10000		#時給

#メイド喫茶(ハード)
mikan_work3_price=20000		#時給
ichigo_work3_price=20000	#時給
karin_work3_price=20000		#時給

#きぐるみ(ハード)
mikan_work4_price=60000		#時給
ichigo_work4_price=60000	#時給
karin_work4_price=60000		#時給


#勤務回数
mikan_work1=		0		#メイド喫茶
mikan_work1_max	=	10
mikan_work2=		0		#着ぐるみ
mikan_work2_max	=	10
mikan_work3=		0		#メイド喫茶(ハード)
mikan_work3_max	=	10
mikan_work4=		0		#着ぐるみ(ハード)
mikan_work4_max	=	10
ichigo_work1=		0		#メイド喫茶
ichigo_work1_max=	10
ichigo_work2=		0		#着ぐるみ
ichigo_work2_max=	10
ichigo_work3=		0		#メイド喫茶(ハード)
ichigo_work3_max=	10
ichigo_work4=		0		#着ぐるみ(ハード)
ichigo_work4_max=	10
karin_work1=		0		#メイド喫茶
karin_work1_max=	10
karin_work2=		0		#着ぐるみ
karin_work2_max=	10
karin_work3=		0		#メイド喫茶(ハード)
karin_work3_max=	10
karin_work4=		0		#着ぐるみ(ハード)
karin_work4_max=	10




#日付(デフォルト)
date_set	2007,1,7

money_set	3000,0
#money_set	30000000,0	#デバッグ用

#体験版用
#item_soldout	200,_TRUE
#item_soldout	202,_TRUE
#item_soldout	203,_TRUE
#item_soldout	204,_TRUE
#item_soldout	205,_TRUE
#item_soldout	206,_TRUE
#item_soldout	207,_TRUE
#item_soldout	208,_TRUE
#item_soldout	210,_TRUE
#item_soldout	211,_TRUE

#item_soldout	303,_TRUE
#item_soldout	304,_TRUE
#item_soldout	305,_TRUE
#item_soldout	306,_TRUE

#item_soldout	400,_TRUE
#item_soldout	401,_TRUE

#ここまで

item_soldout	500,_TRUE			#パソコン
item_soldout	501,_TRUE			#貞操帯
item_soldout	502,_TRUE			#ペニスバンド
item_soldout	503,_TRUE			#三角木馬
#item_soldout	504,_TRUE			#絆創膏

replace_set	"＠巣蓋さん","＠店員さん"

hensai_gaku=10000000



#ichigo_karada=1000
#ichigo_karada_max=1000

@initial_set

#パラメーター設定(これはリアルタイムに反映される)
macro	initial_set
#勉強のパラメータ-------------------------------------------------------------
#優しい
study1_kenkou=-2
study1_kiryoku=-4
study1_atama=8
study1_karada=-1
#普通
study2_kenkou=-6
study2_kiryoku=-8
study2_atama=24
study2_karada=-2
#難しい
study3_kenkou=-8
study3_kiryoku=-12
study3_atama=42
study3_karada=-4
#スパルタ
study4_kenkou=-10
study4_kiryoku=-24
study4_atama=84
study4_karada=-8

#バイトのパラメータ---------------------------------------------------------
#メイド喫茶
work1_kenkou=-8
work1_kiryoku=-2
work1_atama=-1
work1_karada=8

#きぐるみ
work2_kenkou=-24
work2_kiryoku=-4
work2_atama=-2
work2_karada=24

#メイド喫茶(ハード)
work3_kenkou=-36
work3_kiryoku=-8
work3_atama=-4
work3_karada=48

#きぐるみ(ハード)
work4_kenkou=-72
work4_kiryoku=-16
work4_atama=-8
work4_karada=84

#せったいのパラメータ--------------------------------------------------------
#せったい
reception1_kenkou=-6
reception1_kiryoku=-18
reception1_price=30000		#報酬

#奉仕
reception2_kenkou=-18
reception2_kiryoku=-36
reception2_price=50000		#報酬

#売春
reception3_kenkou=-36
reception3_kiryoku=-68
reception3_price=90000		#報酬

#SM
reception4_kenkou=-64
reception4_kiryoku=-128
reception4_price=150000		#報酬

#レッスンのパラメータ----------------------------------------------------------
#習字
lesson1_kenkou=-6
lesson1_kiryoku=-2
lesson1_kokoro=8
lesson1_karada=2
lesson1_price=-5000

#バレエ
lesson2_kenkou=-8
lesson2_kiryoku=-4
lesson2_kokoro=24
lesson2_karada=8
lesson2_price=-8000

#習字(ハード)
lesson3_kenkou=-16
lesson3_kiryoku=-5
lesson3_kokoro=42
lesson3_karada=16
lesson3_price=-20000

#バレエ(ハード)
lesson4_kenkou=-32
lesson4_kiryoku=-8
lesson4_kokoro=84
lesson4_karada=32
lesson4_price=-50000

#チェックポイント------------------------------------------------------------
#チェックポイント1　魅力
checkpoint1_miryoku=		777	#七夕		7
checkpoint2_miryoku=		580	#プール?	8
checkpoint3_miryoku=		1000	#デート		9(ルート)

#checkpoint_mikan	=	900	#みかんTRUEに必要な魅力(みんな輪姦回避)
checkpoint_ichigo1	=	650	#いちごプールHに必要な魅力	8


checkpoint_ichigo2	=	200	#いちご発作1はこれ以下		5
checkpoint_ichigo3	=	230	#いちご発作2はこれ以下		6

checkpoint_hikari	=	1000 	#これ以下でひかりルート		9

check_oosama		=	250			#6/3
check_nomi		=	280			#6/10
check_chichinohi	=	350			#6/17


endm

