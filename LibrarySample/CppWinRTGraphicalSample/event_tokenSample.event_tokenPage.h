#pragma once

namespace Kongkong::event_tokenSample
{
	struct event_tokenPage : public SamplePage {
		event_tokenPage();

	private:
		winrt::Windows::UI::Xaml::Controls::ToggleSwitch _toggleSwitch;
		winrt::Windows::UI::Xaml::Controls::Button _button;
		winrt::Windows::UI::Xaml::Controls::TextBlock _stateTextBlock;

		winrt::event_token _token;

		int _count = 0;

		void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
		void ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
	};
}