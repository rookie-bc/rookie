#define _CRT_SECURE_NO_WARNINGS

//                                                                            malloc      <stdlib,h>

//        void* malloc (size_t size);

                    //size指申请内存块的大小  单位是字节

//这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针
//如果开辟成功，则返回一个指向开辟好空间的指针。
//如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
//返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。
//如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。



//                                                                            free         <stdlib.h>


//         void free (void* ptr);


//free函数用来释放动态开辟的内存。
//如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
//如果参数 ptr 是NULL指针，则函数什么事都不做。

//#include <stdio.h>
//#include <stdlib.h>    // malloc
//#include <string.h>    // strerror
//#include <errno.h>     // errno
//int main()
//{
//	int i;
//	int* p = (int*)malloc(10*sizeof(int));          //向 堆区 内存申请了10个整形的内存   要将返回的值强制类型转换一下     
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));    //打印错误原因的一个方式
//	}
//	else
//	{
//		//正常使用空间
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	free(p);               //如果申请的空间不在使用的话     将那块空间释放掉
//	p = NULL;              //虽然p已经被释放  ，但是p还是有申请的空间的地址       所以释放掉以后及时将p置为空指针  防止p变成野指针
//	return 0;
//}




//                                                                         calloc


//         void* calloc (size_t num, size_t size);

                     //num指开辟元素的个数              size指开辟元素的大小单位是字节



//C语言还提供了一个函数叫 calloc ， calloc 函数也用来动态内存分配。           并且会把开辟的元素初始化为0
//函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
//与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)calloc(10, sizeof(int));              //会初始化开辟空间的内容
//    if (p == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    else
//    {
//        int i = 0;
//        for (i = 0; i < 10; i++)
//        {
//            printf("%d ", *(p + i));
//        }
//    }
//    free(p);             //释放空间
//    p = NULL;
//    return 0;
//}


//                                                             realloc


//调整动态开辟内存空间的大小


//           void* realloc (void* ptr, size_t size);
          
                   //ptr 是要调整的内存地址
                   //size 调整之后新大小



//realloc函数注意事项
//1.如果原先开辟的空间之后有足够的空间可以追加，则直接追加，返回原先的地址
//2.如果原先开辟的空间之后没有足够的空间可以追加，则新开辟一块空间，并且将原来空间已有的数据拷贝过去 同时释放旧的内存空间 返回新开辟空间的地址
//3.当realloc函数开辟失败时，会返回空指针，为防止原来指针的值被改变，所以需要用一个新的变量来接收realloc的返回值
//4.如果realloc的第一个参数传递的是空指针的时候  ，他的功能相当于malloc函数



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)malloc(20);
//    if (p == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    else
//    {
//        int i;
//        for (i = 0; i < 5; i++)
//        {
//            *(p + i) = i;
//        }
//    }
//    //当前是在使用malloc开辟的20个字节空间
//    //假设这里，20个字节不能满足我们的使用
//    //希望我们能有40个字节的空间
//    //这里就可以使用realloc来调整动态开辟的内存
//
//
//                                                        /*  p = realloc(p, 40);                 //不建议这么写  
//                                                        int i;                                  //当堆区p原本空间后面的空间足以延长时才可以这么写
//                                                                                                //返回的是旧的地址
//                                                        for (i = 5; i < 10; i++)                //如果后面的空间不够时他会重新开辟一块你需要的空间
//                                                        {                                       //并将你原来的值转移过去  返回新的空间的地址
//                                                            *(p + i) = i;
//                                                          }*/
//    int* ptr = (int*)realloc(p, 40);
//    if (ptr != NULL)                      //不等于空指针意味着开辟成功
//    {
//        p = ptr;                             //开辟成功后将新的指针赋给原来的指针
//        int i;
//        for (i = 5; i < 10; i++)
//        {
//            *(p + i) = i;
//        }
//        for (i = 0; i < 10; i++)
//        {
//            printf("%d ", *(p + i));
//        }
//    }
//    
//    free(p);                //只要开辟动态内存空间     当不用时就要释放掉
//    p = NULL;
//    
//    
//    //  int* s = (int*)realloc(NULL, 40);      //相当于malloc开辟了40个字节的空间
//
//
//
//    return 0;
//}





