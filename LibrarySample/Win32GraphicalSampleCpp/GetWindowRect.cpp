#include "pch.h"
#include "WinUser.Samples.h"

#define WCS_LENGTH 100

LRESULT CALLBACK Kongkong::WinUser::GetWindowRectProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hStatic = nullptr;
    wchar_t wcs[WCS_LENGTH];

    RECT rect;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:

        hStatic = CreateWindow(L"STATIC", L"ウィンドウを最小化", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER, 0, 0, 120, 68, hwnd, (HMENU)IDC_STATIC, Program::HInstance(), nullptr);

        SetAsCenter(hStatic, hwnd, 0, 0);

        break;

    case WM_MOVE:
        GetWindowRect(hwnd, &rect);

        swprintf(wcs, WCS_LENGTH, L"左: %04ld\n右: %04ld\n上: %04ld\n下: %04ld\n", rect.left, rect.right, rect.top, rect.bottom);

        SetWindowText(hStatic, wcs);

        SetAsCenter(hStatic, hwnd, 0, 0);

        break;

    case WM_SIZE:
        GetWindowRect(hwnd, &rect);

        swprintf(wcs, WCS_LENGTH, L"左: %04ld\n右: %04ld\n上: %04ld\n下: %04ld\n", rect.left, rect.right, rect.top, rect.bottom);

        SetWindowText(hStatic, wcs);

        SetAsCenter(hStatic, hwnd, 0, 0);

        break;

    default:
        return SampleManager::DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}