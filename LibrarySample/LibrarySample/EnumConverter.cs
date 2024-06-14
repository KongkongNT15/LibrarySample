using LibrarySample.Languages;
using LibrarySample.Pages;
using LibrarySample.SampleManagement;
using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public static class EnumConverter
    {
        public static WinRTDesign ToWinRTDesign(string value, WinRTDesign defaultValue = WinRTDesign.XAML)
        {
            return value switch
            {
                "XAML" => WinRTDesign.XAML,
                "CodeOnly" => WinRTDesign.CodeOnly,
                _ => defaultValue,
            };
        }

        public static CodeLanguage ToCodeLanguage(string value)
        {
            return value switch
            {
                "None" => CodeLanguage.None,
                "C" => CodeLanguage.C,
                "CWin32" => CodeLanguage.CWin32,
                "Cpp" => CodeLanguage.Cpp,
                "CppWin32" => CodeLanguage.CppWin32,
                "CppWinRT" => CodeLanguage.CppWinRT,
                "Java" => CodeLanguage.Java,
                "CSharp" => CodeLanguage.CSharp,
                "Text" => CodeLanguage.Text,
                "Xml" => CodeLanguage.Xml,
                "Xaml" => CodeLanguage.Xaml,
                _ => throw new NotImplementedException(),
            };
        }

        public static ElementTheme ToElementTheme(string value, ElementTheme defaultValue = ElementTheme.Default)
        {
            return value switch
            { 
                "Default" => ElementTheme.Default,
                "Dark" => ElementTheme.Dark,
                "Light" => ElementTheme.Light,
                _ => defaultValue,
            };
        }

        public static CVersion ToCLanguage(string value, CVersion defaultValue = CVersion.MinValue)
        {
            return value switch
            {
                "C11" => CVersion.C11,
                "C17" => CVersion.C17,
                "C23" => CVersion.C23,
                "MinValue" => CVersion.MinValue,
                "MaxValue" => CVersion.MaxValue,
                _ => defaultValue
            };
        }

        public static CppVersion ToCppVersion(string value, CppVersion defaultValue = CppVersion.MinValue)
        {
            return value switch
            {
                "Cpp14" => CppVersion.Cpp14,
                "Cpp17" => CppVersion.Cpp17,
                "Cpp20" => CppVersion.Cpp20,
                "Cpp23" => CppVersion.Cpp23,
                "MinValue" => CppVersion.MinValue,
                "MaxValue" => CppVersion.MaxValue,
                _ => defaultValue
            };
        }

        public static ProcesserType ToProcesserType(string value)
        {
            return value switch
            {
                "X86" => ProcesserType.X86,
                "X64" => ProcesserType.X64,
                "Arm64" => ProcesserType.Arm64,
                _ => throw new NotImplementedException()
            };
        }

        public static LaunchType ToLaunchType(string value, LaunchType launchType = LaunchType.PipeConsole)
        {
            return value switch
            {
                "NoSample" => LaunchType.NoSample,
                "Console" => LaunchType.Console,
                "Pipe" => LaunchType.Pipe,
                "PipeConsole" => LaunchType.PipeConsole,
                "Graphical" => LaunchType.Graphical,
                _ => launchType
            };
        }

        public static Library ToLibraryType(Type pageType)
        {
            if (pageType == typeof(CLibraryPage) || pageType == typeof(CStructurePage))
            {
                return Library.C;
            }
            if (pageType == typeof(CppLibraryPage) || pageType == typeof(CppClassPage) || pageType == typeof(CppEnumPage))
            {
                return Library.Cpp;
            }
            if (pageType == typeof(Win32LibraryPage) || pageType == typeof(Win32StructurePage))
            {
                return Library.Win32;
            }
            if (pageType == typeof(CppWinRTNamespacePage) || pageType == typeof(CppWinRTClassPage))
            {
                return Library.CppWinRTNamespace;
            }
            if (pageType == typeof(UwpNamespacePage) || pageType == typeof(UwpClassPage) || pageType == typeof(UwpEnumPage))
            {
                return Library.Uwp;
            }

            throw new ArgumentException();
        }

        public static Library ToLibraryType(string value)
        {
            return value switch
            {
                "C" => Library.C,
                "Cpp" => Library.Cpp,
                "Win32" => Library.Win32,
                "CppWinRTNamespace" => Library.CppWinRTNamespace,
                "Uwp" => Library.Uwp,
                "DotNet" => Library.DotNet,
                _ => throw new NotImplementedException(),
            };
        }

        public static string ToNormalCppVersionName(CppVersion cppVersion)
        {
            return cppVersion.ToString().Replace("pp", "++");
        }

        public static string ToPanelHeader(Category category)
        {
            return category switch
            {
                Category.Class => "クラス",
                Category.Field => "メンバー",
                Category.Function => "関数",
                Category.Structure => "構造体",
                Category.TypeDefinition => "型名",
                _ => throw new Exception(),
            };
        }
    }
}
