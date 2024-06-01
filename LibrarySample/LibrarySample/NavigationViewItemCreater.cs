using LibrarySample.Pages;
using LibrarySample.SampleManagement;
using LibrarySample.UserControls;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample
{
    public static class NavigationViewItemCreater
    {
        //Cライブラリの追加
        public static async Task AddCLibrary(IList<object> menuItems)
        {
            await AddCWin32Library(menuItems, HomePageData.CHomePageTitle, LibraryType.CLibrary, ImageSources.CImageSource, typeof(CLibraryPage), typeof(CStructurePage));
        }

        //Win32ライブラリの追加
        public static async Task AddWin32Library(IList<object> menuItems)
        {
            await AddCWin32Library(menuItems, HomePageData.Win32HomePageTitle, LibraryType.Win32Library, ImageSources.Win32ImageSource, typeof(Win32LibraryPage), typeof(Win32StructurePage));
        }

        //C
        //Win32
        private static async Task AddCWin32Library(IList<object> menuItems, string homePageTitle, LibraryType libraryType, IconSource iconSource, Type libraryPageType, Type StructurePageType)
        {
            //Cライブラリの追加
            NavigationViewItem headers = new NavigationViewItem { Content = homePageTitle, Icon = iconSource.CreateIconElement() };
            menuItems.Add(headers);

            foreach (var pair in XmlDocuments.GetDocuments(libraryType))
            {
                XElement xElement = pair.Value;

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, libraryPageType);
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //構造体を取得
                XElement xStruct = xElement.Element("Structures");

                if (xStruct != null)
                {
                    foreach (XElement element in xStruct.Elements("Structure"))
                    {
                        string name = element.Attribute("Name").Value;
                        item.MenuItems.Add(new XmlNavigationViewItem(element, StructurePageType) { Glyph = Category.Structure.ToGlyph(), Content = name });
                        await Task.Delay(1);
                    }
                }

                headers.MenuItems.Add(item);

                await Task.Delay(1);
            }
        }

        //C++
        public static async Task AddCppLibrary(IList<object> menuItems)
        {
            NavigationViewItem cppHeaders = new NavigationViewItem { Content = HomePageData.CppHomePageTitle, Icon = ImageSources.CppImageSource.CreateIconElement() };
            menuItems.Add(cppHeaders);


            static async Task createCppClassItem(NavigationViewItem item, XElement xElement, string elementName, Category category, Type pageType)
            {
                XElement xClasses = xElement.Element(elementName);

                if (xClasses != null)
                {
                    foreach (XElement xClassReference in xClasses.Elements("ClassReference"))
                    {
                        XElement xClass = XmlDocuments.CppLibraryDocuments[XmlPath.CppLibraryDirectory + xClassReference.Attribute("FileName").Value];

                        string name = xClass.Attribute("Name").Value.Replace("::", " : : ");

                        item.MenuItems.Add(new XmlNavigationViewItem(xClass, pageType) { Glyph = category.ToGlyph(), Content = name });
                        await Task.Delay(1);
                    }

                }
            }

            foreach (var pair in XmlDocuments.CppLibraryDocuments)
            {
                //へだーのみ
                if (!XmlPath.IsCppHeaderXmlFile(pair.Key)) continue;

                XElement xElement = pair.Value;

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, typeof(CppLibraryPage));
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //クラスを取得
                await createCppClassItem(item, xElement, "Classes", Category.Class, typeof(CppClassPage));
                await createCppClassItem(item, xElement, "Structures", Category.Structure, typeof(CppClassPage));
                await createCppClassItem(item, xElement, "Enums", Category.Enum, typeof(CppEnumPage));

                cppHeaders.MenuItems.Add(item);
                await Task.Delay(1);
            }
        }

        //winrt名前空間の追加
        public static async Task AddWinRTNamespace(IList<object> menuItems)
        {
            NavigationViewItem winrtHeaders = new NavigationViewItem { Content = HomePageData.CppWinRTNamespaceHomePageTitle, Icon = ImageSources.CppWinRTNamespaceImageSource.CreateIconElement() };
            menuItems.Add(winrtHeaders);


            static async Task createClassItem(NavigationViewItem item, XElement xElement, string elementName, Category category, Type pageType)
            {
                XElement xClasses = xElement.Element(elementName);

                if (xClasses == null) return;

                foreach (XElement xClassReference in xClasses.Elements("ClassReference"))
                {
                    XElement xClass = XmlDocuments.CppWinRTNamespaceLibraryDocuments[XmlPath.CppWinRTNamespaceLibraryDirectory + xClassReference.Attribute("FileName").Value];

                    string name = xClass.Attribute("Name").Value;

                    item.MenuItems.Add(new XmlNavigationViewItem(xClass, pageType) { Glyph = category.ToGlyph(), Content = name });
                    await Task.Delay(1);
                }

            }

            foreach (var pair in XmlDocuments.CppWinRTNamespaceLibraryDocuments)
            {
                //へだーのみ
                if (!XmlPath.IsCppWinRTNamespaceXmlFile(pair.Key)) continue;

                XElement xElement = pair.Value;

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, typeof(CppWinRTNamespacePage));
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //クラスを取得
                await createClassItem(item, xElement, "Classes", Category.Class, typeof(CppWinRTClassPage));
                await createClassItem(item, xElement, "Structures", Category.Structure, typeof(CppWinRTClassPage));
                //await createClassItem(item, xElement, "Enums", Category.Enum, typeof(CppEnumPage));

                winrtHeaders.MenuItems.Add(item);
                await Task.Delay(1);
            }
        }
    }
}
