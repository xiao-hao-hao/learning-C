#include <malloc.h>
//#include <vld.h>
#include <assert.h>
#include <iostream>
using namespace std;


class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0) : m_data(data)
	{
		cout << "Create Test Object." << endl;
	}
	~Test()
	{
		cout << "Free Test Object." << endl;
	}
private:
	int m_data;
};
/*
void main()
{
	//空间配置器
	Test *pt = (Test *)malloc(sizeof(Test));
	new(pt) Test;
}
*/


void* operator new(size_t sz, int *ptr, int pos)
{
	//return (ptr + pos);
	return &ptr[pos];
}
void main()
{
	//int ar[10] = {0};
	int *ar = (int*)malloc(sizeof(int)*10);
	new(ar, 0)  int(1); //  new(ptr) object(value)
	new(ar, 8)  int(2);
	new(ar, 5)  int(3);
	new(ar, 3)  int(4);
}


/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0) : m_data(data)
	{
		cout << "Create Test Object." << endl;
	}
	~Test()
	{
		cout << "Free Test Object." << endl;
	}
private:
	int m_data;
};

int main()
{
	//不会调用构造函数和析构函数
	Test *pt = (Test*)operator new(sizeof(Test));//malloc
	operator delete(pt);//free
	return 0;
}
*/

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0) : m_data(data)
	{ 
		cout << "Create Test Object." << endl;
	}
	~Test()
	{
		cout << "Free Test Object." << endl;
	}

//public:
//	void* operator new(size_t sz)//在类中的重载只会影响到这一个类
//	{
//		void *ptr = malloc(sz);
//		assert(ptr != nullptr);
//		return ptr;
//	}
//
//	void operator delete(void *ptr)
//	{
//		cout << "111111111111111" << endl;
//		free(ptr);
//	}
	
private:
	int m_data;
};
ostream& operator<<(ostream &out, const Test &t)
{
	out << t.m_data;
	return out;
}
//针对的是单个对象
void* operator new(size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}

void operator delete(void *ptr)
{
	cout << "111111111111111" << endl;
	free(ptr);
}


//针对的是数组对象
void* operator new[](size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}
void operator delete[](void *ptr)
{
	cout << "22222222222222222" << endl;
	free(ptr);
}

//class Test1
//{
//	friend ostream& operator<<(ostream &out, const Test &t);
//public:
//	Test1(int data = 0) : m_data(data)
//	{
//		cout << "Create Test Object." << endl;
//	}
//	~Test1()
//	{
//		cout << "Free Test Object." << endl;
//	}
//private:
//	int m_data;
//};

int main()
{
	Test *pt = new Test;//会自动计算大小
	delete pt;
	Test *pt2 = new Test[10];
	delete[] pt2;
	//Test1 *pt1 = new Test1;
	//delete pt1;
	return 0;
}
*/

/*
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
public:
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	Test *p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	Test *p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}

void Test2()
{
	Test *p1 = new Test;
	delete p1;
	Test *p2 = new Test[10];
	delete[] p2;
}

int main()
{
	//Test1();
	Test2();
	return 0;
}
*/

/*
int main()
{
	//int *p1 = (int*)calloc(4, sizeof(int));
	//int *p2 = (int*)malloc(sizeof(int));
	int *p3 = (int*)_alloca(4);
	return 0;
}
*/