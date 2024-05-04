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

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public sealed partial class GrammarExpander : Expander
    {
        public CodeLanguage CodeLanguage { get; }

        public XElement XElement { get; }

        public GrammarExpander(XElement xElement, CodeLanguage codeLanguage)
        {
            this.InitializeComponent();
            FIcon.Margin = new Thickness((Data.ControlHeight - 24.0) / 2.0, 0, (Data.ControlHeight - 24.0) / 2.0, 0);

            XElement = xElement;
            CodeLanguage = codeLanguage;

            ApplyDefinition();
            ApplyParameter();
        }

        private void ApplyDefinition()
        {
            string fileName = XElement.Element("Definition").Element("DefinitionFile").Value;

            SourceCodeViewer sourceCodeViewer = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage);
            sourceCodeViewer.FilePath = XmlPath.CppLibrarySourceCodeDirectory + fileName;

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
    }
}
