using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample
{
    internal static class DataLoader
    {

        //NavigationViewのヘッダーに表示するアイテムを取得
        public static string[] CreateHeaderItem(XElement xElement, CodeLanguage languageType)
        {
            List<string> list = [];

            string root = languageType switch
            {
                CodeLanguage.C => "C言語",
                CodeLanguage.Cpp => "C++",
                CodeLanguage.CSharp => "C#",
                CodeLanguage.Java => "Java",
                _ => "Unknown",
            };

            XElement tmp = xElement;

            while (tmp != null)
            {
                list.Add(tmp.Attribute("Name").Value);
                tmp = tmp.Parent;
            }

            list.Add(root);

            list.Reverse();

            return [.. list];
        }
    }
}
