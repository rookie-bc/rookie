//                     比较繁琐
//               暴力求解

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reserve(char* left, char* right)       //逆序函数
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while(left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* arr1,int k)                    //左旋函数       算法思想是 将前半部分逆序  将后半部分逆序  再将整体逆序
//{
//	assert(arr1 != NULL);
//	int len = strlen(arr1);
//	assert(k <= len);
//	reserve(arr1, arr1 + k - 1);
//	reserve(arr1 + k, arr1 + len - 1);
//	reserve(arr1, arr1 + len - 1);
//}
//int is_left_move(char* arr1, char* arr2)        //判断是否相等
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	int i, j;
//	int len = strlen(arr1);
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);               //每左旋一次就判断一次      直到旋完  判断是否是所求
//		if (strcmp(arr1, arr2) == 0)       
//		{
//			return 1;                     //相等返回1
//		}
//	}
//	return 0;                         //不相等返回0
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);      //判断是否是旋转字符串
//	if (ret == 1)
//	{
//		printf("Yes!\n");
//	}
//	else
//		printf("No!\n");
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int is_left_move(char* str1, char* str2)
{
	//1. str1再追加一个str1字符串 
	// strcat          不能将自己加到自己后面          有两个参数  第一个是要增长的字符串    第二个是给的字符串  将第二个加到第一个后边
	// 
	// strcat(str1,str1)  err  错误             
	// 
	// strncat         可以将自己加到自己后面        相比strcat多了一个参数      即要添加的个数     将第二个字符串的前n个字符加到第一个后边
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)                  //如果两个字符串不相等一定不是旋转之后的
		                          //目的是防止str2是str1的子串但不是旋转后的    例如    cdef
	{
		return 0;
	}
	strncat(str1, str1, len1);          //这个函数在vs里面会报不安全       
	
	//2. 再判断str2是否是str1追加后的字符串的一个子串
	//  strstr   找子串函数
	char* ret = strstr(str1, str2);           //再str1里面看能不能找到str2字符串   如果能找到将str1里面str2首元素的地址返回来   如果没找到返回一个空指针
	if (ret == NULL)
	{
		return 0;
	}
	else
		return 1;
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);      //判断是否相等
	if (ret == 1)
	{
		printf("Yes!\n");
	}
	else
		printf("No!\n");
	return 0;
}