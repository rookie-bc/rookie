//ǳ����: �򵥵ĸ�ֵ��������                   ������������   �������ڴ��ظ��ͷ�   ��������ָ��ͬһ������ڴ�ռ�
// 
//���: �ڶ�����������ռ䣬���п�������


#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person   Ĭ�Ϲ��캯��" << endl;
	}
	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person   �вι��캯��" << endl;
	}
	//�Լ�дһ���������캯�����ǳ��������������
	Person(const Person& p)
	{
		cout << "Person   �������캯��" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;  //������Ĭ��ʵ�ֵľ������д���
		
		//�������
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//�������룬���������ٵ��������ͷŲ���
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person   ��������" << endl;
	}

	int m_Age;
	int* m_Height;
};
void test1()
{
	Person p1(18,160);                                                         //�ͷŵ�˳����  �Ƚ����  ��˼����p2�ȱ��ͷ�
	cout << "p1�������� :  " << p1.m_Age << "p1������ǣ�" << *p1.m_Height << endl;
		
	Person p2(p1);
	cout << "p2�������� :  " << p2.m_Age << "p2������ǣ�" << *p2.m_Height << endl;

}
int main() 
{
	test1();
	return 0;
}