#include "pch.h"
#include "event_tokenSample.event_tokenPage.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;

namespace Kongkong::event_tokenSample
{
    event_tokenPage::event_tokenPage()
    {
        StackPanel outerPanel = CreateOuterPanel();
        Content(outerPanel);

        StackPanel panel1 = CreateBlockPanel(L"イベント登録");
        outerPanel.Children().Append(panel1);

        panel1.Children().Append(_toggleSwitch);
        

        StackPanel panel2 = CreateBlockPanel(L"状態");
        outerPanel.Children().Append(panel2);

        panel2.Children().Append(_button);
        _button.Content(box_value(_count));
        _button.MinWidth(64);

        panel2.Children().Append(_stateTextBlock);

        //イベントハンドラー
        _toggleSwitch.Toggled({ this, &event_tokenPage::ToggleSwitch_Toggled });

        //後処理
        _toggleSwitch.IsOn(true);
    }

    void event_tokenPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        _button.Content(box_value(++_count));
    }

    void event_tokenPage::ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        if (_toggleSwitch.IsOn()) {
            _token = _button.Click({ this, &event_tokenPage::Button_Click });
        }
        else {
            _button.Click(_token);

            //イベントトークンを無効化
            _token.value = 0;
        }

        if ((bool)_token) {
            std::wostringstream wsout;
            wsout << L"イベントトークンは有効です" << std::endl;
            wsout << L"値: " << _token.value;
            _stateTextBlock.Text(wsout.str());
        }
        else {
            _stateTextBlock.Text(L"イベントトークンは無効です");
        }
    }
}