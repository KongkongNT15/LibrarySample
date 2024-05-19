using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.UserControls
{
    public class ComboBoxPane : SettingCard, IInputText
    {
        private readonly ComboBox _comboBox = new ComboBox();

        public string Text => _comboBox.SelectedItem as string;

        public ComboBoxPane(XElement xElement)
        {
            Content = _comboBox;

            Title = xElement.Attribute("Title").Value;

            List<string> itemList = [];

            foreach (XElement xString in xElement.Elements())
            {
                itemList.Add(xString.Value);
            }

            _comboBox.ItemsSource = itemList.ToArray();

            _comboBox.SelectedItem = xElement.Attribute("SelectedItem")?.Value;

            _comboBox.SelectionChanged += ComboBox_SelectionChanged;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            FunctionExpander.GetParentFunctionExpander(this).Launch();
        }
    }
}
