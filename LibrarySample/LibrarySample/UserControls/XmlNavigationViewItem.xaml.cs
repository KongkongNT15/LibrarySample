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
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class XmlNavigationViewItem : NavigationViewItem
    {
        public XElement XElement { get; }
        public Type PageType { get; }

        public string Glyph
        {
            get => FontIcon.Glyph;
            set => FontIcon.Glyph = value;
        }

        private FontIcon FontIcon { get; } = new FontIcon();

        public XmlNavigationViewItem(XElement element, Type pageType)
        {
            XElement = element;
            Icon = FontIcon;
            PageType = pageType;
        }
    }
}
