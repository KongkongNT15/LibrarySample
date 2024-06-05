#pragma once

#include <Windows.h>
#include <dwmapi.h>

#include <unknwn.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <winrt/base.h>
#include <hstring.h>
#include <windows.UI.xaml.hosting.desktopwindowxamlsource.h>    //DesktopWindowXamlSource

//名称かぶり対策（前半）ここから
#pragma push_macro("GetCurrentTime")
#pragma push_macro("TRY")
#undef GetCurrentTime
#undef TRY
//名称かぶり対策（前半）ここまで

#include <restrictederrorinfo.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.Devices.Enumeration.h>
#include <winrt/Windows.Devices.Power.h>
#include <winrt/Windows.Foundation.h>   //IAsyncAction
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Globalization.h>
#include <winrt/Windows.Globalization.Fonts.h>
#include <winrt/Windows.Globalization.NumberFormatting.h>
#include <winrt/Windows.Graphics.Display.h>
#include <winrt/Windows.Security.Cryptography.h>    //CryptographicBuffer
#include <winrt/Windows.Storage.Pickers.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.System.Display.h>
#include <winrt/Windows.System.Inventory.h>
#include <winrt/Windows.System.Power.h>
#include <winrt/Windows.System.Threading.Core.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>  //Click
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Documents.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>   //XamlReader
#include <winrt/Windows.UI.Xaml.Media.h>    //SolidColorBrush
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.UI.Xaml.Navigation.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>

#include <winrt/CppWinRTGraphicalSample.h>

#ifdef _AMD64_
#define __X64__
#elif defined(_ARM64_)
#define __ARM64__
#else
#define __X86__
#endif

//名称かぶり対策（後半）ここから
#pragma pop_macro("TRY")
#pragma pop_macro("GetCurrentTime")
//名称かぶり対策（後半）ここまで

namespace Kongkong
{
	enum struct BlockPanelType {
		Normal,
		HasChildPanel,
		MinTitle,
	};

	struct SamplePage {

		static winrt::Windows::UI::Xaml::Controls::StackPanel CreateBlockPanel(winrt::hstring const& title, BlockPanelType type = BlockPanelType::Normal);
		static winrt::Windows::UI::Xaml::Controls::StackPanel CreateOuterPanel();

		static void SetAsCenter(winrt::Windows::UI::Xaml::FrameworkElement const& frameworkElement);

		::winrt::Windows::UI::Xaml::Controls::ScrollViewer PageViewer() const { return _content; }
	protected:

		SamplePage();

		::winrt::Windows::Foundation::IInspectable Content() const { return _content.Content(); }
		void Content(::winrt::Windows::Foundation::IInspectable const& value) { _content.Content(value); }

	private:
		::winrt::Windows::UI::Xaml::Controls::ScrollViewer _content;

		

		void ActualThemeChanged(winrt::Windows::UI::Xaml::FrameworkElement const& sender, winrt::Windows::Foundation::IInspectable const& args);
		void Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& args);

		void ChangeTheme();
	};

	struct NotFoundPage : SamplePage {
		NotFoundPage();
	};

	struct MainWindow {
		MainWindow() = delete;
		MainWindow(MainWindow const&) = delete;
		MainWindow(MainWindow&&) = delete;

		MainWindow& operator=(MainWindow const&) = delete;
		MainWindow& operator=(MainWindow&&) = delete;

		static bool Create(HINSTANCE hInstance, int nShowCmd);

		static constexpr HWND Handle() noexcept { return _handle; }

		template <class TPage>
		static int ShowWindow()
		{
			TPage page{};

			_desktopSource.Content(page.PageViewer());

			MessageLoop();

			return 0;
		}

		static int ShowNotFoundWindow();

	private:
		static HWND _handle;
		static HWND _contentHandle;
		static bool _isCreated;
		static int _nShowCmd;
		static winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource _desktopSource;

		//ウインドウプロシージャ
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT messageCode, WPARAM wParam, LPARAM lParam);
		

		static void MessageLoop();
	};

	struct SampleManager {
		SampleManager() = delete;
		SampleManager(SampleManager const&) = delete;
		SampleManager(SampleManager&&) = delete;

		SampleManager& operator=(SampleManager const&) = delete;
		SampleManager& operator=(SampleManager&&) = delete;

		static ::std::vector<std::wstring_view> const& Args() noexcept;

		static int RunSample();
		static int RunNotFoundPage();

	private:
		static bool _isLoaded;
		static ::std::vector<std::wstring_view> _args;


	};
}