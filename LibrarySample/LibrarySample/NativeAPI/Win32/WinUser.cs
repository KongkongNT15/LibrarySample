using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.NativeAPI.Win32
{
    public static class Winuser
    {
        [DllImport("user32.dll")]
        public static extern int IsZoomed(IntPtr hWnd);
    }
}
