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

        public StartSampleButton(string applicationName, string folder, string funcName, LaunchType launchType = LaunchType.PipeConsole)
        {
            ApplicationName = applicationName;
            Folder = folder;
            FuncName = funcName;

            Content = Button;
            Button.Content = "起動";
            Button.Width = Data.DefaultButtonWidth;


            Button.Click += launchType switch
            {
                LaunchType.Graphical => ButtonClickGraphical,
                _ => ButtonClick
            };

            Title = "サンプルを起動して動作確認";
        }

        private void ButtonClick(object sender, RoutedEventArgs e)
        {
            Process.Start("../Sample/SampleLauncher", $"{ApplicationName} {Folder} {FuncName} true");
        }

        private void ButtonClickGraphical(object sender, RoutedEventArgs e)
        {
            Process.Start(ApplicationName, $"{Folder} {FuncName}");
        }
    }
}
