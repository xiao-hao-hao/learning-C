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
        printf("请选择:>");
        scanf("%d", &select);
        switch(select)
        {
        case 0:
            printf("退出成功!\n");
            break;
        case 1:
            printf("请输入要插入的数据<-1结束>:>");
            while(scanf("%d", &data), data != -1)
            {
                SeqListPushBack(&mylist, data);
            }
            break;
        case 2:
            printf("请输入要插入的数据<-1>结束:>");
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
            printf("请输入要插的位置:>");
            scanf("%d", &pos);
            printf("请输入要插入的数据:>");
            scanf("%d", &data);
            SeqListInsertByPos(&mylist, pos, data);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &data);
			SeqListInsertByVal(&mylist, data);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &data);
			SeqListDeleteByVal(&mylist, data);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			ret = SeqListFindByPos(&mylist, pos, &data);
			if(ret)
				printf("位置%d处的值为:> %d\n", pos, data);
			break;
		case 11:
			printf("请输入要查找的数据:>");
			scanf("%d", &data);
			ret = SeqListFindByVal(&mylist, data);
			if(-1 != ret)
				printf("%d的位置是:> %d\n", data, ret);
			else
				printf("要查找的数据不存在!\n");
			break;
		case 12:
			SeqListSort(&mylist);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			ret = SeqListLength(&mylist);
			printf("顺序表的长度为:> %d\n", ret);
			break;
		case 15:
			SeqListClear(&mylist);
			break;
		case 16:
			printf("请输入要修改的位置:>");
			scanf("%d", &pos);
			printf("请输入目标值:>");
			scanf("%d", &data);
			SeqListModifyByPos(&mylist, pos, data);
			break;
		case 17:
			printf("请输入要修改的数据:>");
			scanf("%d", &dest);
			printf("请输入目标值:>");
			scanf("%d", &data);
			SeqListModifyByVal(&mylist, dest, data);
			break;
		default:
            printf("输入错误，请重新输入!\n");
            break;
        }
		system("pause");
		system("cls");
    }
    return 0;
}