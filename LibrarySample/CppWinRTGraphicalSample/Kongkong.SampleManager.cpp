#include "pch.h"
#include "AllSamples.h"

namespace Kongkong
{
	bool SampleManager::_isLoaded = false;

	::std::vector<std::wstring_view> SampleManager::_args;

    int SampleManager::RunSample()
    {
        std::wstring_view rootTag = Args()[1];
        std::wstring_view functionTag = Args()[2];

        if (rootTag == L"winrt.event_token.struct") return event_tokenSample::RunSamplePage(functionTag);
        if (rootTag == L"winrt.Windows.System.Display.DisplayRequest.class") return Windows::System::Display::DisplayRequestSample::RunSamplePage(functionTag);
        if (rootTag == L"winrt.Windows.System.Inventory.InstalledDesktopApp.class") return Windows::System::Inventory::InstalledDesktopAppSample::RunSamplePage(functionTag);
        if (rootTag == L"winrt.Windows.System.Power.PowerManager.class") return Windows::System::Power::PowerManagerSample::RunSamplePage(functionTag);
        if (rootTag == L"winrt.Windows.UI.ColorHelper.class") return Windows::UI::ColorHelperSample::RunSamplePage(functionTag);
        if (rootTag == L"winrt.Windows.UI.Colors.class") return Windows::UI::ColorsSample::RunSamplePage(functionTag);

        return RunNotFoundPage();
    }

    int SampleManager::RunNotFoundPage()
    {
        return MainWindow::ShowWindow<NotFoundPage>();
    }

    ::std::vector<std::wstring_view> const& SampleManager::Args() noexcept
    {
        if (_isLoaded) return _args;
        _isLoaded = true;

        wchar_t* lcommandline = GetCommandLine();

        std::wstring_view wsv = lcommandline;

        for (size_t i = 0; i < wsv.size(); ++i) {
            bool isAdded = false;
            if (wsv[i] != L' ') {
                if (wsv[i] == L'"') {
                    for (size_t j = i + 1; j < wsv.size(); ++j) {
                        if (wsv[j] == L'\"') {
                            _args.push_back(wsv.substr(i + 1, j - i - 1));
                            i = j;
                            break;
                        }
                    }
                }
                else {
                    for (size_t j = i; j < wsv.size(); ++j) {
                        if (wsv[j] == L' ' || wsv[j] == L'\0') {
                            _args.push_back(wsv.substr(i, j - i));
                            i = j - 1;
                            isAdded = true;
                            break;
                        }
                    }
                    if (!isAdded) {
                        _args.push_back(wsv.substr(i, wsv.size() - i));
                        break;
                    }

                }
            }
        }

        return _args;
    }
}