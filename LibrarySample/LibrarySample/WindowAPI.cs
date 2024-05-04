using LibrarySample.NativeAPI.Win32;
using Microsoft.UI.Windowing;
using Microsoft.UI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.UI.Xaml;

namespace LibrarySample
{
    internal static class WindowAPI
    {
        public static void SetTitleBarTheme(IntPtr hWnd, FrameworkElement windowContent)
        {
            int value = windowContent.ActualTheme == ElementTheme.Dark ? BOOL.TRUE : BOOL.FALSE;

            _ = DwmAPI.DwmSetWindowAttribute(hWnd, 20, ref value, sizeof(int));
        }

        public static void SetTitleBarTheme(Window window, FrameworkElement windowContent)
        {
            int value = windowContent.ActualTheme == ElementTheme.Dark ? BOOL.TRUE : BOOL.FALSE;

            _ = DwmAPI.DwmSetWindowAttribute(WinRT.Interop.WindowNative.GetWindowHandle(window), 20, ref value, sizeof(int));
        }

        public static double GetScaleAdjustment(IntPtr hWnd)
        {
            WindowId wndId = Win32Interop.GetWindowIdFromWindow(hWnd);
            DisplayArea displayArea = DisplayArea.GetFromWindowId(wndId, DisplayAreaFallback.Primary);
            IntPtr hMonitor = Win32Interop.GetMonitorFromDisplayId(displayArea.DisplayId);

            // Get DPI.
            int result = ShellScalingAPI.GetDpiForMonitor(hMonitor, Monitor_DPI_Type.MDT_Default, out uint dpiX, out uint _);
            if (result != 0)
            {
                throw new Exception("Could not get DPI for monitor.");
            }

            uint scaleFactorPercent = (uint)(((long)dpiX * 100 + (96 >> 1)) / 96);
            return scaleFactorPercent / 100.0;
        }
    }
}
