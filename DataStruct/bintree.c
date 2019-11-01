#define _CRT_SECURE_NO_WARNINGS 1
#include "bintree.h"

int main()
{
	BinTree bt;
	BinTree bt_clone;
	BinTreeNode *pr = NULL;
	char *str = "ABC##DE##F##G#H##";
	int i = 0;
	BinTreeNode *p = NULL;
	BinTreeInit(&bt);
	BinTreeInit(&bt_clone);
	//bt = BinTreeCreate_1();
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	printf("VLR:");//前序打印
	PreOrder(&bt);
	printf("\n");
	printf("LevelOrder:");
	LevelOrder(&bt);//层序遍历
	printf("\n");
	printf("PreOrderNoR:");//非递归前序遍历
	PreOrderNoR(&bt);
	printf("\n");
	//printf("LVR:");//中序打印
	//InOrder(bt);
	//printf("\n");
	//printf("LRV:");//后序打印
	//PostOrder(bt);
	//printf("\n");
	//printf("%d\n", Height(&bt));//打印数高，深度
	//printf("%d\n", Size(&bt));//打印二叉树节点的个数
	Clone(&bt_clone, &bt);//复制一个二叉树
	printf("VLRCLONE:");
	PreOrder(&bt_clone);
	printf("\n");
	printf("%d\n", Equal(&bt, &bt_clone));
	pr = Parent(&bt, 'G');//寻找data为G的节点的父节点
	printf("%c\n", pr->data);
	p = Find(&bt, 'Z');//寻找data为Z的节点是否存在,返回该节点的地址
	return 0;
}