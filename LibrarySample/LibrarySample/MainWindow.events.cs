using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using LibrarySample.NativeAPI;
using LibrarySample.NativeAPI.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI;
using LibrarySample.Settings;
using LibrarySample.UserControls;
using LibrarySample.Pages;
using Microsoft.UI.Xaml.Navigation;
using System.Xml.Linq;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Input;

namespace LibrarySample
{
    public sealed partial class MainWindow : Window
    {

        private void Buttons_Click(object sender, RoutedEventArgs e)
        {
            ReloadPage();
        }

        //ヘッダーボタンの変更
        private void ContentPageFrame_Navigated(object sender, NavigationEventArgs e)
        {
            ContentPageFrame contentPageFrame = sender as ContentPageFrame;
            SetActiveFramePart(contentPageFrame);
            SetTabContent();

            if (IsNavViewItemInvoked)
            {
                IsNavViewItemInvoked = false;
                return;
            }

            SetSelectedItem(contentPageFrame);

            GC.Collect();
        }

        /// <summary>
        /// タブが多くなるとウィンドウからタブがはみ出るので強引に調整
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void DraggableArea_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            SetDragRegionForCustomTitleBar();
        }

        private void HeaderBar_ItemClicked(BreadcrumbBar sender, BreadcrumbBarItemClickedEventArgs args)
        {
            var itemIndex = args.Index;
            var item = args.Item as string;

            IsNavViewItemInvoked = true;

            int index;

            //選択できるのは階層1まで
            void func()
            {
                foreach (object obj in NavView.MenuItems)
                {
                    index = 0;

                    if (obj is NavigationViewItem navigationViewItem)
                    {
                        if (navigationViewItem.Content as string == item && index == itemIndex)
                        {
                            NavView.SelectedItem = obj;
                            return;
                        }

                        if (itemIndex == 0) continue;

                        foreach (object obj1 in navigationViewItem.MenuItems)
                        {
                            index = 1;

                            if(obj1 is NavigationViewItem navigationViewItem1)
                            {
                                if (navigationViewItem1.Content as string == item && index == itemIndex)
                                {
                                    navigationViewItem.IsExpanded = true;
                                    NavView.SelectedItem = obj1;
                                    return;
                                }
                            }
                        }
                    }

                }
            }

            func();

            NavigateFrame(item, ActiveFrame, ContentPageFrame.SlideFromLeftNavigationTransitionInfo);
        }

        private void Instance_ItemSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ReloadPage();
        }

        private void NavView_BackRequested(NavigationView sender, NavigationViewBackRequestedEventArgs args)
        {
            ActiveFrame.GoBack();
        }

        private void NavView_ItemInvoked(NavigationView sender, NavigationViewItemInvokedEventArgs args)
        {
            if (sender.SelectedItem == NavViewPreviusSelectedItem) return;
            IsNavViewItemInvoked = true;

            NavigateFrame(args.InvokedItem as string, ActiveFrame, ContentPageFrame.EntranceNavigationTransitionInfo);
        }

        private void NavView_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            PointerPoint ptrPt = e.GetCurrentPoint(sender as UIElement);
            if (ptrPt.Properties.IsXButton1Pressed)
            {
                var frame = ActiveFrame;
                if (frame.CanGoBack)
                {
                    frame.GoBack();
                }
            }
        }

        //ヘッダーの内容を変更
        private void NavView_SelectionChanged(NavigationView sender, NavigationViewSelectionChangedEventArgs args)
        {
            NavViewPreviusSelectedItem = sender.SelectedItem;
            //Tabのヘッダー設定
            //(Tabs.SelectedItem as TabViewItem).Header = (NavView.SelectedItem as NavigationViewItem).Content;

            //ホームページの時
            //それぞれの言語のライブラリ一覧の時
            if (sender.SelectedItem is not XmlNavigationViewItem)
            {
                HeaderBar.ItemsSource = new string[] { (sender.SelectedItem as NavigationViewItem).Content as string };
                return;
            }

            //
            XmlNavigationViewItem item = sender.SelectedItem as XmlNavigationViewItem;
            List<string> headerItems = [];

            //ヘッダーのアイテムを設定
            void func(string title)
            {
                headerItems.Add(title);
                foreach (object obj in NavView.MenuItems)
                {
                    if (obj is NavigationViewItem navigationViewItem)
                    {
                        if (navigationViewItem.Content as string == title)
                        {
                            //Header
                            foreach (object obj1 in navigationViewItem.MenuItems)
                            {
                                if (obj1 is NavigationViewItem navigationViewItem1)
                                {
                                    //SelectedItem
                                    if (navigationViewItem1 == item)
                                    {
                                        headerItems.Add(navigationViewItem1.Content as string);
                                        return;
                                    }

                                    //Struct, Class, Enum
                                    foreach (object obj2 in navigationViewItem1.MenuItems)
                                    {
                                        if (obj2 is NavigationViewItem navigationViewItem2)
                                        {
                                            //SelectedItem
                                            if (navigationViewItem2 == item)
                                            {
                                                headerItems.Add(navigationViewItem1.Content as string);
                                                headerItems.Add(navigationViewItem2.Content as string);
                                                return;
                                            }
                                        }
                                    }
                                }
                            }

                            return;
                        }
                    }
                }
            }

            switch (EnumConverter.ToLibraryType(item.PageType))
            {
                case LibraryType.CLibrary: func(HomePageData.CHomePageTitle); break;
                case LibraryType.CppLibrary: func(HomePageData.CppHomePageTitle); break;
                case LibraryType.Win32Library: func(HomePageData.Win32HomePageTitle); break;
                case LibraryType.CppWinRTNamespaceLibrary: func(HomePageData.CppWinRTNamespaceHomePageTitle); break;
            }

            HeaderBar.ItemsSource = headerItems.ToArray();
        }

        /// <summary>
        /// テーマが変更されたときにタイトルバーのキャプションボタンの色を正しく設定する
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        private void RootGrid_ActualThemeChanged(FrameworkElement sender, object args)
        {
            
            if (RootGrid.ActualTheme == ElementTheme.Dark)
            {
                //ダークモード
                AppWindow.TitleBar.ButtonForegroundColor = Color.FromArgb(0xFF, 0xFF, 0xFF, 0xFF);
                AppWindow.TitleBar.ButtonHoverForegroundColor = Color.FromArgb(0xFF, 0xFF, 0xFF, 0xFF);
                AppWindow.TitleBar.ButtonPressedForegroundColor = Color.FromArgb(0xFF, 0xFF, 0xFF, 0xFF);
                AppWindow.TitleBar.ButtonInactiveForegroundColor = Color.FromArgb(0xFF, 0x99, 0x99, 0x99);
                AppWindow.TitleBar.ButtonHoverBackgroundColor = Color.FromArgb(0xFF, 0x2D, 0x2D, 0x2D);
                AppWindow.TitleBar.ButtonPressedBackgroundColor = Color.FromArgb(0xFF, 0x29, 0x29, 0x29);
            }
            else
            {
                //ライトモード
                AppWindow.TitleBar.ButtonForegroundColor = Color.FromArgb(0xFF, 0x00, 0x00, 0x00);
                AppWindow.TitleBar.ButtonHoverForegroundColor = Color.FromArgb(0xFF, 0x00, 0x00, 0x00);
                AppWindow.TitleBar.ButtonPressedForegroundColor = Color.FromArgb(0xFF, 0x00, 0x00, 0x00);
                AppWindow.TitleBar.ButtonInactiveForegroundColor = Color.FromArgb(0xFF, 0x9B, 0x9B, 0x9B);
                AppWindow.TitleBar.ButtonHoverBackgroundColor = Color.FromArgb(0xFF, 0xE9, 0xE9, 0xE9);
                AppWindow.TitleBar.ButtonPressedBackgroundColor = Color.FromArgb(0xFF, 0xED, 0xED, 0xED);

            }
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            SettingWindow.SetActive();
        }

        private void Tabs_AddTabButtonClick(TabView sender, object args)
        {
            
            AddHomePage();
        }

        private void Tabs_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (Tabs.SelectedItem is null) return;
            SetActiveFrame((int)(Tabs.SelectedItem as TabViewItem).Tag);

            ContentPageFrame frame = ActiveFrame;
            SetSelectedItem(frame);

            //タブを変更したときにアプリの設定とページの設定が一致していなければリロード
            switch (frame.CurrentLanguage)
            {
                case LibraryType.CLibrary:
                    ICHandler cHandler = frame.Content as ICHandler;
                    if (cHandler.CVersion != SaveData.CVersion || cHandler.ProcesserType != SaveData.CProcesserType)
                    {
                        ReloadPage();
                    }
                    break;

                case LibraryType.CppLibrary:
                    ICppHandler cppHandler = frame.Content as ICppHandler;
                    if (cppHandler.CppVersion != SaveData.CppVersion || cppHandler.ProcesserType != SaveData.CppProcesserType)
                    {
                        ReloadPage();
                    }
                    break;

                case LibraryType.Win32Library:
                    IWin32Handler win32Handler = frame.Content as IWin32Handler;
                    if (win32Handler.ProcesserType != SaveData.Win32ProcesserType)
                    {
                        ReloadPage();
                    }
                    break;
                case LibraryType.CppWinRTNamespaceLibrary:
                    ICppWinRTHandler cppwinrtHandler = frame.Content as ICppWinRTHandler;
                    if (cppwinrtHandler.ProcesserType != SaveData.CppWinRTNamespaceProcesserType)
                    {
                        ReloadPage();
                    }
                    break;
            }
        }

        private void TabViewItem_CloseRequested(TabViewItem sender, TabViewTabCloseRequestedEventArgs args)
        {
            int tag = (int)sender.Tag;

            //Gridからページを削除
            foreach (UIElement uIElement in ContentsGrid.Children)
            {
                if ((int)(uIElement as Frame).Tag == tag)
                {
                    ContentsGrid.Children.Remove(uIElement);
                    break;
                }
            }

            Tabs.TabItems.Remove(sender);

            if (Tabs.TabItems.Count == 0) Close();
        }

        private void Window_Closed(object sender, WindowEventArgs args)
        {
            MainWindows.Remove(this);

            CHeaderButton.Instance.ItemSelectionChanged -= Instance_ItemSelectionChanged;
            CppHeaderButton.Instance.ItemSelectionChanged -= Instance_ItemSelectionChanged;
            Win32HeaderButton.Instance.SelectionChanged -= Instance_ItemSelectionChanged;
            CppWinRTNamespaceHeaderButton.Instance.SelectionChanged -= Instance_ItemSelectionChanged;

            if (MainWindows.Count == 0)
            {
                SaveData.Save();
                SettingWindow.CloseWindow();
            }
        }

        private void Window_SizeChanged(object sender, WindowSizeChangedEventArgs args)
        {
            bool isZoomed = WinUser.IsZoomed(HWnd) == BOOL.TRUE;

            //状態が変わっていなければ何もしない
            if (isZoomed == IsZoomed) return;

            //以下、状態が変わったとき
            IsZoomed = isZoomed;

            if (isZoomed)
            {
                //最大化
                Tabs.Padding = new Thickness(0);
            }
            else
            {
                //ウィンドウモード
                Tabs.Padding = new Thickness(0, 8, 0, 0);
            }
        }

        //最初にウィンドウを表示するときにアイテムを初期化
        private async void RootGrid_Loaded(object sender, RoutedEventArgs e)
        {
            RootGrid.Loaded -= RootGrid_Loaded;

            ContentDialog contentDialog = new ContentDialog();

            contentDialog.XamlRoot = Content.XamlRoot;
            contentDialog.RequestedTheme = RootGrid.RequestedTheme;
            contentDialog.Title = "準備しています";

            StackPanel panel = new StackPanel { VerticalAlignment = VerticalAlignment.Center };

            panel.Children.Add(new TextBlock { Text = "ページの準備をしています", HorizontalAlignment = HorizontalAlignment.Center });
            panel.Children.Add(new ProgressBar { IsIndeterminate = true, ShowPaused = false, ShowError = false });

            contentDialog.Content = panel;

            panel.Loaded += async (s, e) =>
            {
                await SetNavViewItem();
                contentDialog.Hide();
            };

            _ = await contentDialog.ShowAsync();
        }
    }
}
