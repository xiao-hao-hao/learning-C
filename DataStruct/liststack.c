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
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch(select)
		{
        case 0:
			system("cls");
			printf("�˳��ɹ�!\n");
            break;
		case 1:
			printf("������Ҫ��ջ��ֵ:>");
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
            printf("�����������������!\n");
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