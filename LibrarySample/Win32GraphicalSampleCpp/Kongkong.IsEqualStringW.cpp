#include "pch.h"

bool Kongkong::IsEqualStringW(const wchar_t* left, const wchar_t* right) noexcept
{
	return wcscmp(left, right) == 0;
}