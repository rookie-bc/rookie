                                          //����ָ������   ��ź���ָ�������   Ҳ���Ǵ�ź�����ַ������

//#include <stdio.h>
//int Add(int x, int y)
//{
//    return x + y;
//}
//int Sub(int x, int y)
//{
//    return x - y;
//}
//int Mul(int x, int y)
//{
//    return x * y;
//}
//int Div(int x, int y)
//{
//    return x / y;
//}
//int main()
//{
//    int(*arr)[10];                               //����ָ������
//    int(*p)(int, int) = Add;          //   ����ָ��
//
//    int(*parr[4])(int, int) = { Add,Sub,Mul,Div };         //����ָ������   ��һ������   parr������4��Ԫ��
//                                                           //ÿ��Ԫ�ض��Ǻ���ָ�����͵�
//                                                           //�������ָ��ָ��ĺ���������������Ϊint   ��������Ϊint
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        printf("%d\n", (*parr[i])(2, 3));                //     parr��һ������  parr[0]�ҵ�����Add��������ĵ�ַ
//    }
//    return 0;
//}






//
//char* my_strcpy(char* dest, const char* str)
//{
//    ;
//}
//char* (*pf)(char*, const char*) = my_strcpy;      //����һ������ָ��pf �ܹ�ָ��my_strcpy�������
//char* (*pfArr[4])(char*, const char*);             //����һ������ָ�����飬�ܹ����4��my_strcpy�ĵ�ַ






                                                                //����ָ�������Ӧ��     ת�Ʊ�
//   ����    ����������
//#include <stdio.h>
//#include <assert.h>
//void menu()
//{
//    printf("*********************\n");
//    printf("**  1.add   2.sub  **\n");
//    printf("**  3.mul   4.div  **\n");
//    printf("**      0.exit     **\n");
//    printf("*********************\n");
//}
//int add(int a, int b)
//{
//    return a + b;
//}
//int sub(int a, int b)
//{
//    return a - b;
//}
//int mul(int a, int b)
//{
//    return a * b;
//}
//int div(int a, int b)
//{
//    assert(b != 0);
//   /* if (b == 0)
//    {
//        printf("��������Ϊ0")
//    }*/
//    return a / b;
//}
//int main()
//{
//    int a, b;
//    int input;
//    int (*parr[5])(int, int) = { 0,add,sub,mul,div };          //����һ������ָ������  ���������ŵ�һ���������
//    do
//    {
//        menu();
//        printf("��ѡ��>");
//        scanf_s("%d", &input);
//        if (input >= 1 && input <= 4)
//        {
//            printf("�����������>");
//            scanf_s("%d%d", &a, &b);
//            int ret = parr[input](a, b);
//
//            printf("%d\n", ret);
//        }
//        else if (input == 0)
//        {
//            printf("�˳���");
//        }
//        else
//        {
//            printf("�������!");
//        }
//    } while (input);
//    return 0;
//}



//��һ�������ĵ�ַ�����ݸ�һ��ָ�룬�ں����ڲ���ͨ�����ָ��ȥ���ô������ĺ���   �������õĺ�������Ϊ�ص�����

//    ͨ������ͬ�ĺ�����ַ  �����ò�ͬ�ĺ���   ��ʵ�ֲ�ͬ�Ĺ��ܣ�   �����õĺ����ͳ�Ϊ�ص�����
//void calc(int (*pf)(int,int))           //�ú���ָ�������պ����ĵ�ַ       //���ĺ�����ַ��ͬ   ��������ͬ  ��ʵ�ֵĹ��ܾͲ�ͬ
//{
//    int a, b;
//    printf("��������������\n");
//    scanf_s("%d%d", &a, &b);
//    printf("%d\n", pf(a, b));
//}
//int main()
//{
//    int input;
//    do
//    {
//        menu();
//        printf("��ѡ��>\n");
//        scanf_s("%d", &input);
//        switch (input)
//        {
//        case 1:
//            calc(add);     //��Ҫ���õĺ����ĵ�ַ����ȥ
//            break;
//        case 2:
//            calc(sub);
//            break;
//        case 3:
//            calc(mul);
//            break;
//        case 4:
//            calc(div);
//            break;
//        case 0:
//            printf("�˳���\n");
//            break;
//        default:
//            printf("ѡ�����\n");
//            break;
//        }
//    } while (input);
//    return 0;
//}





//int main()
//{
//    int a, b;
//    int input;
//    do
//    {
//        menu();
//        printf("��ѡ��>\n");
//        scanf_s("%d", &input);
//        switch (input)
//        {
//        case 1:
//            printf("��������������\n");                    //ÿ�ζ�һ�����ܾ�Ҫд�ö����   ����̫����
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", add(a, b));
//            break;
//        case 2:
//            printf("��������������\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", sub(a, b));
//            break;
//        case 3:
//            printf("��������������\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", mul(a, b));
//            break;
//        case 4:
//            printf("��������������\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n",div(a, b));
//            break;
//        case 0:
//            printf("�˳���\n");
//            break;
//        default:
//            printf("ѡ�����\n");
//            break;
//        }
//    } while (input);
//    return 0;
//}





//ָ��   ����ָ������    ��ָ��
#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}
int main()
{
    int arr[10];
    int(*p)[10] = &arr;  // ����ָ��  ָ�������ָ��     

    int (*p[4])(int, int);        //����ָ������   4��Ԫ�� ÿ��Ԫ�ض���һ������ָ��

    int (*(*pp)[4])(int, int) = &p;        // pp  ��  ָ��  ����ָ������  ��ָ��           ������һ������ָ��
                                   //ָ���������4��Ԫ��          ÿ��Ԫ����һ������ָ��
                                            
}