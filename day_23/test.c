#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int num = 0;
//	//int arr[num] = {0};//�������
//	int *ptr = NULL;
//	scanf("%d", &num);
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)
//	{
//		int i = 0;
//		for (i = 0; i < num; ++i)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int *p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int *ptr = (int*)malloc(100);
//	int *p = NULL;
//	if (NULL != ptr)
//	{
//		//ҵ����
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//��չ����
//	//ptr = (int*)realloc(ptr, 1000);//���������ԣ��������ʧ��ԭ�����ڴ��Ҳ�����
//	p = (int*)realloc(ptr, 1000);
//	if (NULL != p)
//	{
//		ptr = p;
//	}
//	//ҵ����
//	free(ptr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int *p = NULL;
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//�ԷǶ�̬�����ڴ�ʹ��free������
//	return 0;
//}

//#include <stdlib.h>
//int main()//ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//{
//	int *p = (int*)malloc(100);
//	++p;
//	free(p);//p����ָ��̬�ڴ����ʼλ�ã�����
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	int *p = (int*)malloc(10*sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 14; ++i)//Խ�����
//	{
//		*(p + i) = i;
//	}
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	int *p = (int*)malloc(100);
//	free(p);
//	free(p);//��ͬһ�鶯̬�ڴ����ͷţ�����
//	return 0;
//}

#include <stdio.h>
char *GetMemory()
{
	char p[] = "hello world";
	return p;
}

void Test()
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}

int main()
{
	Test();
	return 0;
}