//#include "stl_alloc.h"
#include "stl_vector.h"

void main()
{
	vector<int> iv;
}

/*
int main()
{
	//4字节计算出的下标在0下面
	int *ptr = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	//16字节计算出的下标在7下面
	int *ptr1 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int) * 16);
	int *ptr2 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)* 24);
	return 0;
}

/*
void OutOfMemory()
{
	cout << "Out Of Memory" << endl;
	exit(1);
}

int main()
{
	//要在申请空间之前设置，当申请失败了再设置就没有意义了
	__malloc_alloc_template<0>::set_malloc_handler(OutOfMemory);
	try
	{
		int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int)*2);
	}
	catch (bad_alloc &e)
	{
		cout << e.what() <<endl;
	}
	return 0;
}

/*
void main()
{
	try
	{
		int *p = new int[507374102];
		cout << "new OK" << endl;
		delete []p;
	}
	catch(bad_alloc &e)
	{
		cout << e.what() << endl;
	}
}

/*
//一个简单的空间配置器
namespace bit
{
	template<class T>
	T* _allocate(size_t size, T*)//根据T*判断T类型
	{
		//T是一个节点类型
		cout << typeid(T).name() << endl;
		T *tmp = (T*)(::operator new(size * sizeof(T)));
		if (tmp == 0)
		{
			cout << "Out of Memory." << endl;
			exit(1);
		}
		return tmp;
	}
	template<class T>
	void _deallocate(T *buffer)
	{
		::operator delete(buffer);
	}
	template<class T1, class T2>
	void _construct(T1 *p, const T2 &value)
	{
		//定位new，在p所指的空间构造T1对象，把T2的value当做它的初始值
		new(p) T1(value);
	}
	template<class T>
	void _destroy(T *ptr)
	{
		ptr->~T();
	}
	template<class T>
	class alloctor
	{
	public:
		//为类型萃取做准备
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference_type;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef size_t difference_type;
	public:
		pointer allocate(size_type n, const void *hint=0)//申请空间
		{
			return _allocate(n, (pointer)0);
		}
		void  deallocate(pointer p, size_type n)//释放空间
		{
			_deallocate(p);
		}
		//构造对象
		void construct(pointer  p, const T& value)//申请了空间后，将对象放到空间中去
		{
			_construct(p, value);
		}
		//析构对象
		void destroy(pointer p)//摧毁方法
		{
			_destroy(p);
		}
	};
}

int main()
{
	//list<int> lt;
	list<int, bit::alloctor<int>> lt;
	return 0;
}
*/