//strtok  ʵ�ַָ��ַ���   ��ı��ַ���������   
//strtok  ���¼�ı��λ��   ���ҽ��ı��λ�ý��б��   ����ǵ�λ�ø�Ϊ\0
// ���ص��Ǳ��λ��ǰ�ַ�����Ԫ�صĵ�ַ
// ��һ�δ�����Ҫ�ָ���ַ����ĵ�ַ    ��һ�δ�  NULL   ��ȥ����
//�������ڱ�ǵ�ʱ��  ����һ����ָ��


//    char* strtok(char* str, const char* delimiters);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "abcd@qq.com";
	char* p = "@.";


	char buf[1024] = { 0 };
	strcpy(buf, arr);                  //��arr����һ�ݷŵ�buf��

	char* ret;

	for(ret = strtok(buf,p);ret!=NULL;ret = strtok(NULL,p))     //��һ�δ�����Ҫ�ָ���ַ����ĵ�ַ   �Ժ󴫵��ǿ�ָ��   �����ؿ�ָ��ʱ����
	{
		printf("%s\n",ret);
	}
	return 0;
}