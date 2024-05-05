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
    public class CppFunctionExpander : FunctionExpander, ICppHandler
    {
        private CppVersion _actualCppVersion = SaveData.CppVersion;

        public CppVersion CppVersion { get; } = SaveData.CppVersion;
        public ProcesserType ProcesserType { get; } = SaveData.CppProcesserType;

        public CppFunctionExpander(XElement xElement, Category category) : base(xElement, category) { }

        protected override StartSampleButton GetSampleButton()
        {
            return new StartSampleButton(SampleRunner.GetCppSampleRunner(CppVersion, ProcesserType).ApplicationName, Folder, FuncName);
        }

        protected override void ApplyDefinition()
        {
            CppVersion minVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMinVersion")?.Value, CppVersion.MinValue);
            CppVersion maxVersion = EnumConverter.ToCppVersion(XElement.Attribute("TargetMaxVersion")?.Value, CppVersion.MaxValue);

            if (CppVersion < minVersion)
            {
                if (minVersion == CppVersion.MaxValue)
                {
                    SetAsNotSupportedVersion($"このAPIを使用するには{EnumConverter.ToNormalCppVersionName(minVersion)}が必要です");
                }
                else
                {
                    SetAsNotSupportedVersion($"このAPIを使用するには{EnumConverter.ToNormalCppVersionName(minVersion)}以降が必要です");
                }
                return;
            }

            if (maxVersion < CppVersion)
            {
                SetAsNotSupportedVersion($"このAPIを使用するには{EnumConverter.ToNormalCppVersionName(maxVersion)}以前が必要です");
                return;
            }

            while (!FindDefinition(_actualCppVersion))
            {
                _actualCppVersion--;
            }
        }

        protected override void ApplySourceCode()
        {
            foreach (XElement xElement in XElement.Elements("Definition"))
            {
                CppVersion cLanguage = EnumConverter.ToCppVersion(xElement.Attribute("LanguageVersion")?.Value, CppVersion.Cpp14);
                if (cLanguage == _actualCppVersion)
                {
                    XElement def = xElement.Element("DefinitionFile");
                    XElement source = xElement.Element("SourceCodeFile");

                    SourceCodeViewer defCode = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.Cpp);
                    //Tagと同じ名前のフォルダにある
                    defCode.FilePath = XmlPath.CppLibrarySourceCodeDirectory + Folder + "/" + def.Value;
                    AddDefinitionCode(defCode);

                    //ソースコードがない
                    if (source == null)
                    {
                        DeleteSamplePanel();
                        return;
                    }

                    SourceCodeViewer sourceCodeViewer = SourceCodeViewer.GetSourceCodeViewer(CodeLanguage.Cpp);
                    sourceCodeViewer.FilePath = XmlPath.CppLibrarySourceCodeDirectory + Folder + "/" + source.Value;


                    AddSourceCode(sourceCodeViewer);

                    return;
                }
            }
            throw new Exception();
        }

        protected override void LaunchByButton()
        {
            Process.Start(SampleRunner.SampleLauncherPath, $"{SampleRunner.GetCppSampleRunner(CppVersion, ProcesserType).ApplicationName} {Folder} {FuncName} true");
        }

        public override async void Launch()
        {
            if (_isWorking) return;
            _isWorking = true;

            var result = await SampleRunner.GetCppSampleRunner(CppVersion, ProcesserType).RunSampleAsync(Folder, FuncName, InputsPanel.CreateInputs());

            OutputConsole.Output = result.Outputs;

            _isWorking = false;
        }

        private bool FindDefinition(CppVersion cppVersion)
        {
            var definitions = XElement.Elements("Definition");

            //ば＾ジョンに合う定義文を取得
            foreach (var definition in definitions)
            {
                CppVersion cLanguage = EnumConverter.ToCppVersion(definition.Attribute("LanguageVersion")?.Value, CppVersion.Cpp14);

                if (cLanguage == cppVersion)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
