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
using Windows.ApplicationModel.DataTransfer;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public abstract partial class SourceCodeViewer : UserControl
    {
        public static SourceCodeViewer GetSourceCodeViewer(CodeLanguage language)
        {
            return language switch
            {
                CodeLanguage.C => new CCodeViewer(),
                CodeLanguage.Cpp => new CppCodeViewer(),
                _ => new TextViewer(),
            };
        }

        //テキストをコピーする用
        private static DataPackage DataPackage { get; } = new DataPackage();

        public string FilePath { get; set; } = string.Empty;

        private CodeLanguage _languageType;
        public CodeLanguage LanguageType
        {
            get => _languageType;
            protected set
            {
                _languageType = value;

                LanguageText.Text = value switch
                {
                    CodeLanguage.C => "C",
                    CodeLanguage.CWin32 => "C",
                    CodeLanguage.Cpp => "C++",
                    CodeLanguage.CppWinRT => "C++/WinRT",
                    CodeLanguage.Cs => "C#",
                    CodeLanguage.Java => "Java",
                    CodeLanguage.Text => "Text",
                    _  => "Unknown",
                };
            }
        }

        protected TextBlock CodeTextBlock => CodeText;

        public SourceCodeViewer()
        {
            this.InitializeComponent();
            RootPanel.Padding = new Thickness(Data.ControlPaddingHeight + 4.0, Data.ControlPaddingHeight - 4.0, Data.ControlPaddingHeight + 4.0, Data.ControlPaddingHeight);
        }

        public void LoadTextFile(string filePath)
        {
            FilePath = filePath;

            try
            {
                using StreamReader streamReader = new StreamReader(FilePath);

                SetSourceCode(streamReader.ReadToEnd());
            }
            catch (Exception)
            {
                CodeText.Text = $"指定されたファイルが見つかりません: {FilePath}";
            }
        }

        public abstract void SetSourceCode(string sourceCode);

        private void CopyButton_Click(object sender, RoutedEventArgs e)
        {
            DataPackage.RequestedOperation = DataPackageOperation.Copy;
            DataPackage.SetText(CodeText.Text);
            Clipboard.SetContent(DataPackage);
        }

        private void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            Loaded -= UserControl_Loaded;

            if (string.IsNullOrEmpty(FilePath))
            {
                CodeText.Text = "テキストが設定されていません";
                return;
            }

            try
            {
                using StreamReader streamReader = new StreamReader(FilePath);

                SetSourceCode(streamReader.ReadToEnd());
            }
            catch (Exception)
            {
                CodeText.Text = $"指定されたファイルが見つかりません: \"{FilePath}\"";
            }
        }
    }
}
