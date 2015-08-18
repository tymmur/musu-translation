## �݂��񗧂��ݒ� #############################################################
chara_folder	l_mikan,"chara"
chara_name	l_mikan,"�݂���"
@mikan_small
@mikan_shifuku

## ���� #######################################################################
macro	mikan_
	chara_off	l_mikan
endmacro

## ���� #######################################################################
# ����
macro	mikan_small
	layer_release	l_mikan
	chara_size	l_mikan,"��",0,98
endm

# ����
macro	mikan_middle
	layer_release	l_mikan
	chara_size	l_mikan,"��",0,0
endm

# �߂�
macro	mikan_large
	layer_release	l_mikan
	chara_size	l_mikan,"��",0,0
endm

## ���� ######################################################################
macro	mikan_shifuku
	chara_clothes	l_mikan,"����"
endm
macro	mikan_seifuku
	chara_clothes	l_mikan,"�~��"
	if _MONTH>6 and _MONTH<10 then chara_clothes	l_mikan,"�ĕ�"
endm
macro	mikan_pajama
	chara_clothes	l_mikan,"�p�W���}"
endm
macro	mikan_bondage
	chara_clothes	l_mikan,"�{���f�[�W"
endm
macro	mikan_hadaka
	chara_clothes	l_mikan,"��"
endm
macro	mikan_yukata
	chara_clothes	l_mikan,"����"
endm
macro	mikan_mizugi
	chara_clothes	l_mikan,"����"
endm

## �\�� ######################################################################

#- ���� ----------------------------------------------------------------------
macro	mikan
	chara_auto	l_mikan,"����.png"
endm
#- ����(�~��) ----------------------------------------------------------------
macro	mikan2
	chara_auto	l_mikan,"�~��_����.png"
endm
#- �� ------------------------------------------------------------------------
macro	mikan_yorokobi
	chara_auto	l_mikan,"��.png"
endm
#- ��(�~��) ------------------------------------------------------------------
macro	mikan_yorokobi2
	chara_auto	l_mikan,"�~��_��.png"
endm
#- �Ă� ------------------------------------------------------------------
macro	mikan_tere
	chara_auto	l_mikan,"�~��_��.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	mikan_ikari
	chara_auto	l_mikan,"�{.png"
endm
#- �^���{�� ------------------------------------------------------------------
macro	mikan_shinkenikari
	chara_auto	l_mikan,"�^���{��.png"
endm
#- �΂� ----------------------------------------------------------------------
macro	mikan_warai
	chara_auto	l_mikan,"��.png"
endm
#- �΂�2 ---------------------------------------------------------------------
macro	mikan_warai2
	chara_auto	l_mikan,"��2.png"
endm
#- ��� ---------------------------------------------------------------------
macro	mikan_kusyou
	chara_auto	l_mikan,"���.png"
endm
macro	mikan_komaru
	chara_auto	l_mikan,"���.png"
endm
#- �� ------------------------------------------------------------------------
macro	mikan_odoroki
	chara_auto	l_mikan,"��.png"
	layer_movepass_add	l_mikan,0,	100,	0,32
	layer_movepass_add	l_mikan,0,	100,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
#- �� ------------------------------------------------------------------------
macro	mikan_naki
	chara_auto	l_mikan,"��.png"
endm
#- �� ------------------------------------------------------------------------
macro	mikan_kanashimi
	chara_auto	l_mikan,"��.png"
endm
#- ���S ----------------------------------------------------------------------
macro	mikan_houshin
	chara_auto	l_mikan,"���S.png"
endm
#- �R�~�J���{�� --------------------------------------------------------------
macro	mikan_komikaru_ikari
	chara_auto	l_mikan,"�R�~�J���{.png"
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_add	l_mikan,0,	150,	0,16
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_add	l_mikan,0,	150,	0,16
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
macro	mikan_ikari_c
	@mikan_komikaru_ikari
endm

#- �R�~�J���΂� --------------------------------------------------------------
macro	mikan_komikaru_warai
	chara_auto	l_mikan,"�R�~�J����.png"
	layer_movepass_add	l_mikan,0,	150,	8,0
	layer_movepass_add	l_mikan,0,	150,	-8,0
	layer_movepass_add	l_mikan,0,	150,	8,0
	layer_movepass_add	l_mikan,0,	150,	-8,0
	layer_movepass_add	l_mikan,0,	150,	0,0
	layer_movepass_type	l_mikan,0,	PASSTYPE_LINEAR
	layer_movepass_play	l_mikan,0,play_once
endm
#- �R�~�J�������� ------------------------------------------------------------
macro	mikan_komikaru_kanashimi
	chara_auto	l_mikan,"�R�~�J����.png"
endm
macro	mikan_kanashimi_c
	chara_auto	l_mikan,"�R�~�J����.png"
endm


macro	mikan_yokujyou2
	chara_auto	l_mikan,"�~��_��.png"
endm
macro	mikan_yokujyou
	chara_auto	l_mikan,"�~��_����.png"
endm