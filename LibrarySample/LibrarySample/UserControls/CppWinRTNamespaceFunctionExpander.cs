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
    public sealed class CppWinRTNamespaceFunctionExpander : FunctionExpander, ICppWinRTHandler
    {
        public ProcesserType ProcesserType { get; } = SaveData.CppWinRTNamespaceProcesserType;

        public CppWinRTNamespaceFunctionExpander(XElement xElement, Category category) : base (xElement, category, LaunchType.Graphical)
        {

        }

        protected override void ApplyDefinition()
        {
            return;
        }

        protected override void ApplySourceCode()
        {
            XElement xDefinition = XElement.Element("CppWinRTDefinition");

            XElement def = xDefinition.Element("DefinitionFile");
            XElement source = xDefinition.Element("SourceCodeFile");

            string xmlPath = XmlPath.CppWinRTNamespaceLibrarySourceCodeDirectory;

            SourceCodeViewer defCode = SourceCodeViewer.Create(CodeLanguage.CppWinRT);
            defCode.FilePath = xmlPath + Folder + "/" + def.Value;
            AddDefinitionCode(defCode);

            //ソースコードがない
            if (source == null)
            {
                DeleteSamplePanel();
                return;
            }

            SourceCodeViewer sourceCodeViewer = SourceCodeViewer.Create(CodeLanguage.CppWinRT);
            sourceCodeViewer.FilePath = xmlPath + Folder + "/" + source.Value;


            AddSourceCode(sourceCodeViewer);

        }

        protected override StartSampleButton GetSampleButton()
        {
            return new StartSampleButton(SampleRunner.GetCppWinRTSampleRunner(LaunchType, ProcesserType).ApplicationName, Folder, FuncName, LaunchType);
        }

        public override async void Launch()
        {
            await LaunchAsync(SampleRunner.GetCppWinRTSampleRunner(LaunchType, ProcesserType));
        }

        protected override void LaunchByButton()
        {
            Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetCppWinRTSampleRunner(LaunchType, ProcesserType).ApplicationName} {Folder} {FuncName} true");
        }
    }
}
