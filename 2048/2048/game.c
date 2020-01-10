#include "game.h"

void initGame(int data[N][N])
{
	int x = 0, y = 0;

	//初始化游戏数据
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			data[x][y] = 0;//所有数据清零
		}
	}
	srand(time(NULL));//设置随机种子
	getRand(data);
	getRand(data);
}

/*
* 函数名:showGame
* 功能:显示游戏界面
* 参数:需要显示的游戏数据
* 返回值:无
*/
void showGame(int data[N][N])
{
	int x = 0, y = 0;
	printf("欢迎来到2048游戏！");
	printf("(按'q'退出游戏)\n");

	//打印所有数据
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			printf("%5d", data[x][y]);
		}
		printf("\n");
	}
}

/*
* 函数名:getRand
* 功能:在游戏数据中产生一个随机数，2的概率为80%，4的概率为20%
* 参数:需要产生随机数的游戏数据
* 返回值:无
*/
void getRand(int data[N][N])
{
	int x = 0, y = 0;
	int idx = 0;//随机种子索引
	int seedList[] = { 2, 2, 2, 2, 2, 2, 2, 2, 4, 4 };//值列表
	while (1)
	{
		//随机定位
		x = rand() % N;
		y = rand() % N;

		//定位的位置有值了
		if (data[x][y] != 0)
			continue;
		
		//空白位置产生值
		idx = rand() % 10;
		data[x][y] = seedList[idx];
		return;
	}
}

/*
* 函数名:checkGameOver
* 功能:检查游戏是否结束
* 参数:需要检查的游戏数据
* 返回值:游戏结束返回1，没有结束返回0
*/
int checkGameOver(int data[N][N])
{
	int x = 0, y = 0;

	//判断有无空位0
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			if (data[x][y] == 0)
			{
				return 0;
			}
		}
	}

	//判断各行是否可加
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N - 1; ++y)
		{
			if (data[x][y] == data[x][y + 1])
			{
				return 0;
			}
		}
	}
	
	//判断各列是否可加
	for (y = 0; y < N; ++y)
	{
		for (x = 0; x < N - 1; ++x)
		{
			if (data[x][y] == data[x + 1][y])
			{
				return 0;
			}
		}
	}
	//游戏结束
	return 1;
}