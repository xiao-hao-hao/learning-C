#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int num = 0;
//	//int arr[num] = {0};//错误代码
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
//		//使用空间
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
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//扩展容量
//	//ptr = (int*)realloc(ptr, 1000);//这样不可以，如果申请失败原来的内存找不到了
//	p = (int*)realloc(ptr, 1000);
//	if (NULL != p)
//	{
//		ptr = p;
//	}
//	//业务处理
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
//	free(p);//对非动态开辟内存使用free，报错
//	return 0;
//}

//#include <stdlib.h>
//int main()//使用free释放一块动态开辟内存的一部分
//{
//	int *p = (int*)malloc(100);
//	++p;
//	free(p);//p不再指向动态内存的起始位置，报错
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
//	for (i = 0; i <= 14; ++i)//越界访问
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
//	free(p);//对同一块动态内存多次释放，报错
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