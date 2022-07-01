//由程序员分配和释放，若程序员不释放，则由系统自己释放
#include <iostream>
using namespace std;
int* func()
{
	//利用new关键字在堆区开辟空间
	int* p = new int(10);
	cout << p << endl;
	return p;
}
int main()
{
	int a = 10;
	int* p = &a;
	int* d = func();
	cout << d << endl;
	cout << p << endl;

	cout << *d << endl;
	cout << *d << endl;
	free(d);
	cout << *d << endl;
	return 0;
}