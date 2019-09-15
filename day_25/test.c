#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int len = 0;
	char input[1000] = {0};
	char begin[] = "ErrorHandler Begin";
	char end[] = "ErrorHandler End";
	FILE *pf = fopen("test.txt", "r");
	while (fgets(input, sizeof(input), pf))
	{
		len = strlen(input);
		if (input[len-1] == '\n')
		{
			input[len-1] = '\0'; 			
		}
		if (strcmp(input, begin) == 0)
		{
			while (1)
			{
				memset(input, 0, sizeof(input));
				fgets(input, sizeof(input), pf);
				len = strlen(input);
				if (input[len-1] == '\n')
				{
					input[len-1] = '\0'; 			
				}
				if (strcmp(input, end) == 0)
				{
					memset(input, 0, sizeof(input));
					break;
				}
				puts(input);
			}
		}
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_LINE 1024
//int main()
//{
// char buf[MAX_LINE];  /*缓冲区*/
// FILE *fp;            /*文件指针*/
// int len;             /*行字符个数*/
// if((fp = fopen("test.txt","r")) == NULL)
// {
// perror("fail to read");
// exit (1) ;
// }
// while(fgets(buf,MAX_LINE,fp) != NULL)
// {
// len = strlen(buf);
// buf[len-1] = '\0';  /*去掉换行符*/
// printf("%s %d \n",buf,len - 1);
// }
//  return 0;
//}