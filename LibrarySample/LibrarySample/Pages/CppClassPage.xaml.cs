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

                ApplyContents();
            }
        }

        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppClassPage()
        {
            this.InitializeComponent();
        }

        private async void ApplyContents()
        {
            ApplyGrammar();
            ApplyBaseClasses();
            ApplyDerivedClasses();
            ApplyInnerClasses();
            await ApplyStaticMethods();
            ApplyTypeDefinitions();
            await ApplyConstructors();
            await ApplyDestructor();
            await ApplyFields();
            await ApplyOperators();
            await ApplyMethods();
            await ApplyFriendOperators();
            await ApplyFriendFunctions();
        }

        private bool ApplySupportedVersion()
        {
            CppVersion minVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMinVersion")?.Value);
            CppVersion maxVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMaxVersion")?.Value);

            if (CppVersion < minVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = minVersion == CppVersion.MaxValue ? $"���̃N���X���g�p����ɂ�{CppVersion.MaxValue.ToString().Replace("pp", "++")}���K�v�ł�" : $"���̃N���X���g�p����ɂ�{minVersion.ToString().Replace("pp", "++")}�ȍ~���K�v�ł�";

                Content = textBlock;

                return false;
            }

            if (CppVersion < maxVersion)
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

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), LibraryType.CppLibrary, CodeLanguage.Cpp));
        }

        private void ApplyBaseClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(ContentsPanel, XElement, "BaseClasses", "���", XmlPath.CppLibraryDirectory, LibraryType.CppLibrary);
        }

        private void ApplyDerivedClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(ContentsPanel, XElement, "DerivedClasses", "�h��", XmlPath.CppLibraryDirectory, LibraryType.CppLibrary);
        }

        private void ApplyInnerClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(ContentsPanel, XElement, "InnerClasses", "�����N���X", XmlPath.CppLibraryDirectory, LibraryType.CppLibrary);
        }

        private async Task ApplyStaticMethods()
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

        private async Task ApplyConstructors()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(ContentsPanel, XElement, "Constructors", "�R���X�g���N�^�[", LibraryType.CppLibrary, Category.Constructor);
        }

        private async Task ApplyDestructor()
        {
            XElement xDestructor = XElement.Element("Destructor");

            if (xDestructor == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�f�X�g���N�^�[");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new CppFunctionExpander(xDestructor, Category.Destructor));

            await Task.Delay(1);
        }

        private async Task ApplyFields()
        {
            await LibraryPageHelper.ApplyClassMembers(ContentsPanel, XElement, "Fields", "�����o�[�ϐ�", LibraryType.CppLibrary, Category.Field);
        }

        private async Task ApplyOperators()
        {
            await LibraryPageHelper.ApplyClassMembers(ContentsPanel, XElement, "Operators", "���Z�q", LibraryType.CppLibrary, Category.Operator);
        }

        private async Task ApplyMethods()
        {
            await LibraryPageHelper.ApplyClassMembers(ContentsPanel, XElement, "Methods", "�����o�[�֐�", LibraryType.CppLibrary, Category.Method);
        }

        private async Task ApplyFriendOperators()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(ContentsPanel, XElement, "FriendOperators", "friend ���Z�q", LibraryType.CppLibrary, Category.Operator);
        }

        private async Task ApplyFriendFunctions()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(ContentsPanel, XElement, "FriendFunctions", "friend �֐�", LibraryType.CppLibrary, Category.Function);
        }
    }
}
