#include "game.h"

int main()
{
	int gameData[N][N];  //游戏数据

	//初始化游戏
	initGame(gameData);

	//显示游戏
	showGame(gameData);
	return 0;
}
