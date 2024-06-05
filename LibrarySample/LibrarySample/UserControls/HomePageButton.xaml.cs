using LibrarySample.Pages;
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
    public sealed partial class HomePageButton : Button
    {
        public string Title
        {
            get => TitleText.Text;
            set => TitleText.Text = value;
        }

        public string Description
        {
            get => DescriptionText.Text;
            set => DescriptionText.Text = value;
        }

        public ImageSource ImageSource
        {
            get => FIcon.Source;
            set => FIcon.Source = value;
        }

        public Library LibraryType { get; }

        public HomePageButton(Library libraryType)
        {
            this.InitializeComponent();
            LibraryType = libraryType;

            Click += HomePageButton_Click;
        }

        private void HomePageButton_Click(object sender, RoutedEventArgs e)
        {
            DependencyObject dependencyObject = Parent;
            ContentPageFrame frame;

            while (dependencyObject is not ContentPageFrame)
            {
                dependencyObject = (dependencyObject as FrameworkElement).Parent;
            }

            frame = dependencyObject as ContentPageFrame;

            Type pageType = LibraryType switch
            {
                Library.C => typeof(CHomePage),
                Library.Cpp => typeof(CppHomePage),
                Library.Win32 => typeof(Win32HomePage),
                Library.CppWinRTNamespace => typeof(CppWinRTNamespaceHomePage),
                Library.Uwp => typeof(UwpHomePage),
                _ => typeof(Page),
            };

            frame.Navigate(pageType, null, ContentPageFrame.DrillInNavigationTransitionInfo);
        }
    }
}
