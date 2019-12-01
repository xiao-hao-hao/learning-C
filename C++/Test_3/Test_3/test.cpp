
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
	Int operator+(const Int &x);//��������
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
	Int operator++(int)  //i++  ��Ҫ��ʱ�ռ� �����б���һ������ֻ�Ǹ��߱������������в����ģ�����в�������������֪�����������غ��������
	{
		
		Int tmp(m_i);//�����ǳ�ʼ��,ֱ�ӵ��ù��캯��
		//Int tmp;  
		//tmp = m_i;//������ȵ��ù��캯��������ʱ����Ȼ����ø�ֵ�����
		m_i++;
		return tmp;
		
		/*
		Int tmp(*this);//����һ�ο������캯��
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
	return out;//Ϊ�˿���������<<
}

istream& operator>>(istream &in, const Int &x)
{
	in >> x.m_i;
	return in;
}

Int Int::operator+(const Int &x)//����һ����ʱ����
{
	return Int(m_i + x.m_i);//���ù��캯��������һ�������������
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
Int& Int::operator+=(const Int &x)//��Ϊ������ʱ���������Է�������
{
	m_i += x.m_i;
	return *this;
}

Int& Int::operator-=(const Int &x)//��Ϊ������ʱ���������Է�������
{
	m_i -= x.m_i;
	return *this;
}

Int& Int::operator*=(const Int &x)//��Ϊ������ʱ���������Է�������
{
	m_i *= x.m_i;
	return *this;
}

Int& Int::operator/=(const Int &x)//��Ϊ������ʱ���������Է�������
{
	m_i /= x.m_i;
	return *this;
}

Int& Int::operator%=(const Int &x)//��Ϊ������ʱ���������Է�������
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