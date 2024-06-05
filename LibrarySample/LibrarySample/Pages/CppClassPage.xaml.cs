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
                RootPanel.Children.Clear();

                if (!ApplySupportedVersion()) return;

                LibraryPageHelper.ApplyIncoplete(RootPanel, value);

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
            RootPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), Library.Cpp, CodeLanguage.Cpp));
        }

        private void ApplyBaseClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, XElement, "BaseClasses", "���", Library.Cpp);
        }

        private void ApplyDerivedClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, XElement, "DerivedClasses", "�h��", Library.Cpp);
        }

        private void ApplyInnerClasses()
        {
            LibraryPageHelper.ApplyBaseOrDerivedClasses(RootPanel, XElement, "InnerClasses", "�����N���X", Library.Cpp);
        }

        private async Task ApplyStaticMethods()
        {
            await LibraryPageHelper.ApplyClassMembersAsync(RootPanel, XElement, "StaticMethods", "�ÓI�����o�[�֐�", Library.Cpp, Category.Method);
        }

        private void ApplyTypeDefinitions()
        {
            LibraryPageHelper.ApplyTypeDefs(RootPanel, XElement, "TypeDefinitions");
        }

        private async Task ApplyConstructors()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "Constructors", "�R���X�g���N�^�[", Library.Cpp, Category.Constructor);
        }

        private async Task ApplyDestructor()
        {
            XElement xDestructor = XElement.Element("Destructor");

            if (xDestructor == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("�f�X�g���N�^�[");
            RootPanel.Children.Add(panel);

            panel.Children.Add(new CppFunctionExpander(xDestructor, Category.Destructor));

            await Task.Delay(1);
        }

        private async Task ApplyFields()
        {
            await LibraryPageHelper.ApplyClassMembersAsync(RootPanel, XElement, "Fields", "�����o�[�ϐ�", Library.Cpp, Category.Field);
        }

        private async Task ApplyOperators()
        {
            await LibraryPageHelper.ApplyClassMembersAsync(RootPanel, XElement, "Operators", "���Z�q", Library.Cpp, Category.Operator);
        }

        private async Task ApplyMethods()
        {
            await LibraryPageHelper.ApplyClassMembersAsync(RootPanel, XElement, "Methods", "�����o�[�֐�", Library.Cpp, Category.Method);
        }

        private async Task ApplyFriendOperators()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "FriendOperators", "friend ���Z�q", Library.Cpp, Category.Operator);
        }

        private async Task ApplyFriendFunctions()
        {
            await LibraryPageHelper.ApplyFunctionsAsync(RootPanel, XElement, "FriendFunctions", "friend �֐�", Library.Cpp, Category.Function);
        }
    }
}
