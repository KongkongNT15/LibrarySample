#include "pch.h"

using namespace std;
using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace Kongkong;

//argv[0] アプリ名
//argv[1] フォルダー
//argv[2] 関数名
//argv[3] true: コンソール, false: アプリ内パイプ
int main(int argc, char** argv)
{
    if (argc != 4) {
        cerr << "コマンドライン引数の数が正しくありません" << endl;
        return -1;
    }

    if (IsEqualString(argv[3], "true")) IsConsole = true;
    else if (IsEqualString(argv[3], "false")) IsConsole = false;
    else {
        cerr << "コンソール設定が正しくありません" << endl;;
        return -1;
    }

    return RunSample(argv[1], argv[2]);
}
