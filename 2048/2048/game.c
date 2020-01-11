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
	system("cls"); //打印前先清屏
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
	printf("当前最高记录：%d\n", maxScore(data));
	fflush(stdin);//清空缓冲区，避免“回车”字符被读取
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

/*
* 函数名:exitGame()
* 功能:退出游戏
* 参数:无
* 返回值:无
*/
void exitGame(void)
{
	system("cls");
	exit(0);
}

/*
* 函数名:maxScore
* 功能:获取游戏数据中的最大数
* 参数:需要查找的游戏数据
* 返回值:游戏数据中的最大值
*/
int maxScore(int data[N][N])
{
	int x = 0, y = 0;
	int maxValue = 0;
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			if (maxValue < data[x][y])
			{
				maxValue = data[x][y];
			}
		}
	}
	return maxValue;
}

/*
* 函数名:moveUp
* 功能:把游戏数据上移
* 参数:需要上移的游戏数据
* 返回值:无
*/
void moveUp(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //可移动标记位
	//先累加
	for (y = 0; y < N; ++y)
	{
		for (x = 0; x < N; ++x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//判断是否可加，能加则加
			for (idx = x + 1; idx <= N - 1; ++idx)
			{
				if (data[idx][y] == 0)
				{
					continue;
				}
				else if (data[idx][y] != data[x][y])
				{
					break;
				}
				else
				{
					data[x][y] += data[idx][y];//能加则加
					data[idx][y] = 0;//加完之后将其置0以便于不影响下次判断，置0后下次就不会判断改位了
					isChange = 1;
					break;
				}
			}
		}
	}

	//累加后移动
	for (y = 0; y < N; ++y)
	{
		for (x = 1; x < N; ++x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = x - 1;//从x-1位置开始查
			while (data[idx][y] == 0 && idx >= 0)//一直到非零或者超出范围结束
			{
				--idx;
			}
			if (data[idx + 1][y] == 0)
			{
				data[idx + 1][y] = data[x][y];
				data[x][y] = 0;
				isChange = 1;
			}
		}
	}

	//成功移动之后需要随机产生一个数
	if(isChange == 1)
	{
		getRand(data);
	}
}

/*
* 函数名:moveDown
* 功能:把游戏数据下移
* 参数:需要下移的游戏数据
* 返回值:无
*/
void moveDown(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //可移动标记位
	//先累加
	for (y = 0; y < N; ++y)
	{
		for (x = N- 1; x > 0; --x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//判断是否可加，能加则加
			for (idx = x - 1; idx >= 0; --idx)
			{
				if (data[idx][y] == 0)
				{
					continue;
				}
				else if (data[idx][y] != data[x][y])
				{
					break;
				}
				else
				{
					data[x][y] += data[idx][y];//能加则加
					data[idx][y] = 0;//加完之后将其置0以便于不影响下次判断，置0后下次就不会判断改位了
					isChange = 1;
					break;
				}
			}
		}
	}

	//累加后移动
	for (y = 0; y < N; ++y)
	{
		for (x = N - 2; x >= 0; --x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = x + 1;//从x-1位置开始查
			while (data[idx][y] == 0 && idx <= N - 1)//一直到非零或者超出范围结束
			{
				++idx;
			}
			if (data[idx - 1][y] == 0)
			{
				data[idx - 1][y] = data[x][y];
				data[x][y] = 0;
				isChange = 1;
			}
		}
	}

	//成功移动之后需要随机产生一个数
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* 函数名:moveLeft
* 功能:把游戏数据左移
* 参数:需要左移的游戏数据
* 返回值:无
*/
void moveLeft(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //可移动标记位
	//先累加
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//判断是否可加，能加则加
			for (idx = y + 1; idx <= N - 1; ++idx)
			{
				if (data[x][idx] == 0)
				{
					continue;
				}
				else if (data[x][idx] != data[x][y])
				{
					break;
				}
				else
				{
					data[x][y] += data[x][idx];//能加则加
					data[x][idx] = 0;//加完之后将其置0以便于不影响下次判断，置0后下次就不会判断改位了
					isChange = 1;
					break;
				}
			}
		}
	}

	//累加后移动
	for (x = 0; x < N; ++x)
	{
		for (y = 1; y < N; ++y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = y - 1;//从y-1位置开始查
			while (data[x][idx] == 0 && idx >= 0)//一直到非零或者超出范围结束
			{
				--idx;
			}
			if (data[x][idx + 1] == 0)
			{
				data[x][idx + 1] = data[x][y];
				data[x][y] = 0;
				isChange = 1;
			}
		}
	}

	//成功移动之后需要随机产生一个数
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* 函数名:moveRight
* 功能:把游戏数据右移
* 参数:需要右移的游戏数据
* 返回值:无
*/
void moveRight(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //可移动标记位
	//先累加
	for (x = 0; x < N; ++x)
	{
		for (y = N - 1; y > 0; --y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//判断是否可加，能加则加
			for (idx = y - 1; idx >= 0; --idx)
			{
				if (data[x][idx] == 0)
				{
					continue;
				}
				else if (data[x][idx] != data[x][y])
				{
					break;
				}
				else
				{
					data[x][y] += data[x][idx];//能加则加
					data[x][idx] = 0;//加完之后将其置0以便于不影响下次判断，置0后下次就不会判断改位了
					isChange = 1;
					break;
				}
			}
		}
	}

	//累加后移动
	for (x = 0; x < N; ++x)
	{
		for (y = N - 2; y >= 0; --y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = y + 1;//从x-1位置开始查
			while (data[x][idx] == 0 && idx <= N - 1)//一直到非零或者超出范围结束
			{
				++idx;
			}
			if (data[x][idx - 1] == 0)
			{
				data[x][idx - 1] = data[x][y];
				data[x][y] = 0;
				isChange = 1;
			}
		}
	}

	//成功移动之后需要随机产生一个数
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* 函数名:getInput
* 功能:获取用户的输入
* 参数:无
* 返回值:返回用户输入的按键
*/
int getInput(void)
{
	char ch;
	int key;
	//ch = getchar();
	ch = _getch();
	switch (ch)
	{
	case 'u': key = UP; break;
	case 'd': key = DOWN; break;
	case 'l': key = LEFT; break;
	case 'r': key = RIGHT; break;
	case 'q': key = EXIT; break;
	default: key = OTHER; break;
	}
	return key;
}

/*
* 函数名:checkGameWin
* 功能:判断玩家是否赢得比赛
* 参数:需要判断的游戏数据
* 玩家赢则返回1，否则返回0
*/
int checkGameWin(int maxScore)
{
	if (maxScore >= 2048)
	{
		return 1;
	}
	return 0;
}