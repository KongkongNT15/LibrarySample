#include "pch.h"

using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong
{

	NotFoundPage::NotFoundPage()
	{
		TextBlock textBlock;

		SetAsCenter(textBlock);
		textBlock.Text(L"ƒTƒ“ƒvƒ‹‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½");

		Content(textBlock);
	}
}