#ifndef _SCLIST_H_
#define _SCLIST_H_

#include "common.h"
typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	int size;
}SCList;

void SCListInit(SCList *plist);
SCListNode* _BuyNode(DataType data);
void SCListShow(SCList *plist);
void SCListDestroy(SCList *plist);

int SCListPushBack(SCList *plist, DataType data);
int SCListPushFront(SCList *plist, DataType data);
int SCListPopBack(SCList *plist);
int SCListPopFront(SCList *plist);
SCListNode* SCListFindByVal(SCList *plist, DataType data);
int SCListModifyByVal(SCList *plist, DataType dest, DataType data);//调用found函数
int SCListLength(SCList *plist);
void SCListClear(SCList *plist);
void SCListSort(SCList *plist);

SCListNode* _BuyNode(DataType data)
{
	SCListNode *s = (SCListNode*)malloc(sizeof(SCListNode));
	if(s == NULL)
		return NULL;
	s->next = NULL;
	s->data = data;
	return s;
}

void SCListInit(SCList *plist)
{
	SCListNode *s = _BuyNode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->size = 0;
}

int SCListPushBack(SCList *plist, DataType data)
{
	SCListNode *s = _BuyNode(data);
	if(s == NULL)
		return 0;
	plist->last->next = s;
	plist->last = s;
	s->next = plist->first;
	++(plist->size);
	return 1;
}

void SCListShow(SCList *plist)
{
	SCListNode *p = plist->first->next;
	if(plist->size == 0)
	{
		printf("单循环链表为空!\n");
		return;
	}
	while(p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

int SCListPushFront(SCList *plist, DataType data)
{
	
	SCListNode *s = _BuyNode(data);
	if(s == NULL)
		return 0;
	if(plist->first == plist->last)
	{
		plist->first->next = plist->last = s;
		s->next = plist->first;
	}
	else
	{
		s->next = plist->first->next;
		plist->first->next = s;
	}
	++(plist->size);
	return 1;
}

int SCListPopBack(SCList *plist)
{
	SCListNode *prev = plist->first;
	if(plist->size == 0)
		return 0;
	while(prev->next->next != plist->first)
		prev = prev->next;
	free(plist->last);
	plist->last = prev;
	prev->next = plist->first;
	--(plist->size);
	return 1;
}

int SCListPopFront(SCList *plist)
{
	SCListNode *p = plist->first->next;
	if(plist->size == 0)
		return 0;
	plist->first->next = p->next;
	free(p);
	p = NULL;
	if(plist->first->next == plist->first)
		plist->last = plist->first;
	--(plist->size);
	return 1;
}

int SCListInsertByVal(SCList *plist, DataType data)//要求链表有序
{
	SCListNode *prev = plist->first;
	SCListNode *s = _BuyNode(data);
	while(prev->next != plist->first && prev->next->data < data)
		prev = prev->next;
	if(prev->next == plist->first)
	{
		prev->next = s;
		plist->last = s;
		s->next = plist->first;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
	++(plist->size);
}

int SCListDeleteByVal(SCList *plist, DataType data)
{
	SCListNode *p = plist->first;
	SCListNode *q = NULL;
	while(p->next != plist->first && p->next->data != data)
		p = p->next;
	if(p->next == plist->first)
	{
		printf("值%d不在单顺序链表中!\n", data);
		return 0;
	}
	q = p->next;
	if(p->next->next == plist->first)
		plist->last = plist->first;
	p->next = p->next->next;
	free(q);
	q = NULL;
	--(plist->size);
	return 1;
}

SCListNode* SCListFindByVal(SCList *plist, DataType data)
{
	SCListNode *p = plist->first->next;
	while(p != plist->first && p->data != data)
		p = p->next;
	if(p == plist->first)
	{
		printf("找不到值%d\n", data);
		return NULL;
	}
	return p;
}

int SCListModifyByVal(SCList *plist, DataType dest, DataType data)
{
	SCListNode *p = SCListFindByVal(plist, dest);//调用SCListFindByVal()函数
	if(p == NULL)
		return 0;
	p->data = data;
	return 0;
}

int SCListLength(SCList *plist)
{
	return plist->size;
}

void SCListClear(SCList *plist)
{
	SCListNode *p = plist->first->next;
	while(p != plist->first)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	p = NULL;
	plist->last = plist->first;
	plist->size = 0;
}

void SCListReverse(SCList *plist)
{
	if(plist->size > 1)
	{
		SCListNode *p1 = plist->first;
		SCListNode *p2 = p1->next;
		SCListNode *p3 = p2->next;
		plist->last = p2;
		while(p2 != plist->first)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			if(p3 != plist->first)
				p3 = p3->next;
		}
		plist->first->next = p1;
	}
}

void SCListSort(SCList *plist)
{
	if(plist->size > 1)
	{
		SCListNode *prev = NULL;
		SCListNode *p1 = plist->first->next->next;
		SCListNode *p2 = p1;
		plist->last = plist->first->next;
		plist->last->next = plist->first;  //必须有这句
		while(p1 != plist->first)
		{
			prev = plist->first;
			p2 = p2->next;
			while(prev->next != plist->first && p1->data > prev->next->data)
				prev = prev->next;
			if(prev->next == plist->first)
			{
				prev->next = p1;
				plist->last = p1;
				p1->next = plist->first;
			}
			else
			{
				p1->next = prev->next;
				prev->next = p1;
			}
			p1 = p2;
		}
	}
}

void SCListDestroy(SCList *plist)
{
	SCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}
#endif