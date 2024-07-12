#include "SuperString.h"

string SuperString::wstringTostring(const wstring& wstr)
{
	return string(wstr.begin(), wstr.end());
}

wstring SuperString::stringTowstring(const string& str)
{
	return wstring(str.begin(), str.end());
}

string SuperString::C_strTostring(const char* str)
{
	return string(str);
}

string SuperString::TCHARTostring(const TCHAR* str)
{
	return string(TCHARToC_str(str));
}

char* SuperString::stringToC_str(const string& str)
{
	int len = (int)str.length();
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = str[i];
	}
	p[len] = '\0';
	return p;
}

char* SuperString::TCHARToC_str(const TCHAR* tchar)
{
	int charCount = WideCharToMultiByte(CP_ACP, 0, tchar, -1, nullptr, 0, nullptr, nullptr);
	char* result = new char[charCount];
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, result, charCount, nullptr, nullptr);
	return result;
}

TCHAR* SuperString::C_strToTCHAR(const char* c_str)
{
	int charCount = MultiByteToWideChar(CP_ACP, 0, c_str, -1, nullptr, 0);
	TCHAR* result = new TCHAR[charCount];
	MultiByteToWideChar(CP_ACP, 0, c_str, -1, result, charCount);
	return result;
}

TCHAR* SuperString::stringToTCHAR(const string& str)
{
	return C_strToTCHAR(str.c_str());
}

wchar_t* SuperString::C_strTowchar(const char* c_str)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, c_str, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, c_str, -1, pResult, nLen);
	return pResult;
}

char* SuperString::wcharToC_str(const wchar_t* wstr)
{
	int charCount = WideCharToMultiByte(CP_ACP, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	char* result = new char[charCount];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, result, charCount, nullptr, nullptr);
	return result;
}



string SuperString::To_std_string()
{
	return data;
}

wstring SuperString::To_std_wstring()
{
	return stringTowstring(data);
}

TCHAR* SuperString::To_TCHAR_str()
{
	return stringToTCHAR(data);
}

char* SuperString::To_C_str()
{
	return stringToC_str(data);
}



void SuperString::Append(const string& str)
{
	data += str;
}

void SuperString::Append(const wstring& str)
{
	data += wstringTostring(str);
}

void SuperString::Append(const TCHAR* str)
{
	data += TCHARTostring(str);
}

void SuperString::Append(const char* str)
{
	data += str;
}

void SuperString::Append(SuperString& superStr)
{
	data += superStr.To_std_string();
}



ostream& operator<<(ostream& os, const SuperString& superStr)
{
	os << superStr.data;
	return os;
}