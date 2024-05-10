using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public static class Data
    {
        public static readonly double NavigationViewContentPadding = 40;

        public static readonly double ControlHeight = 68;
        public static readonly double MinControlHeight = 60;

        public static readonly Thickness ControlPadding = new Thickness(24, 20, 24, 20);
        public static readonly double ControlPaddingHeight = 24;

        public static readonly double DefaultButtonWidth = 64;

        public static readonly double DefaultStackPanelSpacing = 4;

        public static readonly double FunctionExpanderStackPanelSpacing = 24;

        public static readonly double FunctionExpanderTitleTextBlockFontSize = 18;

        public static readonly double HeaderButtonsStackPanelSpacing = 20;

        public static readonly double TitleTextBlockFontSize = 28;

        public static readonly double SubTitleTextBlockFontSize = 20;

        public static readonly Thickness PageScrollViewerPadding = new Thickness(NavigationViewContentPadding, 0, NavigationViewContentPadding, NavigationViewContentPadding);

        public static readonly Thickness IconMargin = new Thickness((ControlHeight - 24.0) / 2.0, 0, (ControlHeight - 24.0) / 2.0, 0);
    }
}
