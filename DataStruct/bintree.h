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
void _BinTreeDestroy(BinTreeNode *t);
void BinTreeDestroy(BinTree *t);

//二叉树遍历 递归
void PreOrder(BinTree *t);
void _PreOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);

//二叉树遍历 非递归
void PreOrderNoR(BinTree *t);
void _PreOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t);
void PostOrderNoR(BinTree *t);
void _PostOrderNoR(BinTreeNode *t);

void LevelOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);


size_t Height(BinTree *t);
size_t _Height(BinTreeNode *t);

size_t Size(BinTree *t);
size_t _Size(BinTreeNode *t);

BinTreeNode* Find(BinTree *t, char key);
BinTreeNode* _Find(BinTreeNode *t, char key);

BinTreeNode* Parent(BinTree *t, char key);
BinTreeNode* _Parent(BinTreeNode *t, char key);

void BinTreeCreateByStr(BinTree *t, char *str, int *i);
BinTreeNode* _BinTreeCreateByStr(char *str, int *i);

void Clone(BinTree *t1, BinTree *t2);
BinTreeNode* _Clone(BinTreeNode *t);

int Equal(BinTree *t1, BinTree *t2);
int _Equal(BinTreeNode *t1, BinTreeNode *t2);

//由前序遍历和中序遍历以及由后序遍历和中序遍历来创建二叉树
void BinTreeCreateBy_LVR_LRV(BinTree *t, char *lvr, char *lrv, int n);//中序和后序
BinTreeNode* _BinTreeCreateBy_LVR_LRV(char *lvr, char *lrv, int n);

void BinTreeCreateBy_VLR_LVR(BinTree *t, char *lvr, char *lrv, int n);//前序和中序
BinTreeNode* _BinTreeCreateBy_VLR_LVR(char *lvr, char *lrv, int n);

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
	if(str[*i] == '#' || str[*i] == '\0')
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

//二叉树的遍历 非递归
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

void InOrderNoR(BinTree *t)
{
	_InOrderNoR(t->root);
}

void _InOrderNoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		BinTreeNode *p = NULL;
		ListStack st;
		ListStackInit(&st);
		do
		{
			while(t != NULL)
			{
				ListStackPush(&st, t);
				t = t->leftChild ;
			}
			p = ListStackTop(&st);
			ListStackPop(&st);
			printf("%c ", p->data);
			if(p->rightChild != NULL)
				t = p->rightChild;
		}while(!ListStackEmpty(&st) || t != NULL);
	}
}

void PostOrderNoR(BinTree *t)
{
	_PostOrderNoR(t->root);
}

void _PostOrderNoR(BinTreeNode *t)
{
	if(t != NULL)
	{
		BinTreeNode *p = NULL;
		BinTreeNode *pre = NULL;
		ListStack st;
		ListStackInit(&st);
		do
		{
			while(t != NULL)
			{
				ListStackPush(&st, t);
				t = t->leftChild;
			}
			p = ListStackTop(&st);
			if(p->rightChild == NULL || p->rightChild == pre)
			{
				ListStackPop(&st);
				printf("%c ", p->data);
				pre = p;
			}
			else
			{
				t = p->rightChild;
			}
		}while(!ListStackEmpty(&st));
	}
}

void BinTreeCreateBy_LVR_LRV(BinTree *t, char *lvr, char *lrv, int n)
{
	t->root = _BinTreeCreateBy_LVR_LRV(lvr, lrv, n);
}

BinTreeNode* _BinTreeCreateBy_LVR_LRV(char *lvr, char *lrv, int n)
{
	int k = 0;
	BinTreeNode *p = NULL;
	if(n == 0)
		return NULL;
	while(lvr[k] != lrv[n-1])
		++k;//5
	p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	p->data = lvr[k];
	p->rightChild = _BinTreeCreateBy_LVR_LRV(lvr+k+1, lrv+k, n-k-1);
	p->leftChild = _BinTreeCreateBy_LVR_LRV(lvr, lrv, k);
	return p;
}

void BinTreeCreateBy_VLR_LVR(BinTree *t, char *vlr, char *lvr, int n)
{
	t->root = _BinTreeCreateBy_VLR_LVR(vlr, lvr, n);
}
BinTreeNode* _BinTreeCreateBy_VLR_LVR(char *vlr, char *lvr, int n)
{
	int k = 0;
	BinTreeNode *p = NULL;
	if(n == 0)
		return NULL;
	while(lvr[k] != vlr[0])
		++k;//5
	p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	p->data = lvr[k];
	p->leftChild = _BinTreeCreateBy_VLR_LVR(vlr+1, lvr, k);
	p->rightChild = _BinTreeCreateBy_VLR_LVR(vlr+k+1, lvr+k+1, n-k-1);
	return p;
}

void _BinTreeDestroy(BinTreeNode *t)
{
	if(t == NULL)
		return;
	_BinTreeDestroy(t->leftChild);
	_BinTreeDestroy(t->rightChild);
	free(t);
}

void BinTreeDestroy(BinTree *t)
{
	_BinTreeDestroy(t->root);
	t->root = NULL;
}
#endif