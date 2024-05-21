using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CppCodeViewer : CCodeViewerBase
    {
        public static readonly List<string> KeywordsBlue = GetWords("Cpp.Blue.db");

        public static readonly List<string> KeywordsPurple = GetWords("Cpp.Purple.db");

        public static readonly List<string> KeywordsGreen = GetWords("Cpp.Type.db");

        public static readonly List<string> KeywordsEnum = GetWords("Cpp.Enum.db");

        public static readonly List<string> KeywordClassTemplate = GetWords("Cpp.ClassTemplate.db");

        public static readonly List<string> KeywordsConcept = GetWords("Cpp.Concept.db");

        public static readonly List<string> KeywordsNamespace = GetWords("Cpp.Namespace.db");

        public static readonly List<string> KeywordsYellow = GetWords("Cpp.FunctionPointer.db");

        public static readonly List<string> KeywordsFunction = GetWords("Cpp.Function.db");

        public static readonly List<string> KeywordsDefine = GetWords("Cpp.Macro.db");


        public CppCodeViewer()
        {
            LanguageType = CodeLanguage.Cpp;
            AddList();
        }

        private void AddList()
        {
            //C言語のアレ
            KeyBlue.Add(CCodeViewer.KeywordsBlue);
            KeyPurple.Add(CCodeViewer.KeywordsPurple);
            KeyGreen.Add(CCodeViewer.KeywordsGreen);
            KeyDefine.Add(CCodeViewer.KeywordsDefine);
            KeyFunc.Add(CCodeViewer.KeywordsFunc);
            KeyFunctionMacro.Add(CCodeViewer.KeywordsFunctionMacro);

            KeyBlue.Add(KeywordsBlue);
            KeyPurple.Add(KeywordsPurple);
            KeyGreen.Add(KeywordsGreen);
            KeyYellow.Add(KeywordsYellow);
            KeyGlobal.Add(KeywordsNamespace);
            KeyDefine.Add(KeywordsDefine);
            KeyClassTemplate.Add(KeywordClassTemplate);
            KeyEnum.Add(KeywordsEnum);
            KeyConcept.Add(KeywordsConcept);
            KeyFunc.Add(KeywordsFunction);

            //<cstdbool>のマクロを削除
            DeletedMacro.Add("bool");
            DeletedMacro.Add("true");
            DeletedMacro.Add("false");
        }
    }
}
