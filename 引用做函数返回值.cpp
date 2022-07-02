//注意事项:   1.不要返回局部变量的引用2.函数的调用可以作为左值
//函数内部的局部变量是在栈上开辟空间，当函数结束时，栈上的空间被释放，所以不能通过地址或者引用找到这块内存
#include <iostream>
using namespace std;

//不要返回局部变量的引用
int& test1()
{
	int a=10;
	return a;
}

//函数的调用可以作为左值
int& test2()
{
	static int a = 10;   //静态变量，存放在全局区，在程序结束后由系统释放
	return a;
}
int main()
{
	//int &b = test1();
	//cout << b << endl; //第一次正确是因为编译器做了一次保留
	//cout << b << endl; //第二次错误因为内存已经被释放	

	int& ref = test2();
	cout << ref << endl;
	cout << ref << endl;
	test2() = 100;                //如果函数的返回值是一个引用，那么这个函数可以作为左值
	cout << ref << endl;
	cout << ref << endl;
	return 0;
}