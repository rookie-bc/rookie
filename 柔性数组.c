#define _CRT_SECURE_NO_WARNINGS
//��������
//�ṹ���е����һ��Ԫ��������δ֪��С�����飬��ͽ������������须��Ա
//�ص�
//�ṹ�е����������Աǰ���������һ��������Ա��
//sizeof ���ص����ֽṹ��С����������������ڴ档
//�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�
//С������Ӧ���������Ԥ�ڴ�С



//#include <stdio.h>
//struct S
//{
//	int a;
//	int arr[];         //��������Сδ֪   ���ǽṹ�����һ����Ա      ����д��arr[0]        �������Ĵ�С�ǿ��Ե�����
//};
//int main()
//{
//	struct S s;
//	printf("%d", sizeof(s));         //�ڼ��������������Ľṹ��Ĵ�С��ʱ�򣬲��������������Ա
//	return 0;
//



//���������ʹ��
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
//	struct S* ptr = realloc(ps, 44);             //��������Ĵ�С
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



//��������ĺô�

//��һ���ô��ǣ������ڴ��ͷ�
//������ǵĴ�������һ���������õĺ����У������������˶����ڴ���䣬���������ṹ�巵�ظ�
//�û����û�����free�����ͷŽṹ�壬�����û�����֪������ṹ���ڵĳ�ԱҲ��Ҫfree��������
//����ָ���û�����������¡����ԣ�������ǰѽṹ����ڴ��Լ����ԱҪ���ڴ�һ���Է����
//�ˣ������ظ��û�һ���ṹ��ָ�룬�û���һ��free�Ϳ��԰����е��ڴ�Ҳ���ͷŵ���
//�ڶ����ô��ǣ����������ڷ����ٶ�.
//�������ڴ���������߷����ٶȣ�Ҳ�����ڼ����ڴ���Ƭ������ʵ���Ҹ��˾���Ҳû����ˣ�����
//���ܲ���Ҫ����ƫ�����ļӷ���Ѱַ��