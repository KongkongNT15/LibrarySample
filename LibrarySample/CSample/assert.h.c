#include "pch.h"

static int macro(void)
{
	puts("static_assert");
	puts(Macro(static_assert));
	puts("コンパイル時診断");

	return 0;
}

int assert__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
	return NotFound(FUNCNAMEVALUE);
}