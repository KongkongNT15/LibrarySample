using LibrarySample.Languages;
using LibrarySample.Settings;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public class SampleRunner(string _applicationName)
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

        private const string _win32x64ConsoleSampleName = "../Sample/Win32-ConsoleSample-x64";
        private const string _win32x64GraphicalSampleName = "../Sample/Win32-GraphicalSample-x64";

        private const string _win32x86ConsoleSampleName = "../Sample/Win32-ConsoleSample-x86";
        private const string _win32x86GraphicalSampleName = "../Sample/Win32-GraphicalSample-x86";

        private const string _win32x64ConsoleSampleCppName = "../Sample/Win32-ConsoleSample-Cpp-x64";
        private const string _win32x64GraphicalSampleCppName = "../Sample/Win32-GraphicalSample-Cpp-x64";

        private const string _win32x86ConsoleSampleCppName = "../Sample/Win32-ConsoleSample-Cpp-x86";
        private const string _win32x86GraphicalSampleCppName = "../Sample/Win32-GraphicalSample-Cpp-x86";

        private const string _cppWinRTx64ConsoleSampleName = "../Sample/CppWinRT-ConsoleSample-x64";
        private const string _cppWinRTx64GraphicalSampleName = "../Sample/CppWinRT-GraphicalSample-x64";

        private const string _cppWinRTx86ConsoleSampleName = "../Sample/CppWinRT-ConsoleSample-x86";
        private const string _cppWinRTx86GraphicalSampleName = "../Sample/CppWinRT-GraphicalSample-x86";

        private const string _cSharpConsoleSamplex64Name = @"../Sample/DotNet/Net8.0/x64/CSharp-ConsoleSample";
        private const string _cSharpConsoleSamplex86Name = @"../Sample/DotNet/Net8.0/x64/CSharp-ConsoleSample";

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

        private static SampleRunner _win32x64ConsoleSample;
        private static SampleRunner _win32x64GraphicalSample;

        private static SampleRunner _win32x86ConsoleSample;
        private static SampleRunner _win32x86GraphicalSample;

        private static SampleRunner _win32x64ConsoleSampleCpp;
        private static SampleRunner _win32x64GraphicalSampleCpp;

        private static SampleRunner _win32x86ConsoleSampleCpp;
        private static SampleRunner _win32x86GraphicalSampleCpp;

        private static SampleRunner _cppWinRTx64ConsoleSample;
        private static SampleRunner _cppWinRTx64GraphicalSample;

        private static SampleRunner _cppWinRTx86ConsoleSample;
        private static SampleRunner _cppWinRTx86GraphicalSample;
        
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

        public static SampleRunner Win32x64ConsoleSample => _win32x64ConsoleSample;
        public static SampleRunner Win32x64GraphicalSample => _win32x64GraphicalSample;

        public static SampleRunner Win32x86ConsoleSample => _win32x86ConsoleSample;
        public static SampleRunner Win32x86GraphicalSample => _win32x86GraphicalSample;

        public static SampleRunner Win32x64ConsoleSampleCpp => _win32x64ConsoleSampleCpp;
        public static SampleRunner Win32x64GraphicalSampleCpp => _win32x64GraphicalSampleCpp;

        public static SampleRunner Win32x86ConsoleSampleCpp => _win32x86ConsoleSampleCpp;
        public static SampleRunner Win32x86GraphicalSampleCpp => _win32x86GraphicalSampleCpp;

        public static SampleRunner CppWinRTx64ConsoleSample => _cppWinRTx64ConsoleSample;
        public static SampleRunner CppWinRTx64GraphicalSample => _cppWinRTx64GraphicalSample;

        public static SampleRunner CppWinRTx86ConsoleSample => _cppWinRTx86ConsoleSample;
        public static SampleRunner CppWinRTx86GraphicalSample => _cppWinRTx86GraphicalSample;

        private static SampleRunner _cSharpConsoleSampleX64;
        private static SampleRunner CSharpConsoleSampleX64 => _cSharpConsoleSampleX64;

        private static SampleRunner _cSharpConsoleSampleX86;
        private static SampleRunner CSharpConsoleSampleX86 => _cSharpConsoleSampleX86;

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

            _win32x64ConsoleSample = new SampleRunner(_win32x64ConsoleSampleName);
            _win32x64GraphicalSample = new SampleRunner(_win32x64GraphicalSampleName);

            _win32x86ConsoleSample = new SampleRunner(_win32x86ConsoleSampleName);
            _win32x86GraphicalSample = new SampleRunner(_win32x86GraphicalSampleName);

            _win32x64ConsoleSampleCpp = new SampleRunner(_win32x64ConsoleSampleCppName);
            _win32x64GraphicalSampleCpp = new SampleRunner(_win32x64GraphicalSampleCppName);

            _win32x86ConsoleSampleCpp = new SampleRunner(_win32x86ConsoleSampleCppName);
            _win32x86GraphicalSampleCpp = new SampleRunner(_win32x86GraphicalSampleCppName);

            _cppWinRTx64ConsoleSample = new SampleRunner(_cppWinRTx64ConsoleSampleName);
            _cppWinRTx64GraphicalSample = new SampleRunner(_cppWinRTx64GraphicalSampleName);

            _cppWinRTx86ConsoleSample = new SampleRunner(_cppWinRTx86ConsoleSampleName);
            _cppWinRTx86GraphicalSample = new SampleRunner(_cppWinRTx86GraphicalSampleName);

            _cSharpConsoleSampleX64 = new SampleRunner(_cSharpConsoleSamplex64Name);
            _cSharpConsoleSampleX86 = new SampleRunner(_cSharpConsoleSamplex86Name);
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

        public static SampleRunner GetWin32SampleRunner(LaunchType launchType, ProcesserType processerType, CodeLanguage codeLanguage)
        {
            return codeLanguage switch
            {
                CodeLanguage.CWin32 => launchType switch
                {
                    LaunchType.Graphical => processerType switch
                    {
                        ProcesserType.X64 => Win32x64GraphicalSample,
                        ProcesserType.X86 => Win32x86GraphicalSample,
                        _ => throw new NotImplementedException(),
                    },
                    LaunchType.PipeConsole or LaunchType.Console => processerType switch
                    {
                        ProcesserType.X64 => Win32x64ConsoleSample,
                        ProcesserType.X86 => Win32x86ConsoleSample,
                        _ => throw new NotImplementedException(),
                    },
                    _ => throw new NotImplementedException(),
                },
                CodeLanguage.CppWin32 => launchType switch
                {
                    LaunchType.Graphical => processerType switch
                    {
                        ProcesserType.X64 => Win32x64GraphicalSampleCpp,
                        ProcesserType.X86 => Win32x86GraphicalSampleCpp,
                        _ => throw new NotImplementedException(),
                    },
                    LaunchType.PipeConsole or LaunchType.Console => processerType switch
                    {
                        ProcesserType.X64 => Win32x64ConsoleSampleCpp,
                        ProcesserType.X86 => Win32x86ConsoleSampleCpp,
                        _ => throw new NotImplementedException(),
                    },
                    _ => throw new NotImplementedException(),
                },
                _ => throw new NotImplementedException(),
            };
        }

        public static SampleRunner GetCppWinRTSampleRunner(LaunchType launchType, ProcesserType processerType)
        {
            return launchType switch
            {
                LaunchType.Graphical => processerType switch
                {
                    ProcesserType.X64 => CppWinRTx64GraphicalSample,
                    ProcesserType.X86 => CppWinRTx86GraphicalSample,
                    _ => throw new NotImplementedException(),
                },
                LaunchType.PipeConsole or LaunchType.Console => processerType switch
                {
                    ProcesserType.X64 => CppWinRTx64ConsoleSample,
                    ProcesserType.X86 => CppWinRTx86ConsoleSample,
                    _ => throw new NotImplementedException(),
                },
                _ => throw new NotImplementedException(),
            };
        }

        public static SampleRunner GetUwpSampleRunner(LaunchType launchType, ProcesserType processerType, CodeLanguage codeLanguage)
        {
            return codeLanguage switch
            {
                CodeLanguage.CppWinRT => launchType switch
                {
                    LaunchType.Graphical => processerType switch
                    {
                        ProcesserType.X64 => CppWinRTx64GraphicalSample,
                        ProcesserType.X86 => CppWinRTx86GraphicalSample,
                        _ => throw new NotImplementedException(),
                    },
                    LaunchType.PipeConsole or LaunchType.Console => processerType switch
                    {
                        ProcesserType.X64 => CppWinRTx64ConsoleSample,
                        ProcesserType.X86 => CppWinRTx86ConsoleSample,
                        _ => throw new NotImplementedException(),
                    },
                    _ => throw new NotImplementedException(),
                },
                CodeLanguage.CSharp => launchType switch
                {
                    LaunchType.Graphical => processerType switch
                    {
                        ProcesserType.X64 => CppWinRTx64GraphicalSample,
                        ProcesserType.X86 => CppWinRTx86GraphicalSample,
                        _ => throw new NotImplementedException(),
                    },
                    LaunchType.PipeConsole or LaunchType.Console => processerType switch
                    {
                        ProcesserType.X64 => CSharpConsoleSampleX64,
                        ProcesserType.X86 => CSharpConsoleSampleX86,
                        _ => throw new NotImplementedException(),
                    },
                    _ => throw new NotImplementedException(),
                },
                _ => throw new NotSupportedException(),
            };
        }

        public async Task<SampleResult> RunSampleAsync(string folderName, string functuonName, string currentDirectory, string input = "")
        {
            return await Task.Run(() =>
            {
                uint returnCode = 0;
                string output = NativeAPI.NativeMethod.StartSampleProcess(ApplicationName, folderName + " " + functuonName + " false", currentDirectory, input, SaveData.WaitTime, ref returnCode);

                return new SampleResult(output, returnCode);
            });
        }

        public async Task<SampleResult> RunSampleAsync(string folderName, string functuonName, string input = "")
        {
            return await Task.Run(() =>
            {
                uint returnCode = 0;
                string output = NativeAPI.NativeMethod.StartSampleProcess(ApplicationName, folderName + " " + functuonName + " false", Environment.CurrentDirectory, input, SaveData.WaitTime, ref returnCode);

                return new SampleResult(output, returnCode);
            });
        }

    }
}
