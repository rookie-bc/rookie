//位段必须是相同类型    
//位段后面跟个冒号和一个数字
//位段的位指的是二进制位

//位段可以节省空间

//1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
//2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
//3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段

//1. int 位段被当成有符号数还是无符号数是不确定的。
//2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机
//器会出问题。
//3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
//4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是
//舍弃剩余的位还是利用，这是不确定的。

//在当前vs编译器下   位段成员是从右向左分配     并且剩下的不足以存放成员的的比特位被舍弃

#include <stdio.h>
struct A
{
	int a : 2;            //后面的数字表示a占几个比特位    比如a占2个   b占5个  c占10个   d占30个
	int b : 5;
	int c : 10;                  
	int d : 30;             //位段后面的数字不能大于当前机器的比特位数   即32位平台只能  到  32
};                                //总共加起来 是  47 个比特位
                            //但是vs下位段的大小并不是6个字节  
                         //   他先开辟一个int类型的字节数即4个字节   从右往左将  成员的比特位进行分配   
                      //当剩余的比特位  不足以  放下成员的  比特位时   会开辟另一个int类型的字节数  又开辟4个字节  直到存完
int main()
{
	struct A a;
	printf("%d", sizeof(a));
	return 0;
}