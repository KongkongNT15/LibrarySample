#include "pch.h"
using namespace std;

namespace
{
    struct Base {
        virtual void foo() {}
    };

    struct Derived : public Base {};

}

//what
static int f0(void)
{
    Base b;

    try {
        auto& d = dynamic_cast<Derived&>(b);
        cout << "d = (Derived)b" << endl;
    }
    catch (bad_cast& e) {
        cerr << "dynamic_cast�Ɏ��s���܂���" << endl;
        cerr << e.what() << endl;
    }

    return 0;
}

int bad_cast__class__run(FUNCNAME)
{
    if (IsEqualFuncName("what")) return f0();

    return NotFound(FUNCNAMEVALUE);
}