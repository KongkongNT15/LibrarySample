#include "pch.h"

static int macro(void)
{
	PutMacro(INVALID_HANDLE_VALUE, "•s³‚Èƒnƒ“ƒhƒ‹");

	return 0;
}

int RunHandleapiSample(const char* tag)
{
	if (IsEqualStringA(tag, TAG_MACRO)) return macro();

	return NotFound(tag);
}