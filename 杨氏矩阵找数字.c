                    //有一个数字矩阵 从左到右递增，从上到下递增       ---杨氏矩阵
                    //编写一个程序在这个矩阵中找到某个数字           
                    //要求   时间复杂度  小于  O（N）



                                                              //这个代码  不能返回下标
// #include <stdio.h>
//int findnum(int arr[3][3], int k, int row, int col)            //
//{
//    int x = 0;                              
//    int y = col - 1;                        //     x   ,   y  代表右上角的元素
//    while (x <= row-1 && y >= 0)            //当x<行数   y>0  时循环继续
//    {
//        if (arr[x][y] > k)                 //    当右上角元素  >   要找的元素   右边一列都不用找了 
//        {    
//            y--;                      //所以右边一列消失掉
//        }
//        else if (arr[x][y] < k)              //  当  右上角元素   <   要找的元素      上边一行不用找了
//        {
//            x++;                              //跳到下一行
//        }
//        else                           //  如果相等  返回 1
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
//        printf("找到了!\n");
//    }
//    else
//        printf("找不到！\n");
//    return 0;
//}





#include <stdio.h>

int findnum(int arr[3][3], int k, int* row, int* col)
{
    int x = 0;                              
    int y = *col - 1;                        //     x   ,   y  代表右上角的元素
    while (x <= *row - 1 && y >= 0)            //当x<行数   y>0  时循环继续
    {
        if (arr[x][y] > k)                 //    当右上角元素  >   要找的元素   右边一列都不用找了 
        {
            y--;                      //所以右边一列消失掉
        }
        else if (arr[x][y] < k)              //  当  右上角元素   <   要找的元素      上边一行不用找了
        {
            x++;                              //跳到下一行
        }
        else                           //  如果相等  返回 1
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
    //返回型参数
    int ret = findnum(arr, k, &x, &y);
    if (ret == 1)
    {
        printf("找到了!\n下标是%d %d\n", x, y);
    }
    else
        printf("找不到！\n");
    return 0;
}