#ifndef _SORT_H_
#define _SORT_H

#include "common.h"
#include "liststack.h"

#define M 5

void Swap(int *a, int *b);
void PrintArray(int *ar, int left, int right);
void InsertSort_1(int *ar, int left, int right);//��������
void InsertSort_2(int *ar, int left, int right);
void BinInsertSort(int *ar, int left, int right);//���ֲ�������
void ShellSort(int *ar, int left, int right);
void TwoWayInsertSort(int *ar, int left, int right);
void SelectSort(int *ar, int left, int right);
void HeapSort(int *ar, int left, int right);
void BubbleSort_1(int *ar, int left, int right);
void BubbleSort_2(int *ar, int left, int right);
void QuickSort(int *ar, int left, int right);
void MergeSort(int *ar, int left, int right);
void QuickSortNonR(int *ar, int left, int right);
void CountSort(int *ar, int left, int right);
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

void InsertSort_1(int *ar, int left, int right)//��������
{
	int i = 0;
	for(i = left+1; i <= right; ++i)//�����һ��Ԫ���Ѿ��ź���
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
		ar[0] = ar[i];//a[0]�������ڱ�λ��������������ݣ�ͬʱ����Ϊ��ʱ�ռ䣬�����ٵ�����������
		while(ar[0] < ar[j-1])
		{
			ar[j] = ar[j-1];
			--j;
		}
		ar[j] = ar[0];
	}
}

void BinInsertSort(int *ar, int left, int right)//���ֲ�������
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

void TwoWayInsertSort(int *ar, int left, int right)//��·��������  left �� right��������ѡ
{
	int i = 0;
	int k = 0;
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int) * n);//����ռ����Ĵ���ʱ��
	int first, last;//������Ϊ��ʱ�ռ��ͷ��β�ı�־����ʱ�ռ俴��ѭ���ռ䣩
	tmp[0] = ar[left];//�����һ��Ԫ���Ѿ��ź���+
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
	for(i = left; i <= right - gap; ++i)//����Ĳ��������Ƕ�����л��ŵ�
	{
		if(ar[i+gap] < ar[i])//��ֹ�Ѿ��ȽϹ���Ԫ���ظ��Ƚϣ�����Ҳ��
		{
			int end = i;
			int tmp = ar[end + gap];
			while(end >= left && tmp < ar[end])//��������
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

//ѡ������
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

void ShellSort(int *ar, int left, int right)//ϣ������ ���ȶ�
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

//������
void _AdjustDown(int *ar, int left, int right, int start)//���µ���  ������ѡleft �� right
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
	while(start >= 0)//����Ϊ���
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	end = right;
	while(end > left)
	{
		Swap(&ar[left], &ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//�ٴε���Ϊ���
	}
}


//��������
//1��ð������
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
	int is_swap = 0;//�����жϽ������û�н������������Ѿ��ź���
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

//��������ݹ�ʵ��
int GetMidIndex(int *ar, int left, int right)//����left��right��mid���м�ֵ
{
	int mid = (left+right) / 2;
	if(ar[left]>ar[mid] && ar[left]<ar[right])
		return left;
	if(ar[mid]>ar[left] && ar[mid]<ar[right])
		return mid;
	return right;
}

//hoare�汾��������
int _Partition_1(int *ar, int left, int right)//���ֺ���
{
	int key = ar[left];//����һ��Ԫ����Ϊ��׼ֵ
	while(left < right)//left��right�ı仯ԭ�����ÿ���ƶ���ȽϵĻ�׼��Զ����
	{
		while(left < right && ar[right] >= key)
			--right;
		Swap(&ar[left], &ar[right]);
		while(left < right && ar[left] < key)
			++left;
		Swap(&ar[left], &ar[right]);
	}
	return left;//������һ�ε���ʱ��λ��
}

//�ڿӷ������ǣ�
int _Partition_2(int *ar, int left, int right)
{
	int key = ar[left];
	while(left < right)
	{
		while(left<right && ar[right]>=key)
			--right;
		ar[left] = ar[right];//�����ý�����������Ϊ��׼ֵ�Ѿ���key��¼��
		while(left<right && ar[left]<key)
			++left;
		ar[right] = ar[left];
	}
	ar[left] = key;
	return left;
}

int _Partition_3(int *ar, int left, int right)//��һ���м�ֵ��Ϊ��׼ֵ�����Խ����黮�ֵĸ�����
{
	int index = GetMidIndex(ar, left, right);
	int key = 0;
	int i = 0;
	int pos = 0;//pos��i��������¼λ�õı���
	if(index != left)//������ĵ�һ��Ԫ����mid��left��right���м�ֵ����
		Swap(&ar[index], &ar[left]);
	key = ar[left];
	pos = left;
	for(i = left+1; i <= right; ++i)//ǰ��ָ��汾
	{
		if(ar[i] < key)
		{
			++pos;
			if(pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

void QuickSort(int *ar, int left, int right)
{
	if(left >= right)
		return;
	if(right-left+1 <= M)
	{
		InsertSort_1(ar, left, right);//���������Ƚ�Сʱ���ò�������
	}
	else
	{
		//int pos = _Partition_1(ar, left, right);
		//int pos = _Partition_2(ar, left, right);
		int pos = _Partition_3(ar, left, right);
		QuickSort(ar, left, pos-1);
		QuickSort(ar, pos+1, right);
	}
}

//��������ǵݹ�ʵ��
void QuickSortNonR(int *ar, int left, int right)
{
	ListStack st;//ջ�������ÿ�λ��ֵ��±�
	ListStackInit(&st);

	ListStackPush(&st, left);
	ListStackPush(&st, right);

	while(!ListStackEmpty(&st))
	{
		int begin = 0, end = 0, pos = 0;
		ListStackTop(&st, &end);
		ListStackPop(&st);
		ListStackTop(&st, &begin);
		ListStackPop(&st);
		pos = _Partition_1(ar, begin, end);
		if(begin < pos - 1)
		{
			ListStackPush(&st, begin);
			ListStackPush(&st, pos - 1);
		}

		if(pos + 1 < end)
		{
			ListStackPush(&st, pos + 1);
			ListStackPush(&st, end);
		}
	}
	Destroy(&st);
}

//�鲢����
void _MergeSort(int *ar, int left, int right, int *tmp)
{
	int mid = 0;
	int begin1, end1, begin2, end2, i;
	if(left >= right)
		return;
	mid = (left+right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid+1, right, tmp);
	begin1 = left, end1 = mid;
	begin2 = mid+1, end2 = right;
	i = 0;
	while(begin1<=end1 && begin2<=end2)
	{
		if(ar[begin1] <= ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}
	while(begin1 <= end1)
		tmp[i++] = ar[begin1++];
	while(begin2 <= end2)
		tmp[i++] = ar[begin2++];
	memcpy(ar+left, tmp, sizeof(int)*(right-left+1));
}

void MergeSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(ar, left, right, tmp);
	free(tmp);
	tmp = NULL;
}

//��������
int _GetMaxVal(int *ar, int left, int right)//����������������
{
	int max_val = ar[left];
	while(++left <= right)
	{
		if(ar[left] > max_val)
			max_val = ar[left];
	}
	return max_val;
}

void CountSort(int *ar, int left, int right)
{
	int begin = left;
	int end = right;
	int n = _GetMaxVal(ar, begin, end);
	int *tmp = (int*)calloc(sizeof(int), n+1);
	while(begin <= end)
	{
		++(tmp[ar[begin]]);
		++begin;
	}
	for(begin = 0; begin <= n; ++begin)
	{
		while(tmp[begin] > 0)
		{
			ar[left++] = begin;
			--(tmp[begin]);
		}
	}
	free(tmp);
	tmp = NULL;
}

//��������
void RadixSort(int *ar, int left, int right)
{
	
}



void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);//��������
	//InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	//ShellSort(ar, left, right);
	//TwoWayInsertSort(ar, left, right);
	//SelectSort(ar, left, right);
	//HeapSort(ar, left, right);
	//BubbleSort_1(ar, left, right);
	//BubbleSort_2(ar, left, right);
	//QuickSort(ar, left, right);
	//QuickSortNonR(ar, left, right);
	//MergeSort(ar, left, right);
	CountSort(ar, left, right);
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
	int *a10 = (int*)malloc(sizeof(int) * n);
	int *a11 = (int*)malloc(sizeof(int) * n);
	int *a12 = (int*)malloc(sizeof(int) * n);
	int *a13 = (int*)malloc(sizeof(int) * n);
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
		a10[i] = a1[i];
		a11[i] = a1[i];
		a12[i] = a1[i];
		a13[i] = a1[i];
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

	start = clock();
	QuickSort(a10, 0, n-1);
	end = clock();
	printf("QuickSort: %u\n", end - start);

	start = clock();
	QuickSortNonR(a11, 0, n-1);
	end = clock();
	printf("QuickSortNonR: %u\n", end - start);

	start = clock();
	MergeSort(a12, 0, n-1);
	end = clock();
	printf("MergeSort: %u\n", end - start);

	start = clock();
	CountSort(a13, 0, n-1);
	end = clock();
	printf("CountSort: %u\n", end - start);
}
#endif