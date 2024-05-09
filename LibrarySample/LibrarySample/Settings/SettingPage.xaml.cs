using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using LibrarySample.UserControls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Settings
{
    public sealed partial class SettingPage : ScrollableControl
    {
        public static SettingPage Instance { get; } = new SettingPage();

        private SettingPage()
        {
            this.InitializeComponent();

            RootPanel.Padding = new Thickness(0, 0, 0, Data.NavigationViewContentPadding);

            WaitTimeNumberBox.Value = SaveData.WaitTime;
            ThemeComboBox.SelectedIndex = (int)SaveData.RequestedTheme;

            WaitTimeNumberBox.ValueChanged += WaitTimeNumberBox_ValueChanged;
            ThemeComboBox.SelectionChanged += ThemeComboBox_SelectionChanged;
        }

        private void WaitTimeNumberBox_ValueChanged(NumberBox sender, NumberBoxValueChangedEventArgs args)
        {
            SaveData.WaitTime = (uint)WaitTimeNumberBox.Value;
        }

        private void ThemeComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.RequestedTheme = (ElementTheme)ThemeComboBox.SelectedIndex;
        }
    }
}
