using LibrarySample.UserControls;
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
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class HomePage : Page
    {
        public HomePage()
        {
            this.InitializeComponent();

            RootGrid.Margin = new Thickness(Data.NavigationViewContentPadding, 0, 0, 0);

            AddLibraryButton(new HomePageButton(Library.C) { ImageSource = ImageSources.CIconSource, Title = HomePageData.CTitle, Description = HomePageData.CDescription });
            AddLibraryButton(new HomePageButton(Library.Cpp) { ImageSource = ImageSources.CppIconSource, Title = HomePageData.CppTitle, Description = HomePageData.CppDescription });
            AddLibraryButton(new HomePageButton(Library.Win32) { ImageSource = ImageSources.Win32IconSource, Title = HomePageData.Win32Title, Description = HomePageData.Win32Description });
            AddLibraryButton(new HomePageButton(Library.CppWinRTNamespace) { ImageSource = ImageSources.CppWinRTNamespaceIconSource, Title = HomePageData.CppWinRTNamespaceTitle, Description = HomePageData.CppWinRTNamespaceDescription });
            AddLibraryButton(new HomePageButton(Library.Uwp) { ImageSource = ImageSources.UwpIconSource, Title = HomePageData.UwpTitle, Description = HomePageData.UwpDescription });
        }

        public void AddLibraryButton(HomePageButton button)
        {
            RootGrid.Children.Add(button);
        }
    }
}
