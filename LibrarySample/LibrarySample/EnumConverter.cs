﻿using LibrarySample.Languages;
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
                "C++14" => CppVersion.Cpp14,
                "C++17" => CppVersion.Cpp17,
                "C++20" => CppVersion.Cpp20,
                "C++23" => CppVersion.Cpp23,
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

        public static LaunchType ToLaunchType(string value, LaunchType launchType = LaunchType.All)
        {
            return value switch
            {
                "NoSample" => LaunchType.NoSample,
                "Console" => LaunchType.Console,
                "Pipe" => LaunchType.Pipe,
                "All" => LaunchType.All,
                _ => launchType
            };
        }

        public static string ToGlyph(Category sampleType)
        {
            return sampleType switch
            {
                Category.Class => "\uEA86",
                Category.Concept => "\uEA86",
                Category.Constructor => "\uF158",
                Category.Field => "\uEA86",
                Category.Function => "\uF158",
                Category.Macro => "\uE71A",
                Category.Method => "\uF158",
                Category.Operator => "\uE710",
                Category.Structure => "\uEA86",
                Category.TypeDefinition => "\uEA86",
                _ => throw new Exception()
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
