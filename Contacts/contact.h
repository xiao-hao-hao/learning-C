#include <stdio.h>
#include <string.h>

#define NAME_MAX 11
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 21
#define CONTACT_NUM 1000

enum//���˵�����Ϊһ��ö����
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT
};

typedef struct Contact
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	short age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Contact;

typedef struct Contacts
{
	Contact con[CONTACT_NUM];
	int count;
}Contacts;

void InitContacts(Contacts *);//��ʼ��ͨѶ¼
void Add(Contacts *);//�����ϵ��
void Show(const Contacts *);//��ʾ������ϵ����Ϣ 
void Empty(Contacts *);//���������ϵ��
void Del(Contacts *);//	ɾ��ָ����ϵ����Ϣ 
int Find(const Contacts *, char *);//������ϵ�˲����ظ���ϵ�˵�λ�ã��Ҳ�������-1