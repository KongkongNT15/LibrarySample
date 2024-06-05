using LibrarySample.SampleManagement;
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
    public sealed partial class UwpHeaderButton : UserControl
    {
        public event SelectionChangedEventHandler ItemSelectionChanged
        {
            add
            {
                LanguageComboBox.SelectionChanged += value;
                DesignTypeComboBox.SelectionChanged += value;
                ProcesserTypeComboBox.SelectionChanged += value;
            }
            remove
            {
                LanguageComboBox.SelectionChanged -= value;
                DesignTypeComboBox.SelectionChanged -= value;
                ProcesserTypeComboBox.SelectionChanged -= value;
            }
        }


        public static readonly UwpHeaderButton Instance = new UwpHeaderButton();

        private UwpHeaderButton()
        {
            this.InitializeComponent();

            LanguageComboBox.SelectedIndex = SaveData.UwpCodeLanguage switch
            {
                CodeLanguage.CSharp => 0,
                CodeLanguage.CppWinRT => 1,
                _ => throw new Exception()
            };

            DesignTypeComboBox.SelectedIndex = (int)SaveData.UwpCodeDesign;

            ProcesserTypeComboBox.SelectedItem = SaveData.UwpProcesserType.ToString().ToLower();

            LanguageComboBox.SelectionChanged += LanguageComboBox_SelectionChanged;

            DesignTypeComboBox.SelectionChanged += DesignTypeComboBox_SelectionChanged;

            ProcesserTypeComboBox.SelectionChanged += ProcesserTypeComboBox_SelectionChanged;
        }

        private void LanguageComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.UwpCodeLanguage = LanguageComboBox.SelectedIndex switch
            {
                0 => CodeLanguage.CSharp,
                1 => CodeLanguage.CppWinRT,
                _ => throw new Exception(),
            };
        }

        private void DesignTypeComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.UwpCodeDesign = (WinRTDesign)DesignTypeComboBox.SelectedIndex;
        }

        private void ProcesserTypeComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SaveData.UwpProcesserType = EnumConverter.ToProcesserType((ProcesserTypeComboBox.SelectedItem as string).ToUpper());
        }
    }
}
