//��ѭ������
#if 0
#define _CRT_SECURE_NO_WARNINGS 1

#include "sclist.h"

int main()
{
	int select = 1;
	DataType data = 0;
	DataType dest = 0;
	SCListNode *ret = NULL;
    SCList mylist;
    SCListInit(&mylist);
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
                SCListPushBack(&mylist, data);
            }
            break;
        case 2:
            printf("������Ҫ���������<-1>����:>");
            while(scanf("%d", &data), data != -1)
            {
                SCListPushFront(&mylist, data);
            }
            break;
        case 3:
            SCListShow(&mylist);
            break;
        case 4:
            SCListPopBack(&mylist);
            break;
        case 5:
            SCListPopFront(&mylist);
            break;
        case 6:
			printf("������Ҫ���������:>");
			scanf("%d", &data);
			SCListInsertByVal(&mylist, data);//Ҫ��ѭ������Ϊ��������
			break;
		case 7:
			printf("������Ҫɾ��������:>");
			scanf("%d", &data);
			SCListDeleteByVal(&mylist, data);
			break;
		case 8:
			printf("������Ҫ���ҵ�����:>");
			scanf("%d", &data);
			ret = SCListFindByVal(&mylist, data);
			if(ret != NULL)
				printf("����%d�ĵ�ַΪ:>%x\n", data, ret);
			break;
		case 9:
			printf("������Ҫ�޸ĵ�����:>");
			scanf("%d", &dest);
			printf("������Ŀ������:>");
			scanf("%d", &data);
			SCListModifyByVal(&mylist, dest, data);
			break;
		case 10:
			printf("������ĳ���Ϊ:>%d\n", SCListLength(&mylist));
			break;
		case 11:
			SCListClear(&mylist);
			break;
		case 12:
			SCListReverse(&mylist);
			break;
		case 13:
			SCListSort(&mylist);
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
	SCListDestroy(&mylist);
    return 0;
}
#endif