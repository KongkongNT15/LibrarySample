#include "pch.h"

static int macro(void)
{
	puts("and");
	puts(Macro(and));
	puts("�_��AND���Z�q�̑�ւÂ�");

	puts("and_eq");
	puts(Macro(and_eq));
	puts("�r�b�g�ς̑�����Z�q�̑�ւÂ�");

	puts("bitand");
	puts(Macro(bitand));
	puts("�r�b�g�ς�\�����Z�q�̑�ւÂ�");

	puts("bitor");
	puts(Macro(bitor));
	puts("�r�b�g�a��\�����Z�q�̑�ւÂ�");

	puts("compl");
	puts(Macro(compl));
	puts("�r�b�g���]���Z�q�̑�ւÂ�");

	puts("not");
	puts(Macro(not));
	puts("�ے��\�����Z�q�̑�ւÂ�");

	puts("not_eq");
	puts(Macro(not_eq));
	puts("�s�����̑�ւÂ�");

	puts("or");
	puts(Macro(or));
	puts("�_��OR���Z�q�̑�ւÂ�");

	puts("or_eq");
	puts(Macro(or_eq));
	puts("�r�b�g�a�̑�����Z�q�̑�ւÂ�");

	puts("xor");
	puts(Macro(xor));
	puts("�r�b�g����\�����Z�q�̑�ւÂ�");

	puts("xor_eq");
	puts(Macro(xor_eq));
	puts("�r�b�g�a�̑�����Z�q�̑�ւÂ�");

	return 0;
}

int iso646__h__run(FUNCNAME)
{
	if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
	return NotFound(FUNCNAMEVALUE);
}