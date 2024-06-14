#include "pch.h"

LRESULT CALLBACK DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static BOOL isLightMode = FALSE;
    switch (uMsg) {
        //ägëÂó¶ÇÃïœçX
    case WM_DPICHANGED:

        break;

    case WM_SETTINGCHANGE:
        BOOL value = IsLightTheme();

        if (value == isLightMode) break;

        SetTitleBarTheme(hwnd, value);
        isLightMode = value;

        break;

    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_3DFACE + 1));

        EndPaint(hwnd, &ps);

        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}