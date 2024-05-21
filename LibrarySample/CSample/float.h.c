#include "pch.h"

static int macro(void)
{
	PutMacro(DBL_DECIMAL_DIG, "double�̊ۂ߉\�ȍő包��");
	PutMacro(DBL_DIG, "double�̗L������");
	PutMacro(DBL_EPSILON, "double�̌v�Z�@�C�v�V����");
	PutMacro(DBL_HAS_SUBNORM, "double���񐳋K������\���邩�������l");
	PutMacro(DBL_MANT_DIG, "double�̉������̃r�b�g��");
	PutMacro(DBL_MAX, "double�̍ő�l");
	PutMacro(DBL_MAX_10_EXP, "double��10�i���ł̎w�������̍ő�l");
	PutMacro(DBL_MAX_EXP, "double��2�i���ł̎w�������̍ő�l");
	PutMacro(DBL_MIN, "double�̍ŏ��l");
	PutMacro(DBL_MIN_10_EXP, "double��10�i���ł̎w�������̍ŏ��l");
	PutMacro(DBL_MIN_EXP, "double��2�i���ł̎w�������̍ŏ��l");
	PutMacro(DBL_TRUE_MIN, "double�̃[�����傫���ŏ��̒l");

	PutMacro(FLT_DECIMAL_DIG, "float�̊ۂ߉\�ȍő包��");
	PutMacro(FLT_DIG, "float�̗L������");
	PutMacro(FLT_EPSILON, "float�̌v�Z�@�C�v�V����");
	PutMacro(FLT_HAS_SUBNORM, "float���񐳋K������\���邩�������l");
	PutMacro(FLT_MANT_DIG, "float�̉������̃r�b�g��");
	PutMacro(FLT_MAX, "float�̍ő�l");
	PutMacro(FLT_MAX_10_EXP, "float��10�i���ł̎w�������̍ő�l");
	PutMacro(FLT_MAX_EXP, "float��2�i���ł̎w�������̍ő�l");
	PutMacro(FLT_MIN, "float�̍ŏ��l");
	PutMacro(FLT_MIN_10_EXP, "float��10�i���ł̎w�������̍ŏ��l");
	PutMacro(FLT_MIN_EXP, "float��2�i���ł̎w�������̍ŏ��l");
	PutMacro(FLT_TRUE_MIN, "float�̃[�����傫���ŏ��̒l");

	PutMacro(LDBL_DECIMAL_DIG, "long double�̊ۂ߉\�ȍő包��");
	PutMacro(LDBL_DIG, "long double�̗L������");
	PutMacro(LDBL_EPSILON, "long double�̌v�Z�@�C�v�V����");
	PutMacro(LDBL_HAS_SUBNORM, "long double���񐳋K������\���邩�������l");
	PutMacro(LDBL_MANT_DIG, "long double�̉������̃r�b�g��");
	PutMacro(LDBL_MAX, "long double�̍ő�l");
	PutMacro(LDBL_MAX_10_EXP, "long double��10�i���ł̎w�������̍ő�l");
	PutMacro(LDBL_MAX_EXP, "long double��2�i���ł̎w�������̍ő�l");
	PutMacro(LDBL_MIN, "long double�̍ŏ��l");
	PutMacro(LDBL_MIN_10_EXP, "long double��10�i���ł̎w�������̍ŏ��l");
	PutMacro(LDBL_MIN_EXP, "long double��2�i���ł̎w�������̍ŏ��l");
	PutMacro(LDBL_TRUE_MIN, "long double�̃[�����傫���ŏ��̒l");

	PutMacro(DECIMAL_DIG, "���������_���^�̊ۂ߉\�ȍő包��");

	return 0;
}

int float__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

	return NotFound(FUNCNAMEVALUE);
}