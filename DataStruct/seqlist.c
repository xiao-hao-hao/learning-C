#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

int main()
{
	int select = 1;
	DataType data = 0;
	DataType dest = 0;
	int pos = 0;
	int ret = 0;
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
        printf("* [10]find_pos   [11]find_val  *\n");
        printf("* [12]sort       [13]reverse   *\n");
        printf("* [14]length     [15]clear     *\n");
        printf("* [16]modify_pos [17]modify_val*\n");
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
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &data);
			SeqListDeleteByVal(&mylist, data);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��:>");
			scanf("%d", &pos);
			ret = SeqListFindByPos(&mylist, pos, &data);
			if(ret)
				printf("λ��%d����ֵΪ:> %d\n", pos, data);
			break;
		case 11:
			printf("������Ҫ���ҵ�����:>");
			scanf("%d", &data);
			ret = SeqListFindByVal(&mylist, data);
			if(-1 != ret)
				printf("%d��λ����:> %d\n", data, ret);
			else
				printf("Ҫ���ҵ����ݲ�����!\n");
			break;
		case 12:
			SeqListSort(&mylist);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			ret = SeqListLength(&mylist);
			printf("˳���ĳ���Ϊ:> %d\n", ret);
			break;
		case 15:
			SeqListClear(&mylist);
			break;
		case 16:
			printf("������Ҫ�޸ĵ�λ��:>");
			scanf("%d", &pos);
			printf("������Ŀ��ֵ:>");
			scanf("%d", &data);
			SeqListModifyByPos(&mylist, pos, data);
			break;
		case 17:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%d", &dest);
			printf("������Ŀ��ֵ:>");
			scanf("%d", &data);
			SeqListModifyByVal(&mylist, dest, data);
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