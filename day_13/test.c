#define _CRT_SECURE_NO_WARNINGS 1

////1.��������ʹ����ȫ����λ��ż��ǰ�档 
////��Ŀ�� 
////����һ���������飬ʵ��һ�������� 
////�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
////����ż��λ������ĺ�벿�֡�
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

////2.���Ͼ��� 
////��һ����ά����. 
////�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
////�������������в���һ�������Ƿ���ڡ� 
////ʱ�临�Ӷ�С��O(N); 
////
////���飺 
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