#include <iostream>
#include <assert.h>
#include <string.h>

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		std::swap(_str, strTmp._str);
	}
	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	String str1 = "1234";
	String str2;
	str2 = str1;
	return 0;
}

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//	{
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char *pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char *_str;
//};
//
//int main()
//{
//	String str1 = "1234";
//	String str2;
//	str2 = str1;
//	return 0;
//}