#include "pch.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Data::Html;

static int f0(void)
{
    std::locale::global(std::locale(""));

    std::wstring filePath;
    std::wstring html;

    if(Kongkong::IsConsole) std::wcout << L"ファイルのパスを入力: ";
    std::getline(std::wcin, filePath);

    std::wifstream wifs{ filePath };

    if (!wifs) {
        std::wcerr << L"ファイルを開けませんでした" << std::endl;
        std::wcerr << L"ふぁ！？っく" << std::endl;

        return 1;
    }

    std::wstring tmp;

    while (std::getline(wifs, tmp)) {
        html += tmp;
        html += L'\n';
    }

    std::wcout << HtmlUtilities::ConvertToText(html).c_str() << std::endl;

    return 0;
}

namespace Kongkong
{
    int Run_winrt_Windows_Data_Html_HtmlUtilities_class(const char* tag)
    {
        if (IsEqualString(tag, "ConvertToText")) return f0();

        return NotFound(tag);
    }
}