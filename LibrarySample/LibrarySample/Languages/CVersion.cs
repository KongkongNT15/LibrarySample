using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Languages
{
    public enum CVersion
    {
        C11,
        C17,
        C23,
        MinValue = C11,
        MaxValue = C23,
    }
}
