#define _CRT_SECURE_NO_WARNINGS 1

//写一个宏，计算结构体中某变量相对于首地址的偏移量，
//并给出说明  考察offsetof宏的实现

////offsetof的使用
//#include <stdio.h>
//#include <stddef.h>
//
//struct S
//{
//	char ch1;//0
//	//1-3
//	int a;//4-7
//	char ch2;//8
//	//9-11
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, ch1));
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, ch2));
//	return 0;
//}

//offsetof宏的实现
//#include <stdio.h>
//#define OffSetOf(s, m) ((size_t)&(((s *)0)->m))//m的地址就是m和结构体首地址的偏移量(在0地址处只要不解引用取值就可以)
//
//struct S
//{
//	char ch1;//0
//	//1-3
//	int a;//4-7
//	char ch2;//8
//	//9-11
//};
//
//int main()
//{
//	printf("%d\n", OffSetOf(struct S, ch1));
//	printf("%d\n", OffSetOf(struct S, a));
//	printf("%d\n", OffSetOf(struct S, ch2));
//	return 0;
//}

//模拟实现memset
//#include <assert.h>
//
//void * my_memmove(void *dst, const void *src, size_t count)
//{
//	assert(dst && src);
//	if (dst < src)//前->后
//	{
//		while (count--)
//		{
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst + 1;
//			++(char *)dst;
//			++(char *)src;
//		}
//	}
//	else//后->前
//	{
//		while (count--)
//		{
//			*((char *)dst + count) = *((char *)src + count);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	my_memmove(arr + 2, arr, 16);
//	return 0;
//}

#include <stdio.h>
#include <assert.h>

void * my_memset(void *dest, int c, int count)
{
	void *ret = dest;
	assert(dest);
	while (count--)
	{
		*(char *)dest = c;
		dest = (char *)dest + 1;
	}
}

int main()
{
	char arr[] = "hello xiaohaohao!";
	printf("Before: %s\n", arr);
	my_memset(arr, '&', 4);
	printf("After: %s\n", arr);
	return 0;
}