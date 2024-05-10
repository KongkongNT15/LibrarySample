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
        CodeLanguage LanguageType { get; }

        public SlideButton(XElement xElement, CodeLanguage languageType)
        {
            this.InitializeComponent();
            Click += SlideButton_Click;

            XElement = xElement;
            LanguageType = languageType;

            switch (xElement.Name.LocalName)
            {
                case "Header":
                    Glyph = xElement.Attribute("Glyph").Value;

                    break;
            }

            switch (languageType)
            {
                case CodeLanguage.Cpp:
                case CodeLanguage.CppWinRT: Title = XElement.Attribute("Name").Value.Replace("::", " : : "); break;
                default: Title = XElement.Attribute("Name").Value; break;
            }
            Description = xElement.Attribute("Description").Value;
        }

        private void SlideButton_Click(object sender, RoutedEventArgs e)
        {
            ContentPageFrame frame = GetParentFrame();
            switch (LanguageType)
            {
                case CodeLanguage.C:
                    switch(XElement.Name.LocalName)
                    {
                        case "Header":
                            frame.Navigate(typeof(CLibraryPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            (frame.Content as CLibraryPage).XElement = XElement;
                            break;

                        case "Structure":
                            frame.Navigate(typeof(CStructurePage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            (frame.Content as CStructurePage).XElement = XElement;
                            break;

                        default: throw new Exception();
                    }
                    break;

                case CodeLanguage.Cpp:
                    switch (XElement.Name.LocalName)
                    {
                        case "Header":
                            frame.Navigate(typeof(CppLibraryPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            (frame.Content as CppLibraryPage).XElement = XElement;
                            break;

                        case "Class":
                            frame.Navigate(typeof(CppClassPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            (frame.Content as CppClassPage).XElement = XElement;
                            break;

                        case "Enum":
                            frame.Navigate(typeof(CppEnumPage), null, ContentPageFrame.SlideFromRightNavigationTransitionInfo);
                            (frame.Content as CppEnumPage).XElement = XElement;
                            break;

                        default: throw new Exception();
                    }
                    break;

                default: throw new Exception();
            }
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
