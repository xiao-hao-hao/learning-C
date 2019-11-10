#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

int main()
{
	int ar[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	//int ar[] = { 0, 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };//”√”⁄InsertSort_2
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray(ar, 0, n-1);
	TestSort(ar, 3, n-1);
	PrintArray(ar, 0, n-1);
	//TestSort(ar, 1, n-1);
	TestSortEfficiency();
	return 0;
}