                    //��һ�����־��� �����ҵ��������ϵ��µ���       ---���Ͼ���
                    //��дһ������������������ҵ�ĳ������           
                    //Ҫ��   ʱ�临�Ӷ�  С��  O��N��



                                                              //�������  ���ܷ����±�
// #include <stdio.h>
//int findnum(int arr[3][3], int k, int row, int col)            //
//{
//    int x = 0;                              
//    int y = col - 1;                        //     x   ,   y  �������Ͻǵ�Ԫ��
//    while (x <= row-1 && y >= 0)            //��x<����   y>0  ʱѭ������
//    {
//        if (arr[x][y] > k)                 //    �����Ͻ�Ԫ��  >   Ҫ�ҵ�Ԫ��   �ұ�һ�ж��������� 
//        {    
//            y--;                      //�����ұ�һ����ʧ��
//        }
//        else if (arr[x][y] < k)              //  ��  ���Ͻ�Ԫ��   <   Ҫ�ҵ�Ԫ��      �ϱ�һ�в�������
//        {
//            x++;                              //������һ��
//        }
//        else                           //  ������  ���� 1
//            return 1;
//    }                                
//    return 0;
//}
//int main()
//{
//    int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//    int k;
//    scanf_s("%d", &k);
//    int ret = findnum(arr, k, 3, 3);
//    if (ret == 1)
//    {
//        printf("�ҵ���!\n");
//    }
//    else
//        printf("�Ҳ�����\n");
//    return 0;
//}





#include <stdio.h>

int findnum(int arr[3][3], int k, int* row, int* col)
{
    int x = 0;                              
    int y = *col - 1;                        //     x   ,   y  �������Ͻǵ�Ԫ��
    while (x <= *row - 1 && y >= 0)            //��x<����   y>0  ʱѭ������
    {
        if (arr[x][y] > k)                 //    �����Ͻ�Ԫ��  >   Ҫ�ҵ�Ԫ��   �ұ�һ�ж��������� 
        {
            y--;                      //�����ұ�һ����ʧ��
        }
        else if (arr[x][y] < k)              //  ��  ���Ͻ�Ԫ��   <   Ҫ�ҵ�Ԫ��      �ϱ�һ�в�������
        {
            x++;                              //������һ��
        }
        else                           //  ������  ���� 1
        {
            *row = x;
            *col = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int k;
    scanf_s("%d", &k);
    int x = 3;
    int y = 3;
    //�����Ͳ���
    int ret = findnum(arr, k, &x, &y);
    if (ret == 1)
    {
        printf("�ҵ���!\n�±���%d %d\n", x, y);
    }
    else
        printf("�Ҳ�����\n");
    return 0;
}