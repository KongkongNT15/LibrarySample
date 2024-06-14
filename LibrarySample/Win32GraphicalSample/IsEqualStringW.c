#include "pch.h"

int IsEqualStringW(const wchar_t* left, const wchar_t* right)
{
    return wcscmp(left, right) == 0;
}