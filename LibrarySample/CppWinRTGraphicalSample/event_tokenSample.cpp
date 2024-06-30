#include "pch.h"
#include "event_tokenSample.h"
#include "event_tokenSample.event_tokenPage.h"

namespace Kongkong::event_tokenSample
{
	int RunSamplePage(std::wstring_view const& tag)
	{
		if (tag == L"event_token") return MainWindow::ShowWindow<event_tokenPage>();

		return SampleManager::RunNotFoundPage();
	}
}