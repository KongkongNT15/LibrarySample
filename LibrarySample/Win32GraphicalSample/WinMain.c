#include "pch.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"MainWindow";

    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = GetWindowProcedure(L"WinUser.h", L"MessageBox");
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    const wchar_t caption[] =
#ifdef __X64__
        L"Win32 サンプル (x64)";
#elif defined(__ARM64__)
        L"Win32 サンプル (ARM64)";
#else
        L"Win32 サンプル (x86)";
#endif

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        caption,    // Window text
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,// Window style

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

    ShowWindow(hwnd, nCmdShow);
    SetTitleBarTheme(hwnd, IsLightTheme());

    // Run the message loop.

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	return 0;
}