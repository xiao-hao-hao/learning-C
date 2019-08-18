////1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
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

////2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
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


////3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
//#include <stdio.h>
////1到100的整数出现9的位置是各位或者十位
////用/10判断十位是否等于9，用%10判断各位是否等于9
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