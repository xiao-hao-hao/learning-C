#define _CRT_SECURE_NO_WARNINGS 1

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