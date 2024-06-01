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
    if (IsEqualFolderName("any.class")) return any__class__run(func);
    if (IsEqualFolderName("any.hpp")) return any__hpp__run(func);
    if (IsEqualFolderName("array.class")) return array__class__run(func);
    if (IsEqualFolderName("array.hpp")) return array__hpp__run(func);
    if (IsEqualFolderName("bad_any_cast.class")) return bad_any_cast__class__run(func);
    if (IsEqualFolderName("bad_cast.class")) return bad_cast__class__run(func);
    if (IsEqualFolderName("bad_typeid.class")) return bad_typeid__class__run(func);
    if (IsEqualFolderName("bit.hpp")) return bit__hpp__run(func);
    if (IsEqualFolderName("bitset.class")) return bitset__class__run(func);
    if (IsEqualFolderName("bitset.reference.class")) return bitset__reference__class__run(func);
    if (IsEqualFolderName("bitset.hpp")) return bitset__hpp__run(func);
    if (IsEqualFolderName("charconv.hpp")) return charconv__hpp__run(func);
    if (IsEqualFolderName("complex.class")) return complex__class__run(func);
    if (IsEqualFolderName("complex.hpp")) return complex__hpp__run(func);
    if (IsEqualFolderName("exception.class")) return exception__class__run(func);
    if (IsEqualFolderName("hash.bitset.struct")) return hash__bitset__struct__run(func);
    if (IsEqualFolderName("type_info.class")) return type_info__class__run(func);

    return NotFound(folder);
}