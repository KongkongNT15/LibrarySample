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
using Windows.ApplicationModel.Contacts;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class CLibraryPage : Page, IXml, ICHandler
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
                ApplyTypeDefs();
                ApplyStructures();
                ApplyFunctions();
                ApplyFunctionMacros();
                ApplyMacro();
            }
        }

        public CVersion CVersion { get; } = SaveData.CVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CProcesserType;

        public CLibraryPage()
        {
            this.InitializeComponent();
        }

        private void ApplyTypeDefs()
        {
            LibraryPageHelper.ApplyTypeDefs(ContentsPanel, XElement, "TypeDefinitions");
        }

        private void ApplyStructures()
        {
            XElement xStructures = XElement.Element("Structures");

            if (xStructures != null)
            {
                StackPanel panel = LibraryPageHelper.CreateHeaderPanel("構造体");
                ContentsPanel.Children.Add(panel);

                foreach(XElement xStructure in xStructures.Elements("Structure"))
                {
                    panel.Children.Add(new SlideButton(xStructure, CodeLanguage.C) { Glyph = EnumConverter.ToGlyph(Category.Field) });
                }
            }
        }

        private async void ApplyFunctions()
        {
            XElement xFuntions = XElement.Element("Functions");

            if (xFuntions != null)
            {
                StackPanel panel = LibraryPageHelper.CreateHeaderPanel("関数");
                ContentsPanel.Children.Add(panel);

                foreach (XElement xFunction in xFuntions.Elements("Function"))
                {
                    panel.Children.Add(new CFunctionExpander(xFunction, Category.Function));

                    await Task.Delay(1);
                }

            }
        }

        private async void ApplyFunctionMacros()
        {
            XElement xFuntions = XElement.Element("FunctionMacros");

            if (xFuntions != null)
            {
                StackPanel panel = LibraryPageHelper.CreateHeaderPanel("関数マクロ");
                ContentsPanel.Children.Add(panel);

                foreach (XElement xFunction in xFuntions.Elements("Function"))
                {
                    panel.Children.Add(new CFunctionExpander(xFunction, Category.Macro));

                    await Task.Delay(1);
                }

            }
        }

        private async void ApplyMacro()
        {

            if (XElement.Attribute("HasMacros").Value == "True")
            {
                StackPanel panel = LibraryPageHelper.CreateHeaderPanel("マクロ");
                ContentsPanel.Children.Add(panel);

                string folderName = XElement.Attribute("Tag").Value;
                var result = await SampleRunner.GetCSampleRunner(SaveData.CVersion, SaveData.CProcesserType).RunSampleAsync(folderName, "?macro");

                var lines = result.Outputs.Split(Environment.NewLine);

                //
                for (int i = 0; i < lines.Length - 1; i += 3)
                {
                    if (lines[i] == lines[i + 1]) continue;

                    ValueCard valueCard = new ValueCard();
                    valueCard.IsTitleTextSelectionEnabled = true;
                    valueCard.IsValueTextSelectionEnabled = true;
                    valueCard.Glyph = EnumConverter.ToGlyph(Category.Macro);
                    valueCard.Title = lines[i];
                    valueCard.Value = lines[i + 1];
                    valueCard.Description = lines[i + 2];

                    panel.Children.Add(valueCard);
                }

                //マクロがなければpanelを削除
                if (panel.Children.Count == 1)
                {
                    ContentsPanel.Children.Remove(panel);

                    //本当に何もなければ
                    if (ContentsPanel.Children.Count == 0)
                    {
                        this.Content = new TextBlock { Text = "なにも定義されていません", HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };
                    }
                }
            }

        }

    }
}
