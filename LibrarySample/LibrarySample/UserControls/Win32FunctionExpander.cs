using LibrarySample.Languages;
using LibrarySample.Pages;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class Win32FunctionExpander : FunctionExpander, IWin32Handler
    {
        public ProcesserType ProcesserType { get; } = SaveData.Win32ProcesserType;
        public CodeLanguage CodeLanguage { get; } = SaveData.Win32CodeLanguage;

        public Win32FunctionExpander(XElement xElement, Category category) : base(xElement, category, LaunchType.Graphical) { }

        protected override StartSampleButton GetSampleButton()
        {
            return new StartSampleButton(SampleRunner.GetWin32SampleRunner(LaunchType, ProcesserType, CodeLanguage).ApplicationName, Folder, FuncName, LaunchType);
        }

        protected override void ApplyDefinition() { }

        protected override void ApplySourceCode()
        {
            XElement xElement = XElement.Element("Definition");
            XElement def = xElement.Element("DefinitionFile");
            XElement source = CodeLanguage switch
            {
                CodeLanguage.CWin32 => xElement.Element("SourceCodeFile"),
                CodeLanguage.CppWin32 => xElement.Element("SourceCodeFileCpp"),
                _ => throw new Exception()
            };

            SourceCodeViewer defCode = SourceCodeViewer.Create(CodeLanguage);
            defCode.FilePath = XmlPath.Win32LibrarySourceCodeDirectory + def.Value;
            AddDefinitionCode(defCode);

            //ソースコードがない
            if (source == null)
            {
                DeleteSamplePanel();
                return;
            }

            SourceCodeViewer sourceCodeViewer = SourceCodeViewer.Create(CodeLanguage);
            sourceCodeViewer.FilePath = XmlPath.Win32LibrarySourceCodeDirectory + source.Value;


            AddSourceCode(sourceCodeViewer);
        }

        protected override void LaunchByButton()
        {
            Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetWin32SampleRunner(LaunchType, ProcesserType, CodeLanguage).ApplicationName} {Folder} {FuncName} true");
        }

        public override async void Launch()
        {
            await LaunchAsync(SampleRunner.GetWin32SampleRunner(LaunchType, ProcesserType, CodeLanguage));
        }
    }
}
