#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void check_capacity(address_book *pbook)
{
	assert(pbook);
	if (pbook->capacity == pbook->count)//如果满了则扩容
	{
		person_info *ptmp = (person_info *)realloc(pbook->data, (pbook->capacity+2)*sizeof(person_info));
		if (ptmp != NULL)
		{
			pbook->capacity += 2;
			pbook->data = ptmp;
			//printf("扩容成功!\n");
		}
	}
}

void address_book_load(address_book *pbook)
{
	person_info tmp = {0};
	FILE *pfread = fopen("address book.data", "rb");
	if (pfread == NULL)
	{
		printf("加载失败：打开文件失败！\n");
		return;
	}
	//加载消息
	while (fread(&tmp, sizeof(person_info), 1, pfread))
	{
		check_capacity(pbook);
		pbook->data[pbook->count] = tmp;
		pbook->count++;
	}
	fclose(pfread);
	pfread = NULL;
}

void address_book_init(address_book *pbook)
{
	pbook->count = 0;
	//memset(pbook->data, '0', sizeof(pbook->data));
	pbook->data = (person_info *)calloc(DEFAULT_SIZE, sizeof(person_info));
	if (pbook->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	pbook->capacity = DEFAULT_SIZE;
	address_book_load(pbook);//加载通讯录
}

void address_book_show(const address_book *pbook)
{
	int i = 0;
	if (pbook->count == 0)
	{
		printf("通讯录内容为空，无联系人可显示！\n");
		return;
	}
	printf("%-8s%-14s%-8s%-7s%-15s%-24s\n", "序号","姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < (pbook->count); i++)
	{
		printf("%-8d%-14s%-8s%-7d%-15s%-24s\n",
			pbook->data[i].number,
			pbook->data[i].name,
			pbook->data[i].sex,
			pbook->data[i].age,
			pbook->data[i].tel,
			pbook->data[i].addr);
	}

}

void address_book_add(address_book *pbook)
{
	assert(pbook);
	check_capacity(pbook);
	printf("请输入要添加的联系人的信息！\n");
	printf("姓名>> ");
	scanf("%s", pbook->data[pbook->count].name);
	printf("性别>> ");
	scanf("%s", pbook->data[pbook->count].sex);
	printf("年龄>> ");
	scanf("%d", &(pbook->data[pbook->count].age));
	printf("电话>> ");
	scanf("%s", pbook->data[pbook->count].tel);
	printf("地址>> ");
	scanf("%s", pbook->data[pbook->count].addr);
	pbook->data[pbook->count].number = pbook->count + 1;
	(pbook->count)++;
	printf("添加成功！\n");
}

void address_book_del_all(address_book *pbook)
{
	free(pbook->data);
	pbook->data = NULL;
	pbook->capacity = 0;
	pbook->count = 0;
	printf("通讯录内容已经被清空！\n");
}

static int Find(const address_book *pbook, char *name, int i)//查找联系人并返回该联系人的位置，找不到返回-1
{
	for (; i < (pbook->count); i++)//i表示要查找的位置
	{
		if (strcmp((pbook->data[i]).name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void address_book_del(address_book *pbook)
{	
	int i = 0;
	int tmp = 0;
	int tag1 = 0;
	int tag2 = 0;
	char name[11] = {0};
	person_info empty = {0};
	if (0 == (pbook->count))
	{
		printf("通讯录为空，没有内容可删除！\n");
		return;
	}
	printf("请输入要删除的联系人的姓名>> ");
	scanf("%s", name);
	while (tmp < (pbook->count))
	{
		tmp = Find(pbook, name, tag2);
		if (-1 != tmp)
		{
			tag2 = tmp + 1;
			if (0 == tag1)
			{
				printf("%-8s%-14s%-8s%-7s%-15s%-24s\n",
					"序号","姓名", "性别", "年龄", "电话", "地址");
			}
			printf("%-8d%-14s%-8s%-7d%-15s%-24s\n",
				pbook->data[tmp].number,
				pbook->data[tmp].name,
				pbook->data[tmp].sex,
				pbook->data[tmp].age,
				pbook->data[tmp].tel,
				pbook->data[tmp].addr);
			tag1 = 1;
		}
		else
		{
			break;
		}
	}
	if (0 == tag1)
	{
		printf("找不到联系人：%s！\n", name);
	}
	else
	{
		while (1)
		{
			printf("请输入要删除的联系人的序号>> ");
			scanf("%d", &i);
			if (strcmp(pbook->data[i-1].name, name) != 0)
			{
				printf("输入的序号有误，请重新输入！\n");
				continue;
			}
			else//输入的序号与输入的姓名对应才会删除
			{
				for (;i < pbook->count; i++)
				{
					pbook->data[i-1] = pbook->data[i];
					pbook->data[i-1].number = i;//修正序号
				}
				//memset(&(pbook->data[(pbook->count) - 1]), '0', sizeof(person_info));//最后一个单元清空
				pbook->data[(pbook->count) - 1] = empty;
				printf("删除成功！\n");
				(pbook->count)--;
				break;
			}
		}
	}
}

void address_book_find(address_book *pbook)
{
	int tmp = 0;
	int tag1 = 0;//标记是否找到
	int tag2 = 0;//标记查找的位置
	char name[11] = {0};
	if (0 == (pbook->count))
	{
		printf("通讯录为空，无内容可查找！\n");
		return;
	}
	printf("请输入要查找的联系人的姓名>> ");
	scanf("%s", name);
	while (tag2 < (pbook->count))
	{
		tmp = Find(pbook, name, tag2);
		if (-1 != tmp)
		{
			tag2 = tmp + 1;//如果找到了就更新tag2
			if (0 == tag1)
			{
				printf("%-8s%-14s%-8s%-7s%-15s%-24s\n",
					"序号","姓名", "性别", "年龄", "电话", "地址");
			}
			printf("%-8d%-14s%-8s%-7d%-15s%-24s\n",
				pbook->data[tmp].number,
				pbook->data[tmp].name,
				pbook->data[tmp].sex,
				pbook->data[tmp].age,
				pbook->data[tmp].tel,
				pbook->data[tmp].addr);
			tag1 = 1;
		}
		else
		{
			break;
		}
	}
	if (0 == tag1)
	{
		printf("找不到联系人：%s！\n", name);
	}
}

void address_book_update(address_book *pbook)
{
	int i = 0;
	int tmp = 0;
	char name[11] = {0};
	if (0 == pbook->count)
	{
		printf("通讯录内容为空，无法修改联系人!\n");
		return;
	}
	printf("请输入要修改的联系人的姓名>> ");
	scanf("%s", name);
	tmp = Find(pbook, name, i);
	if (-1 != tmp)
	{
		printf("姓名修改为>> ");
		scanf("%s", pbook->data[tmp].name);
		printf("性别修改为>> ");
		scanf("%s", pbook->data[tmp].sex);
		printf("年龄修改为>> ");
		scanf("%d", &(pbook->data[tmp].age));//这里需要注意一下：记得取地址
		printf("电话修改为>> ");
		scanf("%s", pbook->data[tmp].tel);
		printf("地址修改为>> ");
		scanf("%s", pbook->data[tmp].addr);
		printf("修改成功！\n");
	}
	else
	{
		printf("找不到联系人：%s！\n", name);
	}
}

static int cmp_by_name(const void *p1, const void *p2)
{
	return strcmp(((person_info *)p1)->name, ((person_info *)p2)->name);
}

void sort_by_name(address_book *pbook)//使用qsort函数进行排序
{
	if (pbook->count == 0)
	{
		printf("通讯录的内容为空，不需要排序！\n");
		return;
	}
	qsort(pbook->data, (pbook->count), sizeof(pbook->data[0]), cmp_by_name);//需要排序的联系人个数是count个
	printf("排序成功\n");
}

void save_address_book(address_book *pbook)
{
	int i = 0;
	FILE *pfwrite = fopen("address book.data", "wb");
	if (pfwrite == NULL)
	{
		printf("保存失败：打开文件失败！\n");
		return;
	}
	for (i = 0; i < pbook->count; i++)
	{
		fwrite(pbook->data+i, sizeof(person_info), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}