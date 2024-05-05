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
    public sealed partial class CppClassPage : Page, IXml, ICppHandler
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
                ApplyGrammar();
                ApplyStaticMethods();
                ApplyTypeDefinitions();
                ApplyConstructors();
                ApplyDestructor();
                ApplyOperators();
                ApplyMethods();
            }
        }

        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppClassPage()
        {
            this.InitializeComponent();
        }

        private void ApplyGrammar()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�\��");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), CodeLanguage.Cpp));
        }

        private async void ApplyStaticMethods()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "StaticMethods", "�ÓI�����o�[�֐�", Category.Method);
        }

        private void ApplyTypeDefinitions()
        {
            LibraryPageHelper.ApplyTypeDefs(ContentsPanel, XElement, "TypeDefinitions");
        }

        private async void ApplyConstructors()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Constructors", "�R���X�g���N�^�[", Category.Constructor);
        }

        private async void ApplyDestructor()
        {
            XElement xDestructor = XElement.Element("Destructor");

            if (xDestructor == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�f�X�g���N�^�[");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new CppFunctionExpander(xDestructor, Category.Destructor));

            await Task.Delay(1);
        }

        private async void ApplyOperators()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Operators", "���Z�q", Category.Operator);
        }

        private async void ApplyMethods()
        {
            await LibraryPageHelper.ApplyCppFunctions(ContentsPanel, XElement, "Methods", "�����o�[�֐�", Category.Method);
        }
    }
}
