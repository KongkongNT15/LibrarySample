#pragma once

#include <cstring>
#include <fstream>
#include <locale>
#include <iostream>

#include <winrt/Windows.Data.Html.h>
#include <winrt/Windows.Data.Xml.Dom.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>


namespace Kongkong
{
	extern bool IsConsole;

	bool IsEqualString(const char* left, const char* right);
	int RunSample(const char* rootTag, const char* functionTag);

	int NotFound(const char* tag);

	
	
}

