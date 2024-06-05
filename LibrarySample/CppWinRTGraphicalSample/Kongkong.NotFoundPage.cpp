#include "pch.h"

using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong
{

	NotFoundPage::NotFoundPage()
	{
		StackPanel panel;
		TextBlock textBlock1, textBlock2;

		panel.Children().Append(textBlock1);
		panel.Children().Append(textBlock2);

		SetAsCenter(panel);
		SetAsCenter(textBlock1);
		SetAsCenter(textBlock2);

		textBlock1.Text(L"�T���v����������܂���ł���");
		textBlock2.Text(L"�ӂ��I�H����");

		Content(panel);
	}
}