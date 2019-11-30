//#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);//需要用this来区分两个name
		this->count = count;
		this->price = price;
	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return name;
	}
	int GetCount()
	{
		return count;
	}
	float GetPrice()
	{
		return price;
	}
	float GetTotalPrice()
	{
		return price * count;
	}
private:
	char name[10];
	int count;
	float price;
	float total_price;
};

int main()
{
	CGoods goods1;
	goods1.RegisterGoods("abc", 5, 2.1);
	return 0;
}
*/
/*
class A1
{
public:
	void f1(){}
private:
	int _a;
};

class A2
{
public:
	void f2(){}
};

class A3
{};

int main()
{
	cout << sizeof(A1) << sizeof(A2) << sizeof(A3) << endl;
	return 0;
}
*/

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//}
//int main()
//{
//	A a;
//	A *p = &a;
//	p->PrintA();
//	p->Show();
//}
/*
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1;//编译不通过
}
*/

/*
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date()
	{}
private:
	int _year;
	int _month;
	int _day;

	Time _t;
};

int main()
{
	Date d;
	return 0;
}
*/
/*
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}
*/
/*
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	//这里d2调用的是默认拷贝构造函数完成拷贝
	Date d2(d1);
	return 0;
}
*/

/*
//程序会崩溃，
class String
{
public:
	String(const char *str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char *_str;
};

int main()
{
	String s1("hello");
	String s2(s1);//掉用默认复制构造函数，传地址s2._str = s1._str;,同一块地址释放了两次。所以报错
	return 0;
}
*/

/*
class Date
{
public:
	void Display()
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
	return 0;
}
*/
/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;	
};

void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 26);
	cout << (d1 == d2) << endl;
}

int main()
{
	Test();
	return 0;
}
*/
/*
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char *_str;
};

int main()
{
	String s1("hello");
	String s2("world");
	s1 = s2;//同一块空间释放两次
	return 0;
}
*/
/*
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
	String& operator=(const String &s)
	{
		if(this != &s)//1.自我赋值检测
		{
			free(_str);//2.释放当前对象空间
			//3.重新开辟空间并赋值
			_str = (char*)malloc(strlen(s._str) + 1);
			strcpy(_str, s._str);
		}
		return *this;//4.返回当前对象是为了可以连等
	}
private:
	char *_str;
};

int main()
{
	String s1("hello");
	String s2("world");
	String &s3 = s1;
	cout << &s1 << &s1 << endl;
	s3 = s1 = s2;//同一块空间释放两次s1.operator=(s2)//operator(&s1, s2)//s3.operator=(s1.operatoe=(s2))
	return 0;
}
*/

