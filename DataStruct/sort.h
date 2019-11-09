#ifndef _SORT_H_
#define _SORT_H

#include "common.h"

void Swap(int *a, int *b);
void PrintArray(int *ar, int left, int right);
void InsertSort_1(int *ar, int left, int right);//插入排序
void InsertSort_2(int *ar, int left, int right);
void BinInsertSort(int *ar, int left, int right);//二分插入排序
void ShellSort(int *ar, int left, int right);
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

void TwoWayInsertSort(int *ar, int left, int right)//二路插入排序
{
	int i = 0;
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int) * n);
	int first, last;//用于作为临时空间的头和尾的标志（临时空间看作循环空间）
	tmp[0] = ar[left];//假设第一个元素已经排好序
	first = last = 0;
	for(i=left+1; i<=right; ++i)
	{
		if(ar[i] < tmp[first])
		{
			first = (first-1+n) % n;
			tmp[first] = ar[i];
		}
		else if(ar[i] > tmp[last])
		{
			tmp[++last] = ar[i];
		}
	}
}


/*
void _ShellSort(int *ar, int left, int right, int gap)
{
	int i = 0;
	for(i = left; i <= right - gap; ++i)//这里的插入排序是多个序列混排的
	{
		if(ar[i+gap] < ar[i])//防止已经比较过的元素重复比较，不加也行
		{
			int end = i;
			int tmp = ar[end + gap];
			while(end >= left && tmp < ar[end])//插入排序
			{
				ar[end + gap] = ar[end];
				end -= gap;
			}
			ar[end+gap] = tmp;
		}
	}
}

void ShellSort(int *ar, int left, int right)
{
	int i = 0;
	int dlta[] = {5, 3, 2, 1};
	int n = sizeof(dlta) / sizeof(dlta[0]);
	for(i = 0; i < n; ++i)
	{
		_ShellSort(ar, left, right, dlta[i]);
	}
}
*/


void ShellSort(int *ar, int left, int right)//希尔排序 不稳定
{
	int gap = right - left + 1;
	while(gap > 1)
	{
		int i = 0;
		gap = gap/3 + 1;
		for(i = left; i <= right-gap; ++i)
		{
			if(ar[i+gap] < ar[i])
			{
				int end = i;
				int tmp = ar[end+gap];
				while(end>=left && tmp<ar[end])
				{
					ar[end+gap] = ar[end];
					end -= gap;
				}
				ar[end+gap] = tmp;
			}
		}

	}
}



void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);//插入排序
	//InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	ShellSort(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSortEfficiency()
{
	int n = 50000;
	int i = 0;
	time_t start = 0;
	time_t end = 0;
	int *a1 = (int*)malloc(sizeof(int) * n);
	int *a2 = (int*)malloc(sizeof(int) * n);
	int *a3 = (int*)malloc(sizeof(int) * n);
	int *a4 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for(i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
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

	start = clock();
	ShellSort(a4, 0, n-1);
	end = clock();
	printf("ShellSort: %u\n", end - start);
}
#endif