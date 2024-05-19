#include "pch.h"
using namespace std;

#if HAS_CPP17

//from_chars1
static int f0(void)
{
    int radix = -1;

    if(IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    char n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << static_cast<int>(n) << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars2
static int f1(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    signed char n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << static_cast<int>(n) << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars3
static int f2(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    unsigned char n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << static_cast<int>(n) << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars4
static int f3(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    short n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars5
static int f4(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    unsigned short n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars6
static int f5(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    int n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars7
static int f6(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    unsigned n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars8
static int f7(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    long n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars9
static int f8(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    unsigned long n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars10
static int f9(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    long long n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars11
static int f10(void)
{
    int radix = -1;

    if (IsConsole) cout << "基数を入力: ";
    cin >> radix;

    if (cin.fail() || radix < 2 || 36 < radix) {
        cerr << "入力が不正です" << endl;
        return 1;
    }

    //改行を捨てる
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char str[100]{};

    if (IsConsole) cout << "値を入力: ";
    cin.getline(str, 100);

    if (cin.fail()) {
        cerr << "文字配列がオーバーフローしました" << endl;
        cerr << "入力は99文字以内にしてください" << endl;

        return 1;
    }

    unsigned long long n;

    from_chars_result res = from_chars(str, str + sizeof(str), n, radix);

    //変換成功
    if (res.ec == errc{}) {
        cout << "n = " << n << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(res.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars12
static int f11(void)
{
    constexpr size_t length = 100;
    float x;
    int enumValue;
    chars_format format;
    char str[length];
    from_chars_result result;

    if (IsConsole) {
        cout << "表記の選択:" << endl;
        cout << "0... 指数表記" << endl;
        cout << "1... 10進数表記" << endl;
        cout << "2... 16進数表記" << endl;
        cout << "3... 自動" << endl;
        cout << endl;

        cout << "表記を指定: ";
    }

    cin >> enumValue;

    if (cin.fail()) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    switch (enumValue) {
    case 0: format = chars_format::scientific; break;
    case 1: format = chars_format::fixed; break;
    case 2: format = chars_format::hex; break;
    case 3: format = chars_format::general; break;

    default:
        cerr << "範囲外の値が指定されました" << endl;
        return 1;
    }

    if (IsConsole) cout << "値を入力: ";

    //改行文字を読み飛ばす
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(str, length);

    if (cin.fail()) {
        cerr << "文字列がオーバーフローしました" << endl;
        cerr << "入力は" << (length - 1) << "文字以内にしてください" << endl;
        return 1;
    }

    result = from_chars(str, str + length, x, format);

    //変換成功
    if (result.ec == errc{}) {
        cout << "x = " << x << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars13
static int f12(void)
{
    constexpr size_t length = 100;
    double x;
    int enumValue;
    chars_format format;
    char str[length];
    from_chars_result result;

    if (IsConsole) {
        cout << "表記の選択:" << endl;
        cout << "0... 指数表記" << endl;
        cout << "1... 10進数表記" << endl;
        cout << "2... 16進数表記" << endl;
        cout << "3... 自動" << endl;
        cout << endl;

        cout << "表記を指定: ";
    }

    cin >> enumValue;

    if (cin.fail()) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    switch (enumValue) {
    case 0: format = chars_format::scientific; break;
    case 1: format = chars_format::fixed; break;
    case 2: format = chars_format::hex; break;
    case 3: format = chars_format::general; break;

    default:
        cerr << "範囲外の値が指定されました" << endl;
        return 1;
    }

    if (IsConsole) cout << "値を入力: ";

    //改行文字を読み飛ばす
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(str, length);

    if (cin.fail()) {
        cerr << "文字列がオーバーフローしました" << endl;
        cerr << "入力は" << (length - 1) << "文字以内にしてください" << endl;
        return 1;
    }

    result = from_chars(str, str + length, x, format);

    //変換成功
    if (result.ec == errc{}) {
        cout << "x = " << x << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

        return 1;
    }

    return 0;
}

//from_chars14
static int f13(void)
{
    constexpr size_t length = 100;
    long double x;
    int enumValue;
    chars_format format;
    char str[length];
    from_chars_result result;

    if (IsConsole) {
        cout << "表記の選択:" << endl;
        cout << "0... 指数表記" << endl;
        cout << "1... 10進数表記" << endl;
        cout << "2... 16進数表記" << endl;
        cout << "3... 自動" << endl;
        cout << endl;

        cout << "表記を指定: ";
    }

    cin >> enumValue;

    if (cin.fail()) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    switch (enumValue) {
    case 0: format = chars_format::scientific; break;
    case 1: format = chars_format::fixed; break;
    case 2: format = chars_format::hex; break;
    case 3: format = chars_format::general; break;

    default:
        cerr << "範囲外の値が指定されました" << endl;
        return 1;
    }

    if (IsConsole) cout << "値を入力: ";

    //改行文字を読み飛ばす
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(str, length);

    if (cin.fail()) {
        cerr << "文字列がオーバーフローしました" << endl;
        cerr << "入力は" << (length - 1) << "文字以内にしてください" << endl;
        return 1;
    }

    result = from_chars(str, str + length, x, format);

    //変換成功
    if (result.ec == errc{}) {
        cout << "x = " << x << endl;
    }
    else {
        cerr << "変換に失敗しました" << endl;
        cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

        return 1;
    }

    return 0;
}
namespace
{
    //to_chars
    //整数
    template <class TInt>
    int f_to_chars1(void)
    {
        constexpr size_t length = 100;
        char str[length];
        int radix;
        TInt n;
        to_chars_result result;

        if (IsConsole) cout << "基数を入力: ";
        cin >> radix;

        if (cin.fail()) {
            cerr << "基数の値を読み取れませんでした" << endl;
            return 1;
        }

        if (radix < 2 || 36 < radix) {
            cerr << "基数の値が無効です" << endl;
            return 1;
        }

        if (IsConsole) cout << "値を入力: ";
        cin >> n;

        if (cin.fail()) {
            cerr << "値を読み取れませんでした" << endl;
            return 1;
        }

        result = to_chars(str, str + length - 1, n, radix);

        //変換成功
        if (result.ec == errc{}) {
            //NULL文字を追加
            *result.ptr = '\0';

            cout << "n = " << str << endl;
        }
        else {
            cerr << "変換に失敗しました" << endl;
            cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

            return 1;
        }

        return 0;
    }

    //to_chars
    //浮動小数点1
    template <class TFloat>
    int f_to_chars2(void)
    {
        constexpr size_t length = 100;
        char str[length];
        TFloat x;
        to_chars_result result;

        if (IsConsole) cout << "値を入力: ";
        cin >> x;

        if (cin.fail()) {
            cerr << "値を読み取れませんでした" << endl;
            return 1;
        }

        result = to_chars(str, str + length - 1, x);

        //変換失敗
        if (result.ec != errc{}) {
            cerr << "変換に失敗しました" << endl;
            cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

            return 1;
        }

        //NULL文字を追加
        *result.ptr = '\0';

        cout << "x = " << str << endl;

        return 0;
    }

    //to_chars
    //浮動小数点2
    template <class TFloat>
    int f_to_chars3(void)
    {
        constexpr size_t length = 100;
        char str[length];
        float x;
        int enumValue;
        chars_format format;
        to_chars_result result;

        if (IsConsole) {
            cout << "表記の選択:" << endl;
            cout << "0... 指数表記" << endl;
            cout << "1... 10進数表記" << endl;
            cout << "2... 16進数表記" << endl;
            cout << "3... 自動" << endl;
            cout << endl;

            cout << "表記を指定: ";
        }

        cin >> enumValue;

        if (cin.fail()) {
            cerr << "番号を読み取れませんでした" << endl;
            return 1;
        }

        switch (enumValue) {
        case 0: format = chars_format::scientific; break;
        case 1: format = chars_format::fixed; break;
        case 2: format = chars_format::hex; break;
        case 3: format = chars_format::general; break;

        default:
            cerr << "範囲外の値が指定されました" << endl;
            return 1;
        }

        if (IsConsole) cout << "値を入力: ";
        cin >> x;

        if (cin.fail()) {
            cerr << "値を読み取れませんでした" << endl;
            return 1;
        }

        result = to_chars(str, str + length - 1, x, format);

        //変換失敗
        if (result.ec != errc{}) {
            cerr << "変換に失敗しました" << endl;
            cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

            return 1;
        }

        //NULL文字を追加
        *result.ptr = '\0';

        cout << "x = " << str << endl;

        return 0;
    }

    //to_chars
    //浮動小数点3
    template <class TFloat>
    int f_to_chars4(void)
    {
        constexpr size_t length = 100;
        char str[length];
        TFloat x;
        int enumValue;
        chars_format format;
        int precision;
        to_chars_result result;

        if (IsConsole) {
            cout << "表記の選択:" << endl;
            cout << "0... 指数表記" << endl;
            cout << "1... 10進数表記" << endl;
            cout << "2... 16進数表記" << endl;
            cout << "3... 自動" << endl;
            cout << endl;

            cout << "表記を指定: ";
        }

        cin >> enumValue;

        if (cin.fail()) {
            cerr << "番号を読み取れませんでした" << endl;
            return 1;
        }

        switch (enumValue) {
        case 0: format = chars_format::scientific; break;
        case 1: format = chars_format::fixed; break;
        case 2: format = chars_format::hex; break;
        case 3: format = chars_format::general; break;

        default:
            cerr << "範囲外の値が指定されました" << endl;
            return 1;
        }

        if (IsConsole) cout << "有効桁数を入力: ";
        cin >> precision;

        if (cin.fail()) {
            cerr << "有効桁数を読み取れませんでした" << endl;
            return 1;
        }

        if (IsConsole) cout << "値を入力: ";
        cin >> x;

        if (cin.fail()) {
            cerr << "値を読み取れませんでした" << endl;
            return 1;
        }

        result = to_chars(str, str + length - 1, x, format, precision);

        //変換失敗
        if (result.ec != errc{}) {
            cerr << "変換に失敗しました" << endl;
            cerr << "エラーコード: " << static_cast<int>(result.ec) << endl;

            return 1;
        }

        //NULL文字を追加
        *result.ptr = '\0';

        cout << "x = " << str << endl;

        return 0;
    }
}


//to_chars4
static int f14(void)
{
    return f_to_chars1<short>();
}

//to_chars5
static int f15(void)
{
    return f_to_chars1<unsigned short>();
}

//to_chars6
static int f16(void)
{
    return f_to_chars1<int>();
}

//to_chars7
static int f17(void)
{
    return f_to_chars1<unsigned>();
}

//to_chars8
static int f18(void)
{
    return f_to_chars1<long>();
}

//to_chars9
static int f19(void)
{
    return f_to_chars1<unsigned long>();
}

//to_chars10
static int f20(void)
{
    return f_to_chars1<long long>();
}

//to_chars11
static int f21(void)
{
    return f_to_chars1<unsigned long long>();
}

//to_chars12
static int f22(void)
{
    return f_to_chars2<float>();
}

//to_chars13
static int f23(void)
{
    return f_to_chars2<double>();
}

//to_chars14
static int f24(void)
{
    return f_to_chars2<long double>();
}

//to_chars15
static int f25(void)
{
    return f_to_chars3<float>();
}

//to_chars16
static int f26(void)
{
    return f_to_chars3<double>();
}

//to_chars17
static int f27(void)
{
    return f_to_chars3<long double>();
}

//to_chars18
static int f28(void)
{
    return f_to_chars4<float>();
}

//to_chars19
static int f29(void)
{
    return f_to_chars4<double>();
}

//to_chars20
static int f30(void)
{
    return f_to_chars4<long double>();
}

#endif //HAS_CPP17

int charconv__hpp__run(FUNCNAME)
{
#if HAS_CPP17
    if (IsEqualFuncName("from_chars1")) return f0();
    if (IsEqualFuncName("from_chars2")) return f1();
    if (IsEqualFuncName("from_chars3")) return f2();
    if (IsEqualFuncName("from_chars4")) return f3();
    if (IsEqualFuncName("from_chars5")) return f4();
    if (IsEqualFuncName("from_chars6")) return f5();
    if (IsEqualFuncName("from_chars7")) return f6();
    if (IsEqualFuncName("from_chars8")) return f7();
    if (IsEqualFuncName("from_chars9")) return f8();
    if (IsEqualFuncName("from_chars10")) return f9();
    if (IsEqualFuncName("from_chars11")) return f10();
    if (IsEqualFuncName("from_chars12")) return f11();
    if (IsEqualFuncName("from_chars13")) return f12();
    if (IsEqualFuncName("from_chars14")) return f13();
    if (IsEqualFuncName("to_chars4")) return f14();
    if (IsEqualFuncName("to_chars5")) return f15();
    if (IsEqualFuncName("to_chars6")) return f16();
    if (IsEqualFuncName("to_chars7")) return f17();
    if (IsEqualFuncName("to_chars8")) return f18();
    if (IsEqualFuncName("to_chars9")) return f19();
    if (IsEqualFuncName("to_chars10")) return f20();
    if (IsEqualFuncName("to_chars11")) return f21();
    if (IsEqualFuncName("to_chars12")) return f22();
    if (IsEqualFuncName("to_chars13")) return f23();
    if (IsEqualFuncName("to_chars14")) return f24();
    if (IsEqualFuncName("to_chars15")) return f25();
    if (IsEqualFuncName("to_chars16")) return f26();
    if (IsEqualFuncName("to_chars17")) return f27();
    if (IsEqualFuncName("to_chars18")) return f28();
    if (IsEqualFuncName("to_chars19")) return f29();
    if (IsEqualFuncName("to_chars20")) return f30();

#endif //HAS_CPP17

    return NotFound(FUNCNAMEVALUE);
}