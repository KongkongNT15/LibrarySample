#include "pch.h"

WindowProcedure GetWinUserProcedure(const wchar_t* tag)
{
	if (IsEqualStringW(tag, L"MessageBox")) return MessageBoxProc;

	return NotFound(tag);
}