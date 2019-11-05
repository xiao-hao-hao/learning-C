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
	//printf("VLR:");//ǰ���ӡ
	//PreOrder(&bt);
	//printf("\n");
	//printf("LevelOrder:");
	//LevelOrder(&bt);//�������
	//printf("\n");
	//printf("PreOrderNoR:");//�ǵݹ�ǰ�����
	//PreOrderNoR(&bt);
	//printf("\n");
	printf("LVR:");//�����ӡ
	InOrder(&bt);
	printf("\n");
	printf("LVRNR:");//�ǵݹ������ӡ
	InOrderNoR(&bt);
	printf("\n");
	printf("LRV:");//�����ӡ
	PostOrder(&bt);
	printf("\n");
	printf("LRVNR:");
	PostOrderNoR(&bt);
	printf("\n");
	//printf("%d\n", Height(&bt));//��ӡ���ߣ����
	//printf("%d\n", Size(&bt));//��ӡ�������ڵ�ĸ���
	//Clone(&bt_clone, &bt);//����һ��������
	//printf("VLRCLONE:");
	//PreOrder(&bt_clone);
	//printf("\n");
	//printf("%d\n", Equal(&bt, &bt_clone));
	//pr = Parent(&bt, 'G');//Ѱ��dataΪG�Ľڵ�ĸ��ڵ�
	//printf("%c\n", pr->data);
	//p = Find(&bt, 'Z');//Ѱ��dataΪZ�Ľڵ��Ƿ����,���ظýڵ�ĵ�ַ
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