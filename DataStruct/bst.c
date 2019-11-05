#if 0

#define _CRT_SECURE_NO_WARNINGS 1

#include "bst.h"
int main()
{
	BSTree bst;
	int i = 0;
	int ar[] = {45, 10, 24, 53, 12, 38, 21, 90, 30};
	int n = sizeof(ar) / sizeof(ar[0]);
	BSTreeInit(&bst);

	for(i = 0; i < n; ++i)
	{
		Insert(&bst, ar[i]);
	}

	printf("Min = %d\n", Min(bst));
	printf("Max = %d\n", Max(bst));
	i = 0;
	Sort(bst, ar, &i);
	Remove(&bst, 45);
	BSTDestroy(&bst);
	return 0;
}

#endif