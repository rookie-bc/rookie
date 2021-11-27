//
//
//int a = 10;
//char b = 'w';
//void* p = &a;              //void*  ����˼�������͵�ָ��   ���Խ����κ����͵ĵ�ַ
//*p = 0;                             void*���͵�ָ���ǲ��ܽ����ò�����     ��Ϊ��֪��Ҫ���ʼ����ֽ�
// p++;                               void*���͵�ָ��Ҳ���ܽ��мӼ������Ĳ���
//p = &b;




#include <stdio.h>
#include <string.h>       //strcmp
#include <stdlib.h>      //qsort         
void bubble_sort(int arr[], int sz)                  //ð������
{
	int i, j,tmp;
	int flag;
	for (i = 0; i < sz-1; i++)
	{
		flag = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

struct stu
{
	char name[20];                          //�ṹ�����   
	int age;
};



//qsort������ô��
  
//void qsort(void* base, size_t num, size_t width,int (*compar)(const void* e1, const void* e2));
//baseָ����      ָ��Ҫ���������ĵ�һ������ĵ�ַ���ö�����ת��Ϊvoid*��
//numָ����       Ҫ����Ԫ�صĸ���
//widthָ����     Ҫ����Ԫ����ռ�ֽ���   ����������
//comparָ����    Ҫ�����Ԫ�ص�  �ȽϷ�ʽ     
//���ĸ�������    ����ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ-�������ʹ�����Լ�ʵ��
//                ����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ






int cmp_int(const void* e1,const void* e2)                                    //�������������  �ȽϷ�ʽ
{
	//    *e1 *e2      ����void*���͵�ָ�벻�ܽ�����  ����Ҫǿ������ת��
	return *(int*)e1 - *(int*)e2;          //��e1��e2ǿ������ת��Ϊ  int*  ����   �ٽ����ò���   �����
	                                     
	                                                 //Ҫ����С�ڷ���<0����   ���ڷ���0     ���ڷ���>0����
}


int cmp_float(const void* e1, const void* e2)                               //���ڸ���������   ����   �ıȽϷ�ʽ  
{
	return *(float*)e1 - *(float*)e2;                    //ǿ������ת��Ϊ float*����  ���н����ú�  �����
} 



int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����ıȽϲ���ֱ����>,<���Ƚ�  Ӧ����strcmp����
	return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
}



void test1()                                           //��qsort ��������������
{
	int i;
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);                //qsort�ڲ����ÿ�������  ���������� ���ݽ�������
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test2()                                     //��ͨ��ð������
{
	int i;
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);        
	bubble_sort(arr, sz);                                   //   ֻ�������ε�����
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test3()
{
	int i, sz;
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	for (i = 0; i < sz; i++)
	{
		printf("%.1f ", f[i]);
	}
	printf("\n");
}

void test4()
{

	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };   
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}

int main()
{
	test1();
	test2();
	test3();
	test4();  
	return 0;
}