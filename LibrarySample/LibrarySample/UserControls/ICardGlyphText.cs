using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.UserControls
{
    public interface ICardGlyphText
    {
        string Title { get; set; }
        string Description { get; set; }
        string Glyph { get; set; }
    }
}
