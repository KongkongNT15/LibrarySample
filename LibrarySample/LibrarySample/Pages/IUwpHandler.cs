using LibrarySample.SampleManagement;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Pages
{
    public interface IUwpHandler
    {
        WinRTDesign Design { get; }
        CodeLanguage CodeLanguage { get; }
        ProcesserType ProcesserType { get; }
    }
}
