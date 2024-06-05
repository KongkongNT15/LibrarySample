using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI;

namespace CSharpConsoleSample.Windows.UI
{
    internal static class ColorSample
    {
        //ToString
        private static void F0()
        {
            byte a, r, g, b;

            if (Program.IsConsole) Console.Write("アルファ: ");
            a = byte.Parse(Console.ReadLine()?? "");

            if (Program.IsConsole) Console.Write("赤: ");
            r = byte.Parse(Console.ReadLine()?? "");

            if (Program.IsConsole) Console.Write("緑: ");
            g = byte.Parse(Console.ReadLine()?? "");

            if (Program.IsConsole) Console.Write("青: ");
            b = byte.Parse(Console.ReadLine()?? "");

            Color color = Color.FromArgb(a, r, g, b);

            Console.WriteLine($"A: {a}, R: {r}, G: {g}, B: {b}");
            Console.WriteLine($"Color: {color}");
        }

        internal static void Run(string tag)
        {
            switch (tag)
            {
                case "ToString": F0(); return;

                default: SampleRunner.RunNotFound(tag); return;
            }

        }


    }
}
