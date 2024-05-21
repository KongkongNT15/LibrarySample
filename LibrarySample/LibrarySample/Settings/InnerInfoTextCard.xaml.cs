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
    public sealed partial class InnerInfoTextCard : UserControl
    {
        private static readonly Thickness IsFrontThickness = new Thickness(0);
        private static readonly Thickness IsNotFrontThickness = new Thickness(0, 1, 0, 0);


        public string Title
        {
            get => TitleText.Text;
            set => TitleText.Text = value;
        }

        public string Value
        {
            get => ValueText.Text;
            set => ValueText.Text = value;
        }

        public bool IsFront
        {
            get => RootGrid.BorderThickness == IsFrontThickness;
            set => RootGrid.BorderThickness = value ? IsFrontThickness : IsNotFrontThickness;
        }

        public InnerInfoTextCard()
        {
            this.InitializeComponent();
            RootGrid.Padding = new Thickness(Data.ControlPaddingHeight, 0, Data.ControlPaddingHeight, 0);
        }
    }
}
