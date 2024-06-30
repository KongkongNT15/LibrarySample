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
    public sealed partial class UwpEnumPage : Page, IXml, IUwpHandler
    {
        public WinRTDesign Design { get; } = SaveData.UwpCodeDesign;
        public CodeLanguage CodeLanguage { get; } = SaveData.UwpCodeLanguage;
        public ProcesserType ProcesserType { get; } = SaveData.UwpProcesserType;

        private XElement _xElement = null;

        public XElement XElement
        {
            get => _xElement;
            set
            {
                _xElement = value;
                (Frame as ContentPageFrame).AddXElement(value);
                RootPanel.Children.Clear();
                ApplyEnum();

            }
        }

        public UwpEnumPage()
        {
            this.InitializeComponent();
        }

        private void ApplyEnum()
        {
            StackPanel panel = LibraryPageHelper.CreateHeaderPanel("ÉÅÉìÉoÅ[");
            RootPanel.Children.Add(panel);

            foreach (XElement xMember in XElement.Elements())
            {
                panel.Children.Add(new ValueCard { Title = xMember.Attribute("Name").Value, Description = xMember.Attribute("Description").Value, Value = xMember.Attribute("Value")?.Value, Glyph = Category.Field.ToGlyph() });
            }
        }
    }
}
