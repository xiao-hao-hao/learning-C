#pragma once
#include <iostream>
#define __THROW_BAD_ALLOCK throw bad_alloc //定义一个抛出异常的宏

using namespace std;

#include "stl_config.h"

//一级空间配置器
template<int inst>
class __malloc_alloc_template
{
public:
	static void* allocate(size_t n)
	{
		void *result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);//表示内存不足时的申请方案out of memory
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
	//模拟set_new_handler机制
	static void(* set_malloc_handler(void(*f)()))()
	{
		void (*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}

private:
	static void* oom_malloc(size_t n);
	static void* oom_realloc(void *p, size_t n);
	static void(*__malloc_alloc_oom_handler)();//函数指针
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
		if (0 == my_malloc_handler)//如果没有利用set_new_handler机制
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
		if (0 == my_malloc_handler)//如果没有利用set_new_handler机制
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
//二级空间配置器
enum {__ALIGN = 8};//小型区块的边界值
enum {__MAX_BYTES = 128};//一级和二级的分水岭
//它们管理的字节分别为小于8字节、8字节以上16字节以下......
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};//自由链表的个数,128个字节划分为16个块

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
	static size_t ROUND_UP(size_t bytes)//提升为__ALIGIN的最小整数倍
	{
		//(ALIGIN-1) & ~(ALIGIN-1)为全0，通过加bytes产生进位，注意__ALIGIN只能是2的幂次，不能是5、6...
		//因为要保证(ALIGIN-1) & ~(ALIGIN-1)为全0
		return (((bytes) + __ALIGN-1) & ~(__ALIGN-1));
	}
	static size_t FREELIST_INDEX(size_t bytes)//得到自由列表的下标
	{
		return ((bytes)+__ALIGN-1)/__ALIGN - 1;
	}
private:
	union obj//用一个联合体实现一物二用
	{
		union obj *free_list_link;//从此处看是一个链表
		char client_data[1];      //从此处看是用户数据
	};
private:
	static obj *free_list[__NFREELISTS];//数组
private:
	//start和end之间的空间是分配了但是还没有被挂在某个节点下面的空间
	static char *start_free;
	static char *end_free;//end-start就是还没有被用到的空间
	static size_t heap_size;
};

template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::start_free = 0;
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::end_free = 0;
template<bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

//typename让编译器把obj*当做一个类型处理
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
	my_free_list = free_list + FREELIST_INDEX(n);//free_list是首元素的地址
	result = *my_free_list;
	if (result == 0)//如果没有空间
	{
		void *r = refill(ROUND_UP(n));//以8的整数倍填充空间
		return r;
	}
	//在自由链表中申请空间
	*my_free_list = result->free_list_link;
	return result;
}

template<bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	int nobjs = 20;//经验值
	char *chunk = chunk_alloc(n, nobjs);

	if (nobjs == 1)
		return chunk;//只有一个块，不需要自由链表的建立了
	//申请回来的时候如果多于一个块则形成自由链表
	obj *result = 0;
	obj **my_free_list;
	obj *cur_obj, *next_obj;

	my_free_list = free_list + FREELIST_INDEX(n);//在哪个下标下面形成自由链表
	result = (obj*)chunk;//result指向起始位置

	*my_free_list = next_obj = (obj*)(chunk + n);//这两个指针都指向下一个空间
	//一开始没有空间，经过第一次分配形成自由链表
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

//nobjs传的是引用，因为可能会改变它的值
template<bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int &nobjs)
{
	char *result;
	size_t total_bytes = size * nobjs;
	size_t byte_left = end_free - start_free;//字节的剩余
	if (byte_left >= total_bytes)
	{
		//1 空间足够
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else if (byte_left >= size)
	{
		//2 空间不足，但至少满足分配一块
		nobjs = byte_left / size;//剩余空间能分配的块数
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else
	{
		//空间不足且不满足分配一块
		size_t bytes_to_get = 2 * total_bytes;
		//因为剩下的空间和新申请的空间不连续，无法纳入内存池
		//将剩余的未使用的内存池空间进行头插链接
		if (byte_left > 0)
		{
			//计算应该头插链接的下标，比如说32计算的下标是3
			obj **my_free_list = free_list + FREELIST_INDEX(byte_left);
			//头插操作
			((obj*)start_free)->free_list_link = *my_free_list;
			*my_free_list = (obj*)start_free;
		}

		start_free = (char*)malloc(bytes_to_get);
		if (start_free == 0)
		{
			//系统内存不足
			obj **my_free_list, *p;
			//做法1：从当前要的大小开始往后面的128个字节靠近(因为后面的空间大)，找到其他的自由链表后将这个空间当做内存池重新申请空间
			for (size_t i = size; i <= __MAX_BYTES; i += __ALIGN)//要注意i是8的倍数
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if (p != 0)
				{
					*my_free_list = p->free_list_link;
					//取出一块自由链表空间作为未使用空间
					start_free = (char *)p;
					end_free = start_free + i;
					return chunk_alloc(size, nobjs);
				}
			}
			end_free = 0;
			//做法2：如果找了一圈发现内存池也没有自由链表了，寻求一级空间配置器
			//寻求一级空间配置器可能释放内存空间
			start_free = (char*)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return chunk_alloc(size, nobjs);//递归调用
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
	//一个头插
	my_free_list = free_list + FREELIST_INDEX[n];
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}

///////////////////////////////////////////////////////////////
//默认情况下调用二级空间配置器
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
	//针对的是数组
	static T* allocate(size_t n)
	{
		return 0==n ? 0 : (T*)Alloc::allocate(n * sizeof(T));
	}
	//针对的是单个对象
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