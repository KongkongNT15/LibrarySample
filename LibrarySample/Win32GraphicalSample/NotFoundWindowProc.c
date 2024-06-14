#include "pch.h"

LRESULT CALLBACK NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hText;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CREATE:

        hText = CreateWindow(
            L"STATIC", L"サンプルが見つかりませんでした\r\nふぁ！？っく",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            0, 0, 300, 80,
            hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

        SetAsCenter(hText, hwnd, 0, 0);
        return 0;

    case WM_SIZE:
        SetAsCenter(hText, hwnd, 0, 0);
        return 0;
    return 0;

    }
    return DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
}