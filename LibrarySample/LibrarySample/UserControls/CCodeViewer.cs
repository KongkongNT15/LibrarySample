using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CCodeViewer : CCodeViewerBase
    {
        public static readonly List<string> KeywordsBlue = GetWords("C.Blue.db");

        public static readonly List<string> KeywordsPurple = GetWords("C.Purple.db");

        public static readonly List<string> KeywordsGreen = GetWords("C.Type.db");

        public static readonly List<string> KeywordsDefine = GetWords("C.Macro.db");

        public static readonly List<string> KeywordsFunctionMacro = GetWords("C.FunctionMacro.db");

        public static readonly List<string> KeywordsFunc = GetWords("C.Function.db");

        public CCodeViewer()
        {
            LanguageType = CodeLanguage.C;
            AddList();
        }

        private void AddList()
        {
            KeyBlue.Add(KeywordsBlue);
            KeyPurple.Add(KeywordsPurple);
            KeyGreen.Add(KeywordsGreen);
            KeyDefine.Add(KeywordsDefine);
            KeyFunc.Add(KeywordsFunc);
            KeyFunctionMacro.Add(KeywordsFunctionMacro);
        }
    }
}
