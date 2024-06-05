using LibrarySample.Languages;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
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
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class CppHomePage : Page, ICppHandler
    {
        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppHomePage()
        {
            this.InitializeComponent();
            LoadLibrary();
        }

        private async void LoadLibrary()
        {
            foreach (var pair in XmlDocuments.CppLibraryDocuments)
            {
                //ÉwÉbÉ_Å[ÇÃÇ›
                if (!XmlPath.IsCppHeaderXmlFile(pair.Key)) continue;
                
                XElement xElement = pair.Value;

                ContentsPanel.Children.Add(new SlideButton(xElement, Library.Cpp));

                await Task.Delay(1);
            }
        }
    }
}
