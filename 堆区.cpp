//�ɳ���Ա������ͷţ�������Ա���ͷţ�����ϵͳ�Լ��ͷ�
#include <iostream>
using namespace std;
int* func()
{
	//����new�ؼ����ڶ������ٿռ�
	int* p = new int(10);
	cout << p << endl;
	return p;
}
int main()
{
	int a = 10;
	int* p = &a;
	int* d = func();
	cout << d << endl;
	cout << p << endl;

	cout << *d << endl;
	cout << *d << endl;
	free(d);
	cout << *d << endl;
	return 0;
}