using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using LibrarySample.UserControls;
using System.Xml.Linq;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Settings
{
    public sealed class VersionInfoExpander : UserControl
    {
        private ViewExpander ViewExpander { get; } = new ViewExpander();

        private StackPanel RootPanel { get; } = new StackPanel();

        public VersionInfoExpander(XElement xReleaseNote)
        {
            Content = ViewExpander;
            ViewExpander.Content = RootPanel;
            ViewExpander.Glyph = "\uE7C3";

            ReleaseInfo releaseInfo = new ReleaseInfo(xReleaseNote);

            ViewExpander.Title = releaseInfo.VersionText;
            ViewExpander.Description = releaseInfo.DateText;

            foreach (XElement xTextLine in xReleaseNote.Elements("TextLine"))
            {
                RootPanel.Children.Add(new TextBlock { Text = $"・　{xTextLine.Value}", TextWrapping = TextWrapping.Wrap });
            }
        }
    }
}
