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