#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define NAME_MAX 11
#define SEX_MAX 5
#define TEL_MAX 12
#define ADDR_MAX 21
#define DEFAULT_SIZE 3

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

typedef struct person_info
{
	int number;//为每个联系人分配一个编号
	char name[NAME_MAX];
	char sex[SEX_MAX];
	short age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}person_info;

typedef struct address_book
{
	person_info *data;
	int count;//记录联系人个数
	int capacity;//记录容量
}address_book;

void address_book_init(address_book *);//初始化通讯录
void address_book_add(address_book *);//添加联系人
void address_book_show(const address_book *);//显示所有联系人信息 
void address_book_del_all(address_book *);//清空所有联系人
void address_book_del(address_book *);//	删除指定联系人信息 
void address_book_find(address_book *);//查找指定联系人信息,并将其打印
void address_book_update(address_book *);//修改指定联系人信息 
void sort_by_name(address_book *);//将所有的联系人按名字排序
void save_address_book(address_book *);//将通讯录的内容存入文件中