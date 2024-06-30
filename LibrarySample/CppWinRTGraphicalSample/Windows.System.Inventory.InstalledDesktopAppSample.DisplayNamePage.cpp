#include "pch.h"
#include "Windows.System.Inventory.InstalledDesktopAppSample.DisplayNamePage.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::System::Inventory;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;


namespace Kongkong::Windows::System::Inventory::InstalledDesktopAppSample
{
    DisplayNamePage::DisplayNamePage()
    {
        InitializeComponent();
    }

    IAsyncAction DisplayNamePage::InitializeComponent()
    {
        IVectorView<InstalledDesktopApp> vec = co_await InstalledDesktopApp::GetInventoryAsync();

        StackPanel outerPanel = CreateOuterPanel();
        Content(outerPanel);

        StackPanel panel = CreateBlockPanel(L"インストールされているアプリ");
        outerPanel.Children().Append(panel);

        for (InstalledDesktopApp const& app : vec) {
            Button button;
            panel.Children().Append(button);

            button.Height(48);
            button.HorizontalAlignment(HorizontalAlignment::Stretch);
            button.VerticalContentAlignment(VerticalAlignment::Center);
            button.HorizontalContentAlignment(HorizontalAlignment::Stretch);

            TextBlock nameText;
            button.Content(nameText);

            //アプリ名
            nameText.Text(app.DisplayName());
        }
    }
}