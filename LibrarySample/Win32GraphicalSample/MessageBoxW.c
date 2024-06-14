#include "pch.h"
#include "WinUser.Samples.h"

#define IDC_BUTTON1 100
#define IDC_TEXTBOX1 101
#define IDC_COMBOBOX1 102
#define IDC_COMBOBOX2 103

LRESULT CALLBACK MessageBoxWProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hTitleEdit = NULL;
    static HWND hMessageEdit = NULL;
    static HWND hIconsComboBox = NULL;
    static HWND hButtonComboBox = NULL;
    static HWND hResultText = NULL;

    static const wchar_t* icons[] = {
        L"�Ȃ�",
        L"�G���[",
        L"�͂Ăȃ}�[�N",
        L"�x��",
        L"���",
    };

    static const wchar_t* buttons[] = {
        L"OK",
        L"OK�E�L�����Z��",
        L"���~�E�Ď��s�E����",
        L"�͂��E�������E�L�����Z��",
        L"�͂��E������",
        L"�Ď��s�E�L�����Z��",
        L"�L�����Z���E�Ď��s�E���s",
    };

    static const wchar_t* results[] = {
        L"�����ꂽ�{�^���F�@OK",
        L"�����ꂽ�{�^���F�@�L�����Z��",
        L"�����ꂽ�{�^���F�@���~",
        L"�����ꂽ�{�^���F�@�Ď��s",
        L"�����ꂽ�{�^���F�@����",
        L"�����ꂽ�{�^���F�@�͂�",
        L"�����ꂽ�{�^���F�@������",
        L"�����ꂽ�{�^���F�@����",
        L"�����ꂽ�{�^���F�@�w���v",
        L"�����ꂽ�{�^���F�@�Ď��s",
        L"�����ꂽ�{�^���F�@���s",
    };

    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_CREATE:
            CreateWindow(
                L"STATIC", L"�^�C�g��",
                WS_CHILD | WS_VISIBLE,
                20, 20, 300, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            hTitleEdit = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"�^�C�g��",
                WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
                20, 40, 300, 22,
                hwnd,
                (HMENU)IDC_TEXTBOX1,
                GetModuleHandle(NULL),
                NULL);

            CreateWindow(
                L"STATIC", L"���b�Z�[�W",
                WS_CHILD | WS_VISIBLE,
                20, 80, 200, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            hMessageEdit = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"���b�Z�[�W",
                WS_CHILD | WS_VISIBLE | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_AUTOHSCROLL,
                20, 100, 300, 90,
                hwnd,
                (HMENU)IDC_TEXTBOX1,
                GetModuleHandle(NULL),
                NULL);

            CreateWindow(
                L"STATIC", L"�A�C�R��",
                WS_CHILD | WS_VISIBLE,
                20, 210, 200, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            hIconsComboBox = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"COMBOBOX", NULL,
                WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
                20, 230, 80, 20,
                hwnd, (HMENU)IDC_COMBOBOX1, GetModuleHandle(NULL), NULL);

            for (size_t i = 0; i < sizeof(icons) / sizeof(icons[0]); i++) {
                SendMessage(hIconsComboBox, CB_ADDSTRING, 0, (LPARAM)icons[i]);
            }
            SendMessage(hIconsComboBox, CB_SETCURSEL, 1, 0);

            CreateWindow(
                L"STATIC", L"�{�^���̎��",
                WS_CHILD | WS_VISIBLE,
                20, 270, 200, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            hButtonComboBox = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"COMBOBOX", NULL,
                WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
                20, 290, 160, 20,
                hwnd, (HMENU)IDC_COMBOBOX2, GetModuleHandle(NULL), NULL);

            for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
                SendMessage(hButtonComboBox, CB_ADDSTRING, 0, (LPARAM)buttons[i]);
            }
            SendMessage(hButtonComboBox, CB_SETCURSEL, 1, 0);

            CreateWindow(
                L"STATIC", L"���b�Z�[�W�{�b�N�X��\��",
                WS_CHILD | WS_VISIBLE,
                20, 330, 200, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            CreateWindow(L"BUTTON", L"�\��", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 350, 64, 24, hwnd, (HMENU)IDC_BUTTON1, GetModuleHandle(NULL), NULL);

            hResultText = CreateWindow(
                L"STATIC", L"",
                WS_CHILD | WS_VISIBLE,
                20, 390, 200, 16,
                hwnd, (HMENU)IDC_STATIC, GetModuleHandle(NULL), NULL);

            break;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_BUTTON1:
                    int titleLength = GetWindowTextLength(hTitleEdit) + 1;
                    int messageLength = GetWindowTextLength(hMessageEdit) + 1;
                    int result;

                    wchar_t* title = malloc(titleLength * sizeof(wchar_t));
                    wchar_t* message = malloc(messageLength * sizeof(wchar_t));

                    LRESULT iconValue, buttonValue;

                    if (!title || !message) break;

                    GetWindowText(hTitleEdit, title, titleLength);
                    GetWindowText(hMessageEdit, message, messageLength);

                    iconValue = SendMessage(hIconsComboBox, CB_GETCURSEL, 0, 0) << 4ll;
                    buttonValue = SendMessage(hButtonComboBox, CB_GETCURSEL, 0, 0);

                    result = MessageBox(hwnd, message, title, (UINT)(iconValue | buttonValue));

                    if (result < 1 || 11 < result) SetWindowText(hResultText, L"�����ꂽ�{�^���F�@�s���Ȓl");
                    else SetWindowText(hResultText, results[result - 1]);

                    free(title);
                    free(message);
                    break;
            }
            break;

        default:
            return DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}