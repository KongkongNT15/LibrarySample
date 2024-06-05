#include "pch.h"
#include "Windows.System.Display.DisplayRequestSample.DisplayRequestPage.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong::Windows::System::Display::DisplayRequestSample
{
	DisplayRequestPage::DisplayRequestPage()
	{
		SetAsCenter(RequestToggleSwitch);
		RequestToggleSwitch.Header(box_value(L"�\���v��"));

		Content(RequestToggleSwitch);

		RequestToggleSwitch.Toggled({ this, &DisplayRequestPage::RequestToggleSwitch_Toggled });
	}

	void DisplayRequestPage::RequestToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		if (RequestToggleSwitch.IsOn()) {
			Request.RequestActive();
		}
		else {
			//RequestActive()�ƌĂԑO��RequestRelease()���ĂԂƗ�O���X���[�����
			Request.RequestRelease();
		}

	}
}