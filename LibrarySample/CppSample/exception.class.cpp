#include "pch.h"
using namespace std;

static int f0(void)
{
    try {
        string str = "a";

        //���݂��Ȃ��v�f�ɃA�N�Z�X
        char c = str.at(100);
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

int exception__class__run(FUNCNAME)
{
    if (IsEqualFuncName("what")) return f0();

    return NotFound(FUNCNAMEVALUE);
}