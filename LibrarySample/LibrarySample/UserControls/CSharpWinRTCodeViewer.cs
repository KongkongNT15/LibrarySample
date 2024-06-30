using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CSharpWinRTCodeViewer : JavaCodeViewerBase
    {
        public CSharpWinRTCodeViewer()
        {
            LanguageType = CodeLanguage.CSharp;

            KeyBlue.Add(CSharpCodeViewer.KeyWordsBlue);
            KeyPurple.Add(CSharpCodeViewer.KeyWordsPurple);
            KeyClass.Add(CSharpCodeViewer.KeyWordsClass);
            KeyStructs.Add(CSharpCodeViewer.KeyWordsStruct);
            KeyGenericClass.Add(CSharpCodeViewer.KeyWordsGenericClass);
            KeyGenericInterface.Add(CSharpCodeViewer.KeyWordsGenericInterface);

            KeyClass.Add(CppWinRTCodeViewer.UwpClasss);
            KeyEnum.Add(CppWinRTCodeViewer.UwpEnums);
            KeyStructs.Add(CppWinRTCodeViewer.UwpStructs);
            KeyInterface.Add(CppWinRTCodeViewer.UwpInterfaces);

            KeyNamespace.Add(CSharpCodeViewer.KeyWordsNamespace);
            KeyNamespace.Add(CppWinRTCodeViewer.UwpNamespaces);
        }
    }
}
