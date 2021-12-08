//  memmove������������� �ڷ����ڴ��ص�ʱ�����򿽱������û���ڴ��ص� �� �� memcpy ûʲô����.

//void * memmove ( void * destination, const void * source, size_t num )


//#include <stdio.h>
//int main()
//{
//	int i;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr + 2, arr, 20);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	if ((char*)dest - (char*)src)                //   dest > src
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	else
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	return ret;
}
int main()
{
	int i;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}