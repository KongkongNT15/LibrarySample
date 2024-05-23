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
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class CppWinRTNamespaceHeaderButton : UserControl
    {
        public static readonly CppWinRTNamespaceHeaderButton Instance = new CppWinRTNamespaceHeaderButton();

        public event SelectionChangedEventHandler SelectionChanged
        {
            add => ComboBox.SelectionChanged += value;
            remove => ComboBox.SelectionChanged -= value;
        }

        private CppWinRTNamespaceHeaderButton()
        {
            this.InitializeComponent();

            ComboBox.SelectedItem = SaveData.CppWinRTNamespaceProcesserType.ToString().ToLower();

            this.ComboBox.SelectionChanged += CppWinRTNamespaceHeaderButton_SelectionChanged;
        }

        private void CppWinRTNamespaceHeaderButton_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.CppWinRTNamespaceProcesserType = EnumConverter.ToProcesserType((ComboBox.SelectedItem as string).ToUpper());
        }
    }
}
