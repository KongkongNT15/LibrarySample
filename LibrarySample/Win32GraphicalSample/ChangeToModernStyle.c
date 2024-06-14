#include "pch.h"

BOOL CALLBACK ChangeToModernStyle(HWND hwnd, LPARAM lParam)
{
    SendMessage(hwnd, WM_SETFONT, (WPARAM)Font, MAKELPARAM(TRUE, 0));

    double kakudairitu = GetDpiForWindow(hwnd) / 96.0;
    RECT rect, rectParent;
    GetWindowRect(hwnd, &rect);

    if (lParam == MAKELPARAM(TRUE, 0)) {
        GetWindowRect(GetParent(hwnd), &rectParent);
    }
    else {
        POINT point = { 0 };
        ClientToScreen(GetParent(hwnd), &point);

        rectParent.left = point.x;
        rectParent.top = point.y;
    }

    SetWindowPos(hwnd, NULL, (int)((rect.left - rectParent.left) * kakudairitu), (int)((rect.top - rectParent.top) * kakudairitu), (int)((rect.right - rect.left) * kakudairitu), (int)((rect.bottom - rect.top) * kakudairitu), SWP_NOZORDER);

    EnumChildWindows(hwnd, ChangeToModernStyle, MAKELPARAM(TRUE, 0));

    return TRUE;
}