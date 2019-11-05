#ifndef _BST_H_
#define _BST_H_
//二叉排序树（binary sort tree）
#include "common.h"

typedef struct BSTNode
{
	DataType data;
	struct BSTNode *leftChild;
	struct BSTNode *rightChild;
}BSTNode;

typedef BSTNode* BSTree;

void BSTreeInit(BSTree *t);
int Insert(BSTree *t, DataType x);
int Insert(BSTree *t, DataType x);
DataType Min(BSTree t);
DataType Max(BSTree t);
void Sort(BSTree t, int *ar, int *i);
int Remove(BSTree *t, DataType key);
void _BSTDestroy(BSTNode *t);
void BSTDestroy(BSTree *t);

void BSTreeInit(BSTree *t)
{
	*t = NULL;
}

int Insert(BSTree *t, DataType x)
{
	if(*t == NULL)
	{
		*t = (BSTNode*)malloc(sizeof(BSTNode));
		(*t)->data = x;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		return 1;
	}
	else if(x < (*t)->data)
		Insert(&((*t)->leftChild), x);
	else if(x > (*t)->data)
		Insert(&((*t)->rightChild), x);
	else
		return 0;
}

DataType Min(BSTree t)//最左边的节点就是最小值
{
	assert(t != NULL);
	while(t->leftChild != NULL)
		t = t->leftChild;
	return t->data;
}

DataType Max(BSTree t)//最右边的节点就是最大值
{
	assert(t != NULL);
	while(t->rightChild != NULL)
		t = t->rightChild;
	return t->data;
}

void Sort(BSTree t, int *ar, int *i)//相当于一个中序遍历
{
	if(t != NULL)
	{
		Sort(t->leftChild, ar, i);
		ar[*i] = t->data;
		++(*i);
		Sort(t->rightChild, ar, i);
	}
}

int Remove(BSTree *t, DataType key)
{
	if(*t == NULL)
		return 0;
	else if(key < (*t)->data)
		Remove(&((*t)->rightChild), key);
	else if(key > (*t)->data)
		Remove(&((*t)->rightChild), key);
	else
	{
		BSTNode *p = *t;
		if(p->leftChild == NULL && p->rightChild == NULL)
		{
			free(p);
			*t = NULL;
		}
		else if(p->leftChild != NULL && p->rightChild == NULL)
		{
			*t = p->leftChild;
			free(p);
		}
		else if(p->leftChild == NULL && p->rightChild != NULL )
		{
			*t = p->rightChild;
			free(p);
		}
		else//删有两个子树的情况转化为删有一个左或者没有子树的情况
		{
			p = (*t)->leftChild;
			while(p->rightChild != NULL)
				p = p->rightChild;
			(*t)->data = p->data;
			Remove(&((*t)->leftChild), p->data);
		}
		p = NULL;
		return 1;
	}
}

void _BSTDestroy(BSTNode *t)
{
	if(t == NULL)
		return;
	_BSTDestroy(t->leftChild);
	_BSTDestroy(t->rightChild);
	free(t);
}

void BSTDestroy(BSTree *t)
{
	_BSTDestroy(*t);
	*t = NULL;
}
#endif