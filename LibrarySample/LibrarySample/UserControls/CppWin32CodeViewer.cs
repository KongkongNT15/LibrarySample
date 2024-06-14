using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class CppWin32CodeViewer : CCodeViewerBase
    {
        public CppWin32CodeViewer()
        {
            LanguageType = CodeLanguage.CppWin32;

            KeyBlue.Add(CCodeViewer.KeywordsBlue);
            KeyPurple.Add(CCodeViewer.KeywordsPurple);
            KeyGreen.Add(CCodeViewer.Types);
            KeyMacros.Add(CCodeViewer.Macros);
            KeyFunc.Add(CCodeViewer.Functions);
            KeyFunctionMacro.Add(CCodeViewer.FunctionMacros);

            KeyGreen.Add(Win32CodeViewer.Types);
            KeyFunc.Add(Win32CodeViewer.FunctionPointers);
            KeyFunctionMacro.Add(Win32CodeViewer.FunctionMacros);
            KeyMacros.Add(Win32CodeViewer.Macros);

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
        }
    }
}
