using LibrarySample.UserControls;
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
    public sealed partial class AboutAppPage : ScrollableControl
    {
        public static AboutAppPage Instance { get; } = new AboutAppPage();

        private AboutAppPage()
        {
            this.InitializeComponent();
            RootPanel.Padding = new Thickness(0, 0, 0, Data.NavigationViewContentPadding);
        }
    }
}
