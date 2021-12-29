#include "contact.h"
void menu()
{
	printf("*********************************************\n");
	printf("******    1.add              2.del     ******\n");
	printf("******    3.search           4.modify  ******\n");
	printf("******    5.show             6.sort    ******\n");
	printf("******    7.save             0.exit    ******\n");
	printf("*********************************************\n");
	printf("\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con; //  con����ͨѶ¼  ��߰���dataָ�� ��ָ��ͨѶ¼�Ŀռ䣩  �� size  ����  capacity ��ͨѶ¼�������� 
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();         //  �˵�����
		printf("������: ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�ͨѶ¼��\n");
			break;
		default :
			printf("����������������룡\n");
			break;
		}
	} while (input);
}