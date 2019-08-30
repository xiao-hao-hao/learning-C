#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("**************************************************************\n");
	printf("**        1. �����ϵ��                2. ɾ����ϵ��        **\n");
	printf("**        3. ������ϵ��                4. �޸���ϵ����Ϣ    **\n");
	printf("**        5. ��ʾ������ϵ��            6. ���������ϵ��    **\n");
	printf("**        7. ��ϵ�˰���������          0. �˳�              **\n");
	printf("**************************************************************\n");
}

void test()
{
	int input = 1;
	address_book book;
	address_book_init(&book);//��ʼ��ͨѶ¼
	while (input)
	{
		menu();
		printf("��ѡ��>> ");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			save_address_book(&book);
			printf("�˳��ɹ���\n");
			break;
		case ADD:
			address_book_add(&book);
			break;
		case DEL:
			address_book_del(&book);
			break;
		case SEARCH:
			address_book_find(&book);
			break;
		case MODIFY:
			address_book_update(&book);
			break;
		case SHOW:
			address_book_show(&book);
			break;
		case EMPTY:
			address_book_del_all(&book);
			break;
		case SORT:
			sort_by_name(&book);
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