using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class Win32CodeViewer : CCodeViewerBase
    {
        public static readonly IReadOnlyList<string> Types = LoadWords("Win32.Type.db");
        public static readonly IReadOnlyList<string> Enums = LoadWords("Win32.Enum.db");
        public static readonly IReadOnlyList<string> FunctionPointers = LoadWords("Win32.FunctionPointer.db");
        public static readonly IReadOnlyList<string> FunctionMacros = LoadWords("Win32.FunctionMacro.db");
        public static readonly IReadOnlyList<string> Macros = LoadWords("Win32.Macro.db");

        public Win32CodeViewer()
        {
            LanguageType = CodeLanguage.CWin32;

            AddList();
        }

        private void AddList()
        {
            KeyBlue.Add(CCodeViewer.KeywordsBlue);
            KeyPurple.Add(CCodeViewer.KeywordsPurple);
            KeyGreen.Add(CCodeViewer.Types);
            KeyMacros.Add(CCodeViewer.Macros);
            KeyFunc.Add(CCodeViewer.Functions);
            KeyFunctionMacro.Add(CCodeViewer.FunctionMacros);

            KeyGreen.Add(Types);
            KeyFunc.Add(FunctionPointers);
            KeyFunctionMacro.Add(FunctionMacros);
            KeyMacros.Add(Macros);
        }
    }
}
