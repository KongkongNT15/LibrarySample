#include "pch.h"

namespace Kongkong
{
	const wchar_t* MainWindow::_className = L"MainWindow";

	MainWindow::MainWindow()
	{
		const wchar_t caption[] =
#ifdef __X64__
			L"Win32 C++ サンプル (x64)";
#elif defined(__ARM64__)
			L"Win32 C++ サンプル (ARM64)";
#else
			L"Win32 C++ サンプル (x86)";
#endif

		_handle = CreateWindowEx(
			0,                              // Optional window styles.
			_className,                     // Window class
			caption,    // Window text
			WS_OVERLAPPEDWINDOW,// Window style

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			nullptr,       // Parent window    
			nullptr,       // Menu
			Program::HInstance(),  // Instance handle
			nullptr        // Additional application data
		);

		if (_handle == nullptr) [[unlikely]] throw Exception(L"MainWindowの作成に失敗しました");

		_changeToModernStyle();

		SetTitleBarTheme(_handle, System::IsLightTheme());
	}

	void MainWindow::Activate()
	{
		ShowWindow(_handle, Program::CmdShow());
	}

	void MainWindow::_changeToModernStyle() noexcept
	{
		EnumChildWindows(_handle , _changeToModernStyleProc, MAKELPARAM(FALSE, 0));
	}

	BOOL CALLBACK MainWindow::_changeToModernStyleProc(HWND hwnd, LPARAM lParam) noexcept
	{
		SendMessage(hwnd, WM_SETFONT, (WPARAM)Program::HFont(), MAKELPARAM(TRUE, 0));

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

		SetWindowPos(hwnd, nullptr, (int)((rect.left - rectParent.left) * kakudairitu), (int)((rect.top - rectParent.top) * kakudairitu), (int)((rect.right - rect.left) * kakudairitu), (int)((rect.bottom - rect.top) * kakudairitu), SWP_NOZORDER);

		EnumChildWindows(hwnd, _changeToModernStyleProc, MAKELPARAM(TRUE, 0));

		return TRUE;
	}
}