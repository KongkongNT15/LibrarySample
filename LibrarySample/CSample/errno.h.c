#include "pch.h"

static int macro(void)
{
	puts("errno");
	puts(Macro(errno));
	puts("�G���[���");

	return 0;

	//1
	puts("EPERM");
	puts(Macro(EPERM));
	puts("���삪���ۂ���܂���");

	//2
	puts("ENOENT");
	puts(Macro(ENOENT));
	puts("�w�肳�ꂽ�p�X��������܂���ł���");

	//3
	puts("ESRCH");
	puts(Macro(ESRCH));
	puts("�w�肳�ꂽ�v���Z�X��������܂���ł���");

	puts("EINTR");
	puts(Macro(EINTR));
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	puts("");
	puts(Macro());
	puts("");

	return 0;
}

int errno__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();


	return NotFound(FUNCNAMEVALUE);
}