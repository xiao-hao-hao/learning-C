////冒泡函数
//#include <stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0, j = 0, tmp = 0;
//	for (i = 0; i < sz - 1; i++)  //确定排序趟数
//	{
//		int flag = 0;
//		for (j = 0; j < sz - i - 1; j++)  //确定比较次数
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				flag = 1;  //加入标记
//			}
//		}
//		if (flag == 0)  //如果没有交换元素，则已经有序
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[] = {3, 1, 7, 5, 8, 9, 0, 2, 4, 6};
//	//int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
