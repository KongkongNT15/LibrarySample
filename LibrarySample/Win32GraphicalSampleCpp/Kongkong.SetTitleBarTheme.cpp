#include "pch.h"

void Kongkong::SetTitleBarTheme(HWND hwnd, bool isLight)
{
	BOOL isDark = (BOOL)!isLight;
	if (DwmSetWindowAttribute(hwnd, DWMWINDOWATTRIBUTE::DWMWA_USE_IMMERSIVE_DARK_MODE, &isDark, sizeof(isDark)) != S_OK) [[unlikely]] throw Exception(L"タイトルバーのテーマを設定できませんでした");
}