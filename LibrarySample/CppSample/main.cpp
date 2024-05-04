#include "pch.h"
using namespace std;

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

    if (argv[3] == "true"s) IsConsole = true;
    else if (argv[3] == "false"s) IsConsole = false;
    else {
        cerr << "コンソール設定が正しくありません" << endl;;
        return -1;
    }

    return RunSample(argv[1], argv[2]);
}