//#define _CRT_SECURE_NO_WARNINGS 1
////1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
////����9�����9*9�ھ�������12�����12*12�ĳ˷��ھ���
//#include <stdio.h>
//
//void print(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d", j, i, j*i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("please input>>");
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

////2.ʹ�ú���ʵ���������Ľ���
//#include <stdio.h>
//void swap(int *pa, int *pb)
//{
//	int t;
//	t = *pa;
//	*pa = *pb;
//	*pb = t;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("please input>>");
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("%d %d\n", a, b);
//	return 0;
//}

////3.ʵ��һ�������ж�year�ǲ������ꡣ 
//#include <stdio.h>
//int is_leap(int y)
//{
//	if ((y % 4 == 0 && y % 400 != 0) || (y %1000 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("please input>>");
//	scanf("%d", &year);
//	if (1 == is_leap(year))
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//	return 0;
//}

////4.����һ�����飬 
////ʵ�ֺ���init������ʼ�����顢 
////ʵ��empty����������顢 
////ʵ��reverse���������������Ԫ�ص����á� 
////Ҫ���Լ���ƺ����Ĳ���������ֵ��
//#include <stdio.h>
//void menu()
//{
//	printf("******************************************\n");
//	printf("***************1.��ʼ������  *************\n");
//	printf("***************2.�������    *************\n");
//	printf("***************3.����Ԫ������*************\n");
//	printf("***************4.��ӡ����    *************\n");
//	printf("***************0.�˳�����    *************\n");
//	printf("******************************************\n");
//}
//void init(int *parr, int size)
//{
//	int i = 0;
//	printf("please input elements>>");
//	for (i = 0; i < size; i++)
//	{
//		scanf("%d", parr);
//		parr++;
//	}
//}
//
//void empty(int *parr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		*parr = 0;
//		parr++;
//	}
//}
//
//void reverse(int *parr, int size)
//{
//	int temp = 0;
//	int i = 0;
//	while (i <= size - 1)
//	{
//		temp = *(parr + i);
//		*(parr + i) = *(parr + size - 1);
//		*(parr + size - 1) = temp;
//		i++;
//		size--;
//	}
//}
//
//void print(int *parr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", *(parr++));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = {0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	menu();
//
//	do
//	{
//		printf("please input>>");
//		scanf("%d", &i);
//		switch (i)
//		{
//		case 1:
//			init(arr, sz);
//			break;
//		case 2:
//			empty(arr, sz);
//			break;
//		case 3:
//			reverse(arr, sz);
//			break;
//		case 4:
//			print(arr, sz);
//			break;
//		case 0:
//			break;
//		default:
//			printf("����������������룡\n");
//		}	
//	}while (i);
//
//	return 0;
//}

////5.ʵ��һ���������ж�һ�����ǲ�������
//#include <stdio.h>
//#include <math.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n * 1.0); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int num = 0;
//	printf("please input>>");
//	scanf("%d", &num);
//	if (1 == is_prime(num))
//	{
//		printf("yse!\n");
//	}
//	else
//	{
//	
//		printf("no!\n");
//	}
//	return 0;
//}