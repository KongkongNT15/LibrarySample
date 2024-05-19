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

                textBlock.Text = minVersion == CppVersion.MaxValue ? $"このクラスを使用するには{CppVersion.MaxValue.ToString().Replace("pp", "++")}が必要です" : $"このクラスを使用するには{minVersion.ToString().Replace("pp", "++")}以降が必要です";

                Content = textBlock;

                return false;
            }

            if (CppVersion < maxVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = $"このクラスを使用するには{maxVersion.ToString().Replace("pp", "++")}以前が必要です";

                Content = textBlock;

                return false;
            }

            return true;
        }

        private void ApplyGrammar()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("構文");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new GrammarExpander(XElement.Element("Grammar"), CodeLanguage.Cpp));
        }

        private void ApplyBaseClasses()
        {
            LibraryPageHelper.ApplyCppBaseOrDerivedClasses(ContentsPanel, XElement, "BaseClasses", "基底");
        }

        private void ApplyDerivedClasses()
        {
            LibraryPageHelper.ApplyCppBaseOrDerivedClasses(ContentsPanel, XElement, "DerivedClasses", "派生");
        }

        private void ApplyInnerClasses()
        {
            LibraryPageHelper.ApplyCppBaseOrDerivedClasses(ContentsPanel, XElement, "InnerClasses", "内部クラス");
        }

        private async Task ApplyStaticMethods()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "StaticMethods");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("静的メンバー関数");
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
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "Constructors", "コンストラクター", Category.Constructor);
        }

        private async Task ApplyDestructor()
        {
            XElement xDestructor = XElement.Element("Destructor");

            if (xDestructor == null) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("デストラクター");
            ContentsPanel.Children.Add(panel);

            panel.Children.Add(new CppFunctionExpander(xDestructor, Category.Destructor));

            await Task.Delay(1);
        }

        private async Task ApplyFields()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Fields");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("メンバー変数");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Field));

                await Task.Delay(1);
            }
        }

        private async Task ApplyOperators()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Operators");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("演算子");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Operator));

                await Task.Delay(1);
            }
        }

        private async Task ApplyMethods()
        {
            List<XElement> xFunctions = new List<XElement>();

            await LibraryPageHelper.GetBaseClassFunctionsAsync(xFunctions, XElement, "Methods");

            if (xFunctions.Count == 0) return;

            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("メンバー関数");
            ContentsPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions)
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, Category.Method));

                await Task.Delay(1);
            }

        }

        private async Task ApplyFriendOperators()
        {
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "FriendOperators", "friend 演算子", Category.Operator);
        }

        private async Task ApplyFriendFunctions()
        {
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "FriendFunctions", "friend 関数", Category.Function);
        }
    }
}
