#ifndef _SEQCYQUEUE_H_
#define _SEQCYQUEUE_H_
#include "common.h"

#define QUEUE_DEFAULE_SIZE 8
typedef struct SeqCyQueue
{
	DataType *base;
	size_t capacity;
	int front;
	int tail;
}SeqCyQueue;

void SeqCyQueueInit(SeqCyQueue *Q, int sz);
int SeqCyQueueFull(SeqCyQueue *Q);
int SeqCyQueueEmpty(SeqCyQueue *Q);
void SeqCyQueueDe(SeqCyQueue *Q);
void SeqCyQueueShow(SeqCyQueue *Q);
int SeqCyQueueFront(SeqCyQueue *Q, DataType *ret);

int SeqCyQueueFull(SeqCyQueue *Q)//为了区分满和空两种情况，实际的内存大小要比队列的大小多1
{
	return (Q->tail+1)%(Q->capacity) == Q->front;
}

int SeqCyQueueEmpty(SeqCyQueue *Q)
{
	return Q->front == Q->tail;
}

void SeqCyQueueInit(SeqCyQueue *Q, int sz)
{
	Q->capacity = sz > QUEUE_DEFAULE_SIZE ? sz : QUEUE_DEFAULE_SIZE;
	Q->base = (DataType*)malloc(sizeof(DataType) * Q->capacity);
	Q->front = Q->tail = 0;
}

void SeqCyQueueEn(SeqCyQueue *Q, DataType data)
{
	if(SeqCyQueueFull(Q))
	{
		printf("循环队列已满，%d不能入队!\n", data);
		return;
	}
	Q->base[Q->tail] = data;
	Q->tail = (Q->tail+1) % (Q->capacity);
}

void SeqCyQueueDe(SeqCyQueue *Q)
{
	if(SeqCyQueueEmpty(Q))
	{
		printf("队列为空，不能出队!\n");
		return;
	}
	Q->front = (Q->front+1) % (Q->capacity);
}

void SeqCyQueueShow(SeqCyQueue *Q)
{
	int i = 0;
	if(Q->front == Q->tail)
	{
		printf("队列为空!\n");
		return;
	}
	for(i = Q->front; i != Q->tail;)
	{
		printf("%d ", Q->base[i]);
		i = (i+1) % Q->capacity;
	}
	printf("\n");
}

int SeqCyQueueFront(SeqCyQueue *Q, DataType *ret)
{
	if(SeqCyQueueEmpty(Q))
	{
		printf("队列为空，不能取队头元素!\n");
		return 0;
	}
	*ret = (Q->base)[Q->front];
	return 1;
}

void SeqCyQueueDestroy(SeqCyQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}
#endif