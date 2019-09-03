#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//struct S5
//{
//	char c1;
//	int arr[2];
//	int i;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//	printf("%d\n", sizeof(struct S5));
//	return 0;
//}

//#include <stdio.h>
//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//#pragma pack(1)//设置默认对齐数为1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//int main()
//{
//	//输出的结果是什么？
//	printf("%d\n", sizeof(struct S1));//12
//	printf("%d\n", sizeof(struct S2));//6
//	return 0; 
//}

//#include <stdio.h>
//struct S {
//int data[1000];
//int num;
//};
//struct S s = {{1,2,3,4}, 1000};
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); //传结构体
//	print2(&s); //传地址
//	return 0;
//}
//#include <stdio.h>
//union Un 
//{ 
//	 int i; 
//	 char c; 
//}; 
//int main()
//{
//	union Un un; 
//	// 下面输出的结果是一样的吗？
//	printf("%d\n", &(un.i)); 
//	printf("%d\n", &(un.c)); 
//	//下面输出的结果是什么？
//	un.i = 0x11223344; 
//	un.c = 0x55; 
//	printf("%x\n", un.i);
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	//char *a = "hello123";
//	FILE *pf = fopen("test.txt", "w");
//	fprintf(pf, "%d", a);//二进制的形式写到文件中（每次写4个字节，一共写一次）
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	char a:3;
//	char b:4;
//	char c:5;
//	char d:4;
//};
//int main()
//{
//	struct S s = {0};
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE *pFILE;
//	pFILE = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFILE);
//	fseek(pFILE, -2L, SEEK_END);
//	fputs(" sam", pFILE);
//	fclose(pFILE);
//	pFILE = NULL;
//	return 0;
//}