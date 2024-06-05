using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CSharpCodeViewer : JavaCodeViewerBase
    {
        public static readonly IReadOnlyList<string> KeyWordsBlue = LoadWords(@"CSharp.Blue.db");
        public static readonly IReadOnlyList<string> KeyWordsPurple = LoadWords(@"CSharp.Purple.db");
        public static readonly IReadOnlyList<string> KeyWordsClass = LoadWords(@"CSharp.Class.db");
        public static readonly IReadOnlyList<string> KeyWordsNamespace = LoadWords(@"CSharp.Namespace.db");


        public CSharpCodeViewer()
        {
            LanguageType = CodeLanguage.CSharp;

            KeyBlue.Add(KeyWordsBlue);
            KeyPurple.Add(KeyWordsPurple);
            KeyClass.Add(KeyWordsClass);

            KeyNamespace.Add(KeyWordsNamespace);
        }


    }
}
