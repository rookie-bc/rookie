#define _CRT_SECURE_NO_WARNINGS


//题目一



//#include <stdio.h>
//#include <stdlib.h>
//void GetMemory(char* p)                 //p是形式参数   是str的一份临时拷贝
//{
//	p = (char*)malloc(100);            //开辟100个字节的空间  给p
//}                                     //当自定义函数结束时    p被释放掉
//                                     //但是开辟的空间并没有被释放   并且无法找到
//                                     //存在内存泄露问题
//void Test(void)                         
//{
//	char* str = NULL;                   
//	GetMemory(str);                     //将str的值传过去
//	strcpy(str, "hello world");         //此时str的值并没有被改   依然为空指针      将一个字符串  传到一个空指针处程序会崩溃
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//改正1
//#include <stdio.h>
//#include <stdlib.h>
//void GetMemory(char** p)             //用二级指针接收
//{
//	*p = (char*)malloc(100);         //解引用找到str    并将开辟的空间的地址返回str里
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);                    //传地址过去
//	strcpy(str, "hello world");         //此时str里的值就是开辟好的空间的地址     再将字符串拷贝进去
//	printf(str);
//  free(str);
//  str=NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//改正2
//#include <stdio.h>
//#include <stdlib.h>
//char* GetMemory(char* p)            
//{
//	p = (char*)malloc(100);        
//	return p;                           //p是一个形式参数  存放的是开辟好空间的地址   将形参返回
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);                       //用str接收的就是   p的内容    即开辟空间的地址
//	strcpy(str, "hello world");         
//	printf(str);
//
//	free(str);                             //要记得释放动态开辟的内存
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//题目二  返回栈空间的地址问题


//#include <stdio.h>
//char* GetMemory(void)
//{
//	char p[] = "hello world";            //在自定义函数里创建了一个数组  在栈区开辟了一块空间  出了自定义函数就会被销毁  
//	                                       
//	return p;                             //虽然这里返回了数组的首地址      但是这个空间已经被销毁
//	                                     //当通过这个地址找到这个位置时就会造成非法访问
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



//题目三

#include <stdio.h>
#include <stdlib.h>
void Test(void)
{
	char* str = (char*)malloc(100);           //开辟100个字节的空间
	strcpy(str, "hello");                   //将hello拷贝到str中
	free(str);                             //将str释放掉          
	//str=NULL 应该在释放掉后及时置为空指针
	if (str != NULL)                        //释放之后并不是空指针
	{
		strcpy(str, "world");                 //非法访问，str所指向的空间已经还回去了  但是还要进行访问
		printf(str);
	}
}
int main()
{
	Test();
	return 0;
}