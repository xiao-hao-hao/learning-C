#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

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


//using myspace::fun;//ʹ�������ռ�ĳ�Ա����1
using namespace myspace;//ʹ�������ռ�ĳ�Ա����2
int main()
{
	cout<<"hello"<<endl;
	int a = 10;
	char ch = 'A';
	double b= 12.34;
	cin>>a;
	cout<<a<<endl;//printf("%d\n", a);
	cout<<ch<<endl;//printf("%c\n", ch);
	cout<<b<<endl;//printf("%f\n", d);
	//myspace::fun();//ʹ�������ռ�ĳ�Ա����3
	fun();
	yourspace::fun();
	TestFunc();
	TestFunc(10);
}