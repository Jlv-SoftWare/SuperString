#include "SuperString.h"

int main()
{
	SuperString suStr;;
	suStr << TEXT("ÄãºÃ") << TEXT(", ÊÀ½ç");
	cout << suStr << endl;
}