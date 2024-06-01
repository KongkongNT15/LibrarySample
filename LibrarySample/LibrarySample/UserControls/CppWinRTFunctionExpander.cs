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
    public sealed class CppWinRTFunctionExpander : FunctionExpander, ICppWinRTHandler
    {
        public ProcesserType ProcesserType { get; } = SaveData.CppWinRTNamespaceProcesserType;

        private readonly bool _iswinrtNamespaceSample;

        public CppWinRTFunctionExpander(XElement xElement, Category category, bool iswinrtNamespaceSample) : base (xElement, category, LaunchType.Graphical)
        {
            _iswinrtNamespaceSample = iswinrtNamespaceSample;
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

            string xmlPath = _iswinrtNamespaceSample ? XmlPath.CppWinRTNamespaceLibrarySourceCodeDirectory : throw new NotImplementedException();

            SourceCodeViewer defCode = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.CppWinRT);
            defCode.FilePath = xmlPath + Folder + "/" + def.Value;
            AddDefinitionCode(defCode);

            //ソースコードがない
            if (source == null)
            {
                DeleteSamplePanel();
                return;
            }

            SourceCodeViewer sourceCodeViewer = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.CppWinRT);
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
