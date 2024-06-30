#include "pch.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.DisplayNamePage.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.DisplayVersionPage.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.IdPage.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.PublisherPage.h"

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		if (tag == L"DisplayName") return MainWindow::ShowWindow<DisplayNamePage>();
		if (tag == L"DisplayVersion") return MainWindow::ShowWindow<DisplayVersionPage>();
		if (tag == L"Id") return MainWindow::ShowWindow<IdPage>();
		if (tag == L"Publisher") return MainWindow::ShowWindow<PublisherPage>();

		return SampleManager::RunNotFoundPage();
	}
}