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

//#include <stdio.h>
//int main()
//{
//	int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", pFloat);
//
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("pFloat��ֵΪ��%f\n", *pFloat);
//	return 0;
//}

//������
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
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		case 1:
//			printf("�����������");
//			scanf("%d%d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("�������������");
//			scanf("%d%d", &x, &y);
//			ret = sub(x, y);
//			break;
//		case 3:
//			printf("�������������");
//			scanf("%d%d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 4:
//			printf("�������������");
//			scanf("%d%d", &x, &y);
//			ret = div(x, y);
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//		if ((input >= 1) && (input <= 4))
//		{
//			printf("ret = %d\n", ret);			
//		}
//	}
//	printf("�˳���\n");
//	return 0;
//}

//ʹ�ú���ָ������ʵ�ּ�����
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
//		printf("��ѡ��");
//		scanf("%d", &input);
//		if ((input >= 1) && (input <= 4))
//		{
//			printf("�������������");
//			scanf("%d%d", &x, &y);
//			ret = (p[input])(x, y);
//			printf("ret = %d\n", ret);
//		}
//		else if (0 != input)
//			printf("��������\n");
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