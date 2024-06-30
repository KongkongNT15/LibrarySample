#include "pch.h"
#include "AllSamples.h"

namespace Kongkong
{
	int RunSample(const char* rootTag, const char* functionTag)
	{
		if (IsEqualString(rootTag, "winrt.hstring.struct")) return Run_winrt_hstring_struct(functionTag);
		if (IsEqualString(rootTag, "winrt.Windows.Data.Html.HtmlUtilities.class")) return Run_winrt_Windows_Data_Html_HtmlUtilities_class(functionTag);
		

		return NotFound(rootTag);
	}
}