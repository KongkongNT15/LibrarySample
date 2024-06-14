#include "pch.h"

BOOL IsLightTheme()
{
    DWORD value;
    GetRegistoryDoubleWordW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"AppsUseLightTheme",
        &value);

    return value;
}