//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）




//联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）。




#include <stdio.h>
//union un
//{
//	char a;                  //在同一时刻 a和b是不能同时被修改的   因为  改a的时候  b也会被修改
//	int b;
//};
//int main()
//{
//	union un u;
//	printf("%d\n", sizeof(u));
//	printf("%p\n", &u);
//	printf("%p\n", &(u.a));
//	printf("%p\n", &(u.b));
//	return 0;
//}
 
 
 
 
 
                                             //  判断机器字节序   大端还是小端
//#include <stdio.h>
//int check()
//{
//	//int i=1;                                                                                 //方法一
//	//return *(char*)&i;   //   将  &i  强制类型转化为  char*   一次只访问一个字节   
//
//
//
//	union un                                                                                     //方法二
//	{
//		char a;                         //联合体   char  a 和 int  b  的第一个字节用的是同一块空间
//		int b;                           //将   int b  赋1   char a  如果是1   就是小端存储
//	}u;
//	u.b = 1;
//	return u.a;
//}
//int main()
//{
//	
//	int ret = check();
//	if (ret == 1)
//	{
//		printf("小端");
//	}
//	else
//		printf("大端");
//	return 0;
//}



//联合体大小的计算  
 



//联合的大小至少是最大成员的大小。
//当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。


#include <stdio.h>
union un
{
    int a;             //对齐数  4
    char arr[5];       //  char数组的  对齐数是   1   因为char数组  是一个一个的char类型构成的  成员大小就是1   
                       //   然后整个联合体的大小要对齐到   最大对齐数的整数倍
}u;
union Un2
{
    short c[7];  //总大小是14    每个成员大小是  2   对齐数是2
    int i;         //对齐数是4
                   //  要对齐到4的倍数   是16
}n;

int main()
{
    printf("%d\n", sizeof(u));
    printf("%d\n", sizeof(n));
    return 0;
}