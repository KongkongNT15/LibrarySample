#include "pch.h"

namespace Kongkong
{

    LRESULT CALLBACK SampleManager::DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {

        static bool isLightMode = false;
        switch (uMsg) {
            //拡大率の変更
        case WM_DPICHANGED:

            break;

        case WM_SETTINGCHANGE:
        {
            bool value = System::IsLightTheme();

            if (value == isLightMode) break;

            SetTitleBarTheme(hwnd, value);
            isLightMode = value;

            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_3DFACE + 1));

            EndPaint(hwnd, &ps);

            break;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    LRESULT CALLBACK SampleManager::NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

    WindowProcedure SampleManager::NotFound(std::wstring_view const& tag) noexcept
    {
        return NotFoundWindowProc;
    }

}