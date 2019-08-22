//#define _CRT_SECURE_NO_WARNINGS 1
//
////1.编写函数： 
////unsigned int reverse_bit(unsigned int value); 
////这个函数的返回值value的二进制位模式从左到右翻转后的值。
//#include <stdio.h>
//
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int tmp = 0;
//	int i = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		tmp = (tmp * 2) + (value % 2);
//		value /= 2;
//	}
//	return tmp;

//}
//
//int main()
//{
//	unsigned int n = 25;
//	printf("%u\n", reverse_bit(n));
//	return 0;
//}


////2.不使用（a+b）/2这种方式，求两个数的平均值。
//#include <stdio.h>
//
//int average(int a, int b)
//{
//	return a + (b - a) / 2;
//}
//
//int main()
//{
//	int a = 4;
//	int b = 20;
//	printf("%d\n", average(a, b));
//	return 0;
//}

////3.编程实现： 
////一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
////请找出这个数字。（使用位运算）
//#include <stdio.h>
//
//int find(int *num, int size)
//{
//	int i = 0;
//	int t = 0;
//	for (i = 0; i < size; ++i)
//	{
//		t ^= num[i]; 
//	}
//	return t;
//}
//
//int main()
//{
//	int num[] = {1, 2, 3, 5, 2, 1, 3};
//	int size = sizeof(num) / sizeof(num[0]);
//	printf("%d\n", find(num, size));
//	return 0;
//}

////4.有一个字符数组的内容为:"student a am i", 
////请你将数组的内容改为"i am a student". 
////要求： 
////不能使用库函数。 
////只能开辟有限个空间（空间个数和字符串的长度无关）。
//#include <stdio.h>
//#include<assert.h>
////#include <string.h>
//
//void reverse(char *left, char *right)//逆序一个字符串
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		++left;
//		--right;
//	}
//}
//
//int my_strlen(const char *str)//模拟strlen函数求字符串长度
//{
//    int count = 0;
//    assert(str != 0);
//    while (*str++)
//    {
//        count++;
//    }
//    return count;
//}
//
//void reverse_str(char *str)//将字符串逆序
//{
//	char *start = NULL;
//	char *end = NULL;
//	int len = my_strlen(str);
//	reverse(str, str + len - 1);
//	while (*str != '\0')
//	{
//		start = str;
//		end = str;
//		while ((*end != ' ')&&(*end != '\0'))//找一个单词
//		{
//			++end;
//		}
//		reverse(start, end - 1);
//		if ('\0' == *end)
//		{
//			str = end;
//		}
//		else
//		{
//			str = end + 1;
//		}
//	}
//}
//
//int main()
//{
//	char str[] = "student a am i";
//	reverse_str(str);
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char *p = "1234";
//	printf("%d", strlen(p));
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//方法一：用字符串的末尾地址（\0的地址）减去字符串开头地址
//int my_strlen(const char *str)
//{
//	const char *p = str;
//	assert(str);
//	while (*p != '\0')
//	{
//		++p;
//	}
//	return p - str;
//}

//方法二：递归实现（不创建临时变量）
//int my_strlen(const char *str)
//{
//	assert(str);
//	if ('\0' == *str)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}

//方法三：计数器实现（创建中间变量）
//2.定义const char *是为了避免在编写函数时不小心把原来的字符串修改了
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str);//1.assert()函数括号中的表达式为假（参数为空指针）会报错
//	while (*str != '\0')
//	{
//		++count;
//		++str;
//	}
//	return count;
//}

//int my_strlen(const char *str)
//{
//	const char *eos = str;
//	assert(str);
//	while (*eos++)
//	{
//		;
//	}
//	return (eos - str - 1);
//}
//
//int main()
//{
//	int len = 0;
//	char arr[10] = "abcde";
//	char *str = "zbc";
//	printf("%d\n", my_strlen(str));
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//char * my_strcpy(char *dst, const char *src)//1.const char *  2.返回char *类型
//{
//	char *cp = dst;
//	assert(dst && src);
//	while (*cp++ = *src++)//3注意此处写法
//	{
//		;
//	}
//	return dst;
//}
//
//int main()
//{
//	char *src = "abcd";
//	char dst[10] = "12345678";
//	printf("%s\n", my_strcpy(dst, src));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	const int i = 5;
//	int *p = (int *)&i;
//	*p = 6;
//	printf("%d\n", i);
//	return 0;
//}

#include <stdio.h>
int main()
{
	int a = 20;
	int b = -10;
	return 0;
}