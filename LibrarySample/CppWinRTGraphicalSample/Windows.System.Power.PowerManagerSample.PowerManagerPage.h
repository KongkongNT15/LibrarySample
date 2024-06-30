#pragma once

namespace Kongkong::Windows::System::Power::PowerManagerSample
{
	struct PowerManagerPage : public SamplePage {
		PowerManagerPage();

	private:

		winrt::Windows::UI::Xaml::Controls::TextBlock _batteryStatusTextBlock;
		winrt::Windows::UI::Xaml::Controls::TextBlock _energySaverStatusTextBlock;
		winrt::Windows::UI::Xaml::Controls::TextBlock _powerSupplyStatusTextBlock;
		winrt::Windows::UI::Xaml::Controls::TextBlock _remainingChargePercentTextBlock;
		winrt::Windows::UI::Xaml::Controls::TextBlock _remainingDischargeTimeTextBlock;

		void _applyBatteryStatus();
		void _applyEnergySaverStatus();
		void _applyPowerSupplyStatus();
		void _applyRemainingChargePercent();
		void _applyRemainingDischargeTime();

		winrt::Windows::Foundation::IAsyncAction PowerManager_BatteryStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args);
		winrt::Windows::Foundation::IAsyncAction PowerManager_EnergySaverStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args);
		winrt::Windows::Foundation::IAsyncAction PowerManager_PowerSupplyStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args);
		winrt::Windows::Foundation::IAsyncAction PowerManager_RemainingChargePercentChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args);
		winrt::Windows::Foundation::IAsyncAction PowerManager_RemainingDischargeTimeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args);
	};
}