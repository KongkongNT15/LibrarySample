#include "pch.h"

#define STR_LENGTH 100
#define WCS_LENGTH 100

static int macro(void)
{
    PutMacro(PRId8, "printf��8bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRId16, "printf��16bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRId32, "printf��32bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRId64, "printf��64bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRIdLEAST8, "printf��int_least8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdLEAST16, "printf��int_least16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdLEAST32, "printf��int_least32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdLEAST64, "printf��int_least64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdFAST8, "printf��int_fast8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdFAST16, "printf��int_fast16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdFAST32, "printf��int_fast32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdFAST64, "printf��int_fast64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdMAX, "printf��intmax_t���o�͂���Ƃ��̏���");
    PutMacro(PRIdPTR, "printf��intptr_t���o�͂���Ƃ��̏���");
    PutMacro(PRIi8, "printf��8bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRIi16, "printf��16bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRIi32, "printf��32bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRIi64, "printf��64bit�����t���������o�͂���Ƃ��̏���");
    PutMacro(PRIiLEAST8, "printf��int_least8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiLEAST16, "printf��int_least16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiLEAST32, "printf��int_least32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiLEAST64, "printf��int_least64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiFAST8, "printf��int_fast8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiFAST16, "printf��int_fast16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiFAST32, "printf��int_fast32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiFAST64, "printf��int_fast64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiMAX, "printf��intmax_t���o�͂���Ƃ��̏���");
    PutMacro(PRIiPTR, "printf��intptr_t���o�͂���Ƃ��̏���");
    PutMacro(PRIo8, "printf��8bit�����t��������8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIo16, "printf��16bit�����t��������8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIo32, "printf��32bit�����t��������8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIo64, "printf��64bit�����t��������8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoLEAST8, "printf��int_least8_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoLEAST16, "printf��int_least16_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoLEAST32, "printf��int_least32_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoLEAST64, "printf��int_least64_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoFAST8, "printf��int_fast8_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoFAST16, "printf��int_fast16_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoFAST32, "printf��int_fast32_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoFAST64, "printf��int_fast64_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoMAX, "printf��intmax_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIoPTR, "printf��intptr_t��8�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIu8, "printf��8bit�����Ȃ��������o�͂���Ƃ��̏���");
    PutMacro(PRIu16, "printf��16bit�����Ȃ��������o�͂���Ƃ��̏���");
    PutMacro(PRIu32, "printf��32bit�����Ȃ��������o�͂���Ƃ��̏���");
    PutMacro(PRIu64, "printf��64bit�����Ȃ��������o�͂���Ƃ��̏���");
    PutMacro(PRIuLEAST8, "printf��uint_least8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuLEAST16, "printf��uint_least16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuLEAST32, "printf��uint_least32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuLEAST64, "printf��uint_least64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuFAST8, "printf��uint_fast8_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuFAST16, "printf��uint_fast16_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuFAST32, "printf��uint_fast32_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuFAST64, "printf��uint_fast64_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuMAX, "printf��uintmax_t���o�͂���Ƃ��̏���");
    PutMacro(PRIuPTR, "printf��uintptr_t���o�͂���Ƃ��̏���");
    PutMacro(PRIx8, "printf��8bit�������p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIx16, "printf��16bit�������p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIx32, "printf��32bit�������p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIx64, "printf��64bit�������p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxLEAST8, "printf��int_least8_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxLEAST16, "printf��int_least16_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxLEAST32, "printf��int_least32_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxLEAST64, "printf��int_least64_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxFAST8, "printf��int_fast8_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxFAST16, "printf��int_fast16_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxFAST32, "printf��int_fast32_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxFAST64, "printf��int_fast64_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxMAX, "printf��intmax_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIxPTR, "printf��intptr_t���p�q������16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIX8, "printf��8bit�������p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIX16, "printf��16bit�������p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIX32, "printf��32bit�������p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIX64, "printf��64bit�������p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXLEAST8, "printf��int_least8_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXLEAST16, "printf��int_least16_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXLEAST32, "printf��int_least32_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXLEAST64, "printf��int_least64_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXFAST8, "printf��int_fast8_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXFAST16, "printf��int_fast16_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXFAST32, "printf��int_fast32_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXFAST64, "printf��int_fast64_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXMAX, "printf��intmax_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    PutMacro(PRIXPTR, "printf��intptr_t���p�啶����16�i���ŏo�͂���Ƃ��̏���");
    
    PutMacro(SCNd8, "scanf��8bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNd16, "scanf��16bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNd32, "scanf��32bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNd64, "scanf��64bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNdLEAST8, "scanf��int_least8_t����荞�ނƂ��̏���");
    PutMacro(SCNdLEAST16, "scanf��int_least16_t����荞�ނƂ��̏���");
    PutMacro(SCNdLEAST32, "scanf��int_least32_t����荞�ނƂ��̏���");
    PutMacro(SCNdLEAST64, "scanf��int_least64_t����荞�ނƂ��̏���");
    PutMacro(SCNdFAST8, "scanf��int_fast8_t����荞�ނƂ��̏���");
    PutMacro(SCNdFAST16, "scanf��int_fast16_t����荞�ނƂ��̏���");
    PutMacro(SCNdFAST32, "scanf��int_fast32_t����荞�ނƂ��̏���");
    PutMacro(SCNdFAST64, "scanf��int_fast64_t����荞�ނƂ��̏���");
    PutMacro(SCNdMAX, "scanf��intmax_t����荞�ނƂ��̏���");
    PutMacro(SCNdPTR, "scanf��intptr_t����荞�ނƂ��̏���");
    PutMacro(SCNi8, "scanf��8bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNi16, "scanf��16bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNi32, "scanf��32bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNi64, "scanf��64bit�����t����������荞�ނƂ��̏���");
    PutMacro(SCNiLEAST8, "scanf��int_least8_t����荞�ނƂ��̏���");
    PutMacro(SCNiLEAST16, "scanf��int_least16_t����荞�ނƂ��̏���");
    PutMacro(SCNiLEAST32, "scanf��int_least32_t����荞�ނƂ��̏���");
    PutMacro(SCNiLEAST64, "scanf��int_least64_t����荞�ނƂ��̏���");
    PutMacro(SCNiFAST8, "scanf��int_fast8_t����荞�ނƂ��̏���");
    PutMacro(SCNiFAST16, "scanf��int_fast16_t����荞�ނƂ��̏���");
    PutMacro(SCNiFAST32, "scanf��int_fast32_t����荞�ނƂ��̏���");
    PutMacro(SCNiFAST64, "scanf��int_fast64_t����荞�ނƂ��̏���");
    PutMacro(SCNiMAX, "scanf��intmax_t����荞�ނƂ��̏���");
    PutMacro(SCNiPTR, "scanf��intptr_t����荞�ނƂ��̏���");
    PutMacro(SCNo8, "scanf��8bit�����t��������8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNo16, "scanf��16bit�����t��������8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNo32, "scanf��32bit�����t��������8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNo64, "scanf��64bit�����t��������8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoLEAST8, "scanf��int_least8_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoLEAST16, "scanf��int_least16_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoLEAST32, "scanf��int_least32_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoLEAST64, "scanf��int_least64_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoFAST8, "scanf��int_fast8_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoFAST16, "scanf��int_fast16_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoFAST32, "scanf��int_fast32_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoFAST64, "scanf��int_fast64_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoMAX, "scanf��intmax_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNoPTR, "scanf��intptr_t��8�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNu8, "scanf��8bit�����Ȃ���������荞�ނƂ��̏���");
    PutMacro(SCNu16, "scanf��16bit�����Ȃ���������荞�ނƂ��̏���");
    PutMacro(SCNu32, "scanf��32bit�����Ȃ���������荞�ނƂ��̏���");
    PutMacro(SCNu64, "scanf��64bit�����Ȃ���������荞�ނƂ��̏���");
    PutMacro(SCNuLEAST8, "scanf��uint_least8_t����荞�ނƂ��̏���");
    PutMacro(SCNuLEAST16, "scanf��uint_least16_t����荞�ނƂ��̏���");
    PutMacro(SCNuLEAST32, "scanf��uint_least32_t����荞�ނƂ��̏���");
    PutMacro(SCNuLEAST64, "scanf��uint_least64_t����荞�ނƂ��̏���");
    PutMacro(SCNuFAST8, "scanf��uint_fast8_t����荞�ނƂ��̏���");
    PutMacro(SCNuFAST16, "scanf��uint_fast16_t����荞�ނƂ��̏���");
    PutMacro(SCNuFAST32, "scanf��uint_fast32_t����荞�ނƂ��̏���");
    PutMacro(SCNuFAST64, "scanf��uint_fast64_t����荞�ނƂ��̏���");
    PutMacro(SCNuMAX, "scanf��uintmax_t����荞�ނƂ��̏���");
    PutMacro(SCNuPTR, "scanf��uintptr_t����荞�ނƂ��̏���");
    PutMacro(SCNx8, "scanf��8bit�������p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNx16, "scanf��16bit�������p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNx32, "scanf��32bit�������p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNx64, "scanf��64bit�������p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxLEAST8, "scanf��int_least8_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxLEAST16, "scanf��int_least16_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxLEAST32, "scanf��int_least32_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxLEAST64, "scanf��int_least64_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxFAST8, "scanf��int_fast8_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxFAST16, "scanf��int_fast16_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxFAST32, "scanf��int_fast32_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxFAST64, "scanf��int_fast64_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxMAX, "scanf��intmax_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNxPTR, "scanf��intptr_t���p�q������16�i���Ŏ�荞�ނƂ��̏���");

#if 0
    PutMacro(SCNX8, "scanf��8bit�������p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNX16, "scanf��16bit�������p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNX32, "scanf��32bit�������p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNX64, "scanf��64bit�������p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXLEAST8, "scanf��int_least8_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXLEAST16, "scanf��int_least16_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXLEAST32, "scanf��int_least32_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXLEAST64, "scanf��int_least64_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXFAST8, "scanf��int_fast8_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXFAST16, "scanf��int_fast16_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXFAST32, "scanf��int_fast32_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXFAST64, "scanf��int_fast64_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXMAX, "scanf��intmax_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");
    PutMacro(SCNXPTR, "scanf��intptr_t���p�啶����16�i���Ŏ�荞�ނƂ��̏���");

#endif

    return 0;
}

//imaxabs
static int f0(void)
{
    intmax_t n;

    if (IsConsole()) printf("���������: ");
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

    if (IsConsole()) printf("�����鐔: ");
    scanf("%" SCNiMAX, &m);

    if (IsConsole()) printf("���鐔: ");
    scanf("%" SCNiMAX, &n);

    if (n == 0) {
        fputs("�����Ƃ���Ă�\n", stderr);
        return 1;
    }

    result = imaxdiv(m, n);

    printf("%" PRIiMAX " �� %" PRIiMAX " = %" PRIiMAX " ���܂� %" PRIiMAX, m, n, result.quot, result.rem);

    return 0;
}

//strtoimax
static int f2(void)
{
    char str[STR_LENGTH];
    intmax_t n;
    int radix;
    char c;

    if (IsConsole()) printf("������: ");
    scanf("%d", &radix);

    if ((c = getchar()) != '\n' && c != ' ') {
        fputs("�����Ƃ���Ă�\n", stderr);
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fputs("���2~36�͈̔͂ɂ��Ă�\n", stderr);
        return 1;
    }

    if (IsConsole()) printf("�l�����: ");
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

    if (IsConsole()) printf("������: ");
    scanf("%d", &radix);

    if ((c = getchar()) != '\n' && c != ' ') {
        fputs("�����Ƃ���Ă�\n", stderr);
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fputs("���2~36�͈̔͂ɂ��Ă�\n", stderr);
        return 1;
    }

    if (IsConsole()) printf("�l�����: ");
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

    if (IsConsole()) wprintf(L"������: ");
    wscanf(L"%d", &radix);

    if ((c = getwchar()) != L'\n' && c != L' ') {
        fwprintf(stderr, L"�����Ƃ���Ă�\n");
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fwprintf(stderr, L"���2~36�͈̔͂ɂ��Ă�\n");
        return 1;
    }

    if (IsConsole()) wprintf(L"�l�����: ");
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

    if (IsConsole()) wprintf(L"������: ");
    wscanf(L"%d", &radix);

    if ((c = getwchar()) != L'\n' && c != L' ') {
        fwprintf(stderr, L"�����Ƃ���Ă�\n");
        return 1;
    }

    if (radix != 0 && (radix < 2 || 36 < radix)) {
        fwprintf(stderr, L"���2~36�͈̔͂ɂ��Ă�\n");
        return 1;
    }

    if (IsConsole()) wprintf(L"�l�����: ");
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