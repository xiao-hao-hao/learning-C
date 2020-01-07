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
	//getRand(data);
	//getRand(data);
}