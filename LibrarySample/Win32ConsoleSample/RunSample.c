#include "pch.h"

int RunSample(const char* headerTag, const char* sampleTag)
{
    if (IsEqualStringA(headerTag, "fileapi.h")) return RunFileapiSample(sampleTag);
    if (IsEqualStringA(headerTag, "handleapi.h")) return RunHandleapiSample(sampleTag);
    if (IsEqualStringA(headerTag, "WinUser.h")) return RunWinuserSample(sampleTag);

    return RunNotFound(headerTag);
}