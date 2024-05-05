#include "pch.h"

static int macro(void)
{
    puts("NULL");
    puts(Macro(NULL));
    puts("��|�C���^");
    
    return 0;
}

//isalnum
static int f0(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");
            
            continue;
        }

        if (isalnum(c)) printf("'%c'�͉p���������͐����ł�\n", c);
        else printf("'%c'�͉p���ł������ł�����܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isalnum(c)) printf("'%c'�͉p���������͐����ł�\n", c);
        else printf("'%c'�͉p���ł������ł�����܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isalpha
static int f1(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isalpha(c)) printf("'%c'�͉p���ł�\n", c);
        else printf("'%c'�͉p���ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isalpha(c)) printf("'%c'�͉p���ł�\n", c);
        else printf("'%c'�͉p���ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isblank
static int f2(void)
{
    char str[] = "123 abc\tABC";

    size_t length = (sizeof(str) / sizeof(char)) - 1;

    for (size_t i = 0; i < length; ++i) {
        if (isblank(str[i])) printf("'%c'�͋󔒂ł�\n", str[i]);
        else printf("'%c'�͋󔒂ł͂���܂���\n", str[i]);
    }

    return 0;
}

//iscntrl
static int f3(void)
{
    char str[] = "123 \t \n \r abc";

    size_t length = (sizeof(str) / sizeof(char)) - 1;

    for (size_t i = 0; i < length; ++i) {
        if (iscntrl(str[i])) printf("0x%02X�͐��䕶���ł�\n", str[i]);
        else printf("0x%02X�͐��䕶���ł͂���܂���\n", str[i]);
    }

    return 0;
}

//isdigit
static int f4(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isdigit(c)) printf("'%c'�͐����ł�\n", c);
        else printf("'%c'�͐����ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isdigit(c)) printf("'%c'�͐����ł�\n", c);
        else printf("'%c'�͐����ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isgraph
static int f5(void)
{
    char str[] = "123 \t \n \r abc";

    size_t length = (sizeof(str) / sizeof(char)) - 1;

    for (size_t i = 0; i < length; ++i) {
        if (isgraph(str[i])) printf("0x%02X�͋󔒈ȊO�̕\�������ł�\n", str[i]);
        else printf("0x%02X�͋󔒁A�������͐��䕶���ł�\n", str[i]);
    }

    return 0;
}

//islower
static int f6(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (islower(c)) printf("'%c'�͉p�������ł�\n", c);
        else printf("'%c'�͉p�����ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (islower(c)) printf("'%c'�͉p�������ł�\n", c);
        else printf("'%c'�͉p�����ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isprint
static int f7(void)
{
    char str[] = "123 \t \n \r abc";

    size_t length = (sizeof(str) / sizeof(char)) - 1;

    for (size_t i = 0; i < length; ++i) {
        if (isprint(str[i])) printf("0x%02X�͕\�������ł�\n", str[i]);
        else printf("0x%02X�͕\�������ł͂���܂���\n", str[i]);
    }

    return 0;
}

//ispunct
static int f8(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (ispunct(c)) printf("'%c'�͋L���ł�\n", c);
        else printf("'%c'�͋L���ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (ispunct(c)) printf("'%c'�͋L���ł�\n", c);
        else printf("'%c'�͋L���ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isspace
static int f9(void)
{
    char str[] = "123 ABC \t abc !?";

    size_t length = (sizeof(str) / sizeof(char)) - 1;

    for (size_t i = 0; i < length; ++i) {
        if (isspace(str[i])) printf("'%c'�̓X�y�[�X�ł�\n", str[i]);
        else printf("'%c'�̓X�y�[�X�ł͂���܂���\n", str[i]);
    }

    return 0;
}

//isupper
static int f10(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (ispunct(c)) printf("'%c'�͋L���ł�\n", c);
        else printf("'%c'�͋L���ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (ispunct(c)) printf("'%c'�͋L���ł�\n", c);
        else printf("'%c'�͋L���ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//isxdigit
static int f11(void)
{
#ifdef __MSVC__
    int c;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        //�}���`�o�C�g�����̂P�o�C�g��
        if (IsShiftJisMultiByteChar(c)) {
            putchar('\'');
            putchar(c);
            putchar(getchar());
            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isxdigit(c)) printf("'%c'��16�i���̐����ł�\n", c);
        else printf("'%c'��16�i���̐����ł͂���܂���\n", c);
    }

    return 0;
#endif //__MSVC__
#ifdef __UNIX__
    int c;
    int n;
    int i;

    if (IsConsole()) printf("����������: ");

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) break;

        n = GetUTF8MultiByteCharLength(c);

        //�}���`�o�C�g�����̂P�o�C�g��
        if (n > 1) {
            putchar('\'');
            putchar(c);

            for (i = 1; i < n; i++) {
                putchar(getchar());
            }

            puts("'�̓}���`�o�C�g�����ł�");

            continue;
        }

        if (isxdigit(c)) printf("'%c'��16�i���̐����ł�\n", c);
        else printf("'%c'��16�i���̐����ł͂���܂���\n", c);
    }

    return 0;
#endif __UNIX__

}

//tolower
static int f12(void)
{
    char str1[] = "ABCDabcd1234 !?";
    char str2[sizeof(str1) / sizeof(char)];

    for (size_t i = 0; i < (sizeof(str1) / sizeof(char)); ++i) {
        str2[i] = tolower(str1[i]);
    }

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}

//toupper
static int f13(void)
{
    char str1[] = "ABCDabcd1234 !?";
    char str2[sizeof(str1) / sizeof(char)];

    for (size_t i = 0; i < (sizeof(str1) / sizeof(char)); ++i) {
        str2[i] = toupper(str1[i]);
    }

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}

int ctype__h__run(FUNCNAME)
{
    if (IsEqualFuncName("isalnum")) return f0();
    if (IsEqualFuncName("isalpha")) return f1();
    if (IsEqualFuncName("isblank")) return f2();
    if (IsEqualFuncName("iscntrl")) return f3();
    if (IsEqualFuncName("isdigit")) return f4();
    if (IsEqualFuncName("isgraph")) return f5();
    if (IsEqualFuncName("islower")) return f6();
    if (IsEqualFuncName("isprint")) return f7();
    if (IsEqualFuncName("ispunct")) return f8();
    if (IsEqualFuncName("isspace")) return f9();
    if (IsEqualFuncName("isupper")) return f10();
    if (IsEqualFuncName("isxdigit")) return f11();
    if (IsEqualFuncName("tolower")) return f12();
    if (IsEqualFuncName("toupper")) return f13();

    
    if (IsEqualFuncName(MACRO_FUNCTION)) return macro();

    return NotFound(FUNCNAMEVALUE);
}