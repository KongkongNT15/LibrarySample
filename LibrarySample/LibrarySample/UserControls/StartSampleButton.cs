using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public sealed class StartSampleButton : SettingCard
    {
        public string ApplicationName { get; }
        public string Folder { get; }
        public string FuncName { get; }

        private Button Button { get; } = new Button();

        public StartSampleButton(string applicationName, string folder, string funcName)
        {
            ApplicationName = applicationName;
            Folder = folder;
            FuncName = funcName;

            Content = Button;
            Button.Content = "起動";
            Button.Width = Data.DefaultButtonWidth;

            Button.Click += ButtonClick;

            Title = "サンプルを起動して動作確認";
        }

        private void ButtonClick(object sender, RoutedEventArgs e)
        {
            Process.Start("../Sample/SampleLauncher", $"{ApplicationName} {Folder} {FuncName} true");
        }
    }
}
