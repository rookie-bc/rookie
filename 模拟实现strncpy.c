//strncpy   �ַ�������  ���ִ�n���ַ�����������ѡ�񿽱��ĸ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[25] = "abcd";
	char arr2[] = {'h','l'};
	printf("%s\n",strncpy(arr1, arr2,4));        //  ��������   ��arr2������arr1��    ����4���ֽ�  ���Ҳ��Ὣ\0������ȥ
    printf("%s\n",strncpy(arr1, arr2,20));       //  ��� arr2����ַ���  С�� ��ָ��Ҫ�������ַ���   ���Զ�������Ĳ���\0
	return 0;
}


//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//	while (num)
//	{
//		*dest++ = *src++;
//		num--;
//	}
//	return start;
//}
//int main()
//{
//	char arr1[10] = "abcdefg";
//	char arr2[] = "hello";
//	printf("%s",my_strncpy(arr1, arr2, 10));
//	return 0;
//}
