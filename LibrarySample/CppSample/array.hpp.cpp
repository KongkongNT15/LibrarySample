#include "pch.h"
using namespace std;

//_EE
static int f0(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 4, 2, 3 };

    if (arr1 == arr2) cout << "2つのarrayは等しいです" << endl;
    else cout << "2つのarrayは等しくありません" << endl;

    return 0;
}

//get1
static int f1(void)
{
    array<int, 5> arr = { 1, 2, 3, 7, 11 };

    cout << get<1>(arr) << endl;
    cout << get<4>(arr) << endl;

    return 0;
}

//get2
static int f2(void)
{
    const array<int, 5> arr = { 1, 2, 3, 7, 11 };

    cout << get<1>(arr) << endl;
    cout << get<4>(arr) << endl;

    return 0;
}

//get3
static int f3(void)
{
    cout << get<1>(array<int, 5>{ 1, 2, 3, 7, 11 }) << endl;
    cout << get<4>(array<int, 5>{ 2, 7, 5, 6, 9 }) << endl;

    return 0;
}

//_NE
static int f4(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 4, 2, 3 };

    if (arr1 != arr2) cout << "2つのarrayは等しくありません" << endl;
    else cout << "2つのarrayは等しいです" << endl;

    return 0;
}

//_LER
static int f5(void)
{
#if HAS_CPP20
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 4, 2, 3 };

    strong_ordering result = arr1 <=> arr2;

    if (result == strong_ordering::equal) cout << "arr1 == arr2" << endl;
    else if (result == strong_ordering::less) cout << "arr1 < arr2" << endl;
    else cout << "arr1 > arr2" << endl;

#endif

    return 0;
}

//_L
static int f6(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { -3, 2, 3 };

    if (arr1 < arr2) cout << "arr1 < arr2" << endl;
    else cout << "arr1 >= arr2" << endl;

    return 0;
}

//_LE
static int f7(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { -3, 2, 3 };

    if (arr1 <= arr2) cout << "arr1 <= arr2" << endl;
    else cout << "arr1 > arr2" << endl;

    return 0;
}

//_R
static int f8(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { -3, 2, 3 };

    if (arr1 > arr2) cout << "arr1 > arr2" << endl;
    else cout << "arr1 <= arr2" << endl;

    return 0;
}

//_RE
static int f9(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { -3, 2, 3 };

    if (arr1 >= arr2) cout << "arr1 >= arr2" << endl;
    else cout << "arr1 < arr2" << endl;

    return 0;
}

//swap
static int f10(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 5, 6, 8 };

    swap(arr1, arr2);

    cout << "arr1:";
    for (int const& i : arr1) {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "arr2:";
    for (int const& i : arr2) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}

//array1
static int f11(void)
{
#if HAS_CPP23
    int carr[]{ 1, 3, 5, 7, 9 };

    //array<int, 5u>
    auto arr = to_array(carr);

    //ポインタはarrayに変換できない
    //int* p = carr;
    //auto arr2 = to_array(p);

    for (size_t i = 0; i < arr.size(); ++i) {
        print("arr[{}] = {}\n", i, arr[i]);
    }

#elif HAS_CPP20
    int carr[]{ 1, 3, 5, 7, 9 };

    //array<int, 5u>
    auto arr = to_array(carr);

    //ポインタはarrayに変換できない
    //int* p = carr;
    //auto arr2 = to_array(p);

    for (size_t i = 0; i < arr.size(); ++i) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }
#endif

    return 0;
}

//array2
static int f12(void)
{
#if HAS_CPP23

    //array<int, 5u>
    auto arr = to_array({ 1, 3, 5, 7, 9 });

    for (size_t i = 0; i < arr.size(); ++i) {
        print("arr[{}] = {}\n", i, arr[i]);
    }

#elif HAS_CPP20
    //array<int, 5u>
    auto arr = to_array({ 1, 3, 5, 7, 9 });

    for (size_t i = 0; i < arr.size(); ++i) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }
#endif

    return 0;
}

int array__hpp__run(FUNCNAME)
{
    if (IsEqualFuncName("_EE")) return f0();
    if (IsEqualFuncName("get1")) return f1();
    if (IsEqualFuncName("get2")) return f2();
    if (IsEqualFuncName("get3")) return f3();
    if (IsEqualFuncName("_NE")) return f4();
    if (IsEqualFuncName("_LER")) return f5();
    if (IsEqualFuncName("_L")) return f6();
    if (IsEqualFuncName("_LE")) return f7();
    if (IsEqualFuncName("_R")) return f8();
    if (IsEqualFuncName("_RE")) return f9();
    if (IsEqualFuncName("swap")) return f10();
    if (IsEqualFuncName("to_array1")) return f11();
    if (IsEqualFuncName("to_array2")) return f12();

	return NotFound(FUNCNAMEVALUE);
}