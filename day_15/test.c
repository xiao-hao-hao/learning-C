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