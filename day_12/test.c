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