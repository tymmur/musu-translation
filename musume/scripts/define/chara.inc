
## ���C���[�ݒ� ###############################################################
l_trpg_monster	=	52	#�����X�^�[(TRPG)
l_trpg_karin	=	50	#�����(TRPG)
l_trpg_mikan	=	48	#�݂���(TRPG)
l_trpg_itsuki	=	46	#��(TRPG)
l_trpg_ichigo	=	44	#������(TRPG)

l_yakou		=	42	#��s
l_ren		=	40	#�@
l_kurofuku	=	38	#����
l_hikari	=	36	#�Ђ���
l_houkou	=	34	#���
l_seiji		=	32	#���i
l_suzumi	=	30	#���C
l_rua		=	28	#�邠
l_yuzu		=	26	#�䂸
l_subuta	=	24	#���W
l_ichigo	=	22	#������
l_karin		=	18	#�����
l_mikan		=	20	#�݂���
l_zakuro	=	16	#������
l_suika		=	14	#������
l_miu		=	12	#���J
l_shizuku	=	10	#��

## �L�����̏����� #############################################################
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

## �S�L�������� ###############################################################
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



## ���ׂẴL�������N���A ####################################################
macro	clear_charaall
	@shizuku_
	@zakuro_
	@mikan_
endm













#MACRO ichigo
#	ichigoX=160
#	ichigoY=74
#	ichigoLayer=10
#�������ʏ�
#	chara ichigoLayer,"chara\��������\������_����_�x�[�X.png"
#	layer_anime_mepachi ichigoLayer,"chara\��������\������_����_���ʖ�.png","chara\��������\������_����_���ʔ���.png","chara\��������\������_����_���ʕ�.png"
#	layer_parts_load ichigoLayer,						#		0,"chara\��������\������_����_���ʌ�.png"
#	layer_parts_load ichigoLayer,						#		1,"chara\��������\������_����_��_����_�G�o1.png"

#	layer_position ichigoLayer,ichigoX,ichigoY
#ENDMACRO