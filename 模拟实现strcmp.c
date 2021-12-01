//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcd";
//	char* p2 = "ab";
//	int ret = strcmp(p1, p2);    //�Ƚ������ַ�����С�ĺ���    һ��һ�Ե��ַ����бȽ�  >0  �������� <0���ظ���  =0����0 
//	printf("%d", ret);
//	return 0;
//}


//���Ȳ����ַ�����   ֱ������\0Ϊֹ


#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);                        //�����ж�ָ����Ч��
	while (*str1 == *str2)            //������   �����Ƚ���һ��
	{
		if (*str1 == '\0')              
		{
			return 0;                   //������  ���Ҷ�����\0  ˵���Ƚ�����  ������ȫ���
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);               //������ֵ���
}
int main()
{
	char* p1 = "abcd";
	char* p2 = "qwer";
	int ret = my_strcmp(p1, p2);
	printf("%d", ret);
	return 0;
}