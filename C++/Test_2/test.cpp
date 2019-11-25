#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);//需要用this来区分两个name
		this->count = count;
		this->price = price;
	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return name;
	}
	int GetCount()
	{
		return count;
	}
	float GetPrice()
	{
		return price;
	}
	float GetTotalPrice()
	{
		return price * count;
	}
private:
	char name[10];
	int count;
	float price;
	float total_price;
};

int main()
{
	CGoods goods1;
	goods1.RegisterGoods("abc", 5, 2.1);
	return 0;
}
*/

class A1
{
public:
	void f1(){}
private:
	int _a;
};

class A2
{
public:
	void f2(){}
};

class A3
{};

int main()
{
	cout << sizeof(A1) << sizeof(A2) << sizeof(A3) << endl;
	return 0;
}