#define _CRT_SECURE_NO_WARNINGS 1
//1.ʵ��һ�����������������ַ����е�k���ַ��� 
//ABCD����һ���ַ��õ�BCDA 
//ABCD���������ַ��õ�CDAB
//#include <stdio.h>
//
//char *left_roll(char *ps, int k)
//{
//	int i = 0;
//	int j = 0;
//	char tmp = 0;
//	for (i = 0; i < (k % 7); ++i)//�ƶ�7����������ԭ���ַ�����ͬ
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

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
//���磺����s1 =AABCD��s2 = BCDAA������1������s1=abcd��s2=ACBD������0. 
//
//AABCD����һ���ַ��õ�ABCDA 
//AABCD���������ַ��õ�BCDAA 
//
//AABCD����һ���ַ��õ�DAABC
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
//		printf("�ǣ�\n");
//	}
//	else
//	{
//		printf("���ǣ�\n");
//	}
//	return 0;
//}