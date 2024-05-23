#pragma once

#include "ErrorTextBlock.g.h"

namespace winrt::CppWinRTGraphicalSample::implementation
{
    struct ErrorTextBlock : ErrorTextBlockT<ErrorTextBlock>
    {
        ErrorTextBlock() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);

        Windows::UI::Xaml::Controls::TextBlock textBlock;

        hstring Text() const { return textBlock.Text(); }
        void Text(hstring const& value) const { textBlock.Text(value); }

        bool IsError() const noexcept { return _isError; }
        void IsError(bool value);

        bool _isError = false;
    };
}

namespace winrt::CppWinRTGraphicalSample::factory_implementation
{
    struct ErrorTextBlock : ErrorTextBlockT<ErrorTextBlock, implementation::ErrorTextBlock>
    {
    };
}
