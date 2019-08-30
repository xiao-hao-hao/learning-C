#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("**************************************************************\n");
	printf("**        1. 添加联系人                2. 删除联系人        **\n");
	printf("**        3. 查找联系人                4. 修改联系人信息    **\n");
	printf("**        5. 显示所有联系人            6. 清空所有联系人    **\n");
	printf("**        7. 联系人按姓名排序          0. 退出              **\n");
	printf("**************************************************************\n");
}

void test()
{
	int input = 1;
	address_book book;
	address_book_init(&book);//初始化通讯录
	while (input)
	{
		menu();
		printf("请选择>> ");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			save_address_book(&book);
			printf("退出成功！\n");
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
			printf("选择错误，请重新选择！\n");
			break;
		}
	}
}

int main()
{
	test();
	return 0;
}