#define _CRT_SECURE_NO_WARNINGS 1

//1.实现strcpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strlen(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "hello world";
//	char *str = my_strlen(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//2.实现strcat
//#include <stdio.h>
//#include <assert.h>
//
//char *my_strcat(char *dst, const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while(*dst)
//	{
//		++dst;
//	}
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "hello ";
//	char *str2 = "world!";
//	char *str = my_strcat(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//3.实现strstr 
//#include <stdio.h>
//#include <assert.h>
//
//char *my_strstr(const char *str1, const char *str2)
//{
//	const char *start = str1;
//	const char *p1 = str1;
//	const char *p2 = str2;
//	assert(str1 && str2);
//	while (*start)
//	{
//		p1 = start;
//		p2 = str2;
//		while (*p1 == *p2 && *p1 && *p2)
//		{
//			++p1;
//			++p2;
//		}
//		if ('\0' == *p2)
//		{
//			return (char *)start;
//		}
//		++start;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *str1 = "ahbgdjydrdhdjdngd";
//	char *str2 = "";
//	char *str = my_strstr(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}

//4.实现strchr
//#include <stdio.h>
//#include <assert.h>
//
//char * my_strchr(const char *str, const char ch)
//{
//	assert(*str);
//	while (*str && *str != ch)
//	{
//		str++;
//	}
//	if (*str == ch)
//	{
//		return (char *)str;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *str1 = "abcdefghi";
//	char *str = my_strchr(str1, 'a');
//	printf("%s\n", str);
//	return 0;
//}

//5.实现strcmp
//#include <stdio.h>
//#include <assert.h>
//
//int my_strcmp(const char *str1, const char *str2)
//{
//	assert(*str1 && *str2);
//	while (*str1 == *str2 && *str1 && str2)
//	{
//		str1++;
//		str2++;
//	}
//	if (*str1 == *str2)
//	{
//		return 0;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	char *str1 = "aecd";
//	char *str2 = "accd";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}

//6.实现memcpy
//#include <stdio.h>
//#include <assert.h>
//
//void * my_memcpy(void *dst, void *src, size_t count)
//{
//	void *ret = dst;
//	assert(dst && src);
//	while (count--)
//	{
//		*(char *)dst = *(char *)src;
//		dst = (char *)dst + 1;
//		src = (char *)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char string1[20] = "abcdefghij";
//	char string2[20] = "1234567890";
//	my_memcpy(string1 + 3, string2 + 3, 3);
//	printf("%s\n", string1);
//	return 0;
//}