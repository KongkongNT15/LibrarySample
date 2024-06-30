#pragma once

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
	struct IdPage : public SamplePage {
		IdPage();

	private:
		winrt::Windows::Foundation::IAsyncAction InitializeComponent();
	};
}