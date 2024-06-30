using Microsoft.UI.Xaml.Documents;
using Microsoft.UI.Xaml.Media;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public abstract class JavaCodeViewerBase : SourceCodeViewer
    {
        private static readonly SolidColorBrush BlueColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x56, 0x9C, 0xD6));
        private static readonly SolidColorBrush ClassColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x4E, 0xC9, 0xB0));
        private static readonly SolidColorBrush StructColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x86, 0xC6, 0x91));
        private static readonly SolidColorBrush InterfaceColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0xB8, 0xD7, 0xA3));
        private static readonly SolidColorBrush EnumColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0xB8, 0xD7, 0xA3));
        private static readonly SolidColorBrush PurpleColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0xD8, 0xA0, 0xDF));
        private static readonly SolidColorBrush TyairoColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0xFF, 0xD6, 0x9D, 0x85));
        //private static readonly SolidColorBrush GrayColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0xFF, 0x9B, 0x9B, 0x9B));
        private static readonly SolidColorBrush CommentColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0X57, 0xA6, 0x4A));
        private static readonly SolidColorBrush NumberColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XB5, 0xCE, 0xA8));
        private static readonly SolidColorBrush YellowColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XDC, 0xDC, 0xAA));
        //private static readonly SolidColorBrush MacroColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XBE, 0xB7, 0xFF));
        private static readonly SolidColorBrush LocalParameterColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0X9C, 0xDC, 0xFE));
        private static readonly SolidColorBrush NamespaceColorBrush = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0XB8, 0xD7, 0xA3));

        protected List<IReadOnlyList<string>> KeyBlue { get; } = [];
        protected List<IReadOnlyList<string>> KeyPurple { get; } = [];
        protected List<IReadOnlyList<string>> KeyClass { get; } = [];
        protected List<IReadOnlyList<string>> KeyStructs { get; } = [];
        protected List<IReadOnlyList<string>> KeyFunc { get; } = [];
        protected List<IReadOnlyList<string>> KeyYellow { get; } = [];
        protected List<IReadOnlyList<string>> KeyNamespace { get; } = [];
        protected List<IReadOnlyList<string>> KeyGenericClass { get; } = [];
        protected List<IReadOnlyList<string>> KeyGenericInterface { get; } = [];
        protected List<IReadOnlyList<string>> KeyEnum { get; } = [];
        protected List<IReadOnlyList<string>> KeyInterface { get; } = [];

        private List<string> AddedClass { get; } = [];
        private List<string> AddedStruct { get; } = [];
        private readonly List<string> AddedEnum = [];

        private string Mae = "";

        public JavaCodeViewerBase()
        {
            KeyClass.Add(AddedClass);
            KeyStructs.Add(AddedStruct);
            KeyEnum.Add(AddedEnum);
        }

        private static bool Contains(List<IReadOnlyList<string>> lists, string str, bool isMacro = false)
        {
            foreach (var list in lists)
            {
                if (list.Contains(str)) return true;
            }
            return false;
        }

        private static bool Alpha(char c)
        {
            return ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (c == '_' || c == '.');
        }

        private static bool StKey(string str, int i)
        {
            if (i + 1 < str.Length)
            {
                return !Alpha(str[i + 1]);
            }
            return true;
        }

        private bool SetColor(Run run, string tmp, string st, int i)
        {
            if (Contains(KeyBlue, tmp))
            {
                run.Foreground = BlueColorBrush;
                return true;

            }
            if (Contains(KeyNamespace, tmp))
            {
                run.Foreground = NamespaceColorBrush;
                return true;
            }
            if (Contains(KeyClass, tmp))
            {

                run.Foreground = ClassColorBrush;
                return true;

            }
            if (Contains(KeyStructs, tmp))
            {

                run.Foreground = StructColorBrush;
                return true;

            }
            if (Contains(KeyInterface, tmp))
            {

                run.Foreground = InterfaceColorBrush;
                return true;

            }
            if (Contains(KeyEnum, tmp))
            {
                if (i + 2 < st.Length)
                {
                    run.Foreground = st[i + 2] == '=' ? LocalParameterColorBrush : EnumColorBrush;
                    return true;
                }
                run.Foreground = EnumColorBrush;
                return true;

            }
            if (Contains(KeyGenericClass, tmp))
            {
                if (i + 1 < st.Length)
                {
                    if (st[i + 1] == '<')
                    {
                        run.Foreground = ClassColorBrush;
                        return true;
                    }
                }
            }
            if (Contains(KeyGenericInterface, tmp))
            {
                if (i + 1 < st.Length)
                {
                    if (st[i + 1] == '<')
                    {
                        run.Foreground = InterfaceColorBrush;
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
            if (char.IsDigit(tmp[0]))
            {
                run.Foreground = NumberColorBrush;
                return true;
            }
            return false;
        }

        public override void SetSourceCode(string sourceCode)
        {
            string[] strings = sourceCode.Split(Environment.NewLine);
            for (int index = 0; index < strings.Length; index++)
            {
                string st = strings[index];
                int i = 0;
                while (i < st.Length)
                {
                    Run run = new Run();
                    string tmp = string.Empty;
                    if (Mae == "comment")
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
                            if (st[i] == '{')
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
                                    if (st[i] == '\"')
                                    {
                                        if (st[i - 1] != '\\') break;
                                        if (i - 2 < 0) break;

                                        //"...\\"パターン
                                        if (st[i - 2] == '\\') break;
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
                            else if (st[i] == '-')
                            {
                                if (i + 1 < st.Length)
                                {
                                    if (char.IsDigit(st[i + 1]))
                                    {
                                        run.Foreground = NumberColorBrush;
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


                            //次にキーワード
                            if (Contains(KeyBlue, tmp))
                            {
                                run.Foreground = BlueColorBrush;
                                Mae = string.Empty;
                                break;
                            }

                            if (Mae == ".")
                            {
                                if (i + 1 < st.Length)
                                {

                                    if (Contains(KeyClass, tmp))
                                    {
                                        if (st[i + 1] == '(')
                                        {
                                            //run.Foreground = ((CodeTextBlock.Inlines[^2] as Run).Foreground == global) ? green : yellow;
                                            run.Foreground = ClassColorBrush;
                                        }
                                        else
                                        {
                                            run.Foreground = ClassColorBrush;
                                        }
                                        Mae = string.Empty;
                                        break;
                                    }
                                    else if ((CodeTextBlock.Inlines[^2] as Run).Foreground == EnumColorBrush)
                                    {
                                        if (Contains(KeyEnum, (CodeTextBlock.Inlines[^2] as Run).Text))
                                        {
                                            //run.Foreground = NamespaceColorBrush;
                                        }
                                        else
                                        {
                                            run.Foreground = LocalParameterColorBrush;
                                        }
                                        Mae = string.Empty;

                                        break;

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
                                            run.Foreground = YellowColorBrush;
                                            break;
                                        }
                                        else if (st[i + 1] == '<')
                                        {
                                            run.Foreground = YellowColorBrush;
                                            break;
                                        }
                                        else
                                        {
                                            if (SetColor(run, tmp, st, i)) break;
                                            run.Foreground = LocalParameterColorBrush;
                                        }
                                        break;
                                    }


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
                                    switch (tmp1)
                                    {
                                        case "class":
                                            AddedClass.Add(tmp);
                                            run.Foreground = ClassColorBrush;
                                            break;

                                        case "struct":
                                            AddedStruct.Add(tmp);
                                            run.Foreground = StructColorBrush;
                                            break;

                                        case "enum":
                                            AddedEnum.Add(tmp);
                                            run.Foreground = TyairoColorBrush;
                                            break;
                                    }
                                }
                            }
                            if (i + 1 < st.Length)
                            {
                                if (st[i + 1] == '(' || st[i + 1] == '<')
                                {
                                    run.Foreground = YellowColorBrush;
                                    Mae = string.Empty;
                                    break;
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
                                    if (!char.IsDigit(tmp[0]))
                                    {
                                        if (Mae == ".")
                                        {
                                            if (SetColor(run, tmp, st, i)) break;
                                            run.Foreground = LocalParameterColorBrush;
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
                                            if (SetColor(run, tmp, st, i)) break;
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
