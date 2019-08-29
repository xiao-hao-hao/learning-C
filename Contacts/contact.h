#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct person_info
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	short age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}person_info;

typedef struct address_book
{
	person_info data[CONTACT_NUM];
	int count;
}address_book;

void address_book_init(address_book *);//��ʼ��ͨѶ¼
void address_book_add(address_book *);//�����ϵ��
void address_book_show(const address_book *);//��ʾ������ϵ����Ϣ 
void address_book_del_all(address_book *);//���������ϵ��
void address_book_del(address_book *);//	ɾ��ָ����ϵ����Ϣ 
void address_book_find(address_book *);//����ָ����ϵ����Ϣ,�������ӡ
void address_book_update(address_book *);//�޸�ָ����ϵ����Ϣ 
void sort_by_name(address_book *);//�����е���ϵ�˰���������