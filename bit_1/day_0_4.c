////1.��ӡ����ͼ��
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 1; i <= 7; i++)  //��ӡǰ7��
//	{
//		for (j = 1; j <= 7 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= i * 2 - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//
//	}
//
//	for (i = 1; i <= 6; i++)  //��ӡ��6��
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 13 - 2 * i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//
//	}
//	return 0;
//}


////2.���0��999֮������С�ˮ�ɻ������������ 
////��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3?����153��һ����ˮ�ɻ������� 
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0, sum = 0;
//	for (i = 0; i <= 999; i++)
//	{
//		sum = pow((double)(i%10), 3) + pow((double)((i/10)%10), 3) + pow((double)(i/100), 3);
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

////3. ��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣� 
////���磺2+22+222+2222+22222
//#include <stdio.h>
//
//int main()
//{
//	int i =0;
//	int a = 0;
//	int b = 1;  //������Ÿı���a
//	int sum = 0;
//	printf(">>");
//	scanf("%d", &a);
//	b = a;
//	for (i = 1; i <= 5; i++)
//	{
//		sum += b;
//		b = (b * 10) + a;
//	}
//	printf("%d\n", sum);
//	return 0;
//}