#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//¶Ñ
#include "heap.h"

int main()
{
	int ar[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
	int n = sizeof(ar) / sizeof(int);
	int i = 0;
	Heap hp;
	HeapInit(&hp, n);
	for(i = 0; i < n; ++i)
	{
		HeapInsert(&hp, ar[i]);
	}
	HeapShow(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapRemove(&hp);//É¾µôÍ·½Úµã
	HeapShow(&hp);
	HeapDestroy(&php);
	return 0;
}

#endif