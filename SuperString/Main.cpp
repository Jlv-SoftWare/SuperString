#include "SuperString.h"

int main()
{
	SuperString suStr;;
	suStr << TEXT("���") << TEXT(", ����");
	cout << suStr << endl;
}