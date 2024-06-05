using LibrarySample.SampleManagement;
using LibrarySample.Settings;
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

        public static void ApplyClasses(StackPanel rootPanel, XElement xElement, string elementName, string header, Library libraryType, Category category)
        {
            XElement xClasses = xElement.Element(elementName);

            //クラスがなければ何もしない
            if (xClasses == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xClassReference in xClasses.Elements())
            {
                XElement xClass = XmlDocuments.GetDocuments(libraryType)[libraryType.LibraryDirectory() + xClassReference.Attribute("FileName").Value];

                panel.Children.Add(new SlideButton(xClass, libraryType) { Glyph = category.ToGlyph() });
            }
        }

        public static async Task ApplyFunctionsAsync(StackPanel rootPanel, XElement xElement, string elementName, string header, Library libraryType, Category category)
        {
            XElement xFunctions = xElement.Element(elementName);

            //なければ何もしない
            if (xFunctions == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions.Elements())
            {
                panel.Children.Add(FunctionExpander.Create(libraryType, xFunction, category));
                await Task.Delay(1);
            }
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

                valueCard.Glyph = Category.TypeDefinition.ToGlyph();
                valueCard.Title = xTypedef.Attribute("Name").Value;
                valueCard.Description = xTypedef.Attribute("Description").Value;
                valueCard.Value = xTypedef.Attribute("Type")?.Value;

                panel.Children.Add(valueCard);
            }

        }

        public static void ApplyCStructures(StackPanel rootPanel, XElement xElement, Library libraryType)
        {
            XElement xStructures = xElement.Element("Structures");

            if (xStructures != null)
            {
                StackPanel panel = CreateHeaderPanel("構造体");
                rootPanel.Children.Add(panel);

                foreach (XElement xStructure in xStructures.Elements("Structure"))
                {
                    panel.Children.Add(new SlideButton(xStructure, libraryType) { Glyph = Category.Structure.ToGlyph() });
                }
            }
        }

        public static async Task ApplyMacro(Page page, StackPanel rootPanel, XElement xElement, SampleRunner sampleRunner)
        {

            if (xElement.Attribute("HasMacros").Value == "True")
            {
                StackPanel panel = CreateHeaderPanel("マクロ");
                rootPanel.Children.Add(panel);

                string folderName = xElement.Attribute("Tag").Value;
                var result = await sampleRunner.RunSampleAsync(folderName, "?macro");

                var lines = result.Outputs.Split(Environment.NewLine);

                //
                for (int i = 0; i < lines.Length - 1; i += 3)
                {
                    if (lines[i] == lines[i + 1]) continue;

                    ValueCard valueCard = new ValueCard();
                    valueCard.IsTitleTextSelectionEnabled = true;
                    valueCard.IsValueTextSelectionEnabled = true;
                    valueCard.Glyph = Category.Macro.ToGlyph();
                    valueCard.Title = lines[i];
                    valueCard.Value = lines[i + 1];
                    valueCard.Description = lines[i + 2];

                    panel.Children.Add(valueCard);

                    await Task.Delay(1);
                }

                //マクロがなければpanelを削除
                if (panel.Children.Count == 1)
                {
                    rootPanel.Children.Remove(panel);


                }
            }

            //本当に何もなければ
            if (rootPanel.Children.Count == 0)
            {
                page.Content = new TextBlock { Text = "なにも定義されていません", HorizontalAlignment = HorizontalAlignment.Center, VerticalAlignment = VerticalAlignment.Center };
            }
        }

        public static async Task ApplyClassMembersAsync(StackPanel rootPanel, XElement xElement, string elementName, string header, Library libraryType, Category category)
        {
            List<KeyValuePair<XElement, Library>> xFunctions = new List<KeyValuePair<XElement, Library>>();

            await GetBaseClassFunctionsAsync(xFunctions, xElement, libraryType, elementName);

            if (xFunctions.Count == 0) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (var pair in xFunctions)
            {
                panel.Children.Add(FunctionExpander.Create(pair.Value, pair.Key, category));

                await Task.Delay(1);
            }
        }

        public static async Task ApplyClassMembersWinRTAsync(StackPanel rootPanel, XElement xElement, string elementName, string header, Library libraryType, Category category, CodeLanguage codeLanguage)
        {
            List<KeyValuePair<XElement, Library>> xFunctions = new List<KeyValuePair<XElement, Library>>();

            await Task.Run(() =>
            {
                GetBaseClassFunctionsWinRT(xFunctions, xElement, libraryType, elementName, codeLanguage);
            });

            if (xFunctions.Count == 0) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (var pair in xFunctions)
            {
                panel.Children.Add(FunctionExpander.Create(pair.Value, pair.Key, category));

                await Task.Delay(1);
            }
        }

        public static async Task GetBaseClassFunctionsAsync(List<KeyValuePair<XElement, Library>> xElements, XElement xPageRoot, Library libraryType, string elementName, bool ignoreOperatorE = false)
        {
            await Task.Run(() =>
            {
                GetBaseClassFunctions(xElements, xPageRoot, libraryType, elementName, ignoreOperatorE);
            });
        }

        //
        private static void GetBaseClassFunctions(List<KeyValuePair<XElement, Library>> xElements, XElement xPageRoot, Library libraryType, string elementName, bool ignoreOperatorE)
        {

            void applyBase(string cName)
            {
                XElement xBaseClasses = xPageRoot.Element(cName);
                //基底クラスがあれば再起関数
                if (xBaseClasses != null)
                {
                    foreach (XElement xClassReference in xBaseClasses.Elements())
                    {
                        string fileName = xClassReference.Attribute("FileName").Value;

                        //別のライブラリ
                        XAttribute xLibraryType = xClassReference.Attribute("Library");

                        Library classLibraryType = xLibraryType != null ? EnumConverter.ToLibraryType(xLibraryType.Value) : libraryType;

                        XElement xClass = XmlDocuments.GetDocuments(classLibraryType)[classLibraryType.LibraryDirectory() + fileName];
                        GetBaseClassFunctions(xElements, xClass, classLibraryType, elementName, true);
                    }
                }
            }

            applyBase("BaseClasses");

            XElement xFunctuions = xPageRoot.Element(elementName);

            //なければなにもしない
            if (xFunctuions == null) return;

            bool func(XElement xFunction, string name)
            {
                for (int i = 0; i < xElements.Count; i++)
                {
                    string listName = xElements[i].Key.Attribute("Name").Value;

                    //同じメソッドがあれば派生クラスのを使う
                    if (listName == name)
                    {
                        xElements[i] = new KeyValuePair<XElement, Library>(xFunction, libraryType);
                        return true;
                    }

                    if (string.Compare(listName, name) > 0)
                    {
                        xElements.Insert(i, new KeyValuePair<XElement, Library>(xFunction, libraryType));
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

                xElements.Add(new KeyValuePair<XElement, Library>(xFunction, libraryType));
            }
        }

        private static void GetBaseClassFunctionsWinRT(List<KeyValuePair<XElement, Library>> xElements, XElement xPageRoot, Library libraryType, string elementName, CodeLanguage codeLanguage)
        {

            void applyBase(string cName)
            {
                string cName2 = codeLanguage == CodeLanguage.CppWinRT ? "CppWinRTClass" : "CSharpClass";
                XElement xBaseClasses = xPageRoot.Element(cName)?.Element(cName2);
                //基底クラスがあれば再起関数
                if (xBaseClasses != null)
                {
                    foreach (XElement xClassReference in xBaseClasses.Elements())
                    {
                        string fileName = xClassReference.Attribute("FileName").Value;

                        //別のライブラリ
                        XAttribute xLibraryType = xClassReference.Attribute("Library");

                        Library classLibraryType = xLibraryType != null ? EnumConverter.ToLibraryType(xLibraryType.Value) : libraryType;

                        XElement xClass = XmlDocuments.GetDocuments(classLibraryType)[classLibraryType.LibraryDirectory() + fileName];

                        switch (classLibraryType)
                        {
                            case Library.Uwp: GetBaseClassFunctionsWinRT(xElements, xClass, classLibraryType, elementName, codeLanguage); break;
                            default: GetBaseClassFunctions(xElements, xClass, classLibraryType, elementName, true); break;
                        }
                        
                    }
                }
            }

            applyBase("Implements");
            applyBase("BaseClasses");

            XElement xFunctuions = xPageRoot.Element(elementName);

            //なければなにもしない
            if (xFunctuions == null) return;

            bool func(XElement xFunction, string name)
            {
                for (int i = 0; i < xElements.Count; i++)
                {
                    string listName = xElements[i].Key.Attribute("Name").Value;

                    //同じメソッドがあれば派生クラスのを使う
                    if (listName == name)
                    {
                        //xElements[i] = xFunction;
                        xElements[i] = new KeyValuePair<XElement, Library>(xFunction, libraryType);
                        return true;
                    }

                    if (string.Compare(listName, name) > 0)
                    {
                        //xElements.Insert(i, xFunction);
                        xElements.Insert(i, new KeyValuePair<XElement, Library>(xFunction, libraryType));
                        return true;
                    }
                }

                return false;
            }

            foreach (XElement xFunction in xFunctuions.Elements())
            {
                string name = xFunction.Attribute("Name").Value;

                if (func(xFunction, name)) continue;

                xElements.Add(new KeyValuePair<XElement, Library>(xFunction, libraryType));
            }
        }

        public static void ApplyBaseOrDerivedClasses(StackPanel rootPanel, XElement xElement, string elementName, string headerName, Library libraryType)
        {
            XElement xDerivedClasses = xElement.Element(elementName);

            if (xDerivedClasses == null) return;

            StackPanel panel = CreateHeaderPanel(headerName);
            rootPanel.Children.Add(panel);

            foreach (XElement xReference in xDerivedClasses.Elements())
            {
                string fileName = xReference.Attribute("FileName").Value;

                //別のライブラリ
                XAttribute xLibraryType = xReference.Attribute("LibraryType");

                Library classLibraryType = xLibraryType != null ? EnumConverter.ToLibraryType(xLibraryType.Value) : libraryType;

                XElement xClass = XmlDocuments.GetDocuments(classLibraryType)[classLibraryType.LibraryDirectory() + fileName];

                panel.Children.Add(new SlideButton(xClass, classLibraryType) { Glyph = Category.Class.ToGlyph() });
            }
        }

        public static void ApplyBaseOrDerivedClasses(StackPanel rootPanel, XElement xElement, string headerName, Library libraryType)
        {
            if (xElement == null) return;

            StackPanel panel = CreateHeaderPanel(headerName);
            rootPanel.Children.Add(panel);

            foreach (XElement xReference in xElement.Elements())
            {
                string fileName = xReference.Attribute("FileName").Value;

                //別のライブラリ
                XAttribute xLibraryType = xReference.Attribute("Library");

                Library classLibraryType = xLibraryType != null ? EnumConverter.ToLibraryType(xLibraryType.Value) : libraryType;

                XElement xClass = XmlDocuments.GetDocuments(classLibraryType)[classLibraryType.LibraryDirectory() + fileName];

                panel.Children.Add(new SlideButton(xClass, classLibraryType) { Glyph = Category.Class.ToGlyph() });
            }
        }
    }
}
