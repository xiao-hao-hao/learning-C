#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};

//int main()
//{
//	struct Stu s = {"����", 20, 55.5f};
//	int ch = 0;
//	char buf[20] = {0};
//	FILE* pf = fopen("test.txt", "w");
//	if(pf == NULL)
//	{
//		return 0;
//	}
//	//д�ļ�
//	fprintf(pf, "%s %d %f", s.name, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Stu s = {0};
//	int ch = 0;
//	char buf[20] = {0};
//	FILE* pf = fopen("test.txt", "r");
//	if(pf == NULL)
//	{
//		return 0;
//	}
//	//���ļ�
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//	printf("%s %d %f\n", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

#include <stdio.h>
struct Stu
{
	char name[20];
	int age;
	float score;
};

//���л��ͷ����л�

int main()
{
	char buf[50] = {0};
	struct Stu tmp = {0};
	struct Stu s = {"����", 20, 55.5f};
	//�ѽṹ��ת��Ϊ�ַ���
	sprintf(buf, "%s %d %f", s.name, s.age, s.score);
	printf("%s\n", buf);
	//���ַ���ת��Ϊ�ṹ��
	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);
	return 0;
}