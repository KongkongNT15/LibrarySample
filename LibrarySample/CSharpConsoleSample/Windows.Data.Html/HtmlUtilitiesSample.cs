using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Data.Html;

namespace CSharpConsoleSample.Windows.Data.Html
{
    internal static class HtmlUtilitiesSample
    {
        //ConvertToText
        private static void F0()
        {
            string filePath;
            string html;

            if (Program.IsConsole) Console.Write("ファイルのパスを入力: ");
            filePath = Console.ReadLine()?? "";

            using StreamReader streamReader = new StreamReader(filePath);

            html = streamReader.ReadToEnd();

            Console.WriteLine(HtmlUtilities.ConvertToText(html));
        }

        internal static void Run(string tag)
        {
            switch (tag)
            {
                case "ConvertToText": F0(); break;
                default: SampleRunner.RunNotFound(tag); break;
            }

        }
    }
}
