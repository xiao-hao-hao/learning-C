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
void TestFunc(int a = 0);//缺省参数不能在声明和定义中同时出现，即使一样也不行
void TestFunc(int a)
{
	cout<<a<<endl;
}


//using myspace::fun;//使用命名空间的成员方法1
using namespace myspace;//使用命名空间的成员方法2
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
	//myspace::fun();//使用命名空间的成员方法3
	fun();
	yourspace::fun();
	TestFunc();
	TestFunc(10);
}