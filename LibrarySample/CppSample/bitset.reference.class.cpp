#include "pch.h"
using namespace std;

//_E1
static int f0(void)
{
    bitset<8> bs;

    cout << bs << endl;

    bs[0] = true;
    bs[6] = true;

    cout << bs << endl;

    return 0;
}

//_E2
static int f1(void)
{
    bitset<8> bs = 0b11110000;

    cout << bs << endl;

    bs[0] = bs[7];
    bs[2] = bs[5];
    bs[4] = bs[3];
    bs[6] = bs[1];

    cout << bs << endl;

    return 0;
}

//_Bool
static int f2(void)
{
    bitset<2> bs = 0b10;

    bool value1 = bs[0];
    bool value2 = bs[1];

    cout << boolalpha;
    cout << "value1: " << value1 << endl;
    cout << "value2: " << value2 << endl;

    return 0;
}

//_~
static int f3(void)
{
    bitset<8> bs = 0b11110000;

    size_t i;

    cout << " bs: ";
    for (i = 0; i < bs.size(); i++) {
        cout << bs[i];
    }
    cout << endl;

    cout << "~bs: ";
    for (i = 0; i < bs.size(); i++) {
        cout << ~bs[i];
    }
    cout << endl;

    return 0;
}

//flip
static int f4(void)
{
    bitset<8> bs = 0b11001100;

    cout << bs << endl;

    bs[0].flip();
    bs[4].flip();

    cout << bs << endl;

    return 0;
}

int bitset__reference__class__run(FUNCNAME)
{
    if (IsEqualFuncName("_E1")) return f0();
    if (IsEqualFuncName("_E2")) return f1();
    if (IsEqualFuncName("_Bool")) return f2();
    if (IsEqualFuncName("_~")) return f3();
    if (IsEqualFuncName("flip")) return f4();

    return NotFound(FUNCNAMEVALUE);
}