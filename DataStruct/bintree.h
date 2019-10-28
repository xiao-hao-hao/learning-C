#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "common.h"
#include "linkqueue.h"
//ABC##DE##F##G#H##

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

//typedef struct BinTree
//{
//	BinTreeNode *root;
//}BinTree;

#define DataType BinTreeNode*
typedef BinTreeNode* BinTree;
void BinTreeInit(BinTree *t);
BinTreeNode* BinTreeCreate_1();
void BinTreeCreate_2(BinTree *t);
size_t Height(BinTree *t);
size_t Size(BinTree *t);
BinTreeNode* Find(BinTreeNode *t, DataType key);
BinTreeNode* Find(BinTree *t, DataType key);
BinTreeNode* Parent(BinTree *t, DataType key); 
void BinTreeCreateByStr(BinTree *t, char *str, int *i);
void LevelOrder(BinTree *t);
BinTreeNode* Clone(BinTree *t);
int Equal(BinTree *t1, BinTree *t2);

void BinTreeInit(BinTree *t)
{
	*t = NULL;
}

BinTreeNode* BinTreeCreate_1()//前序法创建（根左右）
{
	char input;
	scanf("%c", &input);
	if(input == '#')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = input;
		t->leftChild = BinTreeCreate_1();
		t->rightChild = BinTreeCreate_1();
		return t;
	}
}

void BinTreeCreate_2(BinTree *t)
{
	char input;
	scanf("%c", &input);
	if(input == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = input;
		BinTreeCreate_2(&((*t)->leftChild));
		BinTreeCreate_2(&((*t)->rightChild));
	}
}

void PreOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		printf("%c ", t->data);
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}

void InOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		InOrder(t->leftChild);
		printf("%c ", t->data);
		InOrder(t->rightChild);
	}
}

void PostOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		PostOrder(t->leftChild);
		PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

void LevelOrder(BinTree *t)
{
	if(t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEn(&Q, *t);
		while(!LinkQueueEmpty(&Q))
		{
			BinTreeNode *p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%d ", queue.front);	
			LinkQueueDe(&queue);
		}
	}
}

size_t Height(BinTree *t)
{
	if(*t == NULL)
		return 0;
	else
		return Height(&((*t)->leftChild))>Height(&((*t)->rightChild))
		?Height(&((*t)->leftChild))+1:Height(&((*t)->rightChild))+1;
}

size_t Size(BinTree *t)
{
	if(*t == NULL)
		return 0;
	else
		return Size(&((*t)->leftChild)) + Size(&((*t)->rightChild)) + 1;
}

void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	if(str[*i] == '#' || str[*i] == '\0')
	{
		*t = NULL;
		++(*i);
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = str[(*i)++];
		BinTreeCreateByStr(&((*t)->leftChild), str, i);
		BinTreeCreateByStr(&((*t)->rightChild), str, i);
	}
}

BinTreeNode* Find(BinTree *t, DataType key)
{
	BinTreeNode *p = NULL;
	if(*t == NULL)
		return NULL;
	if((*t)->data == key)
		return *t;
	p = Find(&((*t)->leftChild), key);
	if(p != NULL)
		return p;
	return Find(&((*t)->rightChild), key);
}

BinTreeNode* Clone(BinTree *t)
{
	if(*t == NULL)
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = (*t)->data;
		p->leftChild = Clone(&((*t)->leftChild));
		p->rightChild = Clone(&((*t)->rightChild));
		return p;
	}
}

int Equal(BinTree *t1, BinTree *t2)
{
	if(*t1 == NULL && *t2 == NULL)
		return 1;
	if(*t1 == NULL || *t2 == NULL)
		return 0;
	return ((*t1)->data == (*t2)->data)
		&& Equal(&((*t1)->leftChild), &((*t2)->leftChild))
		&& Equal(&((*t1)->rightChild), &((*t2)->rightChild));
}

BinTreeNode* Parent(BinTree *t, DataType key)
{
	BinTreeNode *p = Find(t, key);
	BinTreeNode *pr = NULL;
	if(p == NULL || p == *t)
		return NULL;
	if((*t)->leftChild == p || (*t)->rightChild == p)
		return *t;
	pr = Parent(&((*t)->leftChild), key);
	if(pr != NULL)
		return pr;
	return Parent(&((*t)->rightChild), key);
}
#endif