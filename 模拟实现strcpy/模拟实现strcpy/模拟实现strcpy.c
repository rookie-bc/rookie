                                             //使用库函数        
//#include <stdio.h>
//int main()
//{
//	// strcpy   字符串拷贝库函数
//	char arr1[] = "############";
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);           //将arr2中的字符串拷贝到arr1中去   包括arr2末尾的\0
//	printf("%s\n", arr1);
//	return 0;
//}



																				                         		 //6分
#include <stdio.h>
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')                       //当不为\0时将src的值赋给dest
//	{
//		*dest = *src;
//		dest++;
//		src++;                                   //挺挫  可以优化
//	}
//	*dest = *src;                //将\0也赋给的dest
//}




//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;             //后置++  先赋值后++      即先将src里的值赋给dest  在++进行下一次赋值
//	}
//	*dest = *src;
//}




																												 //7分
//
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)                   //     当不为\0时进入循环执行空语句   当为\0时跳出循环   
//	{
//		;
//	}
//}




//void my_strcpy(char* dest, char* src)
//{
//	if (dest != NULL && src != NULL)              //当传参时传的是空指针时，不进行拷贝   ，不会造成程序的崩溃  但是也无法解决问题  只是规避了问题
//	{
//		while (*dest++ = *src++)                   //     当不为\0时进入循环执行空语句   当为\0时跳出循环   
//		{
//			;
//		}
//	}
//}





																												          //8分
//#include <assert.h>         //assert  的头文件
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);         //assert是断言的意思      括号里的表达式为真  什么事都不发生   如果为假会报错
//	assert(src != NULL);
//	while (*dest++ = *src++)                   //     当不为\0时进入循环执行空语句   当为\0时跳出循环   
//	{
//		;
//	}
//}





#include <assert.h>         //assert  的头文件
char* my_strcpy(char* dest, const char* src)          //const  修饰时  即使92行写反了，但是会报错  也就是被拷贝的src不能被改变
                                                //char*  时  这个函数有了返回值
{
	char* ret = dest;
	assert(dest != NULL);        
	assert(src != NULL);
	while (*dest++ = *src++)                 //把src指向的字符串拷贝到dest所指向的空间      包含\0字符
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "############";
	char arr2[] = "bit"; 
	printf("%s\n", my_strcpy(arr1, arr2));          //链式访问   一个函数的返回值作为另一个函数的参数
	return 0;
}



//#include <stdio.h>
//int main()
//{
//	const int a = 10;                   //const 修饰a  a的值原则上不能改变
//	//int* p = &a;                //但是把a的地址交给p   就可以通过p改变a的值  此时p是非法改变的
//	//*p = 20;
//	//const int* p = &a;
//	//*p = 20;                         //当const放在指针变量的  *  的左边时   修饰的是  （*p）   不能通过p来改变*p（a）的值
//
//
//	int* const p = &a;
//	*p = 20;
//	int b = 20;
//	p = &b;                               //当const 放在*的右边时     修饰的是   p    可以通过*p  来改变a的值   但是不能改变  p  的值
//
//	printf("%d", a);
//}