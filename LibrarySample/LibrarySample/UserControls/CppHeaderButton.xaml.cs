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
    public sealed partial class CppHeaderButton : UserControl
    {
        public static CppHeaderButton Instance { get; } = new CppHeaderButton();

        public event SelectionChangedEventHandler ItemSelectionChanged
        {
            add
            {
                CppVersionComboBox.SelectionChanged += value;
                CppProcesserTypeComboBox.SelectionChanged += value;
            }
            remove
            {
                CppVersionComboBox.SelectionChanged -= value;
                CppProcesserTypeComboBox.SelectionChanged -= value;
            }
        }

        private CppHeaderButton()
        {
            this.InitializeComponent();

            CppVersionComboBox.SelectedItem = SaveData.CppVersion.ToString().Replace("pp", "++");
            CppProcesserTypeComboBox.SelectedItem = SaveData.CppProcesserType.ToString().ToLower();

            CppVersionComboBox.SelectionChanged += CppVersionComboBox_SelectionChanged;
            CppProcesserTypeComboBox.SelectionChanged += CppProcesserTypeComboBox_SelectionChanged;
        }

        private void CppVersionComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.CppVersion = EnumConverter.ToCppVersion((CppVersionComboBox.SelectedItem as string).Replace("++", "pp"));
        }

        private void CppProcesserTypeComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.CppProcesserType = EnumConverter.ToProcesserType((CppProcesserTypeComboBox.SelectedItem as string).ToUpper());
        }
    }
}
