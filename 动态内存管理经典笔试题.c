#define _CRT_SECURE_NO_WARNINGS


//��Ŀһ



//#include <stdio.h>
//#include <stdlib.h>
//void GetMemory(char* p)                 //p����ʽ����   ��str��һ����ʱ����
//{
//	p = (char*)malloc(100);            //����100���ֽڵĿռ�  ��p
//}                                     //���Զ��庯������ʱ    p���ͷŵ�
//                                     //���ǿ��ٵĿռ䲢û�б��ͷ�   �����޷��ҵ�
//                                     //�����ڴ�й¶����
//void Test(void)                         
//{
//	char* str = NULL;                   
//	GetMemory(str);                     //��str��ֵ����ȥ
//	strcpy(str, "hello world");         //��ʱstr��ֵ��û�б���   ��ȻΪ��ָ��      ��һ���ַ���  ����һ����ָ�봦��������
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//����1
//#include <stdio.h>
//#include <stdlib.h>
//void GetMemory(char** p)             //�ö���ָ�����
//{
//	*p = (char*)malloc(100);         //�������ҵ�str    �������ٵĿռ�ĵ�ַ����str��
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);                    //����ַ��ȥ
//	strcpy(str, "hello world");         //��ʱstr���ֵ���ǿ��ٺõĿռ�ĵ�ַ     �ٽ��ַ���������ȥ
//	printf(str);
//  free(str);
//  str=NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//����2
//#include <stdio.h>
//#include <stdlib.h>
//char* GetMemory(char* p)            
//{
//	p = (char*)malloc(100);        
//	return p;                           //p��һ����ʽ����  ��ŵ��ǿ��ٺÿռ�ĵ�ַ   ���βη���
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);                       //��str���յľ���   p������    �����ٿռ�ĵ�ַ
//	strcpy(str, "hello world");         
//	printf(str);
//
//	free(str);                             //Ҫ�ǵ��ͷŶ�̬���ٵ��ڴ�
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//��Ŀ��  ����ջ�ռ�ĵ�ַ����


//#include <stdio.h>
//char* GetMemory(void)
//{
//	char p[] = "hello world";            //���Զ��庯���ﴴ����һ������  ��ջ��������һ��ռ�  �����Զ��庯���ͻᱻ����  
//	                                       
//	return p;                             //��Ȼ���ﷵ����������׵�ַ      ��������ռ��Ѿ�������
//	                                     //��ͨ�������ַ�ҵ����λ��ʱ�ͻ���ɷǷ�����
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}



//��Ŀ��

#include <stdio.h>
#include <stdlib.h>
void Test(void)
{
	char* str = (char*)malloc(100);           //����100���ֽڵĿռ�
	strcpy(str, "hello");                   //��hello������str��
	free(str);                             //��str�ͷŵ�          
	//str=NULL Ӧ�����ͷŵ���ʱ��Ϊ��ָ��
	if (str != NULL)                        //�ͷ�֮�󲢲��ǿ�ָ��
	{
		strcpy(str, "world");                 //�Ƿ����ʣ�str��ָ��Ŀռ��Ѿ�����ȥ��  ���ǻ�Ҫ���з���
		printf(str);
	}
}
int main()
{
	Test();
	return 0;
}