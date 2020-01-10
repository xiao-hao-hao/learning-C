#ifndef _GAME_H_
#define _GAME_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 //��Ϸ��ά��

/*
 * ������:initGame
 * ����:����Ϸ�������ݽ��г�ʼ�������������������
 * ����:��Ҫ��ʼ������Ϸ����
 * ����ֵ:��
*/
void initGame(int data[N][N]);

/*
 * ������:showGame
 * ����:��ʾ��Ϸ����
 * ����:��Ҫ��ʾ����Ϸ����
 * ����ֵ:��
*/
void showGame(int data[N][N]);

/*
 * ������:getRand
 * ����:����Ϸ�����в���һ���������2�ĸ���Ϊ80%��4�ĸ���Ϊ20%
 * ����:��Ҫ�������������Ϸ����
 * ����ֵ:��
*/
void getRand(int data[N][N]);

/*
 * ������:checkGameOver
 * ����:�����Ϸ�Ƿ����
 * ����:��Ҫ������Ϸ����
 * ����ֵ:��Ϸ��������1��û�н�������0
*/
int checkGameOver(int data[N][N]);

#endif