#include "pch.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    wchar_t* headerTag;
    wchar_t* sampleTag;

    //����������������΂����ŏI��
    if (!GetArgs(&headerTag, &sampleTag)) return -1;

    // Register the window class.
    const wchar_t CLASS_NAME[] = L"MainWindow";

    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = GetWindowProcedure(headerTag, sampleTag);
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    free(headerTag);
    free(sampleTag);

    RegisterClass(&wc);

    const wchar_t caption[] =
#ifdef __X64__
        L"Win32 �T���v�� (x64)";
#elif defined(__ARM64__)
        L"Win32 �T���v�� (ARM64)";
#else
        L"Win32 �T���v�� (x86)";
#endif

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        caption,    // Window text
        WS_OVERLAPPEDWINDOW,// Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    double kakudairitus = GetDpiForSystem() / 96.0;
    //
    font = CreateFont(
        (int)(16 * kakudairitus), (int)(6.8 * kakudairitus),					//����, ��
        0, 0,					//�p�x1, �p�x2
        FW_DONTCARE,			//����
        FALSE, FALSE, FALSE,	//�Α�, ����, �ŏ�����
        SHIFTJIS_CHARSET,		//�����Z�b�g
        OUT_DEFAULT_PRECIS,		//���x
        CLIP_DEFAULT_PRECIS,	//���x
        DEFAULT_QUALITY,		//�i��
        DEFAULT_PITCH | FF_DONTCARE, //�s�b�`�ƃt�@�~��
        L"Yu Gothic UI");

    if (font == NULL) {
        return 1;
    }

    EnumChildWindows(hwnd, ChangeToModernStyle, MAKELPARAM(FALSE, 0));

    SetTitleBarTheme(hwnd, IsLightTheme());
    ShowWindow(hwnd, nCmdShow);
    

    // Run the message loop.

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DeleteObject(font);

	return 0;
}