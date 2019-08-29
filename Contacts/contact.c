#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void address_book_init(address_book *pbook)
{
	pbook->count = 0;
	memset(pbook->data, '0', sizeof(pbook->data));
}

void address_book_show(const address_book *pbook)
{
	int i = 0;
	if (pbook->count == 0)
	{
		printf("通讯录内容为空，无联系人可显示！\n");
		return;
	}
	printf("%-14s%-8s%-7s%-15s%-24s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < (pbook->count); i++)
	{
		printf("%-14s%-8s%-7d%-15s%-24s\n",
			pbook->data[i].name,
			pbook->data[i].sex,
			pbook->data[i].age,
			pbook->data[i].tel,
			pbook->data[i].addr);
	}

}

void address_book_add(address_book *pbook)
{
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
	(pbook->count)++;
	printf("添加成功！\n");
}

void address_book_del_all(address_book *pbook)
{
	address_book_init(pbook);
	printf("通讯录内容已经被清空！\n");
}

static int Find(const address_book *pbook, char *name)////查找联系人并返回该联系人的位置，找不到返回-1
{
	int i = 0;
	for (i = 0; i < (pbook->count); i++)
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
	char name[11] = {0};
	if (0 == (pbook->count))
	{
		printf("通讯录为空，没有内容可删除！\n");
		return;
	}
	printf("请输入要删除的联系人的姓名>> ");
	scanf("%s", name);
	tmp = Find(pbook, name);
	if (-1 != tmp)
	{
		for (i = Find(pbook, name); i < ((pbook->count) - 1); i++)
		{
			pbook->data[i] = pbook->data[i+1];
		}
		printf("删除成功！\n");
		(pbook->count)--;
	}
	else
	{
		printf("找不到联系人：%s！\n", name);
	}
}

void address_book_find(address_book *pbook)
{
	int tmp = 0;
	char name[11] = {0};
	if (0 == (pbook->count))
	{
		printf("通讯录为空，无内容可查找！\n");
		return;
	}
	printf("请输入要查找的联系人的姓名>> ");
	scanf("%s", name);
	tmp = Find(pbook, name);
	if (-1 != tmp)
	{
		printf("%-14s%-8s%-7d%-15s%-24s\n",
		pbook->data[tmp].name,
		pbook->data[tmp].sex,
		pbook->data[tmp].age,
		pbook->data[tmp].tel,
		pbook->data[tmp].addr);
	}
	else
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
	tmp = Find(pbook, name);
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