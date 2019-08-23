#define _CRT_SECURE_NO_WARNINGS 1
//1.实现一个函数，可以左旋字符串中的k个字符。 
//ABCD左旋一个字符得到BCDA 
//ABCD左旋两个字符得到CDAB
//#include <stdio.h>
//
//char *left_roll(char *ps, int k)
//{
//	int i = 0;
//	int j = 0;
//	char tmp = 0;
//	for (i = 0; i < (k % 7); ++i)//移动7的整数倍与原来字符串相同
//	{
//		tmp = *ps;
//		for (j = 1; *(ps + j) != '\0'; ++j)
//		{
//			*(ps + j - 1) = *(ps + j);
//		}
//		*(ps + j - 1) = tmp;
//	}
//}
//
//int main()
//{
//	char str[] = "abcd123";
//	left_roll(str, 8);
//	printf("%s\n", str);
//	return 0;
//}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
//例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0. 
//
//AABCD左旋一个字符得到ABCDA 
//AABCD左旋两个字符得到BCDAA 
//
//AABCD右旋一个字符得到DAABC
//
//#include <stdio.h>
//#include <string.h>
//
//void left_roll(char *ps, int k)
//{
//	int i = 0;
//	int j = 0;
//	char tmp = 0;
//	int sz = strlen(ps);
//	for (i = 0; i < (k % sz); ++i)
//	{
//		tmp = *ps;
//		for (j = 1; *(ps + j) != '\0'; ++j)
//		{
//			*(ps + j - 1) = *(ps + j);
//		}
//		*(ps + j - 1) = tmp;
//	}
//}
//
//int IsRoll(const char *dst, char *src)
//{
//	int i = 0;
//	int j = 0;
//	char tmp = 0;
//	int sz = strlen(src);
//	for (i = 1; i <= sz; ++i)
//	{
//		left_roll(src, 1);
//		if (0 == strcmp(dst, src))
//		{
//			left_roll(src, sz - i);
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char str1[] = "abcde";
//	char str2[] = "eabcd";
//	if(1 == IsRoll(str1, str2))
//	{
//		printf("是！\n");
//	}
//	else
//	{
//		printf("不是！\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", pFloat);
//
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

//计算器
//#include <stdio.h>
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//int div(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 1;
//	while (input)
//	{
//		printf("***************************\n");
//		printf("  1:add             2:sub  \n");
//		printf("  3:mul             3:div  \n");
//		printf("***************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		case 1:
//			printf("输入操作数：");
//			scanf("%d%d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("请输入操作数：");
//			scanf("%d%d", &x, &y);
//			ret = sub(x, y);
//			break;
//		case 3:
//			printf("请输入操作数：");
//			scanf("%d%d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 4:
//			printf("请输入操作数：");
//			scanf("%d%d", &x, &y);
//			ret = div(x, y);
//		default:
//			printf("选择错误！\n");
//			break;
//		}
//		if ((input >= 1) && (input <= 4))
//		{
//			printf("ret = %d\n", ret);			
//		}
//	}
//	printf("退出！\n");
//	return 0;
//}

//使用函数指针数组实现计算器
//#include <stdio.h>
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//int div(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = {0, add, sub, mul, div};
//	while (input)
//	{
//		printf("***************************\n");
//		printf("  1:add             2:sub  \n");
//		printf("  3:mul             3:div  \n");
//		printf("***************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		if ((input >= 1) && (input <= 4))
//		{
//			printf("请输入操作数：");
//			scanf("%d%d", &x, &y);
//			ret = (p[input])(x, y);
//			printf("ret = %d\n", ret);
//		}
//		else if (0 != input)
//			printf("输入有误！\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 5;
//	if (i == 5)
//	{
//		printf("hehe\n");
//	}
//	else if (i > 3)
//	{
//		printf("haha\n");
//	}
//	return 0;
//}