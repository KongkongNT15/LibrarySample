using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.SampleManagement
{
    public static class XmlPath
    {

        public static readonly string CLibraryDirectory = "../Xml/C/";
        public static readonly string CLibrarySourceCodeDirectory = "../Xml/C/Code/";

        public static readonly string CppLibraryDirectory = "../Xml/Cpp/";
        public static readonly string CppLibrarySourceCodeDirectory = "../Xml/Cpp/Code/";

        public static readonly string Win32LibraryDirectory = "../Xml/Win32/";
        public static readonly string Win32LibrarySourceCodeDirectory = "../Xml/Win32/Code/";

        public static readonly string CppWinRTNamespaceLibraryDirectory = "../Xml/CppWinRTNamespace/";
        public static readonly string CppWinRTNamespaceLibrarySourceCodeDirectory = "../Xml/CppWinRTNamespace/Code/";

        public static readonly string ReleaseNoteFilePath = "../Xml/ReleaseNote.xml";

        public static bool IsCppHeaderXmlFile(string path)
        {
            return path.EndsWith(".hpp.xml");
        }

        public static bool IsCppWinRTNamespaceXmlFile(string path)
        {
            return path.EndsWith(".Namespace.xml");
        }
    }
}
