#include <iostream>
using namespace std;

//构造函数的分类和调用
//分类
//    按照参数分类     有参构造      和      无参构造（默认构造）
//    按照类型分类     普通构造      和      拷贝构造
class Person
{
	//构造函数
	//    1.无参构造

public:
	Person()
	{
		cout << "Person	 无参构造函数的调用" << endl;
	}
	//    2.有参构造
	Person(int a)
	{
		age = a;
		cout << "Person	 有参构造函数的调用" << endl;
	}
	//    3.拷贝构造
	Person( const Person& p)
	{
		//将传入的人的所有属性，拷贝到我的身上
		age = p.age;
		cout << "Person	 拷贝构造函数的调用" << endl;
	}


	~Person()
	{
		cout << "Person	 析构函数的调用" << endl;
	}

	int age;
};
//调用
void test01()
{
	//1.括号法
	//Person p1;          //默认构造函数调用
	//Person p2(10);      //有参构造函数
	//Person p3(p2);
	
	//注意事项1
	//调用默认构造函数的时候，不要加（）
	//因为下面这行代码，编译器会认为是一个函数的声明
	//Person p1();

	//cout << p2.age << endl;
	//cout << p3.age << endl;
	 

	//2.显示法
	//Person p1;
	//Person p2 = Person(10);   //有参构造
	//Person p3 = Person(p2);   //拷贝构造

	//Person(10);   //匿名对象   特点：当前 行 执行结束后，系统会立即回收掉匿名对象
	//cout << "aaa" << endl;

	//注意事项2
	//不要用拷贝构造函数初始化匿名对象  编译器会认为Person (p3) ===  Person p3;   相当于对象的声明
	//Person(p3);

	//3.隐式转换法
	Person p4 = 10;     //相当于Person p4 = Person(10);
	Person p5 = p4;
}
int main()
{
	test01();
	return 0;
}