//浅拷贝: 简单的赋值拷贝操作                   带来的问题是   堆区的内存重复释放   两个对象指向同一块堆区内存空间
// 
//深拷贝: 在堆区重新申请空间，进行拷贝操作


#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person   默认构造函数" << endl;
	}
	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person   有参构造函数" << endl;
	}
	//自己写一个拷贝构造函数解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "Person   拷贝构造函数" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;  //编译器默认实现的就是这行代码
		
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//析构代码，将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person   析构函数" << endl;
	}

	int m_Age;
	int* m_Height;
};
void test1()
{
	Person p1(18,160);                                                         //释放的顺序是  先进后出  意思就是p2先被释放
	cout << "p1的年龄是 :  " << p1.m_Age << "p1的身高是：" << *p1.m_Height << endl;
		
	Person p2(p1);
	cout << "p2的年龄是 :  " << p2.m_Age << "p2的身高是：" << *p2.m_Height << endl;

}
int main() 
{
	test1();
	return 0;
}