#include "pch.h"
#include "Windows.UI.ColorsSample.ColorsPage.h"

using namespace winrt;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

namespace Kongkong::Windows::UI::ColorsSample
{
	ColorsPage::ColorsPage()
	{
		//レイアウト構成
		StackPanel outerPanel = CreateOuterPanel();
		StackPanel panel = CreateBlockPanel(L"");

		outerPanel.Children().Append(panel);

		panel.Children().Append(SetColorValue(L"AliceBlue", Colors::AliceBlue()));
		panel.Children().Append(SetColorValue(L"AntiqueWhite", Colors::AntiqueWhite()));
		panel.Children().Append(SetColorValue(L"Aqua", Colors::Aqua()));
		panel.Children().Append(SetColorValue(L"Aquamarine", Colors::Aquamarine()));
		panel.Children().Append(SetColorValue(L"Azure", Colors::Azure()));
		panel.Children().Append(SetColorValue(L"Beige", Colors::Beige()));
		panel.Children().Append(SetColorValue(L"Bisque", Colors::Bisque()));
		panel.Children().Append(SetColorValue(L"Black", Colors::Black()));
		panel.Children().Append(SetColorValue(L"BlanchedAlmond", Colors::BlanchedAlmond()));
		panel.Children().Append(SetColorValue(L"Blue", Colors::Blue()));
		panel.Children().Append(SetColorValue(L"BlueViolet", Colors::BlueViolet()));
		panel.Children().Append(SetColorValue(L"Brown", Colors::Brown()));
		panel.Children().Append(SetColorValue(L"BurlyWood", Colors::BurlyWood()));
		panel.Children().Append(SetColorValue(L"CadetBlue", Colors::CadetBlue()));
		panel.Children().Append(SetColorValue(L"Chartreuse", Colors::Chartreuse()));
		panel.Children().Append(SetColorValue(L"Chocolate", Colors::Chocolate()));
		panel.Children().Append(SetColorValue(L"Coral", Colors::Coral()));
		panel.Children().Append(SetColorValue(L"CornflowerBlue", Colors::CornflowerBlue()));
		panel.Children().Append(SetColorValue(L"Cornsilk", Colors::Cornsilk()));
		panel.Children().Append(SetColorValue(L"Crimson", Colors::Crimson()));
		panel.Children().Append(SetColorValue(L"Cyan", Colors::Cyan()));
		panel.Children().Append(SetColorValue(L"DarkBlue", Colors::DarkBlue()));
		panel.Children().Append(SetColorValue(L"DarkCyan", Colors::DarkCyan()));
		panel.Children().Append(SetColorValue(L"DarkGoldenrod", Colors::DarkGoldenrod()));
		panel.Children().Append(SetColorValue(L"DarkGray", Colors::DarkGray()));
		panel.Children().Append(SetColorValue(L"DarkGreen", Colors::DarkGreen()));
		panel.Children().Append(SetColorValue(L"DarkKhaki", Colors::DarkKhaki()));
		panel.Children().Append(SetColorValue(L"DarkMagenta", Colors::DarkMagenta()));
		panel.Children().Append(SetColorValue(L"DarkOliveGreen", Colors::DarkOliveGreen()));
		panel.Children().Append(SetColorValue(L"DarkOrange", Colors::DarkOrange()));
		panel.Children().Append(SetColorValue(L"DarkOrchid", Colors::DarkOrchid()));
		panel.Children().Append(SetColorValue(L"DarkRed", Colors::DarkRed()));
		panel.Children().Append(SetColorValue(L"DarkSalmon", Colors::DarkSalmon()));
		panel.Children().Append(SetColorValue(L"DarkSeaGreen", Colors::DarkSeaGreen()));
		panel.Children().Append(SetColorValue(L"DarkSlateBlue", Colors::DarkSlateBlue()));
		panel.Children().Append(SetColorValue(L"DarkSlateGray", Colors::DarkSlateGray()));
		panel.Children().Append(SetColorValue(L"DarkTurquoise", Colors::DarkTurquoise()));
		panel.Children().Append(SetColorValue(L"DarkViolet", Colors::DarkViolet()));
		panel.Children().Append(SetColorValue(L"DeepPink", Colors::DeepPink()));
		panel.Children().Append(SetColorValue(L"DeepSkyBlue", Colors::DeepSkyBlue()));
		panel.Children().Append(SetColorValue(L"DimGray", Colors::DimGray()));
		panel.Children().Append(SetColorValue(L"DodgerBlue", Colors::DodgerBlue()));
		panel.Children().Append(SetColorValue(L"Firebrick", Colors::Firebrick()));
		panel.Children().Append(SetColorValue(L"FloralWhite", Colors::FloralWhite()));
		panel.Children().Append(SetColorValue(L"ForestGreen", Colors::ForestGreen()));
		panel.Children().Append(SetColorValue(L"Fuchsia", Colors::Fuchsia()));
		panel.Children().Append(SetColorValue(L"Gainsboro", Colors::Gainsboro()));
		panel.Children().Append(SetColorValue(L"GhostWhite", Colors::GhostWhite()));
		panel.Children().Append(SetColorValue(L"Gold", Colors::Gold()));
		panel.Children().Append(SetColorValue(L"Goldenrod", Colors::Goldenrod()));
		panel.Children().Append(SetColorValue(L"Gray", Colors::Gray()));
		panel.Children().Append(SetColorValue(L"Green", Colors::Green()));
		panel.Children().Append(SetColorValue(L"GreenYellow", Colors::GreenYellow()));
		panel.Children().Append(SetColorValue(L"Honeydew", Colors::Honeydew()));
		panel.Children().Append(SetColorValue(L"HotPink", Colors::HotPink()));
		panel.Children().Append(SetColorValue(L"IndianRed", Colors::IndianRed()));
		panel.Children().Append(SetColorValue(L"Indigo", Colors::Indigo()));
		panel.Children().Append(SetColorValue(L"Ivory", Colors::Ivory()));
		panel.Children().Append(SetColorValue(L"Khaki", Colors::Khaki()));
		panel.Children().Append(SetColorValue(L"Lavender", Colors::Lavender()));
		panel.Children().Append(SetColorValue(L"LavenderBlush", Colors::LavenderBlush()));
		panel.Children().Append(SetColorValue(L"LawnGreen", Colors::LawnGreen()));
		panel.Children().Append(SetColorValue(L"LemonChiffon", Colors::LemonChiffon()));
		panel.Children().Append(SetColorValue(L"LightBlue", Colors::LightBlue()));
		panel.Children().Append(SetColorValue(L"LightCoral", Colors::LightCoral()));
		panel.Children().Append(SetColorValue(L"LightCyan", Colors::LightCyan()));
		panel.Children().Append(SetColorValue(L"LightGoldenrodYellow", Colors::LightGoldenrodYellow()));
		panel.Children().Append(SetColorValue(L"LightGray", Colors::LightGray()));
		panel.Children().Append(SetColorValue(L"LightGreen", Colors::LightGreen()));
		panel.Children().Append(SetColorValue(L"LightPink", Colors::LightPink()));
		panel.Children().Append(SetColorValue(L"LightSalmon", Colors::LightSalmon()));
		panel.Children().Append(SetColorValue(L"LightSeaGreen", Colors::LightSeaGreen()));
		panel.Children().Append(SetColorValue(L"LightSkyBlue", Colors::LightSkyBlue()));
		panel.Children().Append(SetColorValue(L"LightSlateGray", Colors::LightSlateGray()));
		panel.Children().Append(SetColorValue(L"LightSteelBlue", Colors::LightSteelBlue()));
		panel.Children().Append(SetColorValue(L"LightYellow", Colors::LightYellow()));
		panel.Children().Append(SetColorValue(L"Lime", Colors::Lime()));
		panel.Children().Append(SetColorValue(L"LimeGreen", Colors::LimeGreen()));
		panel.Children().Append(SetColorValue(L"Linen", Colors::Linen()));
		panel.Children().Append(SetColorValue(L"Magenta", Colors::Magenta()));
		panel.Children().Append(SetColorValue(L"Maroon", Colors::Maroon()));
		panel.Children().Append(SetColorValue(L"MediumAquamarine", Colors::MediumAquamarine()));
		panel.Children().Append(SetColorValue(L"MediumBlue", Colors::MediumBlue()));
		panel.Children().Append(SetColorValue(L"MediumOrchid", Colors::MediumOrchid()));
		panel.Children().Append(SetColorValue(L"MediumPurple", Colors::MediumPurple()));
		panel.Children().Append(SetColorValue(L"MediumSeaGreen", Colors::MediumSeaGreen()));
		panel.Children().Append(SetColorValue(L"MediumSlateBlue", Colors::MediumSlateBlue()));
		panel.Children().Append(SetColorValue(L"MediumSpringGreen", Colors::MediumSpringGreen()));
		panel.Children().Append(SetColorValue(L"MediumTurquoise", Colors::MediumTurquoise()));
		panel.Children().Append(SetColorValue(L"MediumVioletRed", Colors::MediumVioletRed()));
		panel.Children().Append(SetColorValue(L"MidnightBlue", Colors::MidnightBlue()));
		panel.Children().Append(SetColorValue(L"MintCream", Colors::MintCream()));
		panel.Children().Append(SetColorValue(L"MistyRose", Colors::MistyRose()));
		panel.Children().Append(SetColorValue(L"Moccasin", Colors::Moccasin()));
		panel.Children().Append(SetColorValue(L"NavajoWhite", Colors::NavajoWhite()));
		panel.Children().Append(SetColorValue(L"Navy", Colors::Navy()));
		panel.Children().Append(SetColorValue(L"OldLace", Colors::OldLace()));
		panel.Children().Append(SetColorValue(L"Olive", Colors::Olive()));
		panel.Children().Append(SetColorValue(L"OliveDrab", Colors::OliveDrab()));
		panel.Children().Append(SetColorValue(L"Orange", Colors::Orange()));
		panel.Children().Append(SetColorValue(L"OrangeRed", Colors::OrangeRed()));
		panel.Children().Append(SetColorValue(L"Orchid", Colors::Orchid()));
		panel.Children().Append(SetColorValue(L"PaleGoldenrod", Colors::PaleGoldenrod()));
		panel.Children().Append(SetColorValue(L"PaleGreen", Colors::PaleGreen()));
		panel.Children().Append(SetColorValue(L"PaleTurquoise", Colors::PaleTurquoise()));
		panel.Children().Append(SetColorValue(L"PaleVioletRed", Colors::PaleVioletRed()));
		panel.Children().Append(SetColorValue(L"PapayaWhip", Colors::PapayaWhip()));
		panel.Children().Append(SetColorValue(L"PeachPuff", Colors::PeachPuff()));
		panel.Children().Append(SetColorValue(L"Peru", Colors::Peru()));
		panel.Children().Append(SetColorValue(L"Pink", Colors::Pink()));
		panel.Children().Append(SetColorValue(L"Plum", Colors::Plum()));
		panel.Children().Append(SetColorValue(L"PowderBlue", Colors::PowderBlue()));
		panel.Children().Append(SetColorValue(L"Purple", Colors::Purple()));
		panel.Children().Append(SetColorValue(L"Red", Colors::Red()));
		panel.Children().Append(SetColorValue(L"RosyBrown", Colors::RosyBrown()));
		panel.Children().Append(SetColorValue(L"RoyalBlue", Colors::RoyalBlue()));
		panel.Children().Append(SetColorValue(L"SaddleBrown", Colors::SaddleBrown()));
		panel.Children().Append(SetColorValue(L"Salmon", Colors::Salmon()));
		panel.Children().Append(SetColorValue(L"SandyBrown", Colors::SandyBrown()));
		panel.Children().Append(SetColorValue(L"SeaGreen", Colors::SeaGreen()));
		panel.Children().Append(SetColorValue(L"SeaShell", Colors::SeaShell()));
		panel.Children().Append(SetColorValue(L"Sienna", Colors::Sienna()));
		panel.Children().Append(SetColorValue(L"Silver", Colors::Silver()));
		panel.Children().Append(SetColorValue(L"SkyBlue", Colors::SkyBlue()));
		panel.Children().Append(SetColorValue(L"SlateBlue", Colors::SlateBlue()));
		panel.Children().Append(SetColorValue(L"SlateGray", Colors::SlateGray()));
		panel.Children().Append(SetColorValue(L"Snow", Colors::Snow()));
		panel.Children().Append(SetColorValue(L"SpringGreen", Colors::SpringGreen()));
		panel.Children().Append(SetColorValue(L"SteelBlue", Colors::SteelBlue()));
		panel.Children().Append(SetColorValue(L"Tan", Colors::Tan()));
		panel.Children().Append(SetColorValue(L"Teal", Colors::Teal()));
		panel.Children().Append(SetColorValue(L"Thistle", Colors::Thistle()));
		panel.Children().Append(SetColorValue(L"Tomato", Colors::Tomato()));
		panel.Children().Append(SetColorValue(L"Transparent", Colors::Transparent()));
		panel.Children().Append(SetColorValue(L"Turquoise", Colors::Turquoise()));
		panel.Children().Append(SetColorValue(L"Violet", Colors::Violet()));
		panel.Children().Append(SetColorValue(L"Wheat", Colors::Wheat()));
		panel.Children().Append(SetColorValue(L"White", Colors::White()));
		panel.Children().Append(SetColorValue(L"WhiteSmoke", Colors::WhiteSmoke()));
		panel.Children().Append(SetColorValue(L"Yellow", Colors::Yellow()));
		panel.Children().Append(SetColorValue(L"YellowGreen", Colors::YellowGreen()));

		Content(outerPanel);
	}

	StackPanel ColorsPage::SetColorValue(winrt::hstring const& name, winrt::Windows::UI::Color const& color)
	{
		StackPanel panel;
		panel.Spacing(20);
		panel.Orientation(Orientation::Horizontal);

		winrt::Windows::UI::Xaml::Shapes::Rectangle rectangle;
		rectangle.VerticalAlignment(VerticalAlignment::Stretch);
		rectangle.Width(120);
		rectangle.Fill(SolidColorBrush(color));
		panel.Children().Append(rectangle);

		rectangle.ActualThemeChanged(&ColorsPage::Rectangle_ActualThemeChanged);
		rectangle.Loaded(&ColorsPage::Rectangle_Loaded);

		TextBlock textBlock;
		textBlock.Text(name);
		panel.Children().Append(textBlock);

		return panel;
	}

	void ColorsPage::Rectangle_ActualThemeChanged(winrt::Windows::UI::Xaml::FrameworkElement const& sender, winrt::Windows::Foundation::IInspectable const& args)
	{
		winrt::Windows::UI::Xaml::Shapes::Rectangle rectangle = sender.as<winrt::Windows::UI::Xaml::Shapes::Rectangle>();

		switch (sender.ActualTheme()) {
		case ElementTheme::Dark:
			rectangle.Stroke(SolidColorBrush(ColorHelper::FromArgb(0xFF, 0xFF, 0xFF, 0xFF)));
			break;

		case ElementTheme::Light:
			rectangle.Stroke(SolidColorBrush(ColorHelper::FromArgb(0xFF, 0x00, 0x00, 0x00)));
			break;
		}
	}

	void ColorsPage::Rectangle_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Xaml::Shapes::Rectangle rectangle = sender.as<winrt::Windows::UI::Xaml::Shapes::Rectangle>();

		switch (rectangle.ActualTheme()) {
		case ElementTheme::Dark:
			rectangle.Stroke(SolidColorBrush(ColorHelper::FromArgb(0xFF, 0xFF, 0xFF, 0xFF)));
			break;

		case ElementTheme::Light:
			rectangle.Stroke(SolidColorBrush(ColorHelper::FromArgb(0xFF, 0x00, 0x00, 0x00)));
			break;
		}
	}
}