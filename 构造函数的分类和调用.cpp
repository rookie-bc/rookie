#include <iostream>
using namespace std;

//���캯���ķ���͵���
//����
//    ���ղ�������     �вι���      ��      �޲ι��죨Ĭ�Ϲ��죩
//    �������ͷ���     ��ͨ����      ��      ��������
class Person
{
	//���캯��
	//    1.�޲ι���

public:
	Person()
	{
		cout << "Person	 �޲ι��캯���ĵ���" << endl;
	}
	//    2.�вι���
	Person(int a)
	{
		age = a;
		cout << "Person	 �вι��캯���ĵ���" << endl;
	}
	//    3.��������
	Person( const Person& p)
	{
		//��������˵��������ԣ��������ҵ�����
		age = p.age;
		cout << "Person	 �������캯���ĵ���" << endl;
	}


	~Person()
	{
		cout << "Person	 ���������ĵ���" << endl;
	}

	int age;
};
//����
void test01()
{
	//1.���ŷ�
	//Person p1;          //Ĭ�Ϲ��캯������
	//Person p2(10);      //�вι��캯��
	//Person p3(p2);
	
	//ע������1
	//����Ĭ�Ϲ��캯����ʱ�򣬲�Ҫ�ӣ���
	//��Ϊ�������д��룬����������Ϊ��һ������������
	//Person p1();

	//cout << p2.age << endl;
	//cout << p3.age << endl;
	 

	//2.��ʾ��
	//Person p1;
	//Person p2 = Person(10);   //�вι���
	//Person p3 = Person(p2);   //��������

	//Person(10);   //��������   �ص㣺��ǰ �� ִ�н�����ϵͳ���������յ���������
	//cout << "aaa" << endl;

	//ע������2
	//��Ҫ�ÿ������캯����ʼ����������  ����������ΪPerson (p3) ===  Person p3;   �൱�ڶ��������
	//Person(p3);

	//3.��ʽת����
	Person p4 = 10;     //�൱��Person p4 = Person(10);
	Person p5 = p4;
}
int main()
{
	test01();
	return 0;
}