#include "pch.h"
#include "Windows.System.Display.DisplayRequestSample.h"
#include "Windows.System.Display.DisplayRequestSample.DisplayRequestPage.h"

namespace Kongkong::Windows::System::Display::DisplayRequestSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		return MainWindow::ShowWindow<DisplayRequestPage>();
	}
}