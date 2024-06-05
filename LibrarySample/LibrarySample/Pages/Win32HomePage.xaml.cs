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

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class Win32HomePage : Page, IWin32Handler
    {
        public ProcesserType ProcesserType { get; } = SaveData.Win32ProcesserType;

        public Win32HomePage()
        {
            this.InitializeComponent();
            LoadLibrary();
        }

        private async void LoadLibrary()
        {
            await HomePageHelper.LoadLibrary(RootPanel, Library.Win32, XmlPath.Win32LibraryDirectory);
        }
    }
}
