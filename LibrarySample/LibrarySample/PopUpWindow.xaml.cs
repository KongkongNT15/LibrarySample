using LibrarySample.NativeAPI.Win32;
using LibrarySample.Settings;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class PopUpWindow : Window
    {
        private static readonly List<PopUpWindow> _popUpWindows = [];
        public static IReadOnlyList<PopUpWindow> PopUpWindows => _popUpWindows;

        public static void CloseAll()
        {
            while (_popUpWindows.Count > 0)
            {
                _popUpWindows[^1].Close();
            }
        }

        public static PopUpWindow SearchWindow(UIElement element)
        {
            return _popUpWindows.First(window => (window as Window).Content.XamlRoot == element.XamlRoot);
        }

        public static void ChangeAllWindowTheme(ElementTheme elementTheme)
        {
            foreach (var window in _popUpWindows)
            {
                ((window as Window).Content as FrameworkElement).RequestedTheme = elementTheme;
            }
        }

        public IntPtr HWnd { get; }

        public new UIElement Content
        {
            get => ContentControl.Content;
            set => ContentControl.Content = value;
        }

        public PopUpWindow(FrameworkElement element)
        {
            this.InitializeComponent();
            Content = element;
            ControlGrid.Padding = new Thickness(Data.NavigationViewContentPadding);
            _popUpWindows.Add(this);
            HWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);

            //ÉAÉCÉRÉìê›íË
            AppWindow.SetIcon("Assets/AppIcon.ico");

            double scaling = WindowAPI.GetScaleAdjustment(HWnd);

            if (WindowAPI.SetTitleBarMicaAlt(HWnd) == 0)
            {
                Viewer.Background = null;
                SystemBackdrop = new MicaBackdrop();
            }

            AppWindow.Resize(new Windows.Graphics.SizeInt32((int)(940 * scaling), (int)(660 * scaling)));

            var frameworkElement = base.Content as FrameworkElement;

            frameworkElement.RequestedTheme = SaveData.RequestedTheme;

            WindowAPI.SetTitleBarTheme(HWnd, frameworkElement);

            frameworkElement.ActualThemeChanged += PopUpWindow_ActualThemeChanged;
        }

        private void PopUpWindow_ActualThemeChanged(FrameworkElement sender, object args)
        {
            WindowAPI.SetTitleBarTheme(HWnd, sender);
        }

        private void Window_Closed(object sender, WindowEventArgs args)
        {
            _popUpWindows.Remove(this);
            (Content as FrameworkElement).ActualThemeChanged -= PopUpWindow_ActualThemeChanged;
            Content = null;

            GC.Collect();
        }

        private void CloseButton_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
