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
using Windows.ApplicationModel.Contacts;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class CLibraryPage : Page, IXml, ICHandler
    {
        private XElement _xElement = null;
        public XElement XElement
        {
            get => _xElement;
            set
            {
                _xElement = value;
                (Frame as ContentPageFrame).AddXElement(value);
                ContentsPanel.Children.Clear();

                LibraryPageHelper.ApplyIncoplete(ContentsPanel, value);
                
                ApplyContents();
            }
        }

        public CVersion CVersion { get; } = SaveData.CVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CProcesserType;

        public CLibraryPage()
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
            LibraryPageHelper.ApplyTypeDefs(ContentsPanel, XElement, "TypeDefinitions");
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyCStructures(ContentsPanel, XElement, Library.C);
        }

        private async Task ApplyFunctions()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(ContentsPanel, XElement, "Functions", "ä÷êî", Library.C, Category.Function);
        }

        private async Task ApplyFunctionMacros()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(ContentsPanel, XElement, "FunctionMacros", "ä÷êîÉ}ÉNÉç", Library.C, Category.FunctionMacro);
        }

        private async Task ApplyMacro()
        {
            await LibraryPageHelper.ApplyMacro(this, ContentsPanel, XElement, SampleRunner.GetCSampleRunner(CVersion, ProcesserType));
        }

    }
}
