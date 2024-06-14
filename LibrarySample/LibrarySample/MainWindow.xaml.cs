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
using Microsoft.UI.Xaml.Media.Animation;
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

        //�e�[�}�ύX
        public static void ChangeAllWindowTheme(ElementTheme requestedTheme)
        {
            foreach (MainWindow mainWindow in MainWindows)
            {
                mainWindow.RootGrid.RequestedTheme = requestedTheme;
            }
        }

        private static int _currentIndex = 0;

        /// <summary>
        /// �E�B���h�E�n���h��
        /// </summary>
        public IntPtr HWnd { get; }

        /// <summary>
        /// �E�B���h�E���ő剻����Ă��邩
        /// </summary>
        private bool IsZoomed = false;

        /// <summary>
        /// �e�[�}�ݒ�
        /// </summary>
        public ElementTheme RequestedTheme
        {
            get => RootGrid.RequestedTheme;
            set => RootGrid.RequestedTheme = value;
        }

        //ItemInvoked�Ŏd�l
        object NavViewPreviusSelectedItem = null;

        //ItemInvoked�ɂ����Navigate���������Ȃ�
        private bool IsNavViewItemInvoked = false;

        //��ʂɕ\������Ă���t���[��
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

            //�A�C�R���ݒ�
            AppWindow.SetIcon("Assets/AppIcon.ico");

            this.InitializeComponent();

            //�e�[�}�̓K�p
            RootGrid.RequestedTheme = SaveData.RequestedTheme;

            //�E�B���h�E�ւ̃n���h�����擾
            HWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);

            //�^�C�g���o�[�̕ύX
            AppWindow.TitleBar.ExtendsContentIntoTitleBar = true;
            AppWindow.TitleBar.ButtonBackgroundColor = Windows.UI.Color.FromArgb(0x00, 0x00, 0x00, 0x00);
            AppWindow.TitleBar.ButtonInactiveBackgroundColor = Windows.UI.Color.FromArgb(0x00, 0x00, 0x00, 0x00);

            //���\�[�X�̕ύX
            SetResources();

            //�ӂ��I�H����
            ContentsGrid.Margin = new Thickness(0, Data.NavigationViewContentPadding, 0, 0);

            CHeaderButton.Instance.ItemSelectionChanged += Instance_ItemSelectionChanged;
            CppHeaderButton.Instance.ItemSelectionChanged += Instance_ItemSelectionChanged;
            Win32HeaderButton.Instance.SelectionChanged += Instance_ItemSelectionChanged;
            CppWinRTNamespaceHeaderButton.Instance.SelectionChanged += Instance_ItemSelectionChanged;
            UwpHeaderButton.Instance.ItemSelectionChanged += Instance_ItemSelectionChanged;
        }

        //���\�[�X�̕ύX
        private void SetResources()
        {
            RootGrid.Resources["NavigationViewHeaderMargin"] = new Thickness(Data.NavigationViewContentPadding, Data.NavigationViewContentPadding - 14, Data.NavigationViewContentPadding, 0);
        }

        //���̃��j���[�ɍ��ڂ�ǉ�
        //�z�[����\��
        private async Task SetNavViewItem()
        {
            IList<object> menuItems = NavView.MenuItems;

            //�z�[���̒ǉ�
            menuItems.Add(new NavigationViewItem { Icon = new SymbolIcon(Symbol.Home), Content = HomePageData.HomePageTitle });
            menuItems.Add(new NavigationViewItemSeparator());

            AddHomePage();

            await XmlDocuments.LoadDocumentsAsync();

            await NavigationViewItemCreater.AddCLibrary(menuItems);

            //C++���C�u�����̒ǉ�
            await NavigationViewItemCreater.AddCppLibrary(menuItems);

            await NavigationViewItemCreater.AddWin32Library(menuItems);

            await NavigationViewItemCreater.AddCppWinRTNamespace(menuItems);

            await NavigationViewItemCreater.AddUwpNamespace(menuItems);
        }



        private async void SetSelectedItem(ContentPageFrame contentPageFrame)
        {
            //�z�[���y�[�W�̎�
            //���ꂼ��̌���̃��C�u�����ꗗ�̎�
            if (contentPageFrame.Content is not IXml)
            {
                string header = contentPageFrame.SourcePageType.Name switch
                {
                    "HomePage" => HomePageData.HomePageTitle,
                    "CHomePage" => HomePageData.CTitle,
                    "CppHomePage" => HomePageData.CppTitle,
                    "Win32HomePage" => HomePageData.Win32Title,
                    "CppWinRTNamespaceHomePage" => HomePageData.CppWinRTNamespaceTitle,
                    "UwpHomePage" => HomePageData.UwpTitle,
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

            //XElement���ݒ肳���܂Ń����w���̂悤�ɊĎ�
            while (xElement is null)
            {
                xElement = (contentPageFrame.Content as IXml).XElement;
                await Task.Delay(1);
            }

            foreach (object obj in NavView.MenuItems)
            {
                //
                if (obj is NavigationViewItem item)
                {
                    foreach (object obj1 in item.MenuItems)
                    {
                        //Header
                        //Namespace
                        if (obj1 is XmlNavigationViewItem item1)
                        {
                            if (item1.XElement == xElement)
                            {
                                item.IsExpanded = true;
                                NavView.SelectedItem = obj1;

                                return;
                            }

                            //
                            foreach (object obj2 in item1.MenuItems)
                            {
                                if (obj2 is XmlNavigationViewItem item2)
                                {
                                    if (item2.XElement == xElement)
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
        /// frame��\�����A����ȊO��s���ɂ���
        /// </summary>
        /// <param name="frame">�\������t���[��</param>
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
        /// tag�Ɉ�v����frame��\�����A����ȊO��s���ɂ���
        /// </summary>
        /// <param name="tag">�^�O</param>
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

        //void SetActiveFrame(int tag)�Ŏd�l
        private void SetActiveFramePart(ContentPageFrame contentPageFrame)
        {
            contentPageFrame.Visibility = Visibility.Visible;
            Buttons.SetOtherOptions(contentPageFrame.CurrentLanguage);
            NavView.IsBackEnabled = contentPageFrame.CanGoBack;
        }

        //�z�[���^�u��ǉ�
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

                //XElement���ݒ肳���܂Ń����w���̂悤�ɊĎ�
                while (xElement is null)
                {
                    xElement = xml.XElement;
                    await Task.Delay(1);
                }

                tabViewItem.Header = xElement.Attribute("Name").Value;

                tabViewItem.IconSource = frame.CurrentLanguage switch
                {
                    Library.C => ImageSources.CImageSource,
                    Library.Cpp => ImageSources.CppImageSource,
                    Library.Win32 => ImageSources.Win32ImageSource,
                    Library.CppWinRTNamespace => ImageSources.CppWinRTNamespaceImageSource,
                    Library.Uwp => ImageSources.UwpImageSource,
                    _ => null,
                };

                return;
            }

            if (frame.CurrentSourcePageType == typeof(HomePage))
            {
                tabViewItem.IconSource = ImageSources.HomePageIconSource;
                tabViewItem.Header = HomePageData.HomePageTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(CHomePage))
            {
                tabViewItem.IconSource = ImageSources.CImageSource;
                tabViewItem.Header = HomePageData.CTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(CppHomePage))
            {
                tabViewItem.IconSource = ImageSources.CppImageSource;
                tabViewItem.Header = HomePageData.CppTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(Win32HomePage))
            {
                tabViewItem.IconSource = ImageSources.Win32ImageSource;
                tabViewItem.Header = HomePageData.Win32Title;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(CppWinRTNamespaceHomePage))
            {
                tabViewItem.IconSource = ImageSources.CppWinRTNamespaceImageSource;
                tabViewItem.Header = HomePageData.CppWinRTNamespaceTitle;
                return;
            }
            if (frame.CurrentSourcePageType == typeof(UwpHomePage))
            {
                tabViewItem.IconSource = ImageSources.UwpImageSource;
                tabViewItem.Header = HomePageData.UwpTitle;
                return;
            }
            throw new NotImplementedException();
        }

        //�^�u��ǉ�

        //������
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

        //ItemInvoked()����i�r�Q�[�g
        public void NavigateFrame(string content, ContentPageFrame frame, NavigationTransitionInfo navigationTransitionInfo)
        {
            if (NavView.SelectedItem is not XmlNavigationViewItem)
            {

                if (content == HomePageData.HomePageTitle) frame.Navigate(typeof(HomePage), null, navigationTransitionInfo);
                else if (content == HomePageData.CTitle) frame.Navigate(typeof(CHomePage), null, navigationTransitionInfo);
                else if (content == HomePageData.CppTitle) frame.Navigate(typeof(CppHomePage), null, navigationTransitionInfo);
                else if (content == HomePageData.Win32Title) frame.Navigate(typeof(Win32HomePage), null, navigationTransitionInfo);
                else if (content == HomePageData.CppWinRTNamespaceTitle) frame.Navigate(typeof(CppWinRTNamespaceHomePage), null, navigationTransitionInfo);
                else if (content == HomePageData.UwpTitle) frame.Navigate(typeof(UwpHomePage), null, navigationTransitionInfo);
                else throw new Exception();

                return;
            }

            var item = NavView.SelectedItem as XmlNavigationViewItem;


            frame.Navigate(item.PageType, null, navigationTransitionInfo);

            (frame.Content as IXml).XElement = item.XElement;
        }

        //�^�C�g���o�[�֘A
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

            Windows.Graphics.RectInt32 dragRectL;
            dragRectL.X = (int)(LeftPaddingColumn.ActualWidth * scaleAdjustment);
            dragRectL.Y = 0;
            dragRectL.Height = (int)(TitleBar.ActualHeight * scaleAdjustment);
            dragRectL.Width = (int)(LeftDragColumn.ActualWidth * scaleAdjustment);

            Windows.Graphics.RectInt32 dragRectR;
            dragRectR.X = (int)((LeftPaddingColumn.ActualWidth
                                + LeftDragColumn.ActualWidth
                                + TabColumn.ActualWidth) * scaleAdjustment);
            dragRectR.Y = 0;
            dragRectR.Height = (int)(TitleBar.ActualHeight * scaleAdjustment);
            dragRectR.Width = (int)(RightDragColumn.ActualWidth * scaleAdjustment);

            AppWindow.TitleBar.SetDragRectangles(new Windows.Graphics.RectInt32[] { dragRectL, dragRectR });
        }
    }
}
