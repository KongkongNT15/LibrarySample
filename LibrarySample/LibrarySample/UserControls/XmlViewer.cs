using Microsoft.UI.Xaml.Documents;
using Microsoft.UI.Xaml.Media;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class XmlViewer : SourceCodeViewer
    {
        private static readonly SolidColorBrush TypeName = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0x56, 0x9C, 0xD6));
        private static readonly SolidColorBrush Value = new SolidColorBrush(Windows.UI.Color.FromArgb(0xFF, 0xD6, 0x9D, 0x85));
        private static readonly SolidColorBrush Property = new SolidColorBrush(Windows.UI.Color.FromArgb(0XFF, 0X9C, 0xDC, 0xFE));

        public XmlViewer(bool isXAML = false)
        {
            LanguageType = isXAML ? CodeLanguage.Xaml : CodeLanguage.Xml;
        }

        static bool CanUseName(char ch)
        {
            if ('0' <= ch && ch <= '9') return true;
            if ('A' <= ch && ch <= 'Z') return true;
            if ('a' <= ch && ch <= 'z') return true;
            if (ch == ':') return true;
            if (ch == '.') return true;

            return false;
        }

        public override void SetSourceCode(string sourceCode)
        {
            string mae = "";
            bool In = false;

            string[] lines = sourceCode.Split(Environment.NewLine);

            for(int i = 0; i < lines.Length; i++)
            {
                int j = 0;

                string line = lines[i];

                while (j < line.Length)
                {
                    Run run = new Run();
                    string tmp = string.Empty;

                    if (mae == "<")
                    {
                        In = true;
                        for (; j < line.Length; ++j)
                        {
                            if (!CanUseName(line[j]))
                            {
                                --j;
                                break;
                            }
                            tmp += line[j];
                        }
                        run.Foreground = TypeName;
                        mae = string.Empty;
                    }
                    else if (line[j] == '<')
                    {
                        tmp += '<';
                        if (j + 1 < line.Length)
                        {
                            if (line[j + 1] == '/')
                            {
                                tmp += '/';
                                ++j;
                            }
                        }
                        mae = "<";
                    }
                    else if (line[j] == '\"')
                    {
                        tmp += '\"';

                        for (++j; j < line.Length; ++j)
                        {
                            tmp += line[j];
                            if (line[j] == '\"') break;
                        }
                        run.Foreground = Value;
                    }
                    else if (line[j] == '>')
                    {
                        In = false;
                        tmp += '>';
                    }
                    else
                    {
                        if (In)
                        {
                            if (!CanUseName(line[j]))
                            {
                                tmp += line[j];
                            }
                            else
                            {
                                for (; j < line.Length; ++j)
                                {

                                    if (!CanUseName(line[j]))
                                    {
                                        --j;
                                        break;
                                    }
                                    tmp += line[j];
                                }
                                run.Foreground = Property;
                            }

                        }
                        else
                        {
                            tmp += line[j];
                        }
                    }

                    run.Text = tmp;
                    CodeTextBlock.Inlines.Add(run);
                    ++j;
                }

                if (i != lines.Length - 1)
                {
                    CodeTextBlock.Inlines.Add(new Run { Text = "\n" });
                }
            }
        }
    }
}
