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
    public sealed partial class LinkCard : UserControl
    {
        public string Title
        {
            get => LinkButton.Content as string;
            set => LinkButton.Content = value;
        }

        public Uri NavigateUri
        {
            get => LinkButton.NavigateUri;
            set => LinkButton.NavigateUri = value;
        }

        public LinkCard()
        {
            this.InitializeComponent();

            RootGrid.Padding = new Thickness(Data.ControlPaddingHeight - 10.0, 0, Data.ControlPaddingHeight, 0);
        }
    }
}
