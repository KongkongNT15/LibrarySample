#include "pch.h"
using namespace std;

bool IsConsole = false;

bool IsEqual(const char* left, const char* right)
{
    return strcmp(left, right) == 0;
}

int NotFound(const char* funcName)
{
    cerr << '"' << funcName << "\"‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
    return -1;
}

int RunSample(const char* folder, const char* func)
{
    if (IsEqualFolderName("array.class")) return array__class__run(func);
    if (IsEqualFolderName("array.hpp")) return array__hpp__run(func);
    if (IsEqualFolderName("exception.class")) return exception__class__run(func);

    auto d = get<1>(array<int, 5>{ 2, 34, 5, 6, 6 });

    return NotFound(folder);
}