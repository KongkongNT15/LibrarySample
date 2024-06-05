#pragma once

namespace Kongkong::Windows::System::Display::DisplayRequestSample
{
	struct DisplayRequestPage : public SamplePage {

		DisplayRequestPage();

	private:

		winrt::Windows::UI::Xaml::Controls::ToggleSwitch RequestToggleSwitch;

		winrt::Windows::System::Display::DisplayRequest Request;

		void RequestToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

	};
}