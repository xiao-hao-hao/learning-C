#ifndef _SORT_H_
#define _SORT_H

#include "common.h"

void Swap(int *a, int *b);
void PrintArray(int *ar, int left, int right);
void InsertSort_1(int *ar, int left, int right);//插入排序
void InsertSort_2(int *ar, int left, int right);
void BinInsertSort(int *ar, int left, int right);//二分插入排序
void TestSort(int *ar, int left, int right);
void TestSortEfficiency();

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int *ar, int left, int right)
{
	int i = 0;
	for(i = left; i <= right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void InsertSort_1(int *ar, int left, int right)//插入排序
{
	int i = 0;
	for(i = left+1; i <= right; ++i)//假设第一个元素已经排好序
	{
		int j = i;
		while(j>left && ar[j]<ar[j-1])
		{
			Swap(&ar[j], &ar[j-1]);
			--j;
		}
	}
}

void InsertSort_2(int *ar, int left, int right)
{
	int i = 0;
	for(i = left+1; i <= right; ++i)
	{
		int j = i;
		ar[0] = ar[i];//a[0]用来做哨兵位，不用来存放数据，同时可作为临时空间，不用再掉交换函数了
		while(ar[0] < ar[j-1])
		{
			ar[j] = ar[j-1];
			--j;
		}
		ar[j] = ar[0];
	}
}

void BinInsertSort(int *ar, int left, int right)//二分插入排序
{
	int i = 0;
	for(i = left+1; i <= right; ++i)
	{
		int j = 0;
		int low = left;
		int high = i - 1;
		int mid = 0;
		int tmp = ar[i]; 
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(ar[i] >= ar[mid])
				low = mid + 1;
			if(ar[i] < ar[mid])
				high = mid - 1;
		}
		for(j = i; j > low; --j)
		{
			ar[j] = ar[j-1];
		}
		ar[low] = tmp;
	}
}

void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);//插入排序
	InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSortEfficiency()
{
	int n = 10000;
	int i = 0;
	time_t start = 0;
	time_t end = 0;
	int *a1 = (int*)malloc(sizeof(int) * n);
	int *a2 = (int*)malloc(sizeof(int) * n);
	int *a3 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for(i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
	}
	start = clock();
	InsertSort_1(a1, 0, n-1);
	end = clock();
	printf("InsertSort_1: %u\n", end - start);
	start = clock();
	InsertSort_2(a2, 0, n-1);
	end = clock();
	printf("InsertSort_2: %u\n", end - start);
	start = clock();
	BinInsertSort(a3, 0, n-1);
	end = clock();
	printf("BinInsertSort: %u\n", end - start);
}
#endif