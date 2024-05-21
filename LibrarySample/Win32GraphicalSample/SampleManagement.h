#pragma once

#include "Windows.h"

#ifdef _AMD64_
#define __X64__
#elif defined(_ARM64_)
#define __ARM64__
#else
#define __X86__
#endif

typedef WNDPROC WindowProcedure;

int IsEqualStringA(const char* left, const char* right);
int IsEqualStringW(const wchar_t* left, const wchar_t* right);

BOOL GetRegistoryDWORDW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name, DWORD* pData);
BOOL IsLightTheme();

HRESULT SetTitleBarTheme(HWND hwnd, BOOL isLightTheme);

LRESULT CALLBACK NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

WindowProcedure NotFound(const wchar_t* tag);

WindowProcedure GetWindowProcedure(const wchar_t* headerTag, const wchar_t* sampleTag);

WindowProcedure GetWinUserProcedure(const wchar_t* tag);