﻿using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class TextPane : SettingCard, IInputText
    {
        private TextBox TextBox { get; } = new TextBox();

        public string Text
        {
            get => TextBox.Text;
            set => TextBox.Text = value;
        }

        private FunctionExpander FunctionExpander = null;

        public TextPane(XElement xElement)
        {
            Content = TextBox;
            Title = xElement.Attribute("Title").Value;
            Text = xElement.Attribute("Text").Value;

            TextBox.TextChanging += TextBox_TextChanging1;
            TextBox.TextChanging += TextBox_TextChanging;
        }

        private void TextBox_TextChanging1(TextBox sender, TextBoxTextChangingEventArgs args)
        {
            FunctionExpander = FunctionExpander.GetParentFunctionExpander(this);
            TextBox.TextChanging -= TextBox_TextChanging1;
        }

        public void DeleteEvent()
        {
            TextBox.TextChanging -= TextBox_TextChanging;
        }

        private void TextBox_TextChanging(TextBox sender, TextBoxTextChangingEventArgs args)
        {
            FunctionExpander.Launch();
        }
    }
}
