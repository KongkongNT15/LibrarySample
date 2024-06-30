#include "pch.h"

namespace Kongkong
{
	HWND MainWindow::_handle = nullptr;
	HWND MainWindow::_contentHandle = nullptr;
    bool MainWindow::_isCreated = false;
    int MainWindow::_nShowCmd = 0;
    winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource MainWindow::_desktopSource = nullptr;

	bool MainWindow::Create(HINSTANCE hInstance, int nShowCmd)
	{
        if (_isCreated) [[unlikely]] return false;
        _isCreated = true;
        _nShowCmd = nShowCmd;

        //�E�C���h�E�N���X�o�^
        const wchar_t szWindowClass[] = L"MainWindow";
        WNDCLASSEX windowClass = {};
        windowClass.cbSize = sizeof(WNDCLASSEX);
        windowClass.lpfnWndProc = WindowProc;
        windowClass.hInstance = hInstance;
        windowClass.lpszClassName = szWindowClass;
        windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

        if (::RegisterClassEx(&windowClass) == 0) [[unlikely]] return false;

        //�E�C���h�E�쐬

        const wchar_t titleName[] = L"C++/WinRT �T���v�� "
#ifdef __X64__
            L"(x64)";
#elif defined(__X86__)
            L"(x86)";
#elif defined(__ARM64__)
            L"(ARM64)";
#endif

        _handle = ::CreateWindow(
            szWindowClass,
            titleName,
            WS_OVERLAPPEDWINDOW,            //Window�̃X�^�C��

            //Window�T�C�X�ƈʒu
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            nullptr,
            nullptr,
            hInstance,
            nullptr
        );

        if (_handle == nullptr) [[unlikely]] return false;

        //C++/WinRT�̂��܂��Ȃ�
        ::winrt::init_apartment(::winrt::apartment_type::single_threaded);

        auto tmp = winrt::Windows::UI::Xaml::Hosting::WindowsXamlManager::InitializeForCurrentThread();

        //XAML�z�X�g����
        _desktopSource = winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource();
        auto interop = _desktopSource.as<IDesktopWindowXamlSourceNative>();
        ::winrt::check_hresult(interop->AttachToWindow(_handle));
        interop->get_WindowHandle(&_contentHandle);

        //XAML�z�X�g�̃T�C�Y�����C���E�C���h�E�ɍ��킹��
        RECT rcClient;
        ::GetClientRect(_handle, &rcClient);
        ::SetWindowPos(_contentHandle, nullptr, 0, 0, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, SWP_SHOWWINDOW);

        return true;
	}

    int MainWindow::ShowNotFoundWindow()
    {
        return ShowWindow<NotFoundPage>();
    }

    void MainWindow::MessageLoop()
    {
        //���C���E�C���h�E�\��
        ::ShowWindow(_handle, _nShowCmd);
        ::UpdateWindow(_handle);

        //���b�Z�[�W���[�v
        MSG msg{};

        while (::GetMessage(&msg, nullptr, 0, 0)) {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
    }


    //�E�C���h�E�v���V�[�W��
    LRESULT CALLBACK MainWindow::WindowProc(HWND hWnd, UINT messageCode, WPARAM wParam, LPARAM lParam) {
        RECT rcClient;

        switch (messageCode) {
        case WM_CREATE:
            //return 0;
            break;

        case WM_DESTROY:
            ::PostQuitMessage(0);
            break;

        case WM_DPICHANGED:
        {
            auto  dpi = HIWORD(wParam);
            auto& r = *(RECT const*)lParam;
            // �V���� Windows �T�C�Y�ɕύX.
            SetWindowPos(hWnd, nullptr
                , r.left, r.top, r.right - r.left, r.bottom - r.top
                , SWP_NOZORDER | SWP_NOACTIVATE);
        }
        break;

        case WM_SIZE:   //���C���E�C���h�E�̃T�C�Y���ς������XAML�z�X�g���Ǐ]
            ::GetClientRect(hWnd, &rcClient);
            LONG width, height;
            //�E�B���h�E�T�C�Y���[���Ȃ牽�����Ȃ�
            if ((width = rcClient.right - rcClient.left) == 0 && (height = rcClient.top - rcClient.bottom) == 0) return 0;
            ::SetWindowPos(_contentHandle, nullptr, 0, 0, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, SWP_SHOWWINDOW);

            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            bool isDark = _desktopSource.Content().as<winrt::Windows::UI::Xaml::FrameworkElement>().ActualTheme() == winrt::Windows::UI::Xaml::ElementTheme::Dark;

            if (isDark) {
                FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOWTEXT + 1));
            }
            else {
                FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            }

            EndPaint(hWnd, &ps);

            break;
        }

        default:
            return ::DefWindowProc(hWnd, messageCode, wParam, lParam);
        }

        return 0;
    }
}