////1.打印菱形图案
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 1; i <= 7; i++)  //打印前7行
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
//	for (i = 1; i <= 6; i++)  //打印后6行
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


////2.求出0～999之间的所有“水仙花数”并输出。 
////“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3?，则153是一个“水仙花数”。 
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

////3. 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字， 
////例如：2+22+222+2222+22222
//#include <stdio.h>
//
//int main()
//{
//	int i =0;
//	int a = 0;
//	int b = 1;  //用来存放改变后的a
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