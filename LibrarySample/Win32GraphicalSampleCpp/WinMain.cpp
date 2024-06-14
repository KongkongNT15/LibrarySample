#include "pch.h"
using namespace Kongkong;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	//コマンドラインが正しくなければ即終了
	if (Program::Args().size() < 3) return -1;

	Program::InitializeComponent(hInstance, nCmdShow);

	MainWindow window;

	window.Activate();

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	DeleteObject(Program::HFont());

	return 0;
}