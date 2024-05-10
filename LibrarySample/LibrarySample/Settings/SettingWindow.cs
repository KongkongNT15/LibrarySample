using Microsoft.UI.Windowing;
using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Settings
{
    internal class SettingWindow : Window
    {
        private static SettingWindow _instance = null;
        private static bool _isActivated = false;

        public static void SetActive()
        {
            if (_instance == null || _instance.AppWindow == null)
            {
                _instance = new SettingWindow();
            }
            _instance.Activate();
        }

        public static bool CloseWindow()
        {
            if (!_isActivated) return false;
            if (_instance.AppWindow == null) return false;

            _instance.Close();
            return true;
        }

        public static void SetTheme(ElementTheme requestedTheme)
        {
            if (_instance == null || _instance.AppWindow == null) return;
            (_instance.Content as FrameworkElement).RequestedTheme = requestedTheme;
        }

        public IntPtr HWnd { get; }

        private SettingWindow()
        {
            _isActivated = true;
            var op = OverlappedPresenter.Create();
            op.IsMaximizable = false;
            op.IsMinimizable = false;
            op.IsResizable = false;
            op.IsAlwaysOnTop = false;

            AppWindow.SetPresenter(op);

            //アイコン設定
            AppWindow.SetIcon("Assets/AppIcon.ico");

            HWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);

            double scaling = WindowAPI.GetScaleAdjustment(HWnd);

            AppWindow.Resize(new Windows.Graphics.SizeInt32((int)(916 * scaling), (int)(640 * scaling)));

            Content = SettingWindowContent.Instance;
            (Content as FrameworkElement).RequestedTheme = SaveData.RequestedTheme;

            Title = "設定";

            WindowAPI.SetTitleBarTheme(HWnd, Content as FrameworkElement);

            (Content as FrameworkElement).ActualThemeChanged += FrameworkElement_ActualThemeChanged;

            Closed += SettingWindow_Closed;
        }

        private void SettingWindow_Closed(object sender, WindowEventArgs args)
        {
            (Content as FrameworkElement).ActualThemeChanged -= FrameworkElement_ActualThemeChanged;
        }

        private void FrameworkElement_ActualThemeChanged(FrameworkElement sender, object args)
        {
            WindowAPI.SetTitleBarTheme(HWnd, sender);
        }
    }
}
