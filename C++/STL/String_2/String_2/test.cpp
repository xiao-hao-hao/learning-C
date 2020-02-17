#include <iostream>
#include <assert.h>
using namespace std;

namespace bit
{
	class String
	{
		friend ostream& operator<<(ostream &out, const String &s);
	public:
		typedef char* iterator;
	public:
		String(const char *str = "")
		{
			if (nullptr == str)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String &s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s);
			_swap(*this, tmp);
		}
		String& operator=(String &s)
		{
			if (this != &s)
			{
				String tmp(s);
				_swap(*this, tmp);
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			_size = _capacity = 0;
		}
	public:
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + size();
		}
	public:
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return _size == 0;
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		const char* c_str()const
		{
			return _str;
		}
		void push_back(char c)
		{
			if (_size >= _capacity)
				reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
	public:
		char& operator[](int i)
		{
			assert(i >= 0 && i < _size);
			return _str[i];
		}
	protected:
		static void _swap(String &s1, String &s2)
		{
			std::swap(s1._str, s2._str);
			std::swap(s1._capacity, s2._capacity);
			std::swap(s1._size, s2._size);
		}
	public:
		void reserve(size_t new_cpy)
		{
			if (new_cpy > _capacity)
			{
				char *new_str = new char[new_cpy + 1];
				memcpy(new_str, _str, _size);
				_capacity = new_cpy;
				delete[] _str;
				_str = new_str;
			}
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
	ostream& operator<<(ostream &out, const String &s)
	{
		out << s._str;
		return out;
	}
}


int main()
{
	bit::String str1("hello bit");
	cout << "str1 = " << str1 << endl;
	str1.push_back('x');
	cout << "str1 = " << str1 << endl;
	return 0;
}

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String strTmp(s._str);
//		std::swap(_str, strTmp._str);
//	}
//	String& operator=(String s)
//	{
//		std::swap(_str, s._str);
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	String str1 = "1234";
//	String str2;
//	str2 = str1;
//	return 0;
//}

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