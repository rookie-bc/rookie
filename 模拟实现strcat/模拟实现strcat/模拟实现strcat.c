//Դ�ַ��������� '\0' ������
//Ŀ��ռ�������㹻�Ĵ���������Դ�ַ��������ݡ�
//Ŀ��ռ������޸ġ�
//Դ�ַ����Ὣ\0Ҳ������ȥ
//��Ŀ��ռ��\0��ʼ��������
//strcat���������Լ�
//#include <stdio.h>
//int main()
//{
//	char arr1[40] = "hello\0xxxxxxxx";        
//	char arr2[] = "world" ;
//	strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}


//ʵ��my_strcat

#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);       
	assert(src);                //���ֶ�����        Ϊ�治ִ��  ��Ϊ�پ��ж�
	char* ret = dest;
	//1.�ҵ�dest��\0
	while (*dest != '\0')
	{
		dest++;
	}
	//2.��׷�ӣ�����
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
