#if 0
//��ʽ����

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