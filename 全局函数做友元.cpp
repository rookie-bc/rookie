//��Ԫ  -- �ڳ�������Щ  ˽������  Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ
//��Ԫ��Ŀ��  --  ��һ�����������࣬������һ�����е�˽�г�Ա
//��Ԫ�ؼ��� friend


#include <iostream>
using namespace std;

class Building
{
	//goodGay ȫ�ֺ�����Building���һ����Ԫ�����Է������е�˽�г�Ա
	friend void goodGay(Building* building);

public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
void goodGay(Building *building)
{
	cout << "�û���ȫ�ֺ���  ���ڷ��ʣ�" << building->m_SittingRoom << endl;

	cout << "�û���ȫ�ֺ���  ���ڷ��ʣ�" << building->m_BedRoom << endl;
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