#pragma once

namespace Kongkong::Windows::UI::ColorHelperSample
{
	struct FromArgbPage : SamplePage {

		FromArgbPage();

	private:
		winrt::Windows::UI::Xaml::Controls::Slider _aSlider;
		winrt::Windows::UI::Xaml::Controls::Slider _rSlider;
		winrt::Windows::UI::Xaml::Controls::Slider _gSlider;
		winrt::Windows::UI::Xaml::Controls::Slider _bSlider;

		winrt::Windows::UI::Xaml::Shapes::Rectangle _rectangle;

		void SliderValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& args);

		void ApplyColor();

		void SetSlider(winrt::Windows::UI::Xaml::Controls::Slider const& slider, winrt::Windows::UI::Xaml::Controls::StackPanel const& rootPanel, winrt::hstring const& title);
	};
}