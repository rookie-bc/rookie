                                        //函数指针  --  指向函数的指针
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
//    printf("%p\n", &Add);           //自定义函数的地址
//    printf("%p\n", Add);       //&函数名   和   函数名 都是函数的地址
//
//    int (*p)(int, int) = Add;              //函数指针   （*p）说明是一个指针   （int，int）说明是指针指向的是函数  他的参数是int，int  
//                                       //前面的int表示返回类型是int  
//
//
//    printf("%d", (*p)(2, 3));              //  p这个函数指针存放的是Add的地址
//                                           //   （*p）找到这个函数  （2，3）是这个函数的实参  
//    return 0;
//}


//
//#include <stdio.h>
//void Print(char* str)
//{
//    printf("%s\n", str);                //%s  后边的东西必须是  字符串的地址
//}
//int main()
//{
//    void (*p)(char*) = Print;         //*p表示是指针  （char*）表示函数的参数类型是char*     void表示函数不需要返回
//    (*p)("abcd");
//}



//(*(  void (*)()  ) 0 )();          //首先是一个0      void（*）（）是一个函数指针类型       指向的是  不需要传参，不需要返回的函数
                                       //（void（*）（））0         将0进行强制类型转换   此时0存放的就是函数的地址
                                     //      *（void（*）（））0）   解引用找到该函数    最后的（）表示不需要传参



//  void (*signal(   int,    void(*)(int)   ))(int)                 一个函数
//        函数名  （ 整形，   函数指针类型）
//                      （ 参数 ）
//void (*                                   )(int)
//      返回类型

//signal 是一个函数声明
//signal的函数参数有两个  一个是int  另一个是  函数指针  ，该函数指针指向的函数的参数是int  返回类型是void
//signal 函数的返回类型也是一个函数指针 该函数指针指向的函数的参数是int  返回类型是void






////       void (*signal(int, void(*)(int)))(int)        简化
//void (*signal(int, void(*)(int)))(int);
//                                               //typedef  定义新的类型名
////typedef unsigned int unit;                  //格式为    typedef  旧的类型名  新的类型名;   
//
//typedef void(* pfun_t)(int);                  //将void（*）（int）这个类型名定义为  pfun_t  这个名字
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
    printf("%d\n", (*p)(2, 3));              //  p这个函数指针存放的是Add的地址
                                           //   （*p）找到这个函数  （2，3）是这个函数的实参  

    printf("%d\n", (p)(2, 3));             //不用写  *  也可以
    printf("%d\n", p(2, 3));
     
    return 0;
}