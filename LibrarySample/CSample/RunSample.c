#include "pch.h"

int RunSample(const char* folder, const char* func)
{
    if (IsEqualFolderName("assert.h")) return assert__h__run(func);
    if (IsEqualFolderName("ctype.h")) return ctype__h__run(func);
    if (IsEqualFolderName("errno.h")) return errno__h__run(func);
    if (IsEqualFolderName("float.h")) return float__h__run(func);
    if (IsEqualFolderName("inttypes.h")) return inttypes__h__run(func);
    if (IsEqualFolderName("iso646.h")) return iso646__h__run(func);
    if (IsEqualFolderName("stdbool.h")) return stdbool__h__run(func);
    if (IsEqualFolderName("stdio.h")) return stdio__h__run(func);
    if (IsEqualFolderName("stdnoreturn.h")) return stdnoreturn__h__run(func);

    return NotFound(folder);
}