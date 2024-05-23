using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CppCodeViewer : CCodeViewerBase
    {
        public static readonly IReadOnlyList<string> KeywordsBlue = LoadWords("Cpp.Blue.db");

        public static readonly IReadOnlyList<string> KeywordsPurple = LoadWords("Cpp.Purple.db");

        public static readonly IReadOnlyList<string> Types = LoadWords("Cpp.Type.db");

        public static readonly IReadOnlyList<string> Enums = LoadWords("Cpp.Enum.db");

        public static readonly IReadOnlyList<string> ClassTemplates = LoadWords("Cpp.ClassTemplate.db");

        public static readonly IReadOnlyList<string> Concepts = LoadWords("Cpp.Concept.db");

        public static readonly IReadOnlyList<string> Namespaces = LoadWords("Cpp.Namespace.db");

        public static readonly IReadOnlyList<string> FunctionPointers = LoadWords("Cpp.FunctionPointer.db");

        public static readonly IReadOnlyList<string> Functions = LoadWords("Cpp.Function.db");

        public static readonly IReadOnlyList<string> Macros = LoadWords("Cpp.Macro.db");


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
            KeyGreen.Add(CCodeViewer.Types);
            KeyMacros.Add(CCodeViewer.Macros);
            KeyFunc.Add(CCodeViewer.Functions);
            KeyFunctionMacro.Add(CCodeViewer.FunctionMacros);

            KeyBlue.Add(KeywordsBlue);
            KeyPurple.Add(KeywordsPurple);
            KeyGreen.Add(Types);
            KeyYellow.Add(FunctionPointers);
            KeyGlobal.Add(Namespaces);
            KeyMacros.Add(Macros);
            KeyClassTemplate.Add(ClassTemplates);
            KeyEnum.Add(Enums);
            KeyConcept.Add(Concepts);
            KeyFunc.Add(Functions);

            //<cstdbool>のマクロを削除
            DeletedMacro.Add("bool");
            DeletedMacro.Add("true");
            DeletedMacro.Add("false");
        }
    }
}
