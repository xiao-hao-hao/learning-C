#define _CRT_SECURE_NO_WARNINGS 1

//1.模拟实现strncpy
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

//2.模拟实现strncat 
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
//	*dest = '\0';//strncat总是在结果后面加'\0'，而不是用'\0'填充目标剩余空间
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

