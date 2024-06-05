#include "pch.h"
#include "Windows.UI.ColorHelperSample.ToDisplayNamePage.h"

using namespace winrt;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

namespace Kongkong::Windows::UI::ColorHelperSample
{
	ToDisplayNamePage::ToDisplayNamePage()
	{
		//�O����
		_aSlider.Value(255);
		_rSlider.Value(0);
		_gSlider.Value(255);
		_bSlider.Value(255);

		//���C�A�E�g�\��
		StackPanel rootPanel = CreateOuterPanel();

		StackPanel settingPanel = CreateBlockPanel(L"�\���ݒ�", BlockPanelType::HasChildPanel);

		rootPanel.Children().Append(settingPanel);

		SetSlider(_aSlider, settingPanel, L"�A���t�@");
		SetSlider(_rSlider, settingPanel, L"��");
		SetSlider(_gSlider, settingPanel, L"��");
		SetSlider(_bSlider, settingPanel, L"��");

		StackPanel resultPanel = CreateBlockPanel(L"�o��");

		rootPanel.Children().Append(resultPanel);

		_rectangle.Width(240);
		_rectangle.Height(100);

		_rectangle.HorizontalAlignment(HorizontalAlignment::Left);

		resultPanel.Children().Append(_rectangle);
		resultPanel.Children().Append(_colorTextBlock);

		Content(rootPanel);

		//�㏈��
		ApplyColor();
	}

	void ToDisplayNamePage::SliderValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& args)
	{
		ApplyColor();
	}

	void ToDisplayNamePage::ApplyColor()
	{
		Color color = ColorHelper::FromArgb(
			(uint8_t)_aSlider.Value(),
			(uint8_t)_rSlider.Value(),
			(uint8_t)_gSlider.Value(),
			(uint8_t)_bSlider.Value()
		);

		_rectangle.Fill(SolidColorBrush(color));

		_colorTextBlock.Text(ColorHelper::ToDisplayName(color));
	}

	void ToDisplayNamePage::SetSlider(winrt::Windows::UI::Xaml::Controls::Slider const& slider, winrt::Windows::UI::Xaml::Controls::StackPanel const& rootPanel, winrt::hstring const& title)
	{
		slider.Width(320);

		slider.Maximum(255);
		slider.Minimum(0);

		slider.HorizontalAlignment(HorizontalAlignment::Left);

		slider.ValueChanged({ this, &ToDisplayNamePage::SliderValueChanged });

		StackPanel panel = CreateBlockPanel(title, BlockPanelType::MinTitle);

		rootPanel.Children().Append(panel);

		panel.Children().Append(slider);
	}
}