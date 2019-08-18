#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS (ROW+2)
#define COLS (COL+2)
#define MineCount 10

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col, int num);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine(char mine[ROWS][COLS], int x, int y);
void FirstFind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void extend(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
int IsSuccess(char show[ROWS][COLS], int row, int col);