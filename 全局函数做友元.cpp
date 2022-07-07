//友元  -- 在程序里有些  私有属性  也想让类外特殊的一些函数或者类进行访问，就需要用到友元
//友元的目的  --  让一个函数或者类，访问另一个类中的私有成员
//友元关键字 friend


#include <iostream>
using namespace std;

class Building
{
	//goodGay 全局函数是Building类的一个友元，可以访问类中的私有成员
	friend void goodGay(Building* building);

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
void goodGay(Building *building)
{
	cout << "好基友全局函数  正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友全局函数  正在访问：" << building->m_BedRoom << endl;
}
void test1()
{
	Building building;
	goodGay(&building);
}
int main()
{
	test1();
	return 0;
}