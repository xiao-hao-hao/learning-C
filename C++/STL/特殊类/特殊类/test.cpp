#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <vld.h>
#include <assert.h>

using namespace std;

class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	explicit A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	A tmp(1); 
	A a2 = tmp;
	//A a2 = 1;
}

/*
class A
{
public:
	virtual void f(){}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a);
	cout << &b << endl;
	fun(&b);
	return 0;
}

/*
int main()
{
	double d = 12.34;
	//int *pd = &d;
	//int *pd = static_cast<int*>(&d);
	int *pd = reinterpret_cast<int*>(&d);
	return 0;
}

/*
//不是线程安全
template<typename T>
class LASingletonTemplateBase
{
private:
	static T* sm_instance;
protected:
	LASingletonTemplateBase()
	{
		assert(sm_instance == 0);
		sm_instance = static_cast<T*>(this);//类型转换
	}
	virtual ~LASingletonTemplateBase()
	{
		assert(sm_instance != 0);
		sm_instance = 0;
	}
public:
	static T* get_instance_ptr()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return sm_instance;
	}
	static T& get_instance_ref()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return *sm_instance;
	}
	static void remove_instance()
	{
		assert(sm_instance);
		if (sm_instance)
		{
			delete sm_instance;
			sm_instance = nullptr;
		}
		assert(sm_instance == 0);
	}
};
template<typename T>
T* LASingletonTemplateBase<T>::sm_instance = 0;
class Test
{};
class Test2
{};
void main()
{
	Test *pt1 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test *pt2 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test *pt3 = LASingletonTemplateBase<Test>::get_instance_ptr();
	Test2 *pt4 = LASingletonTemplateBase<Test2>::get_instance_ptr();
	LASingletonTemplateBase<Test>::remove_instance();
	LASingletonTemplateBase<Test2>::remove_instance();
}

/*
mutex mt;
//不是线程安全
class Singleton
{
public:
	static Singleton* Instance()
	{
		if (_instance == nullptr)  //双检锁  //双检机制
		{
			mt.lock();
			if (_instance == nullptr)
			{
				_instance = new Singleton;
			}
			mt.unlock();
		}

		return _instance;
	}
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::_instance)
				delete Singleton::_instance;
		}
	static CGarbo Garbo;
	};
protected:
	Singleton()
	{
		cout << "Create Singleton Obj." << endl;
	}
private:
	static Singleton* _instance;
};
Singleton::CGarbo Garbo;
Singleton* Singleton::_instance = nullptr;
void thread_fun(int n)
{
	for (int i = 0; i<n; ++i)
	{
		Singleton *ps = Singleton::Instance();
		cout << "ps = " << ps << endl;   //一样
	}
}
void main()
{
	thread t1(thread_fun, 10);
	thread t2(thread_fun, 10);
	t1.join();
	t2.join();
}

/*
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton()
	{
		cout << "Create Singleton Obj." << endl;
	}
	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton m_instance;
};
Singleton Singleton::m_instance;
//饿汉模式
void main()
{
	Singleton *ps = Singleton::GetInstance();
	Singleton *ps1 = Singleton::GetInstance();
	Singleton *ps2 = Singleton::GetInstance();
	system("pause");
}


/*
class NonInherit final
{
public:
};
class Test : public NonInherit
{};
void main()
{
	Test t;
}

/*
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit();
};
class Test : public NonInherit
{};
void main()
{
	Test t;
}

/*
class noncopyable
{
protected:
	noncopyable() {}
	~noncopyable() {}
private:  // emphasize the following members are private
	noncopyable(const noncopyable&);
	const noncopyable& operator=(const noncopyable&);
};
class Test : public noncopyable
{
public:
	Test(int data = 0) :m_data(data)
	{}
	Test(const Test &t)
	{
		m_data = t.m_data;
	}
private:
	int m_data = 0;
};
void main()
{
	Test t1;
	Test t2 = t1;
	Test t3;
	//t3 = t1;
}

/*
class Test
{
public:
	static Test* GetInstance()
	{
		return new Test;
	}
public:
	void fun()
	{
		cout << "Test::fun()" << endl;
	}
private:
	Test()
	{}
private:
	int m_data = 0;
};
void main()
{
	Test *pt = Test::GetInstance();
	pt->fun();
}

/*
class File
{
public:
	File(const char *path)
	{
		cout << "Open File." << endl;
		fp = fopen(path, "r");
	}
	~File()
	{
		cout << "Close File." << endl;
		fclose(fp);
	}
private:
	FILE *fp;
};
void main()
{
	shared_ptr<File> sp(new File("C:\\Users\\Administrator\\Desktop\\1.txt"));//放的是结构体变量的指针
}

/*
FILE* OpenFile(const char *path)
{
FILE *p = new FILE;
cout << "Open File." << endl;
p = fopen(path, "r");
return p;
}
void CloseFile(FILE *fp)
{
fclose(fp);
cout << "Close File." << endl;
}
void main()
{
FILE *fp = OpenFile("C:\\Users\\Administrator\\Desktop\\1.txt");
shared_ptr<FILE> sp(fp, CloseFile); //通用
}

/*
template<class T>
struct FreeFunc
{
void operator()(T* ptr)
{
cout << "free:" << ptr << endl;
free(ptr);
}
};
template<class T>
struct DeleteArrayFunc
{
void operator()(T* ptr)
{
cout << "delete[]:" << ptr << endl;
delete[] ptr;
}
};

void main()
{
//int *p = (int *)malloc(4);
int *p = new int(6);
//cout << (*p = 6) << endl;
shared_ptr<int> sp1(p);
shared_ptr<int> sp3;
sp3 = sp1;
shared_ptr<int> sp2(new int(4));
sp1 = sp2;
*p = 5;
}

/*
void main()
{
FreeFunc<int> freeFunc;
int *p = (int *)malloc(4);
cout << (*p = 6) << endl;
shared_ptr<int> sp1(p, freeFunc);
cout << sp1.use_count();
DeleteArrayFunc<int> deleteArrayFunc;
shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
sp1 = sp2;
*p = 5;
//cout << "p = " << p << endl;
//shared_ptr<int> sp1(p, freeFunc);//先构造后释放
//DeleteArrayFunc<int> deleteArrayFunc;
//shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
}

/*
struct ListNode
{
int _data;
weak_ptr<ListNode> _prev;
weak_ptr<ListNode> _next;
~ListNode()
{
cout << "~ListNode()" << endl;
}
};
void main()
{
shared_ptr<ListNode> node1(new ListNode);
shared_ptr<ListNode> node2(new ListNode);
cout << node1.use_count() << endl;
cout << node2.use_count() << endl;
node1->_next = node2;  //循环引用导致节点不能释放
node2->_prev = node1;  //避免循环引用 智能指针
cout << node1.use_count() << endl;
cout << node2.use_count() << endl;
}

/*
//auto_ptr unique_ptr  shared_ptr
void main()
{
shared_ptr<int> sp(new int(10));
shared_ptr<int> sp1 = sp;
shared_ptr<int> sp2;
sp2 = sp1;
cout << "use count = " << sp.use_count() << endl;

//弱指针
weak_ptr<int> wp = sp;
cout << "use count = " << sp.use_count() << endl;
weak_ptr<int> wp1 = wp;
cout << "weak use_count = " << wp.use_count() << endl;
if (!wp.expired())//指向的对象是否已被销毁
{
shared_ptr<int> sp3 = wp.lock();
cout << "use count = " << sp.use_count() << endl;
}
cout << "use count = " << sp.use_count() << endl;
}
*/