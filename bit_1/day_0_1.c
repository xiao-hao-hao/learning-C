////1. ��ӡ100~200֮������� 
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

////2. ����˷��ھ���
//#include <stdio.h>
//
//int main()
//{
//	int i, j;
//	for(i = 1; i <= 9; i++)
//	{
//		for(j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", j, i, j * i);  //%2d��ʾ�̶������λ
//		}
//		printf("\n");
//	}
//	return 0;
//}

////3. �ж�1000��---2000��֮�������
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
