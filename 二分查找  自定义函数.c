#include <stdio.h>	                                                                                          //先写函数怎么用，再写函数怎么实现.
                 //这里的arr其实是一个指针，里边存放的是数组arr的第一个元素的地址
int binary_search(int arr[], int k, int sz)                                     //接收的是传过来的第一个元素的地址
{
	//     int sz = sizeof(arr) / sizeof(arr[0]);                           调用自定义函数的时候，不能用此方法求数组的元素个数
	int left = 0;
	int right = sz - 1;                                                    //  函数内部  求  参数部分  的元素个数是求不到的
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	if (left > right)
	{
		return -1;
	}
}
int main()
{
	int arr[] = {1, 2, 5, 6, 8, 9};
	//int k = 8;
	int k;
	scanf_s("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);              //在外边求好数组的元素个数在传输到自定义函数中
	int ret = binary_search(arr, k, sz);                         //数组传过去的是方框中的第一个元素的地址
	if (ret == -1)
	{
		printf("找不到");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
		printf("找到了,要找的数是：%d", arr[ret]);
	}
	return 0;
}