#include "pch.h"
#include "WinUser.Samples.h"

#define IDC_BUTTON1 100

LRESULT CALLBACK Kongkong::WinUser::IsZoomedProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton = nullptr;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:

        hButton = CreateWindow(L"BUTTON", L"判定", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 64, 24, hwnd, (HMENU)IDC_BUTTON1, Program::HInstance(), nullptr);

        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            MessageBox(hwnd, IsZoomed(hwnd) ? L"最大化されています" : L"通常状態です", L"判定", MB_OK | MB_ICONINFORMATION);
            break;
        }
        break;

    case WM_SIZE:
        //メッセージで状態を判定することもできる
        switch (wParam) {
        case SIZE_RESTORED: /*通常*/ break;
        case SIZE_MINIMIZED: /*最小化*/ break;
        case SIZE_MAXIMIZED: /*最大化*/ break;
        case SIZE_MAXSHOW: /*ほかのウィンドウが最大化状態から移行*/ break;
        case SIZE_MAXHIDE: /*ほかのウィンドウが最大化*/ break;
        }

        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    default:
        return SampleManager::DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}