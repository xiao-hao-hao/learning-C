#define _CRT_SECURE_NO_WARNINGS 1

//模拟实现strtok
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//char * my_strtok(char *str1, const char *str2)
//{
//	int count = 0;
//	const char *str2_tmp = str2;
//	static char *str1_tmp;//用来记录查找的位置
//	assert(str2);
//	if (str1 == NULL)//对原来的字符串继续分割
//	{
//		str1 = str1_tmp;
//	}
//	else//对新的字符串进行分割
//	{
//		str1_tmp = str1;
//	}
//	while (*str1)
//	{
//		while (*str1_tmp != '\0' && *str2 != '\0' && *str1_tmp != *str2)//判断是否为分割符
//		{
//			++str2;
//		}
//		if (*str1_tmp == '\0')//当找到字符串结束标志的时候，直接返回str1，str1_mp不用加一
//		{
//			return str1;
//		}
//		if (*str1_tmp == *str2 && count != 0)//遇到分隔符，而且要保证不是字符串的起始位置
//		{
//			++str1_tmp;
//			*(str1 + count) = '\0';
//			return str1;
//		}
//		if (*str1_tmp == *str2 && count == 0)//遇到在字符串起始位置的分隔符
//		{
//			++str1_tmp;
//			++str1;
//			str2 = str2_tmp;
//		}
//		if (*str2 == '\0')//没遇到分隔符
//		{
//			++str1_tmp;
//			++count;//用来记str1的起始位置到分隔符的位置，相当于分隔符所在的下标
//			str2 = str2_tmp;
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str[] = "hello,world,bit";
//	char *p;
//	//printf("要分割的字符串为：%s\n", str);
//	p = my_strtok(str, " ,");
//	p = strtok(str, " ,");
//	while (p != NULL)
//	{
//		printf("%s\n", p);
//		p = my_strtok(NULL, " ,");
//		//p = strtok(NULL, " ,");
//	}
//}