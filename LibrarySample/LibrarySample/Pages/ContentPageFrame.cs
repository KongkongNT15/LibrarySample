using LibrarySample.UserControls;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Media.Animation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LibrarySample.Pages
{
    internal class ContentPageFrame : Frame
    {
        public static NavigationTransitionInfo DrillInNavigationTransitionInfo { get; } = new DrillInNavigationTransitionInfo();
        public static NavigationTransitionInfo SlideFromLeftNavigationTransitionInfo { get; } = new SlideNavigationTransitionInfo() { Effect = SlideNavigationTransitionEffect.FromLeft };
        public static NavigationTransitionInfo SlideFromRightNavigationTransitionInfo { get; } = new SlideNavigationTransitionInfo() { Effect = SlideNavigationTransitionEffect.FromRight };
        public static NavigationTransitionInfo SuppressNavigationTransitionInfo { get; } = new SuppressNavigationTransitionInfo();
        public static NavigationTransitionInfo EntranceNavigationTransitionInfo { get; } = new EntranceNavigationTransitionInfo();

        private List<XElement> XElements { get; } = [];

        public void AddXElement(XElement element)
        {
            XElements.Add(element);
        }

        public new void GoBack()
        {
            if (Content is IXml)
            {
                XElements.RemoveAt(XElements.Count - 1);
            }
            base.GoBack();

            if(Content is IXml xml1)
            {
                xml1.XElement = XElements[^1];

                //ふぁ！？っく
                XElements.RemoveAt(XElements.Count - 1);
            }
        }

        public CodeLanguage CurrentLanguage
        {
            get
            {
                if (Content is ICHandler) return CodeLanguage.C;
                if (Content is ICppHandler) return CodeLanguage.Cpp;

                return CodeLanguage.None;
            }
        }
    }
}
