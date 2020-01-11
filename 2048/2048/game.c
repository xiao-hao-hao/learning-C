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
	system("cls"); //��ӡǰ������
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
	printf("��ǰ��߼�¼��%d\n", maxScore(data));
	fflush(stdin);//��ջ����������⡰�س����ַ�����ȡ
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

/*
* ������:exitGame()
* ����:�˳���Ϸ
* ����:��
* ����ֵ:��
*/
void exitGame(void)
{
	system("cls");
	exit(0);
}

/*
* ������:maxScore
* ����:��ȡ��Ϸ�����е������
* ����:��Ҫ���ҵ���Ϸ����
* ����ֵ:��Ϸ�����е����ֵ
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
* ������:moveUp
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveUp(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //���ƶ����λ
	//���ۼ�
	for (y = 0; y < N; ++y)
	{
		for (x = 0; x < N; ++x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//�ж��Ƿ�ɼӣ��ܼ����
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
					data[x][y] += data[idx][y];//�ܼ����
					data[idx][y] = 0;//����֮������0�Ա��ڲ�Ӱ���´��жϣ���0���´ξͲ����жϸ�λ��
					isChange = 1;
					break;
				}
			}
		}
	}

	//�ۼӺ��ƶ�
	for (y = 0; y < N; ++y)
	{
		for (x = 1; x < N; ++x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = x - 1;//��x-1λ�ÿ�ʼ��
			while (data[idx][y] == 0 && idx >= 0)//һֱ��������߳�����Χ����
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

	//�ɹ��ƶ�֮����Ҫ�������һ����
	if(isChange == 1)
	{
		getRand(data);
	}
}

/*
* ������:moveDown
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveDown(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //���ƶ����λ
	//���ۼ�
	for (y = 0; y < N; ++y)
	{
		for (x = N- 1; x > 0; --x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//�ж��Ƿ�ɼӣ��ܼ����
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
					data[x][y] += data[idx][y];//�ܼ����
					data[idx][y] = 0;//����֮������0�Ա��ڲ�Ӱ���´��жϣ���0���´ξͲ����жϸ�λ��
					isChange = 1;
					break;
				}
			}
		}
	}

	//�ۼӺ��ƶ�
	for (y = 0; y < N; ++y)
	{
		for (x = N - 2; x >= 0; --x)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = x + 1;//��x-1λ�ÿ�ʼ��
			while (data[idx][y] == 0 && idx <= N - 1)//һֱ��������߳�����Χ����
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

	//�ɹ��ƶ�֮����Ҫ�������һ����
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* ������:moveLeft
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveLeft(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //���ƶ����λ
	//���ۼ�
	for (x = 0; x < N; ++x)
	{
		for (y = 0; y < N; ++y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//�ж��Ƿ�ɼӣ��ܼ����
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
					data[x][y] += data[x][idx];//�ܼ����
					data[x][idx] = 0;//����֮������0�Ա��ڲ�Ӱ���´��жϣ���0���´ξͲ����жϸ�λ��
					isChange = 1;
					break;
				}
			}
		}
	}

	//�ۼӺ��ƶ�
	for (x = 0; x < N; ++x)
	{
		for (y = 1; y < N; ++y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = y - 1;//��y-1λ�ÿ�ʼ��
			while (data[x][idx] == 0 && idx >= 0)//һֱ��������߳�����Χ����
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

	//�ɹ��ƶ�֮����Ҫ�������һ����
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* ������:moveRight
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveRight(int data[N][N])
{
	int x = 0, y = 0;
	int idx;
	int isChange = 0;  //���ƶ����λ
	//���ۼ�
	for (x = 0; x < N; ++x)
	{
		for (y = N - 1; y > 0; --y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			//�ж��Ƿ�ɼӣ��ܼ����
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
					data[x][y] += data[x][idx];//�ܼ����
					data[x][idx] = 0;//����֮������0�Ա��ڲ�Ӱ���´��жϣ���0���´ξͲ����жϸ�λ��
					isChange = 1;
					break;
				}
			}
		}
	}

	//�ۼӺ��ƶ�
	for (x = 0; x < N; ++x)
	{
		for (y = N - 2; y >= 0; --y)
		{
			if (data[x][y] == 0)
			{
				continue;
			}
			idx = y + 1;//��x-1λ�ÿ�ʼ��
			while (data[x][idx] == 0 && idx <= N - 1)//һֱ��������߳�����Χ����
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

	//�ɹ��ƶ�֮����Ҫ�������һ����
	if (isChange == 1)
	{
		getRand(data);
	}
}

/*
* ������:getInput
* ����:��ȡ�û�������
* ����:��
* ����ֵ:�����û�����İ���
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
* ������:checkGameWin
* ����:�ж�����Ƿ�Ӯ�ñ���
* ����:��Ҫ�жϵ���Ϸ����
* ���Ӯ�򷵻�1�����򷵻�0
*/
int checkGameWin(int maxScore)
{
	if (maxScore >= 2048)
	{
		return 1;
	}
	return 0;
}