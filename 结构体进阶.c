//
//                                                                       //�����ṹ��



//
//#include <stdio.h>
//struct                        //�����ṹ��         û�нṹ������      ֻ����һ��       
//{
//	char name[20];
//	int age;
//}sa;                          //�����ṹ��ֻ���ڴ˴���������   �������ڴ˴������ı�����ȫ�ֱ���
//struct
//{
//	char neme[20];
//	int age;
//}* psa;                         //�ṹ��ָ��    
//int main()
//{
//	psa = &sa;                 //��������д     ����ȥ��ͬһ������   �����Ǳ�����������ʱ  ����⿴������������   ���������Ͳ���ͳһ��
//	return 0;
//}





                                                       //�ṹ���������   --   �ṹ���а���һ��ͬ���͵���������   ��ָ����
 
 




//#include <stdio.h>
//
//
//                                                        //  ����    --    һ�����ݽṹ      �����ӽ�һ���������ڵ�������������
//
//
//
//
//
//////struct node
//////{
//////	int data;
//////	struct node n;      //������ôд    �ṹ�������ڲ����ܰ����Լ��������͵ĳ�Ա
//////};
////
//////Ҫдһ������   
////struct node
////{
////	int a;                         //���ĳһ������                    --������
////	 
////	struct node* next;           //���Դ����һ���ڵ�ĵ�ַ            --ָ����
////};
////
////int main()
////{
////	return 0;
////}




//
//
//typedef struct node             //������   ��struct node  ������Ϊ  node
//{
//	int a;                        
//
//	struct node* next;           
//}node;
//
//
//int main()
//{ 
//	struct node a;      //struct node ��������һ������  ���Դ�������
//	node b;              //    node   ������������һ������   Ҳ���Դ�������   
//}




                                                         //�ṹ��ĳ�ʼ��
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
//    struct T st;            //�ṹ����  ��������һ���ṹ��
//    int age;
//    char name[10];
//    double n;
//    char c;
//};
//
//int main()
//{
//
//    struct S s = { 100,"zhangsan",3.14,'c' };         //�ṹ��ĳ�ʼ��  ���ô�����������   
//    printf("%d %s %lf %c\n", s.age, s.name, s.n, s.c);      //�ṹ���Ա�����   ��   .    ������   �ṹ���Ա���ʲ�����
//
//
//    struct S n = { {56.6,18},100,"lisi",3.14,'c' };
//    printf("%lf", s.st.weight);           //s���ҵ� st  ���ҵ�weight 
//
//
//    return 0;
//}
//




                                                           //�ṹ���ڴ����



//�������
//1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵ�ֵΪ8
//3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ�����
//���С��������������������Ƕ�׽ṹ��Ķ���������������




//�ṹ����ڴ�������ÿռ�����ȡʱ���������



//������ƽṹ���ʱ�����Ǽ�Ҫ������룬��Ҫ��ʡ�ռ䣬���������
//��ռ�ÿռ�С�ĳ�Ա����������һ��
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
//    char c;    //1         ����������   8
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
//    struct s1 s1 = { 0 };   //Ĭ��ȫΪ��
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
//#pragma pack(4)       //����Ĭ�϶�����Ϊ4 
//struct s
//{
//    char c;   // 1
//    double a; // 4   �������������С��Ĭ�϶Զ������Ľ�Сֵ
//};
//#pragma pack()         //ȡ��Ĭ�϶�����
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
//{                                                      //offsetof  ���Ǻ���    ����һ����  ���Դ�����      ������ ����ṹ��ƫ������
//    printf("%d\n", offsetof(struct s, c));
//    printf("%d\n", offsetof(struct s, i));
//    printf("%d\n", offsetof(struct s, b));
//
//    return 0;
//}




                                                     // �ṹ�崫��


#include <stdio.h>
struct a
{
	int b;
};
struct stu              //һ������   �൱��int   char  ��
{
	// ��Ա����
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
	struct stu s = { "����",18,"2021040066",{15} };           //���������ʹ�����һ��   �ֲ�����  s   ��s�Ƕ���
	print1(s);           //��ֵ����      �βεĸı䲻��Ӱ��ʵ��     ���ٿռ��  
	print2(&s);          //��ַ����      �βεĸı�ʵ��Ҳ��ı�        ����Ч�ʸ�  ���ٿռ���
	return 0;
}
//�������ε�ʱ�򣬲�������Ҫѹջ������ʱ��Ϳռ��ϵ�ϵͳ������
//�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ�ĵ�ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½���

