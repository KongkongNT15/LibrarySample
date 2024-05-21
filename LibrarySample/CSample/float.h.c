#include "pch.h"

static int macro(void)
{
	PutMacro(DBL_DECIMAL_DIG, "doubleの丸め可能な最大桁数");
	PutMacro(DBL_DIG, "doubleの有効桁数");
	PutMacro(DBL_EPSILON, "doubleの計算機イプシロン");
	PutMacro(DBL_HAS_SUBNORM, "doubleが非正規化数を表せるかを示す値");
	PutMacro(DBL_MANT_DIG, "doubleの仮数部のビット数");
	PutMacro(DBL_MAX, "doubleの最大値");
	PutMacro(DBL_MAX_10_EXP, "doubleの10進数での指数部分の最大値");
	PutMacro(DBL_MAX_EXP, "doubleの2進数での指数部分の最大値");
	PutMacro(DBL_MIN, "doubleの最小値");
	PutMacro(DBL_MIN_10_EXP, "doubleの10進数での指数部分の最小値");
	PutMacro(DBL_MIN_EXP, "doubleの2進数での指数部分の最小値");
	PutMacro(DBL_TRUE_MIN, "doubleのゼロより大きい最小の値");

	PutMacro(FLT_DECIMAL_DIG, "floatの丸め可能な最大桁数");
	PutMacro(FLT_DIG, "floatの有効桁数");
	PutMacro(FLT_EPSILON, "floatの計算機イプシロン");
	PutMacro(FLT_HAS_SUBNORM, "floatが非正規化数を表せるかを示す値");
	PutMacro(FLT_MANT_DIG, "floatの仮数部のビット数");
	PutMacro(FLT_MAX, "floatの最大値");
	PutMacro(FLT_MAX_10_EXP, "floatの10進数での指数部分の最大値");
	PutMacro(FLT_MAX_EXP, "floatの2進数での指数部分の最大値");
	PutMacro(FLT_MIN, "floatの最小値");
	PutMacro(FLT_MIN_10_EXP, "floatの10進数での指数部分の最小値");
	PutMacro(FLT_MIN_EXP, "floatの2進数での指数部分の最小値");
	PutMacro(FLT_TRUE_MIN, "floatのゼロより大きい最小の値");

	PutMacro(LDBL_DECIMAL_DIG, "long doubleの丸め可能な最大桁数");
	PutMacro(LDBL_DIG, "long doubleの有効桁数");
	PutMacro(LDBL_EPSILON, "long doubleの計算機イプシロン");
	PutMacro(LDBL_HAS_SUBNORM, "long doubleが非正規化数を表せるかを示す値");
	PutMacro(LDBL_MANT_DIG, "long doubleの仮数部のビット数");
	PutMacro(LDBL_MAX, "long doubleの最大値");
	PutMacro(LDBL_MAX_10_EXP, "long doubleの10進数での指数部分の最大値");
	PutMacro(LDBL_MAX_EXP, "long doubleの2進数での指数部分の最大値");
	PutMacro(LDBL_MIN, "long doubleの最小値");
	PutMacro(LDBL_MIN_10_EXP, "long doubleの10進数での指数部分の最小値");
	PutMacro(LDBL_MIN_EXP, "long doubleの2進数での指数部分の最小値");
	PutMacro(LDBL_TRUE_MIN, "long doubleのゼロより大きい最小の値");

	PutMacro(DECIMAL_DIG, "浮動小数点数型の丸め可能な最大桁数");

	return 0;
}

int float__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

	return NotFound(FUNCNAMEVALUE);
}