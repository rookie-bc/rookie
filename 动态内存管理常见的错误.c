#define _CRT_SECURE_NO_WARNINGS
//                                                       �����Ķ�̬�ڴ����




//1.�Կ�ָ��Ľ�����




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)malloc(40);          //�ö�̬�ڴ溯�����п��ٿռ�ʱһ��Ҫ���ж�p�ĺϷ���
//
//
//    //       if(p!=NULL)        һ��Ҫ�Ƚ����ж�   
//
//
//
//    int i;
//    for (i = 0; i < 10; i++)
//    {
//        *(p + i) = i;                      //  ������ж�ֱ�Ӹ�ֵ   ��malloc��������ʧ��ʱ  p���ŵľ��ǿ�ָ�� 
//                                           //     ���Կ�ָ����и�ֵʱ�ͻ���ɷǷ�����    
//                                                  
//    }
//    free(p);
//    p = NULL;
//}




//2.�Զ�̬���ٵ��ڴ��Խ�����




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)malloc(5 * sizeof(int));       //  ������5�����εĿռ�
//    if (p == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        int i; 
//        for (i = 0; i < 10; i++)               //     ֻ�ܷ���5������ȴ������10��     Խ����ʶ�̬�ڴ�   �ᵼ��ϵͳ����     
//        {
//            *(p + i) = i; 
//        }
//    }
//    free(p);
//    p = NULL;
//    return 0;
//}




//3.�ԷǶ�̬�ڴ�����ͷ�




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int a;
//    int* p = &a;
//    *p = 20;
//
//    free(p);              //p�����ڶ����Ķ�̬�ڴ�   ȴ�����ͷ�   �����
//    p = NULL;
//
//    return 0;
//}



//4.ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����





//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int i;
//		for (i = 0; i < 10; i++)
//		{
//			*p++ = i;           //�Ƚ��н����ý�p���ֵ�ĵ�   �ٽ�p��ֵ+1   ��ʱp�ĵ�ַ�Ѿ������˱仯
//		}
//	}
//	          
//	free(p);                 //  ��ʱ�ͷ�p�Ѿ�����ԭ��λ�õ�p   �ͷ��˱���û�п��ٵĶ�̬�ڴ�    �����
//
//	                             //ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����       ���Ǵ����
//	p = NULL;
//
//	return 0;
//}




//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�





//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//���ٶ�̬�ڴ�
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//ʹ�ö�̬�ڴ�
//
//	//�ͷŶ�̬�ڴ�
//	free(p);
//	//�ٴ��ͷ�ͬһ�鶯̬�ڴ�����
//	free(p);                   //��ܵķ�����free��ռ��ʱ��ָ����Ϊ��ָ��
//	                          //��free��ָ���൱��û�н��в���
//
//
//	return 0;
//}



//6.��̬�����ڴ������ͷţ��ڴ�й©��
 
 
 
 
 
 
//#include <stdio.h>
//#include <stdlib.h>     //malloc
//#include <Windows.h>    //Sleep
//void test()
//{
//	int* p = (int*)malloc(40);
//	if (p != NULL)
//	{
//		*p = 20;                  
//	}                              //�������������û���ͷŵ���̬�ڴ�   ���Իᷢ���ڴ�й¶   ���������Զ��庯������ʱ��  
//	                                 //���Ե�������֮��û�˻�ǵÿ��ٵĿռ�������  ��������������ͷŶ��ͷŲ�����
//	                             //�������������������ͷ�   ���߽���ַ����  �������ͷ�
//}
//int main()
//{
//	//while (1)                                //һֱѭ��
//	//{
//	//	malloc(1);                          //һֱ���ٿռ�  �����л���   �ᷢ���ڴ�й¶        �ڴ治�ϵر�����   �ǳ�����  
//	//	                                       //������¸�������  ʹ���궯̬�ڴ��  һ��Ҫ�ǵ��ͷŵ�
//	//	Sleep(1000);     //��λ�Ǻ���
//	//}
//	test();
//	while (1);
//	return 0;
//}