#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class SuperString
{
private:
	string data;

	string wstringTostring(const wstring& wstr);

	string TCHARTostring(const TCHAR* str);

	wstring stringTowstring(const string& str);

	string C_strTostring(const char* str);

	char* stringToC_str(const string& str);

	char* TCHARToC_str(const TCHAR* tchar);

	TCHAR* C_strToTCHAR(const char* c_str);

	TCHAR* stringToTCHAR(const string& str);

	wchar_t* C_strTowchar(const char* c_str);

	char* wcharToC_str(const wchar_t* wstr);

public:
	SuperString() : data("") {}

	SuperString(const string& str) : data(str) {}

	SuperString(const char* str) : data(str) {}

	SuperString(const wchar_t* str) : data(wcharToC_str(str)) {}

	SuperString(const wstring& str) : data(str.begin(), str.end()) {}

	SuperString(SuperString& superStr) : data(superStr.To_std_string()) {}

	string To_std_string();

	wstring To_std_wstring();

	TCHAR* To_TCHAR_str();

	char* To_C_str();

	void Append(const string& str);

	void Append(const wstring& str);

	void Append(const TCHAR* str);

	void Append(const char* str);

	void Append(SuperString& superStr);



	SuperString& operator<<(const string& str)
	{
		data += str;
		return *this;
	}

	SuperString& operator<<(const wstring& str)
	{
		data += wstringTostring(str);
		return *this;
	}

	SuperString& operator<<(const TCHAR* str) 
	{
		data += TCHARTostring(str);
		return *this;
	}

	SuperString& operator<<(const char* str)
	{
		data += str;
		return *this;
	}

	/*
	SuperString& operator<<(const wchar_t* str)
	{
		data += wcharToC_str(str);
		return *this;
	}
	*/

	SuperString& operator<<(SuperString& superStr)
	{
		data += superStr.To_std_string();
		return *this;
	}



	SuperString& operator+(const string& str)
	{
		data += str;
		return *this;
	}

	SuperString& operator+(const wstring& str)
	{
		data += wstringTostring(str);
		return *this;
	}

	SuperString& operator+(const TCHAR* str)
	{
		data += TCHARTostring(str);
		return *this;
	}

	SuperString& operator+(const char* str)
	{
		data += str;
		return *this;
	}

	/*
	SuperString& operator+(const wchar_t* str)
	{
		data += wcharToC_str(str);
		return *this;
	}
	*/
	SuperString& operator+(SuperString& superStr)
	{
		data += superStr.To_std_string();
		return *this;
	}



	SuperString& operator+=(const string& str)
	{
		data += str;
		return *this;
	}

	SuperString& operator+=(const wstring& str)
	{
		data += wstringTostring(str);
		return *this;
	}

	SuperString& operator+=(const TCHAR* str)
	{
		data += TCHARTostring(str);
		return *this;
	}

	SuperString& operator+=(const char* str)
	{
		data += str;
		return *this;
	}

	/*
	SuperString& operator+=(const wchar_t* str)
	{
		data += wcharToC_str(str);
		return *this;
	}
	*/

	SuperString& operator+=(SuperString& superStr)
	{
		data += superStr.To_std_string();
		return *this;
	}



	friend ostream& operator<<(ostream& os, const SuperString& superStr);
};