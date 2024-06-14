#include "pch.h"

int Kongkong::RunSample(const char* rootTag, const char* sampleTag)
{
	if (IsEqualStringA(rootTag, "fileapi.h")) return Fileapi::RunSample(sampleTag);
	if (IsEqualStringA(rootTag, "WinUser.h")) return Winuser::RunSample(sampleTag);

	return RunNotFound(rootTag);
}