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
using Microsoft.UI.Text;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace LibrarySample.UserControls
{
    public abstract partial class FunctionExpander : UserControl, ICardGlyphText
    {
        public static FunctionExpander GetParentFunctionExpander(FrameworkElement frameworkElement)
        {
            try
            {
                FrameworkElement element = frameworkElement;
                while (element is not FunctionExpander)
                {
                    element = element.Parent as FrameworkElement;

                    if (element is null) throw new Exception();
                }

                return element as FunctionExpander;
            }
            catch
            {
                FrameworkElement element = frameworkElement;
                while (element.Tag is not FunctionExpander)
                {
                    element = element.Parent as FrameworkElement;
                }

                return element.Tag as FunctionExpander;
            }
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
            get => CurrentTextContent.Title;
            set => CurrentTextContent.Title = value;
        }

        public string Description
        {
            get => CurrentTextContent.Description;
            set => CurrentTextContent.Description = value;
        }

        public string Glyph
        {
            get => CurrentTextContent.Glyph;
            set => CurrentTextContent.Glyph = value;
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

        //�T���v�������s�����ǂ���
        protected bool _isWorking = false;

        private ICardGlyphText CurrentTextContent => SaveData.DisplayFormat switch
        {
            SampleDisplayFormat.Expander => ViewExpander,
            SampleDisplayFormat.PopUp => CardButton,
            _ => throw new NotImplementedException(),
        };

        private CardButton CardButton = null;
        private ViewExpander ViewExpander = null;
        private StackPanel RootPanel = null;
        private StackPanel DefinitionPanel = null;
        private StackPanel ParameterPanel = null;
        private StackPanel ReturnsPanel = null;
        private StackPanel SamplePanel = null;
        private StackPanel ResultsPanel = null;
        private Grid ResultsInnerGrid = null;
        private StackPanel LaunchButtons = null;
        private Button ReloadButton = null;
        private Button LaunchButton = null;
        private InputsPanel _inputsPanel = null;
        private ConsolePane _outputConsole = null;

        private FrameworkElement SampleContent = null;

        public FunctionExpander(XElement xElement, Category category, LaunchType defaultLaunchType = LaunchType.PipeConsole)
        {
            switch (SaveData.DisplayFormat)
            {
                case SampleDisplayFormat.Expander:
                    ViewExpander = new ViewExpander
                    {
                        HorizontalAlignment = HorizontalAlignment.Stretch,
                        MinHeight = Data.ControlHeight
                    };
                    ViewExpander.Expanding += ViewExpander_Expanding;
                    Content = ViewExpander;
                    break;
                case SampleDisplayFormat.PopUp:
                    CardButton = new CardButton();
                    CardButton.Click += CardButton_Click_Initialize;
                    CardButton.Click += CardButton_Click;
                    Content = CardButton;
                    break;
            }

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
                Category.Constructor => "�I�u�W�F�N�g���\�z���܂�",
                Category.Destructor => "�I�u�W�F�N�g��j�����܂�",
                _ => xElement.Attribute("Description").Value,
            };

            LaunchType = EnumConverter.ToLaunchType(XElement.Attribute("LaunchType")?.Value, defaultLaunchType);

            //�������T���v��
            if (Description == "???")
            {
                IsEnabled = false;
            }
            
        }

        private void CardButton_Click_Initialize(object sender, RoutedEventArgs e)
        {
            CardButton.Click -= CardButton_Click_Initialize;
            InitializeContent();
            SetContent();
        }

        private void CardButton_Click(object sender, RoutedEventArgs e)
        {
            if (SampleContent.Parent == null)
            {
                PopUpWindow popUpWindow = new PopUpWindow(SampleContent);
                popUpWindow.Title = Title;

                popUpWindow.Activate();
            }
            else
            {
                var window = PopUpWindow.SearchWindow(SampleContent);
                window.Activate();

            }
        }

        private void InitializeContent()
        {
            RootPanel = new StackPanel
            {
                Spacing = Data.FunctionExpanderStackPanelSpacing,
            };
            SampleContent = RootPanel;
            RootPanel.Tag = this;

            DefinitionPanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
            RootPanel.Children.Add(DefinitionPanel);
            DefinitionPanel.Children.Add(new TextBlock { Text = "��`", FontSize = 18, FontWeight = FontWeights.Bold, });

            ParameterPanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
            RootPanel.Children.Add(ParameterPanel);
            ParameterPanel.Children.Add(new TextBlock { Text = "�p�����[�^�[", FontSize = 18, FontWeight = FontWeights.Bold, });

            ReturnsPanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
            RootPanel.Children.Add(ReturnsPanel);
            ReturnsPanel.Children.Add(new TextBlock { Text = "�߂�l", FontSize = 18, FontWeight = FontWeights.Bold, });

            SamplePanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
            RootPanel.Children.Add(SamplePanel);
            SamplePanel.Children.Add(new TextBlock { Text = "�T���v��", FontSize = 18, FontWeight = FontWeights.Bold, });

            ResultsPanel = new StackPanel { Spacing = Data.DefaultStackPanelSpacing };
            RootPanel.Children.Add(ResultsPanel);
            ResultsInnerGrid = new Grid();
            ResultsPanel.Children.Add(ResultsInnerGrid);
            ResultsInnerGrid.Children.Add(new TextBlock { Text = "���s����", VerticalAlignment = VerticalAlignment.Bottom });

            LaunchButtons = new StackPanel
            {
                Spacing = Data.DefaultStackPanelSpacing,
                Orientation = Orientation.Horizontal,
                HorizontalAlignment = HorizontalAlignment.Right,
            };
            ResultsInnerGrid.Children.Add(LaunchButtons);

            ReloadButton = new Button { Content = new FontIcon { Glyph = "\uE72C" } };
            ReloadButton.Click += ReloadButton_Click;
            LaunchButtons.Children.Add(ReloadButton);

            LaunchButton = new Button { Content = new FontIcon { Glyph = "\uE756", FontFamily = new FontFamily("Segoe MDL2 Assets") } };
            LaunchButton.Click += LaunchButton_Click;
            LaunchButtons.Children.Add (LaunchButton);

            _inputsPanel = new InputsPanel { Spacing = Data.DefaultStackPanelSpacing };
            ResultsPanel.Children.Add(_inputsPanel);

            _outputConsole = new ConsolePane();
            ResultsPanel.Children.Add(_outputConsole);
        }

        //�����Œ�`�ƃT���v���̃R�[�h�̗�����ݒ�
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

            SampleContent = infoBar;
        }

        //_folder��_funcName�ɒl������
        private void ApplyFolder()
        {
            XAttribute xAttribute = XElement.Attribute("Tag");
            _folder = GetXElementRootTag();

            if (xAttribute != null)
            {
                _funcName = xAttribute.Value;
            }
        }

        //�폜���ꂽ�֐�
        private void SetAsDeletedFunction()
        {
            XAttribute xDeletedFunction = XElement.Attribute("IsDeleted");

            //False�Ɣ���
            if (xDeletedFunction == null) return;

            if (xDeletedFunction.Value == "False") return;

            InfoBar infoBar = new InfoBar();

            infoBar.Severity = InfoBarSeverity.Error;
            infoBar.IsOpen = true;
            infoBar.IsClosable = false;
            
            switch (Category)
            {
                case Category.Operator:
                    infoBar.Title = "�폜���ꂽ���Z�q";
                    infoBar.Message = "���̉��Z�q�͍폜����Ă��܂�";
                    break;

                case Category.Constructor:
                    infoBar.Title = "�폜���ꂽ�R���X�g���N�^�[";
                    infoBar.Message = "���̃R���X�g���N�^�[�͍폜����Ă��܂�";
                    break;

                case Category.Method:
                case Category.Function:
                    infoBar.Title = "�폜���ꂽ�֐�";
                    infoBar.Message = "���̊֐��͍폜����Ă��܂�";
                    break;

                default: throw new Exception();
            }

            RootPanel.Children.Insert(0, infoBar);

            _isDeletedFunction = true;
        }


        //��`�t�@�C���̓ǂݍ���
        protected abstract void ApplyDefinition();

        //ConsoleButton����N��
        protected abstract void LaunchByButton();

        protected async Task LaunchAsync(SampleRunner sampleRunner)
        {
            if (_isWorking) return;
            _isWorking = true;

            var result = await sampleRunner.RunSampleAsync(Folder, FuncName, InputsPanel.CreateInputs());

            OutputConsole.Output = result.Outputs;

            _isWorking = false;
        }

        //�T���v���̎��s
        public abstract void Launch();

        private void ApplyParameters()
        {
            //�폜���ꂽ�֐��͈����̐����̕K�v�Ȃ�
            if (_isDeletedFunction)
            {
                RootPanel.Children.Remove(ParameterPanel);
                return;
            }

            //�֐��`���ȊO�̓p�����[�^�Ȃ�
            if (!Category.IsFunctionType())
            {
                RootPanel.Children.Remove(ParameterPanel);
                return;
            }
            XElement returnsElement = XElement.Element("Parameters");

            if (returnsElement == null)
            {

                ParameterPanel.Children.Add(new TextCard { Text = "�Ȃ�(void)" });


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
            //�폜���ꂽ�֐��͖߂�l�̐����̕K�v�Ȃ�
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
                        ReturnsPanel.Children.Add(new TextCard { Text = "�쐬���ꂽ�I�u�W�F�N�g" });
                        break;

                    default:
                        ReturnsPanel.Children.Add(new TextCard { Text = "�Ȃ�(void)" });
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

        //XmlRoot�̖��O���擾
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

            //���͕���
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

            //���͕���������΃����[�h�{�^���𖳌��ɂ���
            ReloadButton.IsEnabled = _inputsPanel.Children.Count == 0;

            //�����t�@�C���s�b�J�[���܂܂�Ă���΃e�L�X�g�ύX���ɃT���v�������s���Ȃ��悤�ɂ���
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

        private void SetContent()
        {
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

        private void ViewExpander_Expanding(Expander sender, ExpanderExpandingEventArgs args)
        {
            ViewExpander.Expanding -= ViewExpander_Expanding;
            InitializeContent();
            ViewExpander.Content = SampleContent;
            SetContent();
        }

        private void ReloadButton_Click(object sender, RoutedEventArgs e)
        {
            Launch();
        }
    }
}
