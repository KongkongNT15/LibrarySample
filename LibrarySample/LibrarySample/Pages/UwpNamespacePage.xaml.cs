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
    public sealed partial class UwpNamespacePage : Page, IXml, IUwpHandler
    {
        public WinRTDesign Design { get; } = SaveData.UwpCodeDesign;
        public CodeLanguage CodeLanguage { get; } = SaveData.UwpCodeLanguage;
        public ProcesserType ProcesserType { get; } = SaveData.UwpProcesserType;

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

        public UwpNamespacePage()
        {
            this.InitializeComponent();
        }

        private void ApplyContents()
        {
            ApplyClasses();
            ApplyStructures();
            ApplyInterfaces();
            ApplyEnums();
        }

        private void ApplyClasses()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Classes", "クラス", Library.Uwp, Category.Class);
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Structures", "構造体", Library.Uwp, Category.Structure);
        }

        private void ApplyInterfaces()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Interfaces", "インターフェース", Library.Uwp, Category.Interface);
        }

        private void ApplyEnums()
        {
            LibraryPageHelper.ApplyClasses(RootPanel, XElement, "Enums", "列挙型", Library.Uwp, Category.Enum);
        }
    }
}
