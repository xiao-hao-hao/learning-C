
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