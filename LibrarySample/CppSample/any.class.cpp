#include "pch.h"
using namespace std;

#if HAS_CPP17

//any2
static int f0(void)
{
    any obj1 = 4;
    any obj2 = obj1;

    cout << "obj1: " << any_cast<int>(obj1) << endl;
    cout << "obj2: " << any_cast<int>(obj2) << endl;

    return 0;
}

//any4
static int f1(void)
{
    any obj1("レポートを受け取りました。");
    any obj2 = "よくできているようです。";

    cout << any_cast<const char*>(obj1) << endl;
    cout << any_cast<const char*>(obj2) << endl;

    return 0;
}

//any5
static int f2(void)
{
    any obj{ in_place_type<string>, 10, 'A' };

    cout << any_cast<string>(obj) << endl;

    return 0;
}

//_E1
static int f3(void)
{
    any obj1 = 5;
    any obj2 = 'A';

    cout << "obj1: " << any_cast<int>(obj1) << endl;
    cout << "obj2: " << any_cast<char>(obj2) << endl;
    cout << endl;

    obj2 = obj1;

    cout << "obj1: " << any_cast<int>(obj1) << endl;
    cout << "obj2: " << any_cast<int>(obj2) << endl;

    return 0;
}

//_E3
static int f4(void)
{
    any obj;

    obj = 45;
    cout << any_cast<int>(obj) << endl;

    obj = 12.6;
    cout << any_cast<double>(obj) << endl;

    return 0;
}

//emplace1
static int f5(void)
{
    any obj;

    obj.emplace<string>(10, 'A');

    cout << "obj: " << any_cast<string>(obj) << endl;

    return 0;
}

//has_value
static int f6(void)
{
    any obj;

    cout << boolalpha;
    cout << obj.has_value() << endl;

    obj = "センスがありません";
    cout << obj.has_value() << endl;

    return 0;
}

//reset
static int f7(void)
{
    any obj = "センスがありません";

    cout << boolalpha;
    cout << obj.has_value() << endl;

    obj.reset();
    cout << obj.has_value() << endl;

    return 0;
}

//swap
static int f8(void)
{
    any obj1, obj2;

    obj1 = 100;
    obj2 = string("よくできているようです");

    cout << "obj1: " << any_cast<int>(obj1) << endl;
    cout << "obj2: " << any_cast<string>(obj2) << endl;
    cout << endl;

    obj1.swap(obj2);

    cout << "obj1: " << any_cast<string>(obj1) << endl;
    cout << "obj2: " << any_cast<int>(obj2) << endl;

    return 0;
}

//type
static int f9(void)
{
    constexpr size_t length = 5;
    any objects[length];

    objects[0] = 12;
    objects[1] = 1.2;
    objects[2] = nullptr;
    objects[3] = "龍が如く";
    objects[4] = string("維新");

    for (size_t i = 0; i < length; ++i) {
        cout << objects[i].type().name() << endl;
    }

    return 0;
}

#endif

int any__class__run(FUNCNAME)
{
#if HAS_CPP17
    if (IsEqualFuncName("any2")) return f0();
    if (IsEqualFuncName("any4")) return f1();
    if (IsEqualFuncName("any5")) return f2();
    if (IsEqualFuncName("_E1")) return f3();
    if (IsEqualFuncName("_E3")) return f4();
    if (IsEqualFuncName("emplace1")) return f5();
    if (IsEqualFuncName("has_value")) return f6();
    if (IsEqualFuncName("reset")) return f7();
    if (IsEqualFuncName("swap")) return f8();
    if (IsEqualFuncName("type")) return f9();

#endif

    return NotFound(FUNCNAMEVALUE);
}