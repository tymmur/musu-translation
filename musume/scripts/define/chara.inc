
## レイヤー設定 ###############################################################
l_trpg_monster	=	52	#モンスター(TRPG)
l_trpg_karin	=	50	#かりん(TRPG)
l_trpg_mikan	=	48	#みかん(TRPG)
l_trpg_itsuki	=	46	#樹(TRPG)
l_trpg_ichigo	=	44	#いちご(TRPG)

l_yakou		=	42	#夜行
l_ren		=	40	#蓮
l_kurofuku	=	38	#黒服
l_hikari	=	36	#ひかり
l_houkou	=	34	#宝交
l_seiji		=	32	#誠司
l_suzumi	=	30	#涼海
l_rua		=	28	#るあ
l_yuzu		=	26	#ゆず
l_subuta	=	24	#巣蓋
l_ichigo	=	22	#いちご
l_karin		=	18	#かりん
l_mikan		=	20	#みかん
l_zakuro	=	16	#ざくろ
l_suika		=	14	#すいか
l_miu		=	12	#美雨
l_shizuku	=	10	#雫

## キャラの初期化 #############################################################
macro	chara_init
@ichigo_small
@ichigo_shifuku
@karin_small
@karin_shifuku
@mikan_small
@mikan_shifuku
@miu_small
@miu_maid
@suika_small
@suika_shifuku
@zakuro_small
@zakuro_shifuku
@shizuku_small
@shizuku_shifuku
@suzumi_small
@suzumi_shifuku
@rua_small
@rua_shifuku
@kurofuku_small
@kurofuku_shifuku
@yuzu_small
@yuzu_jyosou
@ren_small
@ren_shifuku
@hikari_small
@hikari_shifuku
endm

## 全キャラ消去 ###############################################################
macro	chara_clear
@mikan_
@ichigo_
@karin_
@zakuro_
@suika_
@miu_
@shizuku_
@suzumi_
@rua_
@seiji_
@houkou_
@yuzu_
@kurofuku_
@ren_
@hikari_
@yakou_
@trpg_itsuki_
@trpg_mikan_
@trpg_karin_
@trpg_ichigo_
layer_fadeout	l_trpg_monster
endm



## すべてのキャラをクリア ####################################################
macro	clear_charaall
	@shizuku_
	@zakuro_
	@mikan_
endm













#MACRO ichigo
#	ichigoX=160
#	ichigoY=74
#	ichigoLayer=10
#いちご通常
#	chara ichigoLayer,"chara\いちご小\いちご_私服_ベース.png"
#	layer_anime_mepachi ichigoLayer,"chara\いちご小\いちご_私服_普通目.png","chara\いちご小\いちご_私服_普通半目.png","chara\いちご小\いちご_私服_普通閉じ.png"
#	layer_parts_load ichigoLayer,						#		0,"chara\いちご小\いちご_私服_普通口.png"
#	layer_parts_load ichigoLayer,						#		1,"chara\いちご小\いちご_私服_小_普通_触覚1.png"

#	layer_position ichigoLayer,ichigoX,ichigoY
#ENDMACRO
