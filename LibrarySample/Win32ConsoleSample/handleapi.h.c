#include "pch.h"
#include "../Macros/handleapi.macro.h"

int RunHandleapiSample(const char* tag)
{
	if (IsEqualStringA(tag, TAG_MACRO)) return macro();

	return RunNotFound(tag);
}