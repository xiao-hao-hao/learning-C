//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Base1
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base, public Base1
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Derive::Func()" << endl;
//	}
//	void Func5()
//	{
//		cout << "Derive::Func()" << endl;
//	}
//private:
//	int _d = 2;
//
//};
//int main()
//{
//	//Base b;
//	Derive d;
//	//Base *pb = &d;
//	//pb->Func3();
//	//d.Func3();
//	cout << sizeof(Derive) << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
class Person {
public:
	//virtual Person& show(){ cout << "Base::show()" << endl; return *this; }
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	//virtual Student& show(){ cout << "D::show()" << endl; return *this; }
	virtual ~Student() { cout << "~Student()" << endl; }
};

int main()
{

	Person* p1 = new Student;
	delete p1;
	//Student p;
	//Person *ps = &p;
	//ps->show();
	return 0;
}