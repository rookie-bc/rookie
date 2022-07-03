//设计类时，可以把属性和行为放在不同的权限下，加以控制
//三种权限: 1.公共权限 （public）    :   成员   类内可以访问   类外可以访问
//          2.保护权限  (protected)  :   成员   类内可以访问   类外不可以访问   子可以继承父类
//          3.私有权限  (private)    :   成员   类内可以访问   类外不可以访问   子不可以继承父类

//class和struct的区别 :  class默认是private 权限   而struct默认是public 权限



#include <iostream>
using namespace std;

class Person
{
public:
	string m_Name;

protected:
	string m_Car;

private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}

};

int main()
{
	Person p1;
	p1.m_Name = "Lisa";
	//p1.m_Car = "audio";   //保护权限在类外不可以访问
	return 0;
}


