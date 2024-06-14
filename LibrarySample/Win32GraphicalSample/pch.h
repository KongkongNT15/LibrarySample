#pragma once

#include <stdio.h>
#include <Windows.h>
#include <dwmapi.h>

#define IDC_STATIC -1

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

extern HFONT Font;

BOOL GetArgs(wchar_t** pHeaderTag, wchar_t** pSampleTag);

BOOL GetRegistoryDoubleWordW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name, DWORD* pData);
BOOL IsLightTheme();

BOOL CALLBACK ChangeToModernStyle(HWND hwnd, LPARAM lParam);

BOOL SetAsCenter(HWND hChild, HWND hParent, int x, int y);

HRESULT SetTitleBarTheme(HWND hwnd, BOOL isLightTheme);

LRESULT CALLBACK NotFoundWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DefaultSampleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

WindowProcedure NotFound(const wchar_t* tag);

WindowProcedure GetWindowProcedure(const wchar_t* headerTag, const wchar_t* sampleTag);