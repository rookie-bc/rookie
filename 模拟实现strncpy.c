//strncpy   字符串拷贝  这种带n的字符串函数可以选择拷贝的个数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[25] = "abcd";
	char arr2[] = {'h','l'};
	printf("%s\n",strncpy(arr1, arr2,4));        //  三个参数   将arr2拷贝到arr1里    拷贝4个字节  并且不会将\0拷贝进去
    printf("%s\n",strncpy(arr1, arr2,20));       //  如果 arr2里的字符数  小于 你指定要拷贝的字符数   会自动将多余的补成\0
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
