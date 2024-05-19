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

                if (!ApplySupportedVersion()) return;

                LibraryPageHelper.ApplyIncoplete(ContentsPanel, value);

                ApplyContents();
            }
        }

        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppLibraryPage()
        {
            this.InitializeComponent();
        }

        private async void ApplyContents()
        {
            ApplyTypeDefs();
            await ApplyConcepts();
            ApplyClasses();
            ApplyStructures();
            ApplyEnums();
            await ApplyOperators();
            await ApplyFunctions();
        }

        private bool ApplySupportedVersion()
        {
            CppVersion minVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMinVersion")?.Value);
            CppVersion maxVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMaxVersion")?.Value);

            if (SaveData.CppVersion < minVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = minVersion == CppVersion.MaxValue ? $"このヘッダーを使用するには{CppVersion.MaxValue.ToString().Replace("pp", "++")}が必要です" : $"このヘッダーを使用するには{minVersion.ToString().Replace("pp", "++")}以降が必要です";

                Content = textBlock;

                return false;
            }

            if (SaveData.CppVersion < maxVersion)
            {
                TextBlock textBlock = new TextBlock { HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };

                textBlock.Text = $"このヘッダーを使用するには{maxVersion.ToString().Replace("pp", "++")}以前が必要です";

                Content = textBlock;

                return false;
            }

            return true;
        }

        private void ApplyTypeDefs()
        {
            LibraryPageHelper.ApplyTypeDefs(ContentsPanel, XElement, "TypeDefinitions");
        }

        private async Task ApplyConcepts()
        {
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "Concepts", "コンセプト", Category.Concept);
        }

        private void ApplyClasses()
        {
            LibraryPageHelper.ApplyClasses(ContentsPanel, XElement, "Classes", "クラス", XmlPath.CppLibraryDirectory, CodeLanguage.Cpp, Category.Class);
        }

        private void ApplyStructures()
        {
            LibraryPageHelper.ApplyClasses(ContentsPanel, XElement, "Structures", "構造体", XmlPath.CppLibraryDirectory, CodeLanguage.Cpp, Category.Class);
        }

        private void ApplyEnums()
        {
            LibraryPageHelper.ApplyClasses(ContentsPanel, XElement, "Enums", "列挙型", XmlPath.CppLibraryDirectory, CodeLanguage.Cpp, Category.Enum);
        }

        private async Task ApplyOperators()
        {
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "Operators", "演算子", Category.Operator);
        }

        private async Task ApplyFunctions()
        {
            await LibraryPageHelper.ApplyCppFunctionsAsync(ContentsPanel, XElement, "Functions", "関数", Category.Function);
        }

    }
}
