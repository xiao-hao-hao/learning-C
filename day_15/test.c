#define _CRT_SECURE_NO_WARNINGS 1

//1.һ��������ֻ�����������ǳ���һ�Σ� 
//�����������ֶ����������Ρ� 
//�ҳ����������֣����ʵ�֡�
//#include <stdio.h>
//
//void find(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; ++i)
//	{
//		int count = 0;
//		for (j = 0; j < sz; ++j)
//		{
//			if (arr[i] == arr[j])
//			{
//				++count;
//			}
//		}
//		if (1 == count)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1, 3, 5, 7, 3, 2, 1, 7};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	find(arr, sz);
//	printf("\n");
//	return 0;
//}

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
//��20Ԫ�����Զ�����ˮ�����ʵ�֡�
//#include <stdio.h>
//
//int cola_num(int n)
//{
//	if (1 == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return n + cola_num(n / 2);
//	}
//}
//
//int main()
//{
//	int n = 20;
//	int ret = cola_num(n);
//	printf("%d\n", ret);
//	return 0;
//}

////3.ģ��ʵ��strcpy 
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//char *my_strcpy(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while((*dst++ = *src++) != '\0')
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "abcde";
//	char str2[] = "12345";
//	char *pc = my_strcpy(str1, str2);
//	printf("%s\n", pc);
//	return 0;
//}

//4.ģ��ʵ��strcat
//#include <stdio.h>
//#include <assert.h>
//char *my_strcat(char *dst, char *src)
//{
//	char *ret = dst;
//	while ('\0' != *dst)
//	{
//		++dst;
//	}
//	while ((*dst++ = *src++) != '\0')
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "123456";
//	char str2[] = "abcdef";
//	char *pc = my_strcat(str1, str2);
//	printf("%s\n", pc);
//	return 0;
//}