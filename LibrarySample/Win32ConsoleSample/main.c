#include "pch.h"

//argv[0] アプリ名
//argv[1] フォルダー
//argv[2] 関数名
//argv[3] true: コンソール, false: アプリ内パイプ
int main(int argc, char** argv)
{
    if (argc != 4) {
        fputs("コマンドライン引数の数が正しくありません\n", stderr);
        return -1;
    }

    if (IsEqualStringA(argv[3], "true")) SetIsConsole(1);
    else if (IsEqualStringA(argv[3], "false")) SetIsConsole(0);
    else {
        fputs("コンソール設定が正しくありません\n", stderr);
        return -1;
    }

    return RunSample(argv[1], argv[2]);
}