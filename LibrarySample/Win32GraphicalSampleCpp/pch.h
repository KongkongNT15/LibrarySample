#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include <Windows.h>
#include <dwmapi.h>

#ifdef _AMD64_
#define __X64__
#elif defined(_ARM64_)
#define __ARM64__
#else
#define __X86__
#endif

#define IDC_STATIC -1

namespace Kongkong
{
	using WindowProcedure = WNDPROC;

	bool IsEqualStringA(const char* left, const char* right) noexcept;
	bool IsEqualStringW(const wchar_t* left, const wchar_t* right) noexcept;

	void SetTitleBarTheme(HWND hwnd, bool isLight);

	void SetAsCenter(HWND hChild, HWND hParent, int x, int y);

	DWORD GetRegistoryDoubleWordW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name);

	struct System {
		System() = delete;
		System(System const&) = delete;
		System(System&&) = delete;

		System& operator=(System const&) = delete;
		System& operator=(System&&) = delete;

		static bool IsLightTheme();
		static bool IsDarkTheme() { return !IsLightTheme(); }
	};

	struct Program {
		Program() = delete;
		Program(Program const&) = delete;
		Program(Program&&) = delete;

		Program& operator=(Program const&) = delete;
		Program& operator=(Program&&) = delete;

		static std::vector<std::wstring_view> const& Args() noexcept;

		static constexpr int CmdShow() noexcept { return _cmdShow; }

		static void InitializeComponent(HINSTANCE hInstance, int cmdShow);

		static constexpr HFONT HFont() noexcept { return _font; }
		static constexpr HINSTANCE HInstance() noexcept { return _hInstance; }

	private:

		static HFONT _font;
		static HINSTANCE _hInstance;

		static int _cmdShow;

		static std::vector<std::wstring_view> _args;

		static bool _isInitialized;
		static bool _isArgsLoaded;
	};

	struct SampleManager {
		SampleManager() = delete;
		SampleManager(SampleManager const&) = delete;
		SampleManager(SampleManager&&) = delete;

		SampleManager& operator=(SampleManager const&) = delete;
		SampleManager& operator=(SampleManager&&) = delete;
		
		static LRESULT CALLBACK DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		static WindowProcedure NotFound(std::wstring_view const& tag) noexcept;

		static WindowProcedure GetWindowProcedure(std::wstring_view const& rootTag, std::wstring_view const& sampleTag) noexcept;
	};

	class MainWindow {
	public:

		static const wchar_t* ClassName() noexcept { return _className; }

		MainWindow();

		constexpr HWND Handle() const noexcept { return _handle; }

		void Activate();

	private:

		static const wchar_t* _className;

		void _changeToModernStyle() noexcept;

		static BOOL CALLBACK _changeToModernStyleProc(HWND hwnd, LPARAM lParam) noexcept;

		HWND _handle;
	};

	class Exception {
	public:

		Exception() : _message(L"ó·äOÇ™ÉXÉçÅ[Ç≥ÇÍÇ‹ÇµÇΩ") {}
		Exception(const wchar_t* message) : _message(message) {}
		Exception(const wchar_t* message, size_t count) : _message(message, count) {}
		Exception(std::wstring_view const& message) : _message(message) {}
		Exception(std::wstring const& message) : _message(message) {}

		std::wstring_view Message() const noexcept { return _message; }

	private:
		std::wstring _message;
	};
}

