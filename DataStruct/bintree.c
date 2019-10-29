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
	//bt = BinTreeCreate_1();
	//BinTreeCreate_2(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	printf("VLR:");
	PreOrder(bt);
	printf("\n");
	printf("LevelOrder:");
	LevelOrder(&bt);
	printf("\n");
	//printf("LVR:");
	//InOrder(bt);
	//printf("\n");
	//printf("LRV:");
	//PostOrder(bt);
	//printf("\n");
	//printf("%d\n", Height(&bt));
	//printf("%d\n", Size(&bt));
	bt_clone = Clone(&bt);
	printf("VLR:");
	PreOrder(bt_clone);
	printf("\n");
	printf("%d\n", Equal(&bt, &bt_clone));
	pr = Parent(&bt, 'G');
	printf("%c\n", pr->data);
	//p = Find(&bt, 'Z');
	return 0;
}