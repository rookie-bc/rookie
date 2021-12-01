//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcd";
//	char* p2 = "ab";
//	int ret = strcmp(p1, p2);    //比较两个字符串大小的函数    一对一对的字符进行比较  >0  返回正数 <0返回负数  =0返回0 
//	printf("%d", ret);
//	return 0;
//}


//长度不受字符限制   直到遇到\0为止


#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);                        //断言判断指针有效性
	while (*str1 == *str2)            //如果相等   继续比较下一对
	{
		if (*str1 == '\0')              
		{
			return 0;                   //如果相等  并且都等于\0  说明比较完了  并且完全相等
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);               //返回两值相减
}
int main()
{
	char* p1 = "abcd";
	char* p2 = "qwer";
	int ret = my_strcmp(p1, p2);
	printf("%d", ret);
	return 0;
}