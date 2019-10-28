#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "common.h"

#define QUEUE_DEFAULE_SIZE 8

typedef struct SeqQueue
{
	DataType *base;
	int capacity;
	int front;
	int tail;
}SeqQueue;

int SeqQueueFull(SeqQueue *Q);
int SeqQueueEmpty(SeqQueue *Q);
void SeqQueueInit(SeqQueue *Q, int sz);
void SeqQueueEn(SeqQueue *Q, DataType data);
void SeqQueueDe(SeqQueue *Q);
void SeqQueueShow(SeqQueue *Q);

void SeqQueueInit(SeqQueue *Q, int sz)
{
	Q->capacity = sz>QUEUE_DEFAULE_SIZE ? sz : QUEUE_DEFAULE_SIZE;
	Q->base = (DataType*)malloc(sizeof(DataType) * QUEUE_DEFAULE_SIZE);
	Q->front = Q->tail = 0;
}

int SeqQueueFull(SeqQueue *Q)
{
	return Q->tail >= Q->capacity;
}

int SeqQueueEmpty(SeqQueue *Q)
{
	return Q->front == Q->tail;
}

int SeqQueueFront(SeqQueue *Q)
{
	if(SeqQueueEmpty(Q))
	{
		printf("队列已空，不能取队头元素!\n");
		return 0;
	}
	return 1;
}

void SeqQueueEn(SeqQueue *Q, DataType data)
{
	if(SeqQueueFull(Q))
	{
		printf("队列已满，%d不能入队!\n", data);
		return;
	}
	Q->base[Q->tail++] = data;
}

void SeqQueueDe(SeqQueue *Q)
{
	if(SeqQueueEmpty(Q))
	{
		printf("队列已空，不能出队!\n");
		return;
	}
	++(Q->front);
}

void SeqQueueShow(SeqQueue *Q)
{
	int i = 0;
	if(Q->front == Q->tail)
	{
		printf("队列为空!\n");
		return;
	}
	for(i = Q->front; i < Q->tail;++i)
	{
		printf("%d ", Q->base[i]);
	}
	printf("\n");
}

void Destroy(SeqQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}
#endif