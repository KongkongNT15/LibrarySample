#include <Windows.h>

DWORD ShowMessageBox()
{
	MessageBox(NULL, L"アプリケーションの起動に失敗しました", L"LibrarySample", MB_OK | MB_ICONERROR);
	return GetLastError();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	if (SetCurrentDirectory(L"bin") == FALSE) {
		return ShowMessageBox();
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	wchar_t cmdline[] = L"LibrarySampleApp";

	if (!CreateProcess(NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		return ShowMessageBox();
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}