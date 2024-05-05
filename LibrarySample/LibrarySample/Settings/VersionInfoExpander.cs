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

        private readonly int _year = 2000;

        private readonly int _month = 1;

        private readonly int _date = 1;

        private readonly int _versionMajor = 0;
        private readonly int _versionMinor = 0;
        private readonly int _versionBuild = 0;
        private readonly int _versionRevision = 0;

        private StackPanel RootPanel { get; } = new StackPanel();

        public VersionInfoExpander(XElement xReleaseNote)
        {
            Content = ViewExpander;
            ViewExpander.Content = RootPanel;
            ViewExpander.Glyph = "\uE7C3";

            _year = int.Parse(xReleaseNote.Attribute("Year").Value);
            _month = int.Parse(xReleaseNote.Attribute("Month").Value);
            _date = int.Parse(xReleaseNote.Attribute("Date").Value);
            _versionMajor = int.Parse(xReleaseNote.Attribute("VersionMajor").Value);
            _versionMinor = int.Parse(xReleaseNote.Attribute("VersionMinor").Value);
            _versionBuild = int.Parse(xReleaseNote.Attribute("VersionBuild").Value);
            _versionRevision = int.Parse(xReleaseNote.Attribute("VersionRevision").Value);

            SetDate();
            SetVersion();

            foreach (XElement xTextLine in xReleaseNote.Elements("TextLine"))
            {
                RootPanel.Children.Add(new TextBlock { Text = $"・　{xTextLine.Value}", TextWrapping = TextWrapping.Wrap });
            }
        }

        private void SetDate()
        {
            ViewExpander.Description = $"{_year}年{_month}月{_date}日";
        }

        private void SetVersion()
        {
            ViewExpander.Title = $"Version {_versionMajor}.{_versionMinor}.{_versionBuild}.{_versionRevision}";
        }
    }
}
