#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include "bintree.h"

int main()
{
	BinTree bt;
	BinTree bt_clone;
	BinTreeNode *pr = NULL;
	char *str = "ABC##DE##F##G#H##";
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int i = 0;
	BinTreeNode *p = NULL;
	BinTree bt_db;
	BinTreeInit(&bt);
	BinTreeInit(&bt_clone);
	//bt = BinTreeCreate_1();
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	//printf("VLR:");//前序打印
	//PreOrder(&bt);
	//printf("\n");
	//printf("LevelOrder:");
	//LevelOrder(&bt);//层序遍历
	//printf("\n");
	//printf("PreOrderNoR:");//非递归前序遍历
	//PreOrderNoR(&bt);
	//printf("\n");
	printf("LVR:");//中序打印
	InOrder(&bt);
	printf("\n");
	printf("LVRNR:");//非递归中序打印
	InOrderNoR(&bt);
	printf("\n");
	printf("LRV:");//后序打印
	PostOrder(&bt);
	printf("\n");
	printf("LRVNR:");
	PostOrderNoR(&bt);
	printf("\n");
	//printf("%d\n", Height(&bt));//打印数高，深度
	//printf("%d\n", Size(&bt));//打印二叉树节点的个数
	//Clone(&bt_clone, &bt);//复制一个二叉树
	//printf("VLRCLONE:");
	//PreOrder(&bt_clone);
	//printf("\n");
	//printf("%d\n", Equal(&bt, &bt_clone));
	//pr = Parent(&bt, 'G');//寻找data为G的节点的父节点
	//printf("%c\n", pr->data);
	//p = Find(&bt, 'Z');//寻找data为Z的节点是否存在,返回该节点的地址
	printf("LVR_LRV_LEVORDER:");
	BinTreeCreateBy_LVR_LRV(&bt_db, lvr, lrv, 8);
	LevelOrder(&bt_db);
	printf("\n");

	printf("VLR_LVR_LEVORDER:");
	BinTreeCreateBy_VLR_LVR(&bt_db, vlr, lvr, 8);
	LevelOrder(&bt_db);
	printf("\n");
	BinTreeDestroy(&bt);
	BinTreeDestroy(&bt_db);
	BinTreeDestroy(&bt_clone);
	return 0;
}
#endif