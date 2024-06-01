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

		cerr << '"' << tag << "\"��������܂���ł���" << endl;

		return -1;
	}

	int RunSample(const char* rootTag, const char* functionTag)
	{
		if (IsEqualString(rootTag, "winrt.hstring.struct")) return winrt__hstring__struct__run(functionTag);
		return NotFound(rootTag);
	}
}
