#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class SuperString
{
private:
	string dataString;

	string wstringTostring(const wstring& wstr);

	string TCHARTostring(const TCHAR* str);

	wstring stringTowstring(const string& str);

	string C_stringTostring(const char* str);

	char* stringToC_string(const string& str);

	char* TCHARToC_string(const TCHAR* tchar);

	TCHAR* C_stringToTCHAR(const char* c_str);

	TCHAR* stringToTCHAR(const string& str);

	wchar_t* C_stringTowchar(const char* c_str);

	char* wcharToC_string(const wchar_t* wstr);

public:
	SuperString() : dataString("") {}

	SuperString(const string& str) : dataString(str) {}

	SuperString(const char* str) : dataString(str) {}

	SuperString(const wchar_t* str) : dataString(wcharToC_string(str)) {}

	SuperString(const wstring& str) : dataString(str.begin(), str.end()) {}

	SuperString(SuperString& superStr) : dataString(superStr.To_std_string()) {}

	SuperString(const SuperString& other) : dataString(other.dataString) {}

	string To_std_string();

	wstring To_std_wstring();

	TCHAR* To_TCHAR_str();

	char* To_C_string();

	SuperString Append(const string& str);

	SuperString Append(const wstring& str);

	SuperString Append(const TCHAR* str);

	SuperString Append(const char* str);

	SuperString Append(SuperString& superStr);


	vector<SuperString> Split(const string& delimiter);

	vector<SuperString> Split(const wstring& delimiter);

	vector<SuperString> Split(const TCHAR* delimiter);

	vector<SuperString> Split(const char* delimiter);

	vector<SuperString> Split(const char delimiter);

	vector<SuperString> Split(SuperString& delimiter);
	
	
	bool Contains(const string& value);

	bool Contains(const wstring& value);

	bool Contains(const TCHAR* value);

	bool Contains(const char* value);

	bool Contains(const char value);

	bool Contains(SuperString& value);
	

	SuperString& operator<<(const string& str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator<<(const wstring& str)
	{
		dataString += wstringTostring(str);
		return *this;
	}

	SuperString& operator<<(const TCHAR* str) 
	{
		dataString += TCHARTostring(str);
		return *this;
	}

	SuperString& operator<<(const char* str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator<<(const char str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator<<(SuperString& superStr)
	{
		dataString += superStr.To_std_string();
		return *this;
	}



	SuperString& operator+(const string& str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+(const wstring& str)
	{
		dataString += wstringTostring(str);
		return *this;
	}

	SuperString& operator+(const TCHAR* str)
	{
		dataString += TCHARTostring(str);
		return *this;
	}

	SuperString& operator+(const char* str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+(const char str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+(SuperString& superStr)
	{
		dataString += superStr.To_std_string();
		return *this;
	}



	SuperString& operator+=(const string& str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+=(const wstring& str)
	{
		dataString += wstringTostring(str);
		return *this;
	}

	SuperString& operator+=(const TCHAR* str)
	{
		dataString += TCHARTostring(str);
		return *this;
	}

	SuperString& operator+=(const char* str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+=(const char str)
	{
		dataString += str;
		return *this;
	}

	SuperString& operator+=(SuperString& superStr)
	{
		dataString += superStr.To_std_string();
		return *this;
	}



	friend ostream& operator<<(ostream& os, const SuperString& superStr);
};