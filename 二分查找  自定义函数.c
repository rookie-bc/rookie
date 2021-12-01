#include <stdio.h>	                                                                                          //��д������ô�ã���д������ôʵ��.
                 //�����arr��ʵ��һ��ָ�룬��ߴ�ŵ�������arr�ĵ�һ��Ԫ�صĵ�ַ
int binary_search(int arr[], int k, int sz)                                     //���յ��Ǵ������ĵ�һ��Ԫ�صĵ�ַ
{
	//     int sz = sizeof(arr) / sizeof(arr[0]);                           �����Զ��庯����ʱ�򣬲����ô˷����������Ԫ�ظ���
	int left = 0;
	int right = sz - 1;                                                    //  �����ڲ�  ��  ��������  ��Ԫ�ظ������󲻵���
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
	int sz = sizeof(arr) / sizeof(arr[0]);              //�������������Ԫ�ظ����ڴ��䵽�Զ��庯����
	int ret = binary_search(arr, k, sz);                         //���鴫��ȥ���Ƿ����еĵ�һ��Ԫ�صĵ�ַ
	if (ret == -1)
	{
		printf("�Ҳ���");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
		printf("�ҵ���,Ҫ�ҵ����ǣ�%d", arr[ret]);
	}
	return 0;
}