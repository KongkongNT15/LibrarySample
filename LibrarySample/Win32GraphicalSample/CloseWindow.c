#include "pch.h"

#define IDC_BUTTON1 100

LRESULT CALLBACK CloseWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton = NULL;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:

        hButton = CreateWindow(L"BUTTON", L"ウィンドウを最小化", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 120, 24, hwnd, (HMENU)IDC_BUTTON1, GetModuleHandle(NULL), NULL);

        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    case WM_SIZE:
        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            CloseWindow(hwnd);
            break;
        }
        break;

    default:
        return DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}