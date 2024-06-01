using LibrarySample.SampleManagement;
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
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Settings
{
    public sealed partial class AppInfoCard : UserControl
    {
        public AppInfoCard()
        {
            this.InitializeComponent();

            XElement xReleaseNotes = XElement.Load(XmlPath.ReleaseNoteFilePath);

            var elements = xReleaseNotes.Elements();
            var xReleaseNote = elements.Last();

            ReleaseInfo releaseInfo = new ReleaseInfo(xReleaseNote);

            TitleText.Text = "Library Sample";
            DescriptionText.Text = $"{releaseInfo.VersionText}  {releaseInfo.DateText}";
        }
    }
}
