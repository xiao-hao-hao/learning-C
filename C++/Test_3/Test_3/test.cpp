
#include <iostream>
//#include "vld.h"
using namespace std;
#if 0
class Int
{
	friend ostream& operator<<(ostream &out, const Int &x);
	friend istream& operator>>(istream &in, const Int &x);

public:
	Int(int i = 0) : m_i(i)
	{}
	~Int()
	{}
public:
	Int operator+(const Int &x);//函数声明
	Int operator-(const Int &x);
	Int operator*(const Int &x);
	Int operator/(const Int &x);
	Int operator%(const Int &x);
public:
	Int& operator+=(const Int &x);
	Int& operator-=(const Int &x);
	Int& operator*=(const Int &x);
	Int& operator/=(const Int &x);
	Int& operator%=(const Int &x);
public:
	bool operator==(const Int &x);
	bool operator!=(const Int &x);
	bool operator>(const Int &x);
	bool operator>=(const Int &x);
	bool operator<(const Int &x);
	bool operator<=(const Int &x);
public:
	Int& operator++()  //++i
	{
		m_i++;
		return *this;
	}
	Int operator++(int)  //i++  需要临时空间 参数列表有一个参数只是告诉编译器这里是有参数的，如果有参数，编译器就知道这里是重载后置运算符
	{
		
		Int tmp(m_i);//这里是初始化,直接调用构造函数
		//Int tmp;  
		//tmp = m_i;//这里会先调用构造函数生成临时对象，然后调用赋值运算符
		m_i++;
		return tmp;
		
		/*
		Int tmp(*this);//调用一次拷贝构造函数
		++(*this);
		return tmp;
		*/
	}
	Int& operator--()  //--i
	{
		m_i--;
		return *this;
	}
	Int operator--(int)
	{
		Int tmp(*this);
		--(*this);
		return tmp;
	}
private:
	int m_i;
};

ostream& operator<<(ostream &out, const Int &x)
{
	out << x.m_i;
	return out;//为了可以连续用<<
}

istream& operator>>(istream &in, const Int &x)
{
	in >> x.m_i;
	return in;
}

Int Int::operator+(const Int &x)//返回一个临时对象
{
	return Int(m_i + x.m_i);//调用构造函数，生成一个无名的类对象
}

Int Int::operator-(const Int &x)
{
	return Int (m_i - x.m_i);
}

Int Int::operator*(const Int &x)
{
	return Int(m_i * x.m_i);
}

Int Int::operator/(const Int &x)
{
	return Int(m_i / x.m_i);
}

Int Int::operator%(const Int &x)
{
	return Int(m_i % x.m_i);
}

///////////////////////////////////////////////
Int& Int::operator+=(const Int &x)//因为不是临时变量，所以返回索引
{
	m_i += x.m_i;
	return *this;
}

Int& Int::operator-=(const Int &x)//因为不是临时变量，所以返回索引
{
	m_i -= x.m_i;
	return *this;
}

Int& Int::operator*=(const Int &x)//因为不是临时变量，所以返回索引
{
	m_i *= x.m_i;
	return *this;
}

Int& Int::operator/=(const Int &x)//因为不是临时变量，所以返回索引
{
	m_i /= x.m_i;
	return *this;
}

Int& Int::operator%=(const Int &x)//因为不是临时变量，所以返回索引
{
	m_i %= x.m_i;
	return *this;
}

bool Int::operator==(const Int &x)
{
	return m_i == x.m_i;
}

bool Int::operator!=(const Int &x)
{
	//return m_i != x.m_i;
	return !(*this==x);
}

bool Int::operator>(const Int &x)
{
	return m_i > x.m_i;
}

bool Int::operator>=(const Int &x)
{
	//return m_i >= x.m_i;
	return !(*this<x);
}

bool Int::operator<(const Int &x)
{
	return m_i < x.m_i;
}

bool Int::operator<=(const Int &x)
{
	//return m_i <= x.m_i;
	return !(*this>x);
}

int main()
{
	Int a = 1, b = 3;
	//cout << a + b << " " << a - b << " " << 
		//a * b << " " << a / b << " " << a % b << endl;
	//cout << (a %= b) << endl;
	//cout << a << endl;
	//cout << (a == b) << endl;
	//cout << a++ << endl;
	//cout << ++a << endl;
	//cout << a << " " << b << endl;

	//cout << a-- << endl;
	//cout << a << " " << b << endl;

	cout << --a << endl;
	cout << a << " " << b << endl;
	return 0;
}
#endif

/*
class Complex
{
	friend ostream& operator<<(ostream &out, const Complex &c);
public:
	Complex(int real = 0, int imag = 0) : m_real(real), m_imag(imag)
	{}
	~Complex()
	{}
public:
	int GetReal()const
	{
		return m_real;
	}
	int GetImag()const
	{
		return m_imag;
	}
public:
	Complex operator+(int x)
	{
		Complex tmp(m_real + x, m_imag + x);
		return tmp;
	}
	Complex& operator+=(int x)
	{
		m_real += x;
		m_imag += x;
		return *this;
	}
	Complex operator+(const Complex &c)const
	{
		Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		return tmp;
	}
	Complex& operator+=(const Complex &c)
	{
		m_real += c.m_real;
		m_imag += c.m_imag;
		return *this;
	}
private:
	int m_real;
	int m_imag;

};

ostream& operator<<(ostream &out, const Complex &c)
{
	out << "(" << c.m_real << ", " << c.m_imag << ")";
	return out;
}

int main()
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	cout << c1 += c2 << endl;
	cout << c2 << endl;
	return 0;
}
*/

/*
class Complex;//类声明
void Print(const Complex &c);

class Complex
{

	friend void Print(const Complex &c);
public:
	Complex(int real = 0, int imag = 0) : m_real(real), m_imag(imag)//变量初始化
	{}
	~Complex()
	{}
public:
	int GetReal()const
	{
		return m_real;
	}
	int GetImage()const
	{
		return m_imag;
	}
private:
	int m_real;
	int m_imag;
};

void Print(const Complex &c)
{
	cout << "(" << c.m_real << "," << c.m_imag << ")" << endl;
	//cout << "(" << c.GetReal() << "," << c.GetImage() << endl;
}

int main()
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	Print(c1);
	Print(c2);
	return 0;
}

*/

class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0);//函数声明
	Test(const Test &t);
	Test& operator=(const Test &t);
	~Test();
public:
	Test* operator&();
	const Test* operator&()const;
public:
	Test Add(const Test &t)
	{
		int sum = m_data + t.m_data;
		Test tmp(sum);
		return tmp;
	}
	Test operator+(const Test &t)
	{
		int sum = m_data + t.m_data;
		Test tmp(sum);
		return tmp;
	}
public:
	void Print()const
	{
		cout << m_data << endl;
	}
private:
	int m_data;
};

Test::Test(int data) : m_data(data)
{
	//m_data = data;
}

Test::Test(const Test &t)
{
	m_data = t.m_data;
}

Test& Test::operator=(const Test &t)
{
	if (this != &t)
	{
		m_data = t.m_data;
	}
	return *this;
}

Test::~Test()
{}

Test* Test::operator&()
{
	return this;
}

const Test* Test::operator&()const
{
	return this;
}

ostream& operator<<(ostream &out, const Test &t)
{
	out << t.m_data;
	return out;
}
/*
int main()
{
	Test t1(100);
	Test t2(20);
	//Test t = t1 + t2;
	Test t = t1.operator+(t2);
	cout << t << endl;
	return 0;
}
*/
/*
int main()
{
	//const Test t(10);
	//const Test *pt = &t;
	//cout << t << endl;
	//t.Print();
	return 0;
}*/

/*
class Date
{
public:
	Date(int year, int month, int day)
		: _year(_month)
		, _month(year)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1, 2, 3);//year为随机值，因为先对_year赋值，但是_month的值不确定，所以_year被赋予一个随机值
	return 0;
}
*/

/*
class A
{

public:
	A()
	{
		++_count;
	}
	A(const A &t)
	{
		++_count;
	}
	static int GetACount()
	{
		return _count;
	}
private:
	static int _count;
};

int A::_count = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << a1.GetACount() << endl;
	cout << A::GetACount() << endl;
}

int main()
{
	TestA();
	return 0;
}
*/
/*
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	ostream& operator<<(ostream& _cout)
	{
		_cout << this->_year << "-" << this->_month << "-" << this->_day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2019, 12, 5);
	d << cout;
	return 0;
}
*/
/*
class Date
{
	friend ostream& operator<<(ostream &_cout, const Date &d);
	friend istream& operator>>(istream &_cin, Date &d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date &d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

istream& operator>>(istream &_cin, Date &d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}

int main()
{
	//Date d(2019, 12, 5);
	Date d(1, 1, 1);
	cin >> d;
	cout << d << endl;
	return 0;
}
*/
/*
class A
{
public:
	class B
	{
	public:
		void foo(const A &a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
private:
	static int k;
	int h = 6;
};

int A::k = 1;
int main()
{
	A::B b;
	b.foo(A());
	return 0;
}
*/
/*
struct A
{
	int a[10];
	struct
	{
		int b;
	};
};

int main()
{
	//cout << sizeof(A) << endl;
	return 0;
}
*/