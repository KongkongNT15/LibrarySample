using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Storage;
using Windows.Storage.Pickers;

namespace LibrarySample.UserControls
{
    public class FileSavePane : SettingCard, IInputText
    {
        private string _fileName;
        public string FileName => _fileName;

        public string Text => _fileName;

        private Button Button { get; } = new Button();

        private bool _isOpen = false;

        private string[] _extentions;

        public FileSavePane(XElement xElement)
        {
            Content = Button;
            Button.MinWidth = Data.DefaultButtonWidth;

            SetMessage(xElement.Attribute("Message"));
            SetButtonContent(xElement.Attribute("ButtonText"));
            SetExtetions(xElement.Attribute("Extentions"));

            Button.Click += Button_Click;
        }

        private void SetMessage(XAttribute xMessage)
        {
            if (xMessage == null)
            {
                Title = "ファイルを保存";
            }
            else
            {
                Title += xMessage.Value;
            }
        }

        private void SetButtonContent(XAttribute xButtonText)
        {
            if (xButtonText == null)
            {
                Button.Content = "保存";
            }
            else
            {
                Button.Content = xButtonText.Value;
            }
        }

        private void SetExtetions(XAttribute xExtentions)
        {
            if (xExtentions == null)
            {
                _extentions = ["テキストファイル", ".txt"];
            }
            else
            {
                _extentions = xExtentions.Value.Split('|');
            }
        }

        private async void Button_Click(object sender, RoutedEventArgs e)
        {
            if (_isOpen) return;
            _isOpen = true;

            FileSavePicker savePicker = new();

            savePicker.SuggestedFileName = "Sample";

            WinRT.Interop.InitializeWithWindow.Initialize(savePicker, this.OwnerWindowHandle());

            for (int i = 0; i < _extentions.Length; i += 2)
            {
                savePicker.FileTypeChoices.Add(_extentions[i], [_extentions[i + 1]]);

            }

            StorageFile file = await savePicker.PickSaveFileAsync();

            if (file != null)
            {
                _fileName = file.Path;
                FunctionExpander.GetParentFunctionExpander(this).Launch();
            }

            _isOpen = false;
        }
    }
}
