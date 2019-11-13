#ifndef _LISTSTACK_H_
#define _LISTSTACL_H_

#include "common.h"

typedef struct ListStackNode
{
	DataType data;
	struct ListStackNode *next;
}ListStackNode;

typedef ListStackNode* ListStack;

int ListStackEmpty(ListStack *pst);
void ListStackInit(ListStack *pst);
void ListStackPush(ListStack *pst, DataType data);
void ListStackShow(ListStack pst);
void ListStackPop(ListStack *pst);
int ListStackTop(ListStack pst, DataType *ret);
void Destroy(ListStack *pst);


int ListStackEmpty(ListStack *pst)
{
	return *pst == NULL;
}

void ListStackInit(ListStack *pst)//二级指针
{
	*pst = NULL;
}

void ListStackPush(ListStack *pst, DataType data)
{
	ListStackNode *node = (ListStackNode*)malloc(sizeof(ListStackNode));
	assert(node != NULL);
	node->data = data;
	node->next = *pst;
	*pst = node;
}

void ListStackShow(ListStack pst)
{
	if(pst == NULL)
	{
		printf("栈为空!\n");
		return;
	}
	while(pst != NULL)
	{
		printf("%d\n", pst->data);
		pst = pst->next;
	}
}

void ListStackPop(ListStack *pst)
{
	ListStackNode *p = *pst;
	if(*pst == NULL)
	{
		printf("栈为空，不能出栈!\n");
		return;
	}
	*pst = p->next;
	free(p);
	p = NULL;
}

int ListStackTop(ListStack *pst, int *ret)
{
	if(pst != NULL)
	{
		*ret = (*pst)->data;
		return 1;
	}
	return 0;
}

void Destroy(ListStack *pst)
{
	ListStackNode *p;
	while((*pst) != NULL)
	{
		p = *pst;
		(*pst) = (*pst)->next;
		free(p);
	}
	p = NULL;
}
#endif