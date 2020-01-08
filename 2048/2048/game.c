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