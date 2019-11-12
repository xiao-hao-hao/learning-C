#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include "common.h"
#define STACK_DEFAULT_SIZE 8
#define STACK_INC_SIZE 5
typedef struct SeqStack
{
	DataType *base;
	size_t capacity;
	int top;
}SeqStack;

int SeqStackFull(SeqStack *pst)
{
	if(pst->top >= pst->capacity)
		return 1;
	return 0;
}

int SeqStackEmpty(SeqStack *pst)
{
	if(pst->top == 0)
		return 1;
	return 0;
}

int SeqStackIncCapacity(SeqStack *pst)
{
	if(SeqStackFull(pst))
	{
		DataType *p = (DataType*)realloc(pst->base, sizeof(DataType) 
			* (pst->capacity + STACK_INC_SIZE));
		if(p == NULL)
			return 0;
		pst->base = p;
		pst->capacity += STACK_INC_SIZE;
		return 1;
	}
	return 0;
}

void SeqStackInit(SeqStack *pst, int sz);
void SeqStackPush(SeqStack *pst, DataType data);
void SeqStackShow(SeqStack *pst);
SeqStack* SeqStackCreate(SeqStack *pst);
void SeqStackPop(SeqStack *pst);
DataType SeqStackTop(SeqStack *pst);
void Destroy(SeqStack *pst);

void SeqStackInit(SeqStack *pst, int sz)
{
	pst->capacity = sz>STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType) * pst->capacity);
	pst->top = 0;
}

void SeqStackPush(SeqStack *pst, DataType data)
{
	SeqStackIncCapacity(pst);
	if(SeqStackFull(pst))
	{
		printf("栈已满，%d不能入栈!\n", data);
		return;
	}
	pst->base[pst->top++] = data;
}

void SeqStackShow(SeqStack *pst)
{
	int i = pst->top - 1;
	if(i < 0)
	{
		printf("栈为空!\n");
		return;
	}
	while(i >=0)
	{
		printf("%d\n", pst->base[i]);
		--i;
	}
}

SeqStack* SeqStackCreate(int sz)
{
	SeqStack *pst = (SeqStack*)malloc(sizeof(SeqStack));
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType) * pst->capacity);
	pst->top = 0;
	return pst;
}

void SeqStackPop(SeqStack *pst)
{
	if(SeqStackEmpty(pst))
	{
		printf("栈已空，不能出栈!\n");
		return;
	}
	--(pst->top);
}

DataType SeqStackTop(SeqStack *pst)
{
	if(pst->top == 0)
	{
		printf("栈为空，不能取栈顶元素!\n");
		return -1;
	}
	return pst->base[pst->top-1];
}

void Destroy(SeqStack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->top = 0;
}
#endif