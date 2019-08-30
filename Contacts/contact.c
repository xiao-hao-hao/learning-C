#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

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
	pbook->capasity = DEFAULT_SIZE;
}

void check_capacity(address_book *pbook)
{
	assert(pbook);
	if (pbook->capasity == pbook->count)//�������������
	{
		person_info *ptmp = (person_info *)realloc(pbook->data, (pbook->capasity+2)*sizeof(person_info));
		if (ptmp != NULL)
		{
			pbook->capasity += 2;
			pbook->data = ptmp;
			printf("���ݳɹ�!\n");
		}
	}
}

void address_book_show(const address_book *pbook)
{
	int i = 0;
	if (pbook->count == 0)
	{
		printf("ͨѶ¼����Ϊ�գ�����ϵ�˿���ʾ��\n");
		return;
	}
	printf("%-8s%-14s%-8s%-7s%-15s%-24s\n", "���","����", "�Ա�", "����", "�绰", "��ַ");
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
	pbook->data[pbook->count].number = pbook->count + 1;
	(pbook->count)++;
	printf("��ӳɹ���\n");
}

void address_book_del_all(address_book *pbook)
{
	address_book_init(pbook);
	free(pbook->data);
	pbook->data = NULL;
	address_book_init(pbook);
	printf("ͨѶ¼�����Ѿ�����գ�\n");
}

static int Find(const address_book *pbook, char *name, int i)////������ϵ�˲����ظ���ϵ�˵�λ�ã��Ҳ�������-1
{
	for (; i < (pbook->count); i++)//i��ʾҪ���ҵ�λ��
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
	if (0 == (pbook->count))
	{
		printf("ͨѶ¼Ϊ�գ�û�����ݿ�ɾ����\n");
		return;
	}
	printf("������Ҫɾ������ϵ�˵�����>> ");
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
					"���","����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("�Ҳ�����ϵ�ˣ�%s��\n", name);
	}
	else
	{
		while (1)
		{
			printf("������Ҫɾ������ϵ�˵����>> ");
			scanf("%d", &i);
			if (strcmp(pbook->data[i-1].name, name) != 0)
			{
				printf("���������������������룡\n");
				continue;
			}
			else//���������������������Ӧ�Ż�ɾ��
			{
				for (;i < pbook->count; i++)
				{
					pbook->data[i-1] = pbook->data[i];
					pbook->data[i-1].number = i;//�������
				}
				memset(&(pbook->data[(pbook->count) - 1]), '0', sizeof(person_info));//���һ����Ԫ���
				printf("ɾ���ɹ���\n");
				(pbook->count)--;
				break;
			}
		}
	}
}

void address_book_find(address_book *pbook)
{
	int tmp = 0;
	int tag1 = 0;//����Ƿ��ҵ�
	int tag2 = 0;//��ǲ��ҵ�λ��
	char name[11] = {0};
	if (0 == (pbook->count))
	{
		printf("ͨѶ¼Ϊ�գ������ݿɲ��ң�\n");
		return;
	}
	printf("������Ҫ���ҵ���ϵ�˵�����>> ");
	scanf("%s", name);
	while (tag2 < (pbook->count))
	{
		tmp = Find(pbook, name, tag2);
		if (-1 != tmp)
		{
			tag2 = tmp + 1;//����ҵ��˾͸���tag2
			if (0 == tag1)
			{
				printf("%-8s%-14s%-8s%-7s%-15s%-24s\n",
					"���","����", "�Ա�", "����", "�绰", "��ַ");
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
	tmp = Find(pbook, name, i);
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