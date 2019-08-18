//#define _CRT_SECURE_NO_WARNINGS 1
////1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
////输入9，输出9*9口诀表，输入12，输出12*12的乘法口诀表。
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

////2.使用函数实现两个数的交换
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

////3.实现一个函数判断year是不是润年。 
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

////4.创建一个数组， 
////实现函数init（）初始化数组、 
////实现empty（）清空数组、 
////实现reverse（）函数完成数组元素的逆置。 
////要求：自己设计函数的参数，返回值。
//#include <stdio.h>
//void menu()
//{
//	printf("******************************************\n");
//	printf("***************1.初始化数组  *************\n");
//	printf("***************2.清空数组    *************\n");
//	printf("***************3.数组元素逆置*************\n");
//	printf("***************4.打印数组    *************\n");
//	printf("***************0.退出程序    *************\n");
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
//			printf("输入错误，请重新输入！\n");
//		}	
//	}while (i);
//
//	return 0;
//}

////5.实现一个函数，判断一个数是不是素数
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