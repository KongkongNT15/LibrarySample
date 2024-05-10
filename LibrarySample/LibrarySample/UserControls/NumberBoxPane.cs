﻿using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class NumberBoxPane : SettingCard, IInputText
    {
        public string Text => NumberBox.Value.ToString();

        private NumberBox NumberBox { get; } = new NumberBox();

        public NumberBoxPane(XElement xElement)
        {
            Content = NumberBox;
            NumberBox.SpinButtonPlacementMode = NumberBoxSpinButtonPlacementMode.Inline;

            NumberBox.SmallChange = 1;
            NumberBox.LargeChange = 10;

            Title = xElement.Attribute("Title").Value;

            XAttribute xValue = xElement.Attribute("Value");

            if (xValue == null) return;

            NumberBox.Value = double.Parse(xValue.Value);

            NumberBox.ValueChanged += NumberBox_ValueChanged;
        }

        private void NumberBox_ValueChanged(NumberBox sender, NumberBoxValueChangedEventArgs args)
        {
            FunctionExpander.GetParentFunctionExpander(this).Launch();
        }
    }
}
