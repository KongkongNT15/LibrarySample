#include "pch.h"
using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong
{
	StackPanel SamplePage::CreateBlockPanel(hstring const& title, BlockPanelType type)
	{
		StackPanel panel;
		if (type == BlockPanelType::HasChildPanel) {

			panel.Spacing(20.0);
		}
		else {
			panel.Spacing(8.0);
		}

		if (title.size() != 0) {
			TextBlock textBlock;
			if (type != BlockPanelType::MinTitle) {
				textBlock.FontSize(20);
			}

			textBlock.Text(title);
			panel.Children().Append(textBlock);
		}
		return panel;
	}

	StackPanel SamplePage::CreateOuterPanel()
	{
		StackPanel panel;
		panel.Spacing(40.0);
		panel.Padding(ThicknessHelper::FromUniformLength(40));

		return panel;
	}

	void SamplePage::SetAsCenter(winrt::Windows::UI::Xaml::FrameworkElement const& frameworkElement)
	{
		frameworkElement.HorizontalAlignment(HorizontalAlignment::Center);
		frameworkElement.VerticalAlignment(VerticalAlignment::Center);
	}

	SamplePage::SamplePage() : _content()
	{
		_content.Loaded({ this, &SamplePage::Loaded });
		_content.ActualThemeChanged({ this, &SamplePage::ActualThemeChanged });

		//動きません！！！
		//ふぁ！？っく
		_content.Resources(Microsoft::UI::Xaml::Controls::XamlControlsResources());
	}

	void SamplePage::Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& args)
	{
		ChangeTheme();
	}

	void SamplePage::ActualThemeChanged(winrt::Windows::UI::Xaml::FrameworkElement const& sender, winrt::Windows::Foundation::IInspectable const& args)
	{
		ChangeTheme();
	}

	void SamplePage::ChangeTheme()
	{
		BOOL value = _content.ActualTheme() == ElementTheme::Dark ? TRUE : FALSE;

		DwmSetWindowAttribute(MainWindow::Handle(), 20, &value, sizeof(value));
	}
}