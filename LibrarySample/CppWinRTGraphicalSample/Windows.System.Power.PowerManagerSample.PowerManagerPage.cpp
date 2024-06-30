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

        StackPanel panel = CreateBlockPanel(L"�o�b�e���[�̏��");
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
        AddText(leftPanel, L"���: ");
        AddText(leftPanel, L"�o�b�e���[�ߖ�@�\: ");
        AddText(leftPanel, L"�f�o�C�X�̓d�����: ");
        AddText(leftPanel, L"�o�b�e���[�c��: ");
        AddText(leftPanel, L"�c�莞��: ");

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
            _batteryStatusTextBlock.Text(L"�o�b�e���[���ڑ�����Ă��܂���");
            break;

        case BatteryStatus::Discharging:
            _batteryStatusTextBlock.Text(L"���d��");
            break;

        case BatteryStatus::Idle:
            _batteryStatusTextBlock.Text(L"�A�C�h�����");
            break;

        case BatteryStatus::Charging:
            _batteryStatusTextBlock.Text(L"�[�d��");
            break;
        }
    }

    void PowerManagerPage::_applyEnergySaverStatus()
    {
        switch (PowerManager::EnergySaverStatus()) {
        case EnergySaverStatus::On:
            _energySaverStatusTextBlock.Text(L"�I��");
            break;

        case EnergySaverStatus::Off:
            _energySaverStatusTextBlock.Text(L"�I�t");
            break;

        case EnergySaverStatus::Disabled:
            _energySaverStatusTextBlock.Text(L"�g�p�s��");
            break;
        }
    }

    void PowerManagerPage::_applyPowerSupplyStatus()
    {
        switch (PowerManager::PowerSupplyStatus()) {
        case PowerSupplyStatus::Adequate:
            _powerSupplyStatusTextBlock.Text(L"�d�������͏\���ɂ���܂�");
            break;

        case PowerSupplyStatus::Inadequate:
            _powerSupplyStatusTextBlock.Text(L"�d���������s�����Ă��܂�");
            break;

        case PowerSupplyStatus::NotPresent:
            _powerSupplyStatusTextBlock.Text(L"�d�����ڑ�����Ă��܂���");
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

        //�c�莞�Ԃ��s���ȏꍇ�͌^�̍ő�l�ƂȂ�
        if (clock == std::numeric_limits<std::chrono::system_clock::rep>::max()) {
            _remainingDischargeTimeTextBlock.Text(L"�s��");
            return;
        }

        //1�N���b�N��100�i�m�b�Ȃ̂�10000000�Ŋ����ĕb�ɒ���
        tmp = clock / 10000000;
        sec = tmp % 60;

        tmp /= 60;
        min = tmp % 60;

        tmp /= 60;
        hour = tmp % 24;

        tmp /= 24;
        date = tmp;

        std::wostringstream wsout;

        if (date != 0) wsout << date << L"�� ";
        if (hour != 0) wsout << hour << L"���� ";
        if (min != 0) wsout << min << L"�� ";
        if (sec != 0) wsout << sec << L"�b";

        _remainingDischargeTimeTextBlock.Text(wsout.str());
    }

    IAsyncAction PowerManagerPage::PowerManager_BatteryStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //�ʃX���b�h�ŏ��������̂�UI��ύX����ꍇ��Dispatcher���g�p
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyBatteryStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_EnergySaverStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //�ʃX���b�h�ŏ��������̂�UI��ύX����ꍇ��Dispatcher���g�p
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyEnergySaverStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_PowerSupplyStatusChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //�ʃX���b�h�ŏ��������̂�UI��ύX����ꍇ��Dispatcher���g�p
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyPowerSupplyStatus }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_RemainingChargePercentChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //�ʃX���b�h�ŏ��������̂�UI��ύX����ꍇ��Dispatcher���g�p
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyRemainingChargePercent }
        );
    }

    IAsyncAction PowerManagerPage::PowerManager_RemainingDischargeTimeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& args)
    {
        //�ʃX���b�h�ŏ��������̂�UI��ύX����ꍇ��Dispatcher���g�p
        co_await PageViewer().Dispatcher().RunAsync(
            CoreDispatcherPriority::Normal,
            { this, &PowerManagerPage::_applyRemainingDischargeTime }
        );
    }
}