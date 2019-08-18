#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****          1.play         *****\n");
	printf("*****          0.exit         *****\n");
	printf("***********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};//���ڴ���׺ͷ��׵�����
	char show[ROWS][COLS] = {0};//������������ʾ����
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show, ROW, COL);
	Setmine(mine, ROW, COL, MineCount);
	FirstFind(mine, show, ROW, COL);//ȷ����һ�β�����
	Findmine(mine, show, ROW, COL);//��������

}

void test()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default :
			printf("ѡ�����������ѡ��\n");
		}
	} while (i);
}

int main()
{
	test();
	return 0;
}