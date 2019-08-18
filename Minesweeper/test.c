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
	char mine[ROWS][COLS] = {0};//用于存放雷和非雷的数组
	char show[ROWS][COLS] = {0};//该数组用于显示界面
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show, ROW, COL);
	Setmine(mine, ROW, COL, MineCount);
	FirstFind(mine, show, ROW, COL);//确保第一次不是雷
	Findmine(mine, show, ROW, COL);//进行排雷

}

void test()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default :
			printf("选择错误，请重新选择！\n");
		}
	} while (i);
}

int main()
{
	test();
	return 0;
}