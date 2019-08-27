#define _CRT_SECURE_NO_WARNINGS 1

//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ������
//������˵��  ����offsetof���ʵ��

////offsetof��ʹ��
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

//offsetof���ʵ��
//#include <stdio.h>
//#define OffSetOf(s, m) ((size_t)&(((s *)0)->m))//m�ĵ�ַ����m�ͽṹ���׵�ַ��ƫ����(��0��ַ��ֻҪ��������ȡֵ�Ϳ���)
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

//ģ��ʵ��memset
//#include <assert.h>
//
//void * my_memmove(void *dst, const void *src, size_t count)
//{
//	assert(dst && src);
//	if (dst < src)//ǰ->��
//	{
//		while (count--)
//		{
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst + 1;
//			++(char *)dst;
//			++(char *)src;
//		}
//	}
//	else//��->ǰ
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