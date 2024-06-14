#include "pch.h"
#include "WinUser.Samples.h"

#define IDC_BUTTON1 100
#define IDC_COMBOBOX1 101

LRESULT CALLBACK Kongkong::WinUser::MessageBeepProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton = nullptr;
    static HWND hComboBox = nullptr;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:

        hComboBox = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            L"COMBOBOX", nullptr,
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
            0, 0, 120, 20,
            hwnd, (HMENU)IDC_COMBOBOX1, Program::HInstance(), nullptr);

        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"��ʂ̌x����");
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"�V�X�e���G���[");
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"���b�Z�[�W (�₢���킹)");
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"���b�Z�[�W (�x��)");
        SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"���b�Z�[�W (���)");

        SendMessage(hComboBox, CB_SETCURSEL, 0, 0);

        hButton = CreateWindow(L"BUTTON", L"�Đ�", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 64, 24, hwnd, (HMENU)IDC_BUTTON1, Program::HInstance(), nullptr);

        SetAsCenter(hComboBox, hwnd, 0, -12);
        SetAsCenter(hButton, hwnd, 0, 12);

        break;

    case WM_SIZE:

        SetAsCenter(hComboBox, hwnd, 0, -12);
        SetAsCenter(hButton, hwnd, 0, 12);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            unsigned value = (unsigned)(SendMessage(hComboBox, CB_GETCURSEL, 0, 0) << 4ll);
            MessageBeep(value);
            break;
        }
        break;

    default:
        return SampleManager::DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}