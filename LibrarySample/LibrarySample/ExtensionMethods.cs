using LibrarySample.SampleManagement;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public static class ExtensionMethods
    {
        public static string LibraryDirectory(this Library libraryType)
        {
            return libraryType switch
            {
                Library.C => XmlPath.CLibraryDirectory,
                Library.Cpp => XmlPath.CppLibraryDirectory,
                Library.Win32 => XmlPath.Win32LibraryDirectory,
                Library.CppWinRTNamespace => XmlPath.CppWinRTNamespaceLibraryDirectory,
                Library.Uwp => XmlPath.UwpLibraryDirectory,
                Library.DotNet => XmlPath.DotNetLibraryDirectory,
                _ => throw new NotImplementedException(),
            };
        }

        public static string SourceCodeDirectory(this Library libraryType)
        {
            return libraryType switch
            {
                Library.C => XmlPath.CLibrarySourceCodeDirectory,
                Library.Cpp => XmlPath.CppLibrarySourceCodeDirectory,
                Library.Win32 => XmlPath.Win32LibrarySourceCodeDirectory,
                Library.CppWinRTNamespace => XmlPath.CppWinRTNamespaceLibrarySourceCodeDirectory,
                Library.Uwp => XmlPath .UwpLibrarySourceCodeDirectory,
                Library.DotNet => XmlPath.DotNetLibrarySourceCodeDirectory,
                _ => throw new NotImplementedException(),
            };
        }

        public static bool IsFunctionType(this Category category)
        {
            switch (category)
            {
                case Category.Constructor:
                case Category.Function:
                case Category.FunctionMacro:
                case Category.Literal:
                case Category.Method:
                case Category.Operator:
                    return true;
            }

            return false;
        }

        public static string ToGlyph(this Category sampleType)
        {
            return sampleType switch
            {
                Category.Class => "\uECAA",
                Category.Concept => "\uEA86",
                Category.Constructor => "\uF158",
                Category.Destructor => "\uF158",
                Category.Delegate => "\uEC57",
                Category.Enum => "\uE8FD",
                Category.Event => "\uEC57",
                Category.Field => "\uEA86",
                Category.Function => "\uF158",
                Category.FunctionMacro => "\uE71A",
                Category.Interface => "\uF57B",
                Category.Literal => "\uEA3A",
                Category.Macro => "\uE71A",
                Category.Method => "\uF158",
                Category.Operator => "\uE710",
                Category.Property => "\uEA86",
                Category.Specialization => "\uECAA",
                Category.Structure => "\uECA5",
                Category.TypeDefinition => "\uEA86",
                _ => throw new Exception()
            };
        }
    }
}
