#include <iostream>
using namespace std;


class Building;
class GoodGay
{
public:
	GoodGay();         
	void visit();        //��visit�������Է���Building��˽�г�Ա
	void visit2();       //��visit2���������Է���Building��˽�г�Ա

	Building* m_building;
};
class Building
{
	//���߱�����GoodGay���µ�visit��Ա������Ϊ����������Ԫ�����Է���˽�г�Ա
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
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	m_building = new Building;
}

void GoodGay::visit()
{
	cout << "visit �������ڷ��� ��" << m_building->m_SittingRoom << endl;

	cout << "visit �������ڷ��� ��" << m_building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit2 �������ڷ��� ��" << m_building->m_SittingRoom << endl;

	//cout << "visit2 �������ڷ��� ��" << m_building->m_BedRoom << endl;
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