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
    public sealed partial class ValueCard : UserControl
    {
        public string Title
        {
            get => TitleText.Text;
            set => TitleText.Text = value;
        }

        public string Description
        {
            get => DescriptionText.Text;
            set => DescriptionText.Text = value;
        }

        public string Value
        {
            get => ValueText.Text;
            set => ValueText.Text = value;
        }

        public string Glyph
        {
            get => FIcon.Glyph;
            set => FIcon.Glyph = value;
        }

        public bool IsTitleTextSelectionEnabled
        {
            get => TitleText.IsTextSelectionEnabled;
            set => TitleText.IsTextSelectionEnabled = value;
        }

        public bool IsDescriptionTextSelectionEnabled
        {
            get => DescriptionText.IsTextSelectionEnabled;
            set => DescriptionText.IsTextSelectionEnabled = value;
        }

        public bool IsValueTextSelectionEnabled
        {
            get => ValueText.IsTextSelectionEnabled;
            set => ValueText.IsTextSelectionEnabled = value;
        }

        public ValueCard()
        {
            this.InitializeComponent();
            ValueText.Margin = new Thickness(Data.ControlPaddingHeight, 0, Data.ControlPaddingHeight, 0);
        }
    }
}
