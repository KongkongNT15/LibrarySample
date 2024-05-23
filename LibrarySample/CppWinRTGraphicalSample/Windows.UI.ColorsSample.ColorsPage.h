#pragma once

namespace Kongkong::Windows::UI::ColorsSample
{
	struct ColorsPage final : public SamplePage {

		ColorsPage();

	private:

		static winrt::Windows::UI::Xaml::Controls::StackPanel SetColorValue(winrt::hstring const& name, winrt::Windows::UI::Color const& color);

		static void Rectangle_ActualThemeChanged(winrt::Windows::UI::Xaml::FrameworkElement const& sender, winrt::Windows::Foundation::IInspectable const& args);

		static void Rectangle_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
	};
}