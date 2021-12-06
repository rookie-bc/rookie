//strtok  实现分割字符串   会改变字符串的内容   
//strtok  会记录改变的位置   并且将改变的位置进行标记   将标记的位置改为\0
// 返回的是标记位置前字符串首元素的地址
// 第一次传的是要分割的字符串的地址    下一次传  NULL   过去就行
//当不存在标记的时候  返回一个空指针


//    char* strtok(char* str, const char* delimiters);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "abcd@qq.com";
	char* p = "@.";


	char buf[1024] = { 0 };
	strcpy(buf, arr);                  //将arr拷贝一份放到buf里

	char* ret;

	for(ret = strtok(buf,p);ret!=NULL;ret = strtok(NULL,p))     //第一次传的是要分割的字符串的地址   以后传的是空指针   当返回空指针时结束
	{
		printf("%s\n",ret);
	}
	return 0;
}