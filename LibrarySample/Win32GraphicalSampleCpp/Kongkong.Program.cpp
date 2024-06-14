#include "pch.h"

namespace Kongkong
{
    int Program::_cmdShow;
    HINSTANCE Program::_hInstance;
    HFONT Program::_font;
	bool Program::_isInitialized = false;
	std::vector<std::wstring_view> Program::_args;
	bool Program::_isArgsLoaded = false;

	void Program::InitializeComponent(HINSTANCE hInstance, int cmdShow)
	{
		if (_isInitialized) [[unlikely]] return;
		_isInitialized = true;

        _hInstance = hInstance;
        _cmdShow = cmdShow;
		WNDCLASS wc{};

		auto& args = Args();

		wc.lpfnWndProc = SampleManager::GetWindowProcedure(args[1], args[2]);
		wc.hInstance = hInstance;
        wc.lpszClassName = MainWindow::ClassName();

        if (!RegisterClass(&wc)) [[unlikely]] throw Exception(L"�N���X�̓o�^�Ɏ��s���܂���");

        double kakudairitus = GetDpiForSystem() / 96.0;
        //
        _font = CreateFont(
            (int)(16 * kakudairitus), (int)(6.8 * kakudairitus),					//����, ��
            0, 0,					//�p�x1, �p�x2
            FW_DONTCARE,			//����
            FALSE, FALSE, FALSE,	//�Α�, ����, �ŏ�����
            SHIFTJIS_CHARSET,		//�����Z�b�g
            OUT_DEFAULT_PRECIS,		//���x
            CLIP_DEFAULT_PRECIS,	//���x
            DEFAULT_QUALITY,		//�i��
            DEFAULT_PITCH | FF_DONTCARE, //�s�b�`�ƃt�@�~��
            L"Yu Gothic UI");

        if (_font == nullptr) [[unlikely]] throw Exception(L"�t�H���g�̍쐬�Ɏ��s���܂���");
	}

    std::vector<std::wstring_view> const& Program::Args() noexcept
    {
        if (_isArgsLoaded) return _args;
        _isArgsLoaded = true;

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