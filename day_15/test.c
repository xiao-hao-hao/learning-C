#define _CRT_SECURE_NO_WARNINGS 1

//1.一个数组中只有两个数字是出现一次， 
//其他所有数字都出现了两次。 
//找出这两个数字，编程实现。
//#include <stdio.h>
//
//void find(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; ++i)
//	{
//		int count = 0;
//		for (j = 0; j < sz; ++j)
//		{
//			if (arr[i] == arr[j])
//			{
//				++count;
//			}
//		}
//		if (1 == count)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1, 3, 5, 7, 3, 2, 1, 7};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	find(arr, sz);
//	printf("\n");
//	return 0;
//}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//给20元，可以多少汽水。编程实现。
//#include <stdio.h>
//
//int cola_num(int n)
//{
//	if (1 == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return n + cola_num(n / 2);
//	}
//}
//
//int main()
//{
//	int n = 20;
//	int ret = cola_num(n);
//	printf("%d\n", ret);
//	return 0;
//}

////3.模拟实现strcpy 
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//char *my_strcpy(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while((*dst++ = *src++) != '\0')
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "abcde";
//	char str2[] = "12345";
//	char *pc = my_strcpy(str1, str2);
//	printf("%s\n", pc);
//	return 0;
//}

//4.模拟实现strcat
//#include <stdio.h>
//#include <assert.h>
//char *my_strcat(char *dst, char *src)
//{
//	char *ret = dst;
//	while ('\0' != *dst)
//	{
//		++dst;
//	}
//	while ((*dst++ = *src++) != '\0')
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "123456";
//	char str2[] = "abcdef";
//	char *pc = my_strcat(str1, str2);
//	printf("%s\n", pc);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int int_cmp(const void *p1, const void *p2)
//{
//	return (*(int *)p1 > *(int *)p2);
//}
//
//int main()
//{
//	int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
//	int  i = 0;
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

#include <stdio.h>
#include <string.h>

struct Stu
{
	char name[20];
	short age;
};

int cmp_stu_by_name(const void *p1, const void *p2)
{
	return (strcmp(((struct Stu *)p1)->name, ((struct Stu *)p2)->name));
}

int cmp_stu_by_age(const void *p1, const void *p2)
{
	return (((struct Stu *)p1)->age - ((struct Stu *)p2)->age);
}

int cmp_int(void *p1, void *p2)
{
	return (*(int *)p1 - *(int *)p2);
}

int cmp_char(void *p1, void *p2)
{
	return (strcmp(*(char **)p1, *(char **)p2));
}

void swap(void *p1, void *p2, int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void bubble(void *base, int count, int size, int (*cmp)(const void *, const void *))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; ++i)
	{
		for (j = 0; j < count - i - 1; ++j)
		{
			if (cmp((char *)base + j*size, (char *)base + (j+1)*size) > 0)
			{
				swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

int main()
{
	int i = 0;
	//int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
	//bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);

	//char *arr[] = {"aaaa", "dddd", "cccc", "bbbb"};
	//bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_char);

	//struct Stu arr[] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 18}};
	//bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_stu_by_name);

	struct Stu arr[] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 18}};
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_stu_by_age);
	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	//{
	//	printf("%s ", arr[i]);
	//}
	//printf("\n");
	return 0;
}