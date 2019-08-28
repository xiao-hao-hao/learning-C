#include <stdio.h>
#include <string.h>

#define NAME_MAX 11
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 21
#define CONTACT_NUM 1000

enum//将菜单定义为一个枚举类
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

void InitContacts(Contacts *);//初始化通讯录
void Add(Contacts *);//添加联系人
void Show(const Contacts *);//显示所有联系人信息 
void Empty(Contacts *);//清空所有联系人
void Del(Contacts *);//	删除指定联系人信息 
int Find(const Contacts *, char *);//查找联系人并返回该联系人的位置，找不到返回-1