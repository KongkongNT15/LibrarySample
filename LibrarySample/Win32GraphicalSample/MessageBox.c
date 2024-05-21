#include "pch.h"

#define IDC_BUTTON1 100

LRESULT CALLBACK MessageBoxProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:
        HWND hButton = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE, 20, 20, 200, 32, hwnd, (HMENU)IDC_BUTTON1, GetModuleHandle(NULL), NULL);
        //CreateWindow(L"STATIC", L"クリックしてね", WS_CHILD | WS_VISIBLE, 20, 20, 200, 32, hwnd, (HMENU)200, GetModuleHandle(NULL), NULL);
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            MessageBox(hwnd, L"クリックしたよ", L"情報", MB_OK);
            break;
        }
        break;

    default:
        return DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}