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
    public sealed partial class CppWinRTNamespacePage : Page, ICppWinRTHandler, IXml
    {
        public ProcesserType ProcesserType { get; } = SaveData.CppWinRTNamespaceProcesserType;

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

        public CppWinRTNamespacePage()
        {
            this.InitializeComponent();
        }

        private async void ApplyContents()
        {
            ApplyClasses();
            ApplyStructures();
            await ApplyOperators();
            await ApplyFunctions();
        }

        private void ApplyClasses()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Classes", "クラス", Library.CppWinRTNamespace, Category.Class);
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Structures", "構造体", Library.CppWinRTNamespace, Category.Structure);
        }

        private async Task ApplyOperators()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "Operators", "演算子", Library.CppWinRTNamespace, Category.Operator);
        }

        private async Task ApplyFunctions()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "Functions", "関数", Library.CppWinRTNamespace, Category.Function);
        }
    }
}
