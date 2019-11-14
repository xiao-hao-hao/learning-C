#ifndef _SLIST_H_
#define _SLIST_H_

#include "common.h"
typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	int size;
}SList;

int SListEmpty(SList *plist)
{
	return plist->size == 0;
}

void SListInit(SList *plist);
SListNode* _Buynode(DataType data);
void SListDestroy(SList *plist);

int SListPushBack(SList *plist, DataType data);
int SListPushFront(SList *plist, DataType data);
void SListShow(SList *plist);
void SListInsertByVal(SList *plist, DataType data);
SListNode* SListFindByVal(SList *plist, DataType data); 
int SListModifyByVal(SList *plist, DataType dest, DataType data);//调用found函数
int SListLength(SList *plist);
void SListClear(SList *plist);
void SListReverse(SList *plist);
void SListSort(SList *plist);//排序 （断开 插入） 冒泡
void Swap(DataType *p1, DataType *p2);

SListNode* _Buynode(DataType data)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->next = NULL;
	s->data = data;
	return s;
}

void SListInit(SList *plist)
{
	SListNode *s = _Buynode(0);//定义头结点，头结点的数据域内容可以为随机值
	plist->first = plist->last = s;
	plist->size = 0;
}

int SListPushBack(SList *plist, DataType data)
{
	SListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	plist->last->next = s;
	plist->last = s;
	++(plist->size);
	return 1;
}

int SListPushFront(SList *plist, DataType data)
{
	SListNode *s = _Buynode(data);
	if(s == NULL)
		return 0;
	s->next = plist->first->next;
	plist->first->next = s;
	if(plist->size == 0)
		plist->last = s;
	++(plist->size);
	return 1;
}

void SListShow(SList *plist)
{
	SListNode *p = plist->first->next;
	if(plist->size == 0)
	{
		printf("单链表为空!\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

int SListPopBack(SList *plist)
{
	SListNode *p = NULL;
	if(plist->size == 0)
	{
		printf("单链表为空!\n");
		return 0;
	}
	p = plist->first;
	while(p->next != plist->last)
		p = p->next;
	p->next = NULL;
	free(plist->last);
	plist->last = p;
	p = NULL;
	--(plist->size);
	return 1;
}

int SListPopFront(SList *plist)
{
	SListNode *p = NULL;
	if(plist->size == 0)
	{
		printf("单链表为空!\n");
		return 0;
	}
	p = plist->first->next;
	plist->first->next = p->next;
	--(plist->size);
	if(plist->size == 0)
		plist->last = plist->first;
	return 1;
}

void SListInsertByVal(SList *plist, DataType data)
{
	SListNode *s = _Buynode(data);
	SListNode *p = plist->first;
	while(p->next != NULL && p->next->data < data)
		p = p->next;
	if(p->next == NULL)
	{
		p->next = s;
		plist->last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	++(plist->size);
}

int SListDeleteByVal(SList *plist, DataType data)
{
	SListNode *q = NULL;
	SListNode *p = plist->first;
	while(p->next != NULL && p->next->data != data)
		p = p->next;
	if(p->next == NULL)
	{
		printf("找不到数据%d\n", data);
		return 0;
	}
	q = p->next;
	if(p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	q = NULL;
	--(plist->size);
	return 1;
}

SListNode* SListFindByVal(SList *plist, DataType data)
{
	SListNode *p = plist->first->next;
	while(p != NULL && p->data != data)
		p = p->next;
	return p;
}

int SListLength(SList *plist)
{
	assert(plist != NULL);
	return plist->size;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	while(p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	p = NULL;
	plist->last = plist->first;
	plist->size = 0;
}

//方法1
//int SListModifyByVal(SList *plist, DataType dest, DataType data)
//{
//	SListNode *p = plist->first->next;
//	while(p != NULL && p->data != dest)
//		p = p->next;
//	if(p == NULL)
//	{
//		printf("找不到数据%d\n", dest);
//		return 0;
//	}
//	p->data = data;
//	return 0;
//}

//方法2
int SListModifyByVal(SList *plist, DataType dest, DataType data)
{
	SListNode *p = SListFindByVal(plist, dest);//调用SListFindByVal()函数
	if(p == NULL)
		return 0;
	p->data = data;
	return 1;
}

//方法1
//void SListDestroy(SList *plist)
//{
//	SListNode *p = plist->first;
//	SListNode *q = NULL;
//	while(p != NULL)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	plist->first = plist->last = NULL;
//	plist->size = 0;
//}

#endif

//方法2
void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

//方法1
//单链表的转置：将链表分成两部分，第一个结点和其他节点，然后头插
//void SListReverse(SList *plist)
//{
//	if(plist->size > 1)
//	{
//		SListNode *p1 = NULL;
//		SListNode *p2 = plist->first->next;
//		SListNode *p3 = p2->next;
//		plist->last = p2;
//		while(p2 != NULL)
//		{
//			p2->next = p1;
//			p1 = p2;
//			p2 = p3;
//			if(p3 != NULL)
//				p3 = p3->next;
//		}
//		plist->first->next = p1;
//	}
//}

//方法2
//直接改变指向，不插入
void SListReverse(SList *plist)
{
	if(plist->size > 1)
	{
		SListNode *p1 = NULL;
		SListNode *p2 = plist->first->next;
		SListNode *p3 = p2->next;
		plist->last = plist->first->next;
		while(p2 != NULL)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			if(p3 != NULL)
				p3 = p3->next;
		}
		plist->first->next = p1;
	}
}

//单链表排序：将列表分成两部分，进行有序插入
//void SListSort(SList *plist)
//{
//	if(plist->size > 1)
//	{
//		SListNode *prev = NULL;
//		SListNode *p1 = plist->first->next->next;
//		SListNode *p2 = p1;
//		plist->last = plist->first->next;
//		plist->last->next = NULL;  //必须有这句
//		while(p1 != NULL)
//		{
//			prev = plist->first;
//			p2 = p2->next;
//			while(prev->next != NULL && p1->data > prev->next->data)
//				prev = prev->next;
//			if(prev->next == NULL)
//			{
//				prev->next = p1;
//				plist->last = p1;
//				p1->next = NULL;
//			}
//			else
//			{
//				p1->next = prev->next;
//				prev->next = p1;
//			}
//			p1 = p2;
//		}
//	}
//}

//方法2
//冒泡排序（单链表很少采用冒泡排序，因为这样只交换值，没有改变节点之间的指向）
void SListSort(SList *plist)
{
	if(plist->size > 1)
	{
		int i = 0;
		int j = 0;
		int size = plist->size;
		SListNode *p = NULL;
		for(i = 0; i < size-1; ++i)
		{
			p = plist->first->next;
			for(j = 0; j < size-i-1; ++j)
			{
				if(p->data > p->next->data)
					Swap(&(p->data), &(p->next->data));
				p = p->next;
			}
		}
	}
}
