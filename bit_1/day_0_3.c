////1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����
//
//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[3] = {0};
//	scanf("%s", arr);
//	printf("%s\n", arr);
//	//strcpy(arr, "abc");
//	return 0;
//}
////#include <stdio.h>
////
////int main()
////{
////	int a[] = {1, 2, 3}, b[] = {4, 5, 6}, t, i;
////	int n = sizeof(a) / sizeof(a[0]);
////	for(i = 0; i < n; i++)
////	{
////		t = a[i];
////		a[i] = b[i];
////		b[i] = t;
////	}
////	for(i = 0; i < n; i++)
////		printf("%d ", a[i]);
////	printf("\n");
////	for(i = 0; i < n; i++)
////		printf("%d ", b[i]);
////	printf("\n");
////	return 0;
////}

////2. ����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ��
//#include <stdio.h>
//
//int main()
//{
//	double i = 1, sum = 0;
//	int b = 1;
//	for(b = 1; b <= 100; b++)
//	{
//		sum += i / b;
//		i = -i;
//	}
//	printf("%f\n", sum);
//	return 0;
//}


////3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
//#include <stdio.h>
////1��100����������9��λ���Ǹ�λ����ʮλ
////��/10�ж�ʮλ�Ƿ����9����%10�жϸ�λ�Ƿ����9
//int main()
//{
//	int i = 0, count = 0;
//	for(i = 1; i <= 100; i++)
//	{
//		if(i/10 == 9)
//			count++;
//		if(i%10 == 9)
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}