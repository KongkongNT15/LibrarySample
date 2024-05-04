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
    public partial class SettingCard : UserControl
    {
        public string Title
        {
            get => TitleText.Text;
            set => TitleText.Text = value;
        }

        public new UIElement Content
        {
            get => ControlArea.Content;
            set => ControlArea.Content = value;
        }

        public SettingCard()
        {
            this.InitializeComponent();
            RootGrid.Padding = new Thickness(Data.ControlPaddingHeight, 0, Data.ControlPaddingHeight, 0);
            ControlArea.Margin = new Thickness(Data.ControlPaddingHeight, 0, 0, 0);
        }
    }
}
