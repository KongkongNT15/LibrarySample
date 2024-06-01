#include "pch.h"
using namespace std;

//__i1
static int f0(void)
{
    complex<double> z = 1.0 + 2.0i;

    cout << "z: " << z << endl;

    return 0;
}

//__i2
static int f1(void)
{
    complex<double> z = 12.0 + 7i;

    cout << "z: " << z << endl;

    return 0;
}

//__if1
static int f2(void)
{
    complex<float> z = 1.2f + 3.0if;

    cout << "z: " << z << endl;

    return 0;
}

//__if2
static int f3(void)
{
    complex<float> z = 7.4f + 9if;

    cout << "z: " << z << endl;

    return 0;
}

//__il1
static int f4(void)
{
    complex<long double> z = -8.5l + 2.5il;

    cout << "z: " << z << endl;

    return 0;
}

//__il2
static int f5(void)
{
    complex<long double> z = 45.3l + -87il;

    cout << "z: " << z << endl;

    return 0;
}

//_NE1
static int f6(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;
    cout << endl;

    if (z1 != z2) cout << "z1 != z2" << endl;
    else cout << "z1 == z2" << endl;

    return 0;
}

//_EE1
static int f7(void)
{
    complex<double> z1, z2;

    if (IsConsole) cout << "z1: ";
    cin >> z1;

    if (!cin) {
        cerr << "z1の値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "z2: ";
    cin >> z2;

    if (!cin) {
        cerr << "z2の値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;
    cout << endl;

    if (z1 == z2) cout << "z1 == z2" << endl;
    else cout << "z1 != z2" << endl;

    return 0;
}

//_EE2
static int f8(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "z: " << z << endl;
    cout << "x: " << x << endl;
    cout << endl;

    if (z == x) cout << "z == x" << endl;
    else cout << "z != x" << endl;

    return 0;
}

//_EE3
static int f9(void)
{
    double x;
    complex<double> z;
    
    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;
    cout << endl;

    if (x == z) cout << "x == z" << endl;
    else cout << "x != z" << endl;

    return 0;
}

//_NE2
static int f10(void)
{
    complex<double> z;
    double x;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "z: " << z << endl;
    cout << "x: " << x << endl;
    cout << endl;

    if (z != x) cout << "z != x" << endl;
    else cout << "z == x" << endl;

    return 0;
}

//_NE3
static int f11(void)
{
    double x;
    complex<double> z;

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "x: " << x << endl;
    cout << "z: " << z << endl;
    cout << endl;

    if (x != z) cout << "x != z" << endl;
    else cout << "x == z" << endl;

    return 0;
}

//_P1
static int f12(void)
{
    complex<double> z;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    cout << " z = " << z << endl;
    cout << "+z = " << +z << endl;

    return 0;
}

//_P2
static int f13(void)
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

    cout << "z1:      " << z1 << endl;
    cout << "z2:      " << z2 << endl;
    cout << "z1 + z2: " << z1 + z2 << endl;

    return 0;
}

//_P3
static int f14(void)
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

    cout << "z:     " << z << endl;
#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z + x: " << z + x << endl;

    return 0;
}

//_P4
static int f15(void)
{
    double x;
    complex<double> z;

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }
    
    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z:     " << z << endl;
    cout << "x + z: " << x + z << endl;

    return 0;
}

//_M1
static int f16(void)
{
    complex<double> z;

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    cout << " z = " << z << endl;
    cout << "-z = " << -z << endl;

    return 0;
}

//_M2
static int f17(void)
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

    cout << "z1:      " << z1 << endl;
    cout << "z2:      " << z2 << endl;
    cout << "z1 - z2: " << z1 - z2 << endl;

    return 0;
}

//_M3
static int f18(void)
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

    cout << "z:     " << z << endl;
#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z - x: " << z - x << endl;

    return 0;
}

//_M4
static int f19(void)
{
    double x;
    complex<double> z;

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z:     " << z << endl;
    cout << "x - z: " << x - z << endl;

    return 0;
}

//_Mu2
static int f20(void)
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

    cout << "z1:      " << z1 << endl;
    cout << "z2:      " << z2 << endl;
    cout << "z1 * z2: " << z1 * z2 << endl;

    return 0;
}

//_Mu3
static int f21(void)
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

    cout << "z:     " << z << endl;
#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z * x: " << z * x << endl;

    return 0;
}

//_Mu4
static int f22(void)
{
    double x;
    complex<double> z;

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z:     " << z << endl;
    cout << "x * z: " << x * z << endl;

    return 0;
}

//_D2
static int f23(void)
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

    cout << "z1:      " << z1 << endl;
    cout << "z2:      " << z2 << endl;
    cout << "z1 / z2: " << z1 / z2 << endl;

    return 0;
}

//_D3
static int f24(void)
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

    cout << "z:     " << z << endl;
#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z / x: " << z / x << endl;

    return 0;
}

//_D4
static int f25(void)
{
    double x;
    complex<double> z;

    if (IsConsole) cout << "x: ";
    cin >> x;

    if (!cin) {
        cerr << "xの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "z: ";
    cin >> z;

    if (!cin) {
        cerr << "zの値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

#if HAS_CPP23
    println("x:     ({},0)", x);
#else
    printf("x:     (%lf,0)n", x);
#endif
    cout << "z:     " << z << endl;
    cout << "x / z: " << x / z << endl;

    return 0;
}

//_LL
static int f26(void)
{
    double real, imag;

    if (IsConsole) cout << "実部を入力: ";
    cin >> real;

    if (!cin) {
        cerr << "実部の数値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "虚部を入力: ";
    cin >> imag;

    if (!cin) {
        cerr << "虚部の数値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    complex<double> complex{ real, imag };

    cout << "real:    " << real << endl;
    cout << "imag:    " << imag << endl;
    cout << "complex: " << complex << endl;

    return 0;
}

//_RR
static int f27(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z: " << z << endl;

    return 0;
}

//imag-real1
static int f28(void)
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
    cout << "実部: " << real(z) << endl;
    cout << "虚部: " << imag(z) << endl;

    return 0;
}

//imag2
static int f29(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x:    " << x << endl;
    cout << "imag: " << imag(x) << endl;

    return 0;
}

//real2
static int f30(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x:    " << x << endl;
    cout << "real: " << real(x) << endl;

    return 0;
}

//abs
static int f31(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << " z  = " << z << endl;
    cout << "|z| = " << abs(z) << endl;

    return 0;
}

//arg1
static int f32(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "arg(z) = " << arg(z) << endl;

    return 0;
}

//arg2
static int f33(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x      = " << x << endl;
    cout << "arg(x) = " << arg(x) << endl;

    return 0;
}

//norm1
static int f34(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "norm(z) = " << norm(z) << endl;

    return 0;
}

//norm2
static int f35(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x       = " << x << endl;
    cout << "norm(x) = " << norm(x) << endl;

    return 0;
}

//conj1
static int f36(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "conj(z) = " << conj(z) << endl;

    return 0;
}

//conj2
static int f37(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x       = " << x << endl;
    cout << "conj(x) = " << conj(x) << endl;

    return 0;
}

//proj1
static int f38(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "proj(z) = " << proj(z) << endl;

    return 0;
}

//proj2
static int f39(void)
{
    double x;

    if (IsConsole) cout << "実数を入力: ";
    cin >> x;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "x       = " << x << endl;
    cout << "proj(x) = " << proj(x) << endl;

    return 0;
}

//polar
static int f40(void)
{
    double radius, theta;

    if (IsConsole) cout << "原点からの距離: ";
    cin >> radius;

    if (!cin) {
        cerr << "radiusを読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "偏角: ";
    cin >> theta;

    if (!cin) {
        cerr << "thetaを読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "radius = " << radius << endl;
    cout << "theta  = " << theta << endl;
    cout << "polar  = " << polar(radius, theta) << endl;

    return 0;
}

//acos
static int f41(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "acos(z) = " << acos(z) << endl;

    return 0;
}

//asin
static int f42(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "asin(z) = " << asin(z) << endl;

    return 0;
}

//atan
static int f43(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "atan(z) = " << atan(z) << endl;

    return 0;
}

//acosh
static int f44(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z        = " << z << endl;
    cout << "acosh(z) = " << acosh(z) << endl;

    return 0;
}

//asinh
static int f45(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z        = " << z << endl;
    cout << "asinh(z) = " << asinh(z) << endl;

    return 0;
}

//atanh
static int f46(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z        = " << z << endl;
    cout << "atanh(z) = " << atanh(z) << endl;

    return 0;
}

//cos
static int f47(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "cos(z) = " << cos(z) << endl;

    return 0;
}

//sin
static int f48(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "sin(z) = " << sin(z) << endl;

    return 0;
}

//tan
static int f49(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "tan(z) = " << tan(z) << endl;

    return 0;
}

//cosh
static int f50(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "cosh(z) = " << cosh(z) << endl;

    return 0;
}

//sinh
static int f51(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "sinh(z) = " << sinh(z) << endl;

    return 0;
}

//tanh
static int f52(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "tanh(z) = " << tanh(z) << endl;

    return 0;
}

//exp
static int f53(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "exp(z) = " << exp(z) << endl;

    return 0;
}

//log
static int f54(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z      = " << z << endl;
    cout << "log(z) = " << log(z) << endl;

    return 0;
}

//log10
static int f55(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z        = " << z << endl;
    cout << "log10(z) = " << log10(z) << endl;

    return 0;
}

//pow1
static int f56(void)
{
    complex<double> base, power;

    if (IsConsole) cout << "底: ";
    cin >> base;

    if (!cin) {
        cerr << "底の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "指数: ";
    cin >> power;

    if (!cin) {
        cerr << "指数の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "底:   " << base << endl;
    cout << "指数: " << power << endl;
    cout << "pow:  " << pow(base, power) << endl;

    return 0;
}

//pow2
static int f57(void)
{
    complex<double> base;
    double power;

    if (IsConsole) cout << "底: ";
    cin >> base;

    if (!cin) {
        cerr << "底の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "指数: ";
    cin >> power;

    if (!cin) {
        cerr << "指数の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "底:   " << base << endl;
    cout << "指数: " << power << endl;
    cout << "pow:  " << pow(base, power) << endl;

    return 0;
}

//pow3
static int f58(void)
{
    double base;
    complex<double> power;

    if (IsConsole) cout << "底: ";
    cin >> base;

    if (!cin) {
        cerr << "底の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "指数: ";
    cin >> power;

    if (!cin) {
        cerr << "指数の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "底:   " << base << endl;
    cout << "指数: " << power << endl;
    cout << "pow:  " << pow(base, power) << endl;

    return 0;
}

//pow4
static int f59(void)
{
    complex<float> base;
    long long power;

    if (IsConsole) cout << "底: ";
    cin >> base;

    if (!cin) {
        cerr << "底の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (IsConsole) cout << "指数: ";
    cin >> power;

    if (!cin) {
        cerr << "指数の値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "底:   " << base << endl;
    cout << "指数: " << power << endl;
    cout << "pow:  " << pow(base, power) << endl;

    return 0;
}

//sqrt
static int f60(void)
{
    complex<double> z;

    if (IsConsole) cout << "複素数を入力: ";
    cin >> z;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    cout << "z       = " << z << endl;
    cout << "sqrt(z) = " << sqrt(z) << endl;

    return 0;
}

int complex__hpp__run(FUNCNAME)
{
    if (IsEqualFuncName("__i1")) return f0();
    if (IsEqualFuncName("__i2")) return f1();
    if (IsEqualFuncName("__if1")) return f2();
    if (IsEqualFuncName("__if2")) return f3();
    if (IsEqualFuncName("__il1")) return f4();
    if (IsEqualFuncName("__il2")) return f5();
    if (IsEqualFuncName("_NE1")) return f6();
    if (IsEqualFuncName("_NE2")) return f10();
    if (IsEqualFuncName("_NE3")) return f11();
    if (IsEqualFuncName("_EE1")) return f7();
    if (IsEqualFuncName("_EE2")) return f8();
    if (IsEqualFuncName("_EE3")) return f9();
    if (IsEqualFuncName("_P1")) return f12();
    if (IsEqualFuncName("_P2")) return f13();
    if (IsEqualFuncName("_P3")) return f14();
    if (IsEqualFuncName("_P4")) return f15();
    if (IsEqualFuncName("_M1")) return f16();
    if (IsEqualFuncName("_M2")) return f17();
    if (IsEqualFuncName("_M3")) return f18();
    if (IsEqualFuncName("_M4")) return f19();
    if (IsEqualFuncName("_Mu2")) return f20();
    if (IsEqualFuncName("_Mu3")) return f21();
    if (IsEqualFuncName("_Mu4")) return f22();
    if (IsEqualFuncName("_D2")) return f23();
    if (IsEqualFuncName("_D3")) return f24();
    if (IsEqualFuncName("_D4")) return f25();
    if (IsEqualFuncName("_LL")) return f26();
    if (IsEqualFuncName("_RR")) return f27();
    if (IsEqualFuncName("abs")) return f31();
    if (IsEqualFuncName("acos")) return f41();
    if (IsEqualFuncName("acosh")) return f44();
    if (IsEqualFuncName("arg1")) return f32();
    if (IsEqualFuncName("arg2")) return f33();
    if (IsEqualFuncName("asin")) return f42();
    if (IsEqualFuncName("asinh")) return f45();
    if (IsEqualFuncName("atan")) return f43();
    if (IsEqualFuncName("atanh")) return f46();
    if (IsEqualFuncName("conj1")) return f36();
    if (IsEqualFuncName("conj2")) return f37();
    if (IsEqualFuncName("cos")) return f47();
    if (IsEqualFuncName("cosh")) return f50();
    if (IsEqualFuncName("exp")) return f53();
    if (IsEqualFuncName("imag-real1")) return f28();
    if (IsEqualFuncName("imag2")) return f29();
    if (IsEqualFuncName("log")) return f54();
    if (IsEqualFuncName("log10")) return f55();
    if (IsEqualFuncName("norm1")) return f34();
    if (IsEqualFuncName("norm2")) return f35();
    if (IsEqualFuncName("polar")) return f40();
    if (IsEqualFuncName("pow1")) return f56();
    if (IsEqualFuncName("pow2")) return f57();
    if (IsEqualFuncName("pow3")) return f58();
    if (IsEqualFuncName("pow4")) return f59();
    if (IsEqualFuncName("proj1")) return f38();
    if (IsEqualFuncName("proj2")) return f39();
    if (IsEqualFuncName("real2")) return f30();
    if (IsEqualFuncName("sin")) return f48();
    if (IsEqualFuncName("sinh")) return f51();
    if (IsEqualFuncName("sqrt")) return f60();
    if (IsEqualFuncName("tan")) return f49();
    if (IsEqualFuncName("tanh")) return f52();

    return NotFound(FUNCNAMEVALUE);
}