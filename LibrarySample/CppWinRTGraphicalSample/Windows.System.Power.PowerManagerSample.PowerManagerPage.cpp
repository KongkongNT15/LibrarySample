#include "pch.h"
#include "Windows.System.Power.PowerManagerSample.PowerManagerPage.h"

#undef max

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::System::Power;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong::Windows::System::Power::PowerManagerSample
{
    PowerManagerPage::PowerManagerPage()
    {
        StackPanel outerPanel = CreateOuterPanel();
        Content(outerPanel);

        StackPanel panel = CreateBlockPanel(L"バッテリーの状態");
        outerPanel.Children().Append(panel);

        Grid grid;
        panel.Children().Append(grid);

        grid.HorizontalAlignment(HorizontalAlignment::Left);
        grid.ColumnDefinitions().Append(ColumnDefinition());
        grid.ColumnDefinitions().Append(ColumnDefinition());

        StackPanel leftPanel;
        grid.Children().Append(leftPanel);

        leftPanel.Spacing(8);
        leftPanel.Padding(ThicknessHelper::FromLengths(0, 0, 20, 0));
        AddText(leftPanel, L"状態: ");
        AddText(leftPanel, L"バッテリー節約機能: ");
        AddText(leftPanel, L"デバイスの電源状態: ");
        AddText(leftPanel, L"バッテリー残量: ");
        AddText(leftPanel, L"残り時間: ");

        StackPanel rightPanel;
        grid.Children().Append(rightPanel);
        Grid::SetColumn(rightPanel, 1);

        rightPanel.Spacing(8);
        rightPanel.Children().Append(_batteryStatusTextBlock);
        rightPanel.Children().Append(_energySaverStatusTextBlock);
        rightPanel.Children().Append(_powerSupplyStatusTextBlock);
        rightPanel.Children().Append(_remainingChargePercentTextBlock);
        rightPanel.Children().Append(_remainingDischargeTimeTextBlock);

        _applyBatteryStatus();
        _applyEnergySaverStatus();
        _applyPowerSupplyStatus();
        _applyRemainingChargePercent();
        _applyRemainingDischargeTime();

        PowerManager::BatteryStatusChanged({ this, &PowerManagerPage::PowerManager_BatteryStatusChanged });
        PowerManager::EnergySaverStatusChanged({ this, &PowerManagerPage::PowerManager_EnergySaverStatusChanged });
        PowerManager::PowerSupplyStatusChanged({ this, &PowerManagerPage::PowerManager_PowerSupplyStatusChanged });
        PowerManager::RemainingChargePercentChanged({ this, &PowerManagerPage::PowerManager_RemainingChargePercentChanged });
        PowerManager::RemainingDischargeTimeChanged({ this, &PowerManagerPage::PowerManager_RemainingDischargeTimeChanged });
    }

    void PowerManagerPage::_applyBatteryStatus()
    {
        switch (PowerManager::BatteryStatus()) {
        case BatteryStatus::NotPresent:
            _batteryStatusTextBlock.Text(L"バッテリーが接続されていません");
            break;

        case BatteryStatus::Discharging:
            _batteryStatusTextBlock.Text(L"放電中");
            break;

        case BatteryStatus::Idle:
            _batteryStatusTextBlock.Text(L"アイドル状態");
            break;

        case BatteryStatus::Charging:
            _batteryStatusTextBlock.Text(L"充電中");
            break;
        }
    }

    void PowerManagerPage::_applyEnergySaverStatus()
    {
        switch (PowerManager::EnergySaverStatus()) {
        case EnergySaverStatus::On:
            _energySaverStatusTextBlock.Text(L"オン");
            break;

        case EnergySaverStatus::Off:
            _energySaverStatusTextBlock.Text(L"オフ");
            break;

        case EnergySaverStatus::Disabled:
            _energySaverStatusTextBlock.Text(L"使用不可");
            break;
        }
    }

    void PowerManagerPage::_applyPowerSupplyStatus()
    {
        switch (PowerManager::PowerSupplyStatus()) {
        case PowerSupplyStatus::Adequate:
            _powerSupplyStatusTextBlock.Text(L"電源供給は十分にあります");
            break;

        case PowerSupplyStatus::Inadequate:
            _powerSupplyStatusTextBlock.Text(L"電源供給が不足しています");
            break;

        case PowerSupplyStatus::NotPresent:
            _powerSupplyStatusTextBlock.Text(L"電源が接続されていません");
            break;
        }
    }

    void PowerManagerPage::_applyRemainingChargePercent()
    {
        _remainingChargePercentTextBlock.Text(to_hstring(PowerManager::RemainingChargePercent()) + L"%");
    }

    void PowerManagerPage::_applyRemainingDischargeTime()
    {
        std::chrono::system_clock::rep date, hour, min, sec, tmp;
        std::chrono::system_clock::rep clock = PowerManager::RemainingDischargeTime().count();

        //残り時間が不明な場合は型の最大値となる
        if (clock == std::numeric_limits<std::chrono::system_clock::rep>::max()) {
            _remainingDischargeTimeTextBlock.Text(L"不明");
            return;
        }

        //1クロックが100ナノ秒なので10000000で割って秒に直す
        tmp = clock / 10000000;
        sec = tmp % 60;

        tmp /= 60;
        min = tmp % 60;

        tmp /= 60;
        hour = tmp % 24;

        tmp /= 24;
        date = tmp;

        std::wostringstream wsout;

        if (date != 0) wsout << date << L"日 ";
        if (hour != 0) wsout << hour << L"時間 ";
        if (min != 0) wsout << min << L"分 ";
        if (sec != 0) wsout << sec << L"秒";

        _remainingDischargeTimeTextBlock.Text(wsout.str());
    }

    IAsyncAction PowerManagerPage::PowerManager_BatteryStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //別スレッドで処理されるのでUIを変更する場合はDispatcherを使用
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyBatteryStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_EnergySaverStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //別スレッドで処理されるのでUIを変更する場合はDispatcherを使用
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyEnergySaverStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_PowerSupplyStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //別スレッドで処理されるのでUIを変更する場合はDispatcherを使用
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyPowerSupplyStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_RemainingChargePercentChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //別スレッドで処理されるのでUIを変更する場合はDispatcherを使用
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyRemainingChargePercent }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_RemainingDischargeTimeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //別スレッドで処理されるのでUIを変更する場合はDispatcherを使用
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyRemainingDischargeTime }
        );
    }
}