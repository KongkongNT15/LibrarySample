using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class KeyValueComboBoxPane : SettingCard, IInputText
    {
        private readonly ComboBox ComboBox = new ComboBox();

        public string Text => (ComboBox.SelectedItem as KeyValue).Value;

        public KeyValueComboBoxPane(XElement xElement)
        {
            Content = ComboBox;

            Title = xElement.Attribute("Title").Value;

            List<KeyValue> items = [];

            foreach (XElement xKeyValuePair in xElement.Elements())
            {
                string key = xKeyValuePair.Attribute("Key").Value;
                string value = xKeyValuePair.Attribute("Value").Value;

                items.Add(new KeyValue(key, value));
            }

            KeyValue[] keyValues = items.ToArray();

            ComboBox.ItemsSource = keyValues;

            string selectedItem = xElement.Attribute("SelectedItem").Value;

            foreach (KeyValue keyValue in keyValues)
            {
                if (keyValue.Key == selectedItem)
                {
                    ComboBox.SelectedItem = keyValue;
                    break;
                }
            }

            ComboBox.SelectionChanged += ComboBox_SelectionChanged;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            FunctionExpander.GetParentFunctionExpander(this).Launch();
        }

        private class KeyValue
        {
            public readonly string Key;
            public readonly string Value;

            public KeyValue(string key, string value)
            {
                this.Key = key;
                this.Value = value;
            }

            public override string ToString()
            {
                return Key;
            }
        }
    }
}
