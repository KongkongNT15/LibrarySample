using LibrarySample.SampleManagement;
using LibrarySample.UserControls;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;

namespace LibrarySample.Pages
{
    public static class HomePageHelper
    {
        public static async Task LoadLibrary(StackPanel rootPanel, LibraryType libraryType, string xmlPath)
        {
            foreach (var pair in XmlDocuments.GetDocuments(libraryType))
            {
                XElement xElement = pair.Value;

                rootPanel.Children.Add(new SlideButton(xElement, libraryType));

                await Task.Delay(1);
            }
        }
    }
}
