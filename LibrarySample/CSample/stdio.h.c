#include "pch.h"

static void func(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    vprintf(format, args);

    va_end(args);
}

static int macro()
{
    puts("BUFSIZ");
    puts(Macro(BUFSIZ));
    puts("ストリームの最小バッファサイズ");

    puts("EOF");
    puts(Macro(EOF));
    puts("関数が失敗したときの戻り値");

    puts("FOPEN_MAX");
    puts(Macro(FOPEN_MAX));
    puts("一度に開けるファイルの最大数");

    puts("FILENAME_MAX");
    puts(Macro(FILENAME_MAX));
    puts("パスの最大長");

    puts("NULL");
    puts(Macro(NULL));
    puts("空ポインタ");

    puts("SEEK_SET");
    puts(Macro(SEEK_SET));
    puts("ファイルの先頭位置を指定");

    puts("SEEK_CUR");
    puts(Macro(SEEK_CUR));
    puts("ファイルの現在位置を指定");

    puts("SEEK_END");
    puts(Macro(SEEK_END));
    puts("ファイルの終端位置を指定");

    puts("stdin");
    puts(Macro(stdin));
    puts("標準入力ストリーム");

    puts("stdout");
    puts(Macro(stdout));
    puts("標準出力ストリーム");

    puts("stderr");
    puts(Macro(stderr));
    puts("標準エラー出力ストリーム");

    puts("TMP_MAX");
    puts(Macro(TMP_MAX));
    puts("tmpnam() が重複せずに生成できるファイル名の最大個数");

    puts("_IOFBF");
    puts(Macro(_IOFBF));
    puts("バッファがいっぱいになったときにフラッシュすることを指定");

    puts("_IONBF");
    puts(Macro(_IONBF));
    puts("バッファリングしないことを指定");

    puts("_IOLBF");
    puts(Macro(_IOLBF));
    puts("改行文字が挿入されたときにフラッシュすることを指定");

    return 0;
}

//feof
static int f0(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを開く: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("ファイルを開けませんでした\n", stderr);
        return 1;
    }

    printf("feof() = %s\n", feof(fp) == 1 ? "true" : "false");

    //ファイルの終端まで空回し
    while (fgetc(fp) != EOF);

    printf("feof() = %s\n", feof(fp) == 1 ? "true" : "false");

    fclose(fp);

    return 0;
}

//fflush
static int f1(void)
{
    char buf[4096] = { 0 };
    int i;

    setvbuf(stdout, buf, _IOFBF, 4096);

    for (i = 0; i < 5; ++i) {
        printf("%d ", i);
        fflush(stdout);
#ifdef __MSVC__
        Sleep(500);
#endif // __MSVC__

#ifdef __UNIX__
        usleep(500000);
#endif
    }
    putchar('\n');

    fflush(stdout);

    for (i = 0; i < 5; ++i) {
        printf("%d ", i);
#ifdef __MSVC__
        Sleep(500);
#endif // __MSVC__

#ifdef __UNIX__
        usleep(500000);
#endif
    }
    putchar('\n');
    fflush(stdout);

    return 0;
}

//fgetc
static int f2(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを開く: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("ファイルを開けませんでした\n", stderr);
        return 1;
    }

    int c;

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);

    return 0;
}

//fgetpos, fseek
static int f3(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを開く: ");
    getline(path, 1024);

    fpos_t pos1, pos2;
    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("ファイルを開けませんでした\n", stderr);
        return 1;
    }

    fgetpos(fp, &pos1);
    fseek(fp, 0, SEEK_END);
    fgetpos(fp, &pos2);

    printf("pos1: %lld\n", pos1);
    printf("pos2: %lld\n", pos2);
    printf("FileSize: %lld\n", pos2 - pos1);

    fclose(fp);

    return 0;
}

//fgets
static int f4(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを開く: ");
    getline(path, 1024);

    char str[1024];
    FILE* fp = fopen(path, "r");

    if (fp == NULL) {
        fputs("ファイルを開けませんでした\n", stderr);
        return 1;
    }

    for (int row = 1; (fgets(str, 1024, fp)) != NULL; ++row) {
        printf("%4d: %s", row, str);
    }

    fclose(fp);

    return 0;
}

//fprintf
static int f5(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを作成: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "w");

    if(fp == NULL) {
        fputs("ファイルを作成できませんでした\n", stderr);
        return 1;
    }

    char str[100];

    printf("ファイルに書き込む文字列を入力: ");
    scanf("%99s", str);

    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d : %s\n", i + 1, str);
    }

    fclose(fp);
    puts("ファイルを保存しました");

    return 0;
}

//fputs
static int f6(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを作成: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("ファイルを作成できませんでした\n", stderr);
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fputs("よう　桐生ちゃん！\n", fp);
    }

    fclose(fp);
    puts("ファイルを保存しました");

    return 0;
}

//getc
static int f7(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを開く: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("ファイルを開けませんでした\n", stderr);
        return 1;
    }

    int c;

    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);

    return 0;
}

//getchar
static int f8(void)
{
    int c;
    int count;

    if (IsConsole()) printf("文字列を入力: ");

    for (count = 0; (c = getchar()) != '\n'; ++count) {
        putchar(c);
    }
    putchar('\n');

    printf("文字数 = %d\n", count);

    return 0;
}

//perror
static int f9(void)
{
    for (errno = 0; errno < 141; ++errno) {
        printf("No.%d: ", errno);
        perror(NULL);
    }

    return 0;
}

//printf
static int f10(void)
{
    char str[] = "Windows 11 2022 Update";
    int n = 38;
    double x = 2.6;

    printf("%s\n", str);
    printf("共通テスト英語リスニング: %d/%d\n", n, 100);
    printf("%.2lf GHz\n", x);
    printf("printf: %p\n", printf);

    return 0;
}

//fputc
static int f11(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを作成: ");
    getline(path, 1024);

    char c = 'A';
    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("ファイルを作成できませんでした\n", stderr);
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        fputc(c++, fp);
    }

    fclose(fp);
    puts("ファイルを保存しました");

    return 0;
}

//putc
static int f12(void)
{
    char path[1024];

    if (IsConsole()) printf("ファイルを作成: ");
    getline(path, 1024);

    char c = 'A';
    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("ファイルを作成できませんでした\n", stderr);
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        putc(c++, fp);
    }

    fclose(fp);
    puts("ファイルを保存しました");

    return 0;
}

//putchar
static int f13(void)
{
    putchar('A');
    putchar('\n');

    for (int i = 0; i < 10; i++) {
        putchar('n');
    }
    putchar('\n');

    return 0;
}

//puts
static int f14(void)
{
    char str[] = "桐生ちゃん！";

    puts("よう");
    puts(str);

    return 0;
}

//remove
static int f15(void)
{
    char name[1024];

    if (IsConsole()) printf("削除するファイル名を入力: ");
    getline(name, 1024);

    if (remove(name) == EOF) {
        fputs("操作に失敗しました\n", stderr);
        return EOF;
    }
    puts("ファイルを削除しました");

    return 0;
}

//scanf
static int f16(void)
{
    int n;
    int c;

    if (IsConsole()) printf("整数を入力: ");
    scanf("%d", &n);

    printf("n = %d\n", n);

    printf("stdinに残った文字: \"");
    while ((c = getchar()) != '\n' && c != EOF) {
        putchar(c);
    }
    puts("\"");

    return 0;
}

//snprintf
static int f17(void)
{
    size_t ret;
    size_t length;

    ret = snprintf(NULL, 0, "友達が%d月%d日に名駅のホテルに泊まるらしい", 5, 4);

    printf("文字数: %zu\n", ret);

    length = ret + 1;

    char* str = malloc(length * sizeof(char));

    if (str == NULL) {
        fputs("メモリの確保に失敗しました", stderr);
        return 1;
    }

    snprintf(str, length, "友達が%d月%d日に名駅のホテルに泊まるらしい", 5, 4);

    printf("str: %s\n", str);

    free(str);

    return 0;
}

//sprintf
static int f18(void)
{
    char str[100];

    sprintf(str, "今日の気温は%d℃です", 21);

    printf("str: %s\n", str);

    return 0;
}

//sscanf
static int f19(void)
{
    char str1[] = "25";
    char str2[] = "11.2";
    char str3[] = "今日の日付: 8月27日";
    int a;
    double b;
    int c;
    int d;

    sscanf(str1, "%d", &a);
    sscanf(str2, "%lf", &b);
    sscanf(str3, "今日の日付: %d月%d日", &c, &d);

    printf("a: %d\n", a);
    printf("b: %lf\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);

    return 0;
}

//tmpnam
static int f20(void)
{
    char path[FILENAME_MAX];

    for (int i = 0; i < 100; i++) {
        if (tmpnam(path) == NULL) {
            fputs("ファイル名を作成できませんでした\n", stderr);
            return 1;
        }

        puts(path);
    }

    return 0;
}

//ungetc
static int f21(void)
{
    int c;

    while (1) {
        printf("数字を入力: ");

        while ((c = getchar()) != '\n') {
            if (isdigit(c) == 0) {
                ungetc(c, stdin);

                putchar('\n');
                printf("stdinに残った文字: \"");
                while ((c = getchar()) != '\n') {
                    putchar(c);
                }
                putchar('\"');

                break;
            }
            putchar(c);
        }
        putchar('\n');
    }

    return 0;
}

//vprintf
static int f22(void)
{
    char str[] = "Windows 11 2022 Update";
    int n = 38;
    double x = 2.6;

    func("%s\n", str);
    func("共通テスト英語リスニング: %d/%d\n", n, 100);
    func("%.2lf GHz\n", x);
    func("vprintf: %p\n", vprintf);

    return 0;
}

int stdio__h__run(FUNCNAME)
{
    if (IsEqualFuncName("feof")) return f0();
    if (IsEqualFuncName("fflush")) return f1();
    if (IsEqualFuncName("fgetc")) return f2();
    if (IsEqualFuncName("fgetpos")) return f3();
    if (IsEqualFuncName("fgets")) return f4();
    if (IsEqualFuncName("fprintf")) return f5();
    if (IsEqualFuncName("fputc")) return f11();
    if (IsEqualFuncName("fputs")) return f6();
    if (IsEqualFuncName("getc")) return f7();
    if (IsEqualFuncName("getchar")) return f8();
    if (IsEqualFuncName("perror")) return f9();
    if (IsEqualFuncName("printf")) return f10();
    if (IsEqualFuncName("putc")) return f12();
    if (IsEqualFuncName("putchar")) return f13();
    if (IsEqualFuncName("puts")) return f14();
    if (IsEqualFuncName("remove")) return f15();
    if (IsEqualFuncName("scanf")) return f16();
    if (IsEqualFuncName("snprintf")) return f17();
    if (IsEqualFuncName("sprintf")) return f18();
    if (IsEqualFuncName("sscanf")) return f19();
    if (IsEqualFuncName("tmpnam")) return f20();
    if (IsEqualFuncName("ungetc")) return f21();
    if (IsEqualFuncName("vprintf")) return f22();

    if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

    return NotFound(FUNCNAMEVALUE);
}