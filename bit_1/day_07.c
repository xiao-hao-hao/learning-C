//#define _CRT_SECURE_NO_WARNINGS 1
//
////1.递归和非递归分别实现求第n个斐波那契数。 
////递归
////#include <stdio.h>
////
////int fib(int n)
////{
////	if (n <= 2)
////	{
////		return 1;
////	}
////	else
////	{
////		return fib(n - 1) + fib(n - 2);
////	}
////}
////
////int main()
////{
////	int n = 6;
////	printf("%d\n", fib(n));
////	return 0;
////}
//
//#include <stdio.h>
////非递归
//int fib(int n)
//{
//	int a = 1, b = 1, c = 1, i = 0;
//	if (n > 2)
//	{
//		for (i = 0; i < n - 2; ++i)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 6;
//	printf("%d\n", fib(n));
//	return 0;
//}

////2.编写一个函数实现n^k，使用递归实现
//#include <stdio.h>
//
//int fun(int n, int k)
//{
//	if (1 == k)
//	{
//		return n;
//	}
//	else
//	{
//		return n * fun(n, k - 1);
//	}
//}
//int main()
//{
//	printf("%d\n", fun(2,5));
//	return 0;
//}

////3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
////例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 
//#include <stdio.h>
//
//int func(int n)
//{
//	if(n / 10 == 0)
//	{
//		return n;
//	}
//	else
//	{
//		return n % 10 + func(n / 10);
//	}
//}
//
//int main()
//{
//	printf("%d\n", func(1729));
//	return 0;
//}


///*4. 编写一个函数 reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。 
//要求：不能使用C函数库中的字符串操作函数。*/ 
//#include <stdio.h>
//#include <string.h>
//
//void reverse_string(char *str)
//{
//	int len = strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (strlen(str + 1) > 1)
//	{
//		reverse_string(str +1);
//	}
//	*(str + len - 1) = tmp;
//}
//
//int main()
//{
//	char str[] = "123456";
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}

////5.递归和非递归分别实现strlen
//
//#include <stdio.h>
////非递归
//int my_strlen(char *str)
//{
//	int count = 0;
//	while (*(str + count) != '\0')
//	{
//		++count;
//	}
//	return count;
//}
//
//int main()
//{
//	char *str_1 = "123";
//	char str_2[] = "123";
//	printf("%d\n", my_strlen(str_1));
//	printf("%d\n", my_strlen(str_2));
//	return 0;
//}

//
#include<stdio.h>
////递归
//int my_strlen(char *str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str +1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char *str_1 = "123";
//	char str_2[] = "123";
//	printf("%d\n", my_strlen(str_1));
//	printf("%d\n", my_strlen(str_2));
//	return 0;
//}

////6.递归和非递归分别实现求n的阶乘
//#include <stdio.h>
////递归
//int factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * factorial(n - 1);
//	}
//}
//
//int main()
//{
//	printf("%d\n", factorial(10));
//	return 0;
//}

//#include <stdio.h>
////非递归
//int factorial(int n)
//{
//	int tmp = 1;
//	while (n >= 1)
//	{
//		tmp *= n; 
//		--n;
//	}
//	return tmp;
//}
//
//int main()
//{
//	printf("%d\n", factorial(2));
//	return 0;
//}

////7.递归方式实现打印一个整数的每一位 
//#include <stdio.h>
//
//int print(int n)
//{
//	if (n / 10 == 0)
//	{
//		printf("%d  ", n);
//	}
//	else
//	{
//		print(n / 10);
//		print(n % 10);
//	}
//}
//
//int main()
//{
//	int n = 123;
//	print(n);
//	return 0;
//}