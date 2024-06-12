#include "pch.h"
using namespace std;

//max
static int f0(void)
{
    cout << minstd_rand::max() << endl;
    cout << minstd_rand0::max() << endl;

    return 0;
}

//min
static int f1(void)
{
    cout << minstd_rand::min() << endl;
    cout << minstd_rand0::min() << endl;

    return 0;
}

//linear_congruential_engine
static int f2(void)
{
    minstd_rand mr;

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }

    return 0;
}

//linear_congruential_engine
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

    minstd_rand mr{ seed };

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }

    return 0;
}

//discard
static int f4(void)
{
    minstd_rand mr;
    unsigned long long nSkip;

    if (IsConsole) cout << "空回しする回数: ";
    cin >> nSkip;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mr.discard(nSkip);

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }

    return 0;
}

//seed
static int f5(void)
{
    minstd_rand mr;
    unsigned seed;

    if (IsConsole) cout << "シード値1: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値1を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mr.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }
    cout << endl;

    if (IsConsole) cout << "シード値2: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値2を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mr.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }

    return 0;
}

//_LL
static int f6(void)
{
    minstd_rand mr;

    cout << mr << endl;

    return 0;
}

//_RR
static int f7(void)
{
    minstd_rand mr;

    if (IsConsole) cout << "シーケンスを入力: ";
    cin >> mr;

    if (!cin) {
        cerr << "状態が正しく設定されませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    for (int i = 0; i < 10; i++) {
        cout << mr() << endl;
    }

    return 0;
}

int linear_congruential_engine__class__run(FUNCNAME)
{
    if (IsEqualFuncName("linear_congruential_engine")) return f2();
    if (IsEqualFuncName("linear_congruential_engine1")) return f3();
    if (IsEqualFuncName("_LL")) return f6();
    if (IsEqualFuncName("_RR")) return f7();
    if (IsEqualFuncName("discard")) return f4();
    if (IsEqualFuncName("max")) return f0();
    if (IsEqualFuncName("min")) return f1();
    if (IsEqualFuncName("seed")) return f5();

    return NotFound(FUNCNAMEVALUE);
}