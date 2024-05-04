using Microsoft.UI.Xaml.Documents;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public abstract class CCodeViewerBase : SourceCodeViewer
    {
        private static readonly SolidColorBrush BlueColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x56, 0x9C, 0xD6));
        private static readonly SolidColorBrush GreenColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x4E, 0xC9, 0xB0));
        private static readonly SolidColorBrush PurpleColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0xD8, 0xA0, 0xDF));
        private static readonly SolidColorBrush TyairoColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0xFF, 0xD6, 0x9D, 0x85));
        private static readonly SolidColorBrush GrayColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0xFF, 0x9B, 0x9B, 0x9B));
        private static readonly SolidColorBrush CommentColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0X57, 0xA6, 0x4A));
        private static readonly SolidColorBrush NumberColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XB5, 0xCE, 0xA8));
        private static readonly SolidColorBrush YellowColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XDC, 0xDC, 0xAA));
        private static readonly SolidColorBrush MacroColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XBE, 0xB7, 0xFF));
        private static readonly SolidColorBrush LocalParameterColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0X9C, 0xDC, 0xFE));
        private static readonly SolidColorBrush NamespaceColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XB8, 0xD7, 0xA3));

        private string Mae = string.Empty;

        protected List<List<string>> KeyBlue { get; } = [];
        protected List<List<string>> KeyPurple { get; } = [];
        protected List<List<string>> KeyGreen { get; } = [];
        protected List<List<string>> KeyDefine { get; } = [];
        protected List<List<string>> KeyFunc { get; } = [];
        protected List<List<string>> KeyYellow { get; } = [];
        protected List<List<string>> KeyUserFunction { get; } = [];
        protected List<List<string>> KeyGlobal { get; } = [];
        protected List<List<string>> KeyStatic { get; } = [];
        protected List<List<string>> KeyClassTemplate { get; } = [];
        protected List<List<string>> KeyEnum { get; } = [];
        protected List<List<string>> KeyConcept { get; } = [];
        protected List<List<string>> KeyFunctionMacro { get; } = [];

        private List<string> AddedDefine { get; } = [];
        private List<string> AddedGreen { get; } = [];
        protected List<string> DeletedMacro { get; } = [];

        public bool AutoFunc = true;

        public CCodeViewerBase()
        {
            KeyDefine.Add(AddedDefine);
            KeyGreen.Add(AddedGreen);
        }

        private bool Contains(List<List<string>> lists, string str, bool isMacro = false)
        {
            //#undefで削除されたマクロ
            if (isMacro && DeletedMacro.Contains(str))
            {
                return false;
            }
            foreach (var list in lists)
            {
                if (list.Contains(str)) return true;
            }
            return false;
        }

        private static bool StKey(string str, int i)
        {
            if (i + 1 < str.Length)
            {
                return !Alpha(str[i + 1]);
            }
            return true;
        }

        private static bool Alpha(char c)
        {
            return ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (c == '_' || c == '.');
        }

        private static bool IsDigit(char c)
        {
            return '0' <= c && c <= '9';
        }

        private bool SetColor(Run run, string tmp, string st, int i)
        {
            if (Contains(KeyDefine, tmp, true))
            {
                run.Foreground = MacroColorBrush;
                return true;
            }

            if (Contains(KeyBlue, tmp))
            {
                run.Foreground = BlueColorBrush;
                return true;

            }
            if (Contains(KeyGlobal, tmp))
            {
                run.Foreground = NamespaceColorBrush;
                return true;
            }
            if (Contains(KeyGreen, tmp))
            {

                run.Foreground = GreenColorBrush;
                return true;

            }
            if (Contains(KeyEnum, tmp))
            {

                run.Foreground = GreenColorBrush;
                return true;

            }
            if (Contains(KeyConcept, tmp))
            {
                if (CodeTextBlock.Inlines.Count > 2 && (CodeTextBlock.Inlines[^2] as Run).Text != "requires")
                {
                    Mae = "Concept";
                }
                run.Foreground = GreenColorBrush;
                return true;

            }
            if (Contains(KeyClassTemplate, tmp))
            {
                if (i + 1 < st.Length)
                {
                    if (st[i + 1] == '<')
                    {
                        run.Foreground = GreenColorBrush;
                        return true;
                    }
                }
                if (i + 2 < st.Length)
                {
                    if (st[i + 1] == ':' && st[i + 2] == ':')
                    {
                        run.Foreground = GreenColorBrush;
                        return true;
                    }
                }
            }
            if (Contains(KeyPurple, tmp))
            {
                run.Foreground = PurpleColorBrush;
                return true;
            }
            if (Contains(KeyYellow, tmp))
            {

                run.Foreground = YellowColorBrush;
                return true;

            }
            if (IsDigit(tmp[0]))
            {
                run.Foreground = NumberColorBrush;
                return true;
            }
            return false;
        }

        public override void SetSourceCode(string sourceCode)
        {
            string[] strings = sourceCode.Split(Environment.NewLine);
            for(int index = 0; index < strings.Length; index++)
            {
                string st = strings[index];
                int i = 0;
                while (i < st.Length)
                {
                    Run run = new Run();
                    string tmp = string.Empty;
                    if (Mae == "include")
                    {
                        for (; i < st.Length; ++i)
                        {
                            tmp += st[i];
                        }
                        Mae = string.Empty;
                        run.Text = tmp;
                        run.Foreground = TyairoColorBrush;
                        CodeTextBlock.Inlines.Add(run);
                        ++i;
                        continue;
                    }
                    else if (Mae == "define")
                    {
                        for (; i < st.Length && Alpha(st[i]); ++i)
                        {
                            tmp += st[i];
                        }
                        Mae = string.Empty;
                        AddedDefine.Add(tmp);
                        run.Text = tmp;
                        run.Foreground = MacroColorBrush;
                        CodeTextBlock.Inlines.Add(run);
                        continue;
                    }
                    else if (Mae == "ifdef")
                    {
                        for (; i < st.Length && Alpha(st[i]); ++i)
                        {
                            tmp += st[i];
                        }
                        if (Contains(KeyDefine, tmp, true))
                        {
                            run.Foreground = MacroColorBrush;
                        }
                        run.Text = tmp;
                        Mae = string.Empty;
                        CodeTextBlock.Inlines.Add(run);
                        continue;
                    }
                    else if (Mae == "pragma")
                    {
                        for (; i < st.Length; ++i)
                        {
                            tmp += st[i];
                        }
                        Mae = string.Empty;
                        run.Text = tmp;
                        run.Foreground = GrayColorBrush;
                        CodeTextBlock.Inlines.Add(run);
                        ++i;
                        continue;
                    }
                    else if (Mae == "undef")
                    {
                        for (; i < st.Length; ++i)
                        {
                            tmp += st[i];
                        }

                        DeletedMacro.Add(tmp);

                        Mae = string.Empty;
                        run.Text = tmp;
                        CodeTextBlock.Inlines.Add(run);
                        ++i;
                        continue;
                    }
                    else if (Mae == "comment")
                    {
                        for (; !tmp.Contains("*/") && i < st.Length; ++i)
                        {
                            tmp += st[i];
                        }
                        if (tmp.Contains("*/"))
                        {
                            Mae = string.Empty;
                        }
                        run.Foreground = CommentColorBrush;
                        run.Text = tmp;
                        CodeTextBlock.Inlines.Add(run);
                        continue;
                    }
                    while (i < st.Length)
                    {
                        if (Alpha(st[i]) == false)
                        {
                            if (st[i] == '#')
                            {
                                tmp += st[i];
                                for (++i; i < st.Length; ++i)
                                {
                                    tmp += st[i];
                                    if (st[i] == ' ') break;

                                }
                                run.Foreground = GrayColorBrush;
                                if (tmp == "#include ")
                                {
                                    Mae = "include";
                                }
                                else if (tmp == "#pragma ")
                                {
                                    Mae = "pragma";
                                }
                                else if (tmp == "#define ")
                                {
                                    Mae = "define";
                                }
                                else if (tmp == "#ifdef " || tmp == "#ifndef ")
                                {
                                    Mae = "ifdef";
                                }
                                else if (tmp == "#undef ")
                                {
                                    Mae = "undef";
                                }

                            }
                            else if (st[i] == '{')
                            {
                                tmp += '{';
                                Mae = string.Empty;
                            }
                            else if (st[i] == '/')
                            {
                                tmp += st[i];
                                if (i + 1 < st.Length)
                                {
                                    if (st[i + 1] == '/')
                                    {
                                        for (++i; i < st.Length; ++i)
                                        {
                                            tmp += st[i];
                                        }
                                        run.Foreground = CommentColorBrush;
                                    }
                                    else if (st[i + 1] == '*')
                                    {
                                        for (++i; !tmp.Contains("*/") && i < st.Length; ++i)
                                        {
                                            tmp += st[i];
                                        }
                                        if (tmp.Contains("*/"))
                                        {
                                            --i;
                                        }
                                        else
                                        {
                                            Mae = "comment";
                                        }

                                        run.Foreground = CommentColorBrush;
                                    }
                                }
                            }
                            else if (st[i] == '\"')
                            {
                                tmp += st[i];
                                for (++i; i < st.Length; ++i)
                                {
                                    tmp += st[i];
                                    if (st[i] == '\"' && st[i - 1] != '\\')
                                    {
                                        break;
                                    }
                                }
                                run.Foreground = TyairoColorBrush;
                                if (i < st.Length - 1)
                                {
                                    while (Alpha(st[++i]) && st[i] != '.')
                                    {
                                        tmp += st[i];
                                        if (i == st.Length - 1) break;
                                    }
                                    --i;
                                }


                            }
                            else if (st[i] == '\'')
                            {
                                tmp += st[i];
                                for (++i; i < st.Length; ++i)
                                {
                                    tmp += st[i];
                                    if (st[i] == '\'' && st[i - 1] != '\\')
                                    {
                                        break;
                                    }
                                }
                                run.Foreground = TyairoColorBrush;
                            }
                            else if (st[i] == ':')
                            {
                                if (i + 1 < st.Length)
                                {
                                    if (st[i + 1] == ':')
                                    {
                                        Mae = "::";
                                        tmp += "::";
                                        ++i;
                                        break;
                                    }
                                }
                                tmp += st[i];
                            }
                            else if (st[i] == '-')
                            {
                                if (i + 1 < st.Length)
                                {
                                    if (IsDigit(st[i + 1]))
                                    {
                                        run.Foreground = NumberColorBrush;
                                    }
                                    // (ObjectPointer)->(FieldName)
                                    else if (st[i + 1] == '>')
                                    {
                                        Mae = ".";
                                    }
                                }
                                tmp += '-';
                            }
                            else if (st[i] == ';')
                            {
                                Mae = string.Empty;
                                tmp += ";";
                            }
                            else
                            {
                                tmp += st[i];
                            }
                            break;
                        }
                        tmp += st[i];
                        if (StKey(st, i))
                        {
                            //マクロが最優先
                            if (Contains(KeyDefine, tmp, true))
                            {
                                run.Foreground = MacroColorBrush;
                                Mae = string.Empty;
                                break;
                            }

                            //関数マクロ
                            if (i + 1 < st.Length && st[i + 1] == '(' && Contains(KeyFunctionMacro, tmp, true))
                            {
                                run.Foreground = MacroColorBrush;
                                Mae = string.Empty;
                                break;
                            }

                            //次にキーワード
                            if (Contains(KeyBlue, tmp))
                            {
                                run.Foreground = BlueColorBrush;
                                Mae = string.Empty;
                                break;
                            }

                            if (Mae == "." || Mae == "::")
                            {
                                if (i + 1 < st.Length)
                                {

                                    if (Mae == "::")
                                    {
                                        if (Contains(KeyGreen, tmp))
                                        {
                                            if (st[i + 1] == '(')
                                            {
                                                //run.Foreground = ((CodeTextBlock.Inlines[^2] as Run).Foreground == global) ? green : yellow;
                                                run.Foreground = GreenColorBrush;
                                            }
                                            else
                                            {
                                                run.Foreground = GreenColorBrush;
                                            }
                                            Mae = string.Empty;
                                            break;
                                        }
                                        else if ((CodeTextBlock.Inlines[^2] as Run).Foreground == GreenColorBrush)
                                        {
                                            if (st[i + 1] == '(' || st[i + 1] == '<')
                                            {
                                                Mae = string.Empty;
                                                run.Foreground = YellowColorBrush;
                                                break;
                                            }
                                            else
                                            {
                                                if (Contains(KeyEnum, (CodeTextBlock.Inlines[^2] as Run).Text))
                                                {
                                                    run.Foreground = NamespaceColorBrush;
                                                }
                                                else
                                                {
                                                    run.Foreground = LocalParameterColorBrush;
                                                }
                                                Mae = string.Empty;

                                                break;
                                            }
                                        }
                                        else
                                        {
                                            Mae = string.Empty;
                                            if ((CodeTextBlock.Inlines[^2] as Run).Foreground == NamespaceColorBrush)
                                            {
                                                if (SetColor(run, tmp, st, i)) break;
                                            }
                                            if (st[i + 1] == '(')
                                            {
                                                Mae = string.Empty;
                                                run.Foreground = this.AutoFunc ? YellowColorBrush : LocalParameterColorBrush;
                                                break;
                                            }
                                            else if (st[i + 1] == '<')
                                            {
                                                run.Foreground = YellowColorBrush;
                                                break;
                                            }
                                            else
                                            {
                                                run.Foreground = LocalParameterColorBrush;
                                            }
                                            break;
                                        }

                                    }
                                    if (st[i + 1] == '(' || st[i + 1] == '<')
                                    {
                                        Mae = string.Empty;
                                        run.Foreground = YellowColorBrush;
                                        break;
                                    }
                                    run.Foreground = LocalParameterColorBrush;
                                    Mae = string.Empty;
                                    break;


                                }
                                else
                                {
                                    if (Contains(KeyEnum, (CodeTextBlock.Inlines[^2] as Run).Text))
                                    {
                                        run.Foreground = NamespaceColorBrush;
                                    }
                                    else
                                    {
                                        run.Foreground = LocalParameterColorBrush;
                                    }
                                    Mae = string.Empty;

                                    break;
                                }
                            }

                            if (SetColor(run, tmp, st, i)) break;

                            if (CodeTextBlock.Inlines.Count >= 2)
                            {
                                if (CodeTextBlock.Inlines[^2].Foreground == BlueColorBrush)
                                {
                                    string tmp1 = (CodeTextBlock.Inlines[^2] as Run).Text;

                                    if (tmp1 == "typename" || tmp1 == "class" || tmp1 == "struct" || tmp1 == "using" || tmp1 == "enum" || tmp1 == "union")
                                    {
                                        AddedGreen.Add(tmp);

                                        run.Foreground = GreenColorBrush;
                                        break;
                                    }
                                }
                                if (CodeTextBlock.Inlines[^2].Foreground == GreenColorBrush && Contains(KeyConcept, (CodeTextBlock.Inlines[^2] as Run).Text))
                                {
                                    AddedGreen.Add(tmp);

                                    run.Foreground = GreenColorBrush;
                                    break;
                                }
                            }

                            if (Mae == "Concept")
                            {
                                run.Foreground = GreenColorBrush;
                                AddedGreen.Add(tmp);
                                if ((CodeTextBlock.Inlines[^1] as Run).Text == " ")
                                {
                                    Mae = string.Empty;
                                }

                                break;
                            }

                            if (!AutoFunc)
                            {
                                if (Contains(KeyFunc, tmp))
                                {
                                    if (Mae == "::")
                                    {
                                        Mae = string.Empty;
                                        if (Contains(KeyStatic, tmp))
                                        {
                                            break;
                                        }
                                    }

                                    run.Foreground = YellowColorBrush;
                                    break;
                                }
                                else if (Contains(KeyUserFunction, tmp))
                                {
                                    run.Foreground = YellowColorBrush;
                                    break;
                                }

                            }

                            if (AutoFunc)
                            {
                                if (i + 1 < st.Length)
                                {
                                    if (st[i + 1] == '(' || st[i + 1] == '<')
                                    {
                                        run.Foreground = YellowColorBrush;
                                        Mae = string.Empty;
                                        break;
                                    }
                                }
                            }

                            if (i + 1 < st.Length)
                            {
                                if (st[i + 1] == '\"' || st[i + 1] == '\'')
                                {
                                    run.Foreground = TyairoColorBrush;
                                    break;
                                }
                            }
                            run.Foreground = LocalParameterColorBrush;
                            break;
                        }
                        else
                        {
                            if (tmp == ".")
                            {
                                if (i + 2 < st.Length)
                                {
                                    if (st[i + 1] == '.' && st[i + 2] == '.')
                                    {
                                        tmp = "...";
                                        i += 2;
                                        break;
                                    }
                                }
                                Mae = ".";
                                break;
                            }
                            if (i + 1 < st.Length)
                            {
                                if (st[i + 1] == '.')
                                {
                                    if (!IsDigit(tmp[0]))
                                    {
                                        if (Mae == ".")
                                        {
                                            run.Foreground = LocalParameterColorBrush;
                                            break;
                                        }
                                        if (Contains(KeyGlobal, tmp))
                                        {
                                            run.Foreground = NamespaceColorBrush;
                                        }
                                        else
                                        {
                                            if (i + 3 < st.Length)
                                            {
                                                if (st[i + 2] == '.' && st[i + 3] == '.')
                                                {
                                                    SetColor(run, tmp, st, i);
                                                    break;
                                                }
                                            }
                                            run.Foreground = LocalParameterColorBrush;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        ++i;
                    }
                    run.Text = tmp;
                    CodeTextBlock.Inlines.Add(run);
                    ++i;

                }
                if (index != strings.Length - 1)
                {
                    CodeTextBlock.Inlines.Add(new Run { Text = "\n" });
                }
            }

        }
    }
}
