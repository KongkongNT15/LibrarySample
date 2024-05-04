using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class TextViewer : SourceCodeViewer
    {
        public TextViewer()
        {
            LanguageType = CodeLanguage.Text;
        }

        public override void SetSourceCode(string sourceCode)
        {
            CodeTextBlock.Text = sourceCode;
        }

    }
}
