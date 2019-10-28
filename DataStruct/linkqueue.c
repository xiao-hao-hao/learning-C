#if 0
//链式队列

#define _CRT_SECURE_NO_WARNINGS 1
#include "linkqueue.h"

int main()
{
	int select = 1;
	DataType data = 0;
	DataType ret = 0;
	LinkQueue Q;
	LinkQueueInit(&Q);
	while(select)
	{
		printf("************************\n");
		printf("* [1]Enter      [2]Del *\n");
		printf("* [3]Show       [0]exit*\n");
		printf("* [4]Front             *\n");
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
			printf("请输入要入队的值:>");
			scanf("%d", &data);
			LinkQueueEn(&Q, data);
			break;
		case 2:
			LinkQueueDe(&Q);
			break;
		case 3:
			LinkQueueShow(&Q);
			break;
		case 4:
			if(LinkQueueFront(&Q, &ret))
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
	return 0;
}

#endif