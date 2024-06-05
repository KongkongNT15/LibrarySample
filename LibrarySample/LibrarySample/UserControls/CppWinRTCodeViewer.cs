using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class CppWinRTCodeViewer : CCodeViewerBase
    {
        public static readonly IReadOnlyList<string> WinRTTypes = LoadWords("CppWinRT.Type.db");
        public static readonly IReadOnlyList<string> WinRTNamespaces = LoadWords("CppWinRT.Namespace.db");
        public static readonly IReadOnlyList<string> WinRTClassTemplates = LoadWords("CppWinRT.ClassTemplate.db");
        public static readonly IReadOnlyList<string> UwpEnums = LoadWords("Uwp.Enum.db");
        public static readonly IReadOnlyList<string> UwpNamespaces = LoadWords("Uwp.Namespace.db");
        public static readonly IReadOnlyList<string> UwpClasss = LoadWords("Uwp.Class.db");
        public static readonly IReadOnlyList<string> UwpStructs = LoadWords("Uwp.Struct.db");
        public static readonly IReadOnlyList<string> UwpInterfaces = LoadWords("Uwp.Interface.db");


        public CppWinRTCodeViewer()
        {
            LanguageType = CodeLanguage.CppWinRT;
            AddList();
        }

        private void AddList()
        {
            //C言語のアレ
            KeyBlue.Add(CCodeViewer.KeywordsBlue);
            KeyPurple.Add(CCodeViewer.KeywordsPurple);
            KeyGreen.Add(CCodeViewer.Types);
            KeyMacros.Add(CCodeViewer.Macros);
            KeyFunc.Add(CCodeViewer.Functions);
            KeyFunctionMacro.Add(CCodeViewer.FunctionMacros);

            KeyBlue.Add(CppCodeViewer.KeywordsBlue);
            KeyPurple.Add(CppCodeViewer.KeywordsPurple);
            KeyGreen.Add(CppCodeViewer.Types);
            KeyYellow.Add(CppCodeViewer.FunctionPointers);
            KeyGlobal.Add(CppCodeViewer.Namespaces);
            KeyMacros.Add(CppCodeViewer.Macros);
            KeyClassTemplate.Add(CppCodeViewer.ClassTemplates);
            KeyEnum.Add(CppCodeViewer.Enums);
            KeyConcept.Add(CppCodeViewer.Concepts);
            KeyFunc.Add(CppCodeViewer.Functions);

            //<cstdbool>のマクロを削除
            DeletedMacro.Add("bool");
            DeletedMacro.Add("true");
            DeletedMacro.Add("false");

            KeyGreen.Add(WinRTTypes);
            KeyGreen.Add(UwpClasss);
            KeyGreen.Add(UwpStructs);
            KeyGreen.Add(UwpInterfaces);
            KeyClassTemplate.Add(WinRTClassTemplates);
            KeyEnum.Add(UwpEnums);
            KeyGlobal.Add(WinRTNamespaces);
            KeyGlobal.Add(UwpNamespaces);

        }
    }
}
