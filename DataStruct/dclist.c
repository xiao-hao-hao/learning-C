#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include "dclist.h"
int main()
{
	int select = 1;
	DataType data = 0;
	DataType dest = 0;
	DCListNode *ret = NULL;
    DCList mylist;
    DCListInit(&mylist);
    while(select)
    {
        printf("********************************\n");
        printf("* [1]push_back   [2]push_front *\n");
        printf("* [3]show_list   [0]quit_system*\n");
        printf("* [4]pop_back    [5]pop_front  *\n");
        printf("* [6]insert_val  [7]delete_val *\n");
        printf("* [8]find_val    [9]modify_val *\n");
        printf("* [10]length     [11]clear     *\n");
		printf("* [12]reverse    [13]sort      *\n");
        printf("********************************\n");
        printf("��ѡ��:>");
        scanf("%d", &select);
        switch(select)
        {
        case 0:
			system("cls");
			printf("�˳��ɹ�!\n");
            break;
        case 1:
            printf("������Ҫ���������<-1����>:>");
            while(scanf("%d", &data), data != -1)
            {
                DCListPushBack(&mylist, data);
            }
            break;
        case 2:
            printf("������Ҫ���������<-1>����:>");
            while(scanf("%d", &data), data != -1)
            {
                DCListPushFront(&mylist, data);
            }
            break;
        case 3:
            DCListShow(&mylist);
            break;
        case 4:
            DCListPopBack(&mylist);
            break;
        case 5:
            DCListPopFront(&mylist);
            break;
        case 6:
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			DCListInsertByVal(&mylist, data);//Ҫ��ѭ������Ϊ��������
			break;
		case 7:
			printf("������Ҫɾ��������:>");
			scanf("%d", &data);
			DCListDeleteByVal(&mylist, data);
			break;
		case 8:
			printf("������Ҫ���ҵ�����:>");
			scanf("%d", &data);
			ret = DCListFindByVal(&mylist, data);
			if(ret != NULL)
				printf("����%d�ĵ�ַΪ:>%x\n", data, ret);
			break;
		case 9:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%d", &dest);
			printf("������Ŀ������:>");
			scanf("%d", &data);
			DCListModifyByVal(&mylist, dest, data);
			break;
		case 10:
			printf("������ĳ���Ϊ:>%d\n", DCListLength(&mylist));
			break;
		case 11:
			DCListClear(&mylist);
			break;
		case 12:
			DCListReverse(&mylist);
			break;
		case 13:
			DCListSort(&mylist);
			break;
		default:
            printf("�����������������!\n");
            break;
        }
		if(select != 0)
		{
			system("pause");
			system("cls");		
		}

    }
	DCListDestroy(&mylist);
    return 0;
}

#endif