using LibrarySample.SampleManagement;
using Microsoft.UI;
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
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public sealed partial class GrammarExpander : Expander
    {
        public Library LibraryType { get; }

        public XElement XElement { get; }

        public CodeLanguage CodeLanguage { get; }

        public GrammarExpander(XElement xElement, Library libraryType, CodeLanguage codeLanguage)
        {
            this.InitializeComponent();
            FIcon.Margin = new Thickness((Data.ControlHeight - 24.0) / 2.0, 0, (Data.ControlHeight - 24.0) / 2.0, 0);

            XElement = xElement;
            LibraryType = libraryType;
            CodeLanguage = codeLanguage;

            ApplyDefinition();
            ApplyParameter();
        }

        private void ApplyDefinition()
        {
            string fileName = LibraryType switch
            {
                Library.CppWinRTNamespace => XElement.Element("CppWinRTDefinition").Element("DefinitionFile").Value,
                Library.Uwp => CodeLanguage switch
                {
                    CodeLanguage.CppWinRT => XElement.Element("Definition").Element("CppWinRTDefinition").Element("DefinitionFile").Value,
                    CodeLanguage.CSharp => XElement.Element("Definition").Element("CSharpDefinition").Element("DefinitionFile").Value,
                    _ => throw new Exception(),
                },
                _ => XElement.Element("Definition").Element("DefinitionFile").Value,
            };

            SourceCodeViewer sourceCodeViewer = LibraryType == Library.Uwp ? SourceCodeViewer.CreateWinCodeViewer(CodeLanguage): SourceCodeViewer.Create(CodeLanguage);
            sourceCodeViewer.FilePath = LibraryType switch
            {
                Library.Cpp => XmlPath.CppLibrarySourceCodeDirectory + GetXElementRootTag() + "/" + fileName,
                Library.CppWinRTNamespace=> XmlPath.CppWinRTNamespaceLibrarySourceCodeDirectory + GetXElementRootTag() + "/" + fileName,
                Library.Uwp => XmlPath.UwpLibrarySourceCodeDirectory + GetXElementRootTag() + "/" + fileName,

                _ => throw new NotImplementedException(),
            };

            DefinitionPanel.Children.Add(sourceCodeViewer);
        }

        private void ApplyParameter()
        {
            XElement xParameters = XElement.Element("Parameters");

            //パラメーターがなければパネルを削除
            if (xParameters == null)
            {
                ContentsPanel.Children.Remove(ParameterPanel);
                return;
            }

            foreach (XElement xParameter in xParameters.Elements())
            {
                ParameterPanel.Children.Add(new DescriptionTextCard { Title = xParameter.Attribute("Name").Value, Description = xParameter.Attribute("Description").Value });
            }

        }

        //XmlRootの名前を取得
        private string GetXElementRootTag()
        {
            XElement xElement = XElement;

            while (xElement.Parent != null)
            {
                xElement = xElement.Parent;
            }

            return xElement.Attribute("Tag").Value;
        }
    }
}
