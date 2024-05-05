#include "pch.h"

static int macro(void)
{
	puts("and");
	puts(Macro(and));
	puts("論理AND演算子の代替つづり");

	puts("and_eq");
	puts(Macro(and_eq));
	puts("ビット積の代入演算子の代替つづり");

	puts("bitand");
	puts(Macro(bitand));
	puts("ビット積を表す演算子の代替つづり");

	puts("bitor");
	puts(Macro(bitor));
	puts("ビット和を表す演算子の代替つづり");

	puts("compl");
	puts(Macro(compl));
	puts("ビット反転演算子の代替つづり");

	puts("not");
	puts(Macro(not));
	puts("否定を表す演算子の代替つづり");

	puts("not_eq");
	puts(Macro(not_eq));
	puts("不等号の代替つづり");

	puts("or");
	puts(Macro(or));
	puts("論理OR演算子の代替つづり");

	puts("or_eq");
	puts(Macro(or_eq));
	puts("ビット和の代入演算子の代替つづり");

	puts("xor");
	puts(Macro(xor));
	puts("ビット差を表す演算子の代替つづり");

	puts("xor_eq");
	puts(Macro(xor_eq));
	puts("ビット和の代入演算子の代替つづり");

	return 0;
}

int iso646__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
	return NotFound(FUNCNAMEVALUE);
}