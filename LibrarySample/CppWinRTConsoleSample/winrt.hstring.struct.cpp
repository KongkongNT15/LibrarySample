#include "pch.h"
using namespace winrt;
using namespace winrt::Windows::Foundation;

//hstring1
static int f0(void)
{
    hstring hstr;

    std::cout << "•¶Žš—ñ‚Ì’·‚³: " << hstr.size() << std::endl;

    return 0;
}

//hstring4
static int f1(void)
{
    std::locale::global(std::locale(""));

    std::wstring wstr;

    if (Kongkong::IsConsole) std::wcout << L"•¶Žš—ñ‚ð“ü—Í: ";
    std::getline(std::wcin, wstr);

    hstring hstr = hstring(wstr);

    std::wcout << L"wstr: " << wstr << std::endl;
    std::wcout << L"hstr: " << hstr.c_str() << std::endl;

    return 0;
}

//hstring5
static int f2(void)
{
    std::locale::global(std::locale(""));

    hstring hstr = L"‚ ‚¢‚¤‚¦‚¨ABC";

    std::wcout << L"hstr:   " << hstr.c_str() << std::endl;
    std::wcout << L"length: " << hstr.size() << std::endl;

    return 0;
}

//hstring6
static int f3(void)
{
    std::locale::global(std::locale(""));

    hstring hstr = hstring(L"‚ ‚¢‚¤‚¦‚¨ABC", 6);

    std::wcout << L"hstr:   " << hstr.c_str() << std::endl;
    std::wcout << L"length: " << hstr.size() << std::endl;

    return 0;
}

//hstring7
static int f4(void)
{
    std::locale::global(std::locale(""));

    hstring hstr{ L'‚Ó', L'‚Ÿ', L'I', L'H', L'‚Á', L'‚­' };

    std::wcout << L"hstr:   " << hstr.c_str() << std::endl;
    std::wcout << L"length: " << hstr.size() << std::endl;

    return 0;
}

namespace Kongkong
{
    int Run_winrt_hstring_struct(const char* functionTag)
    {
        if (IsEqualString(functionTag, "hstring1")) return f0();
        if (IsEqualString(functionTag, "hstring4")) return f1();
        if (IsEqualString(functionTag, "hstring5")) return f2();
        if (IsEqualString(functionTag, "hstring6")) return f3();
        if (IsEqualString(functionTag, "hstring7")) return f4();


        return NotFound(functionTag);
    }
}
