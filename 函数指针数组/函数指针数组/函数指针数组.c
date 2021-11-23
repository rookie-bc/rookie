                                          //函数指针数组   存放函数指针的数组   也就是存放函数地址的数组

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
//    int(*arr)[10];                               //整形指针数组
//    int(*p)(int, int) = Add;          //   函数指针
//
//    int(*parr[4])(int, int) = { Add,Sub,Mul,Div };         //函数指针数组   是一个数组   parr数组有4个元素
//                                                           //每个元素都是函数指针类型的
//                                                           //这个函数指针指向的函数有两个参数都为int   返回类型为int
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        printf("%d\n", (*parr[i])(2, 3));                //     parr是一个数组  parr[0]找到的是Add这个函数的地址
//    }
//    return 0;
//}






//
//char* my_strcpy(char* dest, const char* str)
//{
//    ;
//}
//char* (*pf)(char*, const char*) = my_strcpy;      //这是一个函数指针pf 能够指向my_strcpy这个函数
//char* (*pfArr[4])(char*, const char*);             //这是一个函数指针数组，能够存放4个my_strcpy的地址






                                                                //函数指针数组的应用     转移表
//   例子    （计算器）
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
//        printf("除数不能为0")
//    }*/
//    return a / b;
//}
//int main()
//{
//    int a, b;
//    int input;
//    int (*parr[5])(int, int) = { 0,add,sub,mul,div };          //创建一个函数指针数组  ，将函数放到一个数组里边
//    do
//    {
//        menu();
//        printf("请选择>");
//        scanf_s("%d", &input);
//        if (input >= 1 && input <= 4)
//        {
//            printf("请输入操作数>");
//            scanf_s("%d%d", &a, &b);
//            int ret = parr[input](a, b);
//
//            printf("%d\n", ret);
//        }
//        else if (input == 0)
//        {
//            printf("退出！");
//        }
//        else
//        {
//            printf("输入错误!");
//        }
//    } while (input);
//    return 0;
//}



//把一个函数的地址，传递给一个指针，在函数内部，通过这个指针去调用传过来的函数   ，被调用的函数被称为回调函数

//    通过传不同的函数地址  ，调用不同的函数   ，实现不同的功能，   被调用的函数就称为回调函数
//void calc(int (*pf)(int,int))           //用函数指针来接收函数的地址       //传的函数地址不同   即函数不同  所实现的功能就不同
//{
//    int a, b;
//    printf("请输入两个数！\n");
//    scanf_s("%d%d", &a, &b);
//    printf("%d\n", pf(a, b));
//}
//int main()
//{
//    int input;
//    do
//    {
//        menu();
//        printf("请选择>\n");
//        scanf_s("%d", &input);
//        switch (input)
//        {
//        case 1:
//            calc(add);     //将要调用的函数的地址传过去
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
//            printf("退出！\n");
//            break;
//        default:
//            printf("选择错误！\n");
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
//        printf("请选择>\n");
//        scanf_s("%d", &input);
//        switch (input)
//        {
//        case 1:
//            printf("请输入两个数！\n");                    //每次多一个功能就要写好多代码   代码太冗杂
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", add(a, b));
//            break;
//        case 2:
//            printf("请输入两个数！\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", sub(a, b));
//            break;
//        case 3:
//            printf("请输入两个数！\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n", mul(a, b));
//            break;
//        case 4:
//            printf("请输入两个数！\n");
//            scanf_s("%d%d", &a, &b);
//            printf("%d\n",div(a, b));
//            break;
//        case 0:
//            printf("退出！\n");
//            break;
//        default:
//            printf("选择错误！\n");
//            break;
//        }
//    } while (input);
//    return 0;
//}





//指向   函数指针数组    的指针
#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}
int main()
{
    int arr[10];
    int(*p)[10] = &arr;  // 数组指针  指向数组的指针     

    int (*p[4])(int, int);        //函数指针数组   4个元素 每个元素都是一个函数指针

    int (*(*pp)[4])(int, int) = &p;        // pp  是  指向  函数指针数组  的指针           本质是一个数组指针
                                   //指向的数组有4个元素          每个元素是一个函数指针
                                            
}