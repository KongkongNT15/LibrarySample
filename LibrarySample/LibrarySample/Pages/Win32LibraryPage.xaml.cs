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
    public sealed partial class Win32LibraryPage : Page, IXml, IWin32Handler
    {
        private XElement _xElement = null;
        public XElement XElement
        {
            get => _xElement;
            set
            {
                _xElement = value;
                (Frame as ContentPageFrame).AddXElement(value);
                RootPanel.Children.Clear();

                LibraryPageHelper.ApplyIncoplete(RootPanel, value);

                ApplyContents();
            }
        }

        public ProcesserType ProcesserType { get; } = SaveData.Win32ProcesserType;
        public CodeLanguage CodeLanguage { get; } = SaveData.Win32CodeLanguage;

        public Win32LibraryPage()
        {
            this.InitializeComponent();
        }

        private async void ApplyContents()
        {
            ApplyTypeDefs();
            ApplyStructures();
            await ApplyFunctions();
            await ApplyFunctionMacros();
            await ApplyMacro();
        }

        private void ApplyTypeDefs()
        {
            LibraryPageHelper.ApplyTypeDefs(RootPanel, XElement, "TypeDefinitions");
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyCStructures(RootPanel, XElement, Library.Win32);
        }

        private async Task ApplyFunctions()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "Functions", "ä÷êî", Library.Win32, Category.Function);
        }

        private async Task ApplyFunctionMacros()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "FunctionMacros", "ä÷êîÉ}ÉNÉç", Library.Win32, Category.Macro);
        }

        private async Task ApplyMacro()
        {
            await LibraryPageHelper.ApplyMacro(this, RootPanel, XElement, SampleRunner.GetWin32SampleRunner(LaunchType.Console, ProcesserType, CodeLanguage));
        }
    }
}
