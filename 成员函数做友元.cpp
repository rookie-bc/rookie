#include <iostream>
using namespace std;


class Building;
class GoodGay
{
public:
	GoodGay();         
	void visit();        //让visit函数可以访问Building中私有成员
	void visit2();       //让visit2函数不可以访问Building中私有成员

	Building* m_building;
};
class Building
{
	//告诉编译器GoodGay类下的visit成员函数作为本函数的友元，可以访问私有成员
	friend void GoodGay::visit();
public:
	Building();

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	m_building = new Building;
}

void GoodGay::visit()
{
	cout << "visit 函数正在访问 ：" << m_building->m_SittingRoom << endl;

	cout << "visit 函数正在访问 ：" << m_building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit2 函数正在访问 ：" << m_building->m_SittingRoom << endl;

	//cout << "visit2 函数正在访问 ：" << m_building->m_BedRoom << endl;
}
void test1()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}
int main()
{
	test1();
	return 0;
}