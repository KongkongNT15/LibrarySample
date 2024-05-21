#include "pch.h"

int IsEqualStringA(const char* left, const char* right)
{
	return strcmp(left, right) == 0;
}

int IsEqualStringW(const wchar_t* left, const wchar_t* right)
{
	return wcscmp(left, right) == 0;
}

BOOL GetRegistoryDWORDW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name, DWORD* pData)
{
    DWORD length = sizeof(DWORD);
    HKEY  hKey = NULL;
    DWORD rc = RegOpenKeyEx(hKeyParent, key, 0, KEY_READ, &hKey);

    if (rc == ERROR_SUCCESS) {
        rc = RegQueryValueEx(hKey, name, NULL, NULL, (LPBYTE)(pData), &length);
    }
        
    RegCloseKey(hKey);

    return rc == ERROR_SUCCESS;
}

BOOL IsLightTheme()
{
    DWORD value;
    GetRegistoryDWORDW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"AppsUseLightTheme",
        &value);

    return value;
}

HRESULT SetTitleBarTheme(HWND hwnd, BOOL isLightTheme)
{
    BOOL isDark = isLightTheme == FALSE;
    return DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &isDark, sizeof(isDark));
}

LRESULT CALLBACK NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        SetTextAlign(hdc, TA_CENTER);

        wchar_t message[] = L"ÉTÉìÉvÉãÇ™å©Ç¬Ç©ÇËÇ‹ÇπÇÒÇ≈ÇµÇΩ";

        TextOut(hdc, ps.rcPaint.right >> 1, ps.rcPaint.bottom >> 1, message, (int)wcslen(message));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefaultSampleWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static BOOL isLightMode = FALSE;
    switch (uMsg) {
        //ägëÂó¶ÇÃïœçX
    case WM_DPICHANGED:

        break;

    case WM_SETTINGCHANGE:
        BOOL value = IsLightTheme();

        if (value == isLightMode) break;

        SetTitleBarTheme(hwnd, value);
        isLightMode = value;

        break;

    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);

        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

//

WindowProcedure NotFound(const wchar_t* tag)
{

    return NotFoundWindowProc;
}

WindowProcedure GetWindowProcedure(const wchar_t* headerTag, const wchar_t* sampleTag)
{
    if (IsEqualStringW(headerTag, L"WinUser.h")) return GetWinUserProcedure(sampleTag);

    return NotFound(headerTag);
}