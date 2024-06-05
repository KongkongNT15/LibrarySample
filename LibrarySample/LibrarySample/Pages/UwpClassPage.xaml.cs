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
    public sealed partial class UwpClassPage : Page, IXml, IUwpHandler
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

                if (!ApplySupportedLanguage())
                {
                    string name = CodeLanguage == CodeLanguage.CppWinRT ? "C#" : "C++/WinRT";
                    Content = new TextBlock
                    {
                        Text = $"���̌^��{name}�ł̂ݎg�p�ł��܂�",
                        HorizontalAlignment = HorizontalAlignment.Center,
                        VerticalAlignment = VerticalAlignment.Center,
                    };
                    return;
                }

                LibraryPageHelper.ApplyIncoplete(RootPanel, value);

                ApplyContents();
            }
        }

        public UwpClassPage()
        {
            this.InitializeComponent();
        }

        private bool ApplySupportedLanguage()
        {
            XAttribute xTargetLanguage = XElement.Attribute("TargetLanguage");

            if (xTargetLanguage == null) return true;

            if (xTargetLanguage.Value == "Both") return true;

            CodeLanguage codeLanguage = EnumConverter.ToCodeLanguage(xTargetLanguage.Value);

            return codeLanguage == CodeLanguage;
        }

        private async void ApplyContents()
        {
            ApplyGrammar();
            ApplyBaseClasses();
            ApplyImplements();
            ApplyDerivedClasses();
            await ApplyStaticMethods();
            await ApplyConstructors();
            await ApplyFields();
            await ApplyProperties();
            await ApplyOperators();
            await ApplyMethods();
        }

        private void ApplyGrammar()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�\��");
            RootPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), Library.Uwp, CodeLanguage));
        }

        private void ApplyBaseClasses()
        {
            XElement xBaseClasses = XElement.Element("BaseClasses");
            if (xBaseClasses == null) return;

            XElement xClasses = CodeLanguage == CodeLanguage.CppWinRT ? xBaseClasses.Element("CppWinRTClass") : xBaseClasses.Element("CSharpClass");
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, xClasses, "���N���X", Library.Uwp);
        }

        private void ApplyImplements()
        {
            XElement xBaseClasses = XElement.Element("Implements");
            if (xBaseClasses == null) return;

            XElement xClasses = CodeLanguage == CodeLanguage.CppWinRT ? xBaseClasses.Element("CppWinRTClass") : xBaseClasses.Element("CSharpClass");
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, xClasses, "����", Library.Uwp);
        }

        private void ApplyDerivedClasses()
        {
            XElement xBaseClasses = XElement.Element("DerivedClasses");
            if (xBaseClasses == null) return;

            XElement xClasses = CodeLanguage == CodeLanguage.CppWinRT ? xBaseClasses.Element("CppWinRTClass") : xBaseClasses.Element("CSharpClass");
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, xClasses, "�h���N���X", Library.Uwp);
        }

        private async Task ApplyStaticMethods()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "StaticMethods", "�ÓI���\�b�h", Library.Uwp, Category.Method);
        }

        private async Task ApplyConstructors()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "Constructors", "�R���X�g���N�^�[", Library.Uwp, Category.Constructor);
        }

        private async Task ApplyFields()
        {
            await LibraryPageHelper.ApplyClassMembersWinRTAsync(RootPanel, XElement, "Fields", "�t�B�[���h", Library.Uwp, Category.Field, CodeLanguage);
        }

        private async Task ApplyProperties()
        {
            await LibraryPageHelper.ApplyClassMembersWinRTAsync(RootPanel, XElement, "Properties", "�v���p�e�B", Library.Uwp, Category.Property, CodeLanguage);
        }

        private async Task ApplyOperators()
        {
            await LibraryPageHelper.ApplyClassMembersWinRTAsync(RootPanel, XElement, "Operators", "���Z�q", Library.Uwp, Category.Operator, CodeLanguage);
        }

        private async Task ApplyMethods()
        {
            await LibraryPageHelper.ApplyClassMembersWinRTAsync(RootPanel, XElement, "Methods", "���\�b�h", Library.Uwp, Category.Method, CodeLanguage);
        }
    }
}
