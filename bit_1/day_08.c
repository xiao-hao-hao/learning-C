//#define _CRT_SECURE_NO_WARNINGS 1
//
////整形提升的例子
//#include <stdio.h>
//
//int main()
//{
//	char a = 0xb6;  //b=1011高位补1
//	short b = 0xb600;
//	int c = 0xb6000000;//16进制常数前面补的是0，不是符号位，
//	int i = -1;
//	if (a == 0xb6)
//	{
//		printf("a");
//	}
//	if (b == 0xb600)
//	{
//		printf("b");
//	}
//	if (c == 0xb6000000)
//	{
//		printf("c");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char c = 1;
//	int a = 0;
//	int b = 0;
//	char d = 0;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4
//	printf("%u\n", sizeof(!c));//4
//	printf("%u  %d\n", sizeof(d = a + b), d);
//	return 0;
//}

//#include <stdio.h>
////整形提升
//int main()
//{
//	//char  -128 -- 127(-128---10000000)
//	char a = 3;//a = 00000011
//	char b = 127;//b = 01111111
//	char c = a + b;//c=10000010
//	printf("%d\n", c);//打印11111111111111111111111110000010取反加1的值  -126
//	return 0;
//}