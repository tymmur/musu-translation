## �Ђ���ݒ� #################################################################
chara_folder	l_hikari,"chara"
chara_name	l_hikari,"�Ђ���"
@hikari_small
@hikari_shifuku

## ���� #######################################################################
macro	hikari_
	chara_off	l_hikari
	layer_release	l_hikari+1
endmacro
macro	hikari2_
	chara_off	l_hikari
	layer_release	l_hikari+1
endmacro

## ���� #######################################################################
# ����
macro	hikari_small
	chara_size	l_hikari,"��",0,130
	hikari_size=0
endm

# ����
macro	hikari_middle
	chara_size	l_hikari,"��",0,99
	hikari_size=1
endm

# �߂�
macro	hikari_large
	chara_size	l_hikari,"��",0,93
	hikari_size=2
endm

## ���� ######################################################################
macro	hikari_shifuku
	chara_clothes	l_hikari,"����"
endm
macro	hikari_pajama
	chara_clothes	l_hikari,"�p�W���}"
endm
macro	hikari_shitagi
	chara_clothes	l_hikari,"����"
endm
macro	hikari_mizugi
	chara_clothes	l_hikari,"����"
endm
macro	hikari_hadaka
	chara_clothes	l_hikari,"��"
endm

## �\�� ######################################################################

#- ���� ----------------------------------------------------------------------
macro	hikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	hikari_ikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"�{.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	hikari_ikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"�{2.png"
endm
#- �΂� ----------------------------------------------------------------------
macro	hikari_warai
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- �Ƃ� ----------------------------------------------------------------------
macro	hikari_tere
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari_odoroki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ������ --------------------------------------------------------------------
macro	hikari_kanashimi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- �ɂ� ----------------------------------------------------------------------
macro	hikari_yorokobi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari_naki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari_komaru
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm

macro	hikari_gimon
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm


#- ���� ----------------------------------------------------------------------
macro	hikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	hikari2_ikari
	layer_release	l_hikari+1
	chara_auto	l_hikari,"�{2.png"
endm
#- �{�� ----------------------------------------------------------------------
macro	hikari2_ikari2
	layer_release	l_hikari+1
	chara_auto	l_hikari,"�{.png"
endm
#- �΂� ----------------------------------------------------------------------
macro	hikari2_warai
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
	if hikari2_size=0 then chara	l_hikari+1,"chara\�}�[�N\�Ă�Ă�}�[�N_��.png"
	if hikari2_size=1 then chara	l_hikari+1,"chara\�}�[�N\�Ă�Ă�}�[�N_��.png"
	if hikari2_size=2 then chara	l_hikari+1,"chara\�}�[�N\�Ă�Ă�}�[�N.png"
	layer_reference_set	l_hikari+1,l_hikari
	if hikari_size=0 then layer_position		l_hikari+1,250,60
	if hikari_size=1 then layer_position		l_hikari+1,350,60
	if hikari_size=2 then layer_position		l_hikari+1,400,40
	layer_scalepass_add 	l_hikari+1,0,	500,30,30
	layer_scalepass_add 	l_hikari+1,0,	500,0,0
	layer_scalepass_play	l_hikari+1,0,	PLAY_LOOP

endm
#- �Ƃ� ----------------------------------------------------------------------
macro	hikari2_tere
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari2_odoroki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ������ --------------------------------------------------------------------
macro	hikari2_kanashimi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- �ɂ� ----------------------------------------------------------------------
macro	hikari2_yorokobi
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari2_naki
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm
#- ���� ----------------------------------------------------------------------
macro	hikari2_komaru
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
endm

macro	hikari2_gimon
	layer_release	l_hikari+1
	chara_auto	l_hikari,"��.png"
	if hikari_size=0 then chara	l_hikari+1,"chara\�}�[�N\�͂Ăȃ}�[�N.png"

	layer_reference_set	l_hikari+1,l_hikari
	layer_position		l_hikari+1,80,40
	layer_movepass_add	l_hikari+1,0,0,0,0
	layer_movepass_add	l_hikari+1,0,2000,-32,-32
	layer_movepass_play	l_hikari+1,0,play_once
	layer_alpha		l_hikari+1,2000,-255,0,passtype_tcb
endm