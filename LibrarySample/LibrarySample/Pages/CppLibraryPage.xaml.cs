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
    public sealed partial class CppLibraryPage : Page, IXml, ICppHandler
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
                ApplyTypeDefs();
                ApplyConcepts();
                ApplyClasses();
                ApplyStructures();
                ApplyOperators();
                ApplyFunctions();
            }
        }

        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppLibraryPage()
        {
            this.InitializeComponent();
        }

        

        private void ApplyTypeDefs()
        {
            LibraryPageHelper.ApplyTypeDefs(ContentsPanel, XElement, "TypeDefinitions");
        }

        private async void ApplyConcepts()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Concepts", "�R���Z�v�g", Category.Concept);
        }

        private void ApplyClasses()
        {
            LibraryPageHelper.ApplyClasses(ContentsPanel, XElement, "Classes", "�N���X", XmlPath.CppLibraryDirectory, CodeLanguage.Cpp, Category.Class);
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyClasses(ContentsPanel, XElement, "Structures", "�\����", XmlPath.CppLibraryDirectory, CodeLanguage.Cpp, Category.Class);
        }

        private async void ApplyOperators()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Operators", "���Z�q", Category.Operator);
        }

        private async void ApplyFunctions()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Functions", "�֐�", Category.Function);
        }

    }
}
