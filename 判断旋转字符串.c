//                     �ȽϷ���
//               �������

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reserve(char* left, char* right)       //������
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
//void left_move(char* arr1,int k)                    //��������       �㷨˼���� ��ǰ�벿������  ����벿������  �ٽ���������
//{
//	assert(arr1 != NULL);
//	int len = strlen(arr1);
//	assert(k <= len);
//	reserve(arr1, arr1 + k - 1);
//	reserve(arr1 + k, arr1 + len - 1);
//	reserve(arr1, arr1 + len - 1);
//}
//int is_left_move(char* arr1, char* arr2)        //�ж��Ƿ����
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	int i, j;
//	int len = strlen(arr1);
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);               //ÿ����һ�ξ��ж�һ��      ֱ������  �ж��Ƿ�������
//		if (strcmp(arr1, arr2) == 0)       
//		{
//			return 1;                     //��ȷ���1
//		}
//	}
//	return 0;                         //����ȷ���0
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);      //�ж��Ƿ�����ת�ַ���
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
	//1. str1��׷��һ��str1�ַ��� 
	// strcat          ���ܽ��Լ��ӵ��Լ�����          ����������  ��һ����Ҫ�������ַ���    �ڶ����Ǹ����ַ���  ���ڶ����ӵ���һ�����
	// 
	// strcat(str1,str1)  err  ����             
	// 
	// strncat         ���Խ��Լ��ӵ��Լ�����        ���strcat����һ������      ��Ҫ��ӵĸ���     ���ڶ����ַ�����ǰn���ַ��ӵ���һ�����
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)                  //��������ַ��������һ��������ת֮���
		                          //Ŀ���Ƿ�ֹstr2��str1���Ӵ���������ת���    ����    cdef
	{
		return 0;
	}
	strncat(str1, str1, len1);          //���������vs����ᱨ����ȫ       
	
	//2. ���ж�str2�Ƿ���str1׷�Ӻ���ַ�����һ���Ӵ�
	//  strstr   ���Ӵ�����
	char* ret = strstr(str1, str2);           //��str1���濴�ܲ����ҵ�str2�ַ���   ������ҵ���str1����str2��Ԫ�صĵ�ַ������   ���û�ҵ�����һ����ָ��
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
	int ret = is_left_move(arr1, arr2);      //�ж��Ƿ����
	if (ret == 1)
	{
		printf("Yes!\n");
	}
	else
		printf("No!\n");
	return 0;
}