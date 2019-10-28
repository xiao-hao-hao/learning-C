#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include "liststack.h"

int main()
{
	ListStack st;
	int select = 1;
	DataType ret = 0;
	DataType data = 0;
	ListStackInit(&st);
	while(select)
	{
		printf("************************\n");
		printf("* [1]push       [2]pop *\n");
		printf("* [3]show       [0]exit*\n");
		printf("* [4]top               *\n");
		printf("************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch(select)
		{
        case 0:
			system("cls");
			printf("退出成功!\n");
            break;
		case 1:
			printf("请输入要入栈的值:>");
			scanf("%d", &data);
			ListStackPush(&st, data);
			break;
		case 2:
			ListStackPop(&st);
			break;
		case 3:
			ListStackShow(st);
			break;
		case 4:
			if(ListStackTop(st, &ret))
				printf("%d\n", ret);
			break;
		default:
            printf("输入错误，请重新输入!\n");
            break;
        }
		if(select != 0)
		{
			system("pause");
			system("cls");		
		}
	}
	Destroy(&st);
	return 0;
}

#endif