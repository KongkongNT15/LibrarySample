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
    puts("�X�g���[���̍ŏ��o�b�t�@�T�C�Y");

    puts("EOF");
    puts(Macro(EOF));
    puts("�֐������s�����Ƃ��̖߂�l");

    puts("FOPEN_MAX");
    puts(Macro(FOPEN_MAX));
    puts("��x�ɊJ����t�@�C���̍ő吔");

    puts("FILENAME_MAX");
    puts(Macro(FILENAME_MAX));
    puts("�p�X�̍ő咷");

    puts("NULL");
    puts(Macro(NULL));
    puts("��|�C���^");

    puts("SEEK_SET");
    puts(Macro(SEEK_SET));
    puts("�t�@�C���̐擪�ʒu���w��");

    puts("SEEK_CUR");
    puts(Macro(SEEK_CUR));
    puts("�t�@�C���̌��݈ʒu���w��");

    puts("SEEK_END");
    puts(Macro(SEEK_END));
    puts("�t�@�C���̏I�[�ʒu���w��");

    puts("stdin");
    puts(Macro(stdin));
    puts("�W�����̓X�g���[��");

    puts("stdout");
    puts(Macro(stdout));
    puts("�W���o�̓X�g���[��");

    puts("stderr");
    puts(Macro(stderr));
    puts("�W���G���[�o�̓X�g���[��");

    puts("TMP_MAX");
    puts(Macro(TMP_MAX));
    puts("tmpnam() ���d�������ɐ����ł���t�@�C�����̍ő��");

    puts("_IOFBF");
    puts(Macro(_IOFBF));
    puts("�o�b�t�@�������ς��ɂȂ����Ƃ��Ƀt���b�V�����邱�Ƃ��w��");

    puts("_IONBF");
    puts(Macro(_IONBF));
    puts("�o�b�t�@�����O���Ȃ����Ƃ��w��");

    puts("_IOLBF");
    puts(Macro(_IOLBF));
    puts("���s�������}�����ꂽ�Ƃ��Ƀt���b�V�����邱�Ƃ��w��");

    return 0;
}

//feof
static int f0(void)
{
    char path[1024];

    if (IsConsole()) printf("�t�@�C�����J��: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("�t�@�C�����J���܂���ł���\n", stderr);
        return 1;
    }

    printf("feof() = %s\n", feof(fp) == 1 ? "true" : "false");

    //�t�@�C���̏I�[�܂ŋ��
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

    if (IsConsole()) printf("�t�@�C�����J��: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("�t�@�C�����J���܂���ł���\n", stderr);
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

    if (IsConsole()) printf("�t�@�C�����J��: ");
    getline(path, 1024);

    fpos_t pos1, pos2;
    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("�t�@�C�����J���܂���ł���\n", stderr);
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

    if (IsConsole()) printf("�t�@�C�����J��: ");
    getline(path, 1024);

    char str[1024];
    FILE* fp = fopen(path, "r");

    if (fp == NULL) {
        fputs("�t�@�C�����J���܂���ł���\n", stderr);
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

    if (IsConsole()) printf("�t�@�C�����쐬: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "w");

    if(fp == NULL) {
        fputs("�t�@�C�����쐬�ł��܂���ł���\n", stderr);
        return 1;
    }

    char str[100];

    printf("�t�@�C���ɏ������ޕ���������: ");
    scanf("%99s", str);

    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d : %s\n", i + 1, str);
    }

    fclose(fp);
    puts("�t�@�C����ۑ����܂���");

    return 0;
}

//fputs
static int f6(void)
{
    char path[1024];

    if (IsConsole()) printf("�t�@�C�����쐬: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("�t�@�C�����쐬�ł��܂���ł���\n", stderr);
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fputs("�悤�@�ː������I\n", fp);
    }

    fclose(fp);
    puts("�t�@�C����ۑ����܂���");

    return 0;
}

//getc
static int f7(void)
{
    char path[1024];

    if (IsConsole()) printf("�t�@�C�����J��: ");
    getline(path, 1024);

    FILE* fp = fopen(path, "rb");

    if (fp == NULL) {
        fputs("�t�@�C�����J���܂���ł���\n", stderr);
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

    if (IsConsole()) printf("����������: ");

    for (count = 0; (c = getchar()) != '\n'; ++count) {
        putchar(c);
    }
    putchar('\n');

    printf("������ = %d\n", count);

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
    printf("���ʃe�X�g�p�ꃊ�X�j���O: %d/%d\n", n, 100);
    printf("%.2lf GHz\n", x);
    printf("printf: %p\n", printf);

    return 0;
}

//fputc
static int f11(void)
{
    char path[1024];

    if (IsConsole()) printf("�t�@�C�����쐬: ");
    getline(path, 1024);

    char c = 'A';
    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("�t�@�C�����쐬�ł��܂���ł���\n", stderr);
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        fputc(c++, fp);
    }

    fclose(fp);
    puts("�t�@�C����ۑ����܂���");

    return 0;
}

//putc
static int f12(void)
{
    char path[1024];

    if (IsConsole()) printf("�t�@�C�����쐬: ");
    getline(path, 1024);

    char c = 'A';
    FILE* fp = fopen(path, "w");

    if (fp == NULL) {
        fputs("�t�@�C�����쐬�ł��܂���ł���\n", stderr);
        return 1;
    }

    for (int i = 0; i < 26; i++) {
        putc(c++, fp);
    }

    fclose(fp);
    puts("�t�@�C����ۑ����܂���");

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
    char str[] = "�ː������I";

    puts("�悤");
    puts(str);

    return 0;
}

//remove
static int f15(void)
{
    char name[1024];

    if (IsConsole()) printf("�폜����t�@�C���������: ");
    getline(name, 1024);

    if (remove(name) == EOF) {
        fputs("����Ɏ��s���܂���\n", stderr);
        return EOF;
    }
    puts("�t�@�C�����폜���܂���");

    return 0;
}

//scanf
static int f16(void)
{
    int n;
    int c;

    if (IsConsole()) printf("���������: ");
    scanf("%d", &n);

    printf("n = %d\n", n);

    printf("stdin�Ɏc��������: \"");
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

    ret = snprintf(NULL, 0, "�F�B��%d��%d���ɖ��w�̃z�e���ɔ��܂�炵��", 5, 4);

    printf("������: %zu\n", ret);

    length = ret + 1;

    char* str = malloc(length * sizeof(char));

    if (str == NULL) {
        fputs("�������̊m�ۂɎ��s���܂���", stderr);
        return 1;
    }

    snprintf(str, length, "�F�B��%d��%d���ɖ��w�̃z�e���ɔ��܂�炵��", 5, 4);

    printf("str: %s\n", str);

    free(str);

    return 0;
}

//sprintf
static int f18(void)
{
    char str[100];

    sprintf(str, "�����̋C����%d���ł�", 21);

    printf("str: %s\n", str);

    return 0;
}

//sscanf
static int f19(void)
{
    char str1[] = "25";
    char str2[] = "11.2";
    char str3[] = "�����̓��t: 8��27��";
    int a;
    double b;
    int c;
    int d;

    sscanf(str1, "%d", &a);
    sscanf(str2, "%lf", &b);
    sscanf(str3, "�����̓��t: %d��%d��", &c, &d);

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
            fputs("�t�@�C�������쐬�ł��܂���ł���\n", stderr);
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
        printf("���������: ");

        while ((c = getchar()) != '\n') {
            if (isdigit(c) == 0) {
                ungetc(c, stdin);

                putchar('\n');
                printf("stdin�Ɏc��������: \"");
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
    func("���ʃe�X�g�p�ꃊ�X�j���O: %d/%d\n", n, 100);
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