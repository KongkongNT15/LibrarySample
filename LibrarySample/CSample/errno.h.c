#include "pch.h"

static int macro(void)
{
	puts("errno");
	puts(Macro(errno));
	puts("エラー状態");

	return 0;

	//1
	puts("EPERM");
	puts(Macro(EPERM));
	puts("操作が拒否されました");

	//2
	puts("ENOENT");
	puts(Macro(ENOENT));
	puts("指定されたパスが見つかりませんでした");

	//3
	puts("ESRCH");
	puts(Macro(ESRCH));
	puts("指定されたプロセスが見つかりませんでした");

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