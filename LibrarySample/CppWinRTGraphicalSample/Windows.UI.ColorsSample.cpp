#include "pch.h"
#include "Windows.UI.ColorsSample.h"

namespace Kongkong::Windows::UI::ColorsSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		return MainWindow::ShowWindow<ColorsPage>();
	}
}