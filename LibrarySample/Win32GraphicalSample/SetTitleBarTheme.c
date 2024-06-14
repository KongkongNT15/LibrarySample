#include "pch.h"

HRESULT SetTitleBarTheme(HWND hwnd, BOOL isLightTheme)
{
    BOOL isDark = isLightTheme == FALSE;
    return DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &isDark, sizeof(isDark));
}