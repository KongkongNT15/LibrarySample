using LibrarySample.Languages;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
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
using System.Xml.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class CStructurePage : Page, IXml, ICHandler
    {
        private XElement _xElement = null;
        public XElement XElement
        {
            get => _xElement;
            set
            {
                _xElement = value;
                (Frame as ContentPageFrame).AddXElement(value);
                StackPanel stackPanel = LibraryPageHelper.CreateHeaderPanel("ÉÅÉìÉoÅ[");
                stackPanel.Padding = Data.PageScrollViewerPadding;
                RootViewer.Content = stackPanel;
                
                foreach (XElement xElement in value.Elements("Field"))
                {
                    stackPanel.Children.Add(new CFunctionExpander(xElement, Category.Field));
                }
            }
        }

        public CVersion CVersion { get; set; } = SaveData.CVersion;
        public ProcesserType ProcesserType { get; set; } = SaveData.CProcesserType;

        public CStructurePage()
        {
            this.InitializeComponent();
        }
    }
}
