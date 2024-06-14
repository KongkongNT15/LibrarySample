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

        hButton = CreateWindow(L"BUTTON", L"����", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 64, 24, hwnd, (HMENU)IDC_BUTTON1, Program::HInstance(), nullptr);

        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            MessageBox(hwnd, IsZoomed(hwnd) ? L"�ő剻����Ă��܂�" : L"�ʏ��Ԃł�", L"����", MB_OK | MB_ICONINFORMATION);
            break;
        }
        break;

    case WM_SIZE:
        //���b�Z�[�W�ŏ�Ԃ𔻒肷�邱�Ƃ��ł���
        switch (wParam) {
        case SIZE_RESTORED: /*�ʏ�*/ break;
        case SIZE_MINIMIZED: /*�ŏ���*/ break;
        case SIZE_MAXIMIZED: /*�ő剻*/ break;
        case SIZE_MAXSHOW: /*�ق��̃E�B���h�E���ő剻��Ԃ���ڍs*/ break;
        case SIZE_MAXHIDE: /*�ق��̃E�B���h�E���ő剻*/ break;
        }

        SetAsCenter(hButton, hwnd, 0, 0);

        break;

    default:
        return SampleManager::DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}