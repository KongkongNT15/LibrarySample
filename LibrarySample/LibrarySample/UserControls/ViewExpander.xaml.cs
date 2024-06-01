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

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public partial class ViewExpander : Expander
    {
        public string Title
        {
            get => TitleTextBlock.Text;
            set => TitleTextBlock.Text = value;
        }

        public string Description
        {
            get => DescriptionTextBlock.Text;
            set => DescriptionTextBlock.Text = value;
        }

        public string Glyph
        {
            get => FIcon.Glyph;
            set => FIcon.Glyph = value;
        }

        public FontFamily TitleFontFamily
        {
            get => TitleTextBlock.FontFamily;
            set => TitleTextBlock.FontFamily = value;
        }

        public FontFamily DescriptionFontFamily
        {
            get => DescriptionTextBlock.FontFamily;
            set => DescriptionTextBlock.FontFamily = value;
        }

        public ViewExpander()
        {
            this.InitializeComponent();
            this.Expanding += ViewExpander_Expanding;
        }

        //コントロールテンプレートの変更
        private void ViewExpander_Expanding(Expander sender, ExpanderExpandingEventArgs args)
        {
            this.Expanding -= ViewExpander_Expanding;
            this.Template = (ControlTemplate)App.Current.Resources["ViewExpanderTemplate"];
        }
    }
}
