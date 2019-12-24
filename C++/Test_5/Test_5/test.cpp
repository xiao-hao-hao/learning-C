#include <iostream>
using namespace std;

/*
//模板就是将类型设置成一个参数的函数或类
//函数模板
//泛型 -- 不能跟类型有关系
//模板的运行效率都比较低下
// 模板不支持分离编译
template<typename Type1, typename Type2>
Type2 max(Type1 a, Type2 b);
void main()
{
cout<<max(12.34,23)<<endl;
cout<<max(10,20)<<endl;
}
*/

template<typename Type1, typename Type2>
Type2 max(Type1 a, Type2 b)
{
	cout << typeid(a).name() << endl;
	return a > b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
void main()
{
	cout << max(12.34, 23) << endl;
	cout << ::max(10, 20) << endl;
}

/*
class Test
{
	friend ostream& operator<<(ostream& out, const Test t);
public:
	Test(int d = 0) : m_data(d)
	{}
	~Test()
	{}
public:
	bool operator>(const Test &t)
	{
		return m_data > t.m_data;
	}
private:
	int m_data;
};

ostream& operator<<(ostream& out, const Test t)
{
	out << t.m_data;
	return out;
}

template<typename Type>
Type Max(Type a, Type b)
{
	cout << typeid(a).name() << endl;
	return a > b ? a : b;
}
//void main()
//{
//	cout << Max('a', 'b') << endl;
//	cout << Max(12.34, 23) << endl;
//	cout << Max<int>(10, 20) << endl;
//	Test t1(10), t2(20);
//	Max(t1, t2);
//}

void main()
{
	cout<<Max<char>('a','b')<<endl;
	cout<<Max<double>(12.34,23.45)<<endl; //23
	cout<<Max<int>(10,20)<<endl;       //20
	Test t1(10), t2(20);
	cout << Max(t1, t2) << endl;
}
*/
/*
template<class Type>
Type Max(Type a, Type b)
{
	cout << typeid(a).name() << endl;
	return a > b ? a : b;
}
void main()
{
	cout << Max('a', 'b') << endl;
	cout << Max(12.34, 23.45) << endl; //23
	cout << Max(10, 20) << endl;       //20
}
*/
/*
char Max(char a, char b)
{
	cout << typeid(a).name() << endl;
	return a > b ? a : b;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}
float Max(float a, float b)
{
	return a > b ? a : b;
}
// C++ 类型的要求更加严格
// C++

//void main()
//{
//	Max('a','b');
//	Max(12.34,23.45);
//	Max(10,20);
//}

void main()
{
	cout << Max('a', 'b') << endl;
	cout << Max(12.34, 23.45) << endl; //23
	cout << Max(10, 20) << endl;       //20
}
*/