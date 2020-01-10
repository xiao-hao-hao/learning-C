#include "game.h"

void initGame(int data[N][N])
{
	int x = 0, y = 0;

	//��ʼ����Ϸ����
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			data[x][y] = 0;//������������
		}
	}
	srand(time(NULL));//�����������
	getRand(data);
	getRand(data);
}

/*
* ������:showGame
* ����:��ʾ��Ϸ����
* ����:��Ҫ��ʾ����Ϸ����
* ����ֵ:��
*/
void showGame(int data[N][N])
{
	int x = 0, y = 0;
	printf("��ӭ����2048��Ϸ��");
	printf("(��'q'�˳���Ϸ)\n");

	//��ӡ��������
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
* ������:getRand
* ����:����Ϸ�����в���һ���������2�ĸ���Ϊ80%��4�ĸ���Ϊ20%
* ����:��Ҫ�������������Ϸ����
* ����ֵ:��
*/
void getRand(int data[N][N])
{
	int x = 0, y = 0;
	int idx = 0;//�����������
	int seedList[] = { 2, 2, 2, 2, 2, 2, 2, 2, 4, 4 };//ֵ�б�
	while (1)
	{
		//�����λ
		x = rand() % N;
		y = rand() % N;

		//��λ��λ����ֵ��
		if (data[x][y] != 0)
			continue;
		
		//�հ�λ�ò���ֵ
		idx = rand() % 10;
		data[x][y] = seedList[idx];
		return;
	}
}

/*
* ������:checkGameOver
* ����:�����Ϸ�Ƿ����
* ����:��Ҫ������Ϸ����
* ����ֵ:��Ϸ��������1��û�н�������0
*/
int checkGameOver(int data[N][N])
{
	int x = 0, y = 0;

	//�ж����޿�λ0
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

	//�жϸ����Ƿ�ɼ�
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
	
	//�жϸ����Ƿ�ɼ�
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
	//��Ϸ����
	return 1;
}