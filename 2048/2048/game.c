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
	//getRand(data);
	//getRand(data);
}