using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CCodeViewer : CCodeViewerBase
    {
        public static readonly IReadOnlyList<string> KeywordsBlue = LoadWords("C.Blue.db");

        public static readonly IReadOnlyList<string> KeywordsPurple = LoadWords("C.Purple.db");

        public static readonly IReadOnlyList<string> Types = LoadWords("C.Type.db");

        public static readonly IReadOnlyList<string> Macros = LoadWords("C.Macro.db");

        public static readonly IReadOnlyList<string> FunctionMacros = LoadWords("C.FunctionMacro.db");

        public static readonly IReadOnlyList<string> Functions = LoadWords("C.Function.db");

        public CCodeViewer()
        {
            LanguageType = CodeLanguage.C;
            AddList();
        }

        private void AddList()
        {
            KeyBlue.Add(KeywordsBlue);
            KeyPurple.Add(KeywordsPurple);
            KeyGreen.Add(Types);
            KeyMacros.Add(Macros);
            KeyFunc.Add(Functions);
            KeyFunctionMacro.Add(FunctionMacros);
        }
    }
}
