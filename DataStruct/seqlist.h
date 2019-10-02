#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
    DataType *base;
    int capacity;
    int size;
}SeqList;

void SeqListInit(SeqList *psl, int sz);
int SeqListIsFull(SeqList *psl);
void Swap(DataType *pa, DataType *pb);

void SeqListShow(SeqList *psl);
int SeqListPushFront(SeqList *psl, DataType data);
int SeqListPushBack(SeqList *psl, DataType data);
int SeqListPopFront(SeqList *psl);
int SeqListPopBack(SeqList *psl);
int SeqListInsertByPos(SeqList *psl, int pos, DataType data);
int SeqListInsertByVal(SeqList *psl, DataType data);//要求顺序表有序
int SeqListDeleteByPos(SeqList *psl, int pos);
int SeqListDeleteByVal(SeqList *psl, DataType data);
int SeqListFindByPos(SeqList *psl, int pos, DataType *ret);
int SeqListFindByVal(SeqList *psl, DataType data);
void SeqListSort(SeqList *psl);
void SeqListReverse(SeqList *psl);
int SeqListLength(SeqList *psl);
int SeqListModifyByPos(SeqList *psl, int pos, DataType data);
int SeqListModifyByVal(SeqList *psl, DataType dest, DataType data);

void SeqListInit(SeqList *psl, int sz)
{
    assert(psl != NULL);
    psl->capacity = sz >SEQLIST_DEFAULT_SIZE ? sz :SEQLIST_DEFAULT_SIZE;
    psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
    psl->size = 0;
}

void SeqListShow(SeqList *psl)
{
	int i = 0;
    assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return;
    }
    for(i = 0; i < (psl->size); ++i)
    {
        printf("%d ", (psl->base)[i]);
    }
    printf("\n");
}

int SeqListPushBack(SeqList *psl, DataType data)
{
    assert(psl);
    if(SeqListIsFull(psl))
    {
        printf("顺序表已满,%d不能插入!\n", data);
        return 0;
    }
    (psl->base)[psl->size++] = data;
    return 1;
}

int SeqListIsFull(SeqList *psl)
{
    assert(psl != NULL);
    return (psl->capacity) <= (psl->size);
}

int SeqListPushFront(SeqList *psl, DataType data)
{
	int i = 0;
    assert(psl != NULL);
    if(SeqListIsFull(psl))
    {
        printf("顺序表已满,%d不能插入!\n", data);
        return 0;
    }
    for(i = (psl->size); i > 0; --i)
    {
        (psl->base)[i] = (psl->base)[i-1];
    }
    (psl->base)[0] = data;
    ++(psl->size);
    return 1;
}

int SeqListPopBack(SeqList *psl)
{
    assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return 0;
    }
    --(psl->size);
    return 1;
}

int SeqListPopFront(SeqList *psl)
{
	int i = 0;
    assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return 0;
    }
    for(i = 0; i <= (psl->size-2); ++i)
    {
        (psl->base)[i] = (psl->base)[i+1];
    }
    --(psl->size);
    return 1;
}

int SeqListInsertByPos(SeqList *psl, int pos, DataType data)
{
	int i = 0;
    assert(psl != NULL);
    if(SeqListIsFull(psl))
    {
        printf("顺序表已满,%d不能插入!\n", data);
        return 0;
    }
    if(pos < 0 || pos > psl->size)
    {
        printf("输入的位置非法!\n");
        return 0;
    }
    for(i = psl->size; i > pos; --i)
    {
        (psl->base)[i] = (psl->base)[i-1];
    }
    (psl->base)[pos] = data;
    ++(psl->size);
    return 1;
}

int SeqListInsertByVal(SeqList *psl, DataType data)
{
	int i = 0;
    assert(psl != NULL);
    if(SeqListIsFull(psl))
    {
        printf("顺序表已满,%d不能插入!\n", data);
        return 0;
    }
	for(i = psl->size - 1; i >= 0; --i)
	{
		if(psl->base[i] > data)
			psl->base[i+1] = psl->base[i];
		else
			break;
	}
	psl->base[i+1] = data;
	++(psl->size);
	return 1;
}

int SeqListDeleteByPos(SeqList *psl, int pos)
{
	int i = 0;
    assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return 0;
    }
    if(pos < 0 || pos > psl->size-1)
    {
        printf("输入的位置非法!\n");
        return 0;
    }
	for(i = pos; i < psl->size-1; ++i)
		psl->base[i] = psl->base[i+1];
	--(psl->size);
	return 1;
}

int SeqListDeleteByVal(SeqList *psl, DataType data)
{
	int ret = SeqListFindByVal(psl, data);//返回要删除数据的位置
    assert(psl != NULL);
    if(0 == psl->size)
        return 0;
	if(-1 == ret)
	{
		printf("要删除的数据不存在!\n");
		return 0;
	}
	return SeqListDeleteByPos(psl, ret);
}

int SeqListFindByPos(SeqList *psl, int pos, DataType *ret)
{
	assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return 0;
    }
    if(pos < 0 || pos > psl->size-1)
    {
        printf("输入的位置非法!\n");
        return 0;
    }
	*ret = psl->base[pos];
	return 1;
}

int SeqListFindByVal(SeqList *psl, DataType data)
{
	int i = 0;
	assert(psl != NULL);
    if(0 == psl->size)
    {
        printf("顺序表为空!\n");
        return -1;
    }
	for(i = 0; i < psl->size; ++i)
	{
		if(psl->base[i] == data)
			return i;
	}
	return -1;
}

void Swap(DataType *pa, DataType *pb)
{
	DataType swap;
	swap = *pa;
	*pa = *pb;
	*pb = swap;
}

void SeqListSort(SeqList *psl)
{
	int i = 0, j = 0;
    assert(psl != NULL);
	for(i = 0; i < psl->size-1; ++i)
	{
		for(j = 0; j < psl->size-i-1; ++j)
		{
			if(psl->base[j] > psl->base[j+1])
			{
				Swap(&(psl->base[j]), &(psl->base[j+1]));
			}
		}
	}
}

void SeqListReverse(SeqList *psl)
{
	int left = 0;
	int right = psl->size - 1;
	assert(psl != NULL);
	while(left < right)
	{
		Swap(&(psl->base[left]), &(psl->base[right]));
		++left;
		--right;
	}
}

int SeqListLength(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size;
}

void SeqListClear(SeqList *psl)
{
	assert(psl != NULL);
	psl->size = 0;
}

int SeqListModifyByPos(SeqList *psl, int pos, DataType data)
{
	assert(psl != NULL);
    if(pos < 0 || pos > psl->size-1)
    {
        printf("输入的位置非法!\n");
        return 0;
    }
	psl->base[pos] = data;
	return 1;
}

int SeqListModifyByVal(SeqList *psl, DataType dest, DataType data)
{
	int ret = SeqListFindByVal(psl, dest);
	assert(psl != NULL);
	if(-1 == ret)
	{
		printf("数据%d不存在!\n", dest);
		return 0;
	}
	psl->base[ret] = data;
	return 1;
}
#endif