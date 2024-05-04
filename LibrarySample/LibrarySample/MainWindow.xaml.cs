using LibrarySample.NativeAPI.Win32;
using LibrarySample.Pages;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
using LibrarySample.UserControls;
using Microsoft.UI;
using Microsoft.UI.Composition.SystemBackdrops;
using Microsoft.UI.Windowing;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        private static List<MainWindow> MainWindows { get; } = [];

        public static MainWindow GetParentWindow(FrameworkElement element)
        {

            foreach (MainWindow mainWindow in MainWindows)
            {
                if (mainWindow.Content.XamlRoot == element.XamlRoot) return mainWindow;
            }

            throw new Exception();
        }

        //テーマ変更
        public static void ChangeAllWindowTheme(ElementTheme requestedTheme)
        {
            foreach (MainWindow mainWindow in MainWindows)
            {
                mainWindow.RootGrid.RequestedTheme = requestedTheme;
            }
        }

        private static int _currentIndex = 0;

        /// <summary>
        /// ウィンドウハンドル
        /// </summary>
        public IntPtr HWnd { get; }

        /// <summary>
        /// ウィンドウが最大化されているか
        /// </summary>
        private bool IsZoomed = false;

        /// <summary>
        /// テーマ設定
        /// </summary>
        public ElementTheme RequestedTheme
        {
            get => RootGrid.RequestedTheme;
            set => RootGrid.RequestedTheme = value;
        }

        //ItemInvokedで仕様
        object NavViewPreviusSelectedItem = null;

        //ItemInvokedによってNavigateしたかいなか
        private bool IsNavViewItemInvoked = false;

        //画面に表示されているフレーム
        private ContentPageFrame ActiveFrame
        {
            get
            {
                foreach (UIElement element in ContentsGrid.Children)
                {
                    if (element.Visibility == Visibility.Visible) return element as ContentPageFrame;
                }
                return null;
            }
        }

        public MainWindow()
        {
            MainWindows.Add(this);

            Title = "Library Sample";

            this.SystemBackdrop = new MicaBackdrop { Kind = MicaKind.BaseAlt };

            this.InitializeComponent();

            //テーマの適用
            RootGrid.RequestedTheme = SaveData.RequestedTheme;

            //ウィンドウへのハンドルを取得
            HWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);

            //タイトルバーの変更
            AppWindow.TitleBar.ExtendsContentIntoTitleBar = true;
            AppWindow.TitleBar.ButtonBackgroundColor = Windows.UI.Color.FromArgb(0x00, 0x00, 0x00, 0x00);
            AppWindow.TitleBar.ButtonInactiveBackgroundColor = Windows.UI.Color.FromArgb(0x00, 0x00, 0x00, 0x00);

            //リソースの変更
            SetResources();

            //ふぁ！？っく
            ContentsGrid.Margin = new Thickness(0, Data.NavigationViewContentPadding, 0, 0);

            CHeaderButton.Instance.ItemSelectionChanged += Instance_ItemSelectionChanged;
            CppHeaderButton.Instance.ItemSelectionChanged += Instance_ItemSelectionChanged;
        }

        //リソースの変更
        private void SetResources()
        {
            RootGrid.Resources["NavigationViewHeaderMargin"] = new Thickness(Data.NavigationViewContentPadding, Data.NavigationViewContentPadding - 14, Data.NavigationViewContentPadding, 0);
        }

        private static object SearchMenuItem(XElement element, IList<object> objects)
        {
            foreach (object obj in objects)
            {
                if (obj is XmlNavigationViewItem item)
                {
                    if (item.XElement.ToString() == element.ToString()) return obj;

                    object ret = SearchMenuItem(element, item.MenuItems);
                    if (ret != null) return ret;
                }
            }
            return null;
        }

        private void ReloadPage()
        {
            ContentPageFrame frame = ActiveFrame;

            if (frame.Content is IXml xml)
            {
                XElement xElement = xml.XElement;

                frame.Navigate(frame.CurrentSourcePageType, null, ContentPageFrame.DrillInNavigationTransitionInfo);

                (frame.Content as IXml).XElement = xElement;

                return;
            }

            frame.Navigate(frame.CurrentSourcePageType, null, ContentPageFrame.DrillInNavigationTransitionInfo);
        }

        //左のメニューに項目を追加
        //ホームを表示
        private async void SetNavViewItem()
        {
            IList<object> menuItems = NavView.MenuItems;

            //ホームの追加
            menuItems.Add(new NavigationViewItem { Icon = new SymbolIcon(Symbol.Home), Content = HomePageData.HomePageTitle });
            menuItems.Add(new NavigationViewItemSeparator());

            //Cライブラリの追加
            NavigationViewItem cHeaders = new NavigationViewItem { Content = HomePageData.CHomePageTitle, Icon = ImageSources.CImageSource.CreateIconElement() };
            menuItems.Add(cHeaders);

            foreach (string path in Directory.GetFiles(XmlPath.CLibraryDirectory))
            {
                XElement xElement = XElement.Load(path);

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, typeof(CLibraryPage));
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //構造体を取得
                XElement xStruct = xElement.Element("Structures");

                if (xStruct != null)
                {
                    foreach (XElement element in xStruct.Elements("Structure"))
                    {
                        string name = element.Attribute("Name").Value;
                        item.MenuItems.Add(new XmlNavigationViewItem(element, typeof(CStructurePage)) { Glyph = EnumConverter.ToGlyph(Category.Structure), Content = name });
                        await Task.Delay(1);
                    }
                }

                cHeaders.MenuItems.Add(item);

                await Task.Delay(1);
            }

            //C++ライブラリの追加
            NavigationViewItem cppHeaders = new NavigationViewItem { Content = HomePageData.CppHomePageTitle, Icon = ImageSources.CppImageSource.CreateIconElement() };
            menuItems.Add(cppHeaders);


            static async Task createCppClassItem(NavigationViewItem item, XElement xElement, string elementName, Category category)
            {
                XElement xClasses = xElement.Element(elementName);

                if (xClasses != null)
                {
                    foreach (XElement xClassReference in xClasses.Elements("ClassReference"))
                    {
                        XElement xClass = XElement.Load(XmlPath.CppLibraryDirectory + xClassReference.Attribute("FileName").Value);

                        string name = xClass.Attribute("Name").Value;

                        item.MenuItems.Add(new XmlNavigationViewItem(xClass, typeof(CppClassPage)) { Glyph = EnumConverter.ToGlyph(category), Content = name });
                        await Task.Delay(1);
                    }

                }
            }

            foreach (string path in Directory.GetFiles(XmlPath.CppLibraryDirectory))
            {
                //へだーのみ
                if (!XmlPath.IsCppHeaderXmlFile(path)) continue;

                XElement xElement = XElement.Load(path);

                XmlNavigationViewItem item = new XmlNavigationViewItem(xElement, typeof(CppLibraryPage));
                item.Glyph = xElement.Attribute("Glyph").Value;
                item.Content = xElement.Attribute("Name").Value;

                //クラスを取得
                await createCppClassItem(item, xElement, "Classes", Category.Class);
                await createCppClassItem(item, xElement, "Structures", Category.Structure);

                cppHeaders.MenuItems.Add(item);
                await Task.Delay(1);
            }

            AddHomePage();
        }

        private async void SetSelectedItem(ContentPageFrame contentPageFrame)
        {
            //ホームページの時
            //それぞれの言語のライブラリ一覧の時
            if (contentPageFrame.Content is not IXml)
            {
                string header = contentPageFrame.SourcePageType.Name switch
                {
                    "HomePage" => HomePageData.HomePageTitle,
                    "CHomePage" => HomePageData.CHomePageTitle,
                    "CppHomePage" => HomePageData.CppHomePageTitle,
                    _ => throw new Exception(),
                };

                foreach (object obj in NavView.MenuItems)
                {
                    if (obj is NavigationViewItem navigationViewItem)
                    {
                        if (navigationViewItem.Content as string == header)
                        {
                            NavView.SelectedItem = obj;
                            return;
                        }

                    }
                }
                throw new Exception();

            }

            XElement xElement = null;

            //XElementが設定されるまでメンヘラのように監視
            while (xElement is null)
            {
                xElement = (contentPageFrame.Content as IXml).XElement;
                await Task.Delay(1);
            }

            string xElementString = xElement.ToString();

            foreach (object obj in NavView.MenuItems)
            {
                //
                if (obj is NavigationViewItem item)
                {
                    foreach (object obj1 in item.MenuItems)
                    {
                        //Header
                        if (obj1 is XmlNavigationViewItem item1)
                        {
                            if (item1.XElement.ToString() == xElementString)
                            {
                                item.IsExpanded = true;
                                NavView.SelectedItem = obj1;

                                return;
                            }

                            //
                            foreach (object obj2 in item1.MenuItems)
                            {
                                if(obj2 is XmlNavigationViewItem item2)
                                {
                                    if (item2.XElement.ToString() == xElementString)
                                    {
                                        item.IsExpanded = true;
                                        item1.IsExpanded = true;
                                        NavView.SelectedItem = obj2;

                                        return;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }

            throw new NotImplementedException();
        }

        /// <summary>
        /// frameを表示し、それ以外を不可視にする
        /// </summary>
        /// <param name="frame">表示するフレーム</param>
        private void SetActiveFrame(ContentPageFrame frame)
        {
            foreach (var element in ContentsGrid.Children)
            {
                if (element == frame)
                {
                    SetActiveFramePart(element as ContentPageFrame);
                }
                else
                {
                    element.Visibility = Visibility.Collapsed;
                }

            }
        }

        /// <summary>
        /// tagに一致するframeを表示し、それ以外を不可視にする
        /// </summary>
        /// <param name="tag">タグ</param>
        private void SetActiveFrame(int tag)
        {
            foreach (var element in ContentsGrid.Children)
            {
                if ((int)(element as ContentPageFrame).Tag == tag)
                {
                    SetActiveFramePart(element as ContentPageFrame);
                }
                else
                {
                    element.Visibility = Visibility.Collapsed;
                }
                
            }
        }

        //void SetActiveFrame(int tag)で仕様
        private void SetActiveFramePart(ContentPageFrame contentPageFrame)
        {
            contentPageFrame.Visibility = Visibility.Visible;
            Buttons.SetOtherOptions(contentPageFrame.CurrentLanguage);
            NavView.IsBackEnabled = contentPageFrame.CanGoBack;
        }

        //ホームタブを追加
        private void AddHomePage()
        {
            TabViewItem tabViewItem = new TabViewItem();
            ContentPageFrame frame = new ContentPageFrame();

            tabViewItem.Tag = _currentIndex;
            frame.Tag = _currentIndex;
            frame.Navigated += ContentPageFrame_Navigated;

            frame.Navigate(typeof(HomePage), null, ContentPageFrame.SuppressNavigationTransitionInfo);

            ++_currentIndex;

            ContentsGrid.Children.Add(frame);

            tabViewItem.CloseRequested += TabViewItem_CloseRequested;

            Tabs.TabItems.Add(tabViewItem);

            Tabs.SelectedItem = tabViewItem;

            SetTabContent();
        }

        //
        private async void SetTabContent()
        {
            if (Tabs.SelectedItem == null) return;

            TabViewItem tabViewItem = Tabs.SelectedItem as TabViewItem;

            ContentPageFrame frame = ActiveFrame;

            if (frame.Content is IXml xml)
            {
                XElement xElement = null;

                //XElementが設定されるまでメンヘラのように監視
                while (xElement is null)
                {
                    xElement = xml.XElement;
                    await Task.Delay(1);
                }

                tabViewItem.Header = xElement.Attribute("Name").Value;
            }

            

            tabViewItem.IconSource = frame.CurrentLanguage switch
            {
                CodeLanguage.C => ImageSources.CImageSource,
                CodeLanguage.Cpp => ImageSources.CppImageSource,
                _ => null,
            };

            //上のswitch文でアイコンが設定されていればreturn
            if (tabViewItem.IconSource != null) return;

            if (frame.CurrentSourcePageType == typeof(HomePage))
            {
                tabViewItem.IconSource = ImageSources.HomePageIconSource;
                tabViewItem.Header = HomePageData.HomePageTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(CHomePage))
            {
                tabViewItem.IconSource = ImageSources.CImageSource;
                tabViewItem.Header = HomePageData.CHomePageTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(CppHomePage))
            {
                tabViewItem.IconSource = ImageSources.CppImageSource;
                tabViewItem.Header = HomePageData.CppHomePageTitle;
                return;
            }
            throw new NotImplementedException();
        }

        //タブを追加

        //未完成
        private void AddTab()
        {
            TabViewItem tabViewItem = new();

            ContentPageFrame frame = new();

            frame.Tag = _currentIndex;
            tabViewItem.Tag = _currentIndex;



            SetActiveFrame(frame);

            Tabs.TabItems.Add(tabViewItem);

            Tabs.SelectedItem = tabViewItem;
        }

        //ItemInvoked()からナビゲート
        private void NavigateFrame(string content, ContentPageFrame frame)
        {
            if (NavView.SelectedItem is not XmlNavigationViewItem)
            {

                if (content == HomePageData.HomePageTitle) frame.Navigate(typeof(HomePage));
                else if (content == HomePageData.CHomePageTitle) frame.Navigate(typeof(CHomePage));
                else if(content == HomePageData.CppHomePageTitle) frame.Navigate(typeof(CppHomePage));
                else throw new Exception();

                return;
            }

            var item = NavView.SelectedItem as XmlNavigationViewItem;


            frame.Navigate(item.PageType);

            (frame.Content as IXml).XElement = item.XElement;
        }

        //タイトルバー関連
        private void SetDragRegionForCustomTitleBar()
        {
            // Check to see if customization is supported.
            // The method returns true on Windows 10 since Windows App SDK 1.2, and on all versions of
            // Windows App SDK on Windows 11.

            double wid = RootGrid.ActualWidth - 260.0;
            if (wid >= 0.0)
            {
                Tabs.MaxWidth = wid;
            }

            double scaleAdjustment = WindowAPI.GetScaleAdjustment(HWnd);

            RightPaddingColumn.Width = new GridLength(AppWindow.TitleBar.RightInset / scaleAdjustment);
            LeftPaddingColumn.Width = new GridLength(AppWindow.TitleBar.LeftInset / scaleAdjustment);

            List<Windows.Graphics.RectInt32> dragRectsList = new();

            Windows.Graphics.RectInt32 dragRectL;
            dragRectL.X = (int)((LeftPaddingColumn.ActualWidth) * scaleAdjustment);
            dragRectL.Y = 0;
            dragRectL.Height = (int)(TitleBar.ActualHeight * scaleAdjustment);
            dragRectL.Width = (int)(LeftDragColumn.ActualWidth * scaleAdjustment);
            dragRectsList.Add(dragRectL);

            Windows.Graphics.RectInt32 dragRectR;
            dragRectR.X = (int)((LeftPaddingColumn.ActualWidth
                                + LeftDragColumn.ActualWidth
                                + TabColumn.ActualWidth) * scaleAdjustment);
            dragRectR.Y = 0;
            dragRectR.Height = (int)(TitleBar.ActualHeight * scaleAdjustment);
            dragRectR.Width = (int)(RightDragColumn.ActualWidth * scaleAdjustment);
            dragRectsList.Add(dragRectR);

            Windows.Graphics.RectInt32[] dragRects = dragRectsList.ToArray();

            AppWindow.TitleBar.SetDragRectangles(dragRects);

        }

        
    }
}
