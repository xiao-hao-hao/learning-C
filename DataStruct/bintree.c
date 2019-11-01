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
	printf("VLR:");//ǰ���ӡ
	PreOrder(&bt);
	printf("\n");
	printf("LevelOrder:");
	LevelOrder(&bt);//�������
	printf("\n");
	printf("PreOrderNoR:");//�ǵݹ�ǰ�����
	PreOrderNoR(&bt);
	printf("\n");
	//printf("LVR:");//�����ӡ
	//InOrder(bt);
	//printf("\n");
	//printf("LRV:");//�����ӡ
	//PostOrder(bt);
	//printf("\n");
	//printf("%d\n", Height(&bt));//��ӡ���ߣ����
	//printf("%d\n", Size(&bt));//��ӡ�������ڵ�ĸ���
	Clone(&bt_clone, &bt);//����һ��������
	printf("VLRCLONE:");
	PreOrder(&bt_clone);
	printf("\n");
	printf("%d\n", Equal(&bt, &bt_clone));
	pr = Parent(&bt, 'G');//Ѱ��dataΪG�Ľڵ�ĸ��ڵ�
	printf("%c\n", pr->data);
	p = Find(&bt, 'Z');//Ѱ��dataΪZ�Ľڵ��Ƿ����,���ظýڵ�ĵ�ַ
	return 0;
}