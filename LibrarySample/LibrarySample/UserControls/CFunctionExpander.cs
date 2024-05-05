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
    public class CFunctionExpander : FunctionExpander, ICHandler
    {
        private CVersion _actualCVersion = SaveData.CVersion;

        public CVersion CVersion { get; } = SaveData.CVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CProcesserType;

        public CFunctionExpander(XElement xElement, Category category) : base(xElement, category)
        {

        }

        protected override StartSampleButton GetSampleButton()
        {
            return new StartSampleButton(SampleRunner.GetCSampleRunner(CVersion, ProcesserType).ApplicationName, Folder, FuncName);
        }

        protected override void ApplyDefinition()
        {
            CVersion minVersion = EnumConverter.ToCLanguage(XElement.Attribute("TargetMinVersion")?.Value, CVersion.MinValue);
            CVersion maxVersion = EnumConverter.ToCLanguage(XElement.Attribute("TargetMaxVersion")?.Value, CVersion.MaxValue);

            if (SaveData.CVersion < minVersion)
            {
                if (minVersion == CVersion.MaxValue)
                {
                    SetAsNotSupportedVersion($"このAPIを使用するには{minVersion}が必要です");
                }
                else
                {
                    SetAsNotSupportedVersion($"このAPIを使用するには{minVersion}以降が必要です");
                }
                return;
            }

            if (maxVersion < SaveData.CVersion)
            {
                SetAsNotSupportedVersion($"このAPIを使用するには{maxVersion}以前が必要です");
                return;
            }

            while (!FindDefinition(_actualCVersion))
            {
                _actualCVersion--;
            }
        }

        protected override void ApplySourceCode()
        {
            foreach (XElement xElement in XElement.Elements("Definition"))
            {
                CVersion cLanguage = EnumConverter.ToCLanguage(xElement.Attribute("LanguageVersion")?.Value, CVersion.C11);
                if (cLanguage == _actualCVersion)
                {
                    XElement def = xElement.Element("DefinitionFile");
                    XElement source = xElement.Element("SourceCodeFile");

                    SourceCodeViewer defCode = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.C);
                    defCode.FilePath = XmlPath.CLibrarySourceCodeDirectory + def.Value;
                    AddDefinitionCode(defCode);

                    //ソースコードがない
                    if (source == null)
                    {
                        DeleteSamplePanel();
                        return;
                    }

                    SourceCodeViewer sourceCodeViewer = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.C);
                    sourceCodeViewer.FilePath = XmlPath.CLibrarySourceCodeDirectory + source.Value;

                    
                    AddSourceCode(sourceCodeViewer);

                    return;
                }
            }
            throw new Exception();
        }

        protected override void LaunchByButton()
        {
            Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetCSampleRunner(CVersion, ProcesserType).ApplicationName} {Folder} {FuncName} true");
        }

        public override async void Launch()
        {
            if (_isWorking) return;
            _isWorking = true;

            var result = await SampleRunner.GetCSampleRunner(CVersion, ProcesserType).RunSampleAsync(Folder, FuncName, InputsPanel.CreateInputs());

            OutputConsole.Output = result.Outputs;

            _isWorking = false;
        }

        private bool FindDefinition(CVersion cVersion)
        {
            var definitions = XElement.Elements("Definition");

            //ば＾ジョンに合う定義文を取得
            foreach (var definition in definitions)
            {
                CVersion cLanguage = EnumConverter.ToCLanguage(definition.Attribute("LanguageVersion")?.Value, CVersion.C11);

                if (cLanguage == cVersion)
                {
                    _actualCVersion = cLanguage;
                    return true;
                }
            }
            return false;
        }

    }
}
