#define _CRT_SECURE_NO_WARNINGS 1

////1.调整数组使奇数全部都位于偶数前面。 
////题目： 
////输入一个整数数组，实现一个函数， 
////来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
////所有偶数位于数组的后半部分。
//#include <stdio.h>
//
//void adjust(int *arr, int sz)
//{
//	int tmp;
//	int *left = arr;
//	int *right = arr + sz - 1;
//	while (left < right)
//	{
//		if (*left % 2 == 0)
//		{
//			tmp = *right;
//			*right = *left;
//			*left = tmp;
//			--right;
//			continue;
//		}
//		++left;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = {1, 7, 3, 4, 5, 8, 12, 35, 18};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	adjust(arr, sz);
//	for (i = 0; i < sz; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0 ;
//}

////2.杨氏矩阵 
////有一个二维数组. 
////数组的每行从左到右是递增的，每列从上到下是递增的. 
////在这样的数组中查找一个数字是否存在。 
////时间复杂度小于O(N); 
////
////数组： 
////1 2 3 
////2 3 4 
////3 4 5 
////
////
////1 3 4 
////2 4 5 
////4 5 6 
////
////1 2 3 
////4 5 6 
////7 8 9 
//
//#include <stdio.h>
//
//int find(int arr[3][3], int num)
//{
//	int i = 0;
//	int j = 2;
//	while (num != arr[i][j])
//	{
//		if (arr[i][j] > num)
//		{
//			--j;
//		}
//		else
//		{
//			++i;
//		}
//		if ((3 == i) || (0 == j))
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int arr[3][3] = {1, 2, 3,
//					 4, 5, 6,
//					 7, 8, 9};
//	if (1 == find(arr, 10))
//	{
//		printf("Yes!\n");
//	}
//	else
//	{
//		printf("No!\n");
//	}
//	return 0;
//}

//判断电脑的字节序
//#include <stdio.h>
//
////方法1
////int check_sys()
////{
////	int i = 1;
////	return (*(char *)&i);
////}
//
////方法2
//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 2;
//	int arr[5] = {1, 2, 3, 4, 5};
//	for (i = 0; i <= 7; i++)
//	{
//		printf("hahahaha\n");
//		arr[i] = 0;
//	}
//	return 0;
//}

