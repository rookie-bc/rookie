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
	//创建通讯录
	struct Contact con; //  con就是通讯录  里边包含data指针 （指向通讯录的空间）  和 size  还有  capacity （通讯录的容量） 
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();         //  菜单函数
		printf("请输入: ");
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
			printf("退出通讯录！\n");
			break;
		default :
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}