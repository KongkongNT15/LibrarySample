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

        public static LibraryType ToLibraryType(Type pageType)
        {
            if (pageType == typeof(CLibraryPage) || pageType == typeof(CStructurePage))
            {
                return LibraryType.CLibrary;
            }
            if (pageType == typeof(CppLibraryPage) || pageType == typeof(CppClassPage) || pageType == typeof(CppEnumPage))
            {
                return LibraryType.CppLibrary;
            }
            if (pageType == typeof(Win32LibraryPage) || pageType == typeof(Win32StructurePage))
            {
                return LibraryType.Win32Library;
            }
            if (pageType == typeof(CppWinRTNamespacePage) || pageType == typeof(CppWinRTClassPage))
            {
                return LibraryType.CppWinRTNamespaceLibrary;
            }

            throw new ArgumentException();
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
