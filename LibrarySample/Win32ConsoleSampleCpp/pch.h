#pragma once

#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <string_view>

#include <Windows.h>

#include "../Macros/MacroDefinition.h"
#include "../Macros/CreateSampleFunction.h"

namespace Kongkong
{
	extern bool IsConsole;

	bool IsEqualStringA(const char* left, const char* right) noexcept;
	bool IsEqualStringW(const wchar_t* left, const wchar_t* right) noexcept;

	int RunSample(const char* rootTag, const char* sampleTag);
	int RunNotFound(const char* tag) noexcept;


}

CREATE_SAMPLE_FUNCTION(Fileapi)
CREATE_SAMPLE_FUNCTION(Handleapi)
CREATE_SAMPLE_FUNCTION(Winuser)


#undef CREATE_SAMPLE_FUNCTION