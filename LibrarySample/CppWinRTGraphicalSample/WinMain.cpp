#include "pch.h"
using namespace Kongkong;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    //�R�}���h���C�����������Ȃ��ꍇ�͑��I��
    //if (SampleManager::Args().size() < 3) return -1;
    if (!MainWindow::Create(hInstance, nShowCmd)) {

        return -1;
    }

    return SampleManager::RunSample();
}