#define _CRT_SECURE_NO_WARNINGS
//                                                       常见的动态内存错误




//1.对空指针的解引用




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)malloc(40);          //用动态内存函数进行开辟空间时一定要先判断p的合法性
//
//
//    //       if(p!=NULL)        一定要先进行判断   
//
//
//
//    int i;
//    for (i = 0; i < 10; i++)
//    {
//        *(p + i) = i;                      //  如果不判断直接赋值   当malloc函数开辟失败时  p里存放的就是空指针 
//                                           //     而对空指针进行赋值时就会造成非法访问    
//                                                  
//    }
//    free(p);
//    p = NULL;
//}




//2.对动态开辟的内存的越界访问




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    int* p = (int*)malloc(5 * sizeof(int));       //  开辟了5个整形的空间
//    if (p == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        int i; 
//        for (i = 0; i < 10; i++)               //     只能访问5个但是却访问了10个     越界访问动态内存   会导致系统崩溃     
//        {
//            *(p + i) = i; 
//        }
//    }
//    free(p);
//    p = NULL;
//    return 0;
//}




//3.对非动态内存进行释放




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
//    free(p);              //p不属于堆区的动态内存   却将他释放   会出错
//    p = NULL;
//
//    return 0;
//}



//4.使用free释放一块动态开辟内存的一部分





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
//			*p++ = i;           //先进行解引用将p里的值改掉   再将p的值+1   此时p的地址已经发生了变化
//		}
//	}
//	          
//	free(p);                 //  此时释放p已经不是原来位置的p   释放了本来没有开辟的动态内存    会出错
//
//	                             //使用free释放一块动态开辟内存的一部分       这是错误的
//	p = NULL;
//
//	return 0;
//}




//5.对同一块动态内存的多次释放





//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//开辟动态内存
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//使用动态内存
//
//	//释放动态内存
//	free(p);
//	//再次释放同一块动态内存会出错
//	free(p);                   //规避的方法，free完空间后及时将指针置为空指针
//	                          //而free空指针相当于没有进行操作
//
//
//	return 0;
//}



//6.动态开辟内存忘记释放（内存泄漏）
 
 
 
 
 
 
//#include <stdio.h>
//#include <stdlib.h>     //malloc
//#include <Windows.h>    //Sleep
//void test()
//{
//	int* p = (int*)malloc(40);
//	if (p != NULL)
//	{
//		*p = 20;                  
//	}                              //这个函数结束后并没有释放掉动态内存   所以会发生内存泄露   而且由于自定义函数是临时的  
//	                                 //多以当调用完之后没人会记得开辟的空间在哪里  出了这个函数想释放都释放不掉了
//	                             //在里面用完了在里面释放   或者将地址返回  在外面释放
//}
//int main()
//{
//	//while (1)                                //一直循环
//	//{
//	//	malloc(1);                          //一直开辟空间  不进行回收   会发生内存泄露        内存不断地被消耗   非常可怕  
//	//	                                       //这个故事告诉我们  使用完动态内存后  一定要记得释放掉
//	//	Sleep(1000);     //单位是毫秒
//	//}
//	test();
//	while (1);
//	return 0;
//}