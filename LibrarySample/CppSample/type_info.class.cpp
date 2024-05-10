#include "pch.h"
using namespace std;

namespace
{
    void printinfo1(type_info const& info1, type_info const& info2, const char* name1, const char* name2)
    {
        if (info1 == info2) cout << name1 << " == " << name2 << endl;
        else cout << name1 << " != " << name2 << endl;
    }

    void printinfo2(type_info const& info1, type_info const& info2, const char* name1, const char* name2)
    {
        if (info1 != info2) cout << name1 << " != " << name2 << endl;
        else cout << name1 << " == " << name2 << endl;
    }

    struct Hoge1 {};
    struct Hoge2 {};

}

//_EE
static int f0(void)
{
    int i = 0;
    double x = 0.0;

    type_info const& info1 = typeid(int);
    type_info const& info2 = typeid(i);
    type_info const& info3 = typeid(double);
    type_info const& info4 = typeid(x);

    printinfo1(info1, info2, "typeid(int)", "typeid(i)");
    printinfo1(info1, info3, "typeid(int)", "typeid(double)");
    printinfo1(info1, info4, "typeid(int)", "typeid(x)");
    printinfo1(info2, info3, "typeid(i)", "typeid(double)");
    printinfo1(info2, info4, "typeid(i)", "typeid(x)");
    printinfo1(info3, info4, "typeid(double)", "typeid(x)");

    return 0;
}

//_NE
static int f1(void)
{
    int i = 0;
    double x = 0.0;

    type_info const& info1 = typeid(int);
    type_info const& info2 = typeid(i);
    type_info const& info3 = typeid(double);
    type_info const& info4 = typeid(x);

    printinfo2(info1, info2, "typeid(int)", "typeid(i)");
    printinfo2(info1, info3, "typeid(int)", "typeid(double)");
    printinfo2(info1, info4, "typeid(int)", "typeid(x)");
    printinfo2(info2, info3, "typeid(i)", "typeid(double)");
    printinfo2(info2, info4, "typeid(i)", "typeid(x)");
    printinfo2(info3, info4, "typeid(double)", "typeid(x)");

    return 0;
}

//before
static int f2(void)
{
    type_info const& info1 = typeid(Hoge1);
    type_info const& info2 = typeid(Hoge2);
    type_info const& info3 = typeid(int);

    cout << boolalpha;
    cout << info1.before(info2) << endl;
    cout << info2.before(info1) << endl;
    cout << info3.before(info1) << endl;

    return 0;
}

//hash_code
static int f3(void)
{
    cout << "int: " << typeid(int).hash_code() << endl;
    cout << "char: " << typeid(char).hash_code() << endl;
    cout << "void*: " << typeid(void*).hash_code() << endl;
    cout << "double: " << typeid(double).hash_code() << endl;
    cout << "type_info: " << typeid(type_info).hash_code() << endl;

    return 0;
}

//name
static int f4(void)
{
    long n = 0L;
    double x = 0.0;
    string str;

    cout << typeid(int).name() << endl;
    cout << typeid(n).name() << endl;
    cout << typeid(str).name() << endl;

    return 0;
}

int type_info__class__run(FUNCNAME)
{
    if (IsEqualFuncName("_EE")) return f0();
    if (IsEqualFuncName("_NE")) return f1();
    if (IsEqualFuncName("before")) return f2();
    if (IsEqualFuncName("hash_code")) return f3();
    if (IsEqualFuncName("name")) return f4();

    return NotFound(FUNCNAMEVALUE);
}