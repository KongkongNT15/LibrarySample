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
    public sealed partial class ConsolePane : UserControl
    {
        public string Output
        {
            get => OutputText.Text;
            set => OutputText.Text = value;
        }

        public void SetAsWaiting()
        {
            OutputText.Text = "‚¨‘Ò‚¿‚­‚¾‚³‚¢...";
        }

        public ConsolePane()
        {
            this.InitializeComponent();
            RootViewer.Padding = new Thickness(Data.ControlPaddingHeight, Data.ControlPaddingHeight - 4.0, Data.ControlPaddingHeight, Data.ControlPaddingHeight - 4.0);
        }
    }
}
