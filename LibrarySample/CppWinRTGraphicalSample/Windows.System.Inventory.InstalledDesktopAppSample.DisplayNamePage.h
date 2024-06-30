#pragma once

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
	struct DisplayNamePage : public SamplePage {
		DisplayNamePage();

	private:
		winrt::Windows::Foundation::IAsyncAction InitializeComponent();
	};
}