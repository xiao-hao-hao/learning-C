#pragma once
#include <iostream>
#define __THROW_BAD_ALLOCK throw bad_alloc //����һ���׳��쳣�ĺ�

using namespace std;

#include "stl_config.h"

//һ���ռ�������
template<int inst>
class __malloc_alloc_template
{
public:
	static void* allocate(size_t n)
	{
		void *result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);//��ʾ�ڴ治��ʱ�����뷽��out of memory
		return result;
	}
	static void* reallocate(void *p, size_t old_sz, size_t new_sz)
	{
		void *result = realloc(p, new_sz);
		if (0 == result)
			result = oom_realloc(p, new_sz);
		return result;
	}
	static void deallocate(void *p, size_t n)
	{
		free(p);
	}
	//ģ��set_new_handler����
	static void(* set_malloc_handler(void(*f)()))()
	{
		void (*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}

private:
	static void* oom_malloc(size_t n);
	static void* oom_realloc(void *p, size_t n);
	static void(*__malloc_alloc_oom_handler)();//����ָ��
};

template<int inst>
void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void(*my_malloc_handler)();
	void *result;
	for (;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)//���û������set_new_handler����
		{
			__THROW_BAD_ALLOCK();
		}
		my_malloc_handler();
		result = malloc(n);
		if (result)
			return result;
	}
}

template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
	void(*my_malloc_handler)();
	void *result;
	for (;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)//���û������set_new_handler����
		{
			__THROW_BAD_ALLOCK();
		}
		my_malloc_handler();
		result = realloc(p, n);
		if (result)
			return result;
	}
}

typedef __malloc_alloc_template<0> malloc_alloc;

//////////////////////////////////////////////////////////////////////////////////////////////
//�����ռ�������
enum {__ALIGN = 8};//С������ı߽�ֵ
enum {__MAX_BYTES = 128};//һ���Ͷ����ķ�ˮ��
//���ǹ�����ֽڷֱ�ΪС��8�ֽڡ�8�ֽ�����16�ֽ�����......
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};//��������ĸ���,128���ֽڻ���Ϊ16����

template<bool thread, int inst>
class __default_alloc_template
{
public:
	static void* allocate(size_t n);
	static void deallocate(void *p, size_t n);
	static void* reallocate(void *p, size_t old_sz, size_t new_sz);
public:
	static void* refill(size_t n);
	static char* chunk_alloc(size_t size, int &nobjs);
private:
	static size_t ROUND_UP(size_t bytes)//����Ϊ__ALIGIN����С������
	{
		//(ALIGIN-1) & ~(ALIGIN-1)Ϊȫ0��ͨ����bytes������λ��ע��__ALIGINֻ����2���ݴΣ�������5��6...
		//��ΪҪ��֤(ALIGIN-1) & ~(ALIGIN-1)Ϊȫ0
		return (((bytes) + __ALIGN-1) & ~(__ALIGN-1));
	}
	static size_t FREELIST_INDEX(size_t bytes)//�õ������б���±�
	{
		return ((bytes)+__ALIGN-1)/__ALIGN - 1;
	}
private:
	union obj//��һ��������ʵ��һ�����
	{
		union obj *free_list_link;//�Ӵ˴�����һ������
		char client_data[1];      //�Ӵ˴������û�����
	};
private:
	static obj *free_list[__NFREELISTS];//����
private:
	//start��end֮��Ŀռ��Ƿ����˵��ǻ�û�б�����ĳ���ڵ�����Ŀռ�
	static char *start_free;
	static char *end_free;//end-start���ǻ�û�б��õ��Ŀռ�
	static size_t heap_size;
};

template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::start_free = 0;
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::end_free = 0;
template<bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

//typename�ñ�������obj*����һ�����ʹ���
template<bool threads, int inst>
typename __default_alloc_template<threads, inst>::obj*
__default_alloc_template<threads, inst>::free_list[__NFREELISTS] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::allocate(size_t n)
{
	obj **my_free_list;
	obj *result = 0;
	if (n > __MAX_BYTES)
		return malloc_alloc::allocate(n);
	my_free_list = free_list + FREELIST_INDEX(n);//free_list����Ԫ�صĵ�ַ
	result = *my_free_list;
	if (result == 0)//���û�пռ�
	{
		void *r = refill(ROUND_UP(n));//��8�����������ռ�
		return r;
	}
	//����������������ռ�
	*my_free_list = result->free_list_link;
	return result;
}

template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	int nobjs = 20;//����ֵ
	char *chunk = chunk_alloc(n, nobjs);

	if (nobjs == 1)
		return chunk;//ֻ��һ���飬����Ҫ��������Ľ�����
	//���������ʱ���������һ�������γ���������
	obj *result = 0;
	obj **my_free_list;
	obj *cur_obj, *next_obj;

	my_free_list = free_list + FREELIST_INDEX(n);//���ĸ��±������γ���������
	result = (obj*)chunk;//resultָ����ʼλ��

	*my_free_list = next_obj = (obj*)(chunk + n);//������ָ�붼ָ����һ���ռ�
	//һ��ʼû�пռ䣬������һ�η����γ���������
	for (int i = 1; ; ++i)
	{
		cur_obj = next_obj;
		next_obj = (obj*)((char*)next_obj + n);
		if (nobjs - 1 == i)
		{
			cur_obj->free_list_link = 0;
			break;
		}
		else
			cur_obj->free_list_link = next_obj;
	}
	return result;
}

//nobjs���������ã���Ϊ���ܻ�ı�����ֵ
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int &nobjs)
{
	char *result;
	size_t total_bytes = size * nobjs;
	size_t byte_left = end_free - start_free;//�ֽڵ�ʣ��
	if (byte_left >= total_bytes)
	{
		//1 �ռ��㹻
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else if (byte_left >= size)
	{
		//2 �ռ䲻�㣬�������������һ��
		nobjs = byte_left / size;//ʣ��ռ��ܷ���Ŀ���
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else
	{
		//�ռ䲻���Ҳ��������һ��
		size_t bytes_to_get = 2 * total_bytes;
		//��Ϊʣ�µĿռ��������Ŀռ䲻�������޷������ڴ��
		//��ʣ���δʹ�õ��ڴ�ؿռ����ͷ������
		if (byte_left > 0)
		{
			//����Ӧ��ͷ�����ӵ��±꣬����˵32������±���3
			obj **my_free_list = free_list + FREELIST_INDEX(byte_left);
			//ͷ�����
			((obj*)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj*)start_free;
		}

		start_free = (char*)malloc(bytes_to_get);
		if (start_free == 0)
		{
			//ϵͳ�ڴ治��
			obj **my_free_list, *p;
			//����1���ӵ�ǰҪ�Ĵ�С��ʼ�������128���ֽڿ���(��Ϊ����Ŀռ��)���ҵ��������������������ռ䵱���ڴ����������ռ�
			for (size_t i = size; i <= __MAX_BYTES; i += __ALIGN)//Ҫע��i��8�ı���
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if (p != 0)
				{
					*my_free_list = p->free_list_link;
					//ȡ��һ����������ռ���Ϊδʹ�ÿռ�
					start_free = (char *)p;
					end_free = start_free + i;
					return chunk_alloc(size, nobjs);
				}
			}
			end_free = 0;
			//����2���������һȦ�����ڴ��Ҳû�����������ˣ�Ѱ��һ���ռ�������
			//Ѱ��һ���ռ������������ͷ��ڴ�ռ�
			start_free = (char*)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return chunk_alloc(size, nobjs);//�ݹ����
	}
}

template<bool threads, int inst>
void __default_alloc_template<threads, inst>::deallocate(void *p, size_t n)
{
	obj *q = (obj*)p;
	obj **my_free_list;
	if (n > __MAX_BYTES)
	{
		malloc_alloc::deallocate(p, n);
		return;
	}
	//һ��ͷ��
	my_free_list = free_list + FREELIST_INDEX[n];
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}

///////////////////////////////////////////////////////////////
//Ĭ������µ��ö����ռ�������
#ifdef __USE_MALLOC
typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0,0> alloc;
#endif

template<class T, class Alloc>
class simple_alloc
{
public:
	//��Ե�������
	static T* allocate(size_t n)
	{
		return 0==n ? 0 : (T*)Alloc::allocate(n * sizeof(T));
	}
	//��Ե��ǵ�������
	static T* allocate(void)
	{
		return (T*)Alloc::allocate(sizeof(T));
	}
	static void deallocate(T *p, size_t n)
	{
		if (0 != n)
			Alloc::deallocate(p, n * sizeof(T));
	}
	static void deallocate(T *p)
	{
		Alloc::deallocate(p, sizeof(T));
	}
};