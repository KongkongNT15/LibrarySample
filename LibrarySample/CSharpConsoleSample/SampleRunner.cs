using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpConsoleSample.Windows.Data.Html;
using CSharpConsoleSample.Windows.UI;

namespace CSharpConsoleSample
{
    internal static class SampleRunner
    {
        internal static void Run(string rootTag, string sampleTag)
        {
            switch (rootTag)
            {
                case "winrt.Windows.Data.Html.HtmlUtilities.class": HtmlUtilitiesSample.Run(sampleTag); return;
                case "winrt.Windows.UI.Color.struct": ColorSample.Run(sampleTag); return;

                default: RunNotFound(rootTag); return;
            }
        }

        internal static void RunNotFound(string tag)
        {
            Console.Error.WriteLine($"\"{tag}\"が見つかりませんでした");
            Console.Error.WriteLine("ふぁ！？っく");

            Environment.Exit(1);
        }
    }
}
