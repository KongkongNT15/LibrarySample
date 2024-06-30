#include "pch.h"

namespace Kongkong
{
	bool IsEqualString(const char* left, const char* right)
	{
		return ::strcmp(left, right) == 0;
	}
}