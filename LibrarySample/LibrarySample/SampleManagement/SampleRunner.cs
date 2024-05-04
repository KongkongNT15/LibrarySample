using LibrarySample.Languages;
using LibrarySample.Settings;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    internal class SampleRunner(string _applicationName)
    {

        public string ApplicationName => _applicationName;

        private const string _c11x64SampleName = "../Sample/CSample-C11";
        private const string _c17x64SampleName = "../Sample/CSample-C17";

        private const string _c11x86SampleName = "../Sample/CSample-C11-x86";
        private const string _c17x86SampleName = "../Sample/CSample-C17-x86";

        private const string _cpp14x64SampleName = "../Sample/CppSample-Cpp14";
        private const string _cpp17x64SampleName = "../Sample/CppSample-Cpp17";
        private const string _cpp20x64SampleName = "../Sample/CppSample-Cpp20";
        private const string _cpp23x64SampleName = "../Sample/CppSample-Cpp23";

        private const string _cpp14x86SampleName = "../Sample/CppSample-Cpp14-x86";
        private const string _cpp17x86SampleName = "../Sample/CppSample-Cpp17-x86";
        private const string _cpp20x86SampleName = "../Sample/CppSample-Cpp20-x86";
        private const string _cpp23x86SampleName = "../Sample/CppSample-Cpp23-x86";

        private static SampleRunner _c11x64Sample;
        private static SampleRunner _c17x64Sample;

        private static SampleRunner _c11x86Sample;
        private static SampleRunner _c17x86Sample;

        private static SampleRunner _cpp14x64Sample;
        private static SampleRunner _cpp17x64Sample;
        private static SampleRunner _cpp20x64Sample;
        private static SampleRunner _cpp23x64Sample;

        private static SampleRunner _cpp14x86Sample;
        private static SampleRunner _cpp17x86Sample;
        private static SampleRunner _cpp20x86Sample;
        private static SampleRunner _cpp23x86Sample;

        public static SampleRunner C11x64Sample => _c11x64Sample;
        public static SampleRunner C17x64Sample => _c17x64Sample;

        public static SampleRunner C11x86Sample => _c11x86Sample;
        public static SampleRunner C17x86Sample => _c17x86Sample;

        private static SampleRunner Cpp14x64Sample => _cpp14x64Sample;
        private static SampleRunner Cpp17x64Sample => _cpp17x64Sample;
        private static SampleRunner Cpp20x64Sample => _cpp20x64Sample;
        private static SampleRunner Cpp23x64Sample => _cpp23x64Sample;

        private static SampleRunner Cpp14x86Sample => _cpp14x86Sample;
        private static SampleRunner Cpp17x86Sample => _cpp17x86Sample;
        private static SampleRunner Cpp20x86Sample => _cpp20x86Sample;
        private static SampleRunner Cpp23x86Sample => _cpp23x86Sample;

        //コンソールのパス
        public static readonly string SampleLauncherPath = @"../Sample/SampleLauncher";

        public static void Initialize()
        {
            _c11x64Sample = new SampleRunner(_c11x64SampleName);
            _c17x64Sample = new SampleRunner(_c17x64SampleName);

            _c11x86Sample = new SampleRunner(_c11x86SampleName);
            _c17x86Sample = new SampleRunner(_c17x86SampleName);

            _cpp14x64Sample = new SampleRunner(_cpp14x64SampleName);
            _cpp17x64Sample = new SampleRunner(_cpp17x64SampleName);
            _cpp20x64Sample = new SampleRunner(_cpp20x64SampleName);
            _cpp23x64Sample = new SampleRunner(_cpp23x64SampleName);

            _cpp14x86Sample = new SampleRunner(_cpp14x86SampleName);
            _cpp17x86Sample = new SampleRunner(_cpp17x86SampleName);
            _cpp20x86Sample = new SampleRunner(_cpp20x86SampleName);
            _cpp23x86Sample = new SampleRunner(_cpp23x86SampleName);
        }

        public static SampleRunner GetCSampleRunner(CVersion cLanguage, ProcesserType processerType)
        {
            return cLanguage switch
            {
                CVersion.C11 => processerType switch
                {
                    ProcesserType.X86 => C11x86Sample,
                    ProcesserType.X64 => C11x64Sample,
                    ProcesserType.Arm64 => throw new NotImplementedException(),
                    _ => throw new NotImplementedException(),
                },
                CVersion.C17 => processerType switch
                {
                    ProcesserType.X86 => C17x86Sample,
                    ProcesserType.X64 => C17x64Sample,
                    ProcesserType.Arm64 => throw new NotImplementedException(),
                    _ => throw new NotImplementedException(),
                },
                _ => throw new NotImplementedException(),
            };
        }

        public static SampleRunner GetCppSampleRunner(CppVersion cppVersion, ProcesserType processerType)
        {
            return cppVersion switch
            {
                CppVersion.Cpp14 => processerType switch
                {
                    ProcesserType.X86 => Cpp14x86Sample,
                    ProcesserType.X64 => Cpp14x64Sample,
                    _ => throw new NotImplementedException(),
                },
                CppVersion.Cpp17 => processerType switch
                {
                    ProcesserType.X86 => Cpp17x86Sample,
                    ProcesserType.X64 => Cpp17x64Sample,
                    _ => throw new NotImplementedException(),
                },
                CppVersion.Cpp20 => processerType switch
                {
                    ProcesserType.X86 => Cpp20x86Sample,
                    ProcesserType.X64 => Cpp20x64Sample,
                    _ => throw new NotImplementedException(),
                },
                CppVersion.Cpp23 => processerType switch
                {
                    ProcesserType.X86 => Cpp23x86Sample,
                    ProcesserType.X64 => Cpp23x64Sample,
                    _ => throw new NotImplementedException(),
                },
                _ => throw new NotImplementedException(),
            };
        }

        public async Task<SampleResult> RunSampleAsync(string folderName, string functuonName, string input = "")
        {
            return await Task.Run(() =>
            {
                uint returnCode = 0;
                string output = NativeAPI.NativeMethod.StartSampleProcess(ApplicationName, folderName + " " + functuonName + " false", input, SaveData.WaitTime, ref returnCode);

                return new SampleResult(output, returnCode);
            });
        }

    }
}
