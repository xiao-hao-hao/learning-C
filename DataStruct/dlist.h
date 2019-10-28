#ifndef _DLIST_H_
#define _DLIST_H_

#include "common.h"
typedef struct DListNode
{
	DataType data;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	int size;
}DList;

DListNode* _Buynode(DataType data)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	if(s == NULL)
		return NULL;
	s->data = data;
	s->prev = s->next = NULL;
	return s;
}

void DListInit(DList *plist);
int DListPushBack(DList *plist, DataType data);
int DListPushFront(DList *plist, DataType data);
void DListShow(DList *plist);
DListNode* DListFindByVal(DList *plist, DataType data);
int DListDeleteByVal(DList *plist, DataType data);
int DListPopBack(DList *plist);
int DListPopFront(DList *plist);
int DListInsertByVal(DList *plist, DataType data);
int DListModifyByVal(DList *plist, DataType dest, DataType data);
int DListLength(DList *plist);
void DListClear(DList *plist);
void DListDestroy(DList *plist);
void DListReverse(DList *plist);
void DListSort(DList *plist);

void DListInit(DList *plist)
{
	DListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

int DListPushBack(DList *plist, DataType data)
{
	DListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	++(plist->size);
	return 1;
}

void DListShow(DList *plist)
{
	DListNode *s = plist->first->next;
	if(plist->size == 0)
	{
		printf("双链表为空\n");
		return;
	}
	while(s != NULL)
	{
		printf("%d-->", s->data);
		s = s->next;
	}
	printf("over\n");
}

int DListPushFront(DList *plist, DataType data)
{
	DListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	s->prev = plist->first;
	s->next = s->prev->next;
	s->prev->next = s;
	if(s->next != NULL)
		s->next->prev = s;
	if(plist->size == 0)
		plist->last = s;
	++(plist->size);
	return 1;
}

DListNode* DListFindByVal(DList *plist, DataType data)
{
	DListNode *p = plist->first->next;
	while(p != NULL && p->data != data)
		p = p->next;
	return p;
}

int DListDeleteByVal(DList *plist, DataType data)
{
	DListNode *p = DListFindByVal(plist, data);
	if(p == NULL)
	{
		printf("找不到值%d!\n", data);
		return 0;
	}
	p->prev->next = p->next;
	if(p->next != NULL)
		p->next->prev = p->prev;
	else
		plist->last = plist->first;
	free(p);
	p = NULL;
	--(plist->size);
	return 1;
}

int DListPopBack(DList *plist)
{
	if(plist->size == 0)
		return 0;
	plist->last = plist->last->prev;
	free(plist->last->next);
	plist->last->next = NULL;
	--(plist->size);
	return 1;
}

int DListPopFront(DList *plist)
{
	DListNode *p = NULL;
	if(plist->size == 0)
		return 0;
	p = plist->first->next;
	plist->first->next = p->next;
	if(p->next == NULL)
		plist->last = plist->first;
	else
		p->next->prev = p->prev;
	free(p);
	p = NULL;
	--(plist->size);
	return 1;
}

int DListInsertByVal(DList *plist, DataType data)
{
	DListNode *s = _Buynode(data);
	DListNode *p = plist->first->next;
	if(s == NULL)
		return 0;
	while(p != NULL && p->data < data)
		p = p->next;
	if(p == NULL)
	{
		plist->last->next = s;
		s->prev = plist->last;
		plist->last = s;
	}
	else
	{
		s->next = p;
		s->prev = p->prev;
		s->prev->next = s;
		s->next->prev = s;
	}
	++(plist->size);
	return 1;
}

int DListModifyByVal(DList *plist, DataType dest, DataType data)
{
	DListNode *p = DListFindByVal(plist, dest);
	if(p == NULL)
	{
		printf("找不到值%d\n", dest);
		return 0;
	}
	p->data = data;
	return 1;
}

int DListLength(DList *plist)
{
	return plist->size;
}

void DListClear(DList *plist)
{
	DListNode *p = plist->first->next;
	while(p != NULL)
	{
		p = p->next;
		free(plist->first->next);
		plist->first->next = p;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void DListDestroy(DList *plist)
{
	DListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

void DListReverse(DList *plist)
{
	if(plist->size > 1)
	{
		DListNode *p1 = plist->first->next;
		DListNode *p2 = p1;
		plist->first->next = NULL;
		plist->last = p2;
		while(p1 != NULL)
		{
			p2 = p2->next;
			p1->next = plist->first->next;
			p1->prev = plist->first;
			if(plist->first->next != NULL)
				p1->next->prev = p1;
			plist->first->next = p1;
			p1 = p2;
		}
	}
}

void DListSort(DList *plist)
{
	if(plist->size > 1)
	{
		DListNode *prev = NULL;
		DListNode *p1 = plist->first->next->next;
		DListNode *p2 = p1->next;
		plist->last = plist->first->next;
		plist->last->next = NULL;
		while(p1 != NULL)
		{
			prev = plist->first->next;
			p2 = p2->next;
			while(prev != NULL && p1->data > prev->data)
				prev = prev->next;
			if(prev == NULL)
			{
				plist->last->next = p1;
				p1->prev = plist->last;
				plist->last = p1;
				p1->next = NULL;
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
