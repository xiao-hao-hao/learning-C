#define _CRT_SECURE_NO_WARNINGS 1

////1.5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
////Aѡ��˵��B�ڶ����ҵ����� 
////Bѡ��˵���ҵڶ���E���ģ� 
////Cѡ��˵���ҵ�һ��D�ڶ��� 
////Dѡ��˵��C����ҵ����� 
////Eѡ��˵���ҵ��ģ�A��һ�� 
////����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; ++a)
//	{
//		for (b = 1; b <= 5; ++b)
//		{
//			for (c = 1; c <= 5; ++c)
//			{
//				for (d = 1; d <= 5; ++d)
//				{
//					for (e = 0; e <= 5; ++e)
//					{
//						if (((3 == a) ^ (2 == b)) &&
//							((2 == b) ^ (4 == e)) &&
//							((1 == c) ^ (2 == d)) &&
//							((5 == c) ^ (3 == d)) &&
//							((4 == e) ^ (1 == a)))
//						{
//							if ((a!=b) && (a!=c) && (a!=d) && (a!=e) && (b!=c) && 
//								(b!=d) && (b!=e) && (c!=d) && (c!=e) && (d!=e))
//							{
//								printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);									
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

////2.�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
////���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
////A˵�������ҡ� 
////B˵����C�� 
////C˵����D�� 
////D˵��C�ں�˵ 
////��֪3����˵���滰��1����˵���Ǽٻ��� 
////�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//#include <stdio.h>
//int main()
//{
//	char murder = 0;
//	for (murder = 'A'; murder <= 'D'; ++murder)
//	{
//		if (('A' != murder) + ('C' == murder) + ('D' == murder) + !('D' == murder) == 3)
//		{
//			printf("%c\n", murder);
//		}
//	}
//	return 0;
//}

////3.����Ļ�ϴ�ӡ������ǡ� 
////1 
////1 1 
////1 2 1 
////1 3 3 1
//#include <stdio.h>
//
//void print(int arr[20][20], int n)
//{
//	int a = 1, b = 1, i = 0, j = 0;
//	arr[1][1] = 1;
//	for (i = 2; i <= n; ++i)
//	{
//		arr[i][1] = 1;
//		for (j = 2; j < i; ++j)
//		{
//			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//		}
//		arr[i][i] = 1;
//	}
//	for (i = 1; i <= n; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%-4d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 10;//�����ӡ����
//	int arr[20][20] = {0};
//	print(arr, n);
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int num = -1;
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		if (((num>>i) & 1) == 1)
//		{
//			++count;
//		}
//	}
//	printf("��������1�ĸ��� = %d\n", count);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = -1;
//	int i = 0;
//	int count = 0;
//	while (num)
//	{
//		++count;
//		num = num & (num - 1);//ÿ����һ�Σ�num������һ��1
//	}
//	printf("��������1�ĸ��� = %d\n", count);
//	return 0;
//}

//#include <stdio.h>
//
////����һ�����ַ�����ĩβ��ַ��\0�ĵ�ַ����ȥ�ַ�����ͷ��ַ
////int my_strlen(char *str)
////{
////	char *p = str;
////	while (*p != '\0')
////	{
////		++p;
////	}
////	return p - str;
////}
//
////���������ݹ�ʵ�֣���������ʱ������
////int my_strlen(char *str)
////{
////	if ('\0' == *str)
////	{
////		return 0;
////	}
////	else
////	{
////		return 1 + my_strlen(str + 1);
////	}
////	return 0;
////}
//
////��������������ʵ�֣������м������
//int my_strlen(char *str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		++count;
//		++str;
//	}
//	return count;
//}
//
//int main()
//{
//	int len = 0;
//	char arr[10] = "abcde";
//	char *str = "zbc";
//	printf("%d\n", my_strlen(arr));
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

#include <stdio.h>

void test1()
{
	printf("hehe\n");
}

void test()
{
	test1();
}

int main()
{
	test();
	return 0;
}