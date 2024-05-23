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

		return -1;
	}

	int RunSample(const char* rootTag, const char* functionTag)
	{

		return NotFound(rootTag);
	}
}
