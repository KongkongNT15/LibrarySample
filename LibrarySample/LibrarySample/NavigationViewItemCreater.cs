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
            await AddCWin32Library(menuItems, HomePageData.CTitle, Library.C, ImageSources.CImageSource, typeof(CLibraryPage), typeof(CStructurePage));
        }

        //Win32ライブラリの追加
        public static async Task AddWin32Library(IList<object> menuItems)
        {
            await AddCWin32Library(menuItems, HomePageData.Win32Title, Library.Win32, ImageSources.Win32ImageSource, typeof(Win32LibraryPage), typeof(Win32StructurePage));
        }

        //C
        //Win32
        private static async Task AddCWin32Library(IList<object> menuItems, string homePageTitle, Library libraryType, IconSource iconSource, Type libraryPageType, Type StructurePageType)
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
            NavigationViewItem cppHeaders = new NavigationViewItem { Content = HomePageData.CppTitle, Icon = ImageSources.CppImageSource.CreateIconElement() };
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

        public static async Task AddCppWinRTNamespace(IList<object> menuItems)
        {
            await AddWinRTNamespace(menuItems, HomePageData.CppWinRTNamespaceTitle, XmlPath.CppWinRTNamespaceLibraryDirectory, Library.CppWinRTNamespace, ImageSources.CppWinRTNamespaceImageSource, typeof(CppWinRTNamespacePage), typeof(CppWinRTClassPage), null);
        }

        public static async Task AddUwpNamespace(IList<object> menuItems)
        {
            await AddWinRTNamespace(menuItems, HomePageData.UwpTitle, XmlPath.UwpLibraryDirectory, Library.Uwp, ImageSources.UwpImageSource, typeof(UwpNamespacePage), typeof(UwpClassPage), typeof(UwpEnumPage));
        }

        //winrt名前空間の追加
        private static async Task AddWinRTNamespace(IList<object> menuItems, string title, string xmlPath, Library libraryType, IconSource iconSource, Type namespaceType, Type classType, Type enumType)
        {
            NavigationViewItem winrtHeaders = new NavigationViewItem { Content = title, Icon = iconSource.CreateIconElement() };
            menuItems.Add(winrtHeaders);


            async Task createClassItem(NavigationViewItem item, XElement xElement, string elementName, Category category, Type pageType)
            {
                XElement xClasses = xElement.Element(elementName);

                if (xClasses == null) return;

                foreach (XElement xClassReference in xClasses.Elements("ClassReference"))
                {
                    XElement xClass = XmlDocuments.GetDocuments(libraryType)[xmlPath + xClassReference.Attribute("FileName").Value];

                    string name = xClass.Attribute("Name").Value;

                    item.MenuItems.Add(new XmlNavigationViewItem(xClass, pageType) { Glyph = category.ToGlyph(), Content = name });
                    await Task.Delay(1);
                }

            }

            foreach (var pair in XmlDocuments.GetDocuments(libraryType))
            {
                //へだーのみ
                if (!XmlPath.IsNamespaceXmlFile(pair.Key)) continue;

                XElement xElement = pair.Value;

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, namespaceType);
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //クラスを取得
                await createClassItem(item, xElement, "Classes", Category.Class, classType);
                await createClassItem(item, xElement, "Structures", Category.Structure, classType);
                await createClassItem(item, xElement, "Interfaces", Category.Interface, classType);
                await createClassItem(item, xElement, "Enums", Category.Enum, enumType);

                winrtHeaders.MenuItems.Add(item);
                await Task.Delay(1);
            }
        }
    }
}
