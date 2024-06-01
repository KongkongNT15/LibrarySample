#include "pch.h"
using namespace std;

//complex1
static int f0(void)
{
    double real, imag;

    if (IsConsole) cout << "実部: ";
    cin >> real;

    if(!cin) {
        cerr << "実部の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "虚部: ";
    cin >> imag;

    if (!cin) {
        cerr << "虚部の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << complex<double>(real, imag) << endl;

    return 0;
}

//complex2
static int f1(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "complex<double>: " << z << endl;
    cout << "complex<float>:  " << complex<float>(z) << endl;

    return 0;
}

//_E1
static int f2(void)
{
    complex<double> z1;
    complex<float> z2;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z1;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    z2 = z1;

    cout << "complex<double>: " << z1 << endl;
    cout << "complex<float>:  " << complex<float>(z1) << endl;

    return 0;
}

//_E2
static int f3(void)
{
    complex<double> z = { 5, 8 };

    cout << "z = " << z << endl;

    z = 7.6;

    cout << "z = " << z << endl;

    return 0;
}

//imag-real1
static int f4(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z:    " << z << endl;
    cout << "実部: " << z.real() << endl;
    cout << "虚部: " << z.imag() << endl;

    return 0;
}

//imag-real2
static int f5(void)
{
    double real, imag;
    complex<double> z;

    if (IsConsole) cout << "実部: ";
    cin >> real;

    if (!cin) {
        cerr << "実部の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "虚部: ";
    cin >> imag;

    if (!cin) {
        cerr << "虚部の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z = " << z << endl;

    z.real(real);
    z.imag(imag);

    cout << "z = " << z << endl;

    return 0;
}

//_PE3
static int f6(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 += z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_PE2
static int f7(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z = " << z << endl;
    cout << "x = " << x << endl;
    cout << endl;

    z += x;

    cout << "z = " << z << endl;

    return 0;
}

//_PE1
static int f8(void)
{
    complex<double> z1;
    complex<float> z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 += z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_ME1
static int f9(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 -= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_ME2
static int f10(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z = " << z << endl;
    cout << "x = " << x << endl;
    cout << endl;

    z -= x;

    cout << "z = " << z << endl;

    return 0;
}

//_ME3
static int f11(void)
{
    complex<double> z1;
    complex<float> z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 -= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_MuE1
static int f12(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 *= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_MuE2
static int f13(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z = " << z << endl;
    cout << "x = " << x << endl;
    cout << endl;

    z *= x;

    cout << "z = " << z << endl;

    return 0;
}

//_MuE3
static int f14(void)
{
    complex<double> z1;
    complex<float> z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 *= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_DE1
static int f15(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 /= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

//_DE2
static int f16(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z = " << z << endl;
    cout << "x = " << x << endl;
    cout << endl;

    z /= x;

    cout << "z = " << z << endl;

    return 0;
}

//_DE3
static int f17(void)
{
    complex<double> z1;
    complex<float> z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    z1 /= z2;

    cout << "z1 = " << z1 << endl;

    return 0;
}

int complex__class__run(FUNCNAME)
{
    if (IsEqualFuncName("complex1")) return f0();
    if (IsEqualFuncName("complex2")) return f1();
    if (IsEqualFuncName("_E1")) return f2();
    if (IsEqualFuncName("_E2")) return f3();
    if (IsEqualFuncName("_DE1")) return f15();
    if (IsEqualFuncName("_DE2")) return f16();
    if (IsEqualFuncName("_DE3")) return f17();
    if (IsEqualFuncName("_ME1")) return f9();
    if (IsEqualFuncName("_ME2")) return f10();
    if (IsEqualFuncName("_ME3")) return f11();
    if (IsEqualFuncName("_MuE1")) return f12();
    if (IsEqualFuncName("_MuE2")) return f13();
    if (IsEqualFuncName("_MuE3")) return f14();
    if (IsEqualFuncName("_PE1")) return f8();
    if (IsEqualFuncName("_PE2")) return f7();
    if (IsEqualFuncName("_PE3")) return f6();
    if (IsEqualFuncName("imag-real1")) return f4();
    if (IsEqualFuncName("imag-real2")) return f5();

    return NotFound(FUNCNAMEVALUE);
}