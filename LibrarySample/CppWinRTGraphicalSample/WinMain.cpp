#include "pch.h"
using namespace Kongkong;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    //コマンドラインが正しくない場合は即終了
    //if (SampleManager::Args().size() < 3) return -1;
    if (!MainWindow::Create(hInstance, nShowCmd)) {

        return -1;
    }

    return SampleManager::RunSample();
}