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
using System.Runtime.CompilerServices;
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
    public sealed partial class CppWinRTClassPage : Page, IXml, ICppWinRTHandler
    {
        private XElement _xElement = null;

        public ProcesserType ProcesserType { get; } = SaveData.CppWinRTNamespaceProcesserType;

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

        public CppWinRTClassPage()
        {
            this.InitializeComponent();
        }

        private async void ApplyContents()
        {
            ApplyGrammar();
            await ApplyMethods();
        }

        private void ApplyGrammar()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("ç\ï∂");
            RootPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), LibraryType.CppWinRTNamespaceLibrary, CodeLanguage.CppWinRT));
        }

        private async Task ApplyMethods()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Methods");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("ÉÅÉìÉoÅ[ä÷êî");
            RootPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppWinRTFunctionExpander(xFunction, Category.Method, true));

                await Task.Delay(1);
            }
        }
    }
}
