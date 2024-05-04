using LibrarySample.Languages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Pages
{
    public interface ICHandler
    {
        CVersion CVersion { get; }
        ProcesserType ProcesserType { get; }
    }
}
