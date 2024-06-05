#include "pch.h"

namespace Kongkong
{
	bool IsConsole;

	bool IsEqualString(const char* left, const char* right)
	{
		return ::strcmp(left, right) == 0;
	}

	int NotFound(const char* tag)
	{
		using namespace std;

		cerr << '"' << tag << "\"‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
		cerr << "‚Ó‚ŸIH‚Á‚­" << endl;

		return -1;
	}

	int RunSample(const char* rootTag, const char* functionTag)
	{
		if (IsEqualString(rootTag, "winrt.Windows.Data.Html.HtmlUtilities.class")) return Run_winrt_Windows_Data_Html_HtmlUtilities_class(functionTag);
		if (IsEqualString(rootTag, "winrt.hstring.struct")) return Run_winrt_hstring_struct(functionTag);
		return NotFound(rootTag);
	}
}
