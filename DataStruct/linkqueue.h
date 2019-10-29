#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "common.h"

typedef struct LinkQueueNode
{
	DataType data;
	struct LinkQueueNode *next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *tail;
}LinkQueue;

int LinkQueueEmpty(LinkQueue *Q);
void LinkQueueInit(LinkQueue *Q);
void LinkQueueEn(LinkQueue *Q, char data);
void LinkQueueDe(LinkQueue *Q);
void LinkQueueShow(LinkQueue *Q);
DataType LinkQueueFront(LinkQueue *q);
void LinkQueueDestroy(LinkQueue *Q);

int LinkQueueEmpty(LinkQueue *Q)
{
	return Q->front == NULL;
}

void LinkQueueInit(LinkQueue *Q)
{
	Q->front = Q->tail = NULL;
}

void LinkQueueEn(LinkQueue *Q, DataType data)
{
	LinkQueueNode *s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s);
	s->data = data;
	s->next = NULL;
	if(LinkQueueEmpty(Q))
		Q->front = Q->tail = s;
	else
	{
		Q->tail->next = s;
		Q->tail = s;
	}
}

void LinkQueueDe(LinkQueue *Q)
{
	LinkQueueNode *p = NULL;
	if(LinkQueueEmpty(Q))
	{
		printf("队列已空，不能出队!\n");
		return;
	}
	p = Q->front->next;
	free(Q->front);
	Q->front = p;
}

void LinkQueueShow(LinkQueue *Q)
{
	LinkQueueNode *p = Q->front;
	if(p == NULL)
	{
		printf("队列为空!\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

DataType LinkQueueFront(LinkQueue *q)
{
	if(LinkQueueEmpty(q))
	{
		printf("队列已空，不能取队头元素!\n");
		return NULL;
	}
	return q->front->data;
}


void LinkQueueDestroy(LinkQueue *Q)
{
	LinkQueueNode *p = Q->front;
	while(p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->front = Q->tail = NULL;
}
#endif