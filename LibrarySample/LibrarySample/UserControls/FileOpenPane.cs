using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Storage.Pickers;

namespace LibrarySample.UserControls
{
    public sealed class FileOpenPane : SettingCard, IInputText
    {
        
        private string _fileName;
        private Button Button { get; } = new Button();

        private bool _isOpen = false;

        public string Text => _fileName;
        public string FileName => _fileName;

        private string[] _extentions;

        public FileOpenPane(XElement xElement)
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
                Title = "ファイルを開く";
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
                Button.Content = "開く";
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
                _extentions = ["*"];
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
            FileOpenPicker picker = new();
            WinRT.Interop.InitializeWithWindow.Initialize(picker, this.OwnerWindowHandle());

            foreach (string extention in  _extentions)
            {
                picker.FileTypeFilter.Add(extention);
            }

            var file = await picker.PickSingleFileAsync();
            
            if (file != null)
            {
                _fileName = file.Path;
                FunctionExpander.GetParentFunctionExpander(this).Launch();
            }
            _isOpen = false;
        }
    }
}
