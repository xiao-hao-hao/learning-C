#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContacts(Contacts *pc)
{
	pc->count = 0;
	memset(pc->con, '0', sizeof(pc->con));
}

void Show(const Contacts *pc)
{
	int i = 0;
	printf("%-14s%-8s%-7s%-15s%-24s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < (pc->count); i++)
	{
		printf("%-14s%-8s%-7d%-15s%-24s\n", 
			pc->con[i].name,
			pc->con[i].sex,
			pc->con[i].age,
			pc->con[i].tel,
			pc->con[i].addr);
	}

}

void Add(Contacts *pc)
{
	printf("姓名>> ");
	scanf("%s", pc->con[pc->count].name);
	printf("性别>> ");
	scanf("%s", pc->con[pc->count].sex);
	printf("年龄>> ");
	scanf("%d", &(pc->con[pc->count].age));
	printf("电话>> ");
	scanf("%s", pc->con[pc->count].tel);
	printf("地址>> ");
	scanf("%s", pc->con[pc->count].addr);
	(pc->count)++;
}

void Empty(Contacts *pc)
{
	InitContacts(pc);
	printf("通讯录内容已经被清空！\n");
}

int Find(const Contacts *pc, char *name)
{
	int i = 0;
	for (i = 0; i < (pc->count); i++)
	{
		if (strcmp((pc->con[i]).name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void Del(Contacts *pc)
{
	int i = 0;
	char name[11] = {0};
	if (0 == (pc->count))
	{
		printf("通讯录已空，没有内容可删除！\n");
		return;
	}
	printf("请输入要删除的联系人的姓名>> ");
	scanf("%s", name);
	if (-1 != Find(pc, name))
	{
		for (i = Find(pc, name); i < ((pc->count) - 1); i++)
		{
			pc->con[i] = pc->con[i+1];
		}
		printf("删除成功！\n");
		(pc->count)--;
	}
	else
	{
		printf("找不到联系人：%s！\n", name);
	}
}