#include "pch.h"
#include "AllSamples.h"

namespace Kongkong
{
    WindowProcedure SampleManager::GetWindowProcedure(std::wstring_view const& rootTag, std::wstring_view const& sampleTag) noexcept
    {
        if (rootTag == L"WinUser.h") return WinUser::GetProcedure(sampleTag);

        return NotFound(rootTag);
    }
}