//
//                                                                       //匿名结构体



//
//#include <stdio.h>
//struct                        //匿名结构体         没有结构体名字      只能用一次       
//{
//	char name[20];
//	int age;
//}sa;                          //匿名结构体只能在此处创建变量   ，并且在此处创建的变量是全局变量
//struct
//{
//	char neme[20];
//	int age;
//}* psa;                         //结构体指针    
//int main()
//{
//	psa = &sa;                 //不能这样写     看上去是同一种类型   ，但是编译器在运行时  会把这看成是两种类型   这两个类型不是统一的
//	return 0;
//}





                                                       //结构体的自引用   --   结构体中包含一个同类型的其他变量   用指针存放
 
 




//#include <stdio.h>
//
//
//                                                        //  链表    --    一种数据结构      用链子将一连串不相邻的数据连接起来
//
//
//
//
//
//////struct node
//////{
//////	int data;
//////	struct node n;      //不能这么写    结构体类型内部不能包含自己这种类型的成员
//////};
////
//////要写一种链表   
////struct node
////{
////	int a;                         //存放某一个数据                    --数据域
////	 
////	struct node* next;           //可以存放下一个节点的地址            --指针域
////};
////
////int main()
////{
////	return 0;
////}




//
//
//typedef struct node             //重命名   将struct node  重命名为  node
//{
//	int a;                        
//
//	struct node* next;           
//}node;
//
//
//int main()
//{ 
//	struct node a;      //struct node 本来就是一种类型  可以创建变量
//	node b;              //    node   是重新命名的一种类型   也可以创建变量   
//}




                                                         //结构体的初始化
//#include <stdio.h>
//
//struct T
//{
//    double weight;
//    short age;
//};
//
//struct S
//{
//    struct T st;            //结构体中  包含了另一个结构体
//    int age;
//    char name[10];
//    double n;
//    char c;
//};
//
//int main()
//{
//
//    struct S s = { 100,"zhangsan",3.14,'c' };         //结构体的初始化  ，用大括号括起来   
//    printf("%d %s %lf %c\n", s.age, s.name, s.n, s.c);      //结构体成员的输出   用   .    操作符   结构体成员访问操作符
//
//
//    struct S n = { {56.6,18},100,"lisi",3.14,'c' };
//    printf("%lf", s.st.weight);           //s先找到 st  在找到weight 
//
//
//    return 0;
//}
//




                                                           //结构体内存对齐



//对齐规则
//1. 第一个成员在与结构体变量偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//VS中默认的值为8
//3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
//体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍




//结构体的内存对齐是拿空间来换取时间的做法。



//那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：
//让占用空间小的成员尽量集中在一起。
//#include <stdio.h>
//struct s1
//{
//    char c1;
//    int a;
//    char c2;
//};
//struct s2
//{
//    char c1;
//    char c2;
//    int a;
//};
//struct s3
//{
//    double d;  //8
//    char c;    //1         最大对齐数是   8
//    int i;     //4
//};
//struct s4
//{
//    char c1;        //1
//    struct s3 s3;   //8
//    double d;       //8
//};
//
//int main()
//{
//    struct s1 s1 = { 0 };   //默认全为零
//    struct s2 s2 = { 0 };
//    struct s3 s3 = { 0 };
//    struct s4 s4 = { 0 };
//
//
//
//    printf("%d\n", sizeof(s1));  //  12
//    printf("%d\n", sizeof(s2));  //  8
//    printf("%d\n", sizeof(s3));  //  16
//    printf("%d\n", sizeof(s4));  //  32
//    return 0;
//}


//#include <stdio.h>
//#pragma pack(4)       //设置默认对齐数为4 
//struct s
//{
//    char c;   // 1
//    double a; // 4   对齐数是自身大小和默认对对齐数的较小值
//};
//#pragma pack()         //取消默认对齐数
//int main()
//{
//    struct s s = { 0 };
//    printf("%d", sizeof(s));
//
//    return 0;
//}


                                                     //  offsetof
//#include <stddef.h>
//#include <stdio.h>
//struct s
//{
//    char c;
//    int i;
//    double b;
//};
//int main()
//{                                                      //offsetof  不是函数    他是一个宏  可以传类型      是用来 计算结构体偏移量的
//    printf("%d\n", offsetof(struct s, c));
//    printf("%d\n", offsetof(struct s, i));
//    printf("%d\n", offsetof(struct s, b));
//
//    return 0;
//}




                                                     // 结构体传参


#include <stdio.h>
struct a
{
	int b;
};
struct stu              //一种类型   相当于int   char  等
{
	// 成员变量
	char name[10];
	int age;
	char id[100];
	struct a n;
};
void print1(struct stu t)
{
	printf("%s %d %s %d\n", t.name, t.age, t.id, t.n.b);
}

void print2(struct stu* ps)
{
	printf("%s %d %s %d", ps->name, ps->age, ps->id, ps->n.b);
}
int main()
{
	struct stu s = { "张三",18,"2021040066",{15} };           //用这种类型创建了一个   局部变量  s   即s是对象
	print1(s);           //传值调用      形参的改变不会影响实参     开辟空间多  
	print2(&s);          //传址调用      形参的改变实参也会改变        传递效率高  开辟空间少
	return 0;
}
//函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。
//如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。

