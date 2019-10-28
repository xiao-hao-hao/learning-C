#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include "seqstack.h"

int main()
{
	SeqStack st;
	int select = 1;
	DataType ret = 0;
	DataType data = 0;
	//SeqStack *pst = SeqStackCreate(STACK_DEFAULT_SIZE);
	SeqStackInit(&st, STACK_DEFAULT_SIZE);
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
			SeqStackPush(&st, data);
			break;
		case 2:
			SeqStackPop(&st);
			break;
		case 3:
			SeqStackShow(&st);
			break;
		case 4:
			if(SeqStackTop(&st, &ret))
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