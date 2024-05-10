#include "pch.h"
using namespace std;

#if HAS_CPP17

//what
static int f0(void)
{
    any obj = 54;

    try {
        cout << any_cast<int>(obj) << endl;
        cout << any_cast<string>(obj) << endl;
    }
    catch (bad_any_cast& e) {
        cerr << "any_cast ‚ªŽ¸”s‚µ‚Ü‚µ‚½" << endl;
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}

#endif

int bad_any_cast__class__run(FUNCNAME)
{
#if HAS_CPP17
    if (IsEqualFuncName("what")) return f0();

#endif


    return NotFound(FUNCNAMEVALUE);
}