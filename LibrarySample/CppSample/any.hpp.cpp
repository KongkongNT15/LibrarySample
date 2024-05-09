#include "pch.h"
using namespace std;

#if HAS_CPP17

//any_cast1
static int f0(void)
{
    any obj1, obj2, obj3;

    obj1 = 25;
    obj2 = 15.0;
    obj3 = "ê^ìáåöê›"s;

    cout << "obj: " << any_cast<int>(obj1) << endl;
    cout << "obj: " << any_cast<double>(obj2) << endl;
    cout << "obj: " << any_cast<string>(obj3) << endl;

    return 0;
}

//any_cast2
static int f1(void)
{
    const any obj = 5;

    int value = any_cast<int>(obj);

    cout << "value: " << value << endl;

    return 0;
}

//make_any1
static int f2(void)
{
    any pbj = make_any<string>(10, 'A');

    cout << any_cast<string>(pbj) << endl;

    return 0;
}

//swap
static int f3(void)
{
    any obj1, obj2;

    obj1 = 100;
    obj2 = string("ÇÊÇ≠Ç≈Ç´ÇƒÇ¢ÇÈÇÊÇ§Ç≈Ç∑");

    swap(obj1, obj2);

    cout << "obj1: " << any_cast<string>(obj1) << endl;
    cout << "obj2: " << any_cast<int>(obj2) << endl;

    return 0;
}

#endif

int any__hpp__run(FUNCNAME)
{
#if HAS_CPP17
    if (IsEqualFuncName("any_cast1")) return f0();
    if (IsEqualFuncName("any_cast2")) return f1();
    if (IsEqualFuncName("make_any1")) return f2();
    if (IsEqualFuncName("swap")) return f3();

#endif

    return NotFound(FUNCNAMEVALUE);
}