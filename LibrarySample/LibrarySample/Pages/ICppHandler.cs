using LibrarySample.Languages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Pages
{
    public interface ICppHandler
    {
        CppVersion CppVersion { get; }
        ProcesserType ProcesserType { get; }
    }
}
