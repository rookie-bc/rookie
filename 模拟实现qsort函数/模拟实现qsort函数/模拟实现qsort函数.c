                        //void qsort(void* base, size_t num, size_t width,int (*compar)(const void* e1, const void* e2));
#include <stdio.h>
#include <string.h>
struct stu
{
	char name[20];
	int age;
};
void swap(char* buf1,char* buf2,int width)            //交换函数   将
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
// 实现bubble_sort的程序员   不知道   用户  需要排序的类型
//那程序员也不知道带比较的两个元素的类型
void bubble_sort(void* base,int sz,int width,int (*cmp)(const void* e1,const void* e2))      //
                                               //cmp是一个函数指针   指向的函数有两个参数参数类型是const void*  返回类型是int
{
	int i, j;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if ((*cmp)((char*)base+j*width,(char*)base+(j+1)*width) >0)        // （*cmp）找到函数指针所对应的函数  并将函数参数传过去
				     //base是数组首元素地址  由于不知道数组中存放的是何种类型的元素
				//先将这个地址转换为  char*类型  即一次只能读取一个字节   +   j*width意思是跳过 几倍的width宽度   width指的是元素所占的字节
				//

			{
				//交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);

				//传过去的参数不仅有要交换的元素的地址   还有字节数   因为这个地址一次只能访问1个字节   不知道数据的类型，只能将元素大小传过去
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)         //将传过来的地址接收
{
	return *((int*)e1) - *((int*)e2);           //目前e1对应的是数组中某一个元素的地址  类型是char*  
	//将e1和e2强制类型转换为  int*  类型   再解引用操作   再相减

	//要求是小于返回<0的数   等于返回0     大于返回>0的数
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);      //比较两个字符串的大小
}
void test1()
{
	int i;
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//使用bubble_sort的程序员一定知道自己排序的是什么数据
	//就应该知道如何比较待排序数组中的元素
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