#define _CRT_SECURE_NO_WARNINGS 1

////1.5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
////A选手说：B第二，我第三； 
////B选手说：我第二，E第四； 
////C选手说：我第一，D第二； 
////D选手说：C最后，我第三； 
////E选手说：我第四，A第一； 
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; ++a)
//	{
//		for (b = 1; b <= 5; ++b)
//		{
//			for (c = 1; c <= 5; ++c)
//			{
//				for (d = 1; d <= 5; ++d)
//				{
//					for (e = 0; e <= 5; ++e)
//					{
//						if ((a * b * c * d * e == 120) &&
//							((3 == a) ^ (2 == b)) &&
//							((2 == b) ^ (4 == e)) &&
//							((1 == c) ^ (2 == d)) &&
//							((5 == c) ^ (3 == d)) &&
//							((4 == e) ^ (1 == a)))
//						{
//							printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

////2.日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
////嫌疑犯的一个。以下为4个嫌疑犯的供词。 
////A说：不是我。 
////B说：是C。 
////C说：是D。 
////D说：C在胡说 
////已知3个人说了真话，1个人说的是假话。 
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include <stdio.h>
//int main()
//{
//	char murder = 0;
//	for (murder = 'A'; murder <= 'D'; ++murder)
//	{
//		if (('A' != murder) + ('C' == murder) + ('D' == murder) + !('D' == murder) == 3)
//		{
//			printf("%c\n", murder);
//		}
//	}
//	return 0;
//}

////3.在屏幕上打印杨辉三角。 
////1 
////1 1 
////1 2 1 
////1 3 3 1
//#include <stdio.h>
//
//void print(int arr[20][20], int n)
//{
//	int a = 1, b = 1, i = 0, j = 0;
//	arr[1][1] = 1;
//	for (i = 2; i <= n; ++i)
//	{
//		arr[i][1] = 1;
//		for (j = 2; j < i; ++j)
//		{
//			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//		}
//		arr[i][i] = 1;
//	}
//	for (i = 1; i <= n; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%-4d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 10;//定义打印行数
//	int arr[20][20] = {0};
//	print(arr, n);
//	return 0;
//}