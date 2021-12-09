//memcpy  内存操作函数
//将  任意类型  的 数据 拷贝
//void * memcpy ( void * destination, const void * source, size_t num );
//dest  指向要复制内容的目标数组的指针，类型强制转换为void*类型的指针
//src   指向要复制的数据源的指针，类型转换为const void*类型的指针
//num   要复制的字节数



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
//	memcpy(arr4, arr3, sizeof(arr3));          //可以拷贝任意类型的数据
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
	my_memcpy(arr4, arr3, sizeof(arr3));          //可以拷贝任意类型的数据

}