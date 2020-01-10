#ifndef _GAME_H_
#define _GAME_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 //游戏的维数

/*
 * 函数名:initGame
 * 功能:对游戏界面数据进行初始化，并产生两个随机数
 * 参数:需要初始化的游戏数据
 * 返回值:无
*/
void initGame(int data[N][N]);

/*
 * 函数名:showGame
 * 功能:显示游戏界面
 * 参数:需要显示的游戏数据
 * 返回值:无
*/
void showGame(int data[N][N]);

/*
 * 函数名:getRand
 * 功能:在游戏数据中产生一个随机数，2的概率为80%，4的概率为20%
 * 参数:需要产生随机数的游戏数据
 * 返回值:无
*/
void getRand(int data[N][N]);

/*
 * 函数名:checkGameOver
 * 功能:检查游戏是否结束
 * 参数:需要检查的游戏数据
 * 返回值:游戏结束返回1，没有结束返回0
*/
int checkGameOver(int data[N][N]);

#endif