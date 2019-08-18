////1. 打印100~200之间的素数 
//#include <stdio.h>
//
//int main()
//{
//	int i = 100;
//	int j = 0;
//	int sign = 1;
//	while(i <= 200)
//	{
//		for(j = 2; j <= i / 2; j++)
//		{
//			if(i % j == 0)
//			{
//				sign = 0;
//				break;
//			}
//		}
//		if(sign == 1)
//			printf("%d ", i);
//		sign = 1;
//		i++;
//	}
//	printf("\n");
//	return 0;
//}

////2. 输出乘法口诀表
//#include <stdio.h>
//
//int main()
//{
//	int i, j;
//	for(i = 1; i <= 9; i++)
//	{
//		for(j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", j, i, j * i);  //%2d表示固定输出两位
//		}
//		printf("\n");
//	}
//	return 0;
//}

////3. 判断1000年---2000年之间的闰年
//#include <stdio.h>
//
//int main()
//{
//	int year = 1000;
//	for(year = 1000; year <= 2000; year++)
//	{
//		if((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
//			printf("%d ", year);
//	}
//	printf("\n");
//	return 0;
//}
