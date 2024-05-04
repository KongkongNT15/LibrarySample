using LibrarySample.Languages;
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
    public sealed partial class CHeaderButton : UserControl
    {
        public static CHeaderButton Instance { get; } = new CHeaderButton();

        public event SelectionChangedEventHandler ItemSelectionChanged
        {
            add
            {
                CVersionComboBox.SelectionChanged += value;
                CProcesserTypeComboBox.SelectionChanged += value;
            }
            remove
            {
                CVersionComboBox.SelectionChanged -= value;
                CProcesserTypeComboBox.SelectionChanged -= value;
            }
        }

        private CHeaderButton()
        {
            this.InitializeComponent();

            CVersionComboBox.SelectedItem = SaveData.CVersion.ToString();
            CProcesserTypeComboBox.SelectedItem = SaveData.CProcesserType.ToString().ToLower();

            CVersionComboBox.SelectionChanged += CVersionComboBox_SelectionChanged;
            CProcesserTypeComboBox.SelectionChanged += CProcesserTypeComboBox_SelectionChanged;
        }

        private void CVersionComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.CVersion = EnumConverter.ToCLanguage(CVersionComboBox.SelectedItem as string);
        }

        private void CProcesserTypeComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.CProcesserType = EnumConverter.ToProcesserType((CProcesserTypeComboBox.SelectedItem as string).ToUpper());
        }
    }
}
