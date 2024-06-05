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
    public class ContentPageFrame : Frame
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

        public Library CurrentLanguage
        {
            get
            {
                if (Content is ICHandler) return Library.C;
                if (Content is ICppHandler) return Library.Cpp;
                if (Content is IWin32Handler) return Library.Win32;
                if (Content is ICppWinRTHandler) return Library.CppWinRTNamespace;
                if (Content is IUwpHandler) return Library.Uwp;

                return Library.None;
            }
        }

        public void Reload()
        {

            if (Content is IXml xml)
            {
                XElement xElement = xml.XElement;

                Navigate(CurrentSourcePageType, null, DrillInNavigationTransitionInfo);

                (Content as IXml).XElement = xElement;

                return;
            }

            Navigate(CurrentSourcePageType, null, DrillInNavigationTransitionInfo);
        }
    }
}
