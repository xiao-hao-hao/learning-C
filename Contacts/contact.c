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
		printf("ͨѶ¼����Ϊ�գ�����ϵ�˿���ʾ��\n");
		return;
	}
	printf("%-14s%-8s%-7s%-15s%-24s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("������Ҫ��ӵ���ϵ�˵���Ϣ��\n");
	printf("����>> ");
	scanf("%s", pbook->data[pbook->count].name);
	printf("�Ա�>> ");
	scanf("%s", pbook->data[pbook->count].sex);
	printf("����>> ");
	scanf("%d", &(pbook->data[pbook->count].age));
	printf("�绰>> ");
	scanf("%s", pbook->data[pbook->count].tel);
	printf("��ַ>> ");
	scanf("%s", pbook->data[pbook->count].addr);
	(pbook->count)++;
	printf("��ӳɹ���\n");
}

void address_book_del_all(address_book *pbook)
{
	address_book_init(pbook);
	printf("ͨѶ¼�����Ѿ�����գ�\n");
}

static int Find(const address_book *pbook, char *name)////������ϵ�˲����ظ���ϵ�˵�λ�ã��Ҳ�������-1
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
		printf("ͨѶ¼Ϊ�գ�û�����ݿ�ɾ����\n");
		return;
	}
	printf("������Ҫɾ������ϵ�˵�����>> ");
	scanf("%s", name);
	tmp = Find(pbook, name);
	if (-1 != tmp)
	{
		for (i = Find(pbook, name); i < ((pbook->count) - 1); i++)
		{
			pbook->data[i] = pbook->data[i+1];
		}
		printf("ɾ���ɹ���\n");
		(pbook->count)--;
	}
	else
	{
		printf("�Ҳ�����ϵ�ˣ�%s��\n", name);
	}
}

void address_book_find(address_book *pbook)
{
	int tmp = 0;
	char name[11] = {0};
	if (0 == (pbook->count))
	{
		printf("ͨѶ¼Ϊ�գ������ݿɲ��ң�\n");
		return;
	}
	printf("������Ҫ���ҵ���ϵ�˵�����>> ");
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
		printf("�Ҳ�����ϵ�ˣ�%s��\n", name);
	}
}

void address_book_update(address_book *pbook)
{
	int i = 0;
	int tmp = 0;
	char name[11] = {0};
	if (0 == pbook->count)
	{
		printf("ͨѶ¼����Ϊ�գ��޷��޸���ϵ��!\n");
		return;
	}
	printf("������Ҫ�޸ĵ���ϵ�˵�����>> ");
	scanf("%s", name);
	tmp = Find(pbook, name);
	if (-1 != tmp)
	{
		printf("�����޸�Ϊ>> ");
		scanf("%s", pbook->data[tmp].name);
		printf("�Ա��޸�Ϊ>> ");
		scanf("%s", pbook->data[tmp].sex);
		printf("�����޸�Ϊ>> ");
		scanf("%d", &(pbook->data[tmp].age));//������Ҫע��һ�£��ǵ�ȡ��ַ
		printf("�绰�޸�Ϊ>> ");
		scanf("%s", pbook->data[tmp].tel);
		printf("��ַ�޸�Ϊ>> ");
		scanf("%s", pbook->data[tmp].addr);
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("�Ҳ�����ϵ�ˣ�%s��\n", name);
	}
}

static int cmp_by_name(const void *p1, const void *p2)
{
	return strcmp(((person_info *)p1)->name, ((person_info *)p2)->name);
}

void sort_by_name(address_book *pbook)//ʹ��qsort������������
{
	if (pbook->count == 0)
	{
		printf("ͨѶ¼������Ϊ�գ�����Ҫ����\n");
		return;
	}
	qsort(pbook->data, (pbook->count), sizeof(pbook->data[0]), cmp_by_name);//��Ҫ�������ϵ�˸�����count��
	printf("����ɹ�\n");
}