#include "pch.h"

using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong
{

	NotFoundPage::NotFoundPage()
	{
		TextBlock textBlock;

		SetAsCenter(textBlock);
		textBlock.Text(L"�T���v����������܂���ł���");

		Content(textBlock);
	}
}