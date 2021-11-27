//
//
//int a = 10;
//char b = 'w';
//void* p = &a;              //void*  的意思是无类型的指针   可以接收任何类型的地址
//*p = 0;                             void*类型的指针是不能解引用操作的     因为不知道要访问几个字节
// p++;                               void*类型的指针也不能进行加减整数的操作
//p = &b;




#include <stdio.h>
#include <string.h>       //strcmp
#include <stdlib.h>      //qsort         
void bubble_sort(int arr[], int sz)                  //冒泡排序
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
	char name[20];                          //结构体变量   
	int age;
};



//qsort函数怎么用
  
//void qsort(void* base, size_t num, size_t width,int (*compar)(const void* e1, const void* e2));
//base指的是      指向要排序的数组的第一个对象的地址，该对象已转换为void*。
//num指的是       要排序元素的个数
//width指的是     要排序元素所占字节数   即他的类型
//compar指的是    要排序的元素的  比较方式     
//第四个参数是    函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
//                函数指针的两个参数是：待比较的两个元素的地址






int cmp_int(const void* e1,const void* e2)                                    //用于整型排序的  比较方式
{
	//    *e1 *e2      由于void*类型的指针不能解引用  所以要强制类型转换
	return *(int*)e1 - *(int*)e2;          //将e1和e2强制类型转换为  int*  类型   再解引用操作   再相减
	                                     
	                                                 //要求是小于返回<0的数   等于返回0     大于返回>0的数
}


int cmp_float(const void* e1, const void* e2)                               //用于浮点型数据   排序   的比较方式  
{
	return *(float*)e1 - *(float*)e2;                    //强制类型转换为 float*类型  进行解引用后  再相减
} 



int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串的比较不能直接用>,<来比较  应该用strcmp函数
	return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
}



void test1()                                           //用qsort 来排序整形数组
{
	int i;
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);                //qsort内部会用快速排序  将传过来的 数据进行排序
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test2()                                     //普通的冒泡排序
{
	int i;
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);        
	bubble_sort(arr, sz);                                   //   只能排整形的数据
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