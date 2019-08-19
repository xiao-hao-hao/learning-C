//#define _CRT_SECURE_NO_WARNINGS 1
//
////1.写一个函数返回参数二进制中 1 的个数 
////比如： 15 0000 1111 4 个 1 
////程序原型： 
////int count_one_bits(unsigned int value) 
////{ 
////// 返回 1的位数 
////} 
////#include <stdio.h>
////
////int count_one_bits(int n)
////{
////	int count = 0;
////	while (n != 0)
////	{
////		count += n % 2;
////		n /= 2;
////	}
////	return count;
////}
////
////int main()
////{
////	printf("%d\n", count_one_bits(15));
////	return 0;
////}
//
////#include <stdio.h>
//////递归实现
////int count_one_bits(int n)
////{
////	if (0 != n) //不等于0说明二进制中有1
////	{
////		return n % 2 + count_one_bits(n / 2);
////	}
////	else//否则二进制中没有一，返回0
////	{
////		return 0;
////	}
////}
////
////int main()
////{
////	printf("%d\n", count_one_bits(8));
////	return 0;
////}
//
//////2.获取一个数二进制序列中所有的偶数位和奇数位， 
//////分别输出二进制序列。
////#include <stdio.h>
//////二进制序列从右到左一次为第1、2、3、4位
////void even_print(int n)
////{
////	int i = 0;
////	int temp = 0;
////	int size = sizeof(n) * 8;
////	for (i = 0; i < size / 2; ++i)
////	{
////		temp = (temp * 2) + ((n / 2) % 2);
////		n /= 4;
////	}
////	for (i = 0; i < size / 2; ++i)
////	{
////		printf("%d", temp % 2);
////		temp /= 2;
////	}
////	printf("\n");
////}
////
////void odd_print(int n)
////{
////	int i = 0;
////	int temp = 0;
////	int size = sizeof(n) * 8;
////	for (i = 0; i < size / 2; ++i)
////	{
////		temp = (temp * 2) + (n % 2);
////		n /= 4;
////	}
////	for (i = 0; i < size / 2; ++i)
////	{
////		printf("%d", temp % 2);
////		temp /= 2;
////	}
////	printf("\n");
////}
////
////int main()
////{
////	int i = 15;
////	even_print(i);//打印偶数位
////	odd_print(i);//打印奇数位
////	return 0;
////}
//
////4.编程实现： 
////两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
////输入例子: 
////1999 2299 
////输出例子:7
//
//#include <stdio.h>
//
//int judge(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		int a = 0;
//		int b = 0;
//		if (m % 2 != n % 2)
//		{
//			++count;
//		}
//		m >>= 1;//这样正数和负数都可以判断
//		n >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = -3;
//	int b = -4;
//	printf("%d\n", judge(a, b));
//	return 0;
//}