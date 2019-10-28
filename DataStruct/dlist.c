#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include "dlist.h"
int main()
{
	int select = 1;
	DataType data = 0;
	DataType dest = 0;
	DListNode *ret = NULL;
    DList mylist;
    DListInit(&mylist);
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
        printf("请选择:>");
        scanf("%d", &select);
        switch(select)
        {
        case 0:
			system("cls");
			printf("退出成功!\n");
            break;
        case 1:
            printf("请输入要插入的数据<-1结束>:>");
            while(scanf("%d", &data), data != -1)
            {
                DListPushBack(&mylist, data);
            }
            break;
        case 2:
            printf("请输入要插入的数据<-1>结束:>");
            while(scanf("%d", &data), data != -1)
            {
                DListPushFront(&mylist, data);
            }
            break;
        case 3:
            DListShow(&mylist);
            break;
        case 4:
            DListPopBack(&mylist);
            break;
        case 5:
            DListPopFront(&mylist);
            break;
        case 6:
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			DListInsertByVal(&mylist, data);//要求单循环链表为有序链表
			break;
		case 7:
			printf("请输入要删除的数据:>");
			scanf("%d", &data);
			DListDeleteByVal(&mylist, data);
			break;
		case 8:
			printf("请输入要查找的数据:>");
			scanf("%d", &data);
			ret = DListFindByVal(&mylist, data);
			if(ret != NULL)
				printf("数据%d的地址为:>%x\n", data, ret);
			break;
		case 9:
			printf("请输入要修改的数据:>");
			scanf("%d", &dest);
			printf("请输入目标数据:>");
			scanf("%d", &data);
			DListModifyByVal(&mylist, dest, data);
			break;
		case 10:
			printf("单链表的长度为:>%d\n", DListLength(&mylist));
			break;
		case 11:
			DListClear(&mylist);
			break;
		case 12:
			DListReverse(&mylist);
			break;
		case 13:
			DListSort(&mylist);
			break;
		default:
            printf("输入错误，请重新输入!\n");
            break;
        }
		if(select != 0)
		{
			system("pause");
			system("cls");		
		}

    }
	//SCListDestroy(&mylist);
    return 0;
}

#endif