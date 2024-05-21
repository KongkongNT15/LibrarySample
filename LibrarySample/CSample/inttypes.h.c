#include "pch.h"

#define STR_LENGTH 100
#define WCS_LENGTH 100

static int macro(void)
{
    PutMacro(PRId8, "printfで8bit符号付き整数を出力するときの書式");
    PutMacro(PRId16, "printfで16bit符号付き整数を出力するときの書式");
    PutMacro(PRId32, "printfで32bit符号付き整数を出力するときの書式");
    PutMacro(PRId64, "printfで64bit符号付き整数を出力するときの書式");
    PutMacro(PRIdLEAST8, "printfでint_least8_tを出力するときの書式");
    PutMacro(PRIdLEAST16, "printfでint_least16_tを出力するときの書式");
    PutMacro(PRIdLEAST32, "printfでint_least32_tを出力するときの書式");
    PutMacro(PRIdLEAST64, "printfでint_least64_tを出力するときの書式");
    PutMacro(PRIdFAST8, "printfでint_fast8_tを出力するときの書式");
    PutMacro(PRIdFAST16, "printfでint_fast16_tを出力するときの書式");
    PutMacro(PRIdFAST32, "printfでint_fast32_tを出力するときの書式");
    PutMacro(PRIdFAST64, "printfでint_fast64_tを出力するときの書式");
    PutMacro(PRIdMAX, "printfでintmax_tを出力するときの書式");
    PutMacro(PRIdPTR, "printfでintptr_tを出力するときの書式");
    PutMacro(PRIi8, "printfで8bit符号付き整数を出力するときの書式");
    PutMacro(PRIi16, "printfで16bit符号付き整数を出力するときの書式");
    PutMacro(PRIi32, "printfで32bit符号付き整数を出力するときの書式");
    PutMacro(PRIi64, "printfで64bit符号付き整数を出力するときの書式");
    PutMacro(PRIiLEAST8, "printfでint_least8_tを出力するときの書式");
    PutMacro(PRIiLEAST16, "printfでint_least16_tを出力するときの書式");
    PutMacro(PRIiLEAST32, "printfでint_least32_tを出力するときの書式");
    PutMacro(PRIiLEAST64, "printfでint_least64_tを出力するときの書式");
    PutMacro(PRIiFAST8, "printfでint_fast8_tを出力するときの書式");
    PutMacro(PRIiFAST16, "printfでint_fast16_tを出力するときの書式");
    PutMacro(PRIiFAST32, "printfでint_fast32_tを出力するときの書式");
    PutMacro(PRIiFAST64, "printfでint_fast64_tを出力するときの書式");
    PutMacro(PRIiMAX, "printfでintmax_tを出力するときの書式");
    PutMacro(PRIiPTR, "printfでintptr_tを出力するときの書式");
    PutMacro(PRIo8, "printfで8bit符号付き整数を8進数で出力するときの書式");
    PutMacro(PRIo16, "printfで16bit符号付き整数を8進数で出力するときの書式");
    PutMacro(PRIo32, "printfで32bit符号付き整数を8進数で出力するときの書式");
    PutMacro(PRIo64, "printfで64bit符号付き整数を8進数で出力するときの書式");
    PutMacro(PRIoLEAST8, "printfでint_least8_tを8進数で出力するときの書式");
    PutMacro(PRIoLEAST16, "printfでint_least16_tを8進数で出力するときの書式");
    PutMacro(PRIoLEAST32, "printfでint_least32_tを8進数で出力するときの書式");
    PutMacro(PRIoLEAST64, "printfでint_least64_tを8進数で出力するときの書式");
    PutMacro(PRIoFAST8, "printfでint_fast8_tを8進数で出力するときの書式");
    PutMacro(PRIoFAST16, "printfでint_fast16_tを8進数で出力するときの書式");
    PutMacro(PRIoFAST32, "printfでint_fast32_tを8進数で出力するときの書式");
    PutMacro(PRIoFAST64, "printfでint_fast64_tを8進数で出力するときの書式");
    PutMacro(PRIoMAX, "printfでintmax_tを8進数で出力するときの書式");
    PutMacro(PRIoPTR, "printfでintptr_tを8進数で出力するときの書式");
    PutMacro(PRIu8, "printfで8bit符号なし整数を出力するときの書式");
    PutMacro(PRIu16, "printfで16bit符号なし整数を出力するときの書式");
    PutMacro(PRIu32, "printfで32bit符号なし整数を出力するときの書式");
    PutMacro(PRIu64, "printfで64bit符号なし整数を出力するときの書式");
    PutMacro(PRIuLEAST8, "printfでuint_least8_tを出力するときの書式");
    PutMacro(PRIuLEAST16, "printfでuint_least16_tを出力するときの書式");
    PutMacro(PRIuLEAST32, "printfでuint_least32_tを出力するときの書式");
    PutMacro(PRIuLEAST64, "printfでuint_least64_tを出力するときの書式");
    PutMacro(PRIuFAST8, "printfでuint_fast8_tを出力するときの書式");
    PutMacro(PRIuFAST16, "printfでuint_fast16_tを出力するときの書式");
    PutMacro(PRIuFAST32, "printfでuint_fast32_tを出力するときの書式");
    PutMacro(PRIuFAST64, "printfでuint_fast64_tを出力するときの書式");
    PutMacro(PRIuMAX, "printfでuintmax_tを出力するときの書式");
    PutMacro(PRIuPTR, "printfでuintptr_tを出力するときの書式");
    PutMacro(PRIx8, "printfで8bit整数を英子文字の16進数で出力するときの書式");
    PutMacro(PRIx16, "printfで16bit整数を英子文字の16進数で出力するときの書式");
    PutMacro(PRIx32, "printfで32bit整数を英子文字の16進数で出力するときの書式");
    PutMacro(PRIx64, "printfで64bit整数を英子文字の16進数で出力するときの書式");
    PutMacro(PRIxLEAST8, "printfでint_least8_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxLEAST16, "printfでint_least16_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxLEAST32, "printfでint_least32_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxLEAST64, "printfでint_least64_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxFAST8, "printfでint_fast8_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxFAST16, "printfでint_fast16_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxFAST32, "printfでint_fast32_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxFAST64, "printfでint_fast64_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxMAX, "printfでintmax_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIxPTR, "printfでintptr_tを英子文字の16進数で出力するときの書式");
    PutMacro(PRIX8, "printfで8bit整数を英大文字の16進数で出力するときの書式");
    PutMacro(PRIX16, "printfで16bit整数を英大文字の16進数で出力するときの書式");
    PutMacro(PRIX32, "printfで32bit整数を英大文字の16進数で出力するときの書式");
    PutMacro(PRIX64, "printfで64bit整数を英大文字の16進数で出力するときの書式");
    PutMacro(PRIXLEAST8, "printfでint_least8_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXLEAST16, "printfでint_least16_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXLEAST32, "printfでint_least32_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXLEAST64, "printfでint_least64_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXFAST8, "printfでint_fast8_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXFAST16, "printfでint_fast16_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXFAST32, "printfでint_fast32_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXFAST64, "printfでint_fast64_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXMAX, "printfでintmax_tを英大文字の16進数で出力するときの書式");
    PutMacro(PRIXPTR, "printfでintptr_tを英大文字の16進数で出力するときの書式");
    
    PutMacro(SCNd8, "scanfで8bit符号付き整数を取り込むときの書式");
    PutMacro(SCNd16, "scanfで16bit符号付き整数を取り込むときの書式");
    PutMacro(SCNd32, "scanfで32bit符号付き整数を取り込むときの書式");
    PutMacro(SCNd64, "scanfで64bit符号付き整数を取り込むときの書式");
    PutMacro(SCNdLEAST8, "scanfでint_least8_tを取り込むときの書式");
    PutMacro(SCNdLEAST16, "scanfでint_least16_tを取り込むときの書式");
    PutMacro(SCNdLEAST32, "scanfでint_least32_tを取り込むときの書式");
    PutMacro(SCNdLEAST64, "scanfでint_least64_tを取り込むときの書式");
    PutMacro(SCNdFAST8, "scanfでint_fast8_tを取り込むときの書式");
    PutMacro(SCNdFAST16, "scanfでint_fast16_tを取り込むときの書式");
    PutMacro(SCNdFAST32, "scanfでint_fast32_tを取り込むときの書式");
    PutMacro(SCNdFAST64, "scanfでint_fast64_tを取り込むときの書式");
    PutMacro(SCNdMAX, "scanfでintmax_tを取り込むときの書式");
    PutMacro(SCNdPTR, "scanfでintptr_tを取り込むときの書式");
    PutMacro(SCNi8, "scanfで8bit符号付き整数を取り込むときの書式");
    PutMacro(SCNi16, "scanfで16bit符号付き整数を取り込むときの書式");
    PutMacro(SCNi32, "scanfで32bit符号付き整数を取り込むときの書式");
    PutMacro(SCNi64, "scanfで64bit符号付き整数を取り込むときの書式");
    PutMacro(SCNiLEAST8, "scanfでint_least8_tを取り込むときの書式");
    PutMacro(SCNiLEAST16, "scanfでint_least16_tを取り込むときの書式");
    PutMacro(SCNiLEAST32, "scanfでint_least32_tを取り込むときの書式");
    PutMacro(SCNiLEAST64, "scanfでint_least64_tを取り込むときの書式");
    PutMacro(SCNiFAST8, "scanfでint_fast8_tを取り込むときの書式");
    PutMacro(SCNiFAST16, "scanfでint_fast16_tを取り込むときの書式");
    PutMacro(SCNiFAST32, "scanfでint_fast32_tを取り込むときの書式");
    PutMacro(SCNiFAST64, "scanfでint_fast64_tを取り込むときの書式");
    PutMacro(SCNiMAX, "scanfでintmax_tを取り込むときの書式");
    PutMacro(SCNiPTR, "scanfでintptr_tを取り込むときの書式");
    PutMacro(SCNo8, "scanfで8bit符号付き整数を8進数で取り込むときの書式");
    PutMacro(SCNo16, "scanfで16bit符号付き整数を8進数で取り込むときの書式");
    PutMacro(SCNo32, "scanfで32bit符号付き整数を8進数で取り込むときの書式");
    PutMacro(SCNo64, "scanfで64bit符号付き整数を8進数で取り込むときの書式");
    PutMacro(SCNoLEAST8, "scanfでint_least8_tを8進数で取り込むときの書式");
    PutMacro(SCNoLEAST16, "scanfでint_least16_tを8進数で取り込むときの書式");
    PutMacro(SCNoLEAST32, "scanfでint_least32_tを8進数で取り込むときの書式");
    PutMacro(SCNoLEAST64, "scanfでint_least64_tを8進数で取り込むときの書式");
    PutMacro(SCNoFAST8, "scanfでint_fast8_tを8進数で取り込むときの書式");
    PutMacro(SCNoFAST16, "scanfでint_fast16_tを8進数で取り込むときの書式");
    PutMacro(SCNoFAST32, "scanfでint_fast32_tを8進数で取り込むときの書式");
    PutMacro(SCNoFAST64, "scanfでint_fast64_tを8進数で取り込むときの書式");
    PutMacro(SCNoMAX, "scanfでintmax_tを8進数で取り込むときの書式");
    PutMacro(SCNoPTR, "scanfでintptr_tを8進数で取り込むときの書式");
    PutMacro(SCNu8, "scanfで8bit符号なし整数を取り込むときの書式");
    PutMacro(SCNu16, "scanfで16bit符号なし整数を取り込むときの書式");
    PutMacro(SCNu32, "scanfで32bit符号なし整数を取り込むときの書式");
    PutMacro(SCNu64, "scanfで64bit符号なし整数を取り込むときの書式");
    PutMacro(SCNuLEAST8, "scanfでuint_least8_tを取り込むときの書式");
    PutMacro(SCNuLEAST16, "scanfでuint_least16_tを取り込むときの書式");
    PutMacro(SCNuLEAST32, "scanfでuint_least32_tを取り込むときの書式");
    PutMacro(SCNuLEAST64, "scanfでuint_least64_tを取り込むときの書式");
    PutMacro(SCNuFAST8, "scanfでuint_fast8_tを取り込むときの書式");
    PutMacro(SCNuFAST16, "scanfでuint_fast16_tを取り込むときの書式");
    PutMacro(SCNuFAST32, "scanfでuint_fast32_tを取り込むときの書式");
    PutMacro(SCNuFAST64, "scanfでuint_fast64_tを取り込むときの書式");
    PutMacro(SCNuMAX, "scanfでuintmax_tを取り込むときの書式");
    PutMacro(SCNuPTR, "scanfでuintptr_tを取り込むときの書式");
    PutMacro(SCNx8, "scanfで8bit整数を英子文字の16進数で取り込むときの書式");
    PutMacro(SCNx16, "scanfで16bit整数を英子文字の16進数で取り込むときの書式");
    PutMacro(SCNx32, "scanfで32bit整数を英子文字の16進数で取り込むときの書式");
    PutMacro(SCNx64, "scanfで64bit整数を英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxLEAST8, "scanfでint_least8_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxLEAST16, "scanfでint_least16_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxLEAST32, "scanfでint_least32_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxLEAST64, "scanfでint_least64_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxFAST8, "scanfでint_fast8_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxFAST16, "scanfでint_fast16_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxFAST32, "scanfでint_fast32_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxFAST64, "scanfでint_fast64_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxMAX, "scanfでintmax_tを英子文字の16進数で取り込むときの書式");
    PutMacro(SCNxPTR, "scanfでintptr_tを英子文字の16進数で取り込むときの書式");

#if 0
    PutMacro(SCNX8, "scanfで8bit整数を英大文字の16進数で取り込むときの書式");
    PutMacro(SCNX16, "scanfで16bit整数を英大文字の16進数で取り込むときの書式");
    PutMacro(SCNX32, "scanfで32bit整数を英大文字の16進数で取り込むときの書式");
    PutMacro(SCNX64, "scanfで64bit整数を英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXLEAST8, "scanfでint_least8_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXLEAST16, "scanfでint_least16_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXLEAST32, "scanfでint_least32_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXLEAST64, "scanfでint_least64_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXFAST8, "scanfでint_fast8_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXFAST16, "scanfでint_fast16_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXFAST32, "scanfでint_fast32_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXFAST64, "scanfでint_fast64_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXMAX, "scanfでintmax_tを英大文字の16進数で取り込むときの書式");
    PutMacro(SCNXPTR, "scanfでintptr_tを英大文字の16進数で取り込むときの書式");

#endif

    return 0;
}

//imaxabs
static int f0(void)
{
    intmax_t n;

    if (IsConsole()) printf("整数を入力: ");
    scanf("%" SCNiMAX, &n);

    printf(" n  = %" PRIiMAX "\n", n);
    printf("|n| = %" PRIiMAX "\n", imaxabs(n));

    return 0;
}

//imaxdiv
static int f1(void)
{
    intmax_t m, n;
    imaxdiv_t result;

    if (IsConsole()) printf("割られる数: ");
    scanf("%" SCNiMAX, &m);

    if (IsConsole()) printf("割る数: ");
    scanf("%" SCNiMAX, &n);

    if (n == 0) {
        fputs("ちゃんとやってね\n", stderr);
        return 1;
    }

    result = imaxdiv(m, n);

    printf("%" PRIiMAX " ÷ %" PRIiMAX " = %" PRIiMAX " あまり %" PRIiMAX, m, n, result.quot, result.rem);

    return 0;
}

//strtoimax
static int f2(void)
{
    char str[STR_LENGTH];
    intmax_t n;
    int radix;
    char c;

    if (IsConsole()) printf("基数を入力: ");
    scanf("%d", &radix);

    if ((c = getchar()) != '\n' && c != ' ') {
        fputs("ちゃんとやってね\n", stderr);
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fputs("基数は2~36の範囲にしてね\n", stderr);
        return 1;
    }

    if (IsConsole()) printf("値を入力: ");
    getline(str, STR_LENGTH);

    n = strtoimax(str, NULL, radix);

    printf("n = %" PRIiMAX "\n", n);

    return 0;
}

//strtoumax
static int f3(void)
{
    char str[STR_LENGTH];
    uintmax_t n;
    int radix;
    char c;

    if (IsConsole()) printf("基数を入力: ");
    scanf("%d", &radix);

    if ((c = getchar()) != '\n' && c != ' ') {
        fputs("ちゃんとやってね\n", stderr);
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fputs("基数は2~36の範囲にしてね\n", stderr);
        return 1;
    }

    if (IsConsole()) printf("値を入力: ");
    getline(str, STR_LENGTH);

    n = strtoumax(str, NULL, radix);

    printf("n = %" PRIuMAX "\n", n);

    return 0;
}

//wcstoimax
static int f4(void)
{
    wchar_t wcs[WCS_LENGTH];
    intmax_t n;
    int radix;
    wint_t c;

    setlocale(LC_ALL, "");

    if (IsConsole()) wprintf(L"基数を入力: ");
    wscanf(L"%d", &radix);

    if ((c = getwchar()) != L'\n' && c != L' ') {
        fwprintf(stderr, L"ちゃんとやってね\n");
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fwprintf(stderr, L"基数は2~36の範囲にしてね\n");
        return 1;
    }

    if (IsConsole()) wprintf(L"値を入力: ");
    getwcsline(wcs, WCS_LENGTH);

    n = wcstoimax(wcs, NULL, radix);

    printf("n = %" PRIiMAX "\n", n);

    return 0;
}

//wcstoumax
static int f5(void)
{
    wchar_t wcs[WCS_LENGTH];
    uintmax_t n;
    int radix;
    wint_t c;

    setlocale(LC_ALL, "");

    if (IsConsole()) wprintf(L"基数を入力: ");
    wscanf(L"%d", &radix);

    if ((c = getwchar()) != L'\n' && c != L' ') {
        fwprintf(stderr, L"ちゃんとやってね\n");
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fwprintf(stderr, L"基数は2~36の範囲にしてね\n");
        return 1;
    }

    if (IsConsole()) wprintf(L"値を入力: ");
    getwcsline(wcs, WCS_LENGTH);

    n = wcstoumax(wcs, NULL, radix);

    printf("n = %" PRIuMAX "\n", n);

    return 0;
}

int inttypes__h__run(FUNCNAME)
{
    if (IsEqualFuncName("imaxabs")) return f0();
    if (IsEqualFuncName("imaxdiv")) return f1();
    if (IsEqualFuncName("strtoimax")) return f2();
    if (IsEqualFuncName("strtoumax")) return f3();
    if (IsEqualFuncName("wcstoimax")) return f4();
    if (IsEqualFuncName("wcstoumax")) return f5();

    if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

    return NotFound(FUNCNAMEVALUE);
}