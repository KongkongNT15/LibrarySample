using LibrarySample.UserControls;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.Pages
{
    public static class HomePageHelper
    {
        public static async Task LoadLibrary(StackPanel rootPanel, LibraryType libraryType, string xmlPath)
        {
            foreach (string path in Directory.GetFiles(xmlPath))
            {
                XElement xElement = XElement.Load(path);

                rootPanel.Children.Add(new SlideButton(xElement, libraryType));

                await Task.Delay(1);
            }
        }
    }
}
