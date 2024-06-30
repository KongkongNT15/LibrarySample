#pragma once

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
	struct DisplayVersionPage : public SamplePage {
		DisplayVersionPage();

	private:
		winrt::Windows::Foundation::IAsyncAction InitializeComponent();
	};
}