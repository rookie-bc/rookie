                                             //ʹ�ÿ⺯��        
//#include <stdio.h>
//int main()
//{
//	// strcpy   �ַ��������⺯��
//	char arr1[] = "############";
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);           //��arr2�е��ַ���������arr1��ȥ   ����arr2ĩβ��\0
//	printf("%s\n", arr1);
//	return 0;
//}



																				                         		 //6��
#include <stdio.h>
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')                       //����Ϊ\0ʱ��src��ֵ����dest
//	{
//		*dest = *src;
//		dest++;
//		src++;                                   //ͦ��  �����Ż�
//	}
//	*dest = *src;                //��\0Ҳ������dest
//}




//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;             //����++  �ȸ�ֵ��++      ���Ƚ�src���ֵ����dest  ��++������һ�θ�ֵ
//	}
//	*dest = *src;
//}




																												 //7��
//
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)                   //     ����Ϊ\0ʱ����ѭ��ִ�п����   ��Ϊ\0ʱ����ѭ��   
//	{
//		;
//	}
//}




//void my_strcpy(char* dest, char* src)
//{
//	if (dest != NULL && src != NULL)              //������ʱ�����ǿ�ָ��ʱ�������п���   ��������ɳ���ı���  ����Ҳ�޷��������  ֻ�ǹ��������
//	{
//		while (*dest++ = *src++)                   //     ����Ϊ\0ʱ����ѭ��ִ�п����   ��Ϊ\0ʱ����ѭ��   
//		{
//			;
//		}
//	}
//}





																												          //8��
//#include <assert.h>         //assert  ��ͷ�ļ�
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);         //assert�Ƕ��Ե���˼      ������ı��ʽΪ��  ʲô�¶�������   ���Ϊ�ٻᱨ��
//	assert(src != NULL);
//	while (*dest++ = *src++)                   //     ����Ϊ\0ʱ����ѭ��ִ�п����   ��Ϊ\0ʱ����ѭ��   
//	{
//		;
//	}
//}





#include <assert.h>         //assert  ��ͷ�ļ�
char* my_strcpy(char* dest, const char* src)          //const  ����ʱ  ��ʹ92��д���ˣ����ǻᱨ��  Ҳ���Ǳ�������src���ܱ��ı�
                                                //char*  ʱ  ����������˷���ֵ
{
	char* ret = dest;
	assert(dest != NULL);        
	assert(src != NULL);
	while (*dest++ = *src++)                 //��srcָ����ַ���������dest��ָ��Ŀռ�      ����\0�ַ�
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "############";
	char arr2[] = "bit"; 
	printf("%s\n", my_strcpy(arr1, arr2));          //��ʽ����   һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
	return 0;
}



//#include <stdio.h>
//int main()
//{
//	const int a = 10;                   //const ����a  a��ֵԭ���ϲ��ܸı�
//	//int* p = &a;                //���ǰ�a�ĵ�ַ����p   �Ϳ���ͨ��p�ı�a��ֵ  ��ʱp�ǷǷ��ı��
//	//*p = 20;
//	//const int* p = &a;
//	//*p = 20;                         //��const����ָ�������  *  �����ʱ   ���ε���  ��*p��   ����ͨ��p���ı�*p��a����ֵ
//
//
//	int* const p = &a;
//	*p = 20;
//	int b = 20;
//	p = &b;                               //��const ����*���ұ�ʱ     ���ε���   p    ����ͨ��*p  ���ı�a��ֵ   ���ǲ��ܸı�  p  ��ֵ
//
//	printf("%d", a);
//}