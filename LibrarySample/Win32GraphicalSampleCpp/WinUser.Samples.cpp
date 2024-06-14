#include "pch.h"
#include "WinUser.GetProcedure.h"
#include "WinUser.Samples.h"

namespace Kongkong::WinUser
{
	WindowProcedure GetProcedure(std::wstring_view const& tag)
	{
		if (tag == L"CloseWindow") return CloseWindowProc;
		if (tag == L"GetWindowRect") return GetWindowRectProc;
		if (tag == L"IsZoomed") return IsZoomedProc;
		if (tag == L"MessageBeep") return MessageBeepProc;
		if (tag == L"MessageBoxW") return MessageBoxWProc;

		return SampleManager::NotFound(tag);
	}
}
