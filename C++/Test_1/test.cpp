#include <iostream>

using namespace std;
/*
namespace myspace
{
	int a = 10;
	int b = 20;
	void fun()
	{
		cout<<"This is fun 1"<<endl;
	}
	void show()
	{
		cout<<"This is show"<<endl;
	}
}

namespace yourspace
{
	void fun()
	{
		cout<<"This is fun 2"<<endl;
	}
}

//void fun()
//{
//	cout<<"This is fun 3"<<endl;
//}
void TestFunc(int a = 0);//ȱʡ���������������Ͷ�����ͬʱ���֣���ʹһ��Ҳ����
void TestFunc(int a)
{
	cout<<a<<endl;
}

int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

long Add(long left, long right)
{
	return left + right;
}

//�������������޷��γ�����
void TestFunc1(int a = 10)
{
	cout<<"void TestFunc(int)"<<endl;
}

//void TestFunc1(int a)
//{
//	cout<<"void TestFunc(int)"<<endl;
//}

extern "C" int ADD(int left, int right)
{
	return 0;
}
//int ADD(int left, int right);
//using myspace::fun;//ʹ�������ռ�ĳ�Ա����1
using namespace myspace;//ʹ�������ռ�ĳ�Ա����2


int main()
{
	cout<<"hello"<<endl;
	int a = 10;
	char ch = 'A';
	double b= 12.34;
	//cin>>a;
	//cout<<a<<endl;//printf("%d\n", a);
	//cout<<ch<<endl;//printf("%c\n", ch);
	//cout<<b<<endl;//printf("%f\n", d);
	//myspace::fun();//ʹ�������ռ�ĳ�Ա����3
	fun();
	yourspace::fun();
	TestFunc();
	TestFunc(10);
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	ADD(1, 2);
	TestFunc1();

	double d = 12.34;
	const int &rd = d;
	//int &rd = d;//�������Ͳ�ͬ
	return 0;
}
*/

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int &ret = Add(1, 2);
	Add(3, 4);
	cout<<"Add(1, 2) is :"<<ret<<endl;
	double d = 12.34;
	const int &rd = d;
	cout << rd << endl;
	return 0;
}