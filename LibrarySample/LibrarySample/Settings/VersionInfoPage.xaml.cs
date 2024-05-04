using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System.Xml.Linq;
using System.Threading.Tasks;
using LibrarySample.UserControls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Settings
{
    public sealed partial class VersionInfoPage : ScrollableControl
    {
        public static VersionInfoPage Instance { get; } = new VersionInfoPage();

        private VersionInfoPage()
        {
            this.InitializeComponent();

            SetReleaseNote();
        }

        private async void SetReleaseNote()
        {
            
            foreach (XElement xReleaseNote in XElement.Load(XmlPath.ReleaseNoteFilePath).Elements())
            {
                RootPanel.Children.Add(new VersionInfoExpander(xReleaseNote));
                await Task.Delay(1);
            }
        }
    }
}
