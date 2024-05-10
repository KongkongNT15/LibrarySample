#include "pch.h"
using namespace std;

namespace
{
    class Hoge {
        virtual void foo() {}
    };

}

//what
static int f0(void)
{
    int* p1 = nullptr;
    string* p2 = nullptr;
    Hoge* p3 = nullptr;

    try {
        cout << "p1 : " << typeid(p1).name() << endl;
        cout << "*p1: " << typeid(*p1).name() << endl;
        cout << "p2 : " << typeid(p2).name() << endl;
        cout << "*p2: " << typeid(*p2).name() << endl;
        cout << "p3 : " << typeid(p3).name() << endl;
        cout << "*p3: " << typeid(*p3).name() << endl;
    }
    catch (bad_typeid& e) {
        cerr << "typeid ‰‰ŽZŽq‚É nullptr ‚ª‘ã“ü‚³‚ê‚Ü‚µ‚½" << endl;
        cerr << e.what() << endl;

        return 1;
    }

    return 0;
}

int bad_typeid__class__run(FUNCNAME)
{
    if (IsEqualFuncName("what")) return f0();

    return NotFound(FUNCNAMEVALUE);
}