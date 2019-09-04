#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int c;
//	FILE *fp = fopen("test.txt", "r");
//	if (!fp)
//	{
//		perror("File opening failed");//The perror function prints an error message to stderr
//		return EXIT_FAILURE;
//	}
//	//fgetc  当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//	while ((c = fgetc(fp)) != EOF)
//	{
//		putchar(c);
//	}
//	//判断是什么原因结束的
//	if (ferror(fp))
//	{
//		puts("I/O error when reading");
//	}
//	else if (feof(fp))
//	{
//		//If no error has occurred on stream, ferror returns 0
//		//Otherwise, it returns a nonzero value
//		puts("End of file reached successfully");
//	}
//	fclose(fp);
//	return 0;
//}


//#include <stdio.h>
//enum{SIZE = 5};
//int main()
//{
//	double a[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
//	double b = 0.0;
//	size_t ret_code = 0;
//	FILE *fp = fopen("test.bin", "wb");
//	fwrite(a, sizeof(*a), SIZE, fp);//写double的数组
//	fclose(fp);
//	fp = fopen("test.bin", "rb");
//	//读double的数组
//	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
//	{
//		printf("%lf\n", b);
//	}
//	if (feof(fp))
//	{
//		printf("Error reading test.bin: unexpected end of file\n");
//	}
//	else if (ferror(fp))
//	{
//		perror("Error reading test.bin");
//	}
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	FILE* fp;
//	int count = 0;
//	if ((fp = fopen("test2.txt", "r")) == NULL) {
//		printf("error\n");
//		system("pause");
//		return 0;
//	}
//	while (!feof(fp)) {
//		fgetc(fp);
//		printf("%d\t", ++count);
//	}
//	system("pause");
//	return 0;
//}

#include <stdio.h>
int main()
{
	char str[512] = {0};
	sscanf("123456abcdedfBCDEF", "%[^A-Z]", str);
	printf("str=%s\n", str);
	return 0;
}