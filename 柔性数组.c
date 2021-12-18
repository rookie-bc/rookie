#define _CRT_SECURE_NO_WARNINGS
//柔性数组
//结构体中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员
//特点
//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大
//小，以适应柔性数组的预期大小



//#include <stdio.h>
//struct S
//{
//	int a;
//	int arr[];         //这个数组大小未知   且是结构体最后一个成员      或者写成arr[0]        这个数组的大小是可以调整的
//};
//int main()
//{
//	struct S s;
//	printf("%d", sizeof(s));         //在计算包含柔性数组的结构体的大小的时候，不包含柔性数组成员
//	return 0;
//



//柔性数组的使用
//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	int n;
//	int arr[];
//};
//int main()
//{
//	struct S s;
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	if (ps == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int i;
//		for (i = 0; i < 5; i++)
//		{
//			ps->arr[i] = i;
//		}
//	}
//	struct S* ptr = realloc(ps, 44);             //调整数组的大小
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	int i;
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//struct S
//{
//	int a;
//	int* arr;
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		*(ps->arr + i) = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	int* ptr = (int*)realloc(ps->arr, 40);
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}



//柔性数组的好处

//第一个好处是：方便内存释放
//如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给
//用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你
//不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好
//了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
//第二个好处是：这样有利于访问速度.
//连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正
//你跑不了要用做偏移量的加法来寻址）