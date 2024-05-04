using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class ScrollableControl : UserControl
    {
        private ScrollViewer ScrollViewer { get; } = new ScrollViewer();

        public new UIElement Content
        {
            get => ScrollViewer.Content as UIElement;
            set => ScrollViewer.Content = value;
        }

        public ScrollableControl()
        {
            base.Content = ScrollViewer;
            ScrollViewer.Padding = new Thickness(Data.NavigationViewContentPadding, 0, Data.NavigationViewContentPadding, 0);
        }
    }
}
