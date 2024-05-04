using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public static class XmlPath
    {
        public static readonly string CLibraryDirectory = "../Xml/C/";
        public static readonly string CLibrarySourceCodeDirectory = "../Xml/C/Code/";

        public static readonly string CppLibraryDirectory = "../Xml/Cpp/";
        public static readonly string CppLibrarySourceCodeDirectory = "../Xml/Cpp/Code/";

        public static readonly string ReleaseNoteFilePath = "../Xml/ReleaseNote.xml";

        public static bool IsCppHeaderXmlFile(string path)
        {
            return path.EndsWith(".hpp.xml");
        }
    }
}
