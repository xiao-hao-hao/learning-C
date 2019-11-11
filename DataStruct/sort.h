#ifndef _SORT_H_
#define _SORT_H

#include "common.h"

void Swap(int *a, int *b);
void PrintArray(int *ar, int left, int right);
void InsertSort_1(int *ar, int left, int right);//插入排序
void InsertSort_2(int *ar, int left, int right);
void BinInsertSort(int *ar, int left, int right);//二分插入排序
void ShellSort(int *ar, int left, int right);
void TwoWayInsertSort(int *ar, int left, int right);
void SelectSort(int *ar, int left, int right);
void HeapSort(int *ar, int left, int right);
void BubbleSort_1(int *ar, int left, int right);
void BubbleSort_2(int *ar, int left, int right);
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
		ar[0] = ar[i];//a[0]用来做哨兵位，不用来存放数据，同时可作为临时空间，不用再调交换函数了
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

void TwoWayInsertSort(int *ar, int left, int right)//二路插入排序  left 和 right可以任意选
{
	int i = 0;
	int k = 0;
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int) * n);//分配空间消耗大量时间
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
		else
		{
			int end = last;
			while(ar[i] < tmp[end])
			{
				tmp[(end+1)%n] = tmp[end];
				end = (end-1+n) % n;
			}
			tmp[(end+1)%n] = ar[i];
			++last;
		}
	}
	k = left;
	for(i = first; k <= right;)
	{
		ar[k++] = tmp[i];
		i = (i+1) % n;
	}
	free(tmp);
	tmp = NULL;
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

//选择排序

int GetMinIndex(int *ar, int left, int right)
{
	int min_value = ar[left];
	int index = left;
	int i = 0;
	for(i = left+1; i <= right; ++i)
	{
		if(ar[i] < min_value)
		{
			min_value = ar[i];
			index = i;
		}
	}
	return index;
}

void SelectSort(int *ar, int left, int right)
{
	int i = 0;
	for(i = left; i < right; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if(index != i)
			Swap(&ar[index], &ar[i]);
	}
}

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

//堆排序
void _AdjustDown(int *ar, int left, int right, int start)//向下调整  可以任选left 和 right
{
	//int n = right - left + 1;
	int i = start + left;
	int j = 2 * start + 1 + left;
	while(j <= right)
	{
		if(j+1<=right && ar[j]<ar[j+1])
			++j;
		if(ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2 * (i-left) + 1 + left;
		}
		else
			break;
	}
}

void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int start = n/2 - 1;
	int end = 0;
	while(start >= 0)//调整为大堆
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	end = right;
	while(end > left)
	{
		Swap(&ar[left], &ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//再次调整为大堆
	}
}


//交换排序
//1、冒泡排序
void BubbleSort_1(int *ar, int left, int right)
{
	int i = 0;
	int j = 0;
	//int n = right - left + 1;
	for(i = left; i < right; ++i)
	{
		for(j = left; j < right - i + left; ++j)
		{
			if(ar[j] > ar[j+1])
				Swap(&ar[j], &ar[j+1]);
		}
	}
}

void BubbleSort_2(int *ar, int left, int right)
{
	int i = 0;
	int j = 0;
	int is_swap = 0;//用来判断交换与否，没有交换表明数据已经排好序
	//int n = right - left + 1;
	for(i = left; i < right; ++i)
	{
		for(j = left; j < right - i + left; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				Swap(&ar[j], &ar[j+1]);
				is_swap = 1;
			}
		}
		if(is_swap)
			is_swap = 0;
		else
			break;
	}
}

void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);//插入排序
	//InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	//ShellSort(ar, left, right);
	//TwoWayInsertSort(ar, left, right);
	//SelectSort(ar, left, right);
	//HeapSort(ar, left, right);
	//BubbleSort_1(ar, left, right);
	BubbleSort_2(ar, left, right);
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
	int *a4 = (int*)malloc(sizeof(int) * n);
	int *a5 = (int*)malloc(sizeof(int) * n);
	int *a6 = (int*)malloc(sizeof(int) * n);
	int *a7 = (int*)malloc(sizeof(int) * n);
	int *a8 = (int*)malloc(sizeof(int) * n);
	int *a9 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for(i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
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

	start = clock();
	TwoWayInsertSort(a5, 0, n-1);
	end = clock();
	printf("TwoWaySort: %u\n", end - start);

	start = clock();
	SelectSort(a6, 0, n-1);
	end = clock();
	printf("SelectSort: %u\n", end - start);

	start = clock();
	HeapSort(a7, 0, n-1);
	end = clock();
	printf("HeapSort: %u\n", end - start);

	start = clock();
	BubbleSort_1(a8, 0, n-1);
	end = clock();
	printf("BubbleSort_1: %u\n", end - start);

	start = clock();
	BubbleSort_2(a9, 0, n-1);
	end = clock();
	printf("BubbleSort_2: %u\n", end - start);
}
#endif