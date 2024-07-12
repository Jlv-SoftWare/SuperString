#include "SuperString.h"

string SuperString::wstringTostring(const wstring& wstr)
{
	return string(wstr.begin(), wstr.end());
}

wstring SuperString::stringTowstring(const string& str)
{
	return wstring(str.begin(), str.end());
}

string SuperString::C_stringTostring(const char* str)
{
	return string(str);
}

string SuperString::TCHARTostring(const TCHAR* str)
{
	return string(TCHARToC_string(str));
}

char* SuperString::stringToC_string(const string& str)
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

char* SuperString::TCHARToC_string(const TCHAR* tchar)
{
	int charCount = WideCharToMultiByte(CP_ACP, 0, tchar, -1, nullptr, 0, nullptr, nullptr);
	char* result = new char[charCount];
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, result, charCount, nullptr, nullptr);
	return result;
}

TCHAR* SuperString::C_stringToTCHAR(const char* c_str)
{
	int charCount = MultiByteToWideChar(CP_ACP, 0, c_str, -1, nullptr, 0);
	TCHAR* result = new TCHAR[charCount];
	MultiByteToWideChar(CP_ACP, 0, c_str, -1, result, charCount);
	return result;
}

TCHAR* SuperString::stringToTCHAR(const string& str)
{
	return C_stringToTCHAR(str.c_str());
}

wchar_t* SuperString::C_stringTowchar(const char* c_str)
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

char* SuperString::wcharToC_string(const wchar_t* wstr)
{
	int charCount = WideCharToMultiByte(CP_ACP, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	char* result = new char[charCount];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, result, charCount, nullptr, nullptr);
	return result;
}



string SuperString::To_std_string()
{
	return dataString;
}

wstring SuperString::To_std_wstring()
{
	return stringTowstring(dataString);
}

TCHAR* SuperString::To_TCHAR_str()
{
	return stringToTCHAR(dataString);
}

char* SuperString::To_C_string()
{
	return stringToC_string(dataString);
}



vector<SuperString> SuperString::Split(const string& delimiter)
{
	vector<SuperString> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = dataString.find(delimiter, lastPos)) != std::string::npos) {
		tokens.push_back(dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter.length();
	}
	tokens.push_back(dataString.substr(lastPos));
	return tokens;
}

vector<SuperString> SuperString::Split(const wstring& delimiter)
{
	vector<SuperString> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = dataString.find(string(delimiter.begin(), delimiter.end()), lastPos)) != wstring::npos) 
	{
		tokens.push_back(dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter.length();
	}
	tokens.push_back(dataString.substr(lastPos));
	return tokens;
}

vector<SuperString> SuperString::Split(const TCHAR* delimiter)
{
	vector<SuperString> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = dataString.find(TCHARTostring(delimiter), lastPos)) != wstring::npos)
	{
		tokens.push_back(dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + TCHARTostring(delimiter).length();
	}
	tokens.push_back(dataString.substr(lastPos));
	return tokens;
}

vector<SuperString> SuperString::Split(const char* delimiter)
{
	vector<SuperString> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = dataString.find(delimiter, lastPos)) != wstring::npos)
	{
		tokens.push_back(dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + C_stringTostring(delimiter).length();
	}
	tokens.push_back(dataString.substr(lastPos));
	return tokens;
}

vector<SuperString> SuperString::Split(const char delimiter)
{
	vector<SuperString> tokens;
	string token;
	istringstream tokenStream(dataString);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

vector<SuperString> SuperString::Split(SuperString& delimiter)
{
	vector<SuperString> tokens;
	size_t pos = 0;
	size_t lastPos = 0;
	while ((pos = dataString.find(delimiter.To_std_string(), lastPos)) != std::string::npos) {
		tokens.push_back(dataString.substr(lastPos, pos - lastPos));
		lastPos = pos + delimiter.To_std_string().length();
	}
	tokens.push_back(dataString.substr(lastPos));
	return tokens;
}




bool SuperString::Contains(const string& value)
{
	return dataString.find(value) != string::npos;
}

bool SuperString::Contains(const wstring& value)
{
	return dataString.find(wstringTostring(value)) != string::npos;
}

bool SuperString::Contains(const TCHAR* value)
{
	return dataString.find(TCHARTostring(value)) != string::npos;
}

bool SuperString::Contains(const char* value)
{
	return dataString.find(value) != string::npos;
}

bool SuperString::Contains(const char value)
{
	return dataString.find(value) != string::npos;
}

bool SuperString::Contains(SuperString& value)
{
	return dataString.find(value.To_std_string()) != string::npos;
}


SuperString SuperString::Append(const string& str)
{
	return SuperString(dataString + str);
}

SuperString SuperString::Append(const wstring& str)
{
	return SuperString(dataString + wstringTostring(str));
}

SuperString SuperString::Append(const TCHAR* str)
{
	return SuperString(dataString + TCHARTostring(str));
}

SuperString SuperString::Append(const char* str)
{
	return SuperString(dataString + str);
}

SuperString SuperString::Append(SuperString& superStr)
{
	return SuperString(dataString + superStr.To_std_string());
}



ostream& operator<<(ostream& os, const SuperString& superStr)
{
	os << superStr.dataString;
	return os;
}