//memcpy  �ڴ��������
//��  ��������  �� ���� ����
//void * memcpy ( void * destination, const void * source, size_t num );
//dest  ָ��Ҫ�������ݵ�Ŀ�������ָ�룬����ǿ��ת��Ϊvoid*���͵�ָ��
//src   ָ��Ҫ���Ƶ�����Դ��ָ�룬����ת��Ϊconst void*���͵�ָ��
//num   Ҫ���Ƶ��ֽ���



//#include <stdio.h>
//#include <string.h>
//
//struct stu
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//
//
//	struct stu arr3[] = { { "zhangsan",20 } ,{"lisi",30} };
//	struct stu arr4[4] = { 0 };
//
//	memcpy(arr2, arr1,sizeof(arr1));
//	memcpy(arr4, arr3, sizeof(arr3));          //���Կ����������͵�����
//	
//}



#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}

struct stu
{
	char name[20];
	int age;
};
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };


	struct stu arr3[] = { { "zhangsan",20 } ,{"lisi",30} };
	struct stu arr4[4] = { 0 };

	my_memcpy(arr2, arr1, sizeof(arr1));
	my_memcpy(arr4, arr3, sizeof(arr3));          //���Կ����������͵�����

}