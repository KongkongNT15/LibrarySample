#include "pch.h"
using namespace std;

//_AMP
static int f0(void)
{
    bitset<32> bs1;
    bitset<32> bs2;

    if (IsConsole) cout << "bs1: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1:" << endl;
    cout << bs1 << endl;
    cout << endl;

    cout << "bs2:" << endl;
    cout << bs2 << endl;
    cout << endl;


    cout << "bs1 & bs2:" << endl;
    cout << (bs1 & bs2) << endl;

    return 0;
}

//_V
static int f1(void)
{
    bitset<32> bs1;
    bitset<32> bs2;

    if (IsConsole) cout << "bs1: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1:" << endl;
    cout << bs1 << endl;
    cout << endl;

    cout << "bs2:" << endl;
    cout << bs2 << endl;
    cout << endl;


    cout << "bs1 | bs2:" << endl;
    cout << (bs1 | bs2) << endl;

    return 0;
}

//_H
static int f2(void)
{
    bitset<32> bs1;
    bitset<32> bs2;

    if (IsConsole) cout << "bs1: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1:" << endl;
    cout << bs1 << endl;
    cout << endl;

    cout << "bs2:" << endl;
    cout << bs2 << endl;
    cout << endl;


    cout << "bs1 ^ bs2:" << endl;
    cout << (bs1 ^ bs2) << endl;

    return 0;
}

//_LL
static int f3(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "n: " << endl;
    cout << n << endl;
    cout << endl;

    cout << "nのビット表現:" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;

    return 0;
}

//_RR
static int f4(void)
{
    bitset<128> bs;

    if (IsConsole) cout << "ビット列を入力: ";
    cin >> bs;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "n(bit):" << endl;
    cout << bs << endl;

    return 0;
}

int bitset__hpp__run(FUNCNAME)
{
    if (IsEqualFuncName("_A")) return f0();
    if (IsEqualFuncName("_V")) return f1();
    if (IsEqualFuncName("_H")) return f2();
    if (IsEqualFuncName("_LL")) return f3();
    if (IsEqualFuncName("_RR")) return f4();

	return NotFound(FUNCNAMEVALUE);
}