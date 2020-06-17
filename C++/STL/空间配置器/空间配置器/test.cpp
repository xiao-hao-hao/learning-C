//#include "stl_alloc.h"
#include "stl_vector.h"

void main()
{
	vector<int> iv;
}

/*
int main()
{
	//4�ֽڼ�������±���0����
	int *ptr = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	//16�ֽڼ�������±���7����
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
	//Ҫ������ռ�֮ǰ���ã�������ʧ���������þ�û��������
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
//һ���򵥵Ŀռ�������
namespace bit
{
	template<class T>
	T* _allocate(size_t size, T*)//����T*�ж�T����
	{
		//T��һ���ڵ�����
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
		//��λnew����p��ָ�Ŀռ乹��T1���󣬰�T2��value�������ĳ�ʼֵ
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
		//Ϊ������ȡ��׼��
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference_type;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef size_t difference_type;
	public:
		pointer allocate(size_type n, const void *hint=0)//����ռ�
		{
			return _allocate(n, (pointer)0);
		}
		void  deallocate(pointer p, size_type n)//�ͷſռ�
		{
			_deallocate(p);
		}
		//�������
		void construct(pointer  p, const T& value)//�����˿ռ�󣬽�����ŵ��ռ���ȥ
		{
			_construct(p, value);
		}
		//��������
		void destroy(pointer p)//�ݻٷ���
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