#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("**************************************************************\n");
	printf("**        1. �����ϵ��                2. ɾ����ϵ��        **\n");
	printf("**        3. ������ϵ��                4. �޸���ϵ����Ϣ    **\n");
	printf("**        5. ��ʾ������ϵ��            6. ���������ϵ��    **\n");
	printf("**        7. ��ϵ������                0. �˳�              **\n");
	printf("**************************************************************\n");
}

void test()
{
	int input = 1;
	Contacts contacts;
	InitContacts(&contacts);
	while (input)
	{
		menu();
		printf("��ѡ��>> ");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳��ɹ���\n");
			break;
		case ADD:
			Add(&contacts);
			break;
		case DEL:
			Del(&contacts);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			Show(&contacts);
			break;
		case EMPTY:
			Empty(&contacts);
			break;
		case SORT:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
}

int main()
{
	test();
	return 0;
}