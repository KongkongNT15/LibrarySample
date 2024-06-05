using LibrarySample.Pages;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class UwpFunctionExpander : FunctionExpander, IUwpHandler
    {
        public WinRTDesign Design { get; } = SaveData.UwpCodeDesign;
        public CodeLanguage CodeLanguage { get; } = SaveData.UwpCodeLanguage;
        public ProcesserType ProcesserType { get; } = SaveData.UwpProcesserType;

        public UwpFunctionExpander(XElement xElement, Category category) : base(xElement, category, LaunchType.Graphical) { }

        protected override void ApplyDefinition()
        {
            XAttribute xDesign = XElement.Attribute("TargetLanguage");

            if (xDesign == null) return;

            if (xDesign.Value == "Both") return;

            CodeLanguage language = EnumConverter.ToCodeLanguage(xDesign.Value);

            if (language == CodeLanguage) return;

            string name = language switch
            {
                CodeLanguage.CSharp => "C#",
                CodeLanguage.CppWinRT => "C++",
                _ => throw new Exception(),
            };

            SetAsNotSupportedVersion($"このAPIは{name}でのみ使用できます");
        }
        

        protected override void ApplySourceCode()
        {
            XElement xDefinition = XElement.Element("Definition");

            XElement xmlSource = xDefinition.Element("XAMLSource");

            //C++
            //C#
            XElement xLanguageDef = CodeLanguage switch
            {
                CodeLanguage.CppWinRT => xDefinition.Element("CppWinRTDefinition"),
                CodeLanguage.CSharp => xDefinition.Element("CSharpDefinition"),
                _ => throw new Exception(),
            };

            XElement def = xLanguageDef.Element("DefinitionFile");
            XElement source = null;

            string xmlPath = XmlPath.UwpLibrarySourceCodeDirectory;

            SourceCodeViewer defCode = SourceCodeViewer.CreateWinCodeViewer(CodeLanguage);
            defCode.FilePath = xmlPath + Folder + "/" + def.Value;
            AddDefinitionCode(defCode);

            
            switch (Design)
            {
                case WinRTDesign.XAML:
                    source = xmlSource != null ? xLanguageDef.Element("UsingXamlSourceCodeFile") : xLanguageDef.Element("SourceCodeFile");
                    //ソースコードがない
                    if (xmlSource == null && source == null)
                    {
                        DeleteSamplePanel();
                        return;
                    }

                    break;
                case WinRTDesign.CodeOnly:
                    source = xLanguageDef.Element("SourceCodeFile");
                    //ソースコードがない
                    if (source == null)
                    {
                        DeleteSamplePanel();
                        return;
                    }
                    break;

            }

            if (xmlSource != null && Design == WinRTDesign.XAML)
            {
                SourceCodeViewer xmlViewer = SourceCodeViewer.Create(CodeLanguage.Xaml);
                xmlViewer.FilePath = xmlPath + Folder + "/" + xmlSource.Value;

                AddSourceCode(xmlViewer);
            }

            if (source != null)
            {
                SourceCodeViewer sourceCodeViewer = SourceCodeViewer.CreateWinCodeViewer(CodeLanguage);
                sourceCodeViewer.FilePath = xmlPath + Folder + "/" + source.Value;
                AddSourceCode(sourceCodeViewer);
            }

        }

        //C++?WinRTのみの対応
        protected override UIElement GetSampleButton()
        {
            if (CodeLanguage == CodeLanguage.CSharp && LaunchType == LaunchType.Graphical)
            {
                StackPanel stackPanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
                var infoBar = new InfoBar
                {
                    Title = "ふぁ！？っく",
                    Message = "C#/WinRTのGUIサンプルは現在準備中です\n「起動」をクリックするとC++/WinRTのサンプルが起動します",
                    Severity = InfoBarSeverity.Warning,
                    IsClosable = false,
                    IsOpen = true,
                };

                stackPanel.Children.Add(infoBar);
                stackPanel.Children.Add(new StartSampleButton(SampleRunner.GetUwpSampleRunner(LaunchType, ProcesserType, CodeLanguage).ApplicationName, Folder, FuncName, LaunchType));

                return stackPanel;
            }
            return new StartSampleButton(SampleRunner.GetUwpSampleRunner(LaunchType, ProcesserType, CodeLanguage).ApplicationName, Folder, FuncName, LaunchType);
        }

        public override async void Launch()
        {
            await LaunchAsync(SampleRunner.GetUwpSampleRunner(LaunchType, ProcesserType, CodeLanguage));
        }

        protected override void LaunchByButton()
        {
            Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetUwpSampleRunner(LaunchType, ProcesserType, CodeLanguage).ApplicationName} {Folder} {FuncName} true");
        }
    }
}
