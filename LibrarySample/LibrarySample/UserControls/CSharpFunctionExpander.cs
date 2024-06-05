using LibrarySample.SampleManagement;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class CSharpFunctionExpander : FunctionExpander
    {
        public CSharpFunctionExpander(XElement xElement, Category category) : base(xElement, category) { }

        protected override void ApplyDefinition()
        {
            return;
        }

        protected override void ApplySourceCode()
        {
            XElement xDefinition = XElement.Element("Definition");

            XElement def = xDefinition.Element("DefinitionFile");
            XElement source = xDefinition.Element("SourceCodeFile");

            string xmlPath = XmlPath.DotNetLibrarySourceCodeDirectory;

            SourceCodeViewer defCode = SourceCodeViewer.Create(CodeLanguage.CSharp);
            defCode.FilePath = xmlPath + Folder + "/" + def.Value;
            AddDefinitionCode(defCode);

            //ソースコードがない
            if (source == null)
            {
                DeleteSamplePanel();
                return;
            }

            SourceCodeViewer sourceCodeViewer = SourceCodeViewer.Create(CodeLanguage.CSharp);
            sourceCodeViewer.FilePath = xmlPath + Folder + "/" + source.Value;


            AddSourceCode(sourceCodeViewer);

        }

        protected override StartSampleButton GetSampleButton()
        {
            return new StartSampleButton("", Folder, FuncName, LaunchType);
        }

        public override void Launch()
        {
            //await LaunchAsync(SampleRunner.GetCppWinRTSampleRunner(LaunchType, ProcesserType));
        }

        protected override void LaunchByButton()
        {
            //Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetCppWinRTSampleRunner(LaunchType, ProcesserType).ApplicationName} {Folder} {FuncName} true");
        }
    }
}
