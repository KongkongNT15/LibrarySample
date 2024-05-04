using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public class InputsPanel : StackPanel
    {
        public bool HasFilePicker
        {
            get
            {
                foreach (UIElement element in Children)
                {
                    if (element is FileOpenPane || element is FileSavePane) return true;
                }
                return false;
            }
        }

        public InputsPanel()
        {

        }

        public string CreateInputs()
        {
            string input = string.Empty;

            foreach (UIElement element in Children)
            {
                if (element is IInputText inputPane)
                {
                    input += inputPane.Text + "\n";
                }
            }

            return input;
        }
    }
}
