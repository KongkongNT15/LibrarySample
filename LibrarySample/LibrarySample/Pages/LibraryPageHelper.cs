using LibrarySample.SampleManagement;
using LibrarySample.UserControls;
using Microsoft.UI.Text;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Media.Core;
using Windows.Networking.Sockets;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace LibrarySample.Pages
{
    public static class LibraryPageHelper
    {
        public static StackPanel CreateHeaderPanel(string header)
        {
            StackPanel panel = new StackPanel();

            panel.Spacing = Data.DefaultStackPanelSpacing;

            TextBlock textBlock = new TextBlock();

            panel.Children.Add(textBlock);

            textBlock.Text = header;
            textBlock.FontSize = Data.SubTitleTextBlockFontSize;
            textBlock.FontWeight = FontWeights.Bold;

            return panel;
        }

        public static InfoBar CreateIncompleteInfoBar()
        {
            InfoBar bar = new InfoBar();

            bar.Title = "不完全なページ";
            bar.Message = "まだここに載っていない項目があります";

            bar.IsOpen = true;
            bar.IsClosable = false;
            bar.Severity = InfoBarSeverity.Warning;

            return bar;
        }

        public static StackPanel CreateHeaderPanel(Category category)
        {
            return CreateHeaderPanel(EnumConverter.ToPanelHeader(category));
        }

        public static void ApplyIncoplete(StackPanel rootPanel, XElement xElement)
        {
            XAttribute xIncomplete = xElement.Attribute("IsIncomplete");

            //nullはFalseとみなす
            if (xIncomplete == null) return;

            //Falseなら何もしない
            if (xIncomplete.Value != "True") return;

            rootPanel.Children.Add(CreateIncompleteInfoBar());
        }

        public static void ApplyClasses(StackPanel rootPanel, XElement xElement, string elementName, string header, string libraryPath, CodeLanguage codeLanguage, Category category)
        {
            XElement xClasses = xElement.Element(elementName);

            //クラスがなければ何もしない
            if (xClasses == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xClassReference in xClasses.Elements())
            {
                XElement xClass = XElement.Load(libraryPath + xClassReference.Attribute("FileName").Value);

                panel.Children.Add(new SlideButton(xClass, codeLanguage) { Glyph = EnumConverter.ToGlyph(category) });
            }
        }

        public static async Task<StackPanel> ApplyCppFunctions(StackPanel rootPanel, XElement xElement, string elementName, string header, Category category)
        {
            XElement xFunctions = xElement.Element(elementName);

            //なければ何もしない
            if (xFunctions == null) return null;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions.Elements())
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, category));
                await Task.Delay(1);
            }

            return panel;
        }

        public static void ApplyTypeDefs(StackPanel rootPanel, XElement xElement, string elementName, string header = "型名")
        {
            XElement xTypeDefs = xElement.Element(elementName);

            //Typedefがなければ何もしない
            if (xTypeDefs == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xTypedef in xTypeDefs.Elements())
            {
                ValueCard valueCard = new ValueCard();

                valueCard.Glyph = EnumConverter.ToGlyph(Category.TypeDefinition);
                valueCard.Title = xTypedef.Attribute("Name").Value;
                valueCard.Description = xTypedef.Attribute("Description").Value;
                valueCard.Value = xTypedef.Attribute("Type")?.Value;

                panel.Children.Add(valueCard);
            }

        }


        public static async Task GetBaseClassFunctionsAsync(List<XElement> xElements, XElement xPageRoot, string elementName, bool ignoreOperatorE = false)
        {
            await Task.Run(() =>
            {
                GetBaseClassFunctions(xElements, xPageRoot, elementName, ignoreOperatorE);
            });
        }

        //
        private static void GetBaseClassFunctions(List<XElement> xElements, XElement xPageRoot, string elementName, bool ignoreOperatorE)
        {
            XElement xBaseClasses = xPageRoot.Element("BaseClasses");
            //基底クラスがあれば再起関数
            if (xBaseClasses != null)
            {
                foreach (XElement xClassReference in  xBaseClasses.Elements())
                {
                    string fileName = xClassReference.Attribute("FileName").Value;
                    XElement xClass = XElement.Load(XmlPath.CppLibraryDirectory + fileName);
                    GetBaseClassFunctions(xElements, xClass, elementName, true);
                }
            }

            XElement xFunctuions = xPageRoot.Element(elementName);

            //なければなにもしない
            if (xFunctuions == null) return;

            bool func(XElement xFunction, string name)
            {
                for (int i = 0; i < xElements.Count; i++)
                {
                    string listName = xElements[i].Attribute("Name").Value;

                    //同じメソッドがあれば派生クラスのを使う
                    if (listName == name)
                    {
                        xElements[i] = xFunction;
                        return true;
                    }

                    if (string.Compare(listName, name) > 0)
                    {
                        xElements.Insert(i, xFunction);
                        return true;
                    }
                }

                return false;
            }

            foreach (XElement xFunction in xFunctuions.Elements())
            {
                string name = xFunction.Attribute("Name").Value;

                if (func(xFunction, name)) continue;

                //operator=は継承しない
                if (ignoreOperatorE && xFunction.Attribute("Name").Value.StartsWith("=(")) continue;

                xElements.Add(xFunction);
            }
        }

        public static void ApplyCppBaseOrDerivedClasses(StackPanel rootPanel, XElement xElement, string elementName, string headerName)
        {
            XElement xDerivedClasses = xElement.Element(elementName);

            if (xDerivedClasses == null) return;

            StackPanel panel = CreateHeaderPanel(headerName);
            rootPanel.Children.Add(panel);

            foreach (XElement xReference in xDerivedClasses.Elements())
            {
                string fileName = xReference.Attribute("FileName").Value;

                XElement xClass = XElement.Load(XmlPath.CppLibraryDirectory + fileName);

                panel.Children.Add(new SlideButton(xClass, CodeLanguage.Cpp) { Glyph = EnumConverter.ToGlyph(Category.Class) });
            }
        }
    }
}
