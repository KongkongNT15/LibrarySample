#pragma once

namespace Kongkong::WinUser
{
	LRESULT CALLBACK CloseWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK GetWindowRectProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK IsZoomedProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK MessageBeepProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK MessageBoxWProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}