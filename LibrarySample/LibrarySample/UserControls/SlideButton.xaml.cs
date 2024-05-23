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
    public sealed partial class SlideButton : Button
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

        public string Glyph
        {
            get => FIcon.Glyph;
            set => FIcon.Glyph = value;
        }

        public XElement XElement { get; }
        LibraryType LibraryType { get; }

        public SlideButton(XElement xElement, LibraryType libraryType)
        {
            this.InitializeComponent();
            Click += SlideButton_Click;

            XElement = xElement;
            LibraryType = libraryType;

            switch (xElement.Name.LocalName)
            {
                case "Namespace":
                case "Header":
                    Glyph = xElement.Attribute("Glyph").Value;

                    break;
            }

            switch (libraryType)
            {
                case LibraryType.CppLibrary: Title = XElement.Attribute("Name").Value.Replace("::", " : : "); break;
                default: Title = XElement.Attribute("Name").Value; break;
            }
            Description = xElement.Attribute("Description").Value;
        }

        private void SlideButton_Click(object sender, RoutedEventArgs e)
        {
            ContentPageFrame frame = GetParentFrame();
            switch (LibraryType)
            {
                case LibraryType.CLibrary:
                    switch(XElement.Name.LocalName)
                    {
                        case "Header":
                            frame.Navigate(typeof(CLibraryPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        case "Structure":
                            frame.Navigate(typeof(CStructurePage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        default: throw new Exception();
                    }
                    break;

                case LibraryType.CppLibrary:
                    switch (XElement.Name.LocalName)
                    {
                        case "Header":
                            frame.Navigate(typeof(CppLibraryPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        case "Class":
                            frame.Navigate(typeof(CppClassPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        case "Enum":
                            frame.Navigate(typeof(CppEnumPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        default: throw new Exception();
                    }
                    break;

                case LibraryType.Win32Library:
                    switch (XElement.Name.LocalName)
                    {
                        case "Header":
                            frame.Navigate(typeof(Win32LibraryPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        case "Structure":
                            frame.Navigate(typeof(Win32StructurePage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        default: throw new Exception();
                    }
                    break;

                case LibraryType.CppWinRTNamespaceLibrary:
                    switch (XElement.Name.LocalName)
                    {
                        case "Namespace":
                            frame.Navigate(typeof(CppWinRTNamespacePage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            
                            break;

                        case "Class":
                            frame.Navigate(typeof(CppWinRTClassPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            break;

                        default: throw new Exception();
                    }
                    break;

                default: throw new Exception();
            }

            (frame.Content as IXml).XElement = XElement;
        }

        private ContentPageFrame GetParentFrame()
        {
            DependencyObject parent = Parent;

            while(parent is not ContentPageFrame)
            {
                parent = (parent as FrameworkElement).Parent;
            }

            return parent as ContentPageFrame;
        }
    }
}
