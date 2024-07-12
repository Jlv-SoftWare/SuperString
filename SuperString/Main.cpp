#include "SuperString.h"

SuperString Input(const string& tips);

int main()
{

}

SuperString Input(const string& tips)
{
	string result;
	cout << tips << "> ";
	getline(cin, result);
	return result;
}