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
/*
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
*/

/*
#include <time.h>

struct A
{
	int a[10000];
};

void TestFunc1(A a)
{}

void TestFunc2(A &a)
{}

void Test()
{
	A a;
	//��ֵ��Ϊ��������
	size_t begin1 = clock();
	for(size_t i = 0; i < 10000000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	//��������Ϊ��������
	size_t begin2 = clock();
	for(size_t i = 0; i < 10000000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();

	//�ֱ����������������ʱ��
	cout << "TestFunc1(A a)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A &a)-time:" << end2 - begin2 << endl;
}

int main()
{
	Test();
	return 0;
}
*/
/*
#include <time.h>

struct A
{
	int a[10000];
};

A a;

A TestFunc1()
{
	return a;
}

A& TestFunc2()
{
	return a;
}

void Test()
{
	A a;
	//��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for(size_t i = 0; i < 100000; ++i)
	{
		TestFunc1();
	}
	size_t end1 = clock();

	//��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for(size_t i = 0; i < 100000; ++i)
	{
		TestFunc2();
	}
	size_t end2 = clock();

	//�ֱ����������������ʱ��
	cout << "TestFunc1()-time:" << end1 - begin1 << endl;
	cout << "TestFunc2()-time:" << end2 - begin2 << endl;
}

int main()
{
	Test();
	return 0;
}
*/

//int main()
//{
//	int a = 10;
//	int &ra = a;
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	return 0;
//}

//int main()
//{
//	double a = 10;
//	double &ra = a;
//	ra = 20;
//	double *pa = &a;
//	*pa = 20;
//	int b[10];
//	//int (&rb)[10] = b;
//	//int &rb = b[0];
//	cout << sizeof(ra) << " " << sizeof(pa) << " "<< sizeof(rb) << endl;
//	return 0;
//}
/*
int main()
{
	double a = 12.34;
	//int &ra = (int)a;//����
	//int &ra = (int&)a;//������
	//int &ra = a;//����
	const int &ra = a;
	a = 18.99;
	cout <<  a << " " << ra << endl;
	return 0;
}
*/

//#include "test1.h"
////inline int Add(int left, int right);
//
////int Add(int left, int right)
////{
////	return left + right;
////}
//
//int main()
//{
//	int ret = 0;
//	auto a = ret;
//	ret = Add(1, 2);
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto *b = &x;
//	auto c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

void TestFor()
{
	int array[] = {1, 2, 3, 4, 5};
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
		array[i] *= 2;
	for(int *p = array; p < array + sizeof(array)/sizeof(array[0]); ++p)
		cout << *p << endl;
}

void TestFor_1()
{
	int ar[] = {1, 2, 3, 4, 5};
	for(auto &e : ar)
		e *= 2;
	for(auto e : ar)
		cout << e << endl;
}

int main()
{
	//TestFor();
	TestFor_1();
	return 0;
}

/*
void f(int)
{
	cout << "f(int)" << endl;
}

void f(char*)
{
	cout << "f(int*)" << endl;
}

void f(nullptr_t)//��û��������غ�����ʱ��f(nullptr)������������Ϊָ�����������νʲôָ�룩�����غ�������������ж������ʱ�ᱨ��
{
	cout << "f(nullptr_t)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	//f((int*)NULL);
	cout << sizeof(nullptr) <<endl;
	f(nullptr);
	return 0;
}
*/