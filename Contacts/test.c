#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("**************************************************************\n");
	printf("**        1. 添加联系人                2. 删除联系人        **\n");
	printf("**        3. 查找联系人                4. 修改联系人信息    **\n");
	printf("**        5. 显示所有联系人            6. 清空所有联系人    **\n");
	printf("**        7. 联系人排序                0. 退出              **\n");
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
		printf("请选择>> ");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出成功！\n");
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