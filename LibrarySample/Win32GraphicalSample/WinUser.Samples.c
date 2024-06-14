#include "pch.h"
#include "WinUser.GetWinUserProcedure.h"
#include "WinUser.Samples.h"

WindowProcedure GetWinUserProcedure(const wchar_t* tag)
{
	if (IsEqualStringW(tag, L"CloseWindow")) return CloseWindowProc;
	if (IsEqualStringW(tag, L"GetWindowRect")) return GetWindowRectProc;
	if (IsEqualStringW(tag, L"IsZoomed")) return IsZoomedProc;
	if (IsEqualStringW(tag, L"MessageBeep")) return MessageBeepProc;
	if (IsEqualStringW(tag, L"MessageBoxW")) return MessageBoxWProc;

	return NotFound(tag);
}