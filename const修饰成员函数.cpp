//��Ա�������const���ǳ��������Ϊ������
//�������ڲ������޸ĳ�Ա����
//��Ա����������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

//��������ǰ��const���������Ϊ������
//������ֻ�ܵ��ó����� 


#include <iostream>
using namespace std;

//������
class Person
{
public:
	
	// ��������൱�ڰ�thisָ���Ϊ   const Person* const this  �Ȳ������޸�ֵҲ�������޸�ָ��    
	//�ڳ�Ա���������constʵ�������ε���thisָ���ָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const      //�������ڲ������޸ĳ�Ա����
	{
		this->m_B = 100;

		//this->m_a = 100;       //ʵ�ʴ�����   this->m_a=100  ��thisָ��ı��� ��һ��ָ�볣��  ָ���ָ�򲻿����޸�  
	}

	void func()
	{

	}

	int m_a;
	mutable int m_B;  //�����������ʹ�ڳ�������Ҳ��Ҫ�޸����ֵ   Ҫ�ӹؼ���  mutable
};
void test1()
{
	Person p;
	p.showPerson();
}

//������
void test2()
{
	const Person p;   //�ڶ���ǰ��const ��Ϊ������ 
	//p.m_a = 100;    // ����������Բ����Ա��޸�
	//p.m_B = 100;    //m_B�Ƚ����⣬��Ϊ�����ؼ��� mutable������
	//������ֻ�ܵ��ó�����
	p.showPerson();    //��ȷ   ��Ϊ  showPerson�ǳ�����
	//p.func();        //����    ������ֻ�ܵ��ó�����
}
int main()
{
	return 0;
}