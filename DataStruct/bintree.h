#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "common.h"

//ABC##DE##F##G#H##

typedef struct BinTreeNode
{
	char data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;


//typedef BinTreeNode* BinTree;
#include "linkqueue.h"

void BinTreeInit(BinTree *t);

BinTreeNode* _BinTreeCreate_1();
void _BinTreeCreate_2(BinTreeNode **t);
void BinTreeCreate(BinTree *t);

void PreOrder(BinTree *t);
void _PreOrder(BinTreeNode *t);

void InOrder(BinTree *t);
void _InOrder(BinTreeNode *t);

void PostOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);

void LevelOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);

void PreOrderNoR(BinTree *t);
void _PreOrderNoR(BinTreeNode *t);

size_t Height(BinTree *t);
size_t _Height(BinTreeNode *t);

size_t Size(BinTree *t);
size_t _Size(BinTreeNode *t);

BinTreeNode* Find(BinTree *t, char key);
BinTreeNode* _Find(BinTreeNode *t, char key);

BinTreeNode* Parent(BinTree *t, char key);
BinTreeNode* _Parent(BinTreeNode *t, char key);

void BinTreeCreateByStr(BinTree *t, char *str, int *i);
BinTreeNode* _BinTreeCreateByStr(char *str, int *i);/////////////?????

void Clone(BinTree *t1, BinTree *t2);
BinTreeNode* _Clone(BinTreeNode *t);

int Equal(BinTree *t1, BinTree *t2);
int _Equal(BinTreeNode *t1, BinTreeNode *t2);

void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}

void BinTreeCreate(BinTree *t)
{
	//t->root = _BinTreeCreate_1();//用方法一生成二叉树
	_BinTreeCreate_2(&(t->root));//用方法二生成二叉树
}

BinTreeNode* _BinTreeCreate_1()//前序法创建（根左右）
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
		t->leftChild = _BinTreeCreate_1();
		t->rightChild = _BinTreeCreate_1();
		return t;
	}
}

void _BinTreeCreate_2(BinTreeNode **t)
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
		_BinTreeCreate_2(&((*t)->leftChild));
		_BinTreeCreate_2(&((*t)->rightChild));
	}
}

void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}

void _PreOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}

void InOrder(BinTree *t)
{
	_InOrder(t->root);
}

void _InOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		_InOrder(t->leftChild);
		printf("%c ", t->data);
		_InOrder(t->rightChild);
	}
}

void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}

void _PostOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		_PostOrder(t->leftChild);
		_PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

void LevelOrder(BinTree *t)
{
	_LevelOrder(t->root);
}

void _LevelOrder(BinTreeNode *t)
{
	if(t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEn(&Q, t);
		while(!LinkQueueEmpty(&Q))
		{
			BinTreeNode *p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c", p->data);
			if(p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if(p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}
	}
}

size_t Height(BinTree *t)
{
	return _Height(t->root);
}

size_t _Height(BinTreeNode *t)
{
	if(t == NULL)
		return 0;
	else
		return _Height(t->leftChild) > _Height(t->rightChild)
		? _Height(t->leftChild)+1 : _Height(t->rightChild)+1;
}

size_t Size(BinTree *t)
{
	return _Size(t->root);
}

size_t _Size(BinTreeNode *t)
{
	if(t == NULL)
		return 0;
	else
		return _Size(t->leftChild) + _Size(t->rightChild) + 1;
}

void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	//*i = 0;
	t->root = _BinTreeCreateByStr(str, i);
}

BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	if(str[*i] == '#')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*i];
		++(*i);
		t->leftChild = _BinTreeCreateByStr(str, i);
		++(*i);
		t->rightChild = _BinTreeCreateByStr(str, i);
		return t;
	}
}

BinTreeNode* Find(BinTree *t, char key)
{
	return _Find(t->root, key);
}

BinTreeNode* _Find(BinTreeNode *t, char key)
{
	BinTreeNode *p = NULL;
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;
	p = _Find(t->leftChild, key);
	if(p != NULL)
		return p;
	return _Find(t->rightChild, key);
}

void Clone(BinTree *t1, BinTree *t2)
{
	t1->root = _Clone(t2->root);
}

BinTreeNode* _Clone(BinTreeNode *t)
{
	if(t == NULL)
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = t->data;
		p->leftChild = _Clone(t->leftChild);
		p->rightChild = _Clone(t->rightChild);
		return p;
	}
}

int Equal(BinTree *t1, BinTree *t2)
{
	return _Equal(t1->root, t2->root);
}

int _Equal(BinTreeNode *t1, BinTreeNode *t2)
{
	if(t1 == NULL && t2 == NULL)
		return 1;
	if(t1 == NULL || t2 == NULL)
		return 0;
	return (t1->data == t2->data)
		&& _Equal(t1->leftChild, t2->leftChild)
		&& _Equal(t1->rightChild, t2->rightChild);
}

BinTreeNode* Parent(BinTree *t, char key)
{
	return _Parent(t->root, key);
}

BinTreeNode* _Parent(BinTreeNode *t, char key)
{
	BinTreeNode *p = _Find(t, key);
	BinTreeNode *pr = NULL;
	if(p == NULL || p == t)
		return NULL;
	if(t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if(pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);
}
///////////////////////////////////////////////////////////
#include "liststack.h"
void PreOrderNoR(BinTree *t)//用非递归的方法前序遍历
{
	_PreOrderNoR(t->root);
}

void _PreOrderNoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		BinTreeNode *p = NULL;
		ListStack st;
		ListStackInit(&st);
		ListStackPush(&st, t);
		while(!ListStackEmpty(&st))
		{
			p = ListStackTop(&st);
			ListStackPop(&st);
			printf("%c ", p->data);
			if(p->rightChild != NULL)
				ListStackPush(&st, p->rightChild);
			if(p->leftChild != NULL)
				ListStackPush(&st, p->leftChild);
		}
	}
}
#endif