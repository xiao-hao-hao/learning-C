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