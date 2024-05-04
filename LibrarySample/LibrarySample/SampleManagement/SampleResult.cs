using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample
{
    public class SampleResult
    {
        private string _outputs;
        public string Outputs => _outputs;

        private uint _returnCode;
        public uint ReturnCode => _returnCode;

        public SampleResult(string outputs, uint returnCode)
        {
            _outputs = outputs.EndsWith(Environment.NewLine) ? outputs[..^Environment.NewLine.Length] : outputs;
            _returnCode = returnCode;
        }
    }
}
