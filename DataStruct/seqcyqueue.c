//ʹ��˳��ѭ�����п������ÿռ䣬���ҳ��Ӳ���Ҫ�ƶ�Ԫ��
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include "seqcyqueue.h"

int main()
{
	SeqCyQueue Q;
	int select = 1;
	DataType data;
	DataType ret;
	SeqCyQueueInit(&Q, QUEUE_DEFAULE_SIZE);
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
			SeqCyQueueEn(&Q, data);
			break;
		case 2:
			SeqCyQueueDe(&Q);
			break;
		case 3:
			SeqCyQueueShow(&Q);
			break;
		case 4:
			if(SeqCyQueueFront(&Q, &ret))
				printf("%d\n", ret);
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
	SeqCyQueueDestroy(&Q);
	return 0;
}

#endif