#include "pch.h"
#include "ErrorTextBlock.h"
#if __has_include("ErrorTextBlock.g.cpp")
#include "ErrorTextBlock.g.cpp"
#endif

namespace winrt::CppWinRTGraphicalSample::implementation
{
    Windows::UI::Color ErrorTextBlock::_errorDark = Windows::UI::ColorHelper::FromArgb(0xFF, 0xFF, 0xFF, 0x00);
    Windows::UI::Color ErrorTextBlock::_errorLight = Windows::UI::ColorHelper::FromArgb(0xFF, 0xFF, 0x00, 0x00);

    int32_t ErrorTextBlock::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ErrorTextBlock::MyProperty(int32_t /*value*/)
    {
        throw hresult_not_implemented();
    }

    void ErrorTextBlock::IsError(bool value)
    {

    }
}
