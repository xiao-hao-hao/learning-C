#define _CRT_SECURE_NO_WARNINGS 1

//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ������
//������˵��  ����offsetof���ʵ��

////offsetof��ʹ��
//#include <stdio.h>
//#include <stddef.h>
//
//struct S
//{
//	char ch1;//0
//	//1-3
//	int a;//4-7
//	char ch2;//8
//	//9-11
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, ch1));
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, ch2));
//	return 0;
//}

////offsetof���ʵ��
//#include <stdio.h>
//#define OffSetOf(s, m) ((size_t)&(((s *)0)->m))//m�ĵ�ַ����m�ͽṹ���׵�ַ��ƫ����(��0��ַ��ֻҪ��������ȡֵ�Ϳ���)
//
//struct S
//{
//	char ch1;//0
//	//1-3
//	int a;//4-7
//	char ch2;//8
//	//9-11
//};
//
//int main()
//{
//	printf("%d\n", OffSetOf(struct S, ch1));
//	printf("%d\n", OffSetOf(struct S, a));
//	printf("%d\n", OffSetOf(struct S, ch2));
//	return 0;
//}

//ģ��ʵ��memmove
//#include <assert.h>
//
//void * my_memmove(void *dest, const void *src, size_t count)
//{
//	assert(dest && src);
//	if (dest < src)//ǰ->��
//	{
//		while (count--)
//		{
//			*(char *)dest = *(char *)src;
//			dest = (char *)dest + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else//��->ǰ
//	{
//		while (count--)
//		{
//			*((char *)dest + count) = *((char *)src + count);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	my_memmove(arr + 2, arr, 16);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//void * my_memset(void *dest, int c, int count)
//{
//	void *ret = dest;
//	assert(dest);
//	while (count--)
//	{
//		*(char *)dest = c;
//		dest = (char *)dest + 1;
//		++((char *)dest);
//	}
//}
//
//int main()
//{
//	char arr[] = "hello xiaohaohao!";
//	printf("before: %s\n", arr);
//	my_memset(arr, '&', 4);
//	printf("after: %s\n", arr);
//	return 0;
//}
//#include <stdio.h>
//#include <assert.h>
//����һ:��������ʽ�������м������
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//������:���ܴ�����ʱ�������������ݹ�ʵ�֣�
//int my_strlen(const char *str)
//{
//	assert(str);
//	if ('\0' == *str)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//������:ָ���ָ��ķ�ʽ��ָ���ָ��õ���������ָ��֮��ģ���ָ����ָ�������ͣ�Ԫ�صĸ�����
//int my_strlen(const char *str)
//{
//	const char *p = str;
//	assert(str);
//	while (*p)
//	{
//		p++;
//	}
//	return p - str;
//}
//��������һ��д��
//int my_strlen(const char *str)
//{
//	const char *eos = str;
//	assert(str);
//	while (*eos++)
//	{
//		;
//	}
//	return (eos - str - 1);
//}

//int main()
//{
//	int len = 0;
//	char arr[10] = "abcde";
//	char *str = "zbc";
//	printf("%d\n", my_strlen(str));
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//char * my_strcpy(char *dest, const char *src)
//{
//	char *ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char *src = "abcd";
//	char dst[10] = "12345678";
//	printf("%s\n", my_strcpy(dst, src));
//	return 0;
//}

//#include <stdio.h>
//
//char *my_strcat(char *dest, const char *src)
//{
//	char *ret = dest;
//	assert(dest && src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[20] = "hello ";
//	char *str = "world!";
//	char *ps = my_strcat(arr, str);
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//
//int my_strcmp(const char *str1, const char *str2)
//{
//	int ret = 0;
//	assert(str1 && str2);
//	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
//	{
//		str1++;
//		str2++;
//	}
//	if (ret < 0)
//	{
//		return -1;
//	}
//	else if (ret > 0)
//	{
//		return 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char *str1 = "abcdef";
//	char *str2 = "abcde";
//	if (my_strcmp(str1, str2) > 0)
//	{
//		printf("str1 > str2\n");
//	}
//	else if (my_strcmp(str1, str2) < 0)
//	{
//		printf("str1 < str2\n");
//	}
//	else
//	{
//		printf("str1 = str2\n");
//	}
//	return 0;
//}

