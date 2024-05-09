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

                if (!ApplySupportedVersion()) return;

                LibraryPageHelper.ApplyIncoplete(ContentsPanel, value);
                ApplyGrammar();
                ApplyBaseClasses();
                ApplyDerivedClasses();
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

        private bool ApplySupportedVersion()
        {
            CppVersion minVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMinVersion")?.Value);
            CppVersion maxVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMaxVersion")?.Value);

            if (SaveData.CppVersion < minVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = minVersion == CppVersion.MaxValue ? $"���̃N���X���g�p����ɂ�{CppVersion.MaxValue.ToString().Replace("pp", "++")}���K�v�ł�" : $"���̃N���X���g�p����ɂ�{minVersion.ToString().Replace("pp", "++")}�ȍ~���K�v�ł�";

                Content = textBlock;

                return false;
            }

            if (SaveData.CppVersion < maxVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = $"���̃N���X���g�p����ɂ�{maxVersion.ToString().Replace("pp", "++")}�ȑO���K�v�ł�";

                Content = textBlock;

                return false;
            }

            return true;
        }

        private void ApplyGrammar()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�\��");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), CodeLanguage.Cpp));
        }

        private void ApplyBaseClasses()
        {
            XElement xBaseClasses = XElement.Element("BaseClasses");

            if (xBaseClasses == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("���");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xReference in xBaseClasses.Elements())
            {
                string fileName = xReference.Attribute("FileName").Value;

                XElement xClass = XElement.Load(XmlPath.CppLibraryDirectory + fileName);

                panel.Children.Add(new SlideButton(xClass, CodeLanguage.Cpp) { Glyph = EnumConverter.ToGlyph(Category.Class) });
            }
        }

        private void ApplyDerivedClasses()
        {
            XElement xDerivedClasses = XElement.Element("DerivedClasses");

            if (xDerivedClasses == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�h��");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xReference in xDerivedClasses.Elements())
            {
                string fileName = xReference.Attribute("FileName").Value;

                XElement xClass = XElement.Load(XmlPath.CppLibraryDirectory + fileName);

                panel.Children.Add(new SlideButton(xClass, CodeLanguage.Cpp) { Glyph = EnumConverter.ToGlyph(Category.Class) });
            }
        }

        private async void ApplyStaticMethods()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "StaticMethods");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�ÓI�����o�[�֐�");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Method));

                await Task.Delay(1);
            }
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
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Operators");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("���Z�q");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Operator));

                await Task.Delay(1);
            }
        }

        private async void ApplyMethods()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Methods");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�����o�[�֐�");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Method));

                await Task.Delay(1);
            }

        }
    }
}
