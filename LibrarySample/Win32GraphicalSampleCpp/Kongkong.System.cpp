#include "pch.h"

namespace Kongkong
{
	bool System::IsLightTheme()
	{
		return GetRegistoryDoubleWordW(
			HKEY_CURRENT_USER,
			L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
			L"AppsUseLightTheme") == TRUE;
	}
}