//�����ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
//����Ȩ��: 1.����Ȩ�� ��public��    :   ��Ա   ���ڿ��Է���   ������Է���
//          2.����Ȩ��  (protected)  :   ��Ա   ���ڿ��Է���   ���ⲻ���Է���   �ӿ��Լ̳и���
//          3.˽��Ȩ��  (private)    :   ��Ա   ���ڿ��Է���   ���ⲻ���Է���   �Ӳ����Լ̳и���

//class��struct������ :  classĬ����private Ȩ��   ��structĬ����public Ȩ��



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
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}

};

int main()
{
	Person p1;
	p1.m_Name = "Lisa";
	//p1.m_Car = "audio";   //����Ȩ�������ⲻ���Է���
	return 0;
}


