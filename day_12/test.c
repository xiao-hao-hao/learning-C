//#define _CRT_SECURE_NO_WARNINGS 1
//
////1.��д������ 
////unsigned int reverse_bit(unsigned int value); 
////��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
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


////2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
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

////3.���ʵ�֣� 
////һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
////���ҳ�������֡���ʹ��λ���㣩
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

////4.��һ���ַ����������Ϊ:"student a am i", 
////���㽫��������ݸ�Ϊ"i am a student". 
////Ҫ�� 
////����ʹ�ÿ⺯���� 
////ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//#include <stdio.h>
//#include<assert.h>
////#include <string.h>
//
//void reverse(char *left, char *right)//����һ���ַ���
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
//int my_strlen(const char *str)//ģ��strlen�������ַ�������
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
//void reverse_str(char *str)//���ַ�������
//{
//	char *start = NULL;
//	char *end = NULL;
//	int len = my_strlen(str);
//	reverse(str, str + len - 1);
//	while (*str != '\0')
//	{
//		start = str;
//		end = str;
//		while ((*end != ' ')&&(*end != '\0'))//��һ������
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
//����һ�����ַ�����ĩβ��ַ��\0�ĵ�ַ����ȥ�ַ�����ͷ��ַ
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

//���������ݹ�ʵ�֣���������ʱ������
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

//��������������ʵ�֣������м������
//2.����const char *��Ϊ�˱����ڱ�д����ʱ��С�İ�ԭ�����ַ����޸���
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str);//1.assert()���������еı��ʽΪ�٣�����Ϊ��ָ�룩�ᱨ��
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
//char * my_strcpy(char *dst, const char *src)//1.const char *  2.����char *����
//{
//	char *cp = dst;
//	assert(dst && src);
//	while (*cp++ = *src++)//3ע��˴�д��
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