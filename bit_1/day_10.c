//#define _CRT_SECURE_NO_WARNINGS 1
//
////1.дһ���������ز����������� 1 �ĸ��� 
////���磺 15 0000 1111 4 �� 1 
////����ԭ�ͣ� 
////int count_one_bits(unsigned int value) 
////{ 
////// ���� 1��λ�� 
////} 
////#include <stdio.h>
////
////int count_one_bits(int n)
////{
////	int count = 0;
////	while (n != 0)
////	{
////		count += n % 2;
////		n /= 2;
////	}
////	return count;
////}
////
////int main()
////{
////	printf("%d\n", count_one_bits(15));
////	return 0;
////}
//
////#include <stdio.h>
//////�ݹ�ʵ��
////int count_one_bits(int n)
////{
////	if (0 != n) //������0˵������������1
////	{
////		return n % 2 + count_one_bits(n / 2);
////	}
////	else//�����������û��һ������0
////	{
////		return 0;
////	}
////}
////
////int main()
////{
////	printf("%d\n", count_one_bits(8));
////	return 0;
////}
//
//////2.��ȡһ�������������������е�ż��λ������λ�� 
//////�ֱ�������������С�
////#include <stdio.h>
//////���������д��ҵ���һ��Ϊ��1��2��3��4λ
////void even_print(int n)
////{
////	int i = 0;
////	int temp = 0;
////	int size = sizeof(n) * 8;
////	for (i = 0; i < size / 2; ++i)
////	{
////		temp = (temp * 2) + ((n / 2) % 2);
////		n /= 4;
////	}
////	for (i = 0; i < size / 2; ++i)
////	{
////		printf("%d", temp % 2);
////		temp /= 2;
////	}
////	printf("\n");
////}
////
////void odd_print(int n)
////{
////	int i = 0;
////	int temp = 0;
////	int size = sizeof(n) * 8;
////	for (i = 0; i < size / 2; ++i)
////	{
////		temp = (temp * 2) + (n % 2);
////		n /= 4;
////	}
////	for (i = 0; i < size / 2; ++i)
////	{
////		printf("%d", temp % 2);
////		temp /= 2;
////	}
////	printf("\n");
////}
////
////int main()
////{
////	int i = 15;
////	even_print(i);//��ӡż��λ
////	odd_print(i);//��ӡ����λ
////	return 0;
////}
//
////4.���ʵ�֣� 
////����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
////��������: 
////1999 2299 
////�������:7
//
//#include <stdio.h>
//
//int judge(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		int a = 0;
//		int b = 0;
//		if (m % 2 != n % 2)
//		{
//			++count;
//		}
//		m >>= 1;//���������͸����������ж�
//		n >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = -3;
//	int b = -4;
//	printf("%d\n", judge(a, b));
//	return 0;
//}