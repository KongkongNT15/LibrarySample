#include "pch.h"
using namespace std;

//max
static int f0(void)
{
    cout << ranlux24_base::max() << endl;
    cout << ranlux48_base::max() << endl;

    return 0;
}

//min
static int f1(void)
{
    cout << ranlux24_base::min() << endl;
    cout << ranlux48_base::min() << endl;

    return 0;
}

//subtract_with_carry_engine
static int f2(void)
{
    ranlux24_base r24b;

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }

    return 0;
}

//subtract_with_carry_engine1
static int f3(void)
{
    unsigned seed;

    if (IsConsole) cout << "シード値: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    ranlux24_base r24b{ seed };

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }

    return 0;
}

//discard
static int f4(void)
{
    ranlux24_base r24b;
    unsigned long long nSkip;

    if (IsConsole) cout << "空回しする回数: ";
    cin >> nSkip;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    r24b.discard(nSkip);

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }

    return 0;
}

//seed
static int f5(void)
{
    ranlux24_base r24b;
    unsigned seed;

    if (IsConsole) cout << "シード値1: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値1を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    r24b.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }
    cout << endl;

    if (IsConsole) cout << "シード値2: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値2を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    r24b.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }

    return 0;
}

//_LL
static int f6(void)
{
    ranlux24_base r24b;

    cout << r24b << endl;

    return 0;
}

//_RR
static int f7(void)
{
    ranlux24_base r24b;

    if (IsConsole) cout << "シーケンスを入力: ";
    cin >> r24b;

    if (!cin) {
        cerr << "状態が正しく設定されませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    for (int i = 0; i < 10; i++) {
        cout << r24b() << endl;
    }

    return 0;
}

int subtract_with_carry_engine__class__run(FUNCNAME)
{
    if (IsEqualFuncName("max")) return f0();
    if (IsEqualFuncName("min")) return f1();
    if (IsEqualFuncName("subtract_with_carry_engine")) return f2();
    if (IsEqualFuncName("subtract_with_carry_engine1")) return f3();
    if (IsEqualFuncName("discard")) return f4();
    if (IsEqualFuncName("seed")) return f5();
    if (IsEqualFuncName("_LL")) return f6();
    if (IsEqualFuncName("_RR")) return f7();


	return NotFound(FUNCNAMEVALUE);
}