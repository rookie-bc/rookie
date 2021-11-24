                        //void qsort(void* base, size_t num, size_t width,int (*compar)(const void* e1, const void* e2));
#include <stdio.h>
#include <string.h>
struct stu
{
	char name[20];
	int age;
};
void swap(char* buf1,char* buf2,int width)            //��������   ��
{
	int i;
	for (i = 0; i < width; i++)
	{
		int tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
// ʵ��bubble_sort�ĳ���Ա   ��֪��   �û�  ��Ҫ���������
//�ǳ���ԱҲ��֪�����Ƚϵ�����Ԫ�ص�����
void bubble_sort(void* base,int sz,int width,int (*cmp)(const void* e1,const void* e2))      //
                                               //cmp��һ������ָ��   ָ��ĺ�����������������������const void*  ����������int
{
	int i, j;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if ((*cmp)((char*)base+j*width,(char*)base+(j+1)*width) >0)        // ��*cmp���ҵ�����ָ������Ӧ�ĺ���  ����������������ȥ
				     //base��������Ԫ�ص�ַ  ���ڲ�֪�������д�ŵ��Ǻ������͵�Ԫ��
				//�Ƚ������ַת��Ϊ  char*����  ��һ��ֻ�ܶ�ȡһ���ֽ�   +   j*width��˼������ ������width���   widthָ����Ԫ����ռ���ֽ�
				//

			{
				//����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);

				//����ȥ�Ĳ���������Ҫ������Ԫ�صĵ�ַ   �����ֽ���   ��Ϊ�����ַһ��ֻ�ܷ���1���ֽ�   ��֪�����ݵ����ͣ�ֻ�ܽ�Ԫ�ش�С����ȥ
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)         //���������ĵ�ַ����
{
	return *((int*)e1) - *((int*)e2);           //Ŀǰe1��Ӧ����������ĳһ��Ԫ�صĵ�ַ  ������char*  
	//��e1��e2ǿ������ת��Ϊ  int*  ����   �ٽ����ò���   �����

	//Ҫ����С�ڷ���<0����   ���ڷ���0     ���ڷ���>0����
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);      //�Ƚ������ַ����Ĵ�С
}
void test1()
{
	int i;
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô����
	//��Ӧ��֪����αȽϴ����������е�Ԫ��
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s,sz,sizeof(s[0]),cmp_stu_by_name);
}
int main()
{
	test1();
	test2();
	return 0;
}