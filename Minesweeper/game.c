#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//printf("---------------------------\n");
	printf("   ");
	for (i = 1; i <= row; ++i)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; ++i)
	{
		printf("%d> ", i);
		for (j = 1; j <= col; ++j)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------\n");
}

void Setmine(char mine[ROWS][COLS], int row, int col, int num)
{
	int count = num;
	while (count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if(mine[i][j] == '0')
		{
			mine[i][j] = '1';
			--count;
		}
	}
}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (!(IsSuccess(show, row, col)))
	{
		printf("���������׵�����>> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("��λ���Ѿ��Ź��ˣ���ѡ������λ�ã�\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("����ը���ˣ���Ϸ������\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				//ͳ��x,y��Χ�ж��ٸ���
				int count = get_mine(mine, x, y);
				show[x][y] = '0' + count;
				extend(mine, show, row, col, x, y);
				Displayboard(show, ROW, COL);
			}
		}
		else
		{
			printf("�����������Ƿ������������룡\n");
		}
	}
	if (IsSuccess(show, row, col))
	{
		printf("��ϲ�������׳ɹ���\n");
	}
}

int get_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y-1] +
		   mine[x-1][y] +
		   mine[x-1][y+1] +
		   mine[x][y+1] +
		   mine[x+1][y+1] +
		   mine[x+1][y] +
		   mine[x+1][y-1] +
		   mine[x][y-1] - '0'*8;
}

void FirstFind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (1)
	{
		printf("���������׵�����>> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if ('1' == mine[x][y])
			{
				mine[x][y] = '0';
				Setmine(mine, row, col, 1);
			}
			count = get_mine(mine, x, y);
			show[x][y] = count + '0';
			extend(mine, show, row, col, x, y);
			Displayboard(show, row, col);
			break;
		}
		else
			printf("�����������Ƿ������������룡\n");
	}
}

void extend(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//�õݹ�ʵ����������չ��
{
	int num = get_mine(mine, x, y);
	if (0 == num)
	{
		if (x - 1 > 0 && y - 1 > 0 && show[x-1][y-1] == '*')
		{
			show[x-1][y-1] = get_mine(mine, x-1, y-1) + '0';
			extend(mine, show, row, col, x - 1, y - 1);
		}
		if (x > 0 && y - 1 > 0 && show[x][y-1] == '*')
		{
			show[x][y-1] = get_mine(mine, x, y-1) + '0';
			extend(mine, show, row, col, x, y - 1);
		}
		if (x + 1 <= row && y - 1 > 0 && show[x+1][y-1] == '*')
		{
			show[x+1][y-1] = get_mine(mine, x+1, y-1) + '0';
			extend(mine, show, row, col, x + 1, y - 1);
		}
		if (x + 1 <= row && show[x+1][y] == '*')
		{
			show[x+1][y] = get_mine(mine, x+1, y) + '0';
			extend(mine, show, row, col, x + 1, y);
		}
		if (x + 1 <= row && y + 1 <= col && show[x+1][y+1] == '*')
		{
			show[x+1][y+1] = get_mine(mine, x+1, y+1) + '0';
			extend(mine, show, row, col, x + 1, y + 1);
		}
		if (y + 1 <= col && show[x][y+1] == '*')
		{
			show[x][y+1] = get_mine(mine, x, y+1) + '0';
			extend(mine, show, row, col, x, y + 1);
		}
		if (x - 1 > 0 && y + 1 <= col && show[x-1][y+1] == '*')
		{
			show[x-1][y+1] = get_mine(mine, x-1, y+1) + '0';
			extend(mine, show, row, col, x - 1, y + 1);
		}
		if (x - 1 <= row && show[x-1][y] == '*')
		{
			show[x-1][y] = get_mine(mine, x-1, y) + '0';
			extend(mine, show, row, col, x - 1, y);
		}
	}
	else
	{
		show[x][y] = get_mine(mine, x, y) + '0';
	}
}

int IsSuccess(char show[ROWS][COLS], int row, int col)//����1��ʾ���׳ɹ�������0��ʾ������δ�ɹ�
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; ++i)
	{
		for (j = 1; j <= col; ++j)
		{
			if (show[i][j] != '*')
			{
				++count;
			}
		}
	}
	if (count == row * col - MineCount)
		return 1;
	return 0;
}