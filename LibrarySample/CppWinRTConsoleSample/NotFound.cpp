#include "pch.h"

namespace Kongkong
{
	int NotFound(const char* tag)
	{
		using namespace std;

		cerr << '"' << tag << "\"が見つかりませんでした" << endl;
		cerr << "ふぁ！？っく" << endl;

		return -1;
	}
}
