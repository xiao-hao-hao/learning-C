#define _CRT_SECURE_NO_WARNINGS 1

//ģ��ʵ��strtok
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//char * my_strtok(char *str1, const char *str2)
//{
//	int count = 0;
//	const char *str2_tmp = str2;
//	static char *str1_tmp;//������¼���ҵ�λ��
//	assert(str2);
//	if (str1 == NULL)//��ԭ�����ַ��������ָ�
//	{
//		str1 = str1_tmp;
//	}
//	else//���µ��ַ������зָ�
//	{
//		str1_tmp = str1;
//	}
//	while (*str1)
//	{
//		while (*str1_tmp != '\0' && *str2 != '\0' && *str1_tmp != *str2)//�ж��Ƿ�Ϊ�ָ��
//		{
//			++str2;
//		}
//		if (*str1_tmp == '\0')//���ҵ��ַ���������־��ʱ��ֱ�ӷ���str1��str1_mp���ü�һ
//		{
//			return str1;
//		}
//		if (*str1_tmp == *str2 && count != 0)//�����ָ���������Ҫ��֤�����ַ�������ʼλ��
//		{
//			++str1_tmp;
//			*(str1 + count) = '\0';
//			return str1;
//		}
//		if (*str1_tmp == *str2 && count == 0)//�������ַ�����ʼλ�õķָ���
//		{
//			++str1_tmp;
//			++str1;
//			str2 = str2_tmp;
//		}
//		if (*str2 == '\0')//û�����ָ���
//		{
//			++str1_tmp;
//			++count;//������str1����ʼλ�õ��ָ�����λ�ã��൱�ڷָ������ڵ��±�
//			str2 = str2_tmp;
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str[] = "hello,world,bit";
//	char *p;
//	//printf("Ҫ�ָ���ַ���Ϊ��%s\n", str);
//	p = my_strtok(str, " ,");
//	p = strtok(str, " ,");
//	while (p != NULL)
//	{
//		printf("%s\n", p);
//		p = my_strtok(NULL, " ,");
//		//p = strtok(NULL, " ,");
//	}
//}