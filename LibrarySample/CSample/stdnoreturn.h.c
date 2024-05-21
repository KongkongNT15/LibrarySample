#include "pch.h"

static int macro(void)
{
	PutMacro(noreturn, "noreturn‘®«");
	return 0;
}

int stdnoreturn__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

	return NotFound(FUNCNAMEVALUE);
}