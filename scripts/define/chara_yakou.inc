## ��s�����ݒ� #############################################################
chara_folder	l_yakou,"chara"
chara_name	l_yakou,"��s"
@yakou_small
@yakou_shifuku

## ���� #######################################################################
macro	yakou_
	chara_off	l_yakou
endmacro

## ���� #######################################################################
# ����
macro	yakou_small
	chara_size	l_yakou,"��",0,-30
endm

# ����
macro	yakou_middle
	chara_size	l_yakou,"��",0,0
endm

# �߂�
macro	yakou_large
	chara_size	l_yakou,"��",0,0
endm

## ���� ######################################################################
macro	yakou_shifuku
	chara_clothes	l_yakou,"����"
endm

macro	yakou_shifuku_damage
	chara_clothes	l_yakou,"�����o��"
endm


## �\�� ######################################################################

#- ���� ----------------------------------------------------------------------
macro	yakou
	chara_auto	l_yakou,"��.png"
endm
#- �΂� ----------------------------------------------------------------------
macro	yakou_warai
	chara_auto	l_yakou,"��.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	yakou_ikari
	chara_auto	l_yakou,"�{.png"
endm
#- ���� ----------------------------------------------------------------------
macro	yakou_odoroki
	chara_auto	l_yakou,"��.png"
endm
#- ������ --------------------------------------------------------------------
macro	yakou_kanashimi
	chara_auto	l_yakou,"��.png"
endm
#- ��� --------------------------------------------------------------------
macro	yakou_yorokobi
	chara_auto	l_yakou,"��.png"
endm
#- �e --------------------------------------------------------------------
macro	yakou_kage
	chara_auto	l_yakou,"�e.png"
endm
