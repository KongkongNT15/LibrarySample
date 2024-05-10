using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace LibrarySample.Settings
{
    public readonly struct ReleaseInfo
    {
        public readonly int Year;
        public readonly int Month;
        public readonly int Date;

        public readonly string DateText;

        public readonly int VersionMajor;
        public readonly int VersionMinor;
        public readonly int VersionBuild;
        public readonly int VersionRevision;

        public readonly string VersionText;

        public ReleaseInfo(XElement xReleaseNote)
        {
            Year = int.Parse(xReleaseNote.Attribute("Year").Value);
            Month = int.Parse(xReleaseNote.Attribute("Month").Value);
            Date = int.Parse(xReleaseNote.Attribute("Date").Value);
            VersionMajor = int.Parse(xReleaseNote.Attribute("VersionMajor").Value);
            VersionMinor = int.Parse(xReleaseNote.Attribute("VersionMinor").Value);
            VersionBuild = int.Parse(xReleaseNote.Attribute("VersionBuild").Value);
            VersionRevision = int.Parse(xReleaseNote.Attribute("VersionRevision").Value);

            DateText = $"{Year}年{Month}月{Date}日";
            VersionText = $"Version {VersionMajor}.{VersionMinor}.{VersionBuild}.{VersionRevision}";
        }
    }
}
