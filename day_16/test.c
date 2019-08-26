#define _CRT_SECURE_NO_WARNINGS 1

//1.实现strcpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strlen(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "hello world";
//	char *str = my_strlen(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//2.实现strcat
//#include <stdio.h>
//#include <assert.h>
//
//char *my_strcat(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while(*dst)
//	{
//		++dst;
//	}
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "hello ";
//	char *str2 = "world!";
//	char *str = my_strcat(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//3.实现strstr 
//#include <stdio.h>
//#include <assert.h>
//
//char *my_strstr(const char *str1, const char *str2)
//{
//	const char *start = str1;
//	const char *p1 = str1;
//	const char *p2 = str2;
//	assert(str1 && str2);
//	while (*start)
//	{
//		p1 = start;
//		p2 = str2;
//		while (*p1 == *p2 && *p1 && *p2)
//		{
//			++p1;
//			++p2;
//		}
//		if ('\0' == *p2)
//		{
//			return (char *)start;
//		}
//		++start;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *str1 = "ahbgdjydrdhdjdngd";
//	char *str2 = "";
//	char *str = my_strstr(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//4.实现strchr
//#include <stdio.h>
//#include <assert.h>
//
//char * my_strchr(const char *str, const char ch)
//{
//	assert(*str);
//	while (*str && *str != ch)
//	{
//		str++;
//	}
//	if (*str == ch)
//	{
//		return (char *)str;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *str1 = "abcdefghi";
//	char *str = my_strchr(str1, 'a');
//	printf("%s\n", str);
//	return 0;
//}

//5.实现strcmp
//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char *str1, const char *str2)
//{
//	assert(*str1 && *str2);
//	while (*str1 == *str2 && *str1 && str2)
//	{
//		str1++;
//		str2++;
//	}
//	if (*str1 == *str2)
//	{
//		return 0;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	char *str1 = "aecd";
//	char *str2 = "accd";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}

//6.实现memcpy
//#include <stdio.h>
//#include <assert.h>
//
//void * my_memcpy(void *dst, void *src, size_t count)
//{
//	void *ret = dst;
//	assert(dst && src);
//	while (count--)
//	{
//		*(char *)dst = *(char *)src;
//		dst = (char *)dst + 1;
//		src = (char *)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char string1[20] = "abcdefghij";
//	char string2[20] = "1234567890";
//	my_memcpy(string1 + 3, string2 + 3, 3);
//	printf("%s\n", string1);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = (int(*)[4])a;
//	printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//地址减地址得到相差的（该指针所指元素类型）元素个数
//	printf("%p\n%x\n", 10, 10);
//	return 0;
//}

//用冒泡排序法实现qsort函数
#include <stdio.h>

struct Stu
{
	char name[20];
	short age;
}

int cmp_int(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(char *buf1, char *buf2, int width)
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < width; i++)
	{
		tmp = *(buf2 + i);
		*(buf2 + i) = *(buf1 + i);
		*(buf1 + i) = tmp;
	}
}

void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char *)base+width*j, (char *)base+width*(j+1)) > 0)
			{
				Swap((char *)base + width*j, (char *)base+width*(j+1), width);
			}
		}
	}
}

void Test1()
{
	int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}

void Test2()
{
	struct Stu arr[] = {{"zhangsan", 20}, {"lisi", 15}, {"wangwu", 25}};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
}

int main()
{
	Test1();
	return 0;
}