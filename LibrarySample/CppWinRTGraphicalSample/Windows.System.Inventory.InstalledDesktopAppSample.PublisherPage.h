#pragma once

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
	struct PublisherPage : public SamplePage {
		PublisherPage();

	private:
		winrt::Windows::Foundation::IAsyncAction InitializeComponent();
	};
}