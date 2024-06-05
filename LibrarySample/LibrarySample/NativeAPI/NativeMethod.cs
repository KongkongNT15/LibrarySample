using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.NativeAPI
{
    public static class NativeMethod
    {
        [DllImport("NativeMethod.dll", CharSet=CharSet.Unicode)]
        private static extern nint StartSample(string commandLine, string currentDirectory, string input, uint wait, ref uint returnCode);

        public static string StartSampleProcess(string exeName, string commandLine, string currentDirectory, string input, uint wait, ref uint returnCode)
        {
            return Marshal.PtrToStringAnsi(StartSample(exeName + " " + commandLine, currentDirectory, input, wait, ref returnCode));
        }


    }
}
