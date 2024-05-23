using LibrarySample.Settings;
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

namespace LibrarySample.UserControls
{
    public sealed partial class Win32HeaderButton : UserControl
    {
        public static readonly Win32HeaderButton Instance = new Win32HeaderButton(); 

        public event SelectionChangedEventHandler SelectionChanged
        {
            add => ComboBox.SelectionChanged += value;
            remove => ComboBox.SelectionChanged -= value;
        }

        private Win32HeaderButton()
        {
            this.InitializeComponent();

            ComboBox.SelectedItem = SaveData.Win32ProcesserType.ToString().ToLower();

            this.ComboBox.SelectionChanged += Win32HeaderButton_SelectionChanged;
        }

        private void Win32HeaderButton_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.Win32ProcesserType = EnumConverter.ToProcesserType((ComboBox.SelectedItem as string).ToUpper());
        }
    }
}
