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
        public static string LibraryDirectory(this LibraryType libraryType)
        {
            return libraryType switch
            {
                LibraryType.CLibrary => XmlPath.CLibraryDirectory,
                LibraryType.CppLibrary => XmlPath.CppLibraryDirectory,
                LibraryType.Win32Library => XmlPath.Win32LibraryDirectory,
                LibraryType.CppWinRTNamespaceLibrary => XmlPath.CppWinRTNamespaceLibraryDirectory,
                _ => throw new NotImplementedException(),
            };
        }

        public static string SourceCodeDirectory(this LibraryType libraryType)
        {
            return libraryType switch
            {
                LibraryType.CLibrary => XmlPath.CLibrarySourceCodeDirectory,
                LibraryType.CppLibrary => XmlPath.CppLibrarySourceCodeDirectory,
                LibraryType.Win32Library => XmlPath.Win32LibrarySourceCodeDirectory,
                LibraryType.CppWinRTNamespaceLibrary => XmlPath.CppWinRTNamespaceLibrarySourceCodeDirectory,
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
                Category.Class => "\uEA86",
                Category.Concept => "\uEA86",
                Category.Constructor => "\uF158",
                Category.Destructor => "\uF158",
                Category.Enum => "\uEA86",
                Category.Field => "\uEA86",
                Category.Function => "\uF158",
                Category.FunctionMacro => "\uE71A",
                Category.Literal => "\uEA3A",
                Category.Macro => "\uE71A",
                Category.Method => "\uF158",
                Category.Operator => "\uE710",
                Category.Specialization => "\uEA86",
                Category.Structure => "\uEA86",
                Category.TypeDefinition => "\uEA86",
                _ => throw new Exception()
            };
        }
    }
}
