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
	printf("%-14s%-8s%-7s%-15s%-24s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("����>> ");
	scanf("%s", pc->con[pc->count].name);
	printf("�Ա�>> ");
	scanf("%s", pc->con[pc->count].sex);
	printf("����>> ");
	scanf("%d", &(pc->con[pc->count].age));
	printf("�绰>> ");
	scanf("%s", pc->con[pc->count].tel);
	printf("��ַ>> ");
	scanf("%s", pc->con[pc->count].addr);
	(pc->count)++;
}

void Empty(Contacts *pc)
{
	InitContacts(pc);
	printf("ͨѶ¼�����Ѿ�����գ�\n");
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
		printf("ͨѶ¼�ѿգ�û�����ݿ�ɾ����\n");
		return;
	}
	printf("������Ҫɾ������ϵ�˵�����>> ");
	scanf("%s", name);
	if (-1 != Find(pc, name))
	{
		for (i = Find(pc, name); i < ((pc->count) - 1); i++)
		{
			pc->con[i] = pc->con[i+1];
		}
		printf("ɾ���ɹ���\n");
		(pc->count)--;
	}
	else
	{
		printf("�Ҳ�����ϵ�ˣ�%s��\n", name);
	}
}