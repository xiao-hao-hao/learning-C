#include <iostream>
#include <assert.h>
#include <string>
#include <vld.h>
using namespace std;

namespace bit
{
	class String
	{
		friend ostream& operator<<(ostream& out, const String &s);
		friend istream& operator>>(istream& in, String& s);
	public:
		typedef char* iterator;
		static const size_t npos = -1;
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
		String& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		String& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void append(const char* str)
		{
			int str_len = strlen(str);
			if (str_len + _size > _capacity)
			{
				reserve((str_len + _size) * 2);
			}
			strcpy(_str + _size, str);
			_size += str_len;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					reserve(newSize * 2);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[_size] = '\0';
		}
		bool operator<(const String& s)
		{
			return (strcmp(_str, s._str) < 0);
		}
		bool operator<=(const String& s)
		{
			return !(*this > s);
		}
		bool operator>(const String& s)
		{
			return (strcmp(_str, s._str) > 0);
		}
		bool operator>=(const String& s)
		{
			return !(*this < s);
		}
		bool operator==(const String& s)
		{
			return (strcmp(_str, s._str) == 0);
		}
		bool operator!=(const String& s)
		{
			return !(*this == s);
		}
		//返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0)const
		{
			for (int i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0)const
		{
			//return strstr(_str + pos, s) - _str;
			size_t i = pos, j = 0;
			size_t s_len = strlen(s);
			while (i < _size && j < s_len)
			{
				if (_str[i] == s[j])
				{
					++i;
					++j;
				}
				else
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if (j >= s_len)
			{
				return i - j;
			}
			return npos;
		}
		String& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve((_size + 1) * 2);
			}
			for (size_t i = _size; i > pos; --i)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_str[_size++] = '\0';
			return *this;
		}
		String& insert(size_t pos, const char* str)
		{
			assert(pos >= 0 && pos <= _size);
			int str_len = strlen(str);
			_size += str_len;
			if (_size + str_len > _capacity)
			{
				reserve((_size + str_len) * 2);
			}
			memcpy(_str + pos + str_len, _str + pos, _size - pos + 1);
			while (*str != '\0')
			{
				_str[pos++] = *(str++);
			}
			return *this;
		}
		String& erase(size_t pos, size_t len)
		{
			memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
			_size -= len;
			return *this;

		}
	public:
		char& operator[](int i)
		{
			assert(i >= 0 && i < _size);
			return _str[i];
		}
		const char& operator[](size_t i)const
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
				memcpy(new_str, _str, _size + 1);//这里要把\0也拷贝上去
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
	istream& operator>>(istream& in, String& s)
	{
		static const size_t default_buf_size = 10;
		int capacity = default_buf_size;
		char *str = new char[default_buf_size];
		char *buf = str;
		size_t count = 0;
		//跳过字符串起始位置的空格和换行
		while ((*buf = getchar()) == ' ' || *buf == '\n');
		while (1)
		{
			++count;
			if (count >= capacity)
			{
				capacity *= 2;
				//str = (char*)realloc(str, capacity);
				char *new_str = new char[capacity];
				memcpy(new_str, str, count);
				delete[] str;
				str = new_str;
				buf = str + count - 1;
			}
			*(++buf) = getchar();
			if (*buf == '\n' || *buf == ' ')
			{
				*buf = '\0';
				break;
			}
		}
		delete[] s._str;
		s._str = str;
		s._capacity = capacity;
		s._size = count;
		return in;
	}
}


int main()
{
	bit::String str1("hello bit");
	string str2("helo");
	cout << "str1 = " << str1 << endl;
	str1.push_back('x');
	cout << str1.find("it");
	//cout << str1.capacity() << endl;
	//cout << str1.insert(1, "123");
	//str1.insert(3, 'u');
	//str1.erase(1, 3);
	//cout << str1 << endl;
	cout << str1 << endl;
	cin >> str1;
	cout << str1 << endl;
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