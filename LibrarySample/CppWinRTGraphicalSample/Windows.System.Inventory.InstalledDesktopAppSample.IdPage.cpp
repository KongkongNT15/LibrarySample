#include "pch.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.IdPage.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::System::Inventory;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
    IdPage::IdPage()
    {
        InitializeComponent();
    }

    IAsyncAction IdPage::InitializeComponent()
    {
        IVectorView<InstalledDesktopApp> vec = co_await InstalledDesktopApp::GetInventoryAsync();

        StackPanel outerPanel = CreateOuterPanel();
        Content(outerPanel);

        StackPanel panel = CreateBlockPanel(L"インストールされているアプリ");
        outerPanel.Children().Append(panel);

        for (InstalledDesktopApp const& app : vec) {
            Button button;
            panel.Children().Append(button);

            button.Height(60);
            button.HorizontalAlignment(HorizontalAlignment::Stretch);
            button.VerticalContentAlignment(VerticalAlignment::Center);
            button.HorizontalContentAlignment(HorizontalAlignment::Stretch);

            StackPanel contentPanel;
            button.Content(contentPanel);

            //アプリ名
            TextBlock nameText;
            contentPanel.Children().Append(nameText);

            nameText.Text(app.DisplayName());

            //バージョン
            TextBlock versionText;
            contentPanel.Children().Append(versionText);

            versionText.Foreground(SolidColorBrush(ColorHelper::FromArgb(0xFF, 0x80, 0x80, 0x80)));
            versionText.FontSize(12);
            versionText.Text(app.Id());
        }
    }
}