                                        //����ָ��  --  ָ������ָ��
//#include <stdio.h>
//int Add(int x, int y)
//{
//    int z = 0;
//    z = x + y;
//    return z;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//    printf("%d\n", Add(a, b));
//    printf("%p\n", &Add);           //�Զ��庯���ĵ�ַ
//    printf("%p\n", Add);       //&������   ��   ������ ���Ǻ����ĵ�ַ
//
//    int (*p)(int, int) = Add;              //����ָ��   ��*p��˵����һ��ָ��   ��int��int��˵����ָ��ָ����Ǻ���  ���Ĳ�����int��int  
//                                       //ǰ���int��ʾ����������int  
//
//
//    printf("%d", (*p)(2, 3));              //  p�������ָ���ŵ���Add�ĵ�ַ
//                                           //   ��*p���ҵ��������  ��2��3�������������ʵ��  
//    return 0;
//}


//
//#include <stdio.h>
//void Print(char* str)
//{
//    printf("%s\n", str);                //%s  ��ߵĶ���������  �ַ����ĵ�ַ
//}
//int main()
//{
//    void (*p)(char*) = Print;         //*p��ʾ��ָ��  ��char*����ʾ�����Ĳ���������char*     void��ʾ��������Ҫ����
//    (*p)("abcd");
//}



//(*(  void (*)()  ) 0 )();          //������һ��0      void��*��������һ������ָ������       ָ�����  ����Ҫ���Σ�����Ҫ���صĺ���
                                       //��void��*��������0         ��0����ǿ������ת��   ��ʱ0��ŵľ��Ǻ����ĵ�ַ
                                     //      *��void��*��������0��   �������ҵ��ú���    ���ģ�����ʾ����Ҫ����



//  void (*signal(   int,    void(*)(int)   ))(int)                 һ������
//        ������  �� ���Σ�   ����ָ�����ͣ�
//                      �� ���� ��
//void (*                                   )(int)
//      ��������

//signal ��һ����������
//signal�ĺ�������������  һ����int  ��һ����  ����ָ��  ���ú���ָ��ָ��ĺ����Ĳ�����int  ����������void
//signal �����ķ�������Ҳ��һ������ָ�� �ú���ָ��ָ��ĺ����Ĳ�����int  ����������void






////       void (*signal(int, void(*)(int)))(int)        ��
//void (*signal(int, void(*)(int)))(int);
//                                               //typedef  �����µ�������
////typedef unsigned int unit;                  //��ʽΪ    typedef  �ɵ�������  �µ�������;   
//
//typedef void(* pfun_t)(int);                  //��void��*����int���������������Ϊ  pfun_t  �������
//pfun_t signal(int, pfun_t);
//




#include <stdio.h>
int Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}
int main()
{
    int a = 10;
    int b = 20;


    int (*p)(int, int) = Add;           
    printf("%d\n", (*p)(2, 3));              //  p�������ָ���ŵ���Add�ĵ�ַ
                                           //   ��*p���ҵ��������  ��2��3�������������ʵ��  

    printf("%d\n", (p)(2, 3));             //����д  *  Ҳ����
    printf("%d\n", p(2, 3));
     
    return 0;
}