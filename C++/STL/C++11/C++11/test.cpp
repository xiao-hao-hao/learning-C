#include <iostream>
#include <functional>
#include <algorithm>
#include <thread>
#include <Windows.h>
using namespace std;

void thread_fun(int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << "This is Child Thread." << endl;
	}
	Sleep(2000);
	cout << "Child Thread End." << endl;
}
struct ThreadObj
{
	void operator()(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "This is Child Thread." << endl;
		}
		Sleep(2000);
		cout << "Child Thread End." << endl;
	}
};
void main()
{
	thread th(thread_fun, 10);
	//th.detach();
	//thread th(ThreadObj(), 10);
	//thread th([]{cout<<"This is Child Thread Lamuda."<<endl;});
	thread &&th1 = move(th);
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Main Thread." << endl;
	}
	th.join();
	cout << "Main Thread End." << endl;
}


/*
int main()
{
	std::thread t1;
	cout << t1.get_id() << endl;
	return 0;
}

/*
void thread_fun()
{
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Child Thread." << endl;
	}
	Sleep(2000);
	cout << "Child Thread End." << endl;
}
void main()
{
	thread th(thread_fun);
	th.detach();
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Main Thread." << endl;
	}
	Sleep(5000);
	cout << "Main Thread End." << endl;
}

/*
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};

int main()
{
	// 函数对象
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	return 0;
}

/*
void main()
{
	auto f1 = []{cout << "This is f1." << endl;};  //匿名函数
	auto f2 = []{cout << "This is f2." << endl;};
	f1();
	f2();
	cout << typeid(f1).name() << endl;
	//f1 = f2;
	auto f3 = f1;
	f3();
	void(*pfun)() = f1;
	pfun();
}

/*
int z = 300;
void main()
{
	int x = 100;
	int y = 200;
	auto fun = [=](int a, int b)->int
	{
		//x = 1;
		//y = 2;
		z = 3;
		return a + b + x + y + z;
	};   //value

	cout << fun(10, 20) << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
}

/*
// []()->{}
int z = 300;
void main()
{

	int x = 100;
	int y = 200;
	auto fun = [x, y](int a, int b)->int
	{
		return a + b + x + y + z;
	};
	cout << fun(10, 20) << endl;
	cout << "x = " << x << endl;
}

/*
void main()
{
	auto fun = []{cout << "This is Lamuda ." << endl; };
	fun();
}

/*
struct Goods
{
	string _name;
	double _price;
};
void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds + n, [](const Goods &gds1, const Goods &gds2)->bool{return gds1._price < gds2._price;});
}

/*
struct Goods
{
	string _name;
	double _price;
};
struct Compare
{
	bool operator()(const Goods &gds1, const Goods &gds2)const
	{
		return gds1._price < gds2._price;
	}
};
void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds + n, Compare());
}

/*
struct Goods
{
	string _name;
	double _price;
	bool operator<(const Goods &gds)const
	{
		return _price < gds._price;
	}
};
void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds + n, less<Goods>());
}

/*
void  main()
{
	int ar[] = { 43, 432, 32, 4, 3, 21, 9, 0, 7, 8, 6, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);
	//sort(ar, ar+n); //
	sort(ar, ar + n, greater<int>());
}

/*
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}
void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}
void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}
void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}
template<typename T>
void PerfectForward(T &&t)
{
	cout << typeid(t).name() << endl;
	Fun(forward<T>(t));           //完美转发
	//Fun(t);
}
int main()
{
	PerfectForward(10); // rvalue ref
	int a = 10;
	PerfectForward(a); // lvalue ref
	PerfectForward(move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(move(b)); // const rvalue ref
	return 0;
}
/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s) : _str(new char[strlen(s._str) + 1])//普通拷贝构造
	{
		strcpy(_str, s._str);
	}
	String(String &&s) : _str(s._str)//右值拷贝构造
	{
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		delete[]pTemp;
		return strRet;
	}
	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};
class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(Person && p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}

void fun(const int &a)
{
	cout << a << endl;
}


void main()
{
	String s1("Hello");
	String s2("Bit.");
	String s3 = s1 + s2;
	String s4 = s3;
}

/*
void main()
{
String s1("Hello");
String s2(move(s1));
}


/*
void main()
{
String s1("Hello");
String s2("Bit.");
String s3 = s1 + s2;
const int &a = 10;
int &&b = 10;
}
*/