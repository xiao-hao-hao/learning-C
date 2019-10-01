#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

int main()
{
	int select = 1;
	DataType data = 0;
	int pos = 0;
    SeqList mylist;
    SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);
    while(select)
    {
        printf("********************************\n");
        printf("* [1]push_back   [2]push_front *\n");
        printf("* [3]show_list   [0]quit_system*\n");
        printf("* [4]pop_back    [5]pop_front  *\n");
        printf("* [6]insert_pos  [7]insert_val *\n");
        printf("* [8]delete_pos  [9]delete_val *\n");
        printf("********************************\n");
        printf("��ѡ��:>");
        scanf("%d", &select);
        switch(select)
        {
        case 0:
            printf("�˳��ɹ�!\n");
            break;
        case 1:
            printf("������Ҫ���������<-1����>:>");
            while(scanf("%d", &data), data != -1)
            {
                SeqListPushBack(&mylist, data);
            }
            break;
        case 2:
            printf("������Ҫ���������<-1>����:>");
            while(scanf("%d", &data), data != -1)
            {
                SeqListPushFront(&mylist, data);
            }
            break;
        case 3:
            SeqListShow(&mylist);
            break;
        case 4:
            SeqListPopBack(&mylist);
            break;
        case 5:
            SeqListPopFront(&mylist);
            break;
        case 6:
            printf("������Ҫ���λ��:>");
            scanf("%d", &pos);
            printf("������Ҫ���������:>");
            scanf("%d", &data);
            SeqListInsertByPos(&mylist, pos, data);
			break;
		case 7:
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SeqListInsertByVal(&mylist, data);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			DeleteByPos(&mylist, pos);
			break;
        default:
            printf("�����������������!\n");
            break;
        }
		system("pause");
		system("cls");
    }
    return 0;
}