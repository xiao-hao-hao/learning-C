//˳�����
//���ںܴ�����⣬�ռ�ֻ�ܱ���һ��(���ǽ��������ƣ����������ܴ�ʱ��ʱ�䶼�˷��������ƶ���)
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
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch(select)
		{
        case 0:
			system("cls");
			printf("�˳��ɹ�!\n");
            break;
		case 1:
			printf("������Ҫ��ӵ�ֵ:>");
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
            printf("�����������������!\n");
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