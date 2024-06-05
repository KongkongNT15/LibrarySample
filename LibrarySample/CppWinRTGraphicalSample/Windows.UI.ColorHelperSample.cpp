#include "pch.h"
#include "Windows.UI.ColorHelperSample.h"
#include "Windows.UI.ColorHelperSample.FromArgbPage.h"
#include "Windows.UI.ColorHelperSample.ToDisplayNamePage.h"

namespace Kongkong::Windows::UI::ColorHelperSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		if (tag == L"FromArgb") return MainWindow::ShowWindow<FromArgbPage>();
		if (tag == L"ToDisplayName") return MainWindow::ShowWindow<ToDisplayNamePage>();

		return MainWindow::ShowNotFoundWindow();
	}
}