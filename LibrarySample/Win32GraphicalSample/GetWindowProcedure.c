#include "pch.h"
#include "AllSamples.h"

WindowProcedure GetWindowProcedure(const wchar_t* headerTag, const wchar_t* sampleTag)
{
    if (IsEqualStringW(headerTag, L"WinUser.h")) return GetWinUserProcedure(sampleTag);

    return NotFound(headerTag);
}