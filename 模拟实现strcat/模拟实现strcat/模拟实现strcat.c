//源字符串必须以 '\0' 结束。
//目标空间必须有足够的大，能容纳下源字符串的内容。
//目标空间必须可修改。
//源字符串会将\0也拷贝过去
//以目标空间的\0开始进行连接
//strcat不能连接自己
//#include <stdio.h>
//int main()
//{
//	char arr1[40] = "hello\0xxxxxxxx";        
//	char arr2[] = "world" ;
//	strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}


//实现my_strcat

#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);       
	assert(src);                //两种都可以        为真不执行  ，为假就中断
	char* ret = dest;
	//1.找到dest的\0
	while (*dest != '\0')
	{
		dest++;
	}
	//2.（追加）连接
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[40] = "hello";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}
