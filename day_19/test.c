#define _CRT_SECURE_NO_WARNINGS 1

//1.ģ��ʵ��strncpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char *dest,const char *src, size_t n)
//{
//	char *tmp = dest;
//	assert(dest && src);
//	while (n)
//	{
//		if ('\0' == *src)
//		{
//			*dest++ = 0;
//			break;
//		}
//		*dest++ = *src++;
//		--n;
//	}
//	return tmp;
//}
//
//int main()
//{
//	char str1[] = "1234567890";
//	char *str2 = "abc";
//	my_strncpy(str1, str2, 4);
//	printf("%s\n", str1);
//	return 0;
//}

//2.ģ��ʵ��strncat 
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncat(char *dest,const char *src, size_t n)
//{
//	assert(dest && src);
//	while (*dest != '\0')
//	{
//		++dest;
//	}
//	while (n)
//	{
//		if (*src == '\0')
//		{
//			break;
//		}
//		*dest++ = *src++;
//		--n;
//	}
//	*dest = '\0';//strncat�����ڽ�������'\0'����������'\0'���Ŀ��ʣ��ռ�
//}
//
//int main()
//{
//	char str1[20] = "To be ";
//	char str2[20] = "or not to be";
//	my_strncat(str1, str2, 50);
//	puts(str1);
//	return 0;
//}

//3.ģ��ʵ��strncmp
//#include <stdio.h>
//
//int my_strncmp(const char *str1, const char *str2, size_t n)
//{
//	while(n--)
//	{
//		if ((*str1 == 0) || (*str1 != *str2))//*str1==0��Ϊ���ж�(str1==str2=='\0'�����)
//		{
//			return *str1 - *str2;
//		}
//		++str1;
//		++str2;
//	}
//	return 0;
//}
//
//int main()
//{
//	int tag = 0;
//	char str1[20] = "123456789";
//	char str2[20] = "1234345667";
//	tag = my_strncmp(str1, str2, 4);
//	printf("%d\n", tag);
//	return 0;
//}