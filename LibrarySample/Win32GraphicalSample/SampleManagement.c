#include "pch.h"

HFONT font = NULL;

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

BOOL GetArgs(wchar_t** pHeaderTag, wchar_t** pSampleTag)
{
    wchar_t* p = GetCommandLine();
    size_t length = wcslen(p);
    wchar_t* end = p + length;
    int count = 0;
    wchar_t* args[3];

    while (p != end) {
        if (count > 3) return FALSE;

        BOOL added = FALSE;
        if (*p != L' ') {
            if (*p == L'"') {
                for (wchar_t* q = p + 1; q != end; ++q) {
                    if (*q == L'\"') {
                        wchar_t* tmp = malloc(sizeof(wchar_t) * ((q - p) + 1));
                        if (tmp == NULL) return FALSE;

                        memcpy(tmp, p + 1, sizeof(wchar_t) * (q - p - 1));

                        tmp[q - p - 1] = L'\0';

                        args[count++] = tmp;

                        puts("s");

                        p = q;
                        break;
                    }
                }
            }
            else {
                for (wchar_t* q = p; q != end; ++q) {
                    if (*q == L' ' || *q == L'\0') {

                        wchar_t* tmp = malloc(sizeof(wchar_t) * ((q - p) + 1));
                        if (tmp == NULL) return FALSE;

                        memcpy(tmp, p, sizeof(wchar_t) * (q - p));

                        tmp[q - p] = L'\0';
                        p = q - 1;
                        added = TRUE;

                        args[count++] = tmp;

                        break;
                    }
                }
                if (!added) {
                    wchar_t* tmp = malloc(sizeof(wchar_t) * ((end - p) + 1));
                    if (tmp == NULL) return FALSE;

                    memcpy(tmp, p, sizeof(wchar_t) * (end - p));

                    tmp[end - p] = L'\0';

                    args[count++] = tmp;

                    break;
                }

            }

            
        }

        p++;
    }

    if (count != 3) return FALSE;

    *pHeaderTag = args[1];
    *pSampleTag = args[2];

    return TRUE;
}

HRESULT SetTitleBarTheme(HWND hwnd, BOOL isLightTheme)
{
    BOOL isDark = isLightTheme == FALSE;
    return DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &isDark, sizeof(isDark));
}

BOOL SetAsCenter(HWND hChild, HWND hParent, int x, int y)
{
    double kakudairitu = GetDpiForWindow(hParent) / 96.0;

    x = (int)(kakudairitu * x);
    y = (int)(kakudairitu * y);

    RECT parentClientRect, childRect;
    int x1, y1;
    int width, height;

    GetClientRect(hParent, &parentClientRect);
    GetWindowRect(hChild, &childRect);

    width = childRect.right - childRect.left;
    height = childRect.bottom - childRect.top;
    x1 = (parentClientRect.right - width) / 2;
    y1 = (parentClientRect.bottom - height) / 2;

    return SetWindowPos(hChild, NULL, x1 + x, y1 + y, width, height, SWP_NOZORDER);
}

BOOL CALLBACK ChangeToModernStyle(HWND hwnd, LPARAM lParam)
{
    SendMessage(hwnd, WM_SETFONT, (WPARAM)font, MAKELPARAM(TRUE, 0));

    double kakudairitu = GetDpiForWindow(hwnd) / 96.0;
    RECT rect, rectParent;
    GetWindowRect(hwnd, &rect);

    if (lParam == MAKELPARAM(TRUE, 0)) {
        GetWindowRect(GetParent(hwnd), &rectParent);
    }
    else {
        POINT point = { 0 };
        ClientToScreen(GetParent(hwnd), &point);

        rectParent.left = point.x;
        rectParent.top = point.y;
    }

    SetWindowPos(hwnd, NULL, (int)((rect.left - rectParent.left) * kakudairitu), (int)((rect.top - rectParent.top) * kakudairitu), (int)((rect.right - rect.left) * kakudairitu), (int)((rect.bottom - rect.top) * kakudairitu), SWP_NOZORDER);

    EnumChildWindows(hwnd, ChangeToModernStyle, MAKELPARAM(TRUE, 0));

    return TRUE;
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

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_3DFACE + 1));
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

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_3DFACE + 1));

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
    if (IsEqualStringW(headerTag, L"Winuser.h")) return GetWinUserProcedure(sampleTag);

    return NotFound(headerTag);
}