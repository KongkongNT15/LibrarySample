using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Media.Imaging;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Devices.Bluetooth.Background;

namespace LibrarySample
{
    public static class ImageSources
    {
        public static readonly string CIconPath = @"Assets\CIcon.png";
        public static readonly string CppIconPath = @"Assets\CppIcon.png";
        public static readonly string Win32IconPath = @"Assets\Win32.png";
        public static readonly string CppWinRTNamespaceIconPath = @"Assets\cppwinrt.png";

        public static readonly ImageSource CIconSource = new BitmapImage(new Uri(System.IO.Directory.GetCurrentDirectory() + '\\' + CIconPath));
        public static readonly ImageSource CppIconSource = new BitmapImage(new Uri(System.IO.Directory.GetCurrentDirectory() + '\\' + CppIconPath));
        public static readonly ImageSource Win32IconSource = new BitmapImage(new Uri(System.IO.Directory.GetCurrentDirectory() + '\\' + Win32IconPath));
        public static readonly ImageSource CppWinRTNamespaceIconSource = new BitmapImage(new Uri(System.IO.Directory.GetCurrentDirectory() + '\\' + CppWinRTNamespaceIconPath));

        public static readonly IconSource CImageSource = new ImageIconSource { ImageSource = CIconSource };
        public static readonly IconSource CppImageSource = new ImageIconSource { ImageSource = CppIconSource };
        public static readonly IconSource Win32ImageSource = new ImageIconSource { ImageSource = Win32IconSource };
        public static readonly IconSource CppWinRTNamespaceImageSource = new ImageIconSource { ImageSource = CppWinRTNamespaceIconSource };

        public static readonly IconSource HomePageIconSource = new SymbolIconSource { Symbol = Symbol.Home };
    }
}
