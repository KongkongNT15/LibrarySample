#include "pch.h"

static int macro(void)
{
	puts("static_assert");
	puts(Macro(static_assert));
	puts("ƒRƒ“ƒpƒCƒ‹f’f");

	return 0;
}

int assert__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
	return NotFound(FUNCNAMEVALUE);
}