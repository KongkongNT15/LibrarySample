#include "pch.h"
using namespace std;

//_EE
static int f0(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 4, 2, 3 };

    if (arr1 == arr2) cout << "2‚Â‚Ìarray‚Í“™‚µ‚¢‚Å‚·" << endl;
    else cout << "2‚Â‚Ìarray‚Í“™‚µ‚­‚ ‚è‚Ü‚¹‚ñ" << endl;

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

int array__hpp__run(FUNCNAME)
{
    if (IsEqualFuncName("_EE")) return f0();
    if (IsEqualFuncName("get1")) return f1();
    if (IsEqualFuncName("get2")) return f2();
    if (IsEqualFuncName("get3")) return f3();

	return NotFound(FUNCNAMEVALUE);
}