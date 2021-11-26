//#include <stdio.h>
//int main()
//{
//
//	            //二维数组的数组名表示首元素的地址         而二维数组的首元素是   第一个一维数组 即第一行的地址
//
//	//a[3][4]    这个数组     a是数组名  表示首元素地址     即第一行的地址
//	//                        a[0]是第一行的数组名      表示的是第一行的首元素的地址      即   第一行第一个元素的地址
//
//
//	                          //*（a+1)  ==   a[1]
//
//	//int a[3][4] = { {0}, {1,2,3,4} };
//	//printf("%d\n", *(a[1] + 2));              //结果是  3
//
//
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));					      //  48     3*4*4   3*4个元素  每个元素占4个字节
//	printf("%d\n", sizeof(a[0][0]));				  //  4      第一行第一个元素的大小
//	printf("%d\n", sizeof(a[0]));                     //  16     a[]  相当于  第一行  作为一维数组名     放在sizeof()里计算的是第一行的大小
//	printf("%d\n", sizeof(a[0] + 1));                 //  4      第一行第二个元素的地址的大小  a[0]是第一行的数组名是第一行第一个元素的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));			  //  4      第一行第二个元素的大小
//	printf("%d\n", sizeof(a + 1));					  //  4      第二行的地址               
//	printf("%d\n", sizeof(*(a + 1)));                 //  16     第二行的大小
//	printf("%d\n", sizeof(&a[0] + 1));                //  4      第二行的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));             //  16     第二行的大小
//	printf("%d\n", sizeof(*a));                       //  16     a是首元素地址  即第一行地址  *a是第一行
//	printf("%d\n", sizeof(a[5]));                     //  16     sizeof内部的表达式是不进行真实运算的  根据里边的类型计算他的大小
//} 
//







#include <stdio.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);                           //POINT
	printf("%s\n", *-- * ++cpp + 3);                   //ER
	printf("%s\n", *cpp[-2] + 3);                      //ST
	printf("%s\n", cpp[-1][-1] + 1);                   //EW
	return 0;
}
