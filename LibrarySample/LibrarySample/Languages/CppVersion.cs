using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Languages
{
    public enum CppVersion
    {
        Cpp14,
        Cpp17,
        Cpp20,
        Cpp23,
        MinValue = Cpp14,
        MaxValue = Cpp23,
    }
}
