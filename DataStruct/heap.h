#ifndef _HEAP_H_
#define _HEAP_H_
#include "common.h"

typedef struct Heap
{
	DataType *heap;
	size_t capacity;
	size_t size;
}Heap;

int HeapFull(Heap *php)
{
	return php->size == php->capacity;
}

int HeapEmpty(Heap *php)
{
	return php->size == 0;
}

void HeapInit(Heap *php, int sz);
int HeapInsert(Heap *php, DataType x);
void _AdjustUp(Heap *php, int start);
void HeapShow(Heap *php);
DataType HeapTop(Heap *php);
int HeapRemove(Heap *php);
void _AdjustDown(Heap *php, int start);
void Swap(DataType *p1, DataType *p2)；

void HeapInit(Heap *php, int sz)
{
	php->capacity = sz;
	php->size = 0;
	php->heap = (DataType*)malloc(sizeof(DataType) * sz);
}

void Swap(DataType *p1, DataType *p2)
{
	DataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int HeapInsert(Heap *php, DataType x)
{
	if(HeapFull(php))
		return 0;
	php->heap[php->size] = x;
	_AdjustUp(php, php->size);
	++(php->size);
	return 1;
}

void _AdjustUp(Heap *php, int start)//向上调整算法 小堆
{
	int j = start;//最后一个叶子节点
	int i = (j-1) / 2;
	while(j > 0)
	{
		if(php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			j = i;
			i = (j-1) / 2;
		}
		else
			break;
	}
}

void HeapShow(Heap *php)
{
	int i;
	for(i = 0; i < php->size; ++i)
	{
		printf("%d ", php->heap[i]);
	}
	printf("\n");
}

DataType HeapTop(Heap *php)
{
	if(!HeapEmpty(php))
		return php->heap[0];
}

int HeapRemove(Heap *php)
{
	if(HeapEmpty(php))
		return 0;
	php->heap[0] = php->heap[php->size-1];
	--(php->size);
	_AdjustDown(php, 0);
	return 1;
}

void _AdjustDown(Heap *php, int start)
{
	int i = start;
	int j = 2 * i + 1;
	while(j < php->size)
	{
		if(j+1<php->size && php->heap[j]>php->heap[j+1])
			++j;
		if(php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

void HeapDestroy(Heap *php)
{
	php->capacity = php->size = 0;
	free(php->heap);
	php->heap = NULL;
}
#endif