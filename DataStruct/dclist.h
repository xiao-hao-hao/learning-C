#ifndef _DCLIST_H_
#define _DCLIST_H_

#include "common.h"

typedef struct DCListNode
{
	DataType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef struct DCList
{
	DCListNode *first;
	DCListNode *last;
	int size;
}DCList;

DCListNode* _Buynode(DataType data)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	if(s == NULL)
		return NULL;
	s->data = data;
	s->prev = s->next = NULL;
	return s;
}

int DCListInit(DCList *plist);
void DCListDestroy(DCList *plist);

int DCListPushBack(DCList *plist, DataType data);
void DCListShow(DCList *plist);
int DCListPushFront(DCList *plist, DataType data);
int DCListPopBack(DCList *plist);
int DCListPopFront(DCList *plist);
DCListNode* DCListFindByVal(DCList *plist, DataType data);
int DCListDeleteByVal(DCList *plist, DataType data);
int DCListModifyByVal(DCList *plist, DataType dest, DataType data);
int DCListLength(DCList *plist);
void DCListClear(DCList *plist);
void DCListReverse(DCList *plist);
//void DCListSort(DCList *plist);

int DCListInit(DCList *plist)
{
	DCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	s->prev = plist->last;
	s->next = plist->first;
	plist->size = 0;
}

int DCListPushBack(DCList *plist, DataType data)
{
	DCListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	++(plist->size);
	return 1;
}

void DCListShow(DCList *plist)
{
	DCListNode *p = plist->first->next;
	if(plist->size == 0)
	{
		printf("双循环链表为空!\n");
		return;
	}
	while(p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over\n");
}

int DCListPushFront(DCList *plist, DataType data)
{
	DCListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	s->next = plist->first->next;
	s->prev = plist->first;
	s->prev->next = s;
	s->next->prev = s;
	if(plist->size == 0)
		plist->last = s;
	++(plist->size);
	return 1;
}

//int DCListPopBack(DCList *plist)
//{
//	if(plist->size == 0)
//		return 0;
//	plist->last->prev->next = plist->last->next;
//	plist->first->prev = plist->last->prev;
//	free(plist->last);
//	plist->last = plist->first->prev;
//	--(plist->size);
//}

int DCListPopBack(DCList *plist)
{
	DCListNode *p = NULL;
	if(plist->size == 0)
		return 0;
	p = plist->last;
	plist->last = p->prev;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	free(p);
	p = NULL;
	--(plist->size);
}

int DCListPopFront(DCList *plist)
{
	DCListNode *p = NULL;
	if(plist->size == 0)
		return 0;
	p = plist->first->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if(p == plist->last)
		plist->last = plist->first;
	free(p);
	p = NULL;
	--(plist->size);
	return 1;
}

int DCListInsertByVal(DCList *plist, DataType data)
{
	DCListNode *s = _Buynode(data);
	DCListNode *p = plist->first->next;
	if(s == NULL)
		return 0;
	while(p != plist->first && p->data < data)//值相等则不插入
		p = p->next;
	if(p != plist->first && p->data == data)
	{
		free(s);
		return 0;
	}
	s->prev = p->prev;
	s->next = p;
	s->prev->next = s;
	s->next->prev = s;
	if(p == plist->first)
		plist->last = s;
	++(plist->size);
	return 1;
}

int DCListDeleteByVal(DCList *plist, DataType data)
{
	DCListNode *p = DCListFindByVal(plist, data);
	if(p == NULL)
	{
		printf("找不到值%d!\n", data);
		return 0;
	}
	p->next->prev = p->prev;
	p->prev->next = p->next;
	if(p == plist->last)
		plist->last = p->prev;
	free(p);
	p = NULL;
	--(plist->size);
	return 1;
}

DCListNode* DCListFindByVal(DCList *plist, DataType data)
{
	DCListNode *p = plist->first->next;
	while(p != plist->first && p->data != data)
		p = p->next;
	if(p == plist->first)
		return NULL;
	return p;
}

int DCListModifyByVal(DCList *plist, DataType dest, DataType data)
{
	DCListNode *p = DCListFindByVal(plist, dest);
	if(p == NULL)
	{
		printf("找不到值%d!\n", dest);
		return 0;
	}
	p->data = data;
	return 1;
}

int DCListLength(DCList *plist)
{
	return plist->size;
}

void DCListClear(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while(p != plist->first)
	{
		p = p->next;
		free(plist->first->next);
		plist->first->next = p;
		p->prev = plist->first;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = 0;
}

void DCListReverse(DCList *plist)
{
	if(plist->size > 1)
	{
		DCListNode *p1 = plist->first->next;
		DCListNode *p2 = p1;
		plist->first->next = plist->first;
		plist->last = p2;
		while(p1 != plist->first)
		{
			p2 = p2->next;
			p1->next = plist->first->next;
			p1->prev = plist->first;
			p1->prev->next = p1;
			p1->next->prev = p1;
			p1 = p2;
		}
	}
}

void DCListSort(DCList *plist)
{
	if(plist->size > 1)
	{
		DCListNode *prev = NULL;
		DCListNode *p1 = plist->first->next->next;
		DCListNode *p2 = p1->next;
		plist->last = plist->first->next;
		plist->last->next = plist->first;
		while(p1 != plist->first)
		{
			prev = plist->first->next;
			p2 = p2->next;
			while(prev != plist->first && p1->data > prev->data)
				prev = prev->next;
			if(prev == plist->first)
			{
				p1->prev = plist->last;
				p1->next = plist->last->next;
				p1->prev->next = p1;
				p1->next->prev = p1;
				plist->last = p1;
			}
			else
			{
				p1->next = prev;
				p1->prev = prev->prev;
				p1->next->prev = p1;
				p1->prev->next = p1;
			}
			p1 = p2;	
		}
	}
}
#endif