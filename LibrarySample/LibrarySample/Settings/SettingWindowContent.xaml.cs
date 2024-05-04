using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Settings
{
    public sealed partial class SettingWindowContent : UserControl
    {
        public static SettingWindowContent Instance { get; } = new SettingWindowContent();

        private SettingWindowContent()
        {
            this.InitializeComponent();

            NavViewContent.Margin = new Thickness(0, Data.NavigationViewContentPadding, 0, 0);

            NavView.SelectedItem = NavView.MenuItems[0];
        }

        private void SetNavViewContent(NavigationViewItem navigationViewItem)
        {
            string headerName = navigationViewItem.Content as string;
            NavView.Header = headerName;

            switch (headerName)
            {
                case "設定": NavViewContent.Content = SettingPage.Instance; break;
                case "アプリについて": NavViewContent.Content = AboutAppPage.Instance; break;
                case "更新履歴": NavViewContent.Content = VersionInfoPage.Instance; break;

            }
        }

        private void NavView_SelectionChanged(NavigationView sender, NavigationViewSelectionChangedEventArgs args)
        {
            SetNavViewContent(sender.SelectedItem as NavigationViewItem);
        }
    }
}
