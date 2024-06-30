using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Diagnostics;
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
        public static readonly IReadOnlyList<string> KeyWordsStruct = LoadWords(@"CSharp.Struct.db");
        public static readonly IReadOnlyList<string> KeyWordsGenericClass = LoadWords(@"CSharp.GenericClass.db");
        //public static readonly IReadOnlyList<string> KeyWordsInterface = LoadWords(@"CSharp.Interface.db");
        public static readonly IReadOnlyList<string> KeyWordsGenericInterface = LoadWords(@"CSharp.GenericInterface.db");
        public static readonly IReadOnlyList<string> KeyWordsNamespace = LoadWords(@"CSharp.Namespace.db");


        public CSharpCodeViewer()
        {
            LanguageType = CodeLanguage.CSharp;

            KeyBlue.Add(KeyWordsBlue);
            KeyPurple.Add(KeyWordsPurple);
            KeyClass.Add(KeyWordsClass);
            KeyStructs.Add(KeyWordsStruct);
            KeyGenericClass.Add(KeyWordsGenericClass);
            KeyGenericInterface.Add(KeyWordsGenericInterface);

            KeyNamespace.Add(KeyWordsNamespace);
        }


    }
}
