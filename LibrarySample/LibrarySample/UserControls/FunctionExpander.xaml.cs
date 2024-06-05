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
using System.Xml.Linq;
using LibrarySample.SampleManagement;
using LibrarySample.Settings;
using System.Linq.Expressions;
using System.Diagnostics;
using System.Threading.Tasks;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public abstract partial class FunctionExpander : UserControl
    {
        public static FunctionExpander GetParentFunctionExpander(FrameworkElement frameworkElement)
        {
            while (frameworkElement is not FunctionExpander)
            {
                frameworkElement = frameworkElement.Parent as FrameworkElement;
            }

            return frameworkElement as FunctionExpander;
        }

        public static FunctionExpander Create(Library libraryType, XElement xElement, Category category)
        {
            return libraryType switch 
            {
                Library.C => new CFunctionExpander(xElement, category),
                Library.Cpp => new CppFunctionExpander(xElement, category),
                Library.Win32 => new Win32FunctionExpander(xElement, category),
                Library.CppWinRTNamespace => new CppWinRTNamespaceFunctionExpander(xElement, category),
                Library.Uwp => new UwpFunctionExpander(xElement, category),
                Library.DotNet => new CSharpFunctionExpander(xElement, category),
                _ => throw new NotImplementedException(),
            };
        }

        public string Title
        {
            get => EExpander.Title;
            set => EExpander.Title = value;
        }

        public string Description
        {
            get => EExpander.Description;
            set => EExpander.Description = value;
        }

        public string Glyph
        {
            get => EExpander.Glyph;
            set => EExpander.Glyph = value;
        }

        public Category Category { get; }
        public LaunchType LaunchType { get; }

        private string _folder;
        public string Folder => _folder;
        private string _funcName;
        public string FuncName => _funcName;

        public InputsPanel InputsPanel => _inputsPanel;
        public ConsolePane OutputConsole => _outputConsole;

        public XElement XElement { get; }

        private bool _isNotSupported = false;

        private bool _isDeletedFunction = false;

        //サンプルを実行中かどうか
        protected bool _isWorking = false;

        public Expander Expander => EExpander;

        public FunctionExpander(XElement xElement, Category category, LaunchType defaultLaunchType = LaunchType.PipeConsole)
        {
            XElement = xElement;

            this.InitializeComponent();

            Category = category;

            Glyph = Category.ToGlyph();

            //
            Title = Category switch
            {
                Category.Operator => "operator",
                Category.Literal => "operator\"\"",
                _ => ""
            } + xElement.Attribute("Name").Value;

            Description = Category switch
            {
                Category.Constructor => "オブジェクトを構築します",
                Category.Destructor => "オブジェクトを破棄します",
                _ => xElement.Attribute("Description").Value,
            };

            LaunchType = EnumConverter.ToLaunchType(XElement.Attribute("LaunchType")?.Value, defaultLaunchType);

            //未完成サンプル
            if (Description == "???")
            {
                IsEnabled = false;
            }
            
        }

        //ここで定義とサンプルのコードの両方を設定
        protected abstract void ApplySourceCode();

        protected void DeleteSamplePanel()
        {
            RootPanel.Children.Remove(SamplePanel);
            RootPanel.Children.Remove(ResultsPanel);
        }

        protected void SetAsNotSupportedVersion(string message)
        {
            _isNotSupported = true;
            InfoBar infoBar = new InfoBar();

            infoBar.Message = message;
            infoBar.IsClosable = false;
            infoBar.IsOpen = true;
            infoBar.Severity = InfoBarSeverity.Error;

            Expander.Content = infoBar;
        }

        //_folderと_funcNameに値を入れる
        private void ApplyFolder()
        {
            XAttribute xAttribute = XElement.Attribute("Tag");
            _folder = GetXElementRootTag();

            if (xAttribute != null)
            {
                _funcName = xAttribute.Value;
            }
        }

        //削除された関数
        private void SetAsDeletedFunction()
        {
            XAttribute xDeletedFunction = XElement.Attribute("IsDeleted");

            //Falseと判定
            if (xDeletedFunction == null) return;

            if (xDeletedFunction.Value == "False") return;

            InfoBar infoBar = new InfoBar();

            infoBar.Severity = InfoBarSeverity.Error;
            infoBar.IsOpen = true;
            infoBar.IsClosable = false;
            
            switch (Category)
            {
                case Category.Operator:
                    infoBar.Title = "削除された演算子";
                    infoBar.Message = "この演算子は削除されています";
                    break;

                case Category.Constructor:
                    infoBar.Title = "削除されたコンストラクター";
                    infoBar.Message = "このコンストラクターは削除されています";
                    break;

                case Category.Method:
                case Category.Function:
                    infoBar.Title = "削除された関数";
                    infoBar.Message = "この関数は削除されています";
                    break;

                default: throw new Exception();
            }

            RootPanel.Children.Insert(0, infoBar);

            _isDeletedFunction = true;
        }


        //定義ファイルの読み込み
        protected abstract void ApplyDefinition();

        //ConsoleButtonから起動
        protected abstract void LaunchByButton();

        protected async Task LaunchAsync(SampleRunner sampleRunner)
        {
            if (_isWorking) return;
            _isWorking = true;

            var result = await sampleRunner.RunSampleAsync(Folder, FuncName, InputsPanel.CreateInputs());

            OutputConsole.Output = result.Outputs;

            _isWorking = false;
        }

        //サンプルの実行
        public abstract void Launch();

        private void ApplyParameters()
        {
            //削除された関数は引数の説明の必要なし
            if (_isDeletedFunction)
            {
                RootPanel.Children.Remove(ParameterPanel);
                return;
            }

            //関数形式以外はパラメータなし
            if (!Category.IsFunctionType())
            {
                RootPanel.Children.Remove(ParameterPanel);
                return;
            }
            XElement returnsElement = XElement.Element("Parameters");

            if (returnsElement == null)
            {

                ParameterPanel.Children.Add(new TextCard { Text = "なし(void)" });


            }
            else
            {
                foreach (XElement xElement in returnsElement.Elements("Parameter"))
                {
                    ParameterPanel.Children.Add(new DescriptionTextCard { Title = xElement.Attribute("Name").Value, Description = xElement.Attribute("Description").Value });
                }

            }
        }

        private void ApplyReturns()
        {
            //削除された関数は戻り値の説明の必要なし
            if (_isDeletedFunction)
            {
                RootPanel.Children.Remove(ReturnsPanel);
                return;
            }

            if (!Category.IsFunctionType())
            {
                RootPanel.Children.Remove(ReturnsPanel);
                return;
            }
            XElement returnsElement = XElement.Element("Returns");

            if (returnsElement == null)
            {
                switch (Category)
                {
                    case Category.Operator:
                        ReturnsPanel.Children.Add(new TextCard { Text = "*this" });
                        break;

                    case Category.Literal:
                        ReturnsPanel.Children.Add(new TextCard { Text = "作成されたオブジェクト" });
                        break;

                    default:
                        ReturnsPanel.Children.Add(new TextCard { Text = "なし(void)" });
                        break;
                }
            }
            else
            {
                ReturnsPanel.Children.Add(new TextCard { Text = returnsElement.Value });
            }
        }

        protected void AddDefinitionCode(SourceCodeViewer sourceCodeViewer)
        {
            DefinitionPanel.Children.Add(sourceCodeViewer);
        }

        protected void AddSourceCode(SourceCodeViewer sourceCodeViewer)
        {
            SamplePanel.Children.Add(sourceCodeViewer);
        }

        //XmlRootの名前を取得
        private string GetXElementRootTag()
        {
            XElement xElement = XElement;

            while (xElement.Parent != null)
            {
                xElement = xElement.Parent;
            }

            return xElement.Attribute("Tag").Value;
        }

        protected abstract UIElement GetSampleButton();

        private void ApplyLaunchType()
        {
            switch (LaunchType)
            {
                case LaunchType.NoSample:
                    RootPanel.Children.Remove(ResultsPanel);

                    return;

                case LaunchType.Graphical:
                case LaunchType.Console:
                    ResultsPanel.Children.Remove(_inputsPanel);
                    ResultsPanel.Children.Remove(_outputConsole);
                    ResultsInnerGrid.Children.Remove(LaunchButtons);

                    ResultsPanel.Children.Add(GetSampleButton());

                    return;

                case LaunchType.Pipe:
                    LaunchButton.IsEnabled = false;

                    break;
            }

            //入力部分
            XElement xInputs = XElement.Element("Inputs");
            if (xInputs == null) return;

            foreach (XElement xInput in xInputs.Elements())
            {
                switch(xInput.Name.LocalName)
                {
                    case "ComboBox":
                        _inputsPanel.Children.Add(new ComboBoxPane(xInput));
                        break;

                    case "FileOpenPicker":
                        _inputsPanel.Children.Add(new FileOpenPane(xInput));
                        break;

                    case "FileSavePicker":
                        _inputsPanel.Children.Add(new FileSavePane(xInput));
                        break;

                    case "KeyValueComboBox":
                        _inputsPanel.Children.Add(new KeyValueComboBoxPane(xInput));
                        break;

                    case "TextBox":
                        _inputsPanel.Children.Add(new TextPane(xInput));
                        break;
                    case "NumberBox":
                        _inputsPanel.Children.Add(new NumberBoxPane(xInput));
                        break;
                }
            }

            //入力部分があればリロードボタンを無効にする
            ReloadButton.IsEnabled = _inputsPanel.Children.Count == 0;

            //もしファイルピッカーが含まれていればテキスト変更時にサンプルを実行しないようにする
            if (_inputsPanel.HasFilePicker)
            {
                foreach (UIElement uiElement in _inputsPanel.Children)
                {
                    if (uiElement is TextPane textPane)
                    {
                        textPane.DeleteEvent();
                    }
                }
            }
        }

        private void LaunchButton_Click(object sender, RoutedEventArgs e)
        {
            LaunchByButton();
        }

        private void ViewExpander_Expanding(Expander sender, ExpanderExpandingEventArgs args)
        {
            Expander.Expanding -= ViewExpander_Expanding;
            SetAsDeletedFunction();


            ApplyDefinition();
            if (_isNotSupported) return;
            ApplyFolder();
            ApplyParameters();
            ApplyReturns();
            ApplySourceCode();

            if (RootPanel.Children.Contains(ResultsPanel))
            {
                ApplyLaunchType();
            }


            if (RootPanel.Children.Contains(ResultsPanel) && ResultsInnerGrid.Children.Contains(LaunchButtons) && !_inputsPanel.HasFilePicker)
            {
                Launch();
            }

        }

        private void ReloadButton_Click(object sender, RoutedEventArgs e)
        {
            Launch();
        }
    }
}
