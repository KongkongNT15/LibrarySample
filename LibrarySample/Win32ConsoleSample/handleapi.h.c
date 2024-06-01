#include "pch.h"

static int macro(void)
{
	PutMacro(INVALID_HANDLE_VALUE, "不正なハンドル");

	return 0;
}

int RunHandleapiSample(const char* tag)
{
	if (IsEqualStringA(tag, TAG_MACRO)) return macro();

	return NotFound(tag);
}