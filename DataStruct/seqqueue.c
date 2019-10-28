//顺序队列
//存在很大的问题，空间只能被用一次(除非将数据左移，当数据量很大时，时间都浪费在数据移动上)
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include "seqqueue.h"

int main()
{
	SeqQueue Q;
	int select = 1;
	DataType data;
	SeqQueueInit(&Q, QUEUE_DEFAULE_SIZE);
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
			SeqQueueEn(&Q, data);
			break;
		case 2:
			SeqQueueDe(&Q);
			break;
		case 3:
			SeqQueueShow(&Q);
			break;
		case 4:
			if(SeqQueueFront(&Q))
				printf("%d\n", Q.base[Q.front]);
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