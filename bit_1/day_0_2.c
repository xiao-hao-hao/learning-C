////1. �����������α�����ֵ��������ֵ�����ݽ��н���
//#include <stdio.h>
//
//int main()
//{
//	int a = 5, b = 9, c = 0;
//	c = a;
//	a = b;
//	b = c;
//	printf("%d %d\n", a, b);
//	return 0;
//}

////2. ����������ʱ���������������������ݣ������⣩
//#include <stdio.h>
//
//int main()
//{
//	int a = 5, b = 8;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d\n", a, b);
//	return 0;
//}

////3.��10 �����������ֵ
//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	int a[] = {3, 5, 2, 8, 69, 98, 648, 23, 18, 76};
//	int n = sizeof(a) / sizeof(a[0]);
//	int max;
//	for(max = a[0]; i < n; i++)
//	{
//		if(a[i] > max)
//			max = a[i];
//	}
//	printf("%d\n", max);
//	return 0;
//}

////4.�����������Ӵ�С���
//#include <stdio.h>
//
//int main()
//{
//	int a = 2, b = 4, c = 6, t;
//	if(a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if(a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if(b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//5.�������������Լ��
#include <stdio.h>
//
//int main()
//{
//	int a = 30, b = 52, i;
//	for(i = a; i > 0; i--)
//	{
//		if(a % i == 0 && b % i == 0)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}