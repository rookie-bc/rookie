//成员函数后加const我们称这个函数为常函数
//常函数内不可以修改成员属性
//成员属性在声明时加关键字mutable后，在常函数中依然可以修改

//声明对象前加const称这个对象为常对象
//常对象只能调用常函数 


#include <iostream>
using namespace std;

//常函数
class Person
{
public:
	
	// 下面代码相当于把this指针变为   const Person* const this  既不可以修改值也不可以修改指向    
	//在成员函数后面加const实际上修饰的是this指针的指向，让指针指向的值也不可以修改
	void showPerson() const      //常函数内不可以修改成员属性
	{
		this->m_B = 100;

		//this->m_a = 100;       //实际代码是   this->m_a=100  而this指针的本质 是一个指针常量  指针的指向不可以修改  
	}

	void func()
	{

	}

	int m_a;
	mutable int m_B;  //特殊变量，即使在常函数中也想要修改这个值   要加关键字  mutable
};
void test1()
{
	Person p;
	p.showPerson();
}

//常对象
void test2()
{
	const Person p;   //在对象前加const 变为常对象 
	//p.m_a = 100;    // 常对象的属性不可以被修改
	//p.m_B = 100;    //m_B比较特殊，因为他被关键字 mutable修饰了
	//常对象只能调用常函数
	p.showPerson();    //正确   因为  showPerson是常函数
	//p.func();        //错误    常对象只能调用常函数
}
int main()
{
	return 0;
}