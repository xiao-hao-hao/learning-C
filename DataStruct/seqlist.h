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
void SeqListShow(SeqList *psl);
int SeqListPushBack(SeqList *psl, DataType data);
int SeqListIsFull(SeqList *psl);
int SeqListPushFront(SeqList *psl, DataType data);
int SeqListPopBack(SeqList *psl);
int SeqListPopBack(SeqList *psl);
int SeqListInsertPos(SeqList *psl, int pos, DataType data);

void SeqListInit(SeqList *psl, int sz)
{
    assert(psl);
    psl->capacity = sz >SEQLIST_DEFAULT_SIZE ? sz :SEQLIST_DEFAULT_SIZE;
    psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
    psl->size = 0;
}

void SeqListShow(SeqList *psl)
{
	int i = 0;
    assert(psl);
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
    return (psl->capacity) <= (psl->size);
}

int SeqListPushFront(SeqList *psl, DataType data)
{
	int i = 0;
    assert(psl);
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
    assert(psl);
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
    assert(psl);
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

int SeqListInsertPos(SeqList *psl, int pos, DataType data)
{
	int i = 0;
    assert(psl);
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
    if(pos == psl->size)
    {
        (psl->base)[pos] = data;
        ++(psl->size);
    }
    else
    {
        for(i = psl->size; i > pos; --i)
        {
            (psl->base)[i] = (psl->base)[i-1];
        }
        (psl->base)[pos] = data;
        ++(psl->size);
    }
    return 1;
}
#endif