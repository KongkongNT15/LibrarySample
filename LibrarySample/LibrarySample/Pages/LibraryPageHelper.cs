using LibrarySample.SampleManagement;
using LibrarySample.UserControls;
using Microsoft.UI.Text;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Networking.Sockets;

namespace LibrarySample.Pages
{
    public static class LibraryPageHelper
    {
        public static StackPanel CreateHeaderPanel(string header)
        {
            StackPanel panel = new StackPanel();

            panel.Spacing = Data.DefaultStackPanelSpacing;

            TextBlock textBlock = new TextBlock();

            panel.Children.Add(textBlock);

            textBlock.Text = header;
            textBlock.FontSize = Data.SubTitleTextBlockFontSize;
            textBlock.FontWeight = FontWeights.Bold;

            return panel;
        }

        public static StackPanel CreateHeaderPanel(Category category)
        {
            return CreateHeaderPanel(EnumConverter.ToPanelHeader(category));
        }

        public static void ApplyClasses(StackPanel rootPanel, XElement xElement, string elementName, string header, string libraryPath, CodeLanguage codeLanguage, Category category)
        {
            XElement xClasses = xElement.Element(elementName);

            //クラスがなければ何もしない
            if (xClasses == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xClassReference in xClasses.Elements())
            {
                XElement xClass = XElement.Load(libraryPath + xClassReference.Attribute("FileName").Value);

                panel.Children.Add(new SlideButton(xClass, codeLanguage) { Glyph = EnumConverter.ToGlyph(category) });
            }
        }

        public static async Task ApplyCppFunctions(StackPanel rootPanel, XElement xElement, string elementName, string header, Category category)
        {
            XElement xFunctions = xElement.Element(elementName);

            //なければ何もしない
            if (xFunctions == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xFunction in xFunctions.Elements())
            {
                panel.Children.Add(new CppFunctionExpander(xFunction, category));
                await Task.Delay(1);
            }
        }

        public static void ApplyTypeDefs(StackPanel rootPanel, XElement xElement, string elementName, string header = "型名")
        {
            XElement xTypeDefs = xElement.Element(elementName);

            //Typedefがなければ何もしない
            if (xTypeDefs == null) return;

            StackPanel panel = CreateHeaderPanel(header);
            rootPanel.Children.Add(panel);

            foreach (XElement xTypedef in xTypeDefs.Elements())
            {
                ValueCard valueCard = new ValueCard();

                valueCard.Glyph = EnumConverter.ToGlyph(Category.TypeDefinition);
                valueCard.Title = xTypedef.Attribute("Name").Value;
                valueCard.Description = xTypedef.Attribute("Description").Value;
                valueCard.Value = xTypedef.Attribute("Type")?.Value;

                panel.Children.Add(valueCard);
            }

        }
    }
}
