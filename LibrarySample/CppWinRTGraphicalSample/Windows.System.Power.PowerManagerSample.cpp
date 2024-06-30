#include "pch.h"
#include "Windows.System.Power.PowerManagerSample.h"
#include "Windows.System.Power.PowerManagerSample.PowerManagerPage.h"

namespace Kongkong::Windows::System::Power::PowerManagerSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		return MainWindow::ShowWindow<PowerManagerPage>();
	}
}